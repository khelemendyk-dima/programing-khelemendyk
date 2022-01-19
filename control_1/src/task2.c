/**
 * @mainpage
 * # Загальне завдання
 * Написать программу, которая создаёт матрийу Х на Х элементов. Определить,
 * во сколько раз самый большой элемент больше самого маленького. Массив
 * заполнять при помощи генератора всевдослучайных чисел в диапахоне [-10..100]
 *
 * @author Khelemendyk D.
 * @date 14-dec-2021
*/
#define X 3
#include <stdlib.h>
void push(int a[], int x); // функция, которая заполняет массив
int max_num(int a[], int x); // функция, которая ищет макс число
int min_num(int a[], int x); // функция, которая ищет мин число
int div_of_max_and_min(int max, int min); // функция, которая делит макс на мин
int main()
{
	int array[X * X];
	push(array, X);
	int max = max_num(array, X);
	int min = min_num(array, X);
	int divide = div_of_max_and_min(max, min);
	int matrix[X][X];
	// создает двумерный массив
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < X; j++) {
			int n = i * X + j + 1;
			matrix[i][j] = array[n - 1];
		}
	}
	return 0;
}
void push(int a[], int x)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			a[i * x + j] = rand() % 110 - 10;
		}
	}
}
int max_num(int a[], int x)
{
	int max = a[0];
	for (int i = 1; i < x * x; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}
int min_num(int a[], int x)
{
	int min = a[0];
	for (int i = 1; i < x * x; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	return min;
}
int div_of_max_and_min(max, min)
{
	int res = max / min;
	return res;
}
