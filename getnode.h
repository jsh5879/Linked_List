/*
1. head node가 없는 경우
2. head node가 있는 경우에 구현
*/
#pragma once
//getnode, retnode
#include <iostream>
using namespace std;

template<class T> class CircularChain; //forward declaration
template<class T> class CircularChainIterator;

template<class T>
class ChainNode {
	friend class CircularChain<T>;
	friend class CircularChainIterator<T>;
public:
	ChainNode(T element = 0)
	{
		data = element;
		link = 0;
	}
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class CircularChain {
	friend class CircularChainIterator<T>;
public:
	CircularChain() { last = 0; };
	~CircularChain();
	void Delete(void);
	void Add(const T& element); //add a new node after last
	void InsertFront(const T& e);
	ChainNode<T>* GetNode();
	void RetNode(ChainNode<T>& x);
	void Merge(CircularChain<T>& b);

	template<class T>
	friend ostream& operator<<(ostream&, CircularChain<T>&);
	//findMax();
private:
	static ChainNode<T>* av; //이거 중요
	ChainNode<T>* last; //point to the last node
};

template<class T>
class CircularChainIterator {
public:
	CircularChainIterator(const CircularChain<T>& l) : current(l.last), list(l) {};
	T* First();
	T* Next();
	bool NotNull();
	bool NextNotNull();
private:
	//ChainNode<T>* current;
	const CircularChain<T>& list; //refers to an existing list
	ChainNode<T>* current;
};

template <class T>
CircularChain<T>::~CircularChain() {
	//TODO
};

template <class T>
void CircularChain<T>::Delete(void) //delete the last element after last
{
	ChainNode<T>* next;
	next = last->link;
	if (!last) //non-empty list
	{
		ChainNode<T>* temp = last;
		last = next;
		delete temp;
	}
	cout << "Empty List: Not deleted" << endl;
}

template <class T>
void CircularChain<T>::Add(const T& element) //add a new node after last
{
	ChainNode<T>* newnode = new ChainNode<T>(element);
	if (!last) //insert into empty list
	{
		last = newnode;
		return;
	}
	//insert a new node after last
	newnode->link = last;
	last = newnode;
};

template <class T>
void CircularChain<T>::InsertFront(const T& e)
{ //insert the element e at the 'front' of the circular list *this
  // last points to the last node in the list
	ChainNode<T>* newNode = new ChainNode<T>(e);
	if (last) { //nonempty list
		newNode->link = last->link;
		last->link = newNode;
	}
	else {//empty list
		last = newNode;
		newNode->link = newNode;
	}

}

template <class T>
ChainNode<T>* CircularChain<T>::GetNode()
{ //provide a node for use
	ChainNode<T>* x;
	if (av) { x = av, av = av->link; }
	else x = new ChainNode<T>;
	return x;
}

//하나의 노드 return
template <class T>
void CircularChain<T>::RetNode(ChainNode<T>& x)
{ //free the node pointed to by x
	x->link = av;
	av = x;
	x = 0;
}

template <class T>
void CircularChain<T>::Merge(CircularChain<T>& b)
{// a.Merge(b) produces list contains the merged result
 // coding한다.
	ChainNode<T> currentPtrA = last->link;
	while (currentPtrA != 0) {
		currentPtrA = currentPtrA->link;
	}
	ChainNode<T> currentPtrB = b.last->link;
	currentPtrB->link = currentPtrB;
}

template <class T>
ChainNode<T>* CircularChain<T>::av = 0;
//ChainNode<T> CircularChain<T>::av = 0;//오류 발생

template<class T>
T* CircularChainIterator<T>::First()
{
	if (list.last) return &list.last->data;
	else return 0;
}

template<class T>
T* CircularChainIterator<T>::Next()
{
	if (current) {
		current = current->link;
		return &current->data;
	}
	else return 0;
}

template<class T>
bool CircularChainIterator<T>::NotNull()
{
	if (current) return 1;
	else return 0;
}

template<class T>
inline bool CircularChainIterator<T>::NextNotNull()
{
	if (current && current->link) return 1;
	else return 0;
}
