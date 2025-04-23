/*
 * parlantes.h
 *
 *  Created on: Apr 22, 2025
 *      Author: cuenc
 */

#ifndef INC_PARLANTES_H_
#define INC_PARLANTES_H_

#include "stm32f4xx_hal.h"
#include "main.h"

// Cantidad de parlantes
#define NUM_PARLANTES 6

// Estructura para cada parlante
typedef struct {
    GPIO_TypeDef* puerto;
    uint16_t pin;
} Parlante;

// Funciones públicas
void Parlantes_Init(void);
void Activar_Parlante(uint8_t numero);



#endif /* INC_PARLANTES_H_ */
