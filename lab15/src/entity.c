/**
 * @file entity.c
 * @brief Файл з реалізацією функцій: отримання відповіді для подальший дій,
 * знаходження згорілих лампочок, сортування за критерієм, виводом у консоль
 * всіх лампочок та записом лампочки у структуру Bulb для подальшого тестування.
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
 */

#include "entity.h"

int get_answer()
{
	int ans;
	printf("\nWhat you want to do?\n");
	printf("0 - exit;\n");
	printf("1 - add bulb;\n");
	printf("2 - remove bulb;\n");
	printf("3 - find burnt out bulbs;\n");
	printf("4 - sort bulbs for criterion;\n");
	printf("5 - print bulbs;\n");
	printf("Answer: ");
	scanf("%i", &ans);
	while (ans < 0 || ans > 5) {
		printf("\nAnswer is incorrect...Please rewrite your answer\n");
		printf("Answer: ");
		scanf("%i", &ans);
	}
	printf("\n");
	return ans;
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