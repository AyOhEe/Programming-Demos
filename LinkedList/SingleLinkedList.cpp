#include "SingleLinkedList.hpp"

template <typename T>
SingleLinkedListNode<T>::SingleLinkedListNode(T* _value, SingleLinkedListNode* _next) {
	next = _next;
	value = _value;
}