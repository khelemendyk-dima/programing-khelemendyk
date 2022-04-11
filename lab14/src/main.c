/**
 * @mainpage
 * # Загальне завдання
 * З розділу “Індивідуальні завдання комплексної роботи” взяти
 * прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою.
 * Створити структуру, що відображає “базовий клас”.
 *
 * @author Khelemendyk D.
 * @date 11-apr-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 11-apr-2022
 * @version 0.1
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - знаходю кількість лампочок за допомогою функції {@link count_lines}
 * та зберігаю дані у змінній number_bulbs;
 * - виділяю пам'ять для масиву символів, у якому буде зберігаться критерій для
 * сортування;
 * - виділяю пам'ять для структури розміром number_bulbs;
 * - далі зчитую дані з файлу, записую критерій, заповнюю структуру
 * шляхом виклику функції {@link get_struct_and_criterion};
 * - знаходю кількість згорівших лампочок функцією {@link is_burned_bulb} та
 * зберігаю у  змінній number_burned_bulbs;
 * - виділяю пам'ять для масиву з номерами згорівших лампочок;
 * - знаходю номера згорівших лампочок та зберігаю їх в показчику burned_bulbs;
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
		int number_bulbs = count_lines(argv);
		char *criterion_for_sorting = (char *)malloc(25);
		struct Bulb *bulbs = malloc((unsigned int)number_bulbs * sizeof(struct Bulb));
		get_struct_and_criterion(bulbs, number_bulbs, argv, criterion_for_sorting);
		// знаходю згорівші лампочки
		int number_burned_bulbs = is_burned_bulb(bulbs, number_bulbs);
		int *burned_bulbs = (int *)malloc((unsigned int)number_burned_bulbs * sizeof(int));
		get_index_burned_bulbs(bulbs, number_bulbs, burned_bulbs);
		// друкую результат
		print_res_screen(bulbs, number_bulbs, burned_bulbs, number_burned_bulbs, criterion_for_sorting);
		if (argc >= 3) {
			print_res_file(bulbs, number_bulbs, burned_bulbs, number_burned_bulbs, criterion_for_sorting, argv);
		}
		free(criterion_for_sorting);
		free(bulbs);
		free(burned_bulbs);
		criterion_for_sorting = NULL;
		bulbs = NULL;
		burned_bulbs = NULL;
	}
	return 0;
}
