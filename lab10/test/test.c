/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Khelemendyk D.
 * @date 07-nov-2021
 */

#include <check.h>
#include <stdlib.h>
#include "lib.h"
#define SIZE_OF_ARRAY 3

/*
 * Верифікація роботи функції {@link get_diagonal}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_diagonal)
{
	int **input_data_a = (int **)malloc(SIZE_OF_ARRAY * sizeof(int *));
	for (int i = 0; i < SIZE_OF_ARRAY; i++) {
		*(input_data_a + i) = (int *)malloc(SIZE_OF_ARRAY * sizeof(int));
	}
	int *input_data_b = (int *)malloc(SIZE_OF_ARRAY * sizeof(int));
	for (int i = 0; i < SIZE_OF_ARRAY; i++) { // заповнення масиву від 1 до 9
		for (int j = 0; j < SIZE_OF_ARRAY; j++) {
			*(*(input_data_a + i) + j) = (i * SIZE_OF_ARRAY + j) + 1;
		}
	}
	int expected_values[] = { 1, 5, 9 };
	get_diagonal(input_data_a, input_data_b, SIZE_OF_ARRAY);
	for (int i = 0; i < SIZE_OF_ARRAY; i++) {
		ck_assert_int_eq(expected_values[i], *(input_data_b + i));
	}
	for (int i = 0; i < N; i++) {
		free(*(input_data_a + i));
	}
	free(input_data_a);
	free(input_data_b);
}
END_TEST

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab10");
	tcase_add_test(tc_core, test_diagonal);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
