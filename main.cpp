#include <iostream>
#include "Header.h"
using namespace std;

template <typename T>
int comparison(T data1, T data2)
{
	T item1=data1;
	T item2=data2;
	if (item1 < item2)
	{
		return -1;
	}
	else if (item1 > item2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int main()
{
	//SplayTree<T>::fcnPtr = comparison;
	int arr[10] = { 6, 5, 8, 3, 9, 2, 7, 12, 1, 4 };
	SplayTree<int> tree(comparison);
	for (int i = 0; i < 10; ++i)
		tree.insert(arr[i]);
	tree.display();
	tree.search(3);
	return 0;

}