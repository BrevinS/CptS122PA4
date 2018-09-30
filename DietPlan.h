#pragma once
#include "header.h"

class DietPlan
{
public:
	//default constructor
	DietPlan();
	DietPlan(int goalCalories, string dietName, string dietDate);
	//copy contructor
	DietPlan(DietPlan &copyDietPlan);
	~DietPlan(); //destructor

	//Getters
	int getGoalCalories() const;
	string getDietName() const;
	string getDietDate() const;

	//Setters
	void setGoalCalories(int newCalories);
	void setDietName(string newDietName);
	void setDietDate(string newDietDate);

	//Edit Goal (Member Function)
	void editDietGoal();

private:
	//maximum intake of calories for a day is stored in the goal calories
	int mGoalCalories;
	string mDietName;
	string mDietDate;
};

//Filestream Extraction Operator
ostream& operator << (ostream &out, const DietPlan &plan);

istream& operator >> (istream &in, DietPlan &plan);