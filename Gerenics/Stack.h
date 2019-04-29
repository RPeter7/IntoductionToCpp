#pragma once
template<typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack& stack_);
	Stack& operator=(const Stack& rhs_);
	~Stack();

	void push(const T& data_);
	T pop();
	bool isEmpty() const;
private:

	struct StackElement
	{
	public:
		T data;
		StackElement* next;
	};

	StackElement* _top;
public:
	class iterator
	{
	public:
		iterator();
		iterator(StackElement* element_);
		bool operator!=(const iterator& rhs_);
		iterator& operator++(); //prefix
		iterator& operator++(int); //postfix
		T& operator*();
	private:
		StackElement* _current;
	};

	iterator begin();
	iterator end();
};