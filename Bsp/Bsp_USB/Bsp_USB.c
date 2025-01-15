/**
 * @file Bsp_USB.c
 * @author noe (noneofever@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Bsp_USB.h"
#include "Bsp_Log.h"
#include "Bsp_DWT.h"

static uint8_t *bsp_usb_rx_buffer; // 接收到的数据会被放在这里,buffer size为2048
// 注意usb单个数据包(Full speed模式下)最大为64byte,超出可能会出现丢包情况

uint8_t *USBInit(USB_Init_Config_s usb_conf)
{
    // usb的软件复位(模拟拔插)在usbd_conf.c中的HAL_PCD_MspInit()中
    bsp_usb_rx_buffer = CDCInitRxbufferNcallback(usb_conf.tx_cbk, usb_conf.rx_cbk); // 获取接收数据指针
    // usb的接收回调函数会在这里被设置,并将数据保存在bsp_usb_rx_buffer中
    LOGINFO("USB init success");
    return bsp_usb_rx_buffer;
}

void USBTransmit(uint8_t *buffer, uint16_t len)
{
    CDC_Transmit_FS(buffer, len); // 发送
}
