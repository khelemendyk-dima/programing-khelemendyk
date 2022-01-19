/**
 * @file lib.c
 * @brief Файл з реалізацією функцій,  
 * потрібних для виконання завдання
 *
 * @author Khelemendyk D.
 * @date 29-dec-2021
 */

#include "lib.h"

void push(int **arr1, int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(arr1 + i) + j) = rand() % 100;
		}
	}
}
void get_diagonal(int **arr1, int *arr2, int n)
{
	for (int i = 0; i < n; i++) {
		*(arr2 + i) = *(*(arr1 + i) + i);
	}
}
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
