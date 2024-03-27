#pragma once
#include <iostream>
template <typename T>
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
	int size;
public:
	Set(): head(new Node(T())), size(0) { }
	Set(const Set<T>& other);
	Set(const T& x): head(new Node(T(), new Node(x))), size(1){ }
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
	Set<T>& operator=(const Set<T>& other);
	Set<T>& add(const T& x);
	Set<T>& addRange(T* arr, int n)
	{
		for (int i = 0; i < n; ++i) this->add(arr[i]);
		return *this;
	}
	Set<T>& remove(const T& x);
	int Size() const { return this->size; }
	bool contain(const T& x);
	Set<T> set_union(const Set<T>& other);
	Set<T> intersect(const Set<T>& other);
	Set<T> difference(const Set<T>& other);
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
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& S)
{
	S.printOn(os);
	return os;
}

template<typename T>
inline Set<T>::Set(const Set<T>& other): head(new Node(T())), size(other.size)
{
	if (size > 0)
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

template<typename T>
inline Set<T>::Set(T* arr, int n): head(new Node(T())), size(0)
{
	for (int i = 0; i < n; ++i) this->add(arr[i]);
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& other)
{
	return *this;
}

template<typename T>
inline Set<T>& Set<T>::add(const T& x)
{
	Node* curr = head;
	while (curr->next != nullptr && curr->next->value < x)
		curr = curr->next;
	if (curr->next == nullptr || x < curr->next->value)
	{
		curr->next = new Node(x, curr->next);
		++size;
	}
	return *this;
}
