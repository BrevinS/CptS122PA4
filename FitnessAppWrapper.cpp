//Programmer: Brevin Simon
//Class: CptS 122, Summer 2018
//Programming Assignment: PA 4
//Date: July 4th, 2018 'Murica
//Help From: Andy Code From BankManager.zip and Lecture Code
//Also Help Managing C++ From http://www.cplusplus.com/doc/tutorial/files/
#include "FitnessAppWrapper.h"
#define ZIP 0
int main(void) {
	runApp();
}

void runApp()
{
	DietPlan *dietPlan = new DietPlan[7];
	ExercisePlan *exercisePlan = new ExercisePlan[7];
	fstream outdiet, outexer;
	outdiet.open("dietPlans.txt");
	outexer.open("exercisePlans.txt");

	int menuOption = 0, day;
	do {
		menuOption = displayMenu();
		switch (menuOption) {
		case 1:
			loadWeeklyPlan(outdiet, &dietPlan);
			break;
		case 2:
			loadWeeklyPlan(outexer, &exercisePlan);
			break;
		case 3:
			storeWeeklyPlan(dietPlan);
			break;
		case 4:
			storeWeeklyPlan(exercisePlan);
			break;
		case 5:
			displayWeeklyPlan(dietPlan);
			break;
		case 6:
			displayWeeklyPlan(exercisePlan);
			break;
		case 7:
			printCurrWeek();

			cout << "What day would you like to edit?" << endl;
			cin >> day;

			dietPlan[day - 1].editDietGoal();
			break;
		case 8:
			printCurrWeek();

			cout << "What day would you like to edit?" << endl;
			cin >> day;
			exercisePlan[day - 1].editExerGoal();
			break;
		case 9:
			if (dietPlan[ZIP].getDietName() != "") {
				storeWeeklyPlan(dietPlan);
			}
			if (exercisePlan[ZIP].getExerName() != "") {
				storeWeeklyPlan(exercisePlan);
			}

			outdiet.close();
			outexer.close();
		}
	} while (menuOption != 9);
}

//Load Day For Deit Plan
void loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

//Load Day For Exercise Plan
void loadDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

//Load Whole Week For Diet Plan
void loadWeeklyPlan(fstream &fileStream, DietPlan *weeklyPlan[])
{
	DietPlan dietTemp;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, dietTemp);
		(*weeklyPlan)[i] = dietTemp;
	}
}

//Load Whole Week For Exercise Plan
void loadWeeklyPlan(fstream &fileStream, ExercisePlan *weeklyPlan[])
{
	ExercisePlan exerciseTemp;
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, exerciseTemp);
		(*weeklyPlan)[i] = exerciseTemp;
	}
}

//Display Whole Week
void displayWeeklyPlan(DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

//Display Whole Week
void displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(weeklyPlan[i]);
	}
}

//Display DailyPlan
void displayDailyPlan(DietPlan plan)
{
	//Print
	cout << plan << endl;
}

//Display Exervise Plan
void displayDailyPlan(ExercisePlan plan)
{
	//Print
	cout << plan << endl;
}

//Store Plan To Stream
void storeDailyPlan(fstream &fileStream, DietPlan plan)
{
	//Store into stream
	fileStream << plan << endl;
}

//Store Other Plan To Stream
void storeDailyPlan(fstream &fileStream, ExercisePlan plan)
{
	//Store into stream
	fileStream << plan << endl;
}

//Store The Whole Week
void storeWeeklyPlan(DietPlan weeklyPlan[])
{
	fstream outDiet;
	outDiet.open("dietPlans.txt");

	for (int i = 0; i < 7; i++) {
		storeDailyPlan(outDiet, weeklyPlan[i]);
	}

	//Close
	outDiet.close();
}

//Store The Whole Week
void storeWeeklyPlan(ExercisePlan weeklyPlan[])
{
	fstream outExer;
	outExer.open("exercisePlans.txt");

	for (int i = 0; i < 7; i++) {
		storeDailyPlan(outExer, weeklyPlan[i]);
	}

	//Close
	outExer.close();
}

//I try to make all my menus look different
void printCurrWeek()
{
	cout << "--------CURRENT WEEK EDIT MENU--------" << endl;
	cout << "{1} Thursday" << endl;
	cout << "{2} Friday" << endl;
	cout << "{3} Saturday" << endl;
	cout << "{4} Sunday" << endl;
	cout << "{5} Monday" << endl;
	cout << "{6} Tuesday" << endl;
	cout << "{7} Wednesday" << endl;
}

int displayMenu()
{
	int menuOption = 0;

	cout << "**********MAIN MENU OPTIONS**********" << endl;
	cout << "[1] Load weekly diet plan from file." << endl;
	cout << "[2] Load weekly exercise plan from file." << endl;
	cout << "[3] Store weekly diet plan to file." << endl;
	cout << "[4] Store weekly exercise plan to file." << endl;
	cout << "[5] Display weekly diet plan to screen." << endl;
	cout << "[6] Display weekly exercise plan to screen." << endl;
	cout << "[7] Edit daily diet plan." << endl;
	cout << "[8] Edit daily exercise plan." << endl;
	cout << "[9] Exit." << endl; // Note: this must write the most recent weekly plans to the corresponding files.
	cin >> menuOption;

	return menuOption;
}