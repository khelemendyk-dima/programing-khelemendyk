/**
 * @mainpage
 * # Загальне завдання
 * Вивести структуру файлів та каталогів, як це робить утиліта Linux tree.
 * Виклик функції system заборонено.
 *
 * @author Khelemendyk D.
 * @date 14-jan-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 14-jan-2022
 * @version 0.1
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - роблю перевірку на кількість аргументів введених користувачем;
 * - знаходю розмір файла, з якого будуть зчитані дані функцією 
 * {@link size_of_file};
 * - виділяю пам'ять для буфера;
 * - зчитую дані з файлу та записую ці дані в буфер шляхом виклика функції 
 * {@link read_from_file};
 * - виконую функцію  {@link open_dir_and_write_output}, яка записує файли
 * заданої директорії в заданий файл;
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
*/
int main(int argc, char *argv[])
{
	if (argc >= 2) { // перевірка на наявність двох аргументів
		int buff_size = size_of_file(argv);
		char *buff = (char *)malloc((unsigned int)buff_size);
		read_from_file(buff, argv);
		open_dir_and_write_output(buff, argv);
		free(buff);
	}
	return 0;
}
