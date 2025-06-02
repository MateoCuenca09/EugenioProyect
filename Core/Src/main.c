/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "i2s.h"
#include "usart.h"
#include "usb_host.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "waveplayer.h"
#include "File_Handling.h"
#include "fonts.h"
#include "ssd1306_oled.h"
#include <stdio.h>
#include "display.h"
#include "parlantes.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */
extern ApplicationTypeDef Appli_state;
extern AUDIO_PLAYBACK_StateTypeDef AudioState;
extern UART_HandleTypeDef huart1;
uint8_t uart_rx_byte = 0;
volatile bool uart_cmd_received = false;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int IsFinished = 0;
bool next_song, prev_song, next_speaker, prev_speaker = false;
int8_t idx = 0; /* Indice de archivos */
int8_t idS = 0; /* Indice de Parlantes */

uint8_t cantidad_wavs = 3; /* Cantidad de archivos a reproducir */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2S3_Init();
  MX_FATFS_Init();
  MX_USB_HOST_Init();
  MX_USART1_UART_Init();
  MX_I2C3_Init();
  /* USER CODE BEGIN 2 */
  SSD1306_Init();
  HAL_UART_Receive_IT(&huart1, &uart_rx_byte, 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */

   	    if (Appli_state == APPLICATION_READY)
   	    {
   	    	Mount_USB();
   	    	AUDIO_PLAYER_Start(idx);
   	    	display_cancion(idx);
   	    	Activar_Parlante(idS);
   	    	while (1)
   	    	{
   	    		AUDIO_PLAYER_Process(TRUE,idx);


   	    		if (uart_cmd_received)
   	    		{
   	    		    uart_cmd_received = false;

   	    		    if (uart_rx_byte >= '0' && uart_rx_byte <= '9')
   	    		    {
   	    		        int nuevo_idx = uart_rx_byte - '0';
   	    		        if (nuevo_idx < cantidad_wavs)
   	    		        {
   	    		            idx = nuevo_idx;
   	    		            AudioState = AUDIO_STATE_NEXT;
   	    		            display_cancion(idx);
   	    		        }
   	    		    }
   	    		}

   	    		if (next_song)
   	    		{
   	    			AudioState = AUDIO_STATE_PAUSE;
   	    			idx = idx + 1;
   	    			/* Control de indice */
   	    			if(idx>(cantidad_wavs-1))
   	    			{
   	    				idx = 0;
   	    			}
   	    			next_song = false;
   	    			display_cancion(idx);
   	    			AudioState = AUDIO_STATE_NEXT;
      	    		};

   	    		if (next_speaker)
   	    		{
   	    			idS = idS + 1;
   	    			/* Control de indice */
   	    			if(idS>NUM_PARLANTES - 1)
   	    			{
   	    				idS = 0;
   	    			}
   	    			Activar_Parlante(idS);
   	    			next_speaker = false;
   	    			display_cancion(idx);
   	    			AudioState = AUDIO_STATE_PLAY;
   	    		}

   	    		if (prev_song)
   	    		{
   	    			idx = idx - 1;
   	    			/* Control de indice */
   	    			if(idx<0)
   	    			{
   	    				idx = cantidad_wavs-1;
   	    			}
   	    			AudioState = AUDIO_STATE_PREVIOUS;
   	    			prev_song = false;
   	    			display_cancion(idx);
   	    		};

   	    		if (prev_speaker)

   	    		{
   	    			idS = idS - 1;
   	    			/* Control de indice */
   	    			if(idS<0)
   	    			{
   	    				idS = NUM_PARLANTES - 1;
   	    			}
   	    			Activar_Parlante(idS);
   	    			prev_speaker = false;
   	    			display_cancion(idx);
   	    		}

   	    	}
   	    }
     }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)  // Cambiá esto si usás otro UART
    {
        uart_cmd_received = true;

        // Reinicia la recepción para recibir el próximo byte
        HAL_UART_Receive_IT(&huart1, &uart_rx_byte, 1);
    }
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if (GPIO_Pin == PD15_Pin)
	{
		next_song = true;
	}

	if (GPIO_Pin == PD13_Pin)
	{
		next_speaker = true;
	}

	if (GPIO_Pin == PD11_Pin)
	{
		prev_speaker = true;
	}

	if (GPIO_Pin == PD9_Pin)
	{
		prev_song = true;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
