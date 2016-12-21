#include "BTree.h"

template<class Type>
BTree<Type>::BTree()
{
	root = NULL;
}

template<class Type>
BTree<Type>::~BTree()
{
	if (root != NULL)
		deleteNode(root);
}

template<class Type>
void BTree<Type>::add(Type data)
{
	Node* n = new Node;
	n->data = data;
	n->lelt = NULL;
	n->right = NULL;
	root = addNode(n, root);
	balanse();
}

template<class Type>
Type BTree<Type>::get(Type key)
{
	
}

template<class Type>
void BTree<Type>::remove(Type key)
{
	Node* del = find(key, root);
	removeNode(del, root);
}

template<class Type>
void BTree<Type>::show()
{
	
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::addNode(Node* n, Node* root)
{
	Node* paste;
	if (root==NULL)
		paste = n;
	else
	{
		if(n->data == root->data) // в двоичное дерево нельзя записать 2 одинаковых значения
			throw std::invalid_argument
		if(root-data > n->data)
			root->lelt = addNode(n, root->lelt);
		else
			root->right = addNode(n, root->right);
		paste = root;
	}
	return paste;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::removeNode(Node* del, Node* root)
{
	Node* r = NULL
	if (root != NULL)
	{
		if(root->data > del->data)
			root->lelt = removeNode(del->data, root->lelt);
		else if (root->data < del->data)
			root->right = removeNode(del->data, root->right);
		else
		{
//			if(root->lelt == NULL && root->right == NULL)
			if(root->lelt != NULL && root->right == NULL)
				r = root->lelt;
			else if(root->lelt == NULL && root->right != NULL)
				r = root->right;
			else if(root->lelt != NULL && root->right != NULL)
			{
				Node* t1 = root->right;
				if(t1->lelt != NULL)
				{
					Node* t2 = t1->lelt;
					while(t2->lelt != NULL)
					{
						t1 = t2;
						t2 = t2->left;
					}
					t1->lelt = NULL;
					t2->lelt = del->left;
					t2->right = del->right;
					r = t2;
				}
				else
				{
					t1->lelt = del->lelt;
					r = t1;
				}
			}
		}
	}
	return r;
		
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::find(Type key, Node* root)
{
	if(root->data > key)
		root = find(key, root->lelt);
	else if (root->data < key)
		root = find(key, root->right);
	return root;
}

template<Type>
void BTree<Type>::deleteNode(Node* n)
{
	if(n->left != NULL)
		deleteNode(n->left);
	if(n->right != NULL)
		deleteNode(n->right);
	delete n;
}

