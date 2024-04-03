#pragma once
#include <iostream>
#include <stdexcept>
#include <functional>

template <typename T, typename comparer = std::less<T>>
class Set
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node(T v = T(), Node* n = nullptr): value(v), next(n) { }
	};
	Node* head;
	int _size;
	comparer compare;
public:
	Set(): head(new Node(T())), _size(0) { }
	Set(const Set<T, comparer>& other): head(new Node(T())), _size(other._size)
	{
		if (_size > 0)
		{
			Node* curr = head;
			Node* source = other.head->next;
			while (source != nullptr)
			{
				curr->next = new Node(source->value);
				curr = curr->next;
				source = source->next;
			}
		}
	}
	Set(const T& x): head(new Node(T(), new Node(x))), _size(1){ }
	~Set()
	{
		while (head != nullptr)
		{
			Node* victim = head;
			head = head->next;
			delete victim;
		}
	}
	Set(T* arr, int n);
	Set<T, comparer>& operator=(const Set<T, comparer>& other);
	Set<T, comparer>& add(const T& x);
	Set<T, comparer>& addRange(T* arr, int n)
	{
		for (int i = 0; i < n; ++i) this->add(arr[i]);
		return *this;
	}
	Set<T, comparer>& remove(const T& x);
	Set<T, comparer>& clear()
	{
		Node*& curr = head->next;
		while (curr != nullptr)
		{
			Node* victim = curr;
			curr = curr->next;
			delete victim;
		}
		_size = 0;
		return *this;
	}
	int size() const { return this->_size; }
	bool contain(const T& x)
	{
		Node* curr = head->next;
		while (curr != nullptr && 
			(compare(curr->value, x) || compare(x, curr->value))) curr = curr->next;
		return curr != nullptr;
	}
	Set<T, comparer> set_union(const Set<T, comparer>& other);
	Set<T, comparer> intersect(const Set<T, comparer>& other);
	Set<T, comparer> difference(const Set<T, comparer>& other);
	void printOn(std::ostream& os) const
	{
		os << "Set{";
		Node* curr = head->next;
		while (curr != nullptr)
		{
			os << ' ' << curr->value;
			curr = curr->next;
		}
		os << " }";
	}
	T* to_array() const
	{
		T* arr = new T[_size];
		Node* curr = head->next;
		for (int i = 0; i < _size; ++i, curr = curr->next) arr[i] = curr->value;
		return arr;
	}
	class Iterator
	{
	private:
		Node* ptr;
	public:
		Iterator(Node* p = nullptr) : ptr(p) {}
		bool operator==(const Iterator& other) const
		{
			return this->ptr == other.ptr;
		}
		bool operator!=(const Iterator& other) const
		{
			return this->ptr != other.ptr;
		}
		Iterator& operator++()
		{
			ptr = ptr->next;
			return *this;
		}
		T operator*() const { return ptr->value; }
	};
	Iterator begin() { return Iterator(head->next); }
	Iterator end() { return Iterator(); }
};

template <typename T, typename comparer = std::less<T>>
std::ostream& operator<<(std::ostream& os, const Set<T, comparer>& S)
{
	S.printOn(os);
	return os;
}

template <typename T, typename comparer>
inline Set<T, comparer>::Set(T* arr, int n): head(new Node(T())), _size(0)
{
	for (int i = 0; i < n; ++i) this->add(arr[i]);
}

template <typename T, typename comparer>
inline Set<T, comparer>& Set<T, comparer>::operator=(const Set<T, comparer>& other)
{
	return *this;
}

template <typename T, typename comparer>
inline Set<T, comparer>& Set<T, comparer>::add(const T& x)
{
	Node* curr = head;
	while (curr->next != nullptr && compare(curr->next->value, x))
		curr = curr->next;
	if (curr->next == nullptr || compare(x, curr->next->value))
	{
		curr->next = new Node(x, curr->next);
		++_size;
	}
	return *this;
}

template <typename T, typename comparer>
inline Set<T, comparer>& Set<T, comparer>::remove(const T& x)
{
	Node* curr = head;
	while (curr->next != nullptr && compare(curr->next->value, x))
		curr = curr->next;
	if (curr->next == nullptr || compare(x, curr->next->value))
		throw std::runtime_error("No such element in the Set");
	Node* victim = curr->next;
	curr->next = victim->next;
	delete victim;
	--_size;
	return *this;
}

template <typename T, typename comparer>
inline Set<T, comparer> Set<T, comparer>::set_union(const Set<T, comparer>& other)
{
	Set<T, comparer> C;
	Node* c = C.head;
	Node* a = this->head->next;
	Node* b = other.head->next;
	while (a != nullptr && b != nullptr)
	{
		if (compare(a->value, b->value))
		{
			c->next = new Node(a->value);
			a = a->next;
		}
		else if (compare(b->value, a->value))
		{
			c->next = new Node(b->value);
			b = b->next;
		}
		else
		{
			c->next = new Node(a->value);
			a = a->next;
			b = b->next;
		}
		c = c->next;
		++C._size;
	}
	while (a != nullptr)
	{
		c->next = new Node(a->value);
		a = a->next;
		c = c->next;
		++C._size;
	}
	while (b != nullptr)
	{
		c->next = new Node(b->value);
		b = b->next;
		c = c->next;
		++C._size;
	}
	return C;
}

template <typename T, typename comparer>
inline Set<T, comparer> Set<T, comparer>::intersect(const Set<T, comparer>& other)
{
	Set<T, comparer> C;
	Node* c = C.head;
	Node* a = this->head->next;
	Node* b = other.head->next;
	while (a != nullptr && b != nullptr)
	{
		if (compare(a->value, b->value)) a = a->next;
		else if (compare(b->value, a->value)) b = b->next;
		else
		{
			c->next = new Node(a->value);
			a = a->next;
			b = b->next;
			c = c->next;
			++C._size;
		}
	}
	return C;
}

template <typename T, typename comparer>
inline Set<T, comparer> Set<T, comparer>::difference(const Set<T, comparer>& other)
{
	Set<T, comparer> C;
	Node* c = C.head;
	Node* a = this->head->next;
	Node* b = other.head->next;
	while (a != nullptr && b != nullptr)
	{
		if (compare(a->value, b->value))
		{
			c->next = new Node(a->value);
			a = a->next;
			c = c->next;
			++C._size;
		}
		else if (compare(b->value, a->value))
		{
			b = b->next;
		}
		else
		{
			a = a->next;
			b = b->next;
		}
	}
	while (a != nullptr)
	{
		c->next = new Node(a->value);
		a = a->next;
		c = c->next;
		++C._size;
	}
	return C;
}
