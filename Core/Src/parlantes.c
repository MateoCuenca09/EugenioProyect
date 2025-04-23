/*
 * parlantes.c
 *
 *  Created on: Apr 22, 2025
 *      Author: cuenc
 */


#include "parlantes.h"

// Definí los parlantes y sus pines
Parlante parlantes[NUM_PARLANTES] = {
    {GPIOC, PC1_Pin},  // Parlante 1
    {GPIOC, PC3_Pin},  // Parlante 2
    {GPIOA, PA1_Pin},  // Parlante 3
    {GPIOA, PA3_Pin},  // Parlante 4
    {GPIOA, PA5_Pin},  // Parlante 5
    {GPIOA, PA7_Pin},  // Parlante 6

};


void Parlantes_Init(void) {}

void Activar_Parlante(uint8_t numero) {
    for (int i = 0; i < NUM_PARLANTES; i++) {
        if (i == (numero)) {
            HAL_GPIO_WritePin(parlantes[i].puerto, parlantes[i].pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(parlantes[i].puerto, parlantes[i].pin, GPIO_PIN_RESET);
        }
    }
}
