#include <iostream>
#include <vector>
#include "D-Heap.h"

using namespace std;




int main()
{
	D_heap a(3);
	a.insert(3, 3);
	cout << a << endl;
	a.insert(4, 4);
	cout << a << endl;
	a.insert(2, 2);
	cout << a << endl;
	a.insert(1, 1);
	cout << a << endl;
	a.insert(5, 5);
	cout << a << endl;
	a.insert(6, 6);
	cout << a << endl;

	a.erase(1);
	cout << a << endl;

	a.erase(3);
	cout << a << endl;


	return 0;
}
