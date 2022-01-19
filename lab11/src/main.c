/**
 * @mainpage
 * # Загальне завдання
 * Визначити зворотню матрицю. Робота повинна бути присвячена взаємодії
 * з користувачем шляхом використання функцій write(), read().
 *
 * @author Khelemendyk D.
 * @date 03-jan-2022
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 03-jan-2022
 */
#include "lib.h"
/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю буфер для даних stdin з розміром {@link N};
 * - зчитую дані з stdin функцією fgets() та друкую їх
 * за допомогою write();
 * - створюю змінну розміру матриці та знаходю її функцією
 * {@link size_of_matrix};
 * - виділяю памʼять для двох матриць(початкової та оберненної); 
 * - записую дані в матрицу matrix за допомогою функції 
 * {@link input_matrix};
 * - далі перетворюю матрицю matrix на оберенену функцією 
 * {@link inverse_matrix}, яка записує обернену матрицю в matrix_res; 
 * - друкую початкову та обернену матриці шляхом виклика функції 
 * {@link print_array} два рази;
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
 */
int main()
{
	char buffer_for_stdin[N];
	fgets(buffer_for_stdin, sizeof(buffer_for_stdin), stdin); // зчитує дані з stdin
	write(1, &buffer_for_stdin, strlen(buffer_for_stdin)); // друкує дані з stdin
	int size = size_of_matrix(); // запитує розмір матриці
	float **matrix = (float **)malloc((unsigned long)size * sizeof(float *));
	for (int r = 0; r < size; r++) {
		*(matrix + r) = (float *)malloc((unsigned long)size * sizeof(float));
	}
	float **matrix_res = (float **)malloc((unsigned long)size * sizeof(float *));
	for (int r = 0; r < size; r++) {
		*(matrix_res + r) = (float *)malloc((unsigned long)size * sizeof(float));
	}
	input_matrix(matrix, size); // запис данних в матрицю
	inverse_matrix(matrix, matrix_res, size); // перетворення на обернену матрицю
	print_array(matrix, size, 1); // вивід початкової матриці
	print_array(matrix_res, size, 2); // вивід оберненної матриці
	for (int r = 0; r < size; r++) {
		free(*(matrix + r));
	}
	free(matrix);
	for (int r = 0; r < size; r++) {
		free(*(matrix_res + r));
	}
	free(matrix_res);
	return 0;
}
