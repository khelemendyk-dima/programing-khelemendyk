/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій: знаходження кількості цілих та
 * дробових чисел, запису їх в показчики.
 *
 * @author Khelemendyk D.
 * @date 09-jan-2022
 * @version 0.1
 */

#include "lib.h"
#include <check.h>

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab12");
	// tcase_add_test(tc_core, test_of_get_int);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
