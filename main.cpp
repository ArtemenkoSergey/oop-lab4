#include "BTree.cpp"


int main(int argc, char **argv)
{
	BTree<int> t;
	t.add(10);
	t.add(5);
	t.add(8);
//	t.show();
//	std::cout << "------------------" << std::endl;
//	t.add(20);
//	t.add(6);
//	t.show();
//	std::cout << "------------------" << std::endl;
//	t.balanse();
	t.add(11);
//	t.show();
//	std::cout << "------------------" << std::endl;
	BTree<int> n = t;
	n.show();
}
