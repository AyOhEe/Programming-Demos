#include "DoubleLinkedList.hpp"

template<typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(T* _value) {
	value = _value;
}


template<typename T>
void DoubleLinkedListNode<T>::attachParent(DoubleLinkedListNode<T>* _last) {
	//detach ourselves from the current parent
	if (last != nullptr) {
		last->next = nullptr;
	}

	//store the new parent
	last = _last;

	if (last != nullptr) {
		//detach the old child
		last->next->last = nullptr;

		//replace the old child
		last->next = this;
	}
}

template<typename T>
void DoubleLinkedListNode<T>::attachChild(DoubleLinkedListNode<T>* _next) {
	//detach the old child from ourselves
	if (next != nullptr) {
		next->last = nullptr;
	}

	//store the new child
	next = _next;

	if (next != nullptr) {
		//detach the old parent
		next->last->next = nullptr;

		//replace the old parent
		next->last = this;
	}
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
		return true;
	}
	if (parent == nullptr) {
		node->next = nullptr;
		child->last = nullptr;

		return true;
	}
	if (child == nullptr) {
		node->last = nullptr;
		parent->next = nullptr;

		return true;
	}

	node->last = nullptr;
	node->next = nullptr;

	parent->next = child;
	child->last = parent;

	return true;
}


template<typename T>
void DoubleLinkedList<T>::insert(T value, int atIndex) {

}

template<typename T>
void DoubleLinkedList<T>::insertFront(T value) {

}

template<typename T>
void DoubleLinkedList<T>::append(T value) {

}