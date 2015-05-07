/*
 * Utilities.c
 *
 *  Created on: Apr 16, 2015
 *      Author: Ezequiel
 */
#include "Events.h"

#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "WAIT1.h"
#include "Utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

struct
{
	uint8	Str[30];
	uint8	Cnt;
	uint8	*Ptr;
	uint8	fnc[10];
	uint8	par[20];
}CMD;

bool flags=FALSE;
uint16	actualpos=0;
uint16	quaderr=0;

uint8 SendChar(uint8 ch)
{
	uint16	Size;
	uint8	err;
	err=AS1_SendBlock((uint8 *)&ch,1,(uint16 *)&Size);
	WaitOnTx();
	return err;
}

void ScanOnRx(void)
{
	if(flags)
	{
		AS1_DisableEvent();
		flags = FALSE;
		Echo();
		AS1_EnableEvent();
	}
}


void InitCMD(void)
{
	CMD.Cnt=0;
	CMD.Ptr=(uint8 *)&CMD.Str;
}

void CMDInc(void)
{
	CMD.Cnt++;
	CMD.Ptr++;
}

void CMDDec(void)
{
	CMD.Cnt--;
	CMD.Ptr--;
}

void PrintCom(char *str)
{
	uint16	Sent;
	uint8	err,Size;
	uint8	buff;
	Size=strlen(str);
	while(AS1_SendBlock((uint8 *)str,Size,&Sent) != ERR_OK);
	WaitOnTx();
}

void WaitOnTx(void)
{
	word Noch;
	do{
		Noch = AS1_GetCharsInTxBuf();
	}
	while(Noch != 0);
}

void EndLine(void)
{
	while(SendChar(0x0d)!=ERR_OK);
	while(SendChar(0x0a)!=ERR_OK);
}

void BackSpace(void)
{
	uint8 debugbuff=CMD.Cnt;
	if(CMD.Cnt>0)
	{
		SendChar(0x08);
		SendChar(0x20);
		SendChar(0x08);
		CMDDec();
	}
}

void Enter(void)
{
	*CMD.Ptr=0x0d;
	EndLine();
	shellcmd();
	InitCMD();
	PrintCom("CMD> ");
}

void Echo(void)
{
	uint8	a=0;
	uint8 	ch;
	AS1_RecvChar((uint8 *)&ch);
	switch(ch)
	{
	case 0x00:
		break;

	case 0x0a:
		break;

	case 0x0d:
		Enter();
		break;

	case 0x08:
		BackSpace();
		break;

	default:
		SendChar(ch);
		*CMD.Ptr=ch;
		CMDInc();
		break;
	}
}

void shellcmd(void)
{
	uint8	i=0;
	uint8	enumfunc=0;
	bool	end=FALSE;
	bool	par=TRUE;

	if(CMD.Str[i]!=13)
	{
		do{
			i++;
			if(CMD.Str[i]==32){ end=TRUE;}
			if(CMD.Str[i]==13){ par=FALSE;end=TRUE;}

		}while(!end);

		UTIL1_strcpy((uint8 *)&CMD.fnc,i+1,(uint8 *)&CMD.Str);

		if(par) {UTIL1_strcpy((uint8 *)&CMD.par,29-i,((uint8 *)&CMD.Str)+i+1);}
		enumfunc=findcmd();
		runcmd(enumfunc,par);
		EndLine();
		EndLine();
	}


}

uint8 findcmd(void)
{
	if(UTIL1_strcmp((uint8 *)&CMD.fnc,"help")==0){return 1;}
	if(UTIL1_strcmp((uint8 *)&CMD.fnc,"version")==0){return 2;}
	if(UTIL1_strcmp((uint8 *)&CMD.fnc,"status")==0){return 3;}
	if(UTIL1_strcmp((uint8 *)&CMD.fnc,"move")==0){return 4;}
	return 0;
}

void runcmd(uint8 enumfunc,bool par)
{
	switch(enumfunc)
	{
	case 1:
		cmdhelp(par);
		break;
	case 2:
		cmdversion(par);
		break;
	case 3:
		cmdstatus(par);
		break;
	case 4:
		cmdmove(par);
		break;
	default:
		nocmd();
	}
}

void cmdhelp(bool par)
{
	if(par)
	{
		PrintCom("Help not implemented yet");
	}
	else{
		PrintCom("Missing parameter");
		EndLine();
		PrintCom("Example:");
		EndLine();
		PrintCom("help version, shows help about version command");
	}
}

void cmdversion(bool par)
{
	PrintCom("Motor Encoder v0.1");
	EndLine();
	PrintCom("Author: Ing. Ezequiel Ramos");
	EndLine();
	PrintCom("Description: Quadrature encoder for lego servo motor");
}

void cmdstatus(bool par)
{
	int16	pos;
	uint8	position[3];
	uint16	errs;
	uint8	errstr[4];
	errs=quaderr;
	pos = Q4C1_GetPos();
	UTIL1_Num16sToStr((uint8 *)&position,3,pos);
	UTIL1_Num16sToStr((uint8 *)&errstr,4,errs);
	PrintCom("Actual position: ");
	PrintCom((uint8 *)&position);
	EndLine();
	PrintCom("Errors on quad: ");
	PrintCom((uint8 *)&errstr);

}

void nocmd(void)
{
	PrintCom("No command '");
	PrintCom(CMD.fnc);
	PrintCom("' found");
}

void cmdmove(bool par)
{
	uint8	i;
	bool	end;
	if(par)
	{
		if(CMD.par[0]=='-')
		{
			switch(CMD.par[1])
			{
				case 'f':
					movedeg((uint8 *)&CMD.par[2],TRUE);
					break;

				case 'b':
					movedeg((uint8 *)&CMD.par[2],FALSE);
					break;

				default:
					PrintCom("No parameter '");
					PrintCom((uint8 *)&CMD.par[1]);
					PrintCom("' found");
					break;
			}
		}
		else{
			PrintCom("wrong parameters in 'move' command");
		}
	}
	else{
		PrintCom("missing parameters for 'move' command");
		EndLine();
		PrintCom("Example: move -f 30, moves motor forward 30 degree ");
	}
}

void movedeg(uint8 *deg,bool dir)
{
	uint8	i=0;
	uint16	degree;
	uint8	degrees[5];
	uint8	*ptr=deg;
	int16	pos;

	do{
	i++;
	ptr++;
	}while(*ptr!=13);
	UTIL1_ScanDecimal16uNumber(&deg,(uint16 *)&degree);

	if(degree>0 && degree<361)
	{
		pos=Q4C1_GetPos();
		UTIL1_Num16uToStr((uint8 *)&degrees,i,degree);
		PrintCom("Moving ");
		PrintCom((uint8 *)&degrees);
		if(degree!=1)
		{
			PrintCom(" degrees");
		}
		else{
			PrintCom(" degree");
		}

		if(dir)
		{
			PrintCom(" forward");
			pos=pos+degree;
			if(pos>360){pos=pos-360;}

		}
		else{
			PrintCom(" backward");
			pos=pos+degree;
			if(pos<0){pos=pos+360;}
		}
		actualpos=pos;
	}
	else{
		PrintCom("value must be between 1 and 360 degrees");
	}
}

#ifdef __cplusplus
}  /* extern "C" */
#endif
