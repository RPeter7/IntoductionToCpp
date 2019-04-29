#include "pch.h"
#include "Stack.h"
#include <string>

using namespace std;

template<typename T>
Stack<T>::Stack() :
	_top(nullptr)
{
}

template<typename T>
Stack<T>::Stack(const Stack & stack_)
{
	//HF megirni ezt
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack & rhs_)
{
	// TODO: insert return statement here
	return this*;
}

template<typename T>
Stack<T>::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template<typename T>
void Stack<T>::push(const T & data_)
{
	StackElement* newElement = new StackElement();
	newElement->data = data_;
	newElement->next = _top;
	_top = newElement;
}

template<typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		T oldValue = _top->data;
		StackElement* oldTop = _top;
		_top = _top->next;
		delete oldTop;
		return oldValue;
	}
	throw "Üres a verem!";
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return _top == nullptr;
}

template<typename T>
Stack<T>::iterator::iterator() :
	_current(nullptr)
{

}

template<typename T>
Stack<T>::iterator::iterator(StackElement* element_) :
	_current(element_)
{

}

template<typename T>
bool Stack<T>::iterator::operator!=(const iterator & rhs_)
{
	return _current != rhs_._current;
}

template<typename T>
typename Stack<T>::iterator& Stack<T>::iterator::operator++()
{
	_current = _current->next;
	return *this;
}

template<typename T>
template Stack<T>::iterator& Stack<T>::iterator::operator++(int)
{
	iterator& oldValue = *this;
	_crrent = _current->next;
	return oldValue;
}

template<typename T>
T & Stack<T>::iterator::operator*()
{
	return _current->data;
}

template<typename T>
typename /*<-Ez ide kell*/ Stack<T>::iterator Stack<T>::begin()
{
	return iterator(_top);
}

template<typename T>
typename /*<-Ez ide kell*/ Stack<T>::iterator Stack<T>::end()
{
	return iterator(); //ez a nullptr re mutat!!
}

template class Stack<int>; //muszaj megmondani, hogy mivel akarom hasznalni.
template class Stack<string>;