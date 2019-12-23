#ifndef __BOARD_H__
#define __BOARD_H__

/*
*************************************************************************
*                             ������ͷ�ļ�
*************************************************************************
*/
/* STM32 �̼���ͷ�ļ� */
#include "stm32h7xx.h"

/* ������Ӳ��bspͷ�ļ� */
#include "./led/bsp_led.h" 
//#include "./key/bsp_key.h" 
#include "./lcd/bsp_lcd.h"
#include "./sdram/bsp_sdram.h" 
#include "./touch/bsp_i2c_touch.h"
#include "./usart/bsp_usart.h"
//#include "./flash/bsp_spi_flash.h"
//#include "./font/fonts.h"
#include "./flash/bsp_qspi_flash.h"
#include "./touch/gt9xx.h"
#include "./cm_backtrace/cm_backtrace.h"
#include "./sd_card/bsp_sdio_sd.h"
#include "./mpu/bsp_mpu.h" 
#include "./key/bsp_key.h" 
#include "./beep/bsp_beep.h"
#include "./app/Board_App/clock/RTC/bsp_rtc.h"
#include "./adc/bsp_adc.h" 
#include "./app/Board_App/gyro/i2c_for_mpu6050/MPU6050_i2c.h"
#include "./app/Board_App/gyro/mpu6050/bsp_mpu_exti.h"

/*
*************************************************************************
*                               ��������
*************************************************************************
*/
	

#endif /* __BOARD_H__ */
