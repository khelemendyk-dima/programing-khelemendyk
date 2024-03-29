# Лабораторна робота №3. Розробка лінійних програм

## 1 Вимоги

### 1.1 Розробник

* Хелемендик Дмитро Олегович;
* студент групи КІТ-121д;
* 22-вер-2021.

### 1.2 Загальне завдання

Підрахувати суму чисел у заданому діапазоні. Наприклад, при вхідних даних 50 та 52 повинно бути 50+51+52=153.

## Хід роботи

### 1. Виконання завдання

Спочатку створюю змінні a, b, c та надаю їм значення:

```
int main()
{
	int a, b, c;
	a = 50;
	b = 55;
	c = (b - a) + 1;
}
```
Далі створюю змінну res, в якій буде результат рахуватис за формулою:

```
int res = (a + b) * c / 2;

```
Тоді мій код має такий вигляд:

```
int main()
{
	int a, b, c;
	a = 50;
	b = 55;
	c = (b - a) + 1;
	int res = (a + b) * c / 2;
}
```
### 2. Зборка проекту та вивід результату за допомогою lldb

Компілюю проект за допомогою команди make all. Виконую програму за домогою lldb, запускаю файл командою lldb main.bin, далі дивлюсь код командою l:

```
(lldb) l
   22  	{
   23  		int a, b, c;
   24  		a = 50;
   25  		b = 55;
   26  		c = (b - a) + 1;
   27  		int res = (a + b) * c / 2;
   28  	}
```
Ставлю брейкпоінт на 25 строці командою 'b 25', запускаю програму, виконую її до завершення:

```
(lldb) b 25
Breakpoint 1: where = main.bin`main + 13 at main.c:25:4, address = 0x000000000040111d
(lldb) r
Process 6053 launched: '/home/dima/dev/programing-khelemendyk/lab03/dist/main.bin' (x86_64)
Process 6053 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x000000000040111d main.bin`main at main.c:25:4
   22  	{
   23  		int a, b, c;
   24  		a = 50;
-> 25  		b = 55;
   26  		c = (b - a) + 1;
   27  		int res = (a + b) * c / 2;
   28  	}
(lldb) thread until 28
Process 6053 resuming
Process 6053 stopped
* thread #1, name = 'main.bin', stop reason = step until
    frame #0: 0x000000000040114d main.bin`main at main.c:28:1
   25  		b = 55;
   26  		c = (b - a) + 1;
   27  		int res = (a + b) * c / 2;
-> 28  	}
```
Тепер дивлюся значення змінних командою v:

```
(lldb) v
(int) a = 50
(int) b = 55
(int) c = 6
(int) res = 315
```

Змінна res=315, а значить завдання виконано.

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду в розробці лінійної програми.
