#pragma once

class Link
{
private:
	int data;
	Link* previousLink;
	Link* nextLink;

public:
	Link(int data, Link* previousLink, Link* nextLink);
	~Link();
	int getData();
	Link* getPreviousLink();
	Link* getNextLink();
	void setData(int value);
	void setPreviousLink(Link* link);
	void setNextLink(Link* link);
};

