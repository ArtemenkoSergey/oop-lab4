#include "BTree.cpp"
#include <iostream>

int main()
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

