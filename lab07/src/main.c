/**
 * @mainpage
 * # Загальне завдання
 * Переробити програми, що були розроблені під час виконання лабораторних робіт
 * з тем “Масиви” та “Цикли” таким чином, щоб використовувалися функції для
 * обчислення результату.
 *
 * @author Khelemendyk D.
 * @date 04-nov-2021
 */

/** #include "lib.h" */
#include <stdlib.h>
#define A 3
float geron(int y, char *z);
void push();
void shiftLeft();
int main(int argc, char *argv[])
{
	float res = geron(argc, argv[1]);
	int array[A * A];
	push(array, A);
	shiftLeft(array, A, argc, argv[2]);
	// створюю двовимірний масив, щоб в нього "загнати"
	// масив array і створити матрицю
	int matrix[A][A];
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			int n = i * A + j + 1;
			matrix[i][j] = array[n - 1];
		}
	}
	return 0;
}
// функція, яка знаходить корінь заданного числа
float geron(int y, char *z)
{
	// перевірка на наявність аргументу
	if (y >= 2) {
		int a = atoi(z);
		// перевірка на додатнє число
		if (a > 0) {
			float x = ((float)a + 1) / 2;
			while (x * x - (float)a > 0.00001) {
				x = 0.5f * (x + (float)a / x);
			}
			return x;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}
void push(int a[], int x)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			a[i * x + j] = random() % 100;
		}
	}
}
void shiftLeft(int a[], int x, int y, char *z)
{
	// чи є аргумент для кількості зсувів
	if (y >= 3) {
		int b = atoi(z);
		for (int p = 0; p < b; p++) {
			// присвоюю значення 1 елемента масиву в тимчасову зміну
			int tmp = a[0];
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					a[i * x + j] = a[i * x + j + 1];
				}
			}
			// присвоюю останньому елементу значення tmp
			a[x * x - 1] = tmp;
		}
	} else {
		// присвоюю значення 1 елемента масиву в тимчасову зміну
		int tmp = a[0];
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				a[i * x + j] = a[i * x + j + 1];
			}
		}
		// присвоюю останньому елементу значення tmp
		a[x * x - 1] = tmp;
	}
}
