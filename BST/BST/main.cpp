#include <iostream>
#include "BST.h"

using namespace std;

int main()
{

	BST t;
	bool exit = false;

	while (!exit) {
		cout << "1. Add Leaf" << endl;
		cout << "2. Find Smallest" << endl;
		cout << "3. Find Biggest" << endl;
		cout << "4. Print InOrder" << endl;
		cout << "5. Print PreOrder" << endl;
		cout << "6. Print PostOrder" << endl;
		cout << "7. Print Children" << endl;
		cout << "8. Remove Node" << endl;
		cout << "9. Exit" << endl;
		cout << endl;
		int option = 0;
		cout << ">>> ";
		cin >> option;
		switch (option) {
		case 1: {

			int key;
			cout << "Type key value >>> ";
			cin >> key;
			t.addLeaf(key);
			continue;
		}
		case 2: {

			cout << "Smallest value is:  " << t.FindSmallest() << endl;
			continue;
		}
		case 3: {

			cout << "Biggest value is:  " << t.FindBiggest() << endl;
			continue;
		}
		case 4: {

			t.PrintInOrder();
			cout << endl;
			cout << endl;
			continue;
		}
		case 5: {

			t.PreOrder();
			cout << endl;
			cout << endl;
			continue;
		}
		case 6: {
			t.PostOrder();
			cout << endl;
			cout << endl;
			continue;
		}
		case 7: {
			int key;
			cout << "Type key value >>> ";
			cin >> key;
			t.PrintChildren(key);
			continue;
		}
		case 8: {
			int key;
			cout << "Type key value to delete >>> ";
			cin >> key;
			t.RemoveNode(key);
			continue;
		}
		case 9: {
			exit = true;
			continue;
		}
		}
	}

}