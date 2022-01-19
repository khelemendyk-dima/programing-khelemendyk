# Лабораторна робота №5. Циклічні конструкці

## 1. Вимоги

### 1.1 Розробник

* Хелемендик Дмитро Олегович;
* студент групи КІТ-121д;
* 07-жовт-2021.

### 1.2 Загальне завдання

Без допомоги зовнішніх бібліотек, отримати корінь заданого числа, реалізуючи
алгоритм ітераційної формули Герона. Виконати роботу в циклах for, while, do-while.

## Хід роботи

### 1. Основна частина

#### 1.1 Опис роботи основної функції:

Ітераційна формула Герона: 0.5 * (x + a / x), де х = (а + 1) / 2; а = задане число. 

#### 1.2 Перелік вхідних даних:

х - позитивне дійсне число(float);
а - задане число, позитивне дійсне число(int), наприклад 25.

#### 1.3 Підтвердження роботи програми

Для підтввердження коректності роботи програми, зупинено відлагодник на строці з "return 0" та введемо команду "print x". Після вводу команди отримали наступне:

```
(lldb) print x
(float) $0 = 5
```
#### 1.4 Структура проекту лабораторної роботи:

```
└── lab05
├── Makefile
├── README.md
├── doc
│ └── lab05.txt
└── src
└── main.c
```
### 2. Виконання роботи

#### 2.1 Цикл while

```
int main()
{
	int a = 25;
	float x = ((float)a + 1) / 2;
	while (x * x - (float)a > 0.00001) {
		x = 0.5f * (x + (float)a / x);
	}
	return 0;
}
```
#### 2.1 Цикл do-while

```
int main()
{
	int a = 25;
	float x = ((float)a + 1) / 2;
	do {
		x = 0.5f * (x + (float)a / x);
	} while (x * x - (float)a > 0.00001);
	return 0;
}
```
#### 2.1 Цикл for

```
int main()
{
	int a = 25;
	float x = ((float)a + 1) / 2;
	for (int i = 0; x * x - (float)a > 0.00001; i++) {
		x = 0.5f * (x + (float)a / x);
	}
	return 0;
}
```
## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду в роботі з циклами for, while, do-while.