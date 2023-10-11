// Isa Ortiz-Acosta
// CS 303
// Assignment 3
// Due 10/10/23

#include "Single_Linked_List.h"
#include <iostream>


using namespace std;

// adds a node to the front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(Item_Type val) {
	Node* newNode = new Node(val); // create the new node
	if (head == nullptr) { // if the list is empty, set the new node as the head and tail
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head; // make new node point to the head
		head = newNode; // set new node as the head
	}
	num_items++; // increment
};

//adds an item to the end of a list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(Item_Type val) {
	Node* newNode = new Node(val); // create new node using given data
	if (head == nullptr) {// if list is empty
		head = newNode;// first node will be the head and tail
		tail = newNode;
	}
	else {
		newNode->next = nullptr;// set the new node's next to null
		tail->next = newNode; // have the current tail point to the new node
		tail = newNode; // make new node the tail
	}
	num_items++; // increment
}

// removes the first node in the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
	if (head == nullptr)// if list is empty, break out of the function
		return;
	else {
		Node* temp = head; // save the head to a temporary node
		head = head->next; // set the next list element as the head
		delete temp; // delete the data stored in the previous head
	}
	num_items--; // decrement
}

// removes the last item in the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
	if (head == nullptr) // if list is empty, break out of the function
		return;
	else {
		Node* temp = head;// set a temporary node
		while (temp->next != tail) //cycles through the list untl the element before the tail is reached
			temp = temp->next;
		delete tail; // delete the data stored in the tail
		temp->next = nullptr; //set the temp's next to null
		tail = temp; // set the tail to the temporary node
	}
	num_items--;// decrement
}

// returns the data stored in the head
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() {
	return head->data;
}

// returns the data stored in the tail
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() {
	return tail->data;
}

// determines if the list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() {
	if (num_items >= 1)// if num_items is greater than 1
		return false; // return false
	else
		return true; // otherwise return true
}

// inserts a new node into a given position in the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (index == 0) {// if the index is 0
		push_front(item);// set the newest item as the head
	}
	else if (index >= num_items) {// if the index is greater than the number of values in the list
		push_back(item);// set it as the tail
	}
	else {
		Node* newNode = new Node(item);// create the new node
		int count = 0;
		Node* currptr = head;// create a pointer to cycle through the list
		while (count < index-1) {// cycle through the list until currptr is in the position before insertion
			currptr = currptr->next;
			count++;
		}
		newNode->next = currptr->next;// set newNode's next to currptrs next
		currptr->next = newNode;// set currptr's next to the new node
	}
	num_items++; // increment
}

// remove a value at a given index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
	if (index >= num_items) {// exit the function if the index to be removed is greater than the size of the list
		return false;
	}
	else if (index == num_items - 1)// if the index points to the last element in the list, pop off the tail
		pop_back();
	else if (index == 0) {// if the index points to the first element, pop the head
		pop_front();
		num_items--;// decrement
		if (num_items == 0) {// if the head was the only element in the list, also clear the head and tail
			tail = nullptr;
			head = nullptr;
		}
		return true;
	}
	else {
		int count = 0;
		Node* currptr = head;
		while (count < index - 1) {// cycle through the list until currptr is in the position before removal
			currptr = currptr->next;
			count++;
		}
		Node* rem_ptr = currptr->next; // set a pointer to the node to be removed
		currptr->next = rem_ptr->next;// have the current pointer point to the node after the one being removed
		delete rem_ptr;// delete the node and set it to null
		rem_ptr = nullptr;
		num_items--;// decrement
		return true;
	}
}

// returns the index of a specific data value
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
	size_t count = 0;
	Node* currptr = head; // set a temporary pointer to the head
	while (count < num_items) {// cycle through the list
		if (currptr->data == item) {// if currptr contains the requested data
			return count;// return the index
		}
		currptr = currptr->next;// otherwise continue cycling
		count++;
	}
	return num_items;// if it is not found, return the size of the list
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::print() {
	Node* curr = head;
	for (int i = 0; i < num_items; i++) {		
		cout << curr->data << endl;
		if (curr->next != nullptr)
			curr = curr->next;
	}
	cout << "Head: " << head->data << " Tail: " << tail->data << endl << endl;
}

// calculates the employee's weekly salary
float Employee::Calc_Weekly_Salary() {
	float salary = hours_worked * hourly_rate;// multiply the worker's hourly rate by their hours worked
	weekly_salary = salary;
	return salary;
}

// calculates the employee's vacation days
int Employee::Calc_Vacation_Days() {
	int v_days = hours_worked % 120; // one vacation day is given for every 120 hours worked;
	vacation_days = v_days;
	return v_days;
}

// calculates how much is an employee's health insurance contribution
float Employee::Calc_Health_Insurance() {
	float contribution = Calc_Weekly_Salary() * 0.20; //health insurance contributions will be 4% of their weekly salary
	health_insurance = contribution;
	return contribution;
}

void Employee::print() {
	cout << "Name: " << name << endl;
	cout << "Weekly Salary: " << weekly_salary << endl;
	cout << "Vacation Days: " << vacation_days << endl;
	cout << "Health Insurance contribution: " << health_insurance << endl;
}

// calculates a professional employee's weekly salary
float Professional::Calc_Weekly_Salary() {
	float salary = monthly_salary / 4.0; // assuming there are 4 weeks in a month, weekly salary is monthly salary divided by 4
	weekly_salary = salary;
	return salary;
}

float Professional::Calc_Health_Insurance() {
	float contribution = weekly_salary * .25; // professionals contribute 25% of their weekly salary to their health insurance 
	health_insurance = contribution;
	return contribution;
}

// default constructor for a professional employee
Professional::Professional(string n, int hw, float mr) : Employee(){
	name = n;
	hours_worked = hw;
	monthly_salary = mr;
	weekly_salary = Calc_Weekly_Salary();
	vacation_days = 10;
	health_insurance = Calc_Health_Insurance();
}

void Professional::print() {
	cout << "Name: " << name << endl;
	cout << "Monthly Salary: " << monthly_salary << endl;
	cout << "Weekly Salary: " << weekly_salary << endl;
	cout << "Vacation Days: " << vacation_days << endl;
	cout << "Health Insurance contribution: " << health_insurance << endl;
}

Nonprofessional::Nonprofessional(string n, int hw, float hr) : Employee() {
	name = n;
	hours_worked = hw;
	hourly_rate = hr;
	weekly_salary = Calc_Weekly_Salary();
	vacation_days = Calc_Vacation_Days();
	health_insurance = Calc_Health_Insurance();
}

int main() {
	/*
	Single_Linked_List<string> mylist;
	mylist.push_back("A");
	mylist.push_back("B");
	mylist.push_back("C");
	mylist.print();
	mylist.push_front("D");
	mylist.print();
	mylist.insert(3, "E");
	mylist.print();
	mylist.remove(4);
	mylist.print();
	cout << mylist.find("B") << endl << endl;
	cout << mylist.empty() << endl << endl;
	mylist.remove(0);
	mylist.remove(0);
	mylist.remove(0);
	mylist.remove(0);
	cout << mylist.empty();*/

	/*
	Nonprofessional Isa = Nonprofessional("Isa", 30, 18.00);
	Isa.print();
	cout << endl << endl;
	Professional Bella = Professional("Bella", 45, 4500);
	Bella.print();
	*/
}