#include "DietPlan.h"

//Default Constructor
DietPlan::DietPlan()
{
	mGoalCalories = 0;
	mDietDate = "";
	mDietName = "";
}

DietPlan::DietPlan(int goalCalories, string dietName, string dietDate)
{
	goalCalories = mGoalCalories;
	dietName = mDietName;
	dietDate = mDietDate;
}

DietPlan::DietPlan(DietPlan &copyDietPlan)
{
	mGoalCalories = copyDietPlan.getGoalCalories();
	mDietName = copyDietPlan.getDietName();
	mDietDate = copyDietPlan.getDietDate();
}

//Not Allocated Dynamically, Thus Useless
DietPlan::~DietPlan() {};

//Getters
int DietPlan::getGoalCalories() const
{
	return mGoalCalories;
}

string DietPlan::getDietName() const
{
	return mDietName;
}

string DietPlan::getDietDate() const
{
	return mDietDate;
}

//Setters
void DietPlan::setGoalCalories(int newCalories)
{
	mGoalCalories = newCalories;
}

void DietPlan::setDietName(string newDietName)
{
	mDietName = newDietName;
}

void DietPlan::setDietDate(string newDietDate)
{
	mDietDate = newDietDate;
}

//Member Function
void DietPlan::editDietGoal()
{
	int newGoal = 0;
	cout << "Please enter your new steps goal: " << endl;
	cin >> newGoal;
	cout << "New Goal Processed ->" << newGoal << "<-" << endl;
	setGoalCalories(newGoal);
}

ostream& operator << (ostream &out, const DietPlan &plan) {
	out << plan.getDietName() << endl
		<< plan.getGoalCalories() << endl
		<< plan.getDietDate() << endl;

	return out;
}

istream& operator >> (istream &in, DietPlan &plan) {
	string data;

	getline(in, data);
	plan.setDietName(data);

	getline(in, data);
	plan.setGoalCalories(stoi(data));

	getline(in, data);
	plan.setDietDate(data);

	in.ignore(sizeof(char), '\n');

	return in;
}