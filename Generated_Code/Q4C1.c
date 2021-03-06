/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Q4C1.c
**     Project     : Encoder
**     Processor   : MK64FN1M0VLL12
**     Component   : QuadCounter
**     Version     : Component 01.026, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-05, 14:52, # CodeGen: 37
**     Abstract    :
**
This driver implements a quadrature encoder using two signals (C1 and C2) to generate position information.
**     Settings    :
**          Component name                                 : Q4C1
**          C1 and C2 swapped                              : yes
**          Counter Type                                   : 16bit
**          Method                                         : 
**            Sampling                                     : Enabled
**              Error Correction                           : no
**              C1                                         : Cx
**              C2                                         : Cx
**            Input Capture                                : Disabled
**          Shell                                          : Disabled
**     Contents    :
**         GetPos - Q4C1_QuadCntrType Q4C1_GetPos(void);
**         SetPos - void Q4C1_SetPos(Q4C1_QuadCntrType pos);
**         GetVal - uint8_t Q4C1_GetVal(void);
**         Sample - void Q4C1_Sample(void);
**         Deinit - void Q4C1_Deinit(void);
**         Init   - void Q4C1_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
**     This an open source software using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file Q4C1.c
** @version 01.00
** @brief
**
This driver implements a quadrature encoder using two signals (C1 and C2) to generate position information.
*/         
/*!
**  @addtogroup Q4C1_module Q4C1 module documentation
**  @{
*/         

/* MODULE Q4C1. */

#include "Events.h"
#include "Q4C1.h"

/* The decoder has 4 different states, together with the previous state the table has 16 entries.
   The value in the table (0,1,-1) indicates the steps taken since previous sample. */
#define QUAD_ERROR  3 /*!< Value to indicate an error in impulse detection. Has to be different from 0,1,-1 */

static const signed char Q4C1_Quad_Table[4][4] =
  {               /* prev   new    */
    {             /* c1 c2  c1 c2  */
     0,           /* 0  0   0  0  no change or missed a step? */
     1,           /* 0  0   0  1   */
     -1,          /* 0  0   1  0   */
     QUAD_ERROR   /* 0  0   1  1  error, lost impulse */
     },
    {             /* c1 c2  c1 c2  */
     -1,          /* 0  1   0  0   */
     0,           /* 0  1   0  1   no change or missed a step? */
     QUAD_ERROR,  /* 0  1   1  0   error, lost impulse */
     1            /* 0  1   1  1   */
     },
    {             /* c1 c2  c1 c2  */
     1,           /* 1  0   0  0   */
     QUAD_ERROR,  /* 1  0   0  1   error, lost impulse */
     0,           /* 1  0   1  0   no change or missed a step? */
     -1           /* 1  0   1  1   */
     },
    {             /* c1 c2  c1 c2  */
     QUAD_ERROR,  /* 1  1   0  0   error, lost impulse */
     -1,          /* 1  1   0  1   */
     1,           /* 1  1   1  0   */
     0            /* 1  1   1  1   no change or missed a step? */
     }
  };
static uint8_t Q4C1_last_quadrature_value; /*! Value of C1&C2 during last round. */

static Q4C1_QuadCntrType Q4C1_currPos = 0; /*!< Current position */

/*
** ===================================================================
**     Method      :  Q4C1_SetPos (component QuadCounter)
**     Description :
**         Sets the position information. Can be used as well to reset
**         the position information.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pos             - Position value to be set.
**     Returns     : Nothing
** ===================================================================
*/
void Q4C1_SetPos(Q4C1_QuadCntrType pos)
{
  Q4C1_currPos = pos;
}

/*
** ===================================================================
**     Method      :  Q4C1_GetPos (component QuadCounter)
**     Description :
**         Returns the current position based on the encoder tracking.
**     Parameters  : None
**     Returns     :
**         ---             - position
** ===================================================================
*/
Q4C1_QuadCntrType Q4C1_GetPos(void)
{
  return Q4C1_currPos;
}

/*
** ===================================================================
**     Method      :  Q4C1_Sample (component QuadCounter)
**     Description :
**         Call this method to periodically sample the signals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Q4C1_Sample(void)
{
  signed char new_step;
  uint8_t c12; /* value of the two sensor input */

  c12 = Q4C1_GET_C1_C2_PINS();
  new_step = Q4C1_Quad_Table[Q4C1_last_quadrature_value][c12];
  Q4C1_last_quadrature_value = c12;
  if (new_step == QUAD_ERROR) {
    Q4C1_OnError(); /* call error handler */
  } else if (new_step != 0) {
    Q4C1_currPos += new_step;
  }
}

/*
** ===================================================================
**     Method      :  Q4C1_Deinit (component QuadCounter)
**     Description :
**         Module de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Q4C1_Deinit(void)
{
  /* nothing needed */
}

/*
** ===================================================================
**     Method      :  Q4C1_Init (component QuadCounter)
**     Description :
**         Module initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Q4C1_Init(void)
{
  Q4C1_currPos = 0;
  Q4C1_last_quadrature_value = Q4C1_GET_C1_C2_PINS();
}

/*
** ===================================================================
**     Method      :  Q4C1_GetVal (component QuadCounter)
**     Description :
**         Returns the quadrature value (0, 1, 2 or 3)
**     Parameters  : None
**     Returns     :
**         ---             - Quadrature value (0-3)
** ===================================================================
*/
/*
uint8_t Q4C1_GetVal(void)
{
  *** Implemented as macro on the header file.
}
*/

/* END Q4C1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
