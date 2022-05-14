#ifndef MS549_LINKED_LIST
#define MS549_LINKED_LIST

#include <iostream>
#include <string>

namespace linked_list {
	/// <summary>
	/// A generic implimentation of a Doubly LinkedList.
	/// </summary>
	/// <typeparam name="T">Data type that the Doubly LinkedList stores.</typeparam>
	template <typename T> class LinkedList {
	public:
		class Node {
		private:
			/// <summary>
			/// The next node in the list (faces tail)
			/// </summary>
			Node* next;

			/// <summary>
			/// The previous node in the list (faces head)
			/// </summary>
			Node* prev;

			/// <summary>
			/// Unlink this node from the list it is contained within.
			/// </summary>
			void unlink() {
				//get current next & prev values
				Node* next = this->next, * prev = this->prev;

				//set the next node to link to the prev node, and vice versa
				if (next != nullptr) next->prev = prev;
				if (prev != nullptr) prev->next = next;

				//set this node to reference itself since it has been removed from the list
				this->next = this;
				this->prev = this;
			}

			/// <summary>
			/// Allow LinkedList class to access Node private members;
			/// </summary>
			friend class LinkedList;

		public:
			/// <summary>
			/// The value contained in the node.
			/// </summary>
			T value;

			/// <summary>
			/// Constructor for a Doubly LinkedList Node
			/// </summary>
			/// <param name="value"></param>
			/// <param name="next"></param>
			/// <param name="prev"></param>
			Node(T value, Node* next = nullptr, Node* prev = nullptr) {
				this->value = value;
				this->next = next;
				this->prev = prev;
			}

			/// <summary>
			/// Defines conversion of the node to value type.
			/// </summary>
			operator T() const { return this->value;  }
		};

	private:
		/// <summary>
		/// The head (front) node of the linked list.
		/// </summary>
		LinkedList<T>::Node* head;

		/// <summary>
		/// The tail (back) node of the linked list.
		/// </summary>
		Node* tail;

	public:
		LinkedList() {
			this->head = nullptr;
			this->tail = nullptr;
		}

		~LinkedList() {
		}

		/// <summary>
		/// Finds the node closest to the front of the list with the specified value.
		/// </summary>
		/// <param name="value">The value to be searched for.</param>
		/// <returns>A pointer to the node closest to the front of the list which contained a value equal to the value provided.</returns>
		Node* find(T value) {
			//check if the list has no nodes
			if (this->head == nullptr) return nullptr;

			//current node being checked, starts at the head moving towards the tail
			Node* current = this->head;

			//iterate over list checking each node for a matching value, if a node with a matching value is found return a pointer to it
			while (current != nullptr) {
				//check if the value matches
				if (current->value == value) return current;

				//set current to the next node
				current = current->next;
			}

			//if no matching node was found return nullptr
			return nullptr;
		}

		/// <summary>
		/// Insert a new value to the end of the LinkedList. 
		/// </summary>
		/// <param name="value">The value to insert into the list.</param>
		/// <returns>A pointer to the newly added node.</returns>
		Node* insert(T value) {
			//check if the list has no nodes
			if (this->head == nullptr) {
				//if there are no nodes create the first one and set it to the head and tail
				Node* node = new Node(value);

				//set node to be head and tail
				this->head = node;
				this->tail = node;

				//return pointer to new node.
				return node;

			}
			else {
				//get the current tail node
				Node* currentTail = this->tail;

				//create the new node to be added to the list
				Node* node = new Node(value);

				//set the current tail to point to the new node
				currentTail->next = node;
				
				//set the new node to point at the tail
				node->prev = currentTail;

				//update tail to be the new node
				this->tail = node;

				//return pointer to new node.
				return node;
			}
		}

		/// <summary>
		/// Remove the node closest to the head of the list with a matching value.
		/// </summary>
		/// <param name="value">The value to be removed from the list.</param>
		/// <returns>If a node was found (and presumably removed).</returns>
		bool remove(T value) {
			//find a node with the value provided
			Node* node = this->find(value);

			//if no node was found
			if (node == nullptr) return false;

			//remove the node from the list
			this->remove(node);
			return true;
		}

		/// <summary>
		/// Remove a specified node from the list if it exists.
		/// </summary>
		/// <param name="value">A pointer to the node to be removed</param>
		void remove(Node* node) {
			//if the node being removed is the head set the new head
			if (this->head == node) {
				this->head = node->next;
			} 
			//if the node being removed is the tail set the new tail
			else if (this->tail == node) {
				this->tail = node->prev;
			}

			//unlink the node from the list
			node->unlink();

			//delete node
			delete node;
		}

		/// <summary>
		/// Output the contents list to a specified stream.
		/// </summary>
		/// <typeparam name="T">Stream to send list contents to.</typeparam>
		void print(std::ostream& stream) {
			//check if the list is empty
			if (this->head == nullptr) {
				stream << "[]";
				return;
			}

			//open list
			stream << "[";

			//keep track of the current node, starts at the head node
			Node* current = this->head;

			//iterate over list until tail is reached
			while (current != nullptr) {
				//send value
				stream << current->value;

				//send comma if this is not the last node
				if (current->next != nullptr) stream << ", ";

				//set current to the next node
				current = current->next;
			}

			stream << "]";
		}
	};
}

#endif // !
