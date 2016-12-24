#include "BTree.h"

// конструктор по умолчанию
// создает пустое дерево
template<class Type>
BTree<Type>::BTree()
{
	root = NULL;
	size = 0;
}

// конструктор копирования
// принимает: ссылку на дерево
// создает копию дерева
template<class Type>
BTree<Type>::BTree(BTree& tree)
{
	root = copyNode(tree.root);
	size = tree.size;
}

// деструктор
// освобождает память занимаемую узлами дерева
template<class Type>
BTree<Type>::~BTree()
{
	if (root != NULL)
		deleteNode(root);
}

// Добавляет в дереву значение
// приниммает: значение добавляемое в дерево
// создает новый узел, добавляет его в дерево, 
// увеличивает значение размера дерева на 1
template<class Type>
void BTree<Type>::add(Type data)
{
	Node* n = find(data, root);
	if( n!= NULL)
		throw std::invalid_argument("Нельзя записать 2 одинаковых значения");
	n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	root = addNode(n, root);
	size++;
}

// возвращает значение по ключу
// принимает: ключ такогог же типа как и значения в дереве
// возвращает: значение хранимое в дереве.
// выполняет поиск по ключу в дереве начиная с корня
// если значение не найдено бросает исключение std::logic_error
template<class Type>
Type BTree<Type>::get(Type key)
{
	Node* f = find(key, root);
	if(f == NULL)
		throw std::logic_error("Попытка найти элемент дерева по не существующему ключу");
	return f->data;
}

// удаляет значение из дерева по ключу
// принимает: ключ такогог же типа как и значения в дереве
// выполняет поиск удаляемого узла по ключу
// если узел не найден бросает исключение std::logic_error
// удаляет найденный узел из дерева, освобождает память занимаемую узлом
// балансирует дерево, уменьшает значение размера дерева на 1
template<class Type>
void BTree<Type>::remove(Type key)
{
	Node* del = find(key, root);
	if(del == NULL)
		throw std::logic_error("Попытка удалить элемент дерева по не существующему ключу");
	root = removeNode(del, root);
	delete del;
	root = balanse(root);
	size--;
}

// возвращает значение размера дерева
template<class Type>
int BTree<Type>::getSize()
{
	return size;
}
//
//template<class Type>
//void BTree<Type>::show()
//{
//	showNode(root);
//}

// добавляет узел в дерево
// принимает: указатель на добавляемый узел, указатель на корень дерева.
// возвращает: указатель на новый корень дерева.
template<class Type>
typename BTree<Type>::Node* BTree<Type>::addNode(Node* n, Node* root)
{
	Node* paste;
	if (root==NULL)
		paste = n;
	else
	{
		if(n->data < root->data)
			root->left = addNode(n, root->left);
		else
			root->right = addNode(n, root->right);
		paste = balanse(root);
	}
	return paste;
}

// удаляет узел из дерева
// принимает: указатель на удаляемый узел, указатель на корень дерева
// возвращает: указатель на новый корень дерева
template<class Type>
typename BTree<Type>::Node* BTree<Type>::removeNode(Node* del, Node* root)
{
	Node* r = NULL;
	if (root != NULL)
	{
		if(del->data < root->data)
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

// выполняет поиск узла дерева по ключу
// принимает: ключ, указатель на корень дерева
// возвращает: указатель на найденый узел или NULL если узел не найден
template<class Type>
typename BTree<Type>::Node* BTree<Type>::find(Type key, Node* root)
{
	if(root!=NULL && !(root->data == key))
	{
		if(key < root->data)
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

// освобождает память занимаемую узлом и его потомками
// НЕ УДАЛЯЕТ УЗЕЛ ИЗ ДЕРЕВА, ТОЛЬКО ДЛЯ ИСПОЛЬЗОВАНИЯ В ДЕСТУКТОРЕ
// принимает: указатель на узел дерева который надо удалить
template<class Type>
void BTree<Type>::deleteNode(Node* n)
{
	if(n->left != NULL)
		deleteNode(n->left);
	if(n->right != NULL)
		deleteNode(n->right);
	delete n;
}

// создает копию узла и его потомков
// принимает: указатель на узел который надо скопировать
// возвращает: указатель на копию узла
template<class Type>
typename BTree<Type>::Node* BTree<Type>::copyNode(Node* root)
{
	if(root != NULL)
	{
		Node* newNode = new Node;
		newNode->data = root->data;
		newNode->left = copyNode(root->left);
		newNode->right = copyNode(root->right);
		return newNode;
	}
	return NULL;
}

//template<class Type>
//void BTree<Type>::showNode(Node* root, int level)
//{	
//	if (root == NULL)
//	{
//		for(int i=0; i < level; i++)
//			std::cout << "   ";
//		std::cout << "  *" << std::endl;
//	}
//	else
//	{
//		showNode(root->left, level+1);
//		for(int i=0; i < level; i++)
//			std::cout << "   ";
//		std::cout.setf(std::ios::right);
//		std::cout.width(3);
//		std::cout << root->data << std::endl;
//		showNode(root->right, level+1);
//	}
//}

//template<class Type>
//void BTree<Type>::balanse()
//{
//	root = balanse(root);
//}

// возвращает высоту дерева
// принимает: указатель на корень дерева
// возвращает высоту дерева
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

// вычисляет фактор баланса деверва (разницу высоты его веток)
// принимает: указатель на корень дерева
// возвращает: фактор баланса 
// фактор баланса > 0 если левая ветка больше правой 
template<class Type>
int BTree<Type>::bFactor(Node* n)
{
	int r = 0;
	if (n != NULL)
		r = height(n->left) - height(n->right);
	return r; 
}

// методы балансировки
// поворачивает дерево в лево 
// принимает: указатель на корень
// возвращает: указатель на новый корень
template<class Type>
typename BTree<Type>::Node* BTree<Type>::rotateLeft(Node* n)
{
	Node* t = n->right;
	n->right = t->left;
	t->left = n;
	return t;
}

// поворачивает дерево в прфво
// принимает: указатель на корень
// возвращает: указатель на новый корень
template<class Type>
typename BTree<Type>::Node* BTree<Type>::rotateRight(Node* n)
{
	Node* t = n->left;
	n->left = t->right;
	t->right = n;
	return t;
}

// балансирует дерево
// принимает: указатель на корень
// возвращает: указатель на новый корень
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