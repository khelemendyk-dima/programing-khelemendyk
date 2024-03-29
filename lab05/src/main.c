/**
 * @mainpage
 * # Загальне завдання
 * Без допомоги зовнішніх бібліотек, отримати корінь заданого числа, реалізуючи
 * алгоритм ітераційної формули Герона.
 *
 *
 * @author Khelemendyk D.
 * @date 24-sep-2021
 */

/** #include "lib.h" */

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - 
 * - 
 * - 
 */
int main()
{
	int a = 39;
	float x = ((float)a + 1) / 2;
	while (x * x - (float)a > 0.00001) {
		x = 0.5f * (x + (float)a / x);
	}
	return 0;
}
