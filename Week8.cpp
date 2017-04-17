// Node.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Node {
	int value;
	Node* next;
	Node():value(0),next(NULL){}
	Node(int v) : value(v),next(NULL) {}
	Node(int v,Node x ):value(v),next(&x) {}
};

class List {
private:
	int listlength;
	Node* lastNode;
	Node* firstNode;
	Node* node;

public:
	List();
	List(const vector<int>& v);
	List(int* array, int size);

	void add(int v);
	int length() const;
	bool insert(int pos, int v);
	int find(int v);
	int remove(int value);
	bool split(int pos, List& new_list);
	void combine(List& append_list);
	void printAll();
};


void List::add(int v) {
	node = new Node();
	node->value = v;
	if (lastNode == NULL) {
		firstNode = node;
		lastNode = node;
	}
	else {
		lastNode->next = node;
		lastNode = node;
	}
	++listlength;
}


List::List() {
	lastNode = NULL;
	firstNode = NULL;
	listlength = 0;
}

List::List(const vector<int> & v) {
	for (int i = 1; i < v.size() + 1; i++) {
		List::add(v[i - 1]);
	}
	listlength = v.size();
}


List::List(int* array,int array_size){
	for (int i = 1; i < array_size; i++) {
		List::add(array[i - 1]);
	}
	listlength = array_size;

}

int List::length() const{
	return listlength;
}

bool List::insert(int pos, int v) {
	int l = List::length();
	if (pos<0 || pos > l)
		return false;
	else {
		return true;
	}
}

int List::find(int v) {
	node = firstNode;
	int i = 0;
	while (node != NULL && node->value != v) {
		node = node->next;
		i++;
	}
	if (i == listlength) {
		cout << "value v is not found!" << endl;
		return -1;
	}
	else {
		return i;
	}
}

int List::remove(int v) {
	int i = 0;
	Node* temp = firstNode;
	if (temp == NULL) return 0;
	if (temp->value == v) {
		++i;
		firstNode = temp->next;
		if (temp->next == NULL) lastNode = NULL;
		delete(temp);
		return i;
	}
	while (temp->next != NULL && temp->next->value != v) {
		++i;
		temp = temp->next;
	}
	if (temp->next == NULL) return i;
	if (temp->next == lastNode) {
		lastNode = temp;
		delete(temp->next);
		temp->next = NULL;
	}
	else{
		node = temp->next;
		temp->next = node->next;
		++i;
		delete(node);
		temp->next = NULL;
	}
	return i;
}

bool List::split(int pos, List& new_list) {

	return true;
}

void List::combine(List& append_list) {


}

void List::printAll() {
	node = firstNode;
	while (node != NULL) {
		cout << node->value << endl;
		node = node->next;
	}
	cout << endl;
}

int main()
{
	ifstream in("D:\\work.txt");
	vector<int> v{ 1,2,3,4,5};
	List l = List(v);
	l.printAll();
    return 0;
}

