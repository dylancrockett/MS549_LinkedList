#ifndef MS549_LL_TESTING
#define MS549_LL_TESTING

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "LinkedList.hpp"
#include "UnitTesting.hpp"

namespace linked_list_testing {
	using namespace std;
	using namespace unit_testing;

	//random value generator seed (for consistantcy between tests)
	const int RAND_SEED = 1231548125718923;

	//run test for the custom doubly LinkedList class
	inline void custom_linked_list_test() {
		UnitTest test = UnitTest("Custom Linked List");

		//initalize random value seed
		srand(RAND_SEED);

		//create instance of custom linked list
		auto list = linked_list::LinkedList<int>();

		test.assert<bool>("Add 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.insert(rand() % 1000);
			}

			return true;
		}, true);

		test.assert<bool>("Delete 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.remove();
			}

			return true;
		}, true);

		test.assert<bool>("Add 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.insert(rand() % 1000);
			}

			return true;
		}, true);

		test.assert<bool>("Delete 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.remove();
			}

			return true;
		}, true);

		test.assert<bool>("Add 10,000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.insert(rand() % 1000);
			}

			return true;
		}, true);

		test.assert<bool>("Delete 1,0000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.remove();
			}

			return true;
		}, true);

		//log the results
		test.log_results();
	}

	//run test for std::list
	inline void standard_library_list_test() {
		UnitTest test = UnitTest("Standard Library Linked List");

		//initalize random value seed
		srand(RAND_SEED);

		//create instance of std::list
		auto list = std::list<int>();

		test.assert<bool>("Add 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.push_front(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.pop_front();
			}

			return true;
			}, true);

		test.assert<bool>("Add 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.push_front(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.pop_front();
			}

			return true;
			}, true);

		test.assert<bool>("Add 10,000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.push_front(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 1,0000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.pop_front();
			}

			return true;
			}, true);

		//log the results
		test.log_results();
	}

	//run test for std::vector
	inline void standard_library_vector_test() {
		UnitTest test = UnitTest("Standard Library Vector");

		//initalize random value seed
		srand(RAND_SEED);

		//create instance of std::vector
		auto list = std::vector<int>();

		test.assert<bool>("Add 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.push_back(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 100 items.", [&list]() {
			for (int i = 0; i < 100; i++) {
				list.pop_back();
			}

			return true;
			}, true);

		test.assert<bool>("Add 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.push_back(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 1,000 items.", [&list]() {
			for (int i = 0; i < 1000; i++) {
				list.pop_back();
			}

			return true;
			}, true);

		test.assert<bool>("Add 10,000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.push_back(rand() % 1000);
			}

			return true;
			}, true);

		test.assert<bool>("Delete 1,0000 items.", [&list]() {
			for (int i = 0; i < 10000; i++) {
				list.pop_back();
			}

			return true;
			}, true);

		//log the results
		test.log_results();
	}
}

#endif