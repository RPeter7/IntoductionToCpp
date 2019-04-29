#include "pch.h"
#include "Stack.h"
#include <vector>

template<typename T>
Stack<T>::Stack() :
	_top(0)
{
}

template<typename T>
bool Stack<T>::empty() const
{
	return _top == 0;
}

template<typename T>
void Stack<T>::push(const T& data_)
{
	StackElement* newElement = new StackElement();
	newElement->data = data_;
	newElement->next = _top;
	_top = newElement;
}

template<typename T>
T Stack<T>::pop()
{
	T topData = _top->data;
	StackElement* oldTop = _top;
	_top = _top->next;
	delete oldTop;
	return topData;
}

template<typename T>
T Stack<T>::top() const
{
	return _top->data;
}

template<typename T>
Stack<T>::~Stack()
{
	while (!empty())
	{
		pop();
	}
}

template<typename T>
Stack<T>::Stack(const Stack& stack_) :
	_top(0)
{
	StackElement* p = stack_._top;
	std::vector<T> elements;
	while (p)
	{
		elements.push_back(p->data);
		p = p->next;
	}
	std::reverse(elements.begin(), elements.end());
	for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it)
	{
		push((*it));
	}
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& stack_)
{
	while (!empty())
	{
		pop();
	}

	StackElement* p = stack_._top;
	std::vector<T> elements;
	while (p)
	{
		elements.push_back(p->data);
		p = p->next;
	}
	std::reverse(elements.begin(), elements.end());
	for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it)
	{
		push(*it);
	}
	return *this;
}

template<typename T>
Stack<T>::Iterator::Iterator() :
	_current(0)
{
}

template<typename T>
Stack<T>::Iterator::Iterator(StackElement* current_) :
	_current(current_)
{
}

template<typename T>
typename Stack<T>::Iterator& Stack<T>::Iterator::operator++()
{
	_current = _current->next;
	return *this;
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::Iterator::operator++(int)
{
	Iterator oldValue = *this;
	_current = _current->next;
	return oldValue;
}

template<typename T>
T& Stack<T>::Iterator::operator*()
{
	return _current->data;
}

template<typename T>
bool Stack<T>::Iterator::operator==(const Iterator& rhs_)
{
	return this->_current == rhs_._current;
}

template<typename T>
bool Stack<T>::Iterator::operator!=(const Iterator& rhs_)
{
	return this->_current != rhs_._current;
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::begin()
{
	return Iterator(_top);
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::end()
{
	return Iterator(0);
}

template class Stack<int>;
