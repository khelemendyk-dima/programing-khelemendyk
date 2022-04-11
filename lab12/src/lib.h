#ifndef LAB_12_LIB_H
#define LAB_12_LIB_H

/**
 * @file lib.h
 * @brief Файл з описом функцій: знаходження кількості цілих та дробових чисел,
 * запису їх в показчики та друку результату.
 *
 * @author Khelemendyk D.
 * @date 09-jan-2022
 * @version 0.1
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Розмір буферу
 */
#define N 1000

int count_digit(char buff[]);
void get_digit(char buff[], int *arr);
void print_digits(int *arr, int size);
/**
 * Отримання даних про кількість цілих чисел.
 *
 * Функція зчитує буфер та записує кількість цілих чисел в змінну.
 */
//int get_int(char buff[]);

/**
 * Отримання даних про кількість дробових чисел.
 *
 * Функція зчитує буфер та записує кількість дробових чисел в змінну.
 */
//int get_float(char buff[]);

/**
 * Запис цілих чисел в показчик.
 *
 * Функція зчитує буфер та записує цілі числа в показчик.
 */
//void get_num_int(char buff[], int *arr_int);

/**
 * Запис дробових чисел в показчик.
 *
 * Функція зчитує буфер та записує дробові числа в показчик.
 */
//void get_num_float(char buff[], float *arr_float);

/**
 * Друк результату.
 *
 * Функція друкує кількість чисел в тексті, кількість цілих та дробових чисел
 * та перераховує.
 */
//void print_res(int *arr_int, float *arr_float, int num_int, int num_float);

#endif
