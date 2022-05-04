/**
 * @file lib.c
 * @brief Файл з реалізацією функцій: заповнення структури, рахувальник строк,
 * знаходження найдовшої строки, заповнення структур та знаходження критерію
 * для сортування, знаходження кількості згорівших лампочок, запис номерів
 * згорівших лампочок, друк результату у консоль, запис результату у файл.
 *
 * @author Khelemendyk D.
 * @date 20-jan-2022
 */

#include "lib.h"
/*
int write_to_struct(char *s, const char *delim, struct bulb *e)
{
	char *p = strtok(s, delim); // розбиваю строку на частини
	// виконую запис в структуру
	if (!p || !strncpy(e->is_on, p, sizeof(e->is_on) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->is_burn, p, sizeof(e->is_burn) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(e->factory, p, sizeof(e->factory) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(e->reverse_cntr)) != 1)
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
	fgets(type_for_sort, 50, f); // знаходю критерій для сортування якщо він є
	char *buff = (char *)malloc((unsigned int)size_buff + 1);
	for (int i = 0; i < count_bulbs; i++) {
		fgets(buff, size_buff + 1, f);
		if (write_to_struct(buff, ",", &bulbs[i])) // заповнюю масив структур
			fprintf(stderr, "Error!\n");
	}
	fclose(f);
	free(buff);
	return 0;
}
int is_burn_bulbs(struct bulb *bulbs, int count_bulbs)
{
	char yes[] = "yes";
	int n = 0; // рахувальник згорівших лампочок
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
			*(burn_bulbs + n) = i; // запис номеру згорівшої лампочки
			n++;
		}
	}
}
void print_res_screen(struct bulb *bulbs, int count_bulbs, int *burn_bulbs, int num_burn_bulbs, char *type_for_sort)
{
	// друк всіх лампочок
	if (count_bulbs == 1) {
		printf("Ваша лампочка:\n");
	} else if (count_bulbs > 1) {
		printf("Ваші лампочки:\n");
	}
	for (int i = 0; i < count_bulbs; i++) {
		printf("Лампочка %d: %s, %s, %s, %d, ", i + 1, bulbs[i].is_on, bulbs[i].is_burn, bulbs[i].factory, bulbs[i].reverse_cntr);
		printf("%d, %d, %s, %s", bulbs[i].vatt, bulbs[i].temp, bulbs[i].form, bulbs[i].type_plinth);
	}
	// друк перегорівших лампочок
	if (num_burn_bulbs == 1) {
		printf("\nПерегорівша лампочка:\n");
	} else if (num_burn_bulbs > 1) {
		printf("\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_bulbs; i++) {
		int n = *(burn_bulbs + i);
		printf("Лампочка %d: %s, %s, %s, ", *(burn_bulbs + i) + 1, bulbs[n].is_on, bulbs[n].is_burn, bulbs[n].factory);
		printf("%d, %d, %d, %s, %s", bulbs[n].reverse_cntr, bulbs[n].vatt, bulbs[n].temp, bulbs[n].form, bulbs[n].type_plinth);
	}
	printf("\n");
	// сортування за заданими критеріями
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
			printf("Лампочка %d: %d\n", i + 1, bulbs[i].reverse_cntr);
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
	// запис всіх лампочок у файл
	if (count_bulbs == 1) {
		fprintf(f, "Ваша лампочка:\n");
	} else if (count_bulbs > 1) {
		fprintf(f, "Ваші лампочки:\n");
	}
	for (int i = 0; i < count_bulbs; i++) {
		fprintf(f, "Лампочка %d: %s, %s, %s, %d, ", i + 1, bulbs[i].is_on, bulbs[i].is_burn, bulbs[i].factory, bulbs[i].reverse_cntr);
		fprintf(f, "%d, %d, %s, %s", bulbs[i].vatt, bulbs[i].temp, bulbs[i].form, bulbs[i].type_plinth);
	}
	// запис перегорівших лампочок
	if (num_burn_bulbs == 1) {
		fprintf(f, "\nПерегорівша лампочка:\n");
	} else if (num_burn_bulbs > 1) {
		fprintf(f, "\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_bulbs; i++) {
		int n = *(burn_bulbs + i);
		fprintf(f, "Лампочка %d: %s, %s, %s, ", *(burn_bulbs + i) + 1, bulbs[n].is_on, bulbs[n].is_burn, bulbs[n].factory);
		fprintf(f, "%d, %d, %d, %s, %s", bulbs[n].reverse_cntr, bulbs[n].vatt, bulbs[n].temp, bulbs[n].form, bulbs[n].type_plinth);
	}
	fprintf(f, "\n");
	// запис сортування за заданими критеріями
	char vkl[] = "Ввімкнена лампочка\n";
	char burn[] = "Перегорівша лампочка\n";
	char prod[] = "Виробник лампочки\n";
	char reverse[] = "Зворотній лічильник\n";
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
	} else if (strcmp(type_for_sort, reverse) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_bulbs; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, bulbs[i].reverse_cntr);
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
*/
