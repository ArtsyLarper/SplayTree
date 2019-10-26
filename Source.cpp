//node should have a parent, a left child node pointer, a right child node pointer, a parent node pointer, and templated data

//travel function should take a node and a data point and return a node
//the travel function will compare the data in the 

//my binary search tree class should take a function pointer in its constructor
#include<iostream>
#include"Header.h"

using namespace std;

template <typename T>
void SplayTree<T>::comparefunct(int(*fun)(T, T)){
	this->compareFunction = fun;
}

/*template<typename T>
BinarySearchTree<T>::BinarySearchTree(int(*fun)(T, T)): root(nullptr)
{
}
*/
template<typename T>
inline node<T>* SplayTree<T>::travel(T item, node<T> * X)
{
	if (item == X->data)
	{
		return X;
	}
	
	
	if (compareFunction(item, X->data)==-1)
	{
			if (X->rightChild == nullptr)
			{
				cout << "value not found" << endl;
				throw - 1;
				return nullptr;
			}
			 return travel(item, X->rightChild);
	}
	if (compareFunction(item, X->data) == 1)
	{
		if (X->leftChild == nullptr)
		{
			cout << "value not found" << endl;
			throw - 1;
			return nullptr;
		}
		return travel(item, X->leftChild);
	}
	
}



//not complete
template<typename T>
void SplayTree<T>::disintegrate(node<T> * Y)
{
	node<T>* temp1 = nullptr;
	temp1 = findPredessor(Y);
	if (Y->rightChild == nullptr || Y->leftChild == nullptr)
	{
		if (Y->rightChild == nullptr)
		{
			if (Y == Y->parent->leftChild)
			{
				Y->parent->leftChild = Y->leftChild;
				Y->leftChild->parent = Y->parent;
				delete Y;
				return;
			}
			else
			{
				Y->parent->rightChild = Y->leftChild;
				Y->leftChild->parent = Y->parent;
				delete Y;
				return;
			}
		}
		else
		{
			if (Y == Y->parent->rightChild)
			{
				Y->parent->rightChild = Y->rightChild;
				Y->rightChild->parent = Y->parent;
				delete Y;
				return;
			}
			else
			{
				Y->parent->leftChild = Y->rightChild;
				Y->rightChild->parent = Y->parent;
				delete Y;
				return;
			}
		}
	}
	else
	{
		Y->data = temp1->data;
		temp1->leftChild->parent = temp1->parent;
		temp1->parent->leftChild = temp1->leftChild;
		delete temp1;
		return;
	}
}

/*
template<typename T>
void inline SplayTree<T>::insert(T input)
{
	if (root == nullptr)
	{
		root = new node<T>;
		root->data = input;
		return;
	}
	if (root != nullptr)
	{
		node<T>*temp, *p;
		temp = root;
		while (temp->data != input)
		{
			//temp->height = height + 1;
			if (compareFunction(input, temp->data) == 1)  //ADD a comment to remind you where the node goes
			{
				if (temp->rightChild == nullptr)
				{
					p = new node<T>;
					p->data = input;
					p->parent = temp;
					temp->rightChild = p;
					return;

					/*temp->rightChild = new node<T>;
					p = temp;
					temp = temp->rightChild;
					temp->parent = p;
					temp->data = input;
				}
				else
				{
					temp = temp->rightChild;
				}
			}
			if (compareFunction(input, temp->data) == -1)
			{
				if (temp->leftChild == nullptr)
				{
					p = new node<T>;
					p->data = input;
					p->parent = temp;
					temp->leftChild = p;
					return;
				}
				else
				{
					temp = temp->leftChild;
				}
			}
		}

	}
}

template<typename T>
void SplayTree<T>::remove(T input)
{
	try
	{
		node<T>*temp = travel(input, root);
		if (temp->leftChild == nullptr && temp->rightChild == nullptr)
		{
			if (temp == temp->parent->rightChild)
			{
				temp->parent->rightChild = nullptr;
				delete temp;
				return;
			}
			if (temp == temp->parent->leftChild)
			{
				temp->parent->leftChild = nullptr;
				delete temp;
				return;
			}
		}
		disintegrate(temp);
		return;
	}
	catch (const std::exception&)
	{

	}

	
}

template<typename T>
T SplayTree<T>::search(T item)
{
	node<T>*temp;
	temp=travel(item, root);
	return item;
}
*/
template<typename T>
node<T> * SplayTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
SplayTree<T>::SplayTree(int(*fun)(T, T)):root(nullptr)
{
	this->root = getRoot();
	comparefunct(fun);
}

template<typename T>
void SplayTree<T>::rightRotation(node<T> * Z)
{
	node<T>* temp;
	temp = Z->rightChild;
	Z->rightChild = Z->parent;
	Z->parent = Z->parent->parent;
	Z->rightChild->leftChild = temp;
	Z->parent->leftChild = Z;
	return;
}

