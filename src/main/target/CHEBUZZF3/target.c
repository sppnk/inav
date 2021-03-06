/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include <platform.h>
#include "drivers/pwm_mapping.h"

const uint16_t multiPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT << 8),     // PPM input
    PWM9  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM10 | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM11 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM12 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM13 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM14 | (MAP_TO_MOTOR_OUTPUT << 8),
    PWM5  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM6  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM7  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    PWM8  | (MAP_TO_MOTOR_OUTPUT << 8),  // Swap to servo if needed
    0xFFFF
};

const uint16_t multiPWM[] = {
    PWM1  | (MAP_TO_PWM_INPUT << 8),     // input #1
    PWM2  | (MAP_TO_PWM_INPUT << 8),
    PWM3  | (MAP_TO_PWM_INPUT << 8),
    PWM4  | (MAP_TO_PWM_INPUT << 8),
    PWM5  | (MAP_TO_PWM_INPUT << 8),
    PWM6  | (MAP_TO_PWM_INPUT << 8),
    PWM7  | (MAP_TO_PWM_INPUT << 8),
    PWM8  | (MAP_TO_PWM_INPUT << 8),     // input #8
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1 or servo #1 (swap to servo if needed)
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2 or servo #2 (swap to servo if needed)
    PWM11 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1 or #3
    PWM12 | (MAP_TO_MOTOR_OUTPUT  << 8),
    PWM13 | (MAP_TO_MOTOR_OUTPUT  << 8),
    PWM14 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #4 or #6
    0xFFFF
};

const uint16_t airPPM[] = {
    PWM1  | (MAP_TO_PPM_INPUT << 8),     // PPM input
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM12 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM13 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM14 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #4
    PWM5  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #5
    PWM6  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM7  | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM8  | (MAP_TO_SERVO_OUTPUT  << 8), // servo #8
    0xFFFF
};

const uint16_t airPWM[] = {
    PWM1  | (MAP_TO_PWM_INPUT << 8),     // input #1
    PWM2  | (MAP_TO_PWM_INPUT << 8),
    PWM3  | (MAP_TO_PWM_INPUT << 8),
    PWM4  | (MAP_TO_PWM_INPUT << 8),
    PWM5  | (MAP_TO_PWM_INPUT << 8),
    PWM6  | (MAP_TO_PWM_INPUT << 8),
    PWM7  | (MAP_TO_PWM_INPUT << 8),
    PWM8  | (MAP_TO_PWM_INPUT << 8),     // input #8
    PWM9  | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #1
    PWM10 | (MAP_TO_MOTOR_OUTPUT  << 8), // motor #2
    PWM11 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #1
    PWM12 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM13 | (MAP_TO_SERVO_OUTPUT  << 8),
    PWM14 | (MAP_TO_SERVO_OUTPUT  << 8), // servo #4
    0xFFFF
};

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    // INPUTS CH1-8
    { TIM1,  IO_TAG(PA8),  TIM_Channel_1, TIM1_CC_IRQn,            1, IOCFG_AF_PP_PD, GPIO_AF_6, 0}, // PWM1 - PA8
    { TIM16, IO_TAG(PB8),  TIM_Channel_1, TIM1_UP_TIM16_IRQn,      0, IOCFG_AF_PP_PD, GPIO_AF_1, 0}, // PWM2 - PB8
    { TIM17, IO_TAG(PB9),  TIM_Channel_1, TIM1_TRG_COM_TIM17_IRQn, 0, IOCFG_AF_PP_PD, GPIO_AF_1, 0}, // PWM3 - PB9
    { TIM8,  IO_TAG(PC6),  TIM_Channel_1, TIM8_CC_IRQn,            1, IOCFG_AF_PP_PD, GPIO_AF_4, 0}, // PWM4 - PC6
    { TIM8,  IO_TAG(PC7),  TIM_Channel_2, TIM8_CC_IRQn,            1, IOCFG_AF_PP_PD, GPIO_AF_4, 0}, // PWM5 - PC7
    { TIM8,  IO_TAG(PC8),  TIM_Channel_3, TIM8_CC_IRQn,            1, IOCFG_AF_PP_PD, GPIO_AF_4, 0}, // PWM6 - PC8
    { TIM15, IO_TAG(PF9),  TIM_Channel_1, TIM1_BRK_TIM15_IRQn,     0, IOCFG_AF_PP_PD, GPIO_AF_3, 0}, // PWM7 - PF9
    { TIM15, IO_TAG(PF10), TIM_Channel_2, TIM1_BRK_TIM15_IRQn,     0, IOCFG_AF_PP_PD, GPIO_AF_3, 0}, // PWM8 - PF10
    // OUTPUTS CH1-10
    { TIM4,  IO_TAG(PD12), TIM_Channel_1, TIM4_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM9 - PD12
    { TIM4,  IO_TAG(PD13), TIM_Channel_2, TIM4_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM10 - PD13
    { TIM4,  IO_TAG(PD14), TIM_Channel_3, TIM4_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM11 - PD14
    { TIM4,  IO_TAG(PD15), TIM_Channel_4, TIM4_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM12 - PD15
    { TIM2,  IO_TAG(PA1),  TIM_Channel_2, TIM2_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_1, 0}, // PWM13 - PA1
    { TIM2,  IO_TAG(PA2),  TIM_Channel_3, TIM2_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_1, 0}, // PWM14 - PA2
    { TIM2,  IO_TAG(PA3),  TIM_Channel_4, TIM2_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_1, 0}, // PWM15 - PA3
    { TIM3,  IO_TAG(PB0),  TIM_Channel_3, TIM3_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM16 - PB0
    { TIM3,  IO_TAG(PB1),  TIM_Channel_4, TIM3_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}, // PWM17 - PB1
    { TIM3,  IO_TAG(PA4),  TIM_Channel_2, TIM3_IRQn,               0, IOCFG_AF_PP,    GPIO_AF_2, 0}  // PWM18 - PA4
};

