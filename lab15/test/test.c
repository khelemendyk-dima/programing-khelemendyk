/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій: знаходження згорівших лампочок.
 *
 * @author Khelemendyk D.
 * @date 01-may-2022
 * @version 0.1
 */

#include "list.h"
#include <check.h>

/*
 * Верифікація роботи функції {@link is_burned_bulb}
 * на основі вхідних даних буферів, структури, кількості лампочок
 * та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_is_burned_bulb)
{
	struct Container *container = malloc(1 * sizeof(struct Container));
	container->bulbs = malloc(3 * sizeof(struct Bulb));
	container->size = 3;
	struct Bulb bulbs_array[3] = { { "yes", "yes", "TOV Roga ta koputa", 20, 15, 1800, "Globe", "E40" },
				       { "no", "no", "TOV Koputa", 30, 25, 1900, "Pear", "E27" },
				       { "yes", "yes", "TOV Romashka", 25, 150, 2500, "Candle", "E50" } };
	memcpy(container->bulbs, bulbs_array, 3 * sizeof(struct Bulb));
	int actual_value = is_burned_bulb(container);
	int expected_value = 1;
	ck_assert_int_eq(expected_value, actual_value);
	free(container->bulbs);
	free(container);
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
	TCase *tc_core = tcase_create("lab15");
	tcase_add_test(tc_core, test_is_burned_bulb);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
