#pragma once
#include "DietPlan.h"
#include "ExercisePlan.h"
#include "Header.h"

void runApp();

void loadDailyPlan(fstream &fileStream, DietPlan &plan);

void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);

void loadWeeklyPlan(fstream &fileStream, DietPlan *weeklyPlan[]);

void loadWeeklyPlan(fstream &fileStream, ExercisePlan *weeklyPlan[]);

void displayDailyPlan(DietPlan plan);

void displayDailyPlan(ExercisePlan plan);

void displayWeeklyPlan(DietPlan weeklyPlan[]);

void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

void storeDailyPlan(fstream &fileStream, DietPlan plan);

void storeDailyPlan(fstream &fileStream, ExercisePlan plan);

void storeWeeklyPlan(DietPlan weeklyPlan[]);

void storeWeeklyPlan(ExercisePlan weeklyPlan[]);

void printCurrWeek();

int displayMenu();
