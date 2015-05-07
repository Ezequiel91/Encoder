/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : MAX1.h
**     Project     : Encoder
**     Processor   : MK64FN1M0VLL12
**     Component   : MaxonF2140
**     Version     : Component 01.001, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-04-29, 15:22, # CodeGen: 2
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         SetDirection - void MAX1_SetDirection(bool forward);
**         SetVal       - void MAX1_SetVal(word ratio);
**         GetVal       - word MAX1_GetVal(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file MAX1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup MAX1_module MAX1 module documentation
**  @{
*/         

#ifndef __MAX1_H
#define __MAX1_H

/* MODULE MAX1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PWM1.h"
#include "DIR1.h"

#include "Cpu.h"




void MAX1_SetDirection(bool forward);
/*
** ===================================================================
**     Method      :  MAX1_SetDirection (component MaxonF2140)
**     Description :
**         Set the direction of the motor (forward or backward)
**     Parameters  :
**         NAME            - DESCRIPTION
**         forward         - 0 for forward, 1 for backward.
**     Returns     : Nothing
** ===================================================================
*/

void MAX1_SetVal(word ratio);
/*
** ===================================================================
**     Method      :  MAX1_SetVal (component MaxonF2140)
**     Description :
**         
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - PWM ratio value, in the range from 0
**                           (stop) to 0xffff (full speed)
**     Returns     : Nothing
** ===================================================================
*/

word MAX1_GetVal(void);
/*
** ===================================================================
**     Method      :  MAX1_GetVal (component MaxonF2140)
**     Description :
**         Returns the current PWM ratio value in the range from 0
**         (stop) to 0xffff (full speed).
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END MAX1. */

#endif
/* ifndef __MAX1_H */
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
