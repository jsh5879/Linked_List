#include "listiterator.h"
Node::Node(int element = 0, Node* next = 0) {
	num = element;
	link = next;
}

Node::~Node() {
}

List::List() {
	first = 0;
}
List::~List() {
}

void List::Add(int& x) {
	if (!first) {
		first = new Node(x);
		first->link = 0;
	}
	else {
		Node* n = new Node(x);
		n->link = first;
		first = n;
	}
}
void List::Delete(int& x) {
	if (first == NULL) cout << " List is empty" << endl;
	// body of delete
	return;
}

void List::Show() {
	Node* current;
	current = first;
	if (first)
		while (current)
		{
			cout << current->num << " ";
			current = current->link;
		}
	else cout << "List is empty" << endl;
}

/*
ListIterator::ListIterator(Node *ll){
}
*/


ListIterator::ListIterator(const List& lst) :
	list(lst), current(lst.first) {
	cout << "List Iterator is constructed" << endl;
}

bool ListIterator::NotNull() {
	if (list.first == 0) return false;
}

bool ListIterator::NextNotNull() {
	if (current->link != 0) return true;
	else return false;
}

int* ListIterator::First() {
	return &list.first->num;
}

int* ListIterator::Next() {
	current = current->link;
	cout << "current = " << current->num;
	return &current->num;
}

int* ListIterator::GetCurrent() {
	return &current->num;
}

ListIterator::~ListIterator() {
}

int& ListIterator::operator*() const {
	return current->num;
}

int* ListIterator::operator->()const {
	return &current->num;
}

ListIterator& ListIterator::operator++() {
	current = current->link;
	return *this;
}

ListIterator ListIterator::operator ++(int) {
	ListIterator old = *this;
	current = current->link;
	return old;
}

bool ListIterator::operator != (const ListIterator right) const {
	return current != right.current;
}

bool ListIterator::operator == (const ListIterator right) const {
	return current == right.current;
}

CircularList::CircularList() : List() {}

CircularList::~CircularList() {}

void CircularList::Add(int& x) {
	Node* newNode = new Node(x);
	if (first) { //nonempty list
		newNode->link = first->link;
		first->link = newNode;
	}
	else { //empty list
		first = newNode;
		newNode->link = newNode;
	}
}

void CircularList::Delete(int& x) {
	Node* newNode = new Node(x);
	if (first) { //nonempty list
		Node* Temp = first->link;
		first->link = first->link->link;
		delete Temp;
	}
	else { //empty list
		cout << "empty list" << endl;
	}
}

void CircularList::DeleteNum(int& x) {
	//Node *newNode = new Node(x);
	//first, medium, last üũ
	if (first) { //nonempty list
		Node* CurrentNode = first;
		Node* PreNode = first;
		bool find = false;

		//while (CurrentNode->link != first || CurrentNode == first)
		while (CurrentNode->link != first)
		{
			if (CurrentNode->num == x)
			{
				find = true;

				if (CurrentNode == first) // first delete case
				{
					Node* Temp = CurrentNode;

					while (CurrentNode->link != first)
					{
						CurrentNode = CurrentNode->link;
					}
					first = first->link;
					delete Temp;

					CurrentNode->link = first;
					break;
				}
				else if (CurrentNode->link != first) // medium delete case
				{
					PreNode->link = CurrentNode->link;
					delete CurrentNode;
					break;
				}
			}



			PreNode = CurrentNode;
			CurrentNode = CurrentNode->link;
		}//while end

		if (find == false)
		{
			if (CurrentNode->num == x) // last Delte Case
			{
				PreNode->link = first;
				delete CurrentNode;
				find = true;
			}

		}
		if (find == false)
			cout << "can't find " << x << endl;
	}
	else { //empty list
		cout << "empty list" << endl;
	}

}

void CircularList::Show() {
	Node* np;
	np = first;
	if (np->num > 0)
		do
		{
			cout << np->num << " ";
			np = np->link;
		} while (np != first);
	else cout << "List is empty" << endl;
}

