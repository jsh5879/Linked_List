#pragma once

/*
 - template 사용시에는 클래스 멤버 함수의 정의와 구현부를 *.h 파일과 *.cpp 파일로 분리할 수 없음. 하나의 file로 처리
 - class Chain, class ChainIterator에 함수 추가하는 코딩 연습 필요
 - template chain으로 circular list로서 head node가 있는 경우 구현
*/

#include <iostream>
using namespace std;

template<class T> class Chain; //forward declaration
template<class T> class ChainIterator;

template<class T> class ChainNode {
	friend class Chain<T>;
	friend class ChainIterator<T>;
public:
	ChainNode(T element = 0);
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain {
	friend class ChainIterator<T>;
public:
	Chain() { first = 0; };
	void Delete(void); //delete the first element after first
	int Length();
	void Add(const T& element); //add a new node after first
	void Invert();
	void Concatenate(Chain<T> b);
	//ostream& operator<<(ostream&, Chain<T>);
	//int Minimum();
private:
	ChainNode<T>* first;
};

template<class T>
class ChainIterator {
public:
	ChainIterator(const Chain<T>& l) :list(l), current(l.first) {};
	//dereferencing operators
	T& operator *() const { return current->data; }
	T* operator->()const { return &current->data; }
	//increment
	ChainIterator<T>& operator ++(); //preincrement
	ChainIterator<T> operator ++(int); //post increment
	bool NotNull(); //check the current element in list is non-null
	bool NextNotNull();//check the next element in list is non-null

	T* First();     //return a pointer to the first element of list
	T* Next();  //return a pointer to the next element of list
private:
	const Chain<T>& list; //refers to an existing list
	ChainNode<T>* current; //points to a node in list
};
template<class T>
ChainNode<T>::ChainNode(T element)
{
	data = element;
	link = 0;
}
template<class T>
void Chain<T>::Delete(void) //delete the first element after first
{
	ChainNode<T>* current, * next;
	if (first != nullptr) //non-empty list
	{
		next = first->link;

		ChainNode<T>* temp = first;
		first = next;
		delete temp;
	}
	else
		cout << "Error - Empty List. not deleted" << endl;
}
template<class T>
void Chain<T>::Add(const T& element) //add a new node after first
{
	ChainNode<T>* newnode = new ChainNode<T>(element);
	if (!first) //insert into empty list
	{
		first = newnode;
		return;
	}
	//insert a new node after first
	newnode->link = first;
	first = newnode;
}

template<class T>
void Chain<T>::Invert() {
	ChainNode<T>* p = first, * q = 0; //q trails p
	while (p) {
		ChainNode<T>* r = q; q = p; //r trails q
		p = p->link; //p moves to next node
		q->link = r; //link q to preceding node
	}
	first = q;
}

template<class T>
void  Chain<T>::Concatenate(Chain<T> b) {
	ChainNode<T>* p;
	if (!first) { first = b.first; return; }
	if (b.first) {
		// No loop body in this for loop. It just moves the pointer 'p' to the end of the A chain.
		for (p = first; p->link; p = p->link);

		p->link = b.first;
	}
}

// pre-increment
template<class T>
ChainIterator<T>& ChainIterator<T>::  operator ++()
{
	current = current->link;
	return *this;
}

//post increment
template<class T>
ChainIterator<T> ChainIterator<T>:: operator ++(int)
{
	ChainIterator<T> old = *this;
	current = current->link;
	return old;
}

//check the current element in list is non-null
template<class T>
bool  ChainIterator<T>::NotNull() {
	if (current) return 1;
	else return 0;
}

//check the next element in list is non-null
template<class T>
bool   ChainIterator<T>::NextNotNull() {
	if (current && current->link) return 1;
	else return 0;
}

//return a pointer to the first element of list
template<class T>
T* ChainIterator<T>::First() {
	if (list.first) return &list.first->data;
	else return 0;
}

//return a pointer to the next element of list
template<class T>
T* ChainIterator<T>::Next() {
	if (current) {
		current = current->link;
		return &current->data;
	}
	else return 0;
}