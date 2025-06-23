/****************************************************************************
*						   										�ŷ�ʵս����		
*1.����֧��QQ:3403129447  �ֻ�:15618987206
*2.΢�Ź��ں�:�ŷ�ʵս����
*3.�Ա�����:https://shop105175919.taobao.com/
*4.����:�ŷ�ʵս����								  
*���������ѧϰʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
*****************************************************************************/


#include "UART.h"
#include "stm32f37x.h"
#include "Sys.h"
/*********************************************************
������: void Init_Uart(void) 
��  ��: ��ʼ������1
����ֵ: ��
���ֵ: ��
����ֵ: ��
**********************************************************/
void Init_Uart(void)
{
/*
	NVIC_InitTypeDef NVIC_InitStructure;
	
	USART1->CR1 &=~ (1<<28);		//M1
	USART1->CR1 &=~ (1<<12);		//M0	M[1:0] = 00: 1 Start bit, 8 data bits, n stop bits
	USART1->CR1 &=~ (1<<10);		//Parity control disabled
	USART1->CR1 |= (1<<5);			//Enable the rx interrup
	USART1->CR1 |= (1<<3);			//Transmitter is enabled
	USART1->CR1 |= (1<<2);			//Receiver is enabled and begins searching for a start bit
	USART1->CR2 &=~ (1<<13);
	USART1->CR2 &=~ (1<<12);		//1 stop bit
	USART1->CR3 &=~ (1<<10);		//CTS hardware flow control disabled
	USART1->CR1 &=~ (1<<15);
	USART1->BRR = 625;					//72000000/115200
	USART1->CR1 |= 1;						//USART enable
	
	// USART NVIC Configuration 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	 
*/
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_APB2Periph_USART1, ENABLE);  //??USART1,GPIOA??
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_7);        
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_7);

  // USART GPIO Configuration     
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;  //Tx
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA,&GPIO_InitStructure); 
  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;   // Rx
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);   

  // USART Parameter Configuration 
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
  USART_Init(USART1, &USART_InitStructure);

	// USART NVIC Configuration 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	   
	
	// Enable USART RXNE Interrupt 
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);   
	// Enable USART
  USART_Cmd(USART1, ENABLE); 
}
/*********************************************************
������: void uart1_send_byte(unsigned char data)
��  ��: ����1����1���ֽ�����
����ֵ: ����
���ֵ: ��
����ֵ: ��
**********************************************************/
void uart1_send_byte(unsigned char data)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	USART_SendData(USART1,data);
}
/*********************************************************
������: void Init_Uart(void) 
��  ��: ���Ͷ���ֽ�����
����ֵ: �洢���ݵĵ�ַ,�ֽ���
���ֵ: ��
����ֵ: ��
**********************************************************/
void uart1_send_nbyte(unsigned char* pbuffer,unsigned int number)
{
	unsigned int count =0;
	for(count =0;count<number;count++)
	{
		uart1_send_byte(pbuffer[count]);
	}
}
/*********************************************************
������: void USART1_IRQHandler(void)
��  ��: ���ڽ����жϷ�����
����ֵ: ��
���ֵ: ��
����ֵ: ��
**********************************************************/
void USART1_IRQHandler(void)
{
	/*receive nrf51822 data*/
		if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)
		{
				USART_ClearITPendingBit(USART1,USART_IT_RXNE);			
			
		}
}


