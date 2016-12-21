#pragma once

#include <stdexcept>		// std::overflow_error std::invalid_argument

template<class Type>
class BTree
{
private:
	// класс узла дерева.
	class Node
	{
	private:
		Type data;
		unsigned char height;
		Node* lChild;
		Node* rChild;
	public:
		Node();
		Node(Type data);
		~Node();
		Type getData();
		void setData(Type Data);
	private:
		int getBalanseFactor() const;
		void fixHeight();
		Node* rotateRight();
		Node* rotateLeft();
	};
	
	Node* root;
	
public:
	BTree();
	~BTree();
	void add(Type data);
	Type get(Type key);
	void remove(Type key);
private:
	void balanse(Node* node);
};