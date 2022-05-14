#include <iostream>
#include "LinkedList.hpp"

using namespace std;
using namespace linked_list;

int main()
{
	auto list = LinkedList<int>();

	//add a couple values
	list.insert(1);
	list.insert(2);
	list.insert(3);

	//print list
	cout << "List: ";
	list.print(std::cout);
	cout << endl;
	cout << endl;

	//find the node containing a value
	auto node = list.find(2);

	//print list
	cout << "New List: ";
	list.print(std::cout);
	cout << endl;
}