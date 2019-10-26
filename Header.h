#pragma once

template <typename T>
class node
{
public:
	node<T>* parent;
	node<T>* leftChild;
	node<T>* rightChild;
	T data;
	node();
};

template <typename T>
class BinarySearchTree {
public:
	
	virtual void insert(T item) = 0;
	virtual void remove(T item) = 0;
	virtual T search(T item) = 0;
	int(*fcnPtr)(T, T);
};

template <typename T>
class SplayTree : public BinarySearchTree<T>
{
	node<T> *getRoot();
	void rightRotation(node<T>* Z);
	void leftRotation(node<T>* A);
	void comparefunct(int(*fun)(T, T));

	int(*compareFunction)(T, T);
	node<T>* travel(T item, node<T>*X);
	void disintegrate(node<T>*Y);
	node<T>* findPredessor(node<T>* T);

	void display_recur(node<T> *n, int val);
	void moveToRoot(node<T>* Z);
	void zig(node<T>* A);
	void zigzig(node<T>* B);
	void zagzag(node<T>* C);
	void zigzag(node<T>* D);
	void zagzig(node<T>* E);
	node<T>* root;
public:
	void insert(T item) override;
	void remove(T item) override;
	T search(T item);
	SplayTree(int(*fun)(T, T));
	void display();
};




