#include "BTree.cpp"
#include "MyClass.h"
#include <iostream>
#include <cstring>		// strlen()

void classExample();
void intExample();


int main()
{
	int exit = 0;
	while(!exit)
	{	
		std::cout << "1. Пример работы шаблона с простым типом данных" << std::endl;
		std::cout << "2. Пример работы шаблона со сложным типом данных" << std::endl;
		std::cout << "0. Выход" << std::endl;
		char ch;
		std::cin >> ch;
		switch (ch)
		{
			case '1':
				intExample();
				break;
			case '2':
				classExample();
				break;
			case '0':
				exit = 1;
				break;
			default:
				std::cout << "Введено: " << ch << std::endl;
		}
	}
}

void classExample()
{
	int exit = 0;
	const int bufSize = 256;
	char buffer[bufSize];
	MyClass tmp;
	BTree<MyClass> tree;
	
	std::cout << "Пример работы шаблона со сложным типом MyClass" << std::endl;
	std::cout << "Класс имеет 2 свойства int key и char* data" << std::endl;
	std::cout << "свойство key значение по которому сравниваются объекты данного класса" << std::endl;
	std::cout << "свойство data хранит строку символов" << std::endl;
	while(!exit)
	{	
		std::cout << "1. Добавить значение в дерево" << std::endl;
		std::cout << "2. Найти значение в дереве" << std::endl;
		std::cout << "3. Удалить значение из дерева" << std::endl;
		std::cout << "0. Выход" << std::endl;
		char ch;
		int t;
		std::cin >> ch;
		switch (ch)
		{
			case '1':
				do
				{
					std::cout << "Введите значения полей объекта, добавлемого в дерево:" << std::endl;
					std::cout << "Введите значение поля key (целое число)" << std::endl;
					std::cin >> t;
					std::cout << "Введите значение поля data (строка длинной не более 255 символов)" << std::endl;
					std::cin >> buffer;
//					buffer[strlen(buffer)]='\0';
					tmp.setKey(t).setData(buffer);
					try
					{
						tree.add(tmp);
						std::cout << "Значение " << tmp << " добавлено в дерево" << std::endl;
						break;
					}
					catch(std::invalid_argument ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '2':
				do
				{
					std::cout << "Введите ключ для поиска:" << std::endl;
					std::cin >> t;
					tmp.setKey(t);
					try
					{
						tmp = tree.get(tmp);
						std::cout << "Найден объеект: " << tmp << std::endl;
						break;
					}
					catch(std::logic_error ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '3':
				do
				{
					std::cout << "Введите ключ удаляемого объекта:" << std::endl;
					std::cin >> t;
					tmp.setKey(t);
					try
					{
						tree.remove(tmp);
						std::cout << "Объект удален из дерева." << std::endl;
						break;
					}
					catch(std::logic_error ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '0':
				exit = 1;
				break;
			default:
				std::cout << "Введено: " << ch << std::endl;
		}
	}
}

void intExample()
{
	int exit = 0;
	BTree<int> tree;
	
	std::cout << "Пример работы шаблона с простым типом int" << std::endl;
	while(!exit)
	{	
		std::cout << "1. Добавить значение в дерево" << std::endl;
		std::cout << "2. Найти значение в дереве" << std::endl;
		std::cout << "3. Удалить значение из дерева" << std::endl;
		std::cout << "0. Выход" << std::endl;
		char ch;
		int tmp;
		std::cin >> ch;
		switch (ch)
		{
			case '1':
				do
				{
					std::cout << "Введите целое число которое будет добавлено в дерево:" << std::endl;
					std::cin >> tmp;
					try
					{
						tree.add(tmp);
						std::cout << "Значение " << tmp << " добавлено в дерево" << std::endl;
						break;
					}
					catch(std::invalid_argument ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '2':
				do
				{
					std::cout << "Введите искомое целое число:" << std::endl;
					std::cin >> tmp;
					try
					{
						tmp = tree.get(tmp);
						std::cout << "Найдено значение: " << tmp << std::endl;
						break;
					}
					catch(std::logic_error ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '3':
				do
				{
					std::cout << "Введите удаляемое из дерева число:" << std::endl;
					std::cin >> tmp;
					try
					{
						tree.remove(tmp);
						std::cout << "Число удалено из дерева" << std::endl;
						break;
					}
					catch(std::logic_error ex)
					{
						std::cerr << ex.what() << std::endl;
					}
				}while(1);
				break;
			case '0':
				exit = 1;
				break;
			default:
				std::cout << "Введено: " << ch << std::endl;
		}
	}
}