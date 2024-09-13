#include "DoubleLinkedList.hpp"

template<typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(T* _value) {
	value = _value;
}


template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
	first = nullptr;
	last = nullptr;
	length = 0;
}

template<typename T>
DoubleLinkedListNode<T>* DoubleLinkedList<T>::seek(int i) {
	if (length == 0) {
		return nullptr;
	}

	DoubleLinkedListNode<T>* node = first;
	
	for (int traversed = 0; traversed < i; ++traversed) {
		if (node->next == nullptr) {
			return nullptr;
		}
		node = node->next;
	}

	return node;
}


template<typename T>
T* DoubleLinkedList<T>::get(int i) {
	DoubleLinkedListNode<T>* node = seek(i);

	if (node != nullptr) {
		return node->value;
	}
	return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::set(int i, T* _value) {
	DoubleLinkedListNode<T>* node = seek(i);

	if (node != nullptr) {
		node->value = _value;
	}
}


template<typename T>
bool DoubleLinkedList<T>::remove(int i) {
	DoubleLinkedListNode<T>* node = seek(i);
	if (node == nullptr) {
		return false;
	}

	DoubleLinkedListNode<T>* parent = node->last;
	DoubleLinkedListNode<T>* child = node->next;

	if (parent == nullptr && child == nullptr) {
		//only node in the list
		first = nullptr;
		last = nullptr;

		delete node;
		length -= 1;
		return true;
	}
	if (parent == nullptr) {
		//first node in the list
		first = nullptr;

		node->next = nullptr;
		child->last = nullptr;

		delete node;
		length -= 1;
		return true;
	}
	if (child == nullptr) {
		//last node in the list
		last = nullptr;

		node->last = nullptr;
		parent->next = nullptr;

		delete node;
		length -= 1;
		return true;
	}

	//in the midsection of the list
	node->last = nullptr;
	node->next = nullptr;

	parent->next = child;
	child->last = parent;

	delete node;
	length -= 1
	return true;
}


template<typename T>
void DoubleLinkedList<T>::insert(T* value, int atIndex) {
	//insertions just after the last node should be treated as appends
	if (atIndex == length) {
		append(value);
		return;
	}

	DoubleLinkedListNode<T>* newChild = seek(atIndex);
	if (newChild == nullptr) {
		return false;
	}

	//the new node should take the place of the child
	DoubleLinkedListNode<T>* newNode = new DoubleLinkedListNode<T>(value);
	newNode->last = newChild->last;
	newNode->next = newChild;
	newChild->last = newNode;

	//ensure first is accurate
	if (newChild == first) {
		first = newNode;
	}

	length += 1;
}

template<typename T>
void DoubleLinkedList<T>::insertFront(T* value) {
	DoubleLinkedListNode<T>* newNode = new DoubleLinkedListNode<T>(value);

	if (first != nullptr) {
		//non-empty list, replace first
		newNode->next = first;
		first->last = newNode;

		first = newNode;
	}
	else {
		//empty list, first node to be added
		first = newNode;
		last = newNode;
	}

	length += 1;
}

template<typename T>
void DoubleLinkedList<T>::append(T* value) {
	DoubleLinkedListNode<T>* newNode = new DoubleLinkedListNode<T>(value);

	if (last != nullptr) {
		//non-empty list, replace last
		last->next = newNode;
		newNode->last = last;

		last = newNode;
	}
	else {
		//empty list, first node to be added
		first = newNode;
		last = newNode;
	}

	length += 1;
}