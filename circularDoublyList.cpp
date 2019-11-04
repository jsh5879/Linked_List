//12.Doubly Linked List Implementation with Pointers C++
//circular doubly lists with head node 구현- 이코드를 수정하여 사용, 두개의 list를 만들고 list node에 정수 값이 sorted된 상태로 입력되게 하고, 두개의 list를 merge하여 합친 결과도 sorted list되게 한다. 
#include <iostream>
using namespace std;
class DbList;
class CircDbList;
class DbListNode {
	friend class CircDbList;
private:
	int data;
	DbListNode* llink, * rlink;
};

class CircDbList {
	friend class CircDbListIterator;
public:
	CircDbList() { first = new DbListNode; first->rlink = last; last->llink = first; };
	CircDbList(const CircDbList&);
	~CircDbList();
	void Attach(int);
	void Delete(DbListNode*);
	void Insert(DbListNode*, DbListNode*);
private:
	DbListNode* first;
	DbListNode* last;
	static DbListNode* av;
};
void CircDbList::Delete(DbListNode* x)
{
	if (x == first) cerr << "Deletion of head node not permitted" << endl;
	else {
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}

void CircDbList::Insert(DbListNode* p, DbListNode* x)
//insert node p to the right of node x
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}


DbListNode<Term>* CircDbList<Term>::av = 0;


class CircDbListIterator {
public:
	CircDbListIterator(const CircDbList& l) : list(l) { current = l.first->link; }
	Type* Next();
	Type* First();
	Bool NotNull();
	Bool NextNotNull();
private:
	const CircDbList& list;
	ListNode* current;
};


Type* CircDbListIterator::First() {
	if (current != list.first) return &current->data;
	else return 0;
}


Type* CircDbListIterator::Next() {
	current = current->link;
	if (current != list.first) return &current->data;
	else return 0;
}


Bool CircDbListIterator::NotNull()
{
	if (current != list.first) return TRUE;
	else return FALSE;
}


Bool CircDbListIterator::NextNotNull()
{
	if (current->link != list.first) return TRUE;
	else return FALSE;
}



CircDbList::CircDbList(const CircDbList& l)
{
	if (l.first == 0) { first = 0; return; }
	first = new DbListNode(l.first->data);
	ListNode* newnode = first;
	for (DbListNode* current = l.first->link; current != l.first; current = current->link)
	{
		newnode->link = new DbListNode(current->data);
		newnode = newnode->link;
	}
	newnode->link = first;
}



CircDbList ::~CircDbList()
{
	if (first)
	{
		DbListNode* second = first->link;
		first->link = av;
		av = second;
		first = 0;
	}
}


ostream& operator<<(ostream& os, CircDbList<Term>& l)
{
	CircDbListIterator<Term> li(l);
	if (!li.NotNull()) return os;
	os << *li.First();
	while (li.NextNotNull())
		os << " + " << *li.Next();
	os << endl;
	return os;
}



void CircDbList::Attach(Type k)
{
	DbListNode* newnode = new DbListNode(k);
	if (first == 0) first = last = newnode;
	else {
		newnode->link = last->link;
		last->link = newnode;
		last = newnode;
	}
}

int main()
{
	//page 219, Fig 4.31, circular list with head node
		// page 220, Exercise 3. Programming project 3
		//implement doubly linked circular list with head nodes
	char select;

	/*Term<int> *tempTerm;
	ChainNode<Term<int>> nd;
	Chain<Term<int>> a, b;
	ChainIterator<Term<int>> iter;*/
	int c, e;

	cout << endl << "Select command: a: Add, d: Delete, m: Merge, d: DisplayAll, q: exit" << endl;
	cin >> select;
	while (select != 'q')
	{
		switch (select)
		{
		case 'a':
			cout << "Add a new term to a: " << endl;

			a.add(c, e);
			break;
		case 'd':
			cout << "Add a new term to b: " << endl;
			cout << "input coef: ";

			break;
		case 'm': //a+b

			break;
		case 'd':
			cout << "display all: " << endl;
			a.display();
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}

		cin >> select;
	}
	system("pause");
	return 0;
}


