/*
 * parlantes.c
 *
 *  Created on: Apr 22, 2025
 *      Author: cuenc
 */


#include "parlantes.h"

// Definí los parlantes y sus pines
Parlante parlantes[NUM_PARLANTES] = {
    {GPIOC, sel_1_b_Pin},  // Parlante 1
    {GPIOC, sel_1_a_Pin},  // Parlante 2
    {GPIOA, sel_2_a_Pin},  // Parlante 3
    {GPIOA, sel_2_b_Pin},  // Parlante 4
    {GPIOA, sel_3_a_Pin},  // Parlante 5
    {GPIOA, sel_3_b_Pin},  // Parlante 6

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
