/****************************************************************************
*						   										张飞实战电子		
*1.技术支持QQ:3403129447  手机:15618987206
*2.微信公众号:张飞实战电子
*3.淘宝店铺:https://shop105175919.taobao.com/
*4.作者:张飞实战电子								  
*本软件仅供学习使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
*****************************************************************************/
#include "stm32f37x.h"
#include "GPIO.h"
#include "Sys.h"
#include "pwm.h"
#include "ADC.h"
#include "UART.h"
int16_t ADC_Value =0;
/*********************************************************
函数名: int main(void)
描  述: 主函数
输入值: 无
输出值: 无
返回值: 无 
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
