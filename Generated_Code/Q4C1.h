/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Q4C1.h
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
** @file Q4C1.h
** @version 01.00
** @brief
**
This driver implements a quadrature encoder using two signals (C1 and C2) to generate position information.
*/         
/*!
**  @addtogroup Q4C1_module Q4C1 module documentation
**  @{
*/         

#ifndef __Q4C1_H
#define __Q4C1_H

/* MODULE Q4C1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "C11.h"
#include "C21.h"

#include "Cpu.h"


#define Q4C1_GET_C1_PIN()      (C11_GetVal())
#define Q4C1_GET_C2_PIN()      (C21_GetVal())
#define Q4C1_GET_C1_C2_PINS()  ((Q4C1_GET_C2_PIN()!=0?2:0)|(Q4C1_GET_C1_PIN()!=0?1:0))

typedef uint16_t Q4C1_QuadCntrType;
#define Q4C1_CNTR_BITS  16
  /*!< Number of bits in counter */

#define Q4C1_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


void Q4C1_SetPos(Q4C1_QuadCntrType pos);
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

Q4C1_QuadCntrType Q4C1_GetPos(void);
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

void Q4C1_Sample(void);
/*
** ===================================================================
**     Method      :  Q4C1_Sample (component QuadCounter)
**     Description :
**         Call this method to periodically sample the signals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Q4C1_Deinit(void);
/*
** ===================================================================
**     Method      :  Q4C1_Deinit (component QuadCounter)
**     Description :
**         Module de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Q4C1_Init(void);
/*
** ===================================================================
**     Method      :  Q4C1_Init (component QuadCounter)
**     Description :
**         Module initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define Q4C1_GetVal() \
  Q4C1_GET_C1_C2_PINS()

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

/* END Q4C1. */

#endif
/* ifndef __Q4C1_H */
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
