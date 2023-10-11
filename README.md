# cs303_assignment2
Utilizing Single_Linked_List class:
An instance of this class, for this example it will be called mylist that is containing strings, the following functions are availible:

an extra function, mylist.print(), outputs the data values of each node in the linked list. it utilizes mylist.front() and mylist.back() to output the head and tail of the list. Neither of these functions requires a parameter. This function is utilized in the demonstrations for each class method

mylist.push_back() requires a value of Item_Type, in this case strings, and will result in the item being added as the tail ![Capture](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/e4e4b56a-8987-438a-952d-436ad8297700) Here, 3 items "A" "B" "C" have been added utilizing push_back

mylist.push_front() requires a value of Item_Type, and will result in the iem being added as the tail ![p2](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/32b2eea9-1c40-450d-8274-1dc5cbe79416) here, "D" is added to the front of the list

mylist.insert() requires two parameters: an int for the index and a value of Item_Type to be inserted into the list. A node with the value will be inserted at the given index. ![p3](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/3de4fee7-c778-47a4-baee-c93623ed7e3f) here, "E" is inserted at index 3.

mylist.remove requires one parameter: an int for the index where a node will be removed. Once the value is removed, this function returns true; if it is unable to remove the value, it returns false. ![p4](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/6708cd6a-b140-4376-bf04-030eec925694) This shows the list after mylist.remove(4) is called, removing "C" from the list.

mylist.find() requires one parameter: a value of Item_Type to be found. It locates the node containing the value and returns the int for the index where the node is located in the list 
mylist.empty() needs no parameters and returns a boolean of false if the list contains elements, and true if the list is empty.
the following image shows mylist.find("B"), which returns the integer 2, and then shows the result of mylist.empty() before and after clearing all of the elements from the list.![p5](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/bb0d93e5-c225-4795-ac54-fa85f91224ab)


Utilizing Employee, Professional, and Nonprofessional

Employee is the abstract class that contains the data members string name,float hourly_rate, int hours_worked, float weekly_salary, int vacation_days, and float health_insurance as well as functions Calc_Weekly_Salary(), Calc_Vacation_Days(), and Calc_Health_Insurance(). This class will not have any instances, so it will not have a constructor. The given functions mainly cater to the Nonprofessional derived class.

Calc_Weekly_Salary multiplies hours_worked * hourly_rate, sets weekly_salary to that product, as well as returns the product

Calc_Vacation_Days takes the mod of hours_worked % 120 to offer 1 day of vacation for every 120 hours worked. It then sets vacation_days to the calculated value, and returns the value

Calc_Health_Insurance multiplies the weekly salary by 0.20 in order to use 20% of the employee's income for their health insurance contribution. this value is stored in health_insurance and returned by the function.

Nonprofessional, a derived class, utilizes these functions as they are given, and its constructor takes in string n, int hw, float hr, correlating with name, hours_worked, and hourly_rate in that order. An instance of this class is created with the values "Isa", 30, 18.00 ![p6](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/baa39441-3510-44f4-894b-d07a2eb53f68)

Professional is a derived class from Employee that requires modifications to the given functions, and functions Calc_Weekly_Salary() and Calc_Health_Insurance() are overrided to meet the class's needs. 

Professional::Calc_Weekly Salary divides monthly salary by 4, calculated the weekly salary assuming that a month has 4 weeks. it assigns weekly_salary to this value and returns it.

Professional::Calc_Health_Insurance() multiplies the weekly_salary by .25, assuming professional employees ought to pay more for their insurance contribution because there would be more benefits. This product is assigned to health_insurance and is returned. 

The Professional constructor takes in string n, int hw, float mr, assigning these to name, hours_worked, and monthly_salary respectively. An instance of this class is created with the values "Bella", 45, 4500 ![p7](https://github.com/IsaOrtiz08/cs303_assignment2/assets/113536391/6e078855-544f-4009-b728-14c0f4c0013e)
