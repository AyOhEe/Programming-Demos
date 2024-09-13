template <typename T>
struct SingleLinkedListNode {
	SingleLinkedListNode<T>* next;
	T* value;

	SingleLinkedListNode<T>(T* _value);
};

template <typename T>
struct SingleLinkedList {
private:
	SingleLinkedListNode<T>* first;
	SingleLinkedListNode<T>* last;
	int length;

	SingleLinkedListNode<T>* seek(int i);

public:
	SingleLinkedList<T>();

	T* get(int i);
	void set(int i, T* value);

	bool remove(int i);

	void insert(T* value, int atIndex);
	void insertFront(T* value);
	void append(T* value);
};
