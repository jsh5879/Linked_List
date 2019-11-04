#pragma once
// class Node, List, ListIterator
#include <iostream>
using namespace std;

class List;

class Node {
	friend class List;
	friend class ListIterator;
	friend class CircularList;
public:
	Node(int, Node*);
	~Node();
private:
	int num;
	Node* link;
};

class List {
	friend class ListIterator;
	friend class CircularList;
public:
	List();
	~List();
	virtual void Add(int&);
	virtual void Delete(int&);//주어진 x 값을 갖는 노드를 삭제
	virtual void Show();
	//int Length(); //count the number of nodes in a list
	//void Merge(List&, List&);//the merged nodes in a sequential order
private:
	Node* first;
};

class ListIterator {
public:
	ListIterator(const List& lst);
	~ListIterator();
	bool NotNull();
	bool NextNotNull();
	int* First();
	int* Next();
	int& operator*() const;
	int* operator->()const;
	ListIterator& operator++(); //Next()
	ListIterator operator ++(int);
	bool operator != (const ListIterator) const;
	bool operator == (const ListIterator) const;
	int* GetCurrent();
private:
	Node* current; //pointer to nodes
	const List& list;//existing list
};

class CircularList : public List {
public:
	CircularList();
	~CircularList();
	void Add(int&);
	void Delete(int&);
	void Show();
	void DeleteNum(int& x);
};
