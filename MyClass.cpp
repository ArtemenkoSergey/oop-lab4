#include "MyClass.h"

MyClass::MyClass()
{
	key = 0;
	data = NULL;
}

MyClass::MyClass(const MyClass& other)
{
	key = other.key;
	data = new char[strlen(other.data)];
	strcpy(data, other.data);
}

MyClass::~MyClass()
{
	if (data != NULL)
		delete[] data;
}

MyClass& MyClass::setKey(const int key)
{
	this->key = key;
	return *this;
}

MyClass& MyClass::setData(const char* newData)
{
	if (data != NULL)
		delete[] data;
	data = new char[strlen(newData)];
	strcpy(data, newData);
	return *this;
}


void MyClass::operator=(const MyClass& right)
{
	key = right.key;
	if (data != NULL)
		delete[] data;
	data = new char[strlen(right.data)];
	strcpy(data, right.data);
}

bool operator==(const MyClass& left, const MyClass& right)
{
	return left.key == right.key;
}

bool operator<(const MyClass& left, const MyClass& right)
{
	return left.key < right.key;
}

std::ostream& operator<<(std::ostream& os, const MyClass& mc)
{
	const char* tmp = "Значение отсутствует.";
	if (mc.data != NULL)
		tmp = mc.data;
	os << "Key: " << mc.key << ", Data: " << tmp;
	return os;
}

