/**
 * @mainpage
 * # Загальне завдання
 * Знайти всі цифри, які зустрічаються в тексті.
 *
 * @author Khelemendyk D.
 * @date 09-jan-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 09-jan-2022
 * @version 0.1
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю буфер для даних stdin з розміром {@link N};
 * - зчитую дані з stdin функцією fgets() та друкую їх;
 * - створюю змінні num_int та num_float, та записую в них
 * кількість цілих та дробових чисел за допогою функцій {@link get_int}
 * та {@link get_float}, відповідно;
 * - створюю змінну size та записую в неї загальну кількість чисел в тексті;
 * - роблю перевірку на вміст чисел в тексті оператором if;
 * - виділяю памʼять для двох масивів(один для цілих чисел, другий - для
 * дробових);
 * - виконую функції {@link get_num_int} та {@link get_num_float} для запису
 * цілих і дробових чисел в показчики;
 * - друкую результат шляхом виклику функції {@link print_res};
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
*/
int main()
{
	char buff[N]; // буфер для stdin
	fgets(buff, sizeof(buff), stdin); // зчитує дані з stdin
	printf("Ваш текст:\n%s\n", buff); // друкує дані з stdin
	int size = count_digit(buff); // кількість цифр
	if (size <= 0) { // перевірка на наявність чисел взагалі
		printf("Помилка...\n");
		return 1;
	} else {
		int *array = (int *)malloc(((unsigned int)size + 1) * sizeof(int));
		get_digit(buff, array); // заповнює масив цифрами
		print_digits(array, size);
		free(array);
	}
	return 0;
}
/*
int main()
{
	char buff[N]; // буфер для stdin
	fgets(buff, sizeof(buff), stdin); // зчитує дані з stdin
	printf("Ваш текст:\n%s\n", buff); // друкує дані з stdin
	int num_int = get_int(buff); // рахує кількість цілих чисел
	int num_float = get_float(buff); // рахує кількість дробових чисел
	int size = num_int + num_float; // загальна кількість чисел
	if (size <= 0) { // перевірка на наявність чисел взагалі
		printf("Помилка...\n");
		return 1;
	} else {
		// виділяю пам'ять для масивів цілих та дробових чисел
		int *array_of_int = (int *)malloc(((unsigned int)num_int + 1) * sizeof(int));
		float *array_of_float = (float *)malloc(((unsigned int)num_float + 1) * sizeof(float));
		get_num_int(buff, array_of_int); // заповнює масив числами int
		get_num_float(buff, array_of_float); // заповнює числами float
		print_res(array_of_int, array_of_float, num_int, num_float);
		// звільнюю пам'ять
		free(array_of_int);
		free(array_of_float);
	}
	return 0;
}
*/
