#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node* next;

	Node<T>() {

	}
	Node<T>(T value) {
		data = value;
		next = NULL;
	}
};

template<typename T>
class SinglyLinkedList {
public:
	Node<T>* head;
	Node<T>* tail;
	size_t size;

	SinglyLinkedList<T>() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(T value) {
		Node<T>* temp = new Node<T>(value);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
		size++;
	}

	void insertLast(T value) {
		Node<T>* temp = new Node<T>(value);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	void insertAt(int index, T value) {
		if (index < 0 || index > size) {
			cout << "Invalid Index" << endl;
		}
		else if (index == 0) {
			insertFirst(value);
		}
		else if (index == size) {
			insertLast(value);
		}
		else {
			Node<T>* current = head;
			Node<T>* temp = new Node<T>(value);

			for (size_t i = 0; i < index - 1; i++)
				current = current->next;

			temp->next = current->next;
			current->next = temp;
			size++;
		}
	}

	void insert(T value) {
		Node<T>* temp = new Node<T>(value);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		size++;
	}

	void deleteFirst() {
		if (head == NULL) {
			cout << "The list is Empty" << endl;
		}
		else
		{
			Node<T>* temp = head;
			head = head->next;

			delete temp;
			size--;
		}
	}

	void deleteLast() {
		if (head == NULL) {
			cout << "The list is Empty" << endl;
		}
		else {
			Node<T>* temp = tail;
			Node<T>* current = head;
			for (size_t i = 0; i < size - 2; i++)
				current = current->next;
			tail = current;
			tail->next = NULL;
			delete temp;
			size--;
		}
	}

	void deleteAt(int index) {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else if (index == 0) {
			deleteFirst();
		}
		else if (index == size - 1) {
			deleteLast();
		}
		else {
			Node<T>* current = head;
			for (size_t i = 0; i < index - 1; i++)
				current = current->next;
			Node<T>* temp = current->next;
			current->next = temp->next;
			delete temp;
			size--;
		}
	}

	void printList() {
		Node<T>* current = head;
		while (current != NULL) {
			cout << current->data << endl;
			current = current->next;
		}
	}



	void search(T value) {
		Node<T>* current = head;
		cout << "Indexes of the node with element " << value << " : ";
		for (int i = 0; i < size; i++) {
			if (current->data == value)
				cout << i << " ";
			current = current->next;
		}
		cout << endl;
	}
};
#pragma once
