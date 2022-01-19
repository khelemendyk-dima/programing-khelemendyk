/**
 * @file lib.c
 * @brief Файл з реалізацією функції, яка виводить дані про структуру файлів та
 * каталогів.
 *
 * @author Khelemendyk D.
 * @date 14-jan-2022
 */

#include "lib.h"

int size_of_file(char *argv[])
{
	FILE *f = fopen(argv[1], "r"); // відкриваю файл для зчитування даних
	if (!f) {
		perror("fopen");
	}
	fseek(f, 0L, SEEK_END);
	int size = (int)ftell(f);
	fseek(f, 0L, SEEK_SET);
	fclose(f);
	return size;
}

void read_from_file(char *buff, char *argv[])
{
	FILE *f = fopen(argv[1], "r"); // відкриваю файл для зчитування даних
	if (!f) {
		perror("fopen");
	}
	fscanf(f, "%s", buff); // запис даних в буфер
	fclose(f);
}

void open_dir_and_write_output(char *buff, char *argv[])
{
	DIR *dir; // створюю директорію
	struct dirent *ent; // створюю структуру
	if ((dir = opendir(buff)) != NULL) { // откриваю директорію
		FILE *f = fopen(argv[2], "w"); // створюю файл для запису
		// зчитую дані з директорії та записую їх у заданий файл
		fprintf(f, "In %s directory we have this file(s):\n", buff);
		while ((ent = readdir(dir)) != NULL) {
			fprintf(f, "%s\n", ent->d_name);
			printf("%s\n", ent->d_name);
		}
		// закриваю директорію та файл
		closedir(dir);
		fclose(f);
	} else {
		perror("");
	}
}
