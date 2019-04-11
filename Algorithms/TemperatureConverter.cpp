#include <iostream>
#include <iomanip>
#include <stdlib>

void c_to_f();
void f_to_c();

int main() {

	int choice;
	char again;
	do{
		system("CLS");

		cout << setw(10) << " " << "What conversion would you like to make?\n";	// menu
		cout << setw(20) << " " << "1. Celsius to Fahrenheit\n\n";				// make a choice which function to use.
		cout << setw(20) << " " << "2. Fahrenheit to celsius\n\n";
		cin >> choice;

		switch (choice) {		// go to chosen function.
		
			case 1: {
			
				c_to_f();
				break;
			}
			case 2: {
			
				f_to_c();
				break;
			}
			default:{
			
				cout << setw(10) << " " << "you must enter 1 or 2  " << endl;		// validate and correct input of function choice.

			}


		}



		cout << setw(10) << " " << "Do you wish to do another conversion? y for yes, n for no  ";	// rerun loop on y for yes
		cin >> again;
	} while (again == 'Y' || again == 'y');

}


void c_to_f() {

	system("CLS");								// clear screen for function data.
	int temp, fahrenheit;

	cout << "\n\n\n";
	cout << setw(10) << " " << "Enter the temperature in whole degrees celsius. \a";
	cin >> temp;

	fahrenheit = ((temp * 9) / 5) + 32;
	cout << endl << setw(10) << " " << temp << " degrees celsius is " << fahrenheit << " degrees fahrenheit \a\n\n\n";
}

void f_to_c() {

	system("CLS");								// clear screen for function data.
	int temp, celsius;

	cout << "\n\n\n";
	cout << setw(10) << " " << "Enter the temperature in whole degrees fahrenheit.  \a";
	cin >> temp;

	celsius = ((temp - 32) * 5) / 9;

	cout << endl << setw(10) << " " << temp << " degrees fahrenheit is " << celsius << " degrees celsius \a\n\n\n";
}