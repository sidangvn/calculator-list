#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "CalcList.hpp"

//Default constructor
Llist::Llist(): head(nullptr)
{
	//nothing
}

//put to front - foundation
void Llist::inFront(Buff elem) //Dlist is doubly linked list
{
	Node* value = new Node; //create a new node
	value -> elem = elem;	//set element to the node
	value -> next = head;	//moving the element to the first node
	head = value;	
}

//remove the front - foundation
void Llist::removeFront()
{
	Node* value = head; //set value to head of node
	head = head -> next; //moving value to head
	delete value; //delete the value
}

//checking for empty list
bool Llist::isEmpty() const
{
	return (head == nullptr);
}

//Destructor
Llist::~Llist()
{
	while(!isEmpty()) 
	{
		removeFront(); //pop out all head values
	}
	delete head;
}

//count the index of the linked list
int Llist::count() const
{
	Node* temp = head;
	int num = 0;
	
	//count nodes
	while(temp != nullptr)
	{
		temp = temp -> next;
		num++;
	}
	return num;
}

//TOTAL
double CalcList::total() const
{
	return totalAll;
}

//New Operation
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{
	double newTotal = 0.00;	
	std::string math;
	std::string signs;

	switch(func)
	{
		case ADDITION: signs = "+";
			newTotal = operand + totalAll;
			break;
		
		case MULTIPLICATION: signs = "*";
			newTotal = totalAll * operand;
			break;
	
		case SUBTRACTION: signs = "-";
			newTotal = totalAll - operand;
			break;

		case DIVISION: signs = "/";
			while(operand == 0)
			{
				throw(std::exception()); 
				break;
			}
			newTotal = totalAll / operand;
			break;
	}
	
	Buff total = {signs, operand, totalAll, newTotal};
	llist.inFront(total); //add the total to front node of Buff class
	totalAll = newTotal; //update total
} 

//remove Last Operation
void CalcList::removeLastOperation()
{
	
	while(llist.isEmpty())
	{
		throw(std::exception());
		break;		
	}
		llist.removeFront();

	if(llist.isEmpty())
	{
		totalAll = 0.00;
	}

	else
	{
		totalAll = llist.head -> elem.finl;	
	}
}

//tostring
std::string CalcList::toString(unsigned short precision) const
{
	Node* foo = llist.head;
	int count = llist.count(); //get count number for each line

	std::string output;
	std::to_string(count); //converts count from int to string type
	std::to_string(totalAll);//coverts totalAll from double to string type
	
	while(foo != nullptr)
	{	
		//read from the string as if it were a stream
		std::stringstream prev;
		prev << std::fixed << std::setprecision(precision) << foo -> elem.prev;
		std::stringstream last;
		last << std::fixed << std::setprecision(precision) << foo -> elem.last;
		std::stringstream finl;
		finl << std::fixed << std::setprecision(precision) << foo -> elem.finl;
		
		//output the results in string 
		output.append(std::to_string(count) + ": " + prev.str() + foo -> elem.val + last.str() + "=" + finl.str() + "\n");
	
		foo = foo -> next;
		count--;
	}

	return output;
}














