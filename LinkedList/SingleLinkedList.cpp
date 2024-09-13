#include "SingleLinkedList.hpp"

template <typename T>
SingleLinkedListNode<T>::SingleLinkedListNode(T* _value) {
	next = _next;
	value = _value;
}


template <typename T>
SingleLinkedListNode<T>* SingleLinkedList<T>::seek(int i) {

}

template <typename T>
SingleLinkedList<T>::SingleLinkedList<T>() {
	first = nullptr;
	last = nullptr;
	length = 0;
}

template <typename T>
T* SingleLinkedList<T>::get(int i) {

}

template <typename T>
void SingleLinkedList<T>::set(int i, T* value) {

}

template <typename T>
bool SingleLinkedList<T>::remove(int i) {

}

template <typename T>
void SingleLinkedList<T>::insert(T* value, int atIndex) {

}

template <typename T>
void SingleLinkedList<T>::insertFront(T* value) {

}

template <typename T>
void SingleLinkedList<T>::append(T* value) {

}