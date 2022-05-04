/**
 * @file list.c
 * @brief Файл з реалізацією функцій: заповнення лампочки, отримання позиції
 * для додавання та видалення елемента, додавання та видалення лампочки
 * у динамічному масиві.
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
 */

#include "list.h"

size_t get_position_to_add(size_t size)
{
	size_t position = 0;
	if (size == 0) {
		return 0;
	} else {
		printf("In what position do you want to add bulb?(From 1 to %lu)\n", size + 1);
		printf("Position: ");
		scanf("%lu", &position);
		while (position < 0 || position > size + 1) {
			printf("Incorect position...Try again\n");
			printf("Position: ");
			scanf("%lu", &position);
		}
		position--;
		return position;
	}
}
size_t get_position_to_remove(size_t size)
{
	size_t position = 0;
	if (size == 0) {
		return 0;
	} else {
		printf("What bulb do you want to remove?(From 1 to %lu)\n", size);
		printf("Bulb number: ");
		scanf("%lu", &position);
		while (position < 0 || position > size) {
			printf("\nIncorect bulb...Try again\n");
			printf("Bulb number: ");
			scanf("%lu", &position);
		}
		position--;
		return position;
	}
}
void insert_bulb(struct Container *container, size_t pos, struct Bulb *bulb)
{
	struct Bulb *new_bulbs = malloc((container->size + 1) * sizeof(struct Bulb));
	if (pos > container->size)
		pos = container->size;
	memcpy(new_bulbs, container->bulbs, pos * sizeof(struct Bulb));
	memcpy(new_bulbs + pos, bulb, sizeof(struct Bulb));
	memcpy(new_bulbs + pos + 1, container->bulbs + pos, (container->size - pos) * sizeof(struct Bulb));
	free(container->bulbs);
	container->bulbs = new_bulbs;
	container->size++;
	printf("Successfully!\n");
}
void remove_bulb(struct Container *container, size_t pos)
{
	if (container->size == 0)
		return;
	struct Bulb *new_bulbs = malloc((container->size - 1) * sizeof(struct Bulb));
	if (pos >= container->size)
		pos = container->size - 1;
	memcpy(new_bulbs, container->bulbs, pos * sizeof(struct Bulb));
	memcpy(new_bulbs + pos, container->bulbs + pos + 1, (container->size - pos - 1) * sizeof(struct Bulb));
	free(container->bulbs);
	container->bulbs = new_bulbs;
	container->size--;
	printf("Successfully!\n");
}
int is_burned_bulb(struct Container *container)
{
	char yes[] = "yes";
	for (size_t i = 0; i < container->size; i++) {
		if (strcmp((container->bulbs + i)->is_burned, yes) == 0) {
			return 1;
		}
	}
	return 0;
}
void print_burned_bulbs(struct Container *cont)
{
	printf("Burnt out bulb(s):\n");
	char yes[] = "yes";
	for (size_t i = 0; i < cont->size; i++) {
		if (strcmp((cont->bulbs + i)->is_burned, yes) == 0) {
			printf("Bulb %lu: %s, %s, %s, %d, %d, %d, %s, %s\n", i + 1, (cont->bulbs + i)->is_on, (cont->bulbs + i)->is_burned,
			       (cont->bulbs + i)->factory, (cont->bulbs + i)->reverse_counter, (cont->bulbs + i)->vatt, (cont->bulbs + i)->color_temp,
			       (cont->bulbs + i)->shape, (cont->bulbs + i)->base_type);
		}
	}
}
void find_burned_bulbs(struct Container *container)
{
	if (container->size == 0) {
		printf("You don't have any bulb...\n");
	} else {
		int burned_bulb = is_burned_bulb(container);
		if (burned_bulb == 1) {
			print_burned_bulbs(container);
		} else {
			printf("Any burnt out bulb...\n");
		}
	}
}
void sort_by_criterion(struct Container *cont)
{
	if (cont->size == 0) {
		printf("Nothing to sort...\n");
	} else {
		char criteria[8][40] = { "1. Bulb is on",      "2. Bulb is burnt out", "3. Bulb manufacturer",
					 "4. Reverse counter", "5. Number of watts",   "6. Color temperature",
					 "7. Shape",	       "8. Base type" };
		int criterion = 0;
		printf("Choose the criterion:\n");
		for (int i = 0; i < 8; i++) {
			printf("%s\n", criteria[i]);
		}
		printf("Number: ");
		scanf("%i", &criterion);
		while (criterion < 1 || criterion > 8) {
			printf("Incorrect input...Rewrite answer\n");
			printf("Number: ");
			scanf("%i", &criterion);
		}
		criterion--;
		printf("Your criterion for sorting: %s\n", criteria[criterion]);
		for (size_t i = 0; i < cont->size; i++) {
			switch (criterion) {
			case 0:
				printf("Bulb %lu: %s\n", i + 1, (cont->bulbs + i)->is_on);
				break;
			case 1:
				printf("Bulb %lu: %s\n", i + 1, (cont->bulbs + i)->is_burned);
				break;
			case 2:
				printf("Bulb %lu: %s\n", i + 1, (cont->bulbs + i)->factory);
				break;
			case 3:
				printf("Bulb %lu: %d\n", i + 1, (cont->bulbs + i)->reverse_counter);
				break;
			case 4:
				printf("Bulb %lu: %d\n", i + 1, (cont->bulbs + i)->vatt);
				break;
			case 5:
				printf("Bulb %lu: %d\n", i + 1, (cont->bulbs + i)->color_temp);
				break;
			case 6:
				printf("Bulb %lu: %s\n", i + 1, (cont->bulbs + i)->shape);
				break;
			case 7:
				printf("Bulb %lu: %s", i + 1, (cont->bulbs + i)->base_type);
				break;
			default:
				break;
			}
		}
	}
}
void print_bulbs(struct Container *cont)
{
	if (cont->size == 0) {
		printf("Ooops...Nothing to print...You don't have bulbs.\n");
	} else {
		if (cont->size == 1)
			printf("Your bulb:\n");
		else
			printf("Your bulbs:\n");
		for (size_t i = 0; i < cont->size; i++) {
			printf("Bulb %lu: %s, %s, %s, %d, %d, %d, %s, %s\n", i + 1, (cont->bulbs + i)->is_on, (cont->bulbs + i)->is_burned,
			       (cont->bulbs + i)->factory, (cont->bulbs + i)->reverse_counter, (cont->bulbs + i)->vatt, (cont->bulbs + i)->color_temp,
			       (cont->bulbs + i)->shape, (cont->bulbs + i)->base_type);
		}
	}
}