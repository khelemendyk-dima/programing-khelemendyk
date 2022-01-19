/**
 * @file test.c
 * @brief Файл з тестами на реалізації функції оберненної матриці
 *
 * @author Khelemendyk D.
 * @date 03-jan-2022
 */

#include "lib.h"
#include <check.h>
#define DATA_SIZE_MATRIX 3 // розмір матриці

/*
 * Верифікація роботи функції {@link inverse_matrix}
 * на основі вхідних даних матриці та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_of_inverse_matrix)
{
	float **matrix_a = (float **)malloc(DATA_SIZE_MATRIX * sizeof(float *));
	for (int r = 0; r < DATA_SIZE_MATRIX; r++) {
		*(matrix_a + r) = (float *)malloc(DATA_SIZE_MATRIX * sizeof(float));
	}
	float **matrix_b = (float **)malloc(DATA_SIZE_MATRIX * sizeof(float *));
	for (int r = 0; r < DATA_SIZE_MATRIX; r++) {
		*(matrix_b + r) = (float *)malloc(DATA_SIZE_MATRIX * sizeof(float));
	}
	// input data
	*(*(matrix_a + 0) + 0) = 2;
	*(*(matrix_a + 0) + 1) = 5;
	*(*(matrix_a + 0) + 2) = 7;
	*(*(matrix_a + 1) + 0) = 6;
	*(*(matrix_a + 1) + 1) = 3;
	*(*(matrix_a + 1) + 2) = 4;
	*(*(matrix_a + 2) + 0) = 5;
	*(*(matrix_a + 2) + 1) = -2;
	*(*(matrix_a + 2) + 2) = -3;
	float expected_values[] = { 1, -1, 1, -38, 41, -34, 27, -29, 24 };
	inverse_matrix(matrix_a, matrix_b, DATA_SIZE_MATRIX);
	for (int r = 0; r < DATA_SIZE_MATRIX; r++) {
		for (int c = 0; c < DATA_SIZE_MATRIX; c++) {
			ck_assert_float_eq_tol(expected_values[r * DATA_SIZE_MATRIX + c], *(*(matrix_b + r) + c), 0.001);
		}
	}
	for (int r = 0; r < DATA_SIZE_MATRIX; r++) {
		free(*(matrix_a + r));
	}
	free(matrix_a);
	for (int r = 0; r < DATA_SIZE_MATRIX; r++) {
		free(*(matrix_b + r));
	}
	free(matrix_b);
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
	TCase *tc_core = tcase_create("lab11");
	tcase_add_test(tc_core, test_of_inverse_matrix);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
