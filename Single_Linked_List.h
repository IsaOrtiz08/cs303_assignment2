#pragma once
#include <string>
using namespace std;
	template <typename Item_Type>
	class Single_Linked_List {
	private:
		struct Node {
			Item_Type data;
			Node* next = nullptr;
			Node(const Item_Type& val) : data(val), next(nullptr) {}
		};
		int num_items=0;
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		void push_front(Item_Type val);
		void push_back(Item_Type val);
		void pop_front();
		void pop_back();
		Item_Type front();
		Item_Type back();
		bool empty();
		void insert(size_t index, const Item_Type& item);
		bool remove(size_t index);
		size_t find(const Item_Type& item);
		void print();
	};

	class Employee {
	public:
		std::string name;
		float hourly_rate;
		int hours_worked;
		float weekly_salary = 0.0;
		int vacation_days = 0;
		float health_insurance = 0.0;
		virtual float Calc_Weekly_Salary();
		virtual int Calc_Vacation_Days();
		virtual float Calc_Health_Insurance();
		virtual void print();
	};

	class Professional : public Employee {
	public:
		float monthly_salary;
		float Calc_Weekly_Salary();
		float Calc_Health_Insurance();
		Professional(std::string n, int hw, float mr);
		void print();
	};

	class Nonprofessional : public Employee {
	public:
		Nonprofessional(std::string n, int hw, float hr);
	};