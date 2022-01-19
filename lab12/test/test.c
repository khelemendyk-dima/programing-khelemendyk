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
#define DATA_SIZE_BUFFER 1000 // розмір буферу
#define DATA_SIZE_INT 5 // кількість цілих чисел
#define DATA_SIZE_FLOAT 3 // кількість дробових чисел
char buff[N] = "Добрий день, мене звати Іван! Я продав 1 яблуко, 22 \
		апельсинів, 333 кг бананів та 4 ящика гранатів. З продажи \
		яблука я отримав 5 грн, апельсинів - 122.55 грн, \
		бананів - 1500.64 грн, гранатів - 215.77 грн.";

/*
 * Верифікація роботи функції {@link get_int}
 * на основі вхідних даних буферу та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_of_get_int)
{
	int expected_value = 5;
	int actual_value = get_int(buff);
	ck_assert_int_eq(expected_value, actual_value);
}
END_TEST

/*
 * Верифікація роботи функції {@link get_float}
 * на основі вхідних даних буферу та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_of_get_float)
{
	int expected_value = 3;
	int actual_value = get_float(buff);
	ck_assert_int_eq(expected_value, actual_value);
}
END_TEST

/*
 * Верифікація роботи функції {@link get_num_int}
 * на основі вхідних даних буферу, показчику та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_of_get_num_int)
{
	int *array_of_int = (int *)malloc((DATA_SIZE_INT + 1) * sizeof(int));
	int expected_values[] = { 1, 22, 333, 4, 5 };
	get_num_int(buff, array_of_int);
	for (int i = 0; i < DATA_SIZE_INT; i++) {
		ck_assert_int_eq(expected_values[i], *(array_of_int + i));
	}
	free(array_of_int);
}
END_TEST

/*
 * Верифікація роботи функції {@link get_num_float}
 * на основі вхідних даних буферу, показчику та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла	
*/
START_TEST(test_of_get_num_float)
{
	float *array_of_float = (float *)malloc((DATA_SIZE_FLOAT + 1) * sizeof(float));
	float expected_values[] = { (float)122.55, (float)1500.64, (float)215.77 };
	get_num_float(buff, array_of_float);
	for (int i = 0; i < DATA_SIZE_FLOAT; i++) {
		ck_assert_float_eq_tol(expected_values[i], *(array_of_float + i), 0.001);
	}
	free(array_of_float);
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
	TCase *tc_core = tcase_create("lab12");
	tcase_add_test(tc_core, test_of_get_int);
	tcase_add_test(tc_core, test_of_get_float);
	tcase_add_test(tc_core, test_of_get_num_int);
	tcase_add_test(tc_core, test_of_get_num_float);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
