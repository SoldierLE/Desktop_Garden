/****************************************************************************
*						   										张飞实战电子		
*1.技术支持QQ:3403129447  手机:15618987206
*2.微信公众号:张飞实战电子
*3.淘宝店铺:https://shop105175919.taobao.com/
*4.作者:张飞实战电子								  
*本软件仅供学习使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
*****************************************************************************/



#include "stm32f37x.h"
#include "Sys.h"


/*********************************************************
函数名: void Delay_us(unsigned int data)
描  述: 延时函数,以1us为单位
输入值: (unsigned int)data(data*1us)
输出值: 无
返回值: 无 
**********************************************************/
void Delay_us(unsigned int data)
{
    unsigned int x;
    unsigned int y;
    for(x = data;x>0;x--)
        for(y =7;y>0;y--);    
}
/*********************************************************
函数名: void RCC_InitConfig(void)
描  述: 时钟初始化
输入值: 无
输出值: 无
返回值: 无 
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
