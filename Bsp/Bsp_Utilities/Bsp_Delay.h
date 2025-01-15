/**
 * @file Bsp_Delay.h
 * @author noe (noneofever@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef BSP_DELAY_H
#define BSP_DELAY_H
#include "main.h"
#include "core_cm7.h"
#include "stm32h7xx_hal.h"
void Delay_Init(uint8_t SysCLK);
void Delay_us(uint32_t nus);
void Delay_ms(uint32_t nms);

#endif
