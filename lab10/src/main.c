/**
 * @mainpage
 * # Загальне завдання
 * Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі
 * записати в одновимірний масив, отриманий масив упорядкувати за зростанням.
 *
 *
 * @author Khelemendyk D.
 * @date 29-dec-2021
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 29-dec-2021
 */
#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення двовимірного масиву parray1 із {@link N} на {@link N} чисел за допомогою показчиків;
 * - створення масиву parray2 із {@link N} чисел за допомогою показчиків;
 * - генерація чисел для parray1 за допомогою функції {@link push};
 * - отримання чисел, які знаходяться на діагоналі parray1, та запис їх в parray2 за допомогою функції {@link get_diagonal};
 * - сортування чисел в масиві parray2 за допомогою функції {@link qsort};
 * - звільнення пам'яті;
 * - @return успішний код повернення з програми (0)
 */
int main()
{
	int **parray1 = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++) {
		*(parray1 + i) = (int *)malloc(N * sizeof(int));
	}
	int *parray2 = (int *)malloc(N * sizeof(int));
	push(parray1, N); // заповнює массив
	get_diagonal(parray1, parray2, N); // записує діагоналі в parray2
	qsort(parray2, N, sizeof(int), cmp); // відсортовує масив
	// звільнення пам'яті
	free(parray2);
	for (int i = 0; i < N; i++) {
		free(*(parray1 + i));
	}
	free(parray1);
	return 0;
}
