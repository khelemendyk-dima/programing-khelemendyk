/**
 * @file list.c
 * @brief Файл з реалізацією функцій: заповнення лампочки, отримання позиції
 * для додавання та видалення елемента, додавання та видалення лампочки
 * у двозв'язний список.
 *
 * @author Khelemendyk D.
 * @date 22-may-2022
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
		scanf("%zd", &position);
		while (position < 0 || position > size + 1) {
			printf("Incorect position...Try again\n");
			printf("Position: ");
			scanf("%zd", &position);
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
		scanf("%zd", &position);
		while (position < 0 || position > size) {
			printf("\nIncorect bulb...Try again\n");
			printf("Bulb number: ");
			scanf("%zd", &position);
		}
		position--;
		return position;
	}
}
struct Element *get_element_by_pos(struct List *list, size_t pos)
{
	struct Element *walker = list->head;
	for (size_t i = 0; i < pos; i++) {
		walker = walker->next;
	}
	return walker;
}
void insert_bulb(struct List *list, size_t pos, struct Bulb *elem)
{
	if (pos > list->size)
		pos = list->size;
	struct Element *walker = get_element_by_pos(list, pos);
	struct Element *to_insert = malloc(sizeof(struct Element));
	memcpy(&to_insert->bulb, elem, sizeof(struct Bulb));
	to_insert->next = walker->next;
	walker->next = to_insert;
	list->size++;
	printf("Successfully!\n");
}
void remove_bulb(struct List *list, size_t pos)
{
	if (list->size == 0)
		return;
	if (pos >= list->size)
		pos = list->size - 1;
	struct Element *walker = get_element_by_pos(list, pos);

	struct Element *to_remove = walker->next;
	walker->next = to_remove->next;
	to_remove = NULL;
	free(to_remove);
	list->size--;
	printf("Successfully!\n");
}
int print_burned_bulbs(struct List *list)
{
	printf("Burnt out bulb(s):\n");
	char yes[] = "yes";
	int is_burned_bulb = 0;
	struct Element *walker = list->head;
	int i = 1;
	while (walker != NULL) {
		walker = walker->next;
		if (strcmp(walker->bulb->is_burned, yes) == 0) {
			printf("Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s\n", i + 1, walker->bulb->is_on, walker->bulb->is_burned,
			       walker->bulb->factory, walker->bulb->reverse_counter, walker->bulb->vatt, walker->bulb->color_temp,
			       walker->bulb->shape, walker->bulb->base_type);
			is_burned_bulb = 1;
			i++;
		}
	}
	return is_burned_bulb;
}
void find_burned_bulbs(struct List *list)
{
	if (list->size == 0) {
		printf("You don't have any bulb...\n");
	} else {
		int burned_bulb = print_burned_bulbs(list);
		if (burned_bulb == 0) {
			printf("Any burnt out bulb...\n");
		}
	}
}
void sort_by_criterion(struct List *list)
{
	if (list->size == 0) {
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
		struct Element *walker = list->head;
		int i = 1;
		while (walker != NULL) {
			walker = walker->next;
			switch (criterion) {
			case 0:
				printf("Bulb %d: %s\n", i + 1, walker->bulb->is_on);
				break;
			case 1:
				printf("Bulb %d: %s\n", i + 1, walker->bulb->is_burned);
				break;
			case 2:
				printf("Bulb %d: %s\n", i + 1, walker->bulb->factory);
				break;
			case 3:
				printf("Bulb %d: %d\n", i + 1, walker->bulb->reverse_counter);
				break;
			case 4:
				printf("Bulb %d: %d\n", i + 1, walker->bulb->vatt);
				break;
			case 5:
				printf("Bulb %d: %d\n", i + 1, walker->bulb->color_temp);
				break;
			case 6:
				printf("Bulb %d: %s\n", i + 1, walker->bulb->shape);
				break;
			case 7:
				printf("Bulb %d: %s", i + 1, walker->bulb->base_type);
				break;
			default:
				break;
			}
			i++;
		}
	}
}
void print_bulbs(struct List *list)
{
	if (list->size == 0) {
		printf("Ooops...Nothing to print...You don't have bulbs.\n");
	} else {
		if (list->size == 1)
			printf("Your bulb:\n");
		else
			printf("Your bulbs:\n");
		struct Element *walker = list->head;
		int i = 1;
		while (walker->next != NULL) {
			walker = walker->next;
			printf("Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s\n", i + 1, walker->bulb->is_on, walker->bulb->is_burned,
			       walker->bulb->factory, walker->bulb->reverse_counter, walker->bulb->vatt, walker->bulb->color_temp,
			       walker->bulb->shape, walker->bulb->base_type);
			i++;
		}
	}
}
void clean_up(struct List *list)
{
	while (list->size > 0) {
		remove_bulb(list, 0);
	}
}