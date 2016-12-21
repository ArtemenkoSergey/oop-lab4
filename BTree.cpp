#include "BTree.h"

template<class Type>
BTree<Type>::Node::Node()
{
	height = 1;
	lChild = NULL;
	rChild = NULL;
}

template<class Type>
BTree<Type>::Node::Node(Type data)
{
	height = 1;
	lChild = NULL;
	rChild = NULL;
	this->data = data;
}

template<class Type>
BTree<Type>::Node::~Node()
{
	if(lChild!=NULL)
		delete lChild;
	if(rChild!=NULL)
		delete rChild;
}

template<class Type>
Type BTree<Type>::Node::getData()
{
	return data;
}

template<class Type>
void BTree<Type>::Node::setData(Type data)
{
	this->data = data;
}

template<class Type>
int BTree<Type>::Node::getBalanseFactor() const
{
	return (lChild?lChild->height:0) - (rChild?rChild->height:0);
}

template<class Type>
void BTree<Type>::Node::fixHeight()
{
	unsigned char hl = (lChild?lChild->height:0);
	unsigned char hr = (rChild?rChild->height:0);
	height = (hl>hr?hl:hr)+1;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::Node::rotateRight()
{
	Node* q = lChild;
	lChild = q->rCild;
	q->rChild = this;
	this->fixHeight();
	q->fixHeigth;
	return q;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::Node::rotateLeft()
{
	Node* q = rChild;
	rChild = q->lCild;
	q->lChild = this;
	this->fixHeight();
	q->fixHeigth;
	return q;
}

template<class Type>
BTree<Type>::BTree()
{
	root = NULL;
}

template<class Type>
BTree<Type>::~BTree()
{
	if(root != NULL)
		delete root;
}

template<class Type>
void BTree<Type>add(Type data)
{
	
}

template<class Type>
Type BTree<Type>::get(Type key)
{
	
}

template<class Type>
void BTree<Type>::remove(Type key)
{
	
}