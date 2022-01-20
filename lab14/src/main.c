/**
 * @mainpage
 * # Загальне завдання
 * З розділу “Індивідуальні завдання комплексної роботи” взяти
 * прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою.
 * Створити структуру, що відображає “базовий клас”.
 *
 * @author Khelemendyk D.
 * @date 20-jan-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 20-jan-2022
 * @version 0.1
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - знаходю кількість лампочок за допомогою функції {@link lines_count}
 * та зберігаю дані у змінній count_bulbs;
 * - виділяю пам'ять для масиву символів, у якому буде зберігаться критерій для
 * сортування;
 * - виділяю пам'ять для структури розміром count_bulbs;
 * - далі зчитую дані з файлу, записую критерій(якщо він є), заповнюю структуру
 * шляхом виклику функції {@link get_struct_and_type};
 * - знаходю кількість згорівших лампочок функцією {@link is_burn_bulbs} та
 * зберігаю у  змінній num_burn_bulbs;
 * - виділяю пам'ять для масиву з номерами згорівших лампочок;
 * - знаходю номера згорівших лампочок та зберігаю їх в показчику burn_bulbs;
 * - друкую результат у вікно консолі за допомогою функції
 * {@link print_res_screen};
 * - якщо введений третий аргумент - друкую результат у файл шляхом виклику
 * функції {@link print_res_file};
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
*/

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		int count_bulbs = lines_count(argv) - 1; // кількість лампочок
		char *type_for_sort = (char *)malloc(50); // критерій для сортування
		struct bulb *bulbs = malloc((unsigned int)count_bulbs * sizeof(struct bulb));
		// отримую структуру та критерій для сортування
		get_struct_and_type(bulbs, count_bulbs, argv, type_for_sort);
		// знаходю згорівші лампочки
		int num_burn_bulbs = is_burn_bulbs(bulbs, count_bulbs);
		int *burn_bulbs = (int *)malloc((unsigned int)num_burn_bulbs * sizeof(int));
		find_burn_bulbs(bulbs, count_bulbs, burn_bulbs);
		// друкую результат
		print_res_screen(bulbs, count_bulbs, burn_bulbs, num_burn_bulbs, type_for_sort);
		if (argc >= 3) {
			print_res_file(bulbs, count_bulbs, burn_bulbs, num_burn_bulbs, type_for_sort, argv);
		}
		free(bulbs);
		free(type_for_sort);
		free(burn_bulbs);
	}
	return 0;
}
