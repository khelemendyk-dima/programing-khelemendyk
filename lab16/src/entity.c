/**
 * @file entity.c
 * @brief Файл з реалізацією функцій: заповнення лампочки.
 * 
 * @author Khelemendyk D.
 * @date 22-may-2022
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