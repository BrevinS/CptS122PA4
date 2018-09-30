#pragma once
#include "header.h"

class ExercisePlan
{
public:
	//default constructor
	ExercisePlan();
	ExercisePlan(int goalSteps, string exerciseName, string exerciseDate);
	//copy contructor
	ExercisePlan(ExercisePlan &copyExerPlan);
	~ExercisePlan(); //destructor

					 //Getters
	int getGoalSteps() const;
	string getExerName() const;
	string getExerDate() const;

	//Setters
	void setGoalSteps(int newSteps);
	void setExerName(string newExerName);
	void setExerDate(string newExerDate);

	//Edit Goal (Member Function)
	void editExerGoal();

private:
	//Your goal steps represent the number of desired steps for a day.
	int mGoalSteps;
	string mExerName;
	string mExerDate;
};

//Filestream Extraction Operator
ostream& operator << (ostream &out, const ExercisePlan &plan);

istream& operator >> (istream &in, ExercisePlan &plan);