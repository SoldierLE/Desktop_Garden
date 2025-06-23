/****************************************************************************
*						   										�ŷ�ʵս����		
*1.����֧��QQ:3403129447  �ֻ�:15618987206
*2.΢�Ź��ں�:�ŷ�ʵս����
*3.�Ա�����:https://shop105175919.taobao.com/
*4.����:�ŷ�ʵս����								  
*���������ѧϰʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
*****************************************************************************/
#include "stm32f37x.h"
#include "GPIO.h"
#include "Sys.h"
#include "pwm.h"
#include "ADC.h"
#include "UART.h"
int16_t ADC_Value =0;
/*********************************************************
������: int main(void)
��  ��: ������
����ֵ: ��
���ֵ: ��
����ֵ: �� 
**********************************************************/
int main()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);/*!< 4 bits for pre-emption priority 0 bits for subpriority */
	SysTick_Init();
	Init_GPIO();
	pwm_init();
	Init_ADC();
	Init_Uart();
	
	ADC_Value = Get_Adc_Average(0,5);
	while(1);
}
