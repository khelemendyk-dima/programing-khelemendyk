/**
 * @file test.c
 * @brief Файл з тестами на реалізації функції Герона
 *
 * @author Khelemendyk D.
 * @date 07-nov-2021
 */

#include <check.h>
#include <stdlib.h>
#include "lib.h"
#define DATA_SIZE_SUM 3

START_TEST(test_geron)
{
	float input_data_a[] = { 25.0, 9.0, 49.0 };
	float expected_values[] = { 5.0, 3.0, 7.0 };
	for (int i = 0; i < DATA_SIZE_SUM; i++) {
		float actual_value = geron(input_data_a[i]);
		ck_assert_float_eq_tol(expected_values[i], actual_value, 0.01);
	}
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab09");
	tcase_add_test(tc_core, test_geron);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
