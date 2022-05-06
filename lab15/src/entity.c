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
int get_answer()
{
	int ans;
	printf("\nWhat do you want to do?\n");
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
