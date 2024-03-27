#pragma once
template <typename T>
class Set
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node(T v = T(), Node* n = nullptr): value(v), next(n) { }
		~Node() { delete next; }
	};
	Node* head;
	int size;
public:
	Set(): head(nullptr), size(0) { }
	Set(const Set<T>& other);
	Set(const T& x): head(new Node(x)), size(1) { }
	~Set() { delete head; }
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
};