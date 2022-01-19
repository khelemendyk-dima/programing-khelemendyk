/**
 * @mainpage
 * # Загальне завдання
 * Вивести структуру файлів та каталогів, як це робить утиліта Linux tree.
 * Виклик функції system заборонено.
 *
 * @author Khelemendyk D.
 * @date 13-jan-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 13-jan-2022
 * @version 0.1
 */

//#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виконую функцію  {@link open_dir_and_write_output}, яка записує файли
 * заданої директорії в заданий файл;
 * - @return успішний код повернення з програми (0).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct bulb {
	char is_on[5];
	char is_burn[5];
	char factory[30];
	int num_vkl;
	int vatt;
	int temp;
	char form[15];
	char type_plinth[10];
} bulb;
int write_to_struct(char *s, const char *delim, struct bulb *e);
int lines_count(char *argv[]);
int longest_line(char *argv[]);
int get_struct_and_type(struct bulb *bulbs, int count_bulbs, char *argv[], char *type_for_sort);
int is_burn_bulbs(struct bulb *bulbs, int count_bulbs);
void find_burn_bulbs(struct bulb *bulbs, int count_bulbs, int *burn_bulbs);
void print_res_screen(struct bulb *bulbs, int count_bulbs, int *burn_bulbs, int num_burn_bulbs, char *type_for_sort);
void print_res_file(struct bulb *bulbs, int count_bulbs, int *burn_bulbs, int num_burn_bulbs, char *type_for_sort, char *argv[]);
int main(int argc, char *argv[])
{
	if (argc >= 2) {
		int count_bulbs = lines_count(argv) - 1; // кількість лампочок
		char *type_for_sort = (char *)malloc(50); // критерій для сортування
		// виділяю пам'ять для структури
		struct bulb *bulbs = malloc((unsigned int)count_bulbs * sizeof(struct bulb));
		// отримую структуру та критерій для сортування
		get_struct_and_type(bulbs, count_bulbs, argv, type_for_sort);
		// знаходю згорівші лампочки
		int num_burn_bulbs = is_burn_bulbs(bulbs, count_bulbs);
		int *burn_bulbs = (int *)malloc((unsigned int)num_burn_bulbs * sizeof(int));
		find_burn_bulbs(bulbs, count_bulbs, burn_bulbs);
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
int write_to_struct(char *s, const char *delim, struct bulb *e)
{
	char *p = strtok(s, delim);
	if (!p || !strncpy(e->is_on, p, sizeof(e->is_on) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->is_burn, p, sizeof(e->is_burn) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->factory, p, sizeof(e->factory) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(e->num_vkl)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(e->vatt)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(e->temp)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->form, p, sizeof(e->form) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->type_plinth, p, sizeof(e->type_plinth) - 1))
		return 1;

	return 0;
}
int lines_count(char *argv[])
{
	int lines = 0;
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("lines_count");
		return 1;
	}
	while (!feof(f)) {
		if (fgetc(f) == '\n')
			lines++;
	}
	fclose(f);
	return lines;
}
int longest_line(char *argv[])
{
	int max = 0;
	int num = 0;
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("longest_line");
		return 1;
	}
	while (!feof(f)) {
		num++;
		if (fgetc(f) == '\n') {
			if (num > max) {
				max = num;
				num = 0;
			}
		}
	}
	fclose(f);
	return max;
}
int get_struct_and_type(struct bulb *bulbs, int count_bulbs, char *argv[], char *type_for_sort)
{
	int size_buff = longest_line(argv); // розмір буфера
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("");
		return 1;
	}
	fgets(type_for_sort, 50, f);
	char *buff = (char *)malloc((unsigned int)size_buff + 1);
	for (int i = 0; i < count_bulbs; i++) {
		fgets(buff, size_buff + 1, f);
		if (write_to_struct(buff, ",", &bulbs[i]))
			fprintf(stderr, "Error!\n");
	}
	fclose(f);
	free(buff);
	return 0;
}
int is_burn_bulbs(struct bulb *bulbs, int count_bulbs)
{
	char yes[] = "yes";
	int n = 0;
	for (int i = 0; i < count_bulbs; i++) {
		if (strcmp(bulbs[i].is_burn, yes) == 0) {
			n++;
		}
	}
	return n;
}
void find_burn_bulbs(struct bulb *bulbs, int count_bulbs, int *burn_bulbs)
{
	char yes[] = "yes";
	int n = 0;
	for (int i = 0; i < count_bulbs; i++) {
		if (strcmp(bulbs[i].is_burn, yes) == 0) {
			*(burn_bulbs + n) = i;
			n++;
		}
	}
}
void print_res_screen(struct bulb *bulbs, int count_bulbs, int *burn_bulbs, int num_burn_bulbs, char *type_for_sort)
{
	if (count_bulbs == 1) {
		printf("Ваша лампочка:\n");
	} else if (count_bulbs > 1) {
		printf("Ваші лампочки:\n");
	}
	for (int i = 0; i < count_bulbs; i++) {
		printf("Лампочка %d: %s, %s, %s, %d, ", i + 1, bulbs[i].is_on, bulbs[i].is_burn, bulbs[i].factory, bulbs[i].num_vkl);
		printf("%d, %d, %s, %s", bulbs[i].vatt, bulbs[i].temp, bulbs[i].form, bulbs[i].type_plinth);
	}
	if (num_burn_bulbs == 1) {
		printf("\nПерегорівша лампочка:\n");
	} else if (num_burn_bulbs > 1) {
		printf("\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_bulbs; i++) {
		int n = *(burn_bulbs + i);
		printf("Лампочка %d: %s, %s, %s, %d, ", *(burn_bulbs + i) + 1, bulbs[n].is_on, bulbs[n].is_burn, bulbs[n].factory, bulbs[n].num_vkl);
		printf("%d, %d, %s, %s", bulbs[n].vatt, bulbs[n].temp, bulbs[n].form, bulbs[n].type_plinth);
	}
	printf("\n");
	// задані критерії
	char vkl[] = "Ввімкнена лампочка\n";
	char burn[] = "Перегорівша лампочка\n";
	char prod[] = "Виробник лампочки\n";
	char invers[] = "Зворотній лічильник\n";
	char num_vatt[] = "Кількість ватт\n";
	char temprtr[] = "Температура кольору\n";
	char forma[] = "Форма\n";
	char type[] = "Тип цоколю\n";
	if (strcmp(type_for_sort, vkl) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %s\n", i + 1, bulbs[i].is_on);
		}
	} else if (strcmp(type_for_sort, burn) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %s\n", i + 1, bulbs[i].is_burn);
		}
	} else if (strcmp(type_for_sort, prod) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %s\n", i + 1, bulbs[i].factory);
		}
	} else if (strcmp(type_for_sort, invers) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %d\n", i + 1, bulbs[i].num_vkl);
		}
	} else if (strcmp(type_for_sort, num_vatt) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %d\n", i + 1, bulbs[i].vatt);
		}
	} else if (strcmp(type_for_sort, temprtr) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %d\n", i + 1, bulbs[i].temp);
		}
	} else if (strcmp(type_for_sort, forma) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %s\n", i + 1, bulbs[i].form);
		}
	} else if (strcmp(type_for_sort, type) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			printf("Лампочка %d: %s", i + 1, bulbs[i].type_plinth);
		}
	}
}
void print_res_file(struct bulb *bulbs, int count_bulbs, int *burn_bulbs, int num_burn_bulbs, char *type_for_sort, char *argv[])
{
	FILE *f = fopen(argv[2], "w");
	if (count_bulbs == 1) {
		fprintf(f, "Ваша лампочка:\n");
	} else if (count_bulbs > 1) {
		fprintf(f, "Ваші лампочки:\n");
	}
	for (int i = 0; i < count_bulbs; i++) {
		fprintf(f, "Лампочка %d: %s, %s, %s, %d, ", i + 1, bulbs[i].is_on, bulbs[i].is_burn, bulbs[i].factory, bulbs[i].num_vkl);
		fprintf(f, "%d, %d, %s, %s", bulbs[i].vatt, bulbs[i].temp, bulbs[i].form, bulbs[i].type_plinth);
	}
	if (num_burn_bulbs == 1) {
		fprintf(f, "\nПерегорівша лампочка:\n");
	} else if (num_burn_bulbs > 1) {
		fprintf(f, "\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_bulbs; i++) {
		int n = *(burn_bulbs + i);
		fprintf(f, "Лампочка %d: %s, %s, %s, ", *(burn_bulbs + i) + 1, bulbs[n].is_on, bulbs[n].is_burn, bulbs[n].factory);
		fprintf(f, "%d, %d, %d, %s, %s", bulbs[n].num_vkl, bulbs[n].vatt, bulbs[n].temp, bulbs[n].form, bulbs[n].type_plinth);
	}
	fprintf(f, "\n");
	// задані критерії
	char vkl[] = "Ввімкнена лампочка\n";
	char burn[] = "Перегорівша лампочка\n";
	char prod[] = "Виробник лампочки\n";
	char invers[] = "Зворотній лічильник\n";
	char num_vatt[] = "Кількість ватт\n";
	char temprtr[] = "Температура кольору\n";
	char forma[] = "Форма\n";
	char type[] = "Тип цоколю\n";
	if (strcmp(type_for_sort, vkl) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, bulbs[i].is_on);
		}
	} else if (strcmp(type_for_sort, burn) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, bulbs[i].is_burn);
		}
	} else if (strcmp(type_for_sort, prod) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, bulbs[i].factory);
		}
	} else if (strcmp(type_for_sort, invers) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, bulbs[i].num_vkl);
		}
	} else if (strcmp(type_for_sort, num_vatt) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, bulbs[i].vatt);
		}
	} else if (strcmp(type_for_sort, temprtr) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, bulbs[i].temp);
		}
	} else if (strcmp(type_for_sort, forma) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, bulbs[i].form);
		}
	} else if (strcmp(type_for_sort, type) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %s", i + 1, bulbs[i].type_plinth);
		}
	}
	fclose(f);
}
