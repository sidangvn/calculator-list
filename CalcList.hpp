#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"
#include <string>


class Buff
{
	public:
		std::string val;
		double last;
		double prev;
		double finl;			
};


class Node
{
	public:
		Buff elem;
		Node *next;
};

//Linked List
class Llist
{
	public:
		Llist();
		void inFront(Buff elem);
		void removeFront();
		bool isEmpty() const;
		~Llist();
		int count() const;
		Node *head;
};

//includes an abstract class for the CalcList from which to inherit
class CalcList:public CalcListInterface
{
	private:
		Llist llist;
		double totalAll = 0;
	public:
		virtual double total() const;
		virtual void newOperation(const FUNCTIONS func, const double operand);
		virtual void removeLastOperation();
		virtual std::string toString(unsigned short precision) const;
};


#endif
