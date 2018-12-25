#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template <typename T>
class Node {
public:
	Node<T>* prev;
	Node<T>* next;
	T data;
	Node( ) { };
	Node(T givendata) {
		prev = NULL;
		next = NULL;
		data = givendata;
	}
	virtual ~Node() {};
	void setNext(Node<T>* currentNode, Node<T>* nextNode) {
		currentNode -> next = nextNode;
	}
	void setPrev(Node<T>* currentNode, Node<T>* prevNode) {
		currentNode -> prev = prevNode;
	}
	Node<T> getNext(Node<T>* currentNode) {
		Node<T>* getnextNode = currentNode -> next;
		return getnextNode;
	}
	Node<T> getPrev(Node<T>* currentNode) {
		Node<T>* getprevNode = currentNode -> prev;
		return getprevNode;
	}
	T getdata(Node<T>* currentNode) {
		return currentNode -> data;
	}
};

#endif

