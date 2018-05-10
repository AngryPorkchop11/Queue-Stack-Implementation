// Mathew Lister
// CSC 2431
// HW 2: Stack and queue templated implmentation using a doubly linked list. The relationship between LinkedList and stack/queue is composition. 

#pragma once
#include <cassert>

#define ANSWER1 "The virtual key word is what allows you to override a base classes implementation." \
				"When you have a virtual method, it allows the compiler to call the derived class method." \

#define ANSWER2 "Templated classes have to be defined and implemented in the header because the compiler has to know" \
				"The parameter types to decide which methods to call at run time. Polymorphism allows us to use the same" \
				"method name multiple times, the compilers distinguishes them based on amount / types of parameters. In a" \
				"templated class that could cause the wrong method to be called."

/*
Start with your favorite linked list implementation. You may use the one from your previous lab, mine
if I ever release it, or from the textbook. Using that, implement:

1) A templated queue class that stores type T with the following public functions:
- void EnqueueOn(T t) - adds t to the end of the queue in O(n) time
- EnqueueO1(T t) - adds t to the end of the queue in O(1) time
- T Dequeue() - removes and returns the item at the front of the queue. In the case of an empty queue, exit the program
- T Peek() - returns the item at the front of the queue without removing it. In the case of an empty queue, exit the program
- unsigned int Size() - returns the number of items currently in the queue

2) A templated stack class that stores type T with the following public functions:
- void Push(T t) - adds t to the top of the stack
- T Pop() - removes and returns the item at the top of the stack. In the case of an empty queue, exit the program
- T Peek() - returns the item at the top of the stack without removing it. In the case of an empty queue, exit the program
- unsigned int Size() - returns the number of items currently in the queue


Again, the above function descriptions might or might not be missing additional decorations such as const or virtual.
At the top of "2431 Homework 2.cpp" is a working, example templated class. You'll see that it prints out questions in
need of answers. You should answer them below where ANSWER1 and ANSWER2 are defined. They're part of the homework
and will be graded.
It also shows an example of an "assert" statement, which is useful for verifying that something is true and then
exiting the program in the case of an error. Such a statement might be useful for other similar conditions.

Tips, hints, and things to think about:
- Should the relationship between LinkedList and Stack/Queue be inheritance or composition?
- Since stack and queue are simply constrained lists (stack can only add/remove from top and
queue can only add to end and remove from beginning) most of the work is in LinkedList. If you
find your Stack and Queue classes getting complicated, you're doing something wrong.
- You'll turn in this one file, Solution2.h. Thus, both declare and define your classes here.
*/

//---------------- LinkedList Class ----------------// 
template<class T>
class LinkedList
{
public:
//Testing---------------------------------------------------------------- 
	void Print()
	{
		Node *ptr = _head;
		cout << "[";
		while (ptr)
		{
			cout << ptr->data << ", ";
			ptr = ptr->next;
		}
		cout << "]";
		cout << " I'm a list. My size is " << GetSize() << endl;
	}
//------------------------------------------------------------------------
// Constructor	
	LinkedList()
	{
		_head = NULL;
		_tail = NULL;
		_size = 0;
	}
// Peek 
	T Peek()
	{
		if (_size == 0)
		{
			exit(1);
		}
		return _head->data;
	}

