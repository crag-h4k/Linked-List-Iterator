#include "Node.h"
#include "Iterator.h"
#include "list.h"
	// Constructor
	Iterator::Iterator(Node *np){
		n = np;
	}

	// precondition: is_item is true
	// post condition n points to the next item in the list
	void Iterator::operator++(){
		if (is_item()){
			n = n->next;
		}
	}

	// precondition:
	// postcondition: returns true if there is a valid item
	bool Iterator::is_item(){
		return n != nullptr;

	}

	// precondition: is_item == true
	// postcondition returns data that n is pointing at
	int Iterator::operator* (){
		if (is_item()){
			return n->data;
		}
	}
