#pragma once

template <typename T>
struct SingleLinkedListNode {
	SingleLinkedListNode<T>* next;
	T* value;

	SingleLinkedListNode<T>(T* _value, SingleLinkedListNode* _next);
};