template<typename T>
void SplayTree<T>::leftRotation(node<T> * A)
{
	node<T>* temp;
	temp = A->leftChild;
	A->leftChild = A->parent;
	A->parent = A->parent->parent;
	A->leftChild->rightChild = temp;
	if (A->parent != nullptr)
	{
		A->parent->rightChild = A;
	}
	return;
}

template<typename T>
void SplayTree<T>::moveToRoot(node<T> * Z)
{
	if (Z->parent == nullptr)
	{
		return;
	}
	while (Z->parent != nullptr)
	{


		if (Z->parent->parent == nullptr)
		{
			zig(Z);
			//return;
		}
		else if (Z == Z->parent->leftChild && Z->parent == Z->parent->parent->leftChild)
		{
			zigzig(Z);
		}
		else if (Z == Z->parent->rightChild && Z->parent == Z->parent->parent->rightChild)
		{
			zagzag(Z);
		}
		else if (Z == Z->parent->leftChild && Z->parent == Z->parent->parent->rightChild)
		{
			zigzag(Z);
		}
		else if (Z == Z->parent->rightChild && Z->parent == Z->parent->parent->leftChild)
		{
			zagzig(Z);
		}
	}
	this->root = Z;
	return;
}

template<typename T>
void SplayTree<T>::zig(node<T> * A)
{
	if (A == A->parent->leftChild)
	{
		rightRotation(A);
		return;
	}
	leftRotation(A);
	return;
}

template<typename T>
void SplayTree<T>::zigzig(node<T> * B)
{
	rightRotation(B->parent);
	rightRotation(B);
	return;
}

template<typename T>
void SplayTree<T>::zagzag(node<T> * C)
{
	leftRotation(C->parent);
	leftRotation(C);
	return;
}

template<typename T>
void SplayTree<T>::zigzag(node<T> * D)
{
	leftRotation(D);
	rightRotation(D);
}

template<typename T>
void SplayTree<T>::zagzig(node<T> * E)
{
	rightRotation(E);
	leftRotation(E);
}

template<typename T>
void SplayTree<T>::insert(T input)
{
	if (root == nullptr)
	{
		root = new node<T>;
		root->data = input;
		return;
	}
	else if (root != nullptr)
	{
		node<T>*temp;
		temp = root;
		while (temp->data != input)
		{
			//temp->height = height + 1;
			if (compareFunction(input, temp->data) == -1)  //ADD a comment to remind you where the node goes
			{
				if (temp->rightChild == nullptr)
				{
					temp->rightChild = new node<T>;
					temp->rightChild->parent = temp;
					temp = temp->rightChild;
					temp->data = input;
				}
				else
				{
					temp = temp->rightChild;
				}
			}
			else if (compareFunction(input, temp->data) == 1)
			{
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = new node<T>;
					temp->leftChild->parent = temp;
					temp = temp->leftChild;
					temp->data = input;
				}
				else
				{
					temp = temp->leftChild;
				}
			}
		}

	}
}

template<typename T>
void SplayTree<T>::remove(T item)
{
	try
	{
		node<T>*temp = travel(item, root);
		if (temp->leftChild == nullptr && temp->rightChild == nullptr)
		{
			if (temp == temp->parent->rightChild)
			{
				temp->parent->rightChild = nullptr;
				delete temp;
				return;
			}
			if (temp == temp->parent->leftChild)
			{
				temp->parent->leftChild = nullptr;
				delete temp;
				return;
			}
		}
		disintegrate(temp);
	}
	catch (const std::exception&)
	{

	}

	
}

template<typename T>
inline T SplayTree<T>::search(T item)
{
	moveToRoot(travel(item, root));
	//moveToRoot(temp);
	display();
	return T();
}

template <typename T>
node<T>* SplayTree<T>::findPredessor(node<T> *position)
{
	node<T> *temp1;
	node<T> *temp2;
	temp1 = position;
	temp2 = temp1->leftChild;
	while (temp2 != nullptr)
	{
		temp1 = temp2;
		temp2 = temp1->rightChild;
	}
	return temp1;
}



template<typename T>
inline node<T>::node()
{
	T data = NULL;
	node<T>* parent = nullptr;
	node<T>* rightChild = nullptr;
	node<T>* leftChild = nullptr;

}


template <typename T>
void SplayTree<T>::display()
{
	cout << "\n";
	for (int i = 0; i < 11; i++)
		cout << "*****";
	cout << "\n";
	display_recur(root, 0);
	for (int i = 0; i < 11; i++)
		cout << "*****";
	cout << "\n\n";
}

////////////////////////
//Display recur function was provided by Coding Cougs Club and written by Trevor
///////////////////////

template <typename T>
void SplayTree<T>::display_recur(node<T> *n, int val)
{
	if (n != nullptr)
	{
		val++;
		display_recur(n->rightChild, val);
		for (int i = 0; i < val; i++)
			cout << "\t";
		cout << n->data << "\n";
		display_recur(n->leftChild, val);
	}
}

template class SplayTree<int>;
