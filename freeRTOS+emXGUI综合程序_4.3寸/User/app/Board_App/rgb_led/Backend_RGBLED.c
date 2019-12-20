#include "emXGUI.h"
#include "x_libc.h"
#include "./led/bsp_led.h"  
#include "Backend_RGBLED.h" 


 /**
  * @brief  ����TIM3�������PWMʱ�õ���I/O
  * @param  ��
  * @retval ��
  */
void TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  PWM_LEDR_GPIO_CLK_ENABLE();
  PWM_LEDG_GPIO_CLK_ENABLE();
  PWM_LEDB_GPIO_CLK_ENABLE();

  GPIO_InitStruct.Pin = PWM_LEDR_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH ;
  GPIO_InitStruct.Alternate = PWM_LEDR_AF;
  HAL_GPIO_Init(PWM_LEDR_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = PWM_LEDG_GPIO_PIN;
  GPIO_InitStruct.Alternate = PWM_LEDG_AF;
  HAL_GPIO_Init(PWM_LEDG_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = PWM_LEDB_GPIO_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; 
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH ;
  GPIO_InitStruct.Alternate = PWM_LEDB_AF;

  HAL_GPIO_Init(PWM_LEDB_GPIO_PORT, &GPIO_InitStruct);  
   
}


//ʹ��ȫ�ֱ������������
TIM_HandleTypeDef TIM_Handle;
TIM_OC_InitTypeDef sConfig;
/**
  * @brief  ����TIM5�����PWM�źŵ�ģʽ�������ڡ�����
  * @param  ��
  * @retval ��
  */
/*
 * TIMxCLK/CK_PSC --> TIMxCNT --> TIMx_ARR --> �ж� & TIMxCNT ���¼���
 *                    TIMx_CCR(��ƽ�����仯)
 *
 * �ź�����=(TIMx_ARR +1 ) * ʱ������
 * 
 */
/*    _______    ______     _____      ____       ___        __         _
 * |_|       |__|      |___|     |____|    |_____|   |______|  |_______| |________|
 */
void TIM_Mode_Config(void)
{

  //ʹ��TIM5��ʱ��
  RGB_PWM_TIM_CLK_ENABLE();    
  
  TIM_Handle.Instance = RGB_PWM_TIM;
  TIM_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  TIM_Handle.Init.Period = 255 - 1;
  TIM_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM_Handle.Init.Prescaler =  2500 - 1;   
  // ��ʼ����ʱ��TIM
  HAL_TIM_PWM_Init(&TIM_Handle);

  sConfig.OCMode = TIM_OCMODE_PWM1;
  //CHx����Ч��ƽΪ�ߵ�ƽ
  sConfig.OCPolarity = TIM_OCPOLARITY_LOW;
  //CHx�ڿ���״̬��Ϊ�͵�ƽ
  sConfig.OCIdleState = TIM_OCNIDLESTATE_SET;
  //�Ƚ���CCR��ֵ
  sConfig.Pulse = 0;  
  //��ʼ������Ƚ�ͨ��
  HAL_TIM_PWM_ConfigChannel(&TIM_Handle, &sConfig, R_PWM_TIM_CH);
  HAL_TIM_PWM_ConfigChannel(&TIM_Handle, &sConfig, G_PWM_TIM_CH);
	HAL_TIM_PWM_ConfigChannel(&TIM_Handle, &sConfig, B_PWM_TIM_CH);

  HAL_TIM_PWM_Start(&TIM_Handle, R_PWM_TIM_CH);
  HAL_TIM_PWM_Start(&TIM_Handle, G_PWM_TIM_CH);
  HAL_TIM_PWM_Start(&TIM_Handle, B_PWM_TIM_CH);
}

//RGBLED��ʾ��ɫ
void SetRGBColor(uint32_t rgb)
{
	uint8_t r=0,g=0,b=0;
	r=(uint8_t)(rgb>>16);
	g=(uint8_t)(rgb>>8);
	b=(uint8_t)rgb;
	TIM5->CCR1 = r;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ
	TIM5->CCR2 = g;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ        
	TIM5->CCR3 = b;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ
}

//RGBLED��ʾ��ɫ
void SetColorValue(uint8_t r,uint8_t g,uint8_t b)
{
	TIM5->CCR1 = r;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ
	TIM5->CCR2 = g;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ        
	TIM5->CCR3 = b;	//����PWM���޸Ķ�ʱ���ıȽϼĴ���ֵ
}

//ֹͣpwm���
void TIM_RGBLED_Close(void)
{
	SetColorValue(0,0,0);

  HAL_TIM_PWM_Stop(&TIM_Handle, R_PWM_TIM_CH);
  HAL_TIM_PWM_Stop(&TIM_Handle, G_PWM_TIM_CH);
  HAL_TIM_PWM_Stop(&TIM_Handle, B_PWM_TIM_CH);

  __HAL_TIM_ENABLE(&TIM_Handle);
  
  __TIM5_CLK_DISABLE();
	LED_GPIO_Config();
  
}


