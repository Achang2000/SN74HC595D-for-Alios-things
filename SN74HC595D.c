/* 
 *design by Achang 2019-07-1 
 */
#include<SN74HC595D.h>
#include <aos/kernel.h>
#include <aos/hal/gpio.h>
#include "esp_misc.h"
gpio_dev_t DEV_ST;

gpio_dev_t DEV_SH;

gpio_dev_t DEV_DS;
void SN74HC595D_Init(void)
{
  DEV_DS.port=DS;
  DEV_SH.port=SH;
  DEV_ST.port=ST;
  DEV_DS.config=DEV_SH.config=DEV_ST.config=OUTPUT_PUSH_PULL;
  int i;
  for( i=0;i<8;i++)
  {
     PortBase[i]=0;      
  }
  hal_gpio_init(&DEV_ST);
  hal_gpio_init(&DEV_SH);
  hal_gpio_init(&DEV_DS);
  /*
  初始化数据推送至芯片
   */
  SN74HC595D_WriteData();
}
void SN74HC595D_WriteData(void)
{
    hal_gpio_output_low(&DEV_ST);
    int i;
    for( i=7 ;i>=0;i--)
    {
      hal_gpio_output_low(&DEV_SH);

      if(PortBase[i]==ON)
      {
        //ON
        hal_gpio_output_high(&DEV_DS);
      }
      else
      {
        //OFF
        hal_gpio_output_low(&DEV_DS);
      }

      hal_gpio_output_high(&DEV_SH);
    }

    hal_gpio_output_high(&DEV_ST);
}

void SN74HC595D_SetData(int index,unsigned char value)
{
   if(index>=0 && index<8)
   {
       PortBase[index]=value;
   }
}

unsigned char SN74HC595D_GetData(int index)
{
    if(index >=0 && index<8)
    {
        return PortBase[index];
    }
    return 0;
}

void SN74HC595D_Port_0(unsigned char value)
{
   SN74HC595D_SetData(0,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_1(unsigned char value)
{
  SN74HC595D_SetData(1,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_2(unsigned char value)
{
  SN74HC595D_SetData(2,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_3(unsigned char value)
{
  SN74HC595D_SetData(3,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_4(unsigned char value)
{
  SN74HC595D_SetData(4,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_5(unsigned char value)
{
  SN74HC595D_SetData(5,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_6(unsigned char value)
{
  SN74HC595D_SetData(6,value);
   SN74HC595D_WriteData();
}
void SN74HC595D_Port_7(unsigned char value)
{
  SN74HC595D_SetData(7,value);
   SN74HC595D_WriteData();
}