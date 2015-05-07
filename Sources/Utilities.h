/*
 * Utilities.h
 *
 *  Created on: Apr 16, 2015
 *      Author: Ezequiel
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "WAIT1.h"

#include <stdio.h>
#include <string.h>


#ifdef __cplusplus
extern "C" {
#endif

void cmdhelp(bool par);
void cmdversion(bool par);
void cmdstatus(bool par);
void nocmd(void);
void cmdmove(bool par);

void InitCMD(void);

void CMDInc(void);

void CMDDec(void);

void Waitus(uint32 time);

void PrintCom(char *str);

void WaitOnTx(void);

void EndLine(void);

void Echo(void);

void BackSpace(void);

void Enter(void);

void shellcmd(void);

uint8 findcmd(void);

void runcmd(uint8 enumfunc,bool par);

uint8 SendChar(uint8 ch);

void ScanOnRx(void);

void movedeg(uint8 *deg,bool dir);

#ifdef __cplusplus
}  /* extern "C" */
#endif


#endif /* UTILITIES_H_ */
