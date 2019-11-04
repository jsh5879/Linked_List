// Program 4.24 – Adding two polynomials, page 206
//Polynomial addition

#include "polynomialListIterator.h"
using namespace std;

//void testChain() {
//	Chain<int> chain;
//	chain.Add(1);
//	chain.Add(2);
//	chain.Add(3);
//	chain.Add(4);
//
//	chain.displayAll();
//
//	ChainIterator<int> iter = chain.begin();
//	
//	while (iter.NotNull()) {
//		cout << *(iter) << ", ";
//		iter.Next();
//	}
//	
//	cout << endl;
//	
//	chain.Delete();
//	chain.displayAll();
//}

int main(void) {

	Polynomial<int> a, b, sum;

	char select;
	Term<int> *tempTerm;
	ChainNode<Term<int>> cn;
	Chain<Term<int>> ca, cb;
	ChainIterator<Term<int>> iter;
	int c, e;

	cout << endl << "Select command: a: Add_a, b: Add_b, p: a + b, d: DisplayAll, q: exit" << endl;
	cin >> select;
	while (select != 'q')
	{
		switch (select)
		{
		case 'a':
			cout << "Add a new term to a: " << endl;
			cout << "input coef: ";
			cin >> c;
			cout << "input exp: ";
			cin >> e;
			a.add(c, e);
			break;
		case 'b':
			cout << "Add a new term to b: " << endl;
			cout << "input coef: ";
			cin >> c;
			cout << "input exp: ";
			cin >> e;
			b.add(c, e);
			break;
		case 'p': //a+b
			cout << "a+b: ";
			a.addAll(&b);
			a.display();
			b.display();
			sum = a + b;
			//cout << sum;
			break;
		case 'd':
			cout << "display all: " << endl;
			a.display();
			b.display();
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
		}
		cout << endl << "Select command: a: Add_a, b: Add_b, p: Plus, d: DisplayAll, q: exit" << endl;
		cin >> select;
	}
	system("pause");
	return 0;
}
