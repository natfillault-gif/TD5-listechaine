#pragma once
#include "Link.h"

class LinkedList
{
private:
	Link* firstLink;
	Link* lastLink;
	Link* getLink(int position);

public:
	LinkedList();
	~LinkedList();
	int size();
	void add(int valeur);
	void insert(int value, int position);
	void remove(int position);
	int operator[](int position);

};

