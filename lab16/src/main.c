/**
 * @mainpage
 * # Загальне завдання
 * З розділу “Індивідуальні завдання комплексної роботи” взяти
 * прикладну галузь стосовно номеру варіанту за попередньо-визначеною формулою.
 * Створити структуру, що відображає “базовий клас”.
 *
 * @author Khelemendyk D.
 * @date 20-jan-2022
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 20-jan-2022
 * @version 0.1
 */

//#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - знаходю кількість лампочок за допомогою функції {@link lines_count}
 * та зберігаю дані у змінній count_s_lists;
 * - виділяю пам'ять для масиву символів, у якому буде зберігаться критерій для
 * сортування;
 * - виділяю пам'ять для структури розміром count_s_lists;
 * - далі зчитую дані з файлу, записую критерій(якщо він є), заповнюю структуру
 * шляхом виклику функції {@link get_struct_and_type};
 * - знаходю кількість згорівших лампочок функцією {@link is_burn_s_lists} та
 * зберігаю у  змінній num_burn_s_lists;
 * - виділяю пам'ять для масиву з номерами згорівших лампочок;
 * - знаходю номера згорівших лампочок та зберігаю їх в показчику burn_s_lists;
 * - друкую результат у вікно консолі за допомогою функції
 * {@link print_res_screen};
 * - якщо введений третий аргумент - друкую результат у файл шляхом виклику
 * функції {@link print_res_file};
 * - звільнюю пам'ять;
 * - @return успішний код повернення з програми (0).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_list {
	char is_on[5];
	char is_burn[5];
	char factory[30];
	int reverse_cntr;
	int vatt;
	int temp;
	char form[15];
	char type_plinth[10];
	struct s_list *next;
} t_list;

