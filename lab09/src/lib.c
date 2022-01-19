/**
 * @file lib.c
 * @brief Файл з реалізацією функції 
 * знаходження кореню
 *
 * @author Khelemendyk D.
 * @date 7-nov-2021
 */

#include "lib.h"

float geron(float a)
{
	if (a > 0) {
		float x = (a + 1) / 2;
		while (x * x - a > 0.00001) {
			x = 0.5f * (x + a / x);
		}
		return x;
	} else {
		return 1;
	}
}
