#pragma once
//Stack node & Queue Node
#include <stdio.h>
#include <iostream>
using namespace std;
template <class T>
class Stack; //forward declaration
template <class T>
class Queue;
template <class T>
class StackNode {
	friend class Stack<T>;
private:
	T data;
	StackNode<T>* link;

public:
	StackNode<T>(T d = 0, StackNode<T>* l = 0) : data(d), link(l) {}//constructor
	/*
	StackNode<T>(T d=0, StackNode<T>* l=0) {
		data = d;
		link = l;
	}//constructor
	*/
};

template <class T>
class QueueNode {
	friend class Queue<T>;
private:
	T data;
	QueueNode<T>* link;
public:
	QueueNode<T>(T d = 0, QueueNode<T>*lk = 0) : data(d), link(lk) {}//constructor
};

//av사용하는 코드로 고처보기
template <class T>
class Stack {
public:
	Stack<T>() { top = 0; }//constructor
	void Add(const T);
	T* Delete(T&);
private:
	StackNode<T>* top;
	void StackEmpty();

};

template <class T>
class Queue {
public:
	Queue<T>() { front = rear = 0; }//constructor
	void Add(const T);
	T* Delete(T&);
private:
	QueueNode<T>* front;
	QueueNode<T>* rear;
	void QueueEmpty();

};

template <class T>
void Stack<T>::Add(const T y) {
	top = new StackNode<T>(y, top);
}
template <class T>
void Stack<T>::StackEmpty() {
	if (top == 0)
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is non empty"<<endl;
}

template <class T>
T* Stack<T>::Delete(T& retvalue)
//delete the top node from stack and return a pointer to its data
{
	if (top == 0) {
		StackEmpty(); return 0;
	} //retrun null pointer constant
	StackNode<T>* x = top;
	retvalue = top->data; //get data field of top node
	top = x->link;//remove top node
	delete x;
	return &retvalue;//return pointer to data
}

template <class T>
void Queue<T>::Add(const T y) {
	if (front == 0) front = rear = new QueueNode<T>(y,0);//empty queue
	else rear = rear->link = new QueueNode<T>(y,0); //attach node and update rear
}

template <class T>
T* Queue<T>::Delete(T& retvalue)
//delete the first node in queue and return a pointer to its data
{
	if (front == 0) {QueueEmpty(); return 0;}
	QueueNode<T> *x = front;
	retvalue = front->data; //get data field of front node
	front = x->link;//remove front node
	delete x;
	return &retvalue;//return pointer to data
}
template <class T>
void Queue<T>::QueueEmpty() {
	if (top == 0)
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is non empty" << endl;
}