	unsigned int GetSize()
	{
		return _size;
	}
// Add item at back in O(N) time
	bool AppendItem(T t)
	{
		// Allocate a new node and fill data with current object 
		Node *ptrNew = new Node;
		ptrNew->data = t;

		// If the list is empty
		if (_size == 0)
		{
			_head = ptrNew;
			_tail = ptrNew;

			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;
			_size++;
			return true;
		}

		Node *ptr = _head;
		Node *run = _head;
		while (ptr)
		{
			run = ptr;
			ptr = ptr->next;
		}
		// Insert at end
		ptrNew->prev = run;
		ptrNew->next = NULL;
		run->next = ptrNew;
		_size++;
		return true;
	}
// Add item at back in O(1) time
	void AppendItemO1(T t)
	{
		// Allocate a new node and fill data with current object 
		Node *ptrNew = new Node;
		ptrNew->data = t;

		// If the list is empty
		if (_size == 0)
		{
			_head = ptrNew;
			_tail = ptrNew;

			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;
			_size++;
			return;
		}
		// Insert at end O(1)
		ptrNew->prev = _tail;
		_tail->next = ptrNew;
		ptrNew->next = NULL;
		_tail = ptrNew;
		_size++;
	}
// Add item at top
	bool PrependItem(T t)
	{
		// Allocate a new node and fill data with current object 
		Node *ptrNew = new Node;
		ptrNew->data = t;
		// If the list is empty
		if (_size == 0)
		{
			_head = ptrNew;
			_tail = ptrNew;
			_tail->next = NULL;
			_tail->prev = NULL;

			_head->next = NULL;
			_head->prev = NULL;
			_size++;
			return true;
		}
		// Insert at beginning of list
			ptrNew->next = _head;
			ptrNew->prev = NULL;
			_head->prev = ptrNew;
			_head = ptrNew;
			_size++;
			return true;
	}
// Delete from top
	T DeleteItem()
	{
		Node *ptr = _head;
		Node *run = _head;
		// Check for empty list
		if (_size == 0)
		{
			exit(1);
		}
		// If only one element
		else if (_size == 1)
		{
			_head = NULL;
			_tail = NULL;
			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
		// Remove from front
		else
		{
			_head->next->prev = NULL;
			_head = _head->next;
			
			_size--;
			T info = ptr->data;
			delete ptr;
			return info;
		}
	}
// Destructor
	~LinkedList()
	{
		if (_size == 0)
		{
			return;
		}

		Node *ptr = _head;
		Node *run = _head;
		while (ptr)
		{
			run = ptr->next;
			delete ptr;
			ptr = run;
		}
		delete run;

	}
protected:
	unsigned int _size;
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* _head;
	Node* _tail;
};

//---------------- Qeue Class ----------------// 
template<class T>
class Queue //FIFO
{
public:
	void EnqueueOn(T t) // adds t to the end of the queue in O(n) time
	{
		QueueList.AppendItem(t);
	}

	void EnqueueO1(T t) // adds t to the end of the queue in O(1) time
	{
		QueueList.AppendItemO1(t);
	}

	T Dequeue() // removes and returns the item at the front of the queue.In the case of an empty queue, exit the program
	{
		if (QueueList.GetSize() == 0)
		{
			exit(1);
		}
		return QueueList.DeleteItem();
	}

	T Peek() // returns the item at the front of the queue without removing it.In the case of an empty queue, exit the program
	{
		return QueueList.Peek();
	}
	unsigned int Size() // returns the number of items currently in the queue
	{
		return QueueList.GetSize();
	}
//Testing--------------------------------------
	void Qprint()
	{
		QueueList.Print();
	}
//-----------------------------------------------
private:
	LinkedList <T> QueueList;
};

//---------------- Stack Class ----------------// 
template<class T>
class Stack //LIFO
{
public:
	void Push(T t) // adds t to the top of the stack
	{
		StackList.PrependItem(t);
	}

	T Pop() // removes and returns the item at the top of the stack.In the case of an empty queue, exit the program
	{
		if (StackList.GetSize() == 0)
		{
			exit(1);
		}
		return StackList.DeleteItem();
	}

	T Peek() // returns the item at the top of the stack without removing it.In the case of an empty queue, exit the program
	{
		return StackList.Peek();
	}

	unsigned int Size() // returns the number of items currently in the queue
	{
		return StackList.GetSize();
	}
//Testing---------------------------------
	void Sprint()
	{
		StackList.Print();
	}

	bool SearchArray(T araryX, T size, T key)
	{
		for (int i = 0; i < size; i++)
		{
			if (arrayX[i] == key)
			{
				return true;
			}
		}
		return false;
	}

	bool SearchArray(T arrayX, T size, T key)
	{
		int i = 0;
		if (i == size)
		{
			return false;
		}
		if (arrayX[i] == key)
		{
			return true;
		}
		i++
			SearchArray(arrayX, size, key);
	}
//---------------------------------------
private:
	LinkedList <T> StackList;
};