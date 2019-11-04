#include <iostream>
#include "stacknode.h"
using namespace std;

int main(void) {

	char select;
	StackNode<int> sn;
	Stack<int> a;
	
	QueueNode<int> qn;
	Queue<int> q;
	
	int value, result;

	cout << endl << "Select command:A: Add to Stack, D: Delete from Stack, P: PrintAll:";
	cin >> select;
	while (select != 'Q' || select != 'q')
	{
		switch (select)
		{
		case 'A':
		case 'a':
			cout << "Add a new value: ";
			cin >> value;
			a.Add(value);
			break;
		case 'D':
		case 'd':
			result = *a.Delete(value);
			break;
		case 'P':
		case 'p'://print all elements 
			for (;;) // coding 추가
				;
			break;
		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
			break;
		}
		cout << endl << "Select command:A: Add to Stack, D: Delete from Stack, P: PrintAll:";
		cin >> select;
	}
	system("pause");
	return 0;
}
//queuenode도 생성하도록 코드 수정
