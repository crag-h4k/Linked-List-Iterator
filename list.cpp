#include "list.h"

	// CONSTRUCTOR
	list::list(){
		head = nullptr;
	}


	// postcondition: all nodes in the list are destroyed.
	list::~list(){
		destroyNode(head);
	}
	void list::destroyNode(Node *N){
		if (N != nullptr){
			destroyNode(N->next);
			delete N;
		}
	}

	// MODIFICATION MEMBER FUNCTIONS
	//postcondition: entry is added to the front of the list
	void list::insert_front(const int& entry){
		if (head != nullptr){
			Node *temp = head;
			head = new Node(entry);
			head->next = temp;
		}
		else {
			head = new Node(entry);
		}
	}

	//postcondition: entry is added to the back of the list
	void list::add_back(const int& entry){
		add_back(entry, head);
	}

	void list::add_back(const int& entry, Node*& N){
		if (N != nullptr){
			add_back(entry, N->next);
		}
		else{
			N = new Node(entry);
		}
	}

	// postcondition: all nodes with data == entry are removed from the list
	void list::remove_all(const int& entry){
		remove_all(entry, head);
	}

	void list::remove_all(const int& entry,Node*& N){
		if (N != nullptr){
			if (N->data == entry){
				N = N->next;
				remove_all(entry, N);
			}
			else{
				remove_all(entry, N->next);
			}
		}
	}
	// postcondition: an iterator is created pointing to the head of the list
	Iterator list::begin(void){
		return Iterator(head);
	}

	// CONSTANT MEMBER FUNCTIONS
	// postcondition: the size of the list is returned
	int list::size() const{
		int counter = 0;
		Node *N = head;
		while (N != nullptr){
			counter++;
			N = N->next;
		}
		return counter;
	}
