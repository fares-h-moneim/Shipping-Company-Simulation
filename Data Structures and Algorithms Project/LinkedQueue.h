#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Queue ADT.h"

template <class T>

class LinkedQueue:public QueueADT<T> {
	Node<T>* rearPtr;
	Node<T>* frontPtr;

public:
	LinkedQueue() {
		rearPtr = nullptr;
		frontPtr = nullptr;
	}
	bool isEmpty() const {
		return (frontPtr == nullptr);
	}
	bool enqueue(const T& it) {
		Node<T>* temp = new Node<T>(it);

		if (isEmpty()) {
			frontPtr = temp;
		}
		else {
			rearPtr->setNext(temp);
		}
		rearPtr = temp;
		return true;

	}
	bool dequeue(T& it) {
		if (isEmpty())
			return false;

		Node<T>* nodetobedeleted = frontPtr;
		it = frontPtr->getItem();
		frontPtr = frontPtr->getNext();

		if (nodetobedeleted == rearPtr) {
			rearPtr = nullptr;
		}

		delete nodetobedeleted;
		return true;
	}
	bool peek(T& it) const{
		if (isEmpty) {
			return false;
		}
		it = frontPtr->getItem();
		return true;
	}
	~LinkedQueue() {
		T temp;

		while (dequeue(temp));
	}

	LinkedQueue(const LinkedQueue<T>& LQ)
	{
		Node<T>* NodePtr = LQ.frontPtr;
		if (!NodePtr) //LQ is empty
		{
			frontPtr = backPtr = nullptr;
			return;
		}

		//insert the first node
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		frontPtr = backPtr = ptr;
		NodePtr = NodePtr->getNext();

		//insert remaining nodes
		while (NodePtr)
		{
			Node<T>* ptr = new Node<T>(NodePtr->getItem());
			backPtr->setNext(ptr);
			backPtr = ptr;
			NodePtr = NodePtr->getNext();
		}
	}
};