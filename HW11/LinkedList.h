#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <string>
#include "MyClass.h"
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList : public Node<T> {
public:
	Node<T>* head;
	LinkedList( ) {
		this -> head = NULL;
	}
	LinkedList (T data) {
		this -> head = new Node<T>(data);
	}
	T getNodeData(T datacompare) {
		Node<T>* compare = head;
		while (compare != NULL) {
			if (compare -> data == datacompare) {
				return compare -> data;
			}
			compare = compare -> next;
		}
	}
	Node<T>* addNode(T adddata) {
		Node<T>* nodepointer = head;
		Node<T>* newnode = new Node<T>(adddata);
		while (nodepointer != NULL) {
			if (nodepointer -> prev == NULL && nodepointer -> next == NULL) {
				if ((nodepointer -> data) < adddata) {
					newnode -> prev = nodepointer;
					nodepointer -> next = newnode;
					return newnode;
				}
				else {
					nodepointer -> prev = newnode;
					newnode -> next = nodepointer;
					head = newnode;
					return newnode;
				}
			}
			else {
				if (adddata < (nodepointer -> data)) {
					Node<T>* tempnode = nodepointer -> prev;
					nodepointer -> prev = newnode;
					newnode -> next = nodepointer;
					if (tempnode == NULL) {
						newnode -> prev = tempnode;
						head = newnode;
					}
					else {
						tempnode -> next = newnode;
						newnode -> prev = tempnode;
					}
					return newnode;
				}
			}
			nodepointer = nodepointer -> next;
		}
		nodepointer = head;
		while (nodepointer -> next != NULL) {
			nodepointer = nodepointer -> next;
		}
		nodepointer -> next = newnode;
		newnode -> prev = nodepointer;
		return newnode;
	}

	void deleteNode(T deletedata) {
		Node<T>* nodepointer = head;
		while (nodepointer != NULL) {
			if ((nodepointer -> data) == deletedata) {
				if (nodepointer -> prev == NULL) {
					Node<T>* deletenode = nodepointer;
					nodepointer -> next -> prev = NULL;
					head = nodepointer -> next;
					delete deletenode;
					return;
				}
				else if (nodepointer -> next == NULL) {
					Node<T>* deletenode = nodepointer;
					nodepointer -> prev -> next = NULL;
					delete deletenode;
					return;
				}
				else if (nodepointer != head) {
					Node<T>* deletenode = nodepointer;
					nodepointer -> prev -> next = deletenode -> next;
					nodepointer -> next -> prev = deletenode -> prev;
					delete deletenode;
					return;
				}
			}
			nodepointer = nodepointer -> next;
		}
		return;
	}

	void print() {
		Node<T>* current = head;
		while (current != NULL) {
			cout << current -> data << "  ";
			current = current -> next;
		}
		cout << endl;
	}

	virtual ~LinkedList() {
		Node<T>* current = this;
		while (head != NULL) {
			Node<T>* next = current -> next;
			delete current;
			current = next;
		}
	}
};

#endif
