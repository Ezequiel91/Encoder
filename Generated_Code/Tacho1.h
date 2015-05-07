/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Tacho1.h
**     Project     : Encoder
**     Processor   : MK64FN1M0VLL12
**     Component   : Tacho
**     Version     : Component 01.002, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-04-29, 15:22, # CodeGen: 2
**     Abstract    :
**
This component implements a tacho to measure the speed, for example the speed of a DC motor.
**     Settings    :
**
**     Contents    :
**         Sample   - void Tacho1_Sample(void);
**         GetVal   - word Tacho1_GetVal(void);
**         GetSpeed - int16_t Tacho1_GetSpeed(void);
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
** @file Tacho1.h
** @version 01.00
** @brief
**
This component implements a tacho to measure the speed, for example the speed of a DC motor.
*/         
/*!
**  @addtogroup Tacho1_module Tacho1 module documentation
**  @{
*/         

#ifndef __Tacho1_H
#define __Tacho1_H

/* MODULE Tacho1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "CS1.h"
#include "Q4C1.h"

#include "Cpu.h"




int16_t Tacho1_GetSpeed(void);
/*
** ===================================================================
**     Method      :  Tacho1_GetSpeed (component Tacho)
**     Description :
**         Returns the speed (RPM) based on the position information
**         from the encoder.
**     Parameters  : None
**     Returns     :
**         ---             - Speed in RPM.
** ===================================================================
*/

#define Tacho1_GetVal() Tacho1_GetSpeed()
/* function is implemented as macro
word Tacho1_GetVal(void);
*/
/*
** ===================================================================
**     Method      :  Tacho1_GetVal (component Tacho)
**     Description :
**         Returns the sensor value (RPM)
**     Parameters  : None
**     Returns     :
**         ---             - Sensor value
** ===================================================================
*/

void Tacho1_Sample(void);
/*
** ===================================================================
**     Method      :  Tacho1_Sample (component Tacho)
**     Description :
**         This method samples counter values in order to calculate the
**         speed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Tacho1. */

#endif
/* ifndef __Tacho1_H */
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