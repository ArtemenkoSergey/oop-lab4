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
	n->left = NULL;
	n->right = NULL;
	root = addNode(n, root);
//	balanse();
}

template<class Type>
Type BTree<Type>::get(Type key)
{
	
}

template<class Type>
void BTree<Type>::remove(Type key)
{
	Node* del = find(key, root);
	root = removeNode(del, root);
	delete del;
}

template<class Type>
void BTree<Type>::show()
{
		showNode(root);
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
			throw std::invalid_argument("");
		if(root->data > n->data)
			root->left = addNode(n, root->left);
		else
			root->right = addNode(n, root->right);
		paste = root;
	}
	return paste;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::removeNode(Node* del, Node* root)
{
	Node* r = NULL;
	if (root != NULL)
	{
		if(root->data > del->data)
		{
			root->left = removeNode(del, root->left);
			r = root;
		}
		else if (root->data < del->data)
		{
			root->right = removeNode(del, root->right);
			r = root;
		}
		else
		{
//			if(root->left == NULL && root->right == NULL)
			if(root->left != NULL && root->right == NULL)
				r = root->left;
			else if(root->left == NULL && root->right != NULL)
				r = root->right;
			else if(root->left != NULL && root->right != NULL)
			{
				Node* t1 = root->right;
				if(t1->left != NULL)
				{
					Node* t2 = t1->left;
					while(t2->left != NULL)
					{
						t1 = t2;
						t2 = t2->left;
					}
					t1->left = NULL;
					t2->left = del->left;
					t2->right = del->right;
					r = t2;
				}
				else
				{
					t1->left = del->left;
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
	if(root->data != key && root!=NULL)
	{
		if(root->data > key)
		{
			if (root->left != NULL)
				root = find(key, root->left);
			else
				root = NULL;
		}
		else if (root->data < key)
		{
			if (root->right != NULL)
				root = find(key, root->right);
			else
				root = NULL;
		}
	}
	return root;
}

template<class Type>
void BTree<Type>::deleteNode(Node* n)
{
	if(n->left != NULL)
		deleteNode(n->left);
	if(n->right != NULL)
		deleteNode(n->right);
	delete n;
}

template<class Type>
void BTree<Type>::showNode(Node* root, int level)
{	
	if (root == NULL)
	{
		for(int i=0; i < level; i++)
			std::cout << "   ";
		std::cout << "  *" << std::endl;
	}
	else
	{
		showNode(root->left, level+1);
		for(int i=0; i < level; i++)
			std::cout << "   ";
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout << root->data << std::endl;
		showNode(root->right, level+1);
	}
}

template<class Type>
void BTree<Type>::balanse()
{
	root = balanse(root);
}

template<class Type>
int BTree<Type>::height(Node* root)
{
	int r  = 0;
	if(root != NULL)
	{
		int lH = height(root->left);	// высота левой ветки
		int rH = height(root->right);	// высота правой ветки
		r = (lH>rH?lH:rH)+1;
	}
	return r;
}

template<class Type>
int BTree<Type>::bFactor(Node* n)
{
	int r = 0;
	if (n != NULL)
		r = height(n->left) - height(n->right);
	return r; 
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::rotateLeft(Node* n)
{
	Node* t = n->right;
	n->right = t->left;
	t->left = n;
	return t;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::rotateRight(Node* n)
{
	Node* t = n->left;
	n->left = t->right;
	t->right = n;
	return t;
}

template<class Type>
typename BTree<Type>::Node* BTree<Type>::balanse(Node* root)
{
	int bf = bFactor(root);
	if (bf > 1)
	{
		if(bFactor(root->left) < 0)
			root->left = rotateLeft(root->left);
		root = rotateRight(root);
	}
	if (bf < -1)
	{
		if(bFactor(root->right) > 0)
			root->right = rotateRight(root->right);
		root = rotateLeft(root);
	}
	return root;
}