#pragma once

#include <stdexcept>		// std::invalid_argument std::logic_error
//#include <iostream>
//#include <ios>

// шаблон класса бинарного дерева
// тип Type должен поддерживать следующие операции: =, ==, <
template<class Type>
class BTree
{
private:
	// структура узла дерева.
	struct Node
	{
		Type data;
		Node* left;
		Node* right;
	};
	
	Node* root;				// ссылка на корень дерева
	int size;				// количество узлов дерева
	
public:
	BTree();				// конструктор по умолчанию
	BTree(BTree& tree);		// конструктор копирования
	~BTree();				// деструктор
	void add(Type data);	// добавить узел в дерево
	Type get(Type key);		// найти значение по ключу
	void remove(Type key);	// удалить значение по ключу
	int getSize();			// вернуть размер дерева
//	void show();			// отладочная функция для просмотра структуры дерева
private:
	// методы для работы с узлами дерева
	Node* addNode(Node* n, Node* root);		// добавить узел в дерево
	Node* removeNode(Node* del, Node* root);	// удалить узел из дерева
	Node* find(Type key, Node* root);		// найти узел по ключу 
	void deleteNode(Node* n);	// удалить узел вместе с потомкати
	Node* copyNode(Node* root); // скопировать узел вместе с потомками
	
//	void showNode(Node* root, int level=0);	// отладочная функция для просмотра структуры дерева
	
	// баланисировка дерева
//public:
//	void balanse(); // балансировка всего дерева
private:
	int height(Node* n); // высота дерева от определенного узла
	int bFactor(Node* root); // фактор баланса для определенного узла.
	
	Node* rotateLeft(Node* n); // правй поворот вокруг узла
	Node* rotateRight(Node* n); // левый поаорот вокруг узла
	Node* balanse(Node* root); // балансировка дерева 
};