/**
 * @mainpage
 * # Загальне завдання
 * На базі попередньо розробленого функціоналу по роботі з прикладною областю 
 * сформувати динамічний масив елементів розробленої структури. 
 * Реалізувати наступні функції роботи зі списком: вивід вмісту списку на екран; 
 * реалізувати функцію No1 з категорії “Методи для роботи з колекцією”; 
 * додавання об’єкта у кінець списку; видалення об’єкта зі списку за індексом;
 * сортування вмісту списку за одним з критеріїв. Проект має складатися 
 * з 6 файлів (main.c, test.c, list.h, list.c, entity.c, entity.h).
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
 * @version 0.1
 */

#include "list.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виділяю пам'ять для динамічного масива та однієї лампочки;
 * - далі у користувача запитую, яку функцію він хоче виконати за 
 * допомогою функції {@link get_anwer};
 * - якщо користувач захоче виконати додавання лампочки до масиву, то, 
 * при наявності лампочок, буде запитано на яку позицію він хоче помістити 
 * лампочку функцією {@link get_position_to_add}, далі будуть зчитані дані 
 * шляхом виклику функції {@link get_bulb}, та додавання лампочки у масив
 * за допомогою функції {@link insert_bulb};
 * - при видаленні лампочки буде запитання позиція для видаллення
 *  функцією {@link get_position_to_remove} та видалення самої лампочки
 * за допомогою {@link remove_bulb};
 * - при знаходження згорілої лампочки від користувача нічого не потрібно, 
 * функція {@link find_burned_bulbs} знаходе перегорівші лампочки, якщо 
 * вони є;
 * - при сортуванні лампочок за критерієм функція {@link sort_by_criterion} 
 * запитує у користувача критерій та друкує відсортовані лампочки;
 * - шлязом виклику функції {@link print_bulbs} користувач друкує всі наявні
 * лапочки;
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
 */

int main()
{
	// memory allocation
	struct Container *container = malloc(1 * sizeof(struct Container));
	container->bulbs = malloc(1 * sizeof(struct Bulb));
	container->size = 0;
	struct Bulb *bulb = malloc(1 * sizeof(struct Bulb));
	// menu
	int answer = -1;
	while (answer != 0) {
		answer = get_answer();
		if (answer == 1) {
			size_t position = get_position_to_add(container->size);
			get_bulb(bulb);
			insert_bulb(container, position, bulb);
		} else if (answer == 2) {
			if (container->size > 0) {
				size_t position = get_position_to_remove(container->size);
				remove_bulb(container, position);
			} else {
				printf("You don't hane any bulb...\n");
			}
		} else if (answer == 3) {
			find_burned_bulbs(container);
		} else if (answer == 4) {
			sort_by_criterion(container);
		} else if (answer == 5) {
			print_bulbs(container);
		} else {
			printf("Have a nice day!\n\n");
		}
	}
	// memory free
	free(container->bulbs);
	free(container);
	free(bulb);
	return 0;
}