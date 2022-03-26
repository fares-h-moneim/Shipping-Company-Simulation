#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {
		if (!head) { InsertBeg(x); }
		Node<T>* temp = new Node<T>(x);
		Node<T>* temp2 = head;
		while (temp2->getnext())
		{
			temp2 = temp2->getnext();
		}
		temp2->setnext(temp);
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key) {
		if (!head) { return 0; }
		Node<T>* ptr = head;
		while (ptr)
		{
			if (ptr->getitem() == x) {
				return true;
			}
			ptr = ptr->getnext();
		}
		return 0;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) {
		Node<T>* ptr = head;
		int count = 0;
		while (ptr) {
			if (ptr->getitem() == x) {
				count++;
			}
			ptr = ptr->getnext();
		}
		return count;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst() {
		Node<T>* ptr = head;
		if (!ptr) { return; }
		head = head->getnext();
		delete ptr;
	}


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() {
		Node<T>* temp2 = head;
		while ((temp2->getnext())->getnext()) {
			temp2 = temp2->getnext();
		}
		delete temp2->getnext();
		temp2->setnext(NULL);
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value) {
		Node<T>* temp = head;
		int c = search(x);
		if (c == 0) {
			return false;
		}
		else {
			while ((temp->getnext())->getitem() != x) {
				temp = temp->getnext();
			}
			Node<T>* temp2 = temp->getnext()->getnext();
			delete temp->getnext();
			temp->setnext(temp2);
			return true;
		}
		return false;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value) {
		Node<T>* temp = head;
		int c = counterofitm(x);
		for (int i = 0; i < c; i++) {
			deleteNode(x);
		}
		return true;
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L) {
		Node<T>* ptr = head;
		while (ptr->getnext()) {
			ptr = ptr->getnext();
		}
		ptr->setnext(L.head);
		L.head = NULL;
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse() {
		if (!head) { return; }
		Node<T>* current = head;
		Node<T>* prev = NULL;
		Node<T>* next = NULL;

		while (current != NULL) {
			next = current->getnext();

			current->setnext(prev);

			prev = current;
			current = next;
		}
		head = prev;
	}

	//[10] Insert Sorted
	//Inserts an element in the linked list in ascending order
	void Intsert_sorted(T x) {
		Node<T>* ptr = head;
		if (!head) { return; }
		if (x < ptr->getitem()) {
			Node<T>* ptr2 = new Node<T>;
			ptr2->setitem(x);
			ptr2->setnext(ptr);
			head = ptr2;
			return;
		}
		while (ptr->getnext()) {
			if (ptr->getitem() < x && ptr->getnext()->getitem() >= x) {
				Node<T>* ptr2 = new Node<T>;
				ptr2->setitem(x);
				ptr2->setnext(ptr->getnext());
				ptr->setnext(ptr2);
				return;
			}
			ptr = ptr->getnext();
		}
		if (!ptr->getnext()) {
			Node<T>* ptr2 = new Node<T>;
			ptr2->setitem(x);
			ptr2->setnext(NULL);
			ptr->setnext(ptr2);
		}
	}
};

#endif	
