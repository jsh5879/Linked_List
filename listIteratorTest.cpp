/* listIteratorTest.cpp - List Iterator를 사용
- Add()에서 학생들이 실습할 코드로 
  1) add된 데이터를 last node로 추가하는 코드 작성, 
  2) 입력된 값이 sort되도록 add()를 수정
  3) sum(xi * xi+5)를 구하는 코드 작성
*/
#include "listiterator.h"
//int printAll(const List& l);//list iterator를 사용하여 작성하는 연습
//int sumProductFifthElement(const List& l);//list iterator를 사용하여 작성하는 연습
int sum(const List& l)
{
	ListIterator li(l);
	if (!li.NotNull()) return 0;
	int retvalue = *li.First();
	while (li.NextNotNull() == true) {
		++li;//current를 증가시킴
		//retvalue = retvalue + *li.Next();
		retvalue = retvalue + *li.GetCurrent();//현재 current가 가르키는 node의 값을 가져옴
	}
	return retvalue;
}

double avg(const List& l)
{
	ListIterator li(l);
	if (!li.NotNull()) return 0;
	int retvalue = *li.First();
	int count = 1;
	while (li.NextNotNull() == true) {
		++li;
		count++;
		//retvalue = retvalue + *li.Next();
		retvalue = retvalue + *li.GetCurrent();
	}

	double result = (double)retvalue / count;

	return result;
}

int min(const List& l)
{
	ListIterator li(l);
	if (!li.NotNull()) return -1;
	int minValue = *li.First();

	while (li.NextNotNull() == true) {
		++li;
		if (minValue > * li.GetCurrent())
		{
			minValue = *li.GetCurrent();
		}
	}
	return minValue;
}

int max(const List& l)
{
	ListIterator li(l);
	if (!li.NotNull()) return -1;
	int maxValue = *li.First();

	while (li.NextNotNull() == true) {
		++li;
		if (maxValue < *li.GetCurrent())
		{
			maxValue = *li.GetCurrent();
		}
	}
	return maxValue;
}

void ListTesting() {
	int ch;
	List st;
	while (1)
	{
		cout << "\n1.Add  2.Delete  3.Show  4. sum 5.avg 6.min 7.max 8.exit\nEnter ur choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:  cout << "enter the element ";
			cin >> ch;
			st.Add(ch);
			break;
		case 2:  st.Delete(ch);  break;
		case 3:  st.Show(); break;
		case 4:  cout << "sum() = " << sum(st) << endl; break;
		case 5:  cout << "avg() = " << avg(st) << endl; break;
		case 6:  cout << "min() = " << min(st) << endl; break;
		case 7:  cout << "max() = " << max(st) << endl; break;
		case 8:  return;
		}
	}

	return;
}

void CircularListTesting() {
	int ch;
	CircularList st;
	while (1)
	{
		cout << "\n1.Add  2.Delete  3.DeleteNum  4.Show  5.exit\nEnter ur choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:  cout << "enter the element ";
			cin >> ch;
			st.Add(ch);
			break;
		case 2:  st.Delete(ch);  break;
		case 3:  cout << "enter the element ";
			cin >> ch;
			st.DeleteNum(ch);
			break;
		case 4:  st.Show(); break;
		case 5:  return;
		}
	}

	return;
}

void main() {
	cout << endl << "List Testing begins: " << endl;
	//ListTesting();
	CircularListTesting();
	//	CircularListHead Testing();
	system("Pause");
}