int fill_buff(char *buff, char *argv[]);
int write_to_struct(char *s, const char *delim, struct s_list *e);
int lines_count(char *argv[]);
int longest_line(char *argv[]);
int get_struct_and_type(struct s_list *s_lists, int count_s_lists, char *argv[], char *type_for_sort);
int is_burn_s_lists(struct s_list *s_lists, int count_s_lists);
void find_burn_s_lists(struct s_list *s_lists, int count_s_lists, int *burn_s_lists);
void print_res_screen(struct s_list *s_lists, int count_s_lists, int *burn_s_lists, int num_burn_s_lists, char *type_for_sort);
void print_res_file(struct s_list *s_lists, int count_s_lists, int *burn_s_lists, int num_burn_s_lists, char *type_for_sort, char *argv[]);

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		//int count_s_lists = lines_count(argv); // кількість лампочок
		int size_buff = longest_line(argv); // розмір буфера
		char *buff = (char *)malloc((unsigned int)size_buff);
		//char *type_for_sort = (char *)malloc(50); // критерій для сортування
		fill_buff(buff, argv);
		//get_struct_and_type(s_lists, count_s_lists, argv, type_for_sort);
		/*
		// знаходю згорівші лампочки
		int num_burn_s_lists = is_burn_s_lists(s_lists, count_s_lists);
		int *burn_s_lists = (int *)malloc((unsigned int)num_burn_s_lists * sizeof(int));
		find_burn_s_lists(s_lists, count_s_lists, burn_s_lists);
		// друкую результат
		print_res_screen(s_lists, count_s_lists, burn_s_lists, num_burn_s_lists, type_for_sort);
		if (argc >= 3) {
			print_res_file(s_lists, count_s_lists, burn_s_lists, num_burn_s_lists, type_for_sort, argv);
		}
		*/
		free(buff);
		//free(type_for_sort);
		//free(burn_s_lists);
	}
	return 0;
}
int fill_buff(char *buff, char *argv[])
{
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("fill_buff");
		return 1;
	}
	while (fscanf(f, "%s ", buff) != EOF) {
		printf("%s", buff);
	}
	fclose(f);
	return 0;
}
int write_to_struct(char *s, const char *delim, struct s_list *e)
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
int get_struct_and_type(struct s_list *s_lists, int count_s_lists, char *argv[], char *type_for_sort)
{
	int size_buff = longest_line(argv); // розмір буфера
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("");
		return 1;
	}
	fgets(type_for_sort, 50, f); // знаходю критерій для сортування якщо він є
	char *buff = (char *)malloc((unsigned int)size_buff + 1);
	for (int i = 0; i < count_s_lists; i++) {
		fgets(buff, size_buff + 1, f);
		if (write_to_struct(buff, ",", &s_lists[i])) // заповнюю масив структур
			fprintf(stderr, "Error!\n");
	}
	fclose(f);
	free(buff);
	return 0;
}
int is_burn_s_lists(struct s_list *s_lists, int count_s_lists)
{
	char yes[] = "yes";
	int n = 0; // рахувальник згорівших лампочок
	for (int i = 0; i < count_s_lists; i++) {
		if (strcmp(s_lists[i].is_burn, yes) == 0) {
			n++;
		}
	}
	return n;
}
void find_burn_s_lists(struct s_list *s_lists, int count_s_lists, int *burn_s_lists)
{
	char yes[] = "yes";
	int n = 0;
	for (int i = 0; i < count_s_lists; i++) {
		if (strcmp(s_lists[i].is_burn, yes) == 0) {
			*(burn_s_lists + n) = i; // запис номеру згорівшої лампочки
			n++;
		}
	}
}
void print_res_screen(struct s_list *s_lists, int count_s_lists, int *burn_s_lists, int num_burn_s_lists, char *type_for_sort)
{
	// друк всіх лампочок
	if (count_s_lists == 1) {
		printf("Ваша лампочка:\n");
	} else if (count_s_lists > 1) {
		printf("Ваші лампочки:\n");
	}
	for (int i = 0; i < count_s_lists; i++) {
		printf("Лампочка %d: %s, %s, %s, %d, ", i + 1, s_lists[i].is_on, s_lists[i].is_burn, s_lists[i].factory, s_lists[i].reverse_cntr);
		printf("%d, %d, %s, %s", s_lists[i].vatt, s_lists[i].temp, s_lists[i].form, s_lists[i].type_plinth);
	}
	// друк перегорівших лампочок
	if (num_burn_s_lists == 1) {
		printf("\nПерегорівша лампочка:\n");
	} else if (num_burn_s_lists > 1) {
		printf("\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_s_lists; i++) {
		int n = *(burn_s_lists + i);
		printf("Лампочка %d: %s, %s, %s, ", *(burn_s_lists + i) + 1, s_lists[n].is_on, s_lists[n].is_burn, s_lists[n].factory);
		printf("%d, %d, %d, %s, %s", s_lists[n].reverse_cntr, s_lists[n].vatt, s_lists[n].temp, s_lists[n].form, s_lists[n].type_plinth);
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
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %s\n", i + 1, s_lists[i].is_on);
		}
	} else if (strcmp(type_for_sort, burn) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %s\n", i + 1, s_lists[i].is_burn);
		}
	} else if (strcmp(type_for_sort, prod) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %s\n", i + 1, s_lists[i].factory);
		}
	} else if (strcmp(type_for_sort, invers) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %d\n", i + 1, s_lists[i].reverse_cntr);
		}
	} else if (strcmp(type_for_sort, num_vatt) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %d\n", i + 1, s_lists[i].vatt);
		}
	} else if (strcmp(type_for_sort, temprtr) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %d\n", i + 1, s_lists[i].temp);
		}
	} else if (strcmp(type_for_sort, forma) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %s\n", i + 1, s_lists[i].form);
		}
	} else if (strcmp(type_for_sort, type) == 0) {
		printf("Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			printf("Лампочка %d: %s", i + 1, s_lists[i].type_plinth);
		}
	}
}
void print_res_file(struct s_list *s_lists, int count_s_lists, int *burn_s_lists, int num_burn_s_lists, char *type_for_sort, char *argv[])
{
	FILE *f = fopen(argv[2], "w");
	// запис всіх лампочок у файл
	if (count_s_lists == 1) {
		fprintf(f, "Ваша лампочка:\n");
	} else if (count_s_lists > 1) {
		fprintf(f, "Ваші лампочки:\n");
	}
	for (int i = 0; i < count_s_lists; i++) {
		fprintf(f, "Лампочка %d: %s, %s, %s, %d, ", i + 1, s_lists[i].is_on, s_lists[i].is_burn, s_lists[i].factory, s_lists[i].reverse_cntr);
		fprintf(f, "%d, %d, %s, %s", s_lists[i].vatt, s_lists[i].temp, s_lists[i].form, s_lists[i].type_plinth);
	}
	// запис перегорівших лампочок
	if (num_burn_s_lists == 1) {
		fprintf(f, "\nПерегорівша лампочка:\n");
	} else if (num_burn_s_lists > 1) {
		fprintf(f, "\nПерегорівші лампочки:\n");
	}
	for (int i = 0; i < num_burn_s_lists; i++) {
		int n = *(burn_s_lists + i);
		fprintf(f, "Лампочка %d: %s, %s, %s, ", *(burn_s_lists + i) + 1, s_lists[n].is_on, s_lists[n].is_burn, s_lists[n].factory);
		fprintf(f, "%d, %d, %d, %s, %s", s_lists[n].reverse_cntr, s_lists[n].vatt, s_lists[n].temp, s_lists[n].form, s_lists[n].type_plinth);
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
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, s_lists[i].is_on);
		}
	} else if (strcmp(type_for_sort, burn) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, s_lists[i].is_burn);
		}
	} else if (strcmp(type_for_sort, prod) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, s_lists[i].factory);
		}
	} else if (strcmp(type_for_sort, reverse) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, s_lists[i].reverse_cntr);
		}
	} else if (strcmp(type_for_sort, num_vatt) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, s_lists[i].vatt);
		}
	} else if (strcmp(type_for_sort, temprtr) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %d\n", i + 1, s_lists[i].temp);
		}
	} else if (strcmp(type_for_sort, forma) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %s\n", i + 1, s_lists[i].form);
		}
	} else if (strcmp(type_for_sort, type) == 0) {
		fprintf(f, "Заданий критерій для сортування: %s", type_for_sort);
		for (int i = 0; i < count_s_lists; i++) {
			fprintf(f, "Лампочка %d: %s", i + 1, s_lists[i].type_plinth);
		}
	}
	fclose(f);
}
