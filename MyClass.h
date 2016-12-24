#pragma once

#include <cstring>		// strlen() strcpy()
#include <iostream> 	// std::ostream

// Класс для примера использования сложных типов с шабоном двоичного дерева BTree
// перегружены операторы присваивания(=), сравнения(==, <) для работы шаблона.
// и оператор вывода в поток(<<) для удобства использования в примере.
// класс имеет 2 свойства key по этому свойству происходит сравнивание объектов класса
// и data в котором хранится строка символов.
class MyClass
{
private:
	int key;
	char* data;
public:
	MyClass();					// конструктор по умолчанию
	MyClass(const MyClass&);	// конструктор копирования
	~MyClass();
	MyClass& setKey(int);		
	MyClass& setData(char*);
	void operator=(const MyClass&);
	friend bool operator==(const MyClass&, const MyClass&);
	friend bool operator<(const MyClass&, const MyClass&);
	friend std::ostream& operator<<(std::ostream& os, const MyClass& mc);
};

