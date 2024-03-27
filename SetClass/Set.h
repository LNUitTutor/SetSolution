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
	Set(): head(nullptr), size(0) { }
	Set(const Set<T>& other);
	Set(const T& x): head(new Node(x)), size(1) { }
	~Set()
	{
		Node* victim = head;
		while (victim != nullptr)
		{
			head = head->next;
			delete victim;
			victim = head;
		}
	}
	Set(T* arr, int n);
	Set<T>& operator=(const Set<T>& other);
	Set<T>& add(const T& x);
	Set<T>& addRange(T* arr, int n);
	Set<T>& remove(const T& x);
	int size() const { return this->size; }
	bool contain(const T& x);
	Set<T> set_union(const Set<T>& other);
	Set<T> intersect(const Set<T>& other);
	Set<T> difference(const Set<T>& other);
	void printOn(std::ostream& os) const;
};

template<typename T>
inline Set<T>::Set(const Set<T>& other): head(nullptr), size(other.size)
{
	if (size > 0)
	{
		head = new Node(other.head->value);
		Node* curr = head;
		Node* source = other.head->next;
		while (next != nullptr)
		{
			curr->next = new Node(source->value);
			curr = curr->next;
			source = source->next;
		}
	}
}

template<typename T>
inline Set<T>::Set(T* arr, int n): head(nullptr), size(0)
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
	Node phantom(0, head);
	while (phantom->next != nullptr && phantom->next->value < x)
		phantom->next = phantom->next->next;
	phantom->next = new Node(x, phantom->next);
}
