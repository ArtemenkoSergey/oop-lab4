#pragma once

#include <stdexcept>		// std::overflow_error std::invalid_argument
#include <iostream>
#include <ios>
template<class Type>
class BTree
{
private:
	// класс узла дерева.
	struct Node
	{
		Type data;
		Node* left;
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
	Node* removeNode(Node* del, Node* root);	// удалить узел из дерева
	Node* find(Type key, Node* root);		// найти узел по ключу 
	void deleteNode(Node* n);	// удалить узел вместе с потомкати
	
	void showNode(Node* root, int level=0);
	
	// баланисировка дерева
public:
	void balanse(); // балансировка всего дерева
private:
	int height(Node* n); // высота дерева от определенного узла
	int bFactor(Node* root); // фактор баланса для определенного узла.
	
	Node* rotateLeft(Node* n); // правй поворот вокруг узла
	Node* rotateRight(Node* n); // левый поаорот вокруг узла
	Node* balanse(Node* root); // балансировка дерева 
};