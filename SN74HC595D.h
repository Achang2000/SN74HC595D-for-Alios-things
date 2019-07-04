/*
 * design by Achang 2019-07-1
 */
#include <stdio.h>
//#ifndef _SN74HC595D_
#define _SN74HC595D_
#define ST  12    /* MTDI */
#define SH  14    /* MTMS */
#define DS  15    /* MTDO */
#define ON  1
#define OFF 0
/* This Is SN74HC595D Output Port, State 
0  SN74HC595D 0 port
1  SN74HC595D 1 port
2  SN74HC595D 2 port
3  SN74HC595D 3 port
4  SN74HC595D 4 port
5  SN74HC595D 5 port
6  SN74HC595D 6 port
7  SN74HC595D 7 port
 */
unsigned char PortBase[8];
/*
 SN74HC595D  Init;
 */
void SN74HC595D_Init(void);
/*
 index is Port postion, 0-7;
 value is  Set Port, Value 0 or 1
 */
void SN74HC595D_SetData(int index,unsigned char value);
/*
 Get SN74HC595D Port Value ,index is port postion.
 */
unsigned char SN74HC595D_GetData(int index);
/*
 Data Write To SN74HC595D . OutPut Data.
 */
void SN74HC595D_WriteData(void);
//Port_0  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_0(unsigned char value);
//Port_1  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_1(unsigned char value);
//Port_2  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_2(unsigned char value);
//Port_3  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_3(unsigned char value);
//Port_4  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_4(unsigned char value);
//Port_5  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_5(unsigned char value);
//Port_6  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_6(unsigned char value);
//Port_7  function , value is 1 ON ,value is 0 OFF
void SN74HC595D_Port_7(unsigned char value);
//#endif