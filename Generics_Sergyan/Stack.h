#pragma once
#ifndef Stack_hpp
#define Stack_hpp

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();
	void push(const T&);
	T pop();
	T top() const;
	bool empty() const;
private:
	struct StackElement
	{
		T data;
		StackElement* next;
	};
	StackElement* _top;
public:
	class Iterator
	{
	public:
		Iterator();
		Iterator(StackElement*);
		Iterator& operator++();
		Iterator operator++(int);
		T& operator*();
		bool operator==(const Iterator&);
		bool operator!=(const Iterator&);
	private:
		StackElement* _current;
	};
public:
	Iterator begin();
	Iterator end();
};

#endif /* Stack_hpp */
