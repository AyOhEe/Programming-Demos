template <typename T>
struct DoubleLinkedListNode {
	DoubleLinkedListNode<T>* next;
	DoubleLinkedListNode<T>* last;
	T* value;

	DoubleLinkedListNode<T>(T* _value);
};

template <typename T>
struct DoubleLinkedList {
private:
	DoubleLinkedListNode<T>* first;
	DoubleLinkedListNode<T>* last;
	int length;

	DoubleLinkedListNode<T>* seek(int i);

public:
	DoubleLinkedList<T>();

	T* get(int i);
	void set(int i, T* value);

	bool remove(int i);

	void insert(T* value, int atIndex);
	void insertFront(T* value);
	void append(T* value);
};
