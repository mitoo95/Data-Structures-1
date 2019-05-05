#include "pch.h"
#include <iostream>
#include "mangoFruit.h"
#include "mangoTree.h"

using namespace std;

int main()
{
	bool exit = false;
	mangoTree mTree;
	int option = 0, test = 0, pos = 0;
	double weight = 0;

	while (!exit)
	{
		cout << "\n\n--> M A N G O  T R E E <--\n\n";
		cout << "1. Add a Mango Fruit to the tree\n";
		cout << "2. Insert a Mango Fruit to the tree\n";
		cout << "3. Delete a Mango Fruit from the tree\n";
		cout << "4. Print Mangos\n";
		cout << "5. Exit";

		cout << "\n\nPlease type the desired option: ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "-> Add Mango <-";
			cout << "\nInsert the weight of the mango to insert: ";
			cin >> weight;

			mangoFruit* mAdd = new mangoFruit(weight);
			test = mTree.addMangoFruit(mAdd);

			if (test == 0)
			{
				cout << "\t\tMango added!!";
			}
		}
		break;

		case 2:
		{
			cout << "-> Insert Mango <-";
			cout << "\nInsert the weight of the mango to insert: ";
			cin >> weight;

			cout << "\nInsert the position to insert the fruit in the tree: ";
			cin >> pos;

			mangoFruit* mInsert = new mangoFruit(weight);
			test = mTree.insertMangoFruit(mInsert, pos);

			switch (test)
			{
			case (-1):
				cout << "\t\tThe position inserted doesn't exist in the tree.";
				break;

			case (-2):
				cout << "\t\tThe position inserted is negative, therefore it doesn't exist in the tree.";
				break;

			case 0:
				cout << "\t\tMango added to the tree through add.";
				break;

			case (-3):
				cout << "\t\tMango couldn't be added to the tree";
				break;

			case 1:
				cout << "\t\tMango inserted successfully";
				break;

			default:
				cout << "\t\tPosition or weight inserted not valid.";
				break;
			}
		}
		break;

		case 3:

			cout << "-> Delete Mango <-";
			cout << "\nInsert the position of the mango to delete: ";
			cin >> pos;

			test = mTree.deleteMangoFruit(pos);

			if (test == 0)
			{
				cout << "\t\tMango deleted!!";
			}
			break;

		case 4:
			
			mTree.printMangoWeight();
			break;

		case 5:
			
			exit = true;
			break;

		default:
			cout << "The option entered is not valid.";
			break;
		}

	}

}