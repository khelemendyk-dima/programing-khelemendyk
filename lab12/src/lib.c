/**
 * @file lib.c
 * @brief Файл з реалізацією функцій: знаходження кількості цілих та дробових
 * чисел, запису їх в показчики та друку результату.
 *
 * @author Khelemendyk D.
 * @date 09-jan-2022
 */

#include "lib.h"

int count_digit(char buff[])
{
	int counter = 0;
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) { // перевірка на число
			counter++;
			while (isdigit(buff[i]))
				i++;
		}
	}
	return counter;
}
void get_digit(char buff[], int *arr)
{
	int p = 0; // рахувальник для показчика
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) { // перевірка на число
			*(arr + p) = atoi(&buff[i]); // запис в показчик
			p++;
			while (isdigit(buff[i]))
				i++;
		}
	}
}
void print_digits(int *arr, int size)
{
	printf("Результат:\n");
	// друкую кількість чисел взагалі
	if (size == 1) {
		printf("У цьому тексті одне число:\n");
	} else if (size > 1 && size < 5) {
		printf("У цьому тексті %d числа:\n", size);
	} else if (size > 4) {
		printf("У цьому тексті %d чисел:\n", size);
	}
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d.", *(arr + i));
		} else {
			printf("%d, ", *(arr + i));
		}
	}
	printf("\n");
}
/*
int get_int(char buff[])
{
	int num_int = 0; // рахувальник
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) { // перевірка на число
			num_int++;
			while (isdigit(buff[i])) {
				// якщо дробове рахувальник -= 1
				if (isdigit(buff[i]) && buff[i + 1] == '.' && isdigit(buff[i + 2])) {
					num_int--;
					while (isdigit(buff[i + 2])) {
						i++;
					}
				}
				i++;
			}
		}
	}
	return num_int;
}
int get_float(char buff[])
{
	int num_float = 0; // рахувальник
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) { // перевірка на число
			while (isdigit(buff[i])) {
				// якщо дробове рахувальник += 1
				if (isdigit(buff[i]) && buff[i + 1] == '.' && isdigit(buff[i + 2])) {
					num_float++;
					while (isdigit(buff[i + 2])) {
						i++;
					}
				}
				i++;
			}
		}
	}
	return num_float;
}
void get_num_int(char buff[], int *arr_int)
{
	int p = 0; // рахувальник для показчика
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) { // перевірка на число
			*(arr_int + p) = atoi(&buff[i]); // запис в показчик
			p++;
			while (isdigit(buff[i])) {
				// якщо число дробове рахувальник -= 1
				if (isdigit(buff[i]) && buff[i + 1] == '.' && isdigit(buff[i + 2])) {
					p--;
					while (isdigit(buff[i + 2])) {
						i++;
					}
				}
				i++;
			}
		}
	}
}
void get_num_float(char buff[], float *arr_float)
{
	int p = 0; // рахувальник для показчика
	for (int i = 0; i < (int)strlen(buff); i++) {
		if (isdigit(buff[i])) {
			*(arr_float + p) = (float)atof(&buff[i]);
			while (isdigit(buff[i])) {
				// якщо дробове записую в показчик
				if (isdigit(buff[i]) && buff[i + 1] == '.' && isdigit(buff[i + 2])) {
					p++;
					while (isdigit(buff[i])) {
						i++;
					}
					float tmp = 0; // змінна для дробної частини числа
					tmp = (float)atof(&buff[i + 2]); // запис дроб. част.
					while (isdigit(buff[i + 2])) {
						i++;
					}
					// перетворюю tmp в дробну частину числа
					while (tmp > 1) {
						tmp = tmp / 10;
					}
					*(arr_float + p) += tmp; // додаю дроб. част.
				}
				i++;
			}
		}
	}
}
void print_res(int *arr_int, float *arr_float, int num_int, int num_float)
{
	int size = num_int + num_float; // всього чисел
	printf("Результат:\n");
	// друкую кількість чисел взагалі
	if (size == 1) {
		printf("У цьому тексті одне число.");
	} else if (size > 1 && size < 5) {
		printf("У цьому тексті %d числа.", size);
	} else if (size > 4) {
		printf("У цьому тексті %d чисел.", size);
	}
	if (num_int != 0) {
		printf("\n");
	}
	// друкую кількість цілих чисел
	if (num_int == 1) {
		printf("Знайдено 1 ціле число: ");
	} else if (num_int > 1 && num_int < 5) {
		printf("Знайдено %d цілих числа: ", num_int);
	} else if (num_int > 4) {
		printf("Знайдено %d цілих чисел: ", num_int);
	}
	// перераховую цілі числа
	for (int i = 0; i < num_int; i++) {
		if (i == num_int - 1) {
			printf("%d.", *(arr_int + i));
		} else {
			printf("%d, ", *(arr_int + i));
		}
	}
	if (num_float != 0) {
		printf("\n");
	}
	// друкую кількість дробових чисел
	if (num_float == 1) {
		printf("Знайдено 1 ціле число: ");
	} else if (num_float > 1 && num_float < 5) {
		printf("Знайдено %d дробових числа: ", num_float);
	} else if (num_float > 4) {
		printf("Знайдено %d дробових чисел: ", num_float);
	}
	// перераховую дробові числа
	for (int i = 0; i < num_float; i++) {
		if (i == num_float - 1) {
			printf("%.2f.", *(arr_float + i));
		} else {
			printf("%.2f, ", *(arr_float + i));
		}
	}
	printf("\n");
}
*/
