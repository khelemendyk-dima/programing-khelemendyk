# Лабораторна робота №7. Функції

## 1. Вимоги

### 1.1 Розробник

* Хелемендик Дмитро Олегович;
* студент групи КІТ-121д;
* 04-лист-2021.

### 1.2 Загальне завдання

Переробити програми, що були розроблені під час виконання лабораторних робіт з тем “Масиви” та "Цикли" таким чином, щоб використовувалися функції для обчислення результату. Параметри одного з викликів функції повинні бути згенеровані за допомогою генератора псевдовипадкових чисел random(). Продемонструвати встановлення вхідних даних через аргументи додатка (параметри командної строки). Обробити випадок, коли дані не передались - у цьому випадку вони матимуть значення за умовчуванням, обраними розробником.

## Хід роботи

### 1. Основна частина

#### 1.1 Опис роботи основної функції:

Створюю змінну res, яка виконує фунцію geron(знаходе корінь із заданного числа користувачем). Далі створюю константу А, яка є розміром масиву array, потім виконую функцію push(заповнює массив числами менше 100 за допомогою random). Далі виконується функція shiftLeft(зсув вліво на задану кількість користувачем). Після цього створюю двовимірний масив matrix та заповнюю його одновимірним масивом array.
#### 1.2 Перелік вхідних даних:

float res - результат від знаходження кореню;
const int A - розмір масивів array та matrix;
array[A * A] - одномірний масив;
int matrix[A][A] - двовимірний масив; 
int push() - функція, котра заповнює масив псевдорандомними числами менше 100; 
int shiftLeft() - функція, котра робить зсув вліво;

#### 1.3 Підтвердження роботи програми

Для підтввердження коректності роботи програми запускаю відлагодник з двома аргументами: 25(знаходження кореню) та 2(кількість зсувів). Зупинено відлагодник на строчках 21(демонструє функцію gerin), 24(демонструє функцію push), 27(демонструє функцію shiftLeft), 34(return 0) та вводимо "print res", "print array" та "print matrix". Після вводу команди отримали наступне:

```
(lldb) b 21 ...
(lldb) print res
(float) $0 = 5

(lldb) b 24 ...
(lldb) print array
(int [9]) $0 = ([0] = 83, [1] = 86, [2] = 77, [3] = 15, [4] = 93, [5] = 35, [6] = 86, [7] = 92, [8] = 49)

(lldb) b 27 ...
(lldb) print array
(int [9]) $2 = ([0] = 77, [1] = 15, [2] = 93, [3] = 35, [4] = 86, [5] = 92, [6] = 49, [7] = 83, [8] = 86)

(lldb) b 34 ...
(lldb) print matrix
(int [3][3]) $3 = {
  [0] = ([0] = 77, [1] = 15, [2] = 93)
  [1] = ([0] = 35, [1] = 86, [2] = 92)
  [2] = ([0] = 49, [1] = 83, [2] = 86)
}
```
#### 1.4 Структура проекту лабораторної роботи:

```
└── lab07
   ├── Makefile
   ├── README.md
   ├── doc
   │ └── lab07.txt
   └── src
     └── main.c
```
## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду в розробці функцій, роботі з random() та з вхідними даними через аргументи додатка (параметри командної строки).
