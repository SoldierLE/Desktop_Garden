/****************************************************************************
*						   										�ŷ�ʵս����		
*1.����֧��QQ:3403129447  �ֻ�:15618987206
*2.΢�Ź��ں�:�ŷ�ʵս����
*3.�Ա�����:https://shop105175919.taobao.com/
*4.����:�ŷ�ʵս����								  
*���������ѧϰʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
*****************************************************************************/



#include "stm32f37x.h"
#include "Sys.h"


/*********************************************************
������: void Delay_us(unsigned int data)
��  ��: ��ʱ����,��1usΪ��λ
����ֵ: (unsigned int)data(data*1us)
���ֵ: ��
����ֵ: �� 
**********************************************************/
void Delay_us(unsigned int data)
{
    unsigned int x;
    unsigned int y;
    for(x = data;x>0;x--)
        for(y =7;y>0;y--);    
}
/*********************************************************
������: void RCC_InitConfig(void)
��  ��: ʱ�ӳ�ʼ��
����ֵ: ��
���ֵ: ��
����ֵ: �� 
**********************************************************/
void SysTick_Init(void)
{
	uint32_t ticks;
  ticks = SystemCoreClock / 1000;  
	SysTick_Config((ticks/8));       //1ms //9000	
	//change the SysTick Clock source to be HCLK_Div8   
	//note: the function must be call after the function SysTick_Config();
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);  //systick --> 9Mhz
}
