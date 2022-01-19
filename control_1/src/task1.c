/**
 * @mainpage
 * # Загальне завдання
 * Написать программу, которая вычисляет столетие по номеру года.
 * Предусмотреть любой год в диапазоне от 1 до 9900
 *
 * @author Khelemendyk D.
 * @date 14-dec-2021
*/

#define NUMBER_OF_YEAR 1234
int number_of_century(int num); // функция, которая вычисляет столетие
int main()
{
	int res = number_of_century(NUMBER_OF_YEAR);
	return 0;
}
int number_of_century(int year)
{
	int century = year / 100;
	if (century % 100 != 0) {
		century++;
	}
	if (century == 0) {
		century++;
	}
	return century;
}
