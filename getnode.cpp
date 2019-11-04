/* getnode.cpp - Available space lists*/
#include "getnode.h"

template <class T>
void Show(const CircularChain<T>& l) {
	CircularChainIterator<T> li(l); //li is associated with list l
	if (!li.NotNull()) return; //empty list, return 0
	T retvalue = *li.First();//get first element
	cout << retvalue;
	while (li.NextNotNull()) //make sure that next element exists
	{
		retvalue = *li.Next();
		cout << " <- " << retvalue;
	}
	return;
}

int main(void) {
	char select;
	ChainNode<int> nd;
	CircularChain<int> a, b;
	int value;
	do {
		cout << endl << "Select command:1: Add to list a,2: Add to list b, 3: Delete, 4:InsertFront, 5: PrintAll, 6: Merge, q: quit" << endl;
		cin >> select;
		switch (select)
		{
		case '1':
			cout << "Add a new value: ";
			cin >> value;
			a.Add(value);
			break;
		case '2':
			cout << "Add a new value: ";
			cin >> value;
			b.Add(value);
			break;
		case '3':
			a.Delete();
			break;
		case '4':
			cin >> value;
			a.InsertFront(value);
			break;
		case '5': //print all elements by using iterator class
			
			Show(a);
			cout << endl;
			Show(b);
			cout << endl;
			break;
	
		case '6':
			a.Merge(b);//a -> b, b ->a, a1, b1,b2, a2, a3, a4등으로 교대로 merge
			break;
			
		case 'q':
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
	} while (select != 'q');
	system("pause");
	return 0;
}
//head node가 있는 circular list로 수정한다.
