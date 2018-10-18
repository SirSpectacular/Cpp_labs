#ifndef LIST_H
#define LIST_H

#include <ostream>
#include "Exception.h"
using namespace std;

template <typename T> class List;
template <typename T> class Node;
template<typename T> ostream& operator<<(ostream&, const List<T>&);
template<typename T> ostream& operator<<(ostream&, const Node<T>&);

template <typename T>
class List {
	Node<T> *first;
public:
	List<T>() : first{ nullptr } {}
	~List<T>();
	List<T>(const List<T>&) = delete;
	List<T>& operator=(const List<T>&) = delete;

	friend ostream& operator<< <T>(ostream&, const List<T>&);
	void insert(const T&);
	void remove();
};

template <typename T> 
class Node {
	friend class List<T>;

	T val;
	Node<T> *next;
	Node<T> *previous;

	Node<T>(T val) : val{ val }, next{ nullptr }, previous{ nullptr } {}
public:
	~Node<T>() = default;
	
	friend ostream& operator<< <T>(ostream&, const Node<T>&);
	Node<T>* getNext() const { return next; }
	Node<T>* getPrevious() const { return previous; }
};

template<typename T> ostream& operator<<(ostream &os, const Node<T> &node){
		return os << "( " << node.val << " ) ";
}

template<typename T> ostream& operator<<(ostream &os, const List<T> &list) {
	Node<T> *iterator = list.first;
	os << "[ ";
	if (list.first != nullptr) {
		while (iterator != nullptr) {
			os << *iterator;
			iterator = iterator->getNext();
		}
	}
	return os << " ]";
}

template<typename T>
List<T>::~List<T>() {
	Node<T> *iterator = this->first;
	while (iterator != nullptr) {
		Node<T> *garbageCollector = iterator;
		iterator = iterator->getNext();
		delete garbageCollector;
	}
}

template <typename T>
void List<T>::insert(const T &val) {
	if (this->first != nullptr) {
		Node<T>* dummy = this->first;
		this->first = new Node<T>(val);

		this->first->next = dummy;
		dummy->previous = this->first;
	}
	else {
		this->first = new Node<T>(val);
	}
}

template <typename T>
void List<T>::remove() {
	if (this->first == nullptr) throw Exception(7, "Attempted to remove element from empty list");
	Node<T>* dummy = this->first->getNext();
	delete this->first;
	this->first = dummy;
}

#endif //LIST_H
