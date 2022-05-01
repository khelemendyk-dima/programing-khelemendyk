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

void get_bulb(struct Bulb *e)
{
	char temp;
	printf("Is bulb on?(yes/no): ");
	scanf("%s", e->is_on);
	printf("Is bulb burned out?(yes/no): ");
	scanf("%s", e->is_burned);
	scanf("%c", &temp);
	printf("Who is bulb manufacturer?: ");
	scanf("%[^\n]", e->factory);
	printf("How many bulbs are left before it burns out?: ");
	scanf("%i", &(e->reverse_counter));
	printf("What is the number of vatt?: ");
	scanf("%i", &(e->vatt));
	printf("What is the color temperature?: ");
	scanf("%i", &(e->color_temp));
	printf("What is the shape of bulb?: ");
	scanf("%s", e->shape);
	printf("What is the base type of bulb?: ");
	scanf("%s", e->base_type);
}
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