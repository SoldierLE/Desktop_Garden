/* 
 * File:   Sys.h
 * Author: Administrator
 *
 * Created on 2016?12?10?, ??9:31
 */
#ifndef SYS_H
#define	SYS_H

#ifdef	__cplusplus
extern "C" {
#endif
	
	void SysTick_Init(void);
void Delay_us(unsigned int data);
#ifdef	__cplusplus
}
#endif

#endif	/* SYS_H */

