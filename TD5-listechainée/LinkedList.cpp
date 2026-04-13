#include "LinkedList.h"
#include <string>
#include <ostream>

Link* LinkedList::getLink(int position)
{
	if (position<0 || position>size()) {
		throw std::out_of_range("Veuillez rentrer une position supperieure ou egale a 0 ou une position qui qui existe(pas trop grande)");
	}
	Link* actuel = firstLink;
	int compteur = 0;
	while ( compteur!=position) {
		actuel = actuel->getNextLink();
		compteur++;
	}
	return actuel;
}
LinkedList::LinkedList()
	:firstLink(nullptr), lastLink(nullptr)
{

}
LinkedList::~LinkedList()
{
	Link* actuel = firstLink;
	while (actuel != nullptr) {
		Link* suivant = actuel->getNextLink();
		delete actuel;
		actuel = suivant;
	}
}
int LinkedList::size()
{
	Link* actuel = firstLink;
	int compteur = 0;
	while (actuel != nullptr) {
		compteur++;
		actuel = actuel->getNextLink();
	}
	return compteur;
}
void LinkedList::add(int value)
{
	if (firstLink == nullptr && lastLink == nullptr) {
		Link* newLink = new Link(value, nullptr, nullptr);
		firstLink = newLink;
		lastLink = newLink;
	}
	else {
		Link* newLink = new Link(value, lastLink, nullptr);
		lastLink->setNextLink(newLink);
		lastLink = newLink;
	}
}
void LinkedList::insert(int value, int position)
{
	Link* linkposition;
	linkposition = getLink(position);
	Link link_insert(value,linkposition->getPreviousLink(), linkposition);
	linkposition->getPreviousLink()->setNextLink(&link_insert);
	linkposition->setPreviousLink(&link_insert);
}
void LinkedList::remove(int position)
{
	Link* linkToRemove = getLink(position);
	if (linkToRemove == firstLink) {
		firstLink = linkToRemove->getNextLink();
		if (firstLink != nullptr) {
			firstLink->setPreviousLink(nullptr);
		}
		else {
			lastLink = nullptr;
		}
	}
	else if (linkToRemove == lastLink) {
		lastLink = linkToRemove->getPreviousLink();
		lastLink->setNextLink(nullptr);
	}
	else {
		linkToRemove->getPreviousLink()->setNextLink(linkToRemove->getNextLink());
		linkToRemove->getNextLink()->setPreviousLink(linkToRemove->getPreviousLink());
	}
	delete linkToRemove;
}
int LinkedList::operator[](int position)
{
	Link* linkposition;
	linkposition = getLink(position);
	return linkposition->getData();
}