/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */


void main()
{
	board_init();			// 初始化寄存器,勿删除此句代码。
	
	// 此处编写用户代码(例如：外设初始化代码等)
    
	gpio_mode(P6_7, GPO_PP); //蜂鸣器
    //pwm_init(PWM1, 17000, 0)
    BEEP = 0;
    lcd_init();
    
    BEEP = 1;
    delay_ms(10);
    BEEP = 0;
    
    eeprom_init();
    
    RTC_Init(0);	//RTC实时时钟初始化
	RTC_Set(0,0,0,0,0,0,0);    //设置时间
    
    //RTCI_Set(1,1,3);
    pit_timer_ms(TIM_4, 5);
    
    while(1)
	{
		 // 此处编写需要循环执行的代码
        Keystroke_Scan();
        Keystroke_Menu();        	
        //读取时：YEAR年 MONTH月 DAY日 HOUR时 MIN分 SEC秒 SSEC(1/128秒)

    }
}

