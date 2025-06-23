/* 
 * File:   Sys.h
 * Author: Administrator
 *
 * Created on 2016?12?10?, ??9:31
 */
#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif
	
#define LED1_ON 	GPIOB->ODR &= 0xFFFB;				//输出低 	
#define LED2_ON 	GPIOB->ODR &= 0xFFEF;				//输出低 	
#define	LED3_ON		GPIOE->ODR &= 0xFEFF;				//输出低 
#define	LED4_ON		GPIOE->ODR &= 0xFDFF;				//输出低 	
#define	LED5_ON		GPIOD->ODR &= 0xFEFF;				//输出低 	
#define	LED6_ON		GPIOC->ODR &= 0x7FFF;				//输出低 
#define	LED1_OFF	GPIOB->ODR |= 0x0004;				//输出高 	
#define	LED2_OFF	GPIOB->ODR |= 0x0010;				//输出高 
#define	LED3_OFF	GPIOE->ODR |= 0x0100;				//输出高 
#define	LED4_OFF	GPIOE->ODR |= 0x0200;				//输出高 	
#define	LED5_OFF	GPIOD->ODR |= 0x0100;				//输出高 	
#define	LED6_OFF	GPIOC->ODR |= 0x8000;				//输出高 


#define LED_Flick GPIOB->ODR ^= GPIO_Pin_2;
void Init_GPIO(void);
#ifdef	__cplusplus
}
#endif

#endif	/* SYS_H */

