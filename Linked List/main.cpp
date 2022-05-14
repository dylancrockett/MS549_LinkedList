#include <iostream>
#include "LinkedList.hpp"
#include "LinkedListTest.hpp"

using namespace std;

//menu functions
void main_menu();
void linked_list_playground();
void testing_menu();

int main()
{
	//start menus
	main_menu();
}

//main menu
void main_menu() {
main_menu:

	cout << "<> Main Menu <>\n\n";
	cout << "[1] Linked List Playground\n";
	cout << "[2] Testing Menu\n";
	cout << "[3] Exit\n\n";
	cout << "Please enter your selection: ";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		system("cls");
		linked_list_playground();
		goto main_menu;
	case 2:
		system("cls");
		testing_menu();
		goto main_menu;
	case 3:
		return;
	default:
		system("cls");
		cout << "INVALID OPTION: Please select one of the valid options below (1-3).\n\n";
		goto main_menu;
	}
}

//linked list playground menu
void linked_list_playground() {
	//create LinkedList
	auto list = linked_list::LinkedList<int>();

	//node var
	linked_list::LinkedList<int>::Node* node = nullptr;

	//reset random
	srand(time(0));

	//add some random values
	for (int i = 0; i < 5; i++) list.insert(rand() % 100 + 1);

linked_list_playground:
	cout << "List: ";
	list.print();
	cout << "\n\n";

	cout << "<> Modify Linked List <>\n\n";
	cout << "[1] Add\n";
	cout << "[2] Remove\n";
	cout << "[3] Find\n";
	cout << "[4] Exit\n\n";
	cout << "Please enter your selection: ";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		//get new value
		int newVal;
		cout << "\n\nPlease enter the value to add: ";
		cin >> newVal;

		//add value to list
		list.insert(newVal);
		system("cls");

		goto linked_list_playground;
	case 2:
		//get value to remove
		int valToRemove;
		cout << "\n\nPlease enter the value to be removed: ";
		cin >> valToRemove;

		//remove specified value if it exists
		list.remove(valToRemove);
		system("cls");
		goto linked_list_playground;
	case 3:
		// get value to find
		int valToFind;
		cout << "\n\nPlease enter the value to be found: ";
		cin >> valToFind;

		//find specified value if it exists
		node = list.find(valToFind);

		//if the node was found show it's pointer
		if (node != nullptr) cout << "\nNode Found! Location: " << node << endl;
		else cout << "No node could be found with the specified value." << endl;
		system("pause");
		system("cls");

		goto linked_list_playground;
	case 4:
		system("cls");
		return;
	default:
		system("cls");
		cout << "INVALID OPTION: Please select one of the valid options below (1-3).\n\n";
		goto linked_list_playground;
	}
}

//testing menu
void testing_menu() {

testing_menu:
	cout << "<> Testing Menu <>\n\n";
	cout << "[1] Custom Linked List Test\n";
	cout << "[2] std::list Test\n";
	cout << "[3] std::vector Test\n";
	cout << "[4] All Tests\n";
	cout << "[5] Exit\n\n";
	cout << "Please enter which test you would like to run: ";

	int choice;
	cin >> choice;

	system("cls");

	switch (choice) {
	case 1:
		linked_list_testing::custom_linked_list_test();
		system("pause");
		system("cls");
		goto testing_menu;
	case 2:
		linked_list_testing::standard_library_list_test();
		system("pause");
		system("cls");
		goto testing_menu;
	case 3:
		linked_list_testing::standard_library_vector_test();
		system("pause");
		system("cls");
		goto testing_menu;
	case 4:
		linked_list_testing::custom_linked_list_test();
		cout << endl;
		linked_list_testing::standard_library_list_test();
		cout << endl;
		linked_list_testing::standard_library_vector_test();
		system("pause");
		system("cls");
		goto testing_menu;
	case 5:
		return;
	default:
		cout << "INVALID OPTION: Please select one of the valid options below (1-3).\n\n";
		goto testing_menu;
	}
}