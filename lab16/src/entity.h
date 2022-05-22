#ifndef LAB_16_ENTITY_H
#define LAB_16_ENTITY_H

/**
 * @file entity.h
 * @brief Файл з описом функцій: заповнення лампочки.
 *
 * @author Khelemendyk D.
 * @date 22-may-2022
 * @version 0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Структура "лампочка"
 */
struct Bulb {
	char is_on[5];
	char is_burned[5];
	char factory[30];
	int reverse_counter;
	int vatt;
	int color_temp;
	char shape[15];
	char base_type[10];
};
/**
 * Заповнення структури "лампочка".
 *
 * Функція запитує у користувача дані та записує їх у структуру.
 * Отримує показчик на структуру.
 */
void get_bulb(struct Bulb *e);
#endif