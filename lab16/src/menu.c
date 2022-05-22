/**
 * @file menu.c
 * @brief Файл з реалізацією функцій: меню взаємодії з користувачем.
 *
 * @author Khelemendyk D.
 * @date 22-may-2022
 */

#include <menu.h>

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