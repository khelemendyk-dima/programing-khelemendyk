#ifndef LAB_15_ENTITY_H
#define LAB_15_ENTITY_H

/**
 * @file entity.h
 * @brief Файл з описом функцій: меню взаємодії з користувачем,
 * знаходження згорілих лампочок, сортування за критерієм, виводом у консоль
 * всіх лампочок та записом лампочки у структуру Bulb для подальшого тестування.
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
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
 * Заповнення структури.
 *
 * Функція запитує у користувача дані та записує їх у структуру.
 * Отримує показчик на структуру.
 */
void get_bulb(struct Bulb *e);
/**
 * Меню взаємодії з користувачем.
 *
 * Функція запитує у користувача який саме функціонал він хоче виконати.
 * Повертає номер функції.
 */
int get_answer();

#endif