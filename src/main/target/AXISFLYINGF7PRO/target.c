/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <platform.h>

#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

timerHardware_t timerHardware[] = {
    DEF_TIM(TIM3, CH4, PB1,  TIM_USE_OUTPUT_AUTO, 0, 0),  // S1 (Normal Kullanım)
    DEF_TIM(TIM3, CH3, PB0,  TIM_USE_OUTPUT_AUTO, 0, 0),  // S2 (Normal Kullanım)
    DEF_TIM(TIM8, CH3, PC8,  TIM_USE_OUTPUT_AUTO, 0, 1),  // S3 (Normal Kullanım)
    DEF_TIM(TIM8, CH4, PC9,  TIM_USE_OUTPUT_AUTO, 0, 0),  // S4 (Normal Kullanım)

    DEF_TIM(TIM1, CH1, PA8,  TIM_USE_SERVO, 0, 0),        // S5 (Servo)

    DEF_TIM(TIM4, CH1, PB6,  TIM_USE_OUTPUT_AUTO, 0, 0),  // S6 (Normal Kullanım)
    DEF_TIM(TIM4, CH2, PB7,  TIM_USE_OUTPUT_AUTO, 0, 0),  // S7 (Normal Kullanım)

    // --- T3 VE R3 PİNLERİ (SERVO KULLANIMI) ---
    // S8 ve S9 pinleri genellikle UART3 yani T3/R3 pinleridir.
    DEF_TIM(TIM2, CH3, PB10, TIM_USE_SERVO, 0, 0),        // T3 Pini / S8 (Servo)
    DEF_TIM(TIM2, CH4, PB11, TIM_USE_SERVO, 0, 1),        // R3 Pini / S9 (Servo)

    // --- LED STRIP PİNİ (SERVO KULLANIMI) ---
    // NOT: Axisflying F7 Pro LED MCU pinine göre PA0 kısmını güncelleyin (PA0, PA15 veya PB3 olabilir).
    DEF_TIM(TIM5, CH1, PA0,  TIM_USE_SERVO, 0, 0),        // LED STRIP Pini (Servo)

    // --- DİĞER MOTOR/SİNYAL PİNLERİ ---
    DEF_TIM(TIM12, CH2, PB15, TIM_USE_OUTPUT_AUTO, 0, 0), // CC Pini (Motor Sinyali)

    // --- T2 VE R2 PİNLERİ (ELRS / UART KULLANIMI İÇİN KALDIRILDI) ---
    // T2 (PA2) ve R2 (PA3) pinleri ELRS alıcısı (UART2) olarak kullanılacağı için 
    // timerHardware dizisinden çıkarılmalıdır. Aksi takdirde timer çakışması yaşanır.
    // DEF_TIM(TIM5, CH3, PA2,  TIM_USE_OUTPUT_AUTO, 0, 0),  // T2 Pini (İptal - ELRS TX2)
    // DEF_TIM(TIM5, CH4, PA3,  TIM_USE_OUTPUT_AUTO, 0, 0),  // R2 Pini (İptal - ELRS RX2)
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
