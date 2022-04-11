/**
 * @file lib.c
 * @brief Файл з реалізацією функцій: заповнення структури, рахувальник строк,
 * знаходження найдовшої строки, заповнення структур та знаходження критерію
 * для сортування, знаходження кількості згорівших лампочок, запис номерів
 * згорівших лампочок, друк результату у консоль, запис результату у файл.
 *
 * @author Khelemendyk D.
 * @date 11-apr-2022
 */

#include "lib.h"

int count_lines(char *argv[])
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
	lines--;
	return lines;
}
int get_struct_and_criterion(struct Bulb *bulbs, int number_bulbs, char *argv[], char *criterion_for_sorting)
{
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("");
		return 1;
	}
	fgets(criterion_for_sorting, 50, f);
	int size_buffer = max_string_length(argv);
	char *buffer = (char *)malloc((unsigned int)size_buffer);
	for (int i = 0; i < number_bulbs; i++) {
		fgets(buffer, size_buffer, f);
		if (write_to_struct(buffer, ",", (bulbs + i))) // заповнюю масив структур
			fprintf(stderr, "Error!\n");
	}
	fclose(f);
	free(buffer);
	return 0;
}
int max_string_length(char *argv[])
{
	int max_length = 0;
	int length = 0;
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror("max_string_length");
		return 1;
	}
	while (!feof(f)) {
		length++;
		if (fgetc(f) == '\n') {
			if (length > max_length) {
				max_length = length;
				length = 0;
			}
		}
	}
	max_length++;
	fclose(f);
	return max_length;
}
int write_to_struct(char *string, const char *delim, struct Bulb *bulbs)
{
	char *p = strtok(string, delim);
	if (!p || !strncpy(bulbs->is_on, p, sizeof(bulbs->is_on) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(bulbs->is_burned, p, sizeof(bulbs->is_burned) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(bulbs->factory, p, sizeof(bulbs->factory) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(bulbs->reverse_counter)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(bulbs->vatt)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || sscanf(p, "%d", &(bulbs->color_temp)) != 1)
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(bulbs->shape, p, sizeof(bulbs->shape) - 1))
		return 1;
	if (!(p = strtok(NULL, delim)) || !strncpy(bulbs->base_type, p, sizeof(bulbs->base_type) - 1))
		return 1;

	return 0;
}
int is_burned_bulb(struct Bulb *bulbs, int number_bulbs)
{
	char yes[] = "yes";
	int n = 0; // рахувальник згорівших лампочок
	for (int i = 0; i < number_bulbs; i++) {
		if (strcmp((bulbs + i)->is_burned, yes) == 0) {
			n++;
		}
	}
	return n;
}
void get_index_burned_bulbs(struct Bulb *bulbs, int number_bulbs, int *burned_bulbs)
{
	char yes[] = "yes";
	int n = 0;
	for (int i = 0; i < number_bulbs; i++) {
		if (strcmp((bulbs + i)->is_burned, yes) == 0) {
			*(burned_bulbs + n) = i; // запис номеру згорівшої лампочки
			n++;
		}
	}
}
void print_res_screen(struct Bulb *bulbs, int number_bulbs, int *burned_bulbs, int number_burned_bulbs, char *criterion_for_sorting)
{
	// друк всіх лампочок
	if (number_bulbs == 1) {
		printf("Your bulb:\n");
	} else if (number_bulbs > 1) {
		printf("Your bulbs:\n");
	}
	for (int i = 0; i < number_bulbs; i++) {
		printf("Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s", i + 1, (bulbs + i)->is_on, (bulbs + i)->is_burned, (bulbs + i)->factory,
		       (bulbs + i)->reverse_counter, (bulbs + i)->vatt, (bulbs + i)->color_temp, (bulbs + i)->shape, (bulbs + i)->base_type);
	}
	// друк перегорівших лампочок
	if (number_burned_bulbs == 1) {
		printf("\nBurnt out bulb:\n");
	} else if (number_burned_bulbs > 1) {
		printf("\nBurnt out bulbs:\n");
	}
	for (int i = 0; i < number_burned_bulbs; i++) {
		int n = *(burned_bulbs + i);
		printf("Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s", *(burned_bulbs + i) + 1, (bulbs + n)->is_on, (bulbs + n)->is_burned,
		       (bulbs + n)->factory, (bulbs + n)->reverse_counter, (bulbs + n)->vatt, (bulbs + n)->color_temp, (bulbs + n)->shape,
		       (bulbs + n)->base_type);
	}
	printf("\n");
	// сортування за заданими критеріями
	char criteria[8][40] = { "Bulb is on\n",      "Bulb is burnt out\n", "Bulb manufacturer\n",
				 "Reverse counter\n", "Number of watts\n",   "Color temperature\n",
				 "Shape\n",	      "Base type\n" };
	int validator = 0; // перевірка на ідентичність
	int mode = -1; // показник категорії
	for (int i = 0; i < 8; i++) {
		if (strcmp(criterion_for_sorting, criteria[i]) == 0) {
			validator = 1;
			mode = i;
			break;
		}
	}
	if (validator == 1) {
		printf("Your criterion for sorting: %s", criterion_for_sorting);
		for (int i = 0; i < number_bulbs; i++) {
			switch (mode) {
			case 0:
				printf("Bulb %d: %s\n", i + 1, (bulbs + i)->is_on);
				break;
			case 1:
				printf("Bulb %d: %s\n", i + 1, (bulbs + i)->is_burned);
				break;
			case 2:
				printf("Bulb %d: %s\n", i + 1, (bulbs + i)->factory);
				break;
			case 3:
				printf("Bulb %d: %d\n", i + 1, (bulbs + i)->reverse_counter);
				break;
			case 4:
				printf("Bulb %d: %d\n", i + 1, (bulbs + i)->vatt);
				break;
			case 5:
				printf("Bulb %d: %d\n", i + 1, (bulbs + i)->color_temp);
				break;
			case 6:
				printf("Bulb %d: %s\n", i + 1, (bulbs + i)->shape);
				break;
			case 7:
				printf("Bulb %d: %s", i + 1, (bulbs + i)->base_type);
				break;
			default:
				break;
			}
		}
	} else {
		printf("Criterion wasn't introduced or was entered incorrectly.\n");
	}
}
void print_res_file(struct Bulb *bulbs, int number_bulbs, int *burned_bulbs, int number_burned_bulbs, char *criterion_for_sorting, char *argv[])
{
	FILE *f = fopen(argv[2], "w");
	// запис всіх лампочок у файл
	if (number_bulbs == 1) {
		fprintf(f, "Your bulb:\n");
	} else if (number_bulbs > 1) {
		fprintf(f, "Your bulbs:\n");
	}
	for (int i = 0; i < number_bulbs; i++) {
		fprintf(f, "Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s", i + 1, (bulbs + i)->is_on, (bulbs + i)->is_burned, (bulbs + i)->factory,
			(bulbs + i)->reverse_counter, (bulbs + i)->vatt, (bulbs + i)->color_temp, (bulbs + i)->shape, (bulbs + i)->base_type);
	}
	// запис перегорівших лампочок
	if (number_burned_bulbs == 1) {
		fprintf(f, "\nBurnt out bulb:\n");
	} else if (number_burned_bulbs > 1) {
		fprintf(f, "\nBurnt out bulbs:\n");
	}
	for (int i = 0; i < number_burned_bulbs; i++) {
		int n = *(burned_bulbs + i);
		fprintf(f, "Bulb %d: %s, %s, %s, %d, %d, %d, %s, %s", *(burned_bulbs + i) + 1, (bulbs + n)->is_on, (bulbs + n)->is_burned,
			(bulbs + n)->factory, (bulbs + n)->reverse_counter, (bulbs + n)->vatt, (bulbs + n)->color_temp, (bulbs + n)->shape,
			(bulbs + n)->base_type);
	}
	fprintf(f, "\n");
	// запис сортування за заданими критеріями
	char criteria[8][40] = { "Bulb is on\n",      "Bulb is burnt out\n", "Bulb manufacturer\n",
				 "Reverse counter\n", "Number of watts\n",   "Color temperature\n",
				 "Shape\n",	      "Base type\n" };
	int validator = 0; // перевірка на ідентичність
	int mode = -1; // показник категорії
	for (int i = 0; i < 8; i++) {
		if (strcmp(criterion_for_sorting, criteria[i]) == 0) {
			validator = 1;
			mode = i;
			break;
		}
	}
	if (validator == 1) {
		fprintf(f, "Your criterion for sorting: %s", criterion_for_sorting);
		for (int i = 0; i < number_bulbs; i++) {
			switch (mode) {
			case 0:
				fprintf(f, "Bulb %d: %s\n", i + 1, (bulbs + i)->is_on);
				break;
			case 1:
				fprintf(f, "Bulb %d: %s\n", i + 1, (bulbs + i)->is_burned);
				break;
			case 2:
				fprintf(f, "Bulb %d: %s\n", i + 1, (bulbs + i)->factory);
				break;
			case 3:
				fprintf(f, "Bulb %d: %d\n", i + 1, (bulbs + i)->reverse_counter);
				break;
			case 4:
				fprintf(f, "Bulb %d: %d\n", i + 1, (bulbs + i)->vatt);
				break;
			case 5:
				fprintf(f, "Bulb %d: %d\n", i + 1, (bulbs + i)->color_temp);
				break;
			case 6:
				fprintf(f, "Bulb %d: %s\n", i + 1, (bulbs + i)->shape);
				break;
			case 7:
				fprintf(f, "Bulb %d: %s", i + 1, (bulbs + i)->base_type);
				break;
			default:
				break;
			}
		}
	} else {
		fprintf(f, "Criterion wasn't introduced or was entered incorrectly.\n");
	}
	fclose(f);
}
