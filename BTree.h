#pragma once

#include <stdexcept>		// std::overflow_error std::invalid_argument

template<class Type>
class BTree
{
private:
	// класс узла дерева.
	struct Node
	{
		Type data;
		Node* lelt;
		Node* right;
	};
	
	Node* root;
	
public:
	BTree();
	~BTree();
	void add(Type data);
	Type get(Type key);
	void remove(Type key);
	void show();
private:
	// методы для работы с узлами дерева
	Node* addNode(Node* n, Node* root);		// добавить узел в дерево
	void removeNode(Node* n);	// удалить узел из дерева
	Node* find(Type key, Node* root);		// найти узел по ключу 
	void deleteNode(Node* n);	// удалить узел вместе с потомкати
	
	int height(Node* n) // высота дерева от определенного узла
	void balanse() // балансировка всего дерева
};