/**
 * @mainpage
 * # Загальне завдання
 * Дано два числа олицетворяющих целую и дробную части числа. Написать функцию,
 * которая формирует дроь=бное число на основе этих чисел.
 *
 * @author Khelemendyk D.
 * @date 14-dec-2021
*/

double double_num(int a, int b);
int main()
{
	int num1 = 123;
	int num2 = 456;
	double res = double_num(num1, num2);
	return 0;
}
double double_num(int a, int b)
{
	int ns = 1; // хранит кол-во цифр в числе b
	int b2 = b;
	//cчитает кол-во цифр в b
	while (b2 / 10 > 0) {
		b2 /= 10;
		ns++;
	}
	double zz = 0.1;
	// считает степень, чтобы получить дробную часть числа b
	for (int i = 1; i < ns; i++) {
		zz = zz * 0.1;
	}
	double d = b * zz; // получаю дробную часть числа b
	double res = a + d;
	return res;
}
