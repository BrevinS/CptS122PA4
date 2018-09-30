#include "ExercisePlan.h"    

//Default Contructor
ExercisePlan::ExercisePlan()
{
	mGoalSteps = 0;
	mExerDate = "";
	mExerName = "";
}

ExercisePlan::ExercisePlan(int goalSteps, string exerciseName, string exerciseDate)
{
	goalSteps = mGoalSteps;
	exerciseName = mExerName;
	exerciseDate = mExerDate;
}

ExercisePlan::ExercisePlan(ExercisePlan &copyExerPlan)
{
	mGoalSteps = copyExerPlan.getGoalSteps();
	mExerName = copyExerPlan.getExerName();
	mExerDate = copyExerPlan.getExerDate();
}

//Not Allocated Dynamically, Thus Useless
ExercisePlan::~ExercisePlan() {};

//Getters
int ExercisePlan::getGoalSteps() const
{
	return mGoalSteps;
}

string ExercisePlan::getExerName() const
{
	return mExerName;
}

string ExercisePlan::getExerDate() const
{
	return mExerDate;
}

//Setters
void ExercisePlan::setGoalSteps(int newSteps)
{
	mGoalSteps = newSteps;
}

void ExercisePlan::setExerName(string newExerName)
{
	mExerName = newExerName;
}

void ExercisePlan::setExerDate(string newExerDate)
{
	mExerDate = newExerDate;
}

//Member Function
void ExercisePlan::editExerGoal()
{
	int newGoal;
	cout << "Please enter your new steps goal: " << endl;
	cin >> newGoal;
	cout << "New Goal Processed ->" << newGoal << "<-" << endl;
	setGoalSteps(newGoal);
}

//Filestream Extraction Operator
ostream& operator << (ostream &out, const ExercisePlan &plan) {
	out << plan.getExerName() << endl 
		<< plan.getGoalSteps() << endl 
		<< plan.getExerDate() << endl;
	return out;
}

//Filestream
istream& operator >> (istream &in, ExercisePlan &plan) {
	string str;

	getline(in, str);
	plan.setExerName(str);

	getline(in, str);
	plan.setGoalSteps(stoi(str));

	getline(in, str);
	plan.setExerDate(str);

	in.ignore(sizeof(char), '\n');

	return in;
}