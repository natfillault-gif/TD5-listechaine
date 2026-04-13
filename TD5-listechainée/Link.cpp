#include "Link.h"
#include <iostream>

Link::Link(int data, Link* previousLink, Link* nextLink) 
{
	this->data = data;
	this->previousLink = previousLink;
	this->nextLink = nextLink;
}
Link::~Link()
{
	std::cout << "Maillon detruit " << data << std::endl;
}
int Link::getData()
{
	return data;
}
Link* Link::getPreviousLink()
{
	return previousLink;
}
Link* Link::getNextLink()
{
	return nextLink;
}
void Link::setData(int value)
{
	data = value;
}
void Link::setPreviousLink(Link* link)
{
	previousLink = link;
}
void Link::setNextLink(Link* link)
{
	nextLink = link;
}