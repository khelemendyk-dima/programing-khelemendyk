/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій: заповнення структури,
 * знаходження кількості згорівших лампочок, запис номерів згорівших лампочок.
 *
 * @author Khelemendyk D.
 * @date 11-apr-2022
 * @version 0.1
 */

#include "lib.h"
#include <check.h>

/*
 * Верифікація роботи функції {@link write_to_struct}
 * на основі вхідних даних буферу, роздільника, структури та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_write_to_struct)
{
	char input_data[] = "yes,no,TOV Roga ta koputa,20,15,1800,Globe,E40";
	struct Bulb data;
	char expected_value[8][20] = { "yes", "no", "TOV Roga ta koputa", "20", "15", "1800", "Globe", "E40" };
	write_to_struct(input_data, ",", &data);
	ck_assert_str_eq(data.is_on, &expected_value[0][0]);
	ck_assert_str_eq(data.is_burned, &expected_value[1][0]);
	ck_assert_str_eq(data.factory, &expected_value[2][0]);
	ck_assert_int_eq(data.reverse_counter, atoi(&expected_value[3][0]));
	ck_assert_int_eq(data.vatt, atoi(&expected_value[4][0]));
	ck_assert_int_eq(data.color_temp, atoi(&expected_value[5][0]));
	ck_assert_str_eq(data.shape, &expected_value[6][0]);
	ck_assert_str_eq(data.base_type, &expected_value[7][0]);
}
END_TEST

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
#define DATA_COUNT 3 // кількість лампочок
	char buffer_1[] = "yes,yes,TOV Roga ta koputa,20,15,1800,Globe,E40";
	char buffer_2[] = "no,no,TOV Koputa,30,25,1900,Pear,E27";
	char buffer_3[] = "yes,yes,TOV Romashka,25,150,2500,Candle,E50";
	struct Bulb data[3];
	write_to_struct(buffer_1, ",", &data[0]);
	write_to_struct(buffer_2, ",", &data[1]);
	write_to_struct(buffer_3, ",", &data[2]);
	int actual_value = is_burned_bulb(data, DATA_COUNT);
	int expected_value = 2;
	ck_assert_int_eq(expected_value, actual_value);
}
END_TEST

/*
 * Верифікація роботи функції {@link get_index_burned_bulbs}
 * на основі вхідних даних буферів, показчику та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_get_index_burned_bulbs)
{
#define DATA_COUNT 3 // кількість лампочок
	char buffer_1[] = "yes,yes,TOV Roga ta koputa,20,15,1800,Globe,E40";
	char buffer_2[] = "no,no,TOV Koputa,30,25,1900,Pear,E27";
	char buffer_3[] = "yes,yes,TOV Romashka,25,150,2500,Candle,E50";
	struct Bulb data[3];
	write_to_struct(buffer_1, ",", &data[0]);
	write_to_struct(buffer_2, ",", &data[1]);
	write_to_struct(buffer_3, ",", &data[2]);
	int *burned_bulbs = (int *)malloc(2 * sizeof(int));
	int expected_value[2] = { 0, 2 };
	get_index_burned_bulbs(data, DATA_COUNT, burned_bulbs);
	for (int i = 0; i < 2; i++) {
		ck_assert_int_eq(expected_value[i], *(burned_bulbs + i));
	}
	free(burned_bulbs);
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
	TCase *tc_core = tcase_create("lab14");
	tcase_add_test(tc_core, test_write_to_struct);
	tcase_add_test(tc_core, test_is_burned_bulb);
	tcase_add_test(tc_core, test_get_index_burned_bulbs);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
