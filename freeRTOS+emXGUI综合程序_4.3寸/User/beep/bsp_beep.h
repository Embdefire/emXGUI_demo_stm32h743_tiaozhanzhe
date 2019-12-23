#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32h7xx.h"


/* ������������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶķ��������� */
#define BEEP_GPIO_PORT    	         GPIOI			              /* GPIO�˿� */
#define BEEP_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOI_CLK_ENABLE()  /* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN		  	         GPIO_PIN_11			          /* ���ӵ���������GPIO */

/* �ߵ�ƽʱ���������� */
#define ON_0x1  1
#define OFF_0x1 0

/* ���κ꣬��������������һ��ʹ�� */
#define BEEP(a)	                     HAL_GPIO_WritePin(BEEP_GPIO_PORT,BEEP_GPIO_PIN,a)
					
/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi_0x1(p,i)			         {p->BSRRL = i;}			        //����Ϊ�ߵ�ƽ		
#define digitalLo_0x1(p,i)			         {p->BSRRH=i;}  //����͵�ƽ
#define digitalToggle_0x1(p,i)	         {p->ODR ^=i;}			//�����ת״̬


/* �������IO�ĺ� */
#define BEEP_TOGGLE		   digitalToggle_0x1(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_ON	        digitalHi_0x1(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_OFF		    digitalLo_0x1(BEEP_GPIO_PORT,BEEP_GPIO_PIN)





void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
