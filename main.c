#include <stdio.h>
#include <string.h>
#include "time.h"
#include <time.h>
#include <ctype.h>

/* Function declarations: */

int chooseProgram(char * str);
void clockApp();
void calculateAge();
void startApp();
void endApp();
struct tm getCurrentDateTime();
int getBirthMonth();
int getMonthNumber(char * str);
int getBirthDay(int monthNo);
int getBirthYear(int currentYear);

//---------------------------
//
// Main Methods
//
//---------------------------

int main() {
	printf("Welcome to the C HelloBot Project!\n\n");

	char name[30];
	printf("Enter your name: ");
	gets(name, 30, stdin);
	printf("Hello, %s.\n\n", name);

	int state = 1;
	while (state)
	{
		char command[5];
		printf("Enter '1' for Clock, '2' to Calculate Age, or\n");
		printf("enter 'end' to terminate: ");
		fgets(command, 5, stdin);

		state = chooseProgram(command);
	}
	
	return 0;
}

// selects program to be run
int chooseProgram(char * str) 
{
	char * endstr = "end" + '\0';
	int retVal = 1;

	if (strlen(str) == 2)
	{
		if (strncmp(str, "1", 1) == 0)
		{
			clockApp();
		}
		else if (strncmp(str, "2", 1) == 0)
		{
			calculateAge();
		}
		else 
		{
			printf("\nInvalid.\n\n");
		}
	}
	else if (strlen(str) == 4)
	{
		if (strncmp(str, endstr, 3) != 0)
		{
			printf("\nInvalid.\n\n");
		}
		else
		{
			printf("\nUser ended process.");
			retVal = 0;
		}
	}
	else
	{
		printf("\nInvalid.\n\n");
	}

	return retVal;
}

//---------------------------
//
// Clock App
//
//---------------------------

void clockApp()
{
	startApp();

	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	struct tm current = getCurrentDateTime();
	printf("The current time is %d:%d:%d\n", (int)current.tm_hour, (int)current.tm_min, (int)current.tm_sec);

	endApp();
}

//---------------------------
//
// Calculate Age App
//
//---------------------------

void calculateAge()
{
	startApp();

	// get current d/t below:
	struct tm ltm = getCurrentDateTime();
	int currentYear = 1900 + ltm.tm_year;
	int currentMonth = 1 + ltm.tm_mon;
	int currentDay = ltm.tm_mday;
	////
	////logging
	//printf("year: %d, month: %d, day: %d\n", currentYear, currentMonth, currentDay);
	////

	// get users birthdate:
	int birthMonth;
	birthMonth = getBirthMonth();
	////
	//logging
	//printf("month num: %d\n", birthMonth);
	////

	int birthDay;
	birthDay = getBirthDay(birthMonth);
	////
	//logging
	//printf("day num: %d\n", birthDay);
	////

	int birthYear;
	birthYear = getBirthYear(currentYear);
	////
	//logging
	//printf("year num: %d\n", birthYear);
	////

	//int alreadyHadBirthday = 0;
	int age = 0;
	if (currentMonth > birthMonth ||
		(currentMonth == birthMonth && currentDay >= birthDay))
	{
		//alreadyHadBirthday = 1;
		age = currentYear - birthYear;
	}
	else
	{
		age = currentYear - birthYear - 1;
	}

	printf("You are %d years old.\n", age);

	endApp();
}

int getBirthMonth()
{
	int birthMonth = 0;
	char input[5];

	while (1)
	{
		printf("Enter the number of your birth month: ");
		fgets(input, 5, stdin);
		//printf("%s", input);

		birthMonth = getMonthNumber(input);
		//printf("number is: %d\n", birthMonth);

		if (birthMonth != 0)
		{
			break;
		}
	}
	
	return birthMonth;
}

int getMonthNumber(char * str)
{
	////
	//logging
	//printf("looking for month number %s\n", str);
	////

	if (strlen(str) == 2)
	{
		if (strncmp(str, "1", 1) == 0)
		{
			return 1;
		}
		else if (strncmp(str, "2", 1) == 0)
		{
			return 2;
		}
		else if (strncmp(str, "3", 1) == 0)
		{
			return 3;
		}
		else if (strncmp(str, "4", 1) == 0)
		{
			return 4;
		}
		else if (strncmp(str, "5", 1) == 0)
		{
			return 5;
		}
		else if (strncmp(str, "6", 1) == 0)
		{
			return 6;
		}
		else if (strncmp(str, "7", 1) == 0)
		{
			return 7;
		}
		else if (strncmp(str, "8", 1) == 0)
		{
			return 8;
		}
		else if (strncmp(str, "9", 1) == 0)
		{
			return 9;
		}
		else
		{
			//printf("\nInvalid.\n\n");
			return 0;
		}
	}
	else if (strlen(str) == 3)
	{
		if (strncmp(str, "10", 2) == 0)
		{
			return 10;
		}
		else if (strncmp(str, "11", 2) == 0)
		{
			return 11;
		}
		else if (strncmp(str, "12", 2) == 0)
		{
			return 12;
		}
		else
		{
			//printf("\nInvalid.\n\n");
			return 0;
		}
	}
	else
	{
		//printf("\nInvalid.\n\n");
		return 0;
	}
}

int getBirthDay(int monthNo)
{
	int birthDay = 0;
	int maxDays = 31;

	// setup: find max days in month
	if (monthNo == 2)
	{
		maxDays = 28;
	}
	else if ((monthNo == 4) || (monthNo == 6) || (monthNo == 9) || (monthNo == 11))
	{
		maxDays = 30;
	}

	while (birthDay == 0)
	{
		printf("Enter the day of the month: ");

		scanf("%d", &birthDay);
		// flushes the standard input 
    // (clears the input buffer) 
		while ((getchar()) != '\n');
		////
		//logging
		//printf("%d\n", birthDay);
		////

		if (birthDay > maxDays)
		{
			birthDay = 0;
		}
	}

	return birthDay;
}

int getBirthYear(int currentYear)
{
	int year = 0;

	while (year == 0)
	{
		printf("Enter your birth year: ");

		scanf("%d", &year);
		// flushes the standard input 
	// (clears the input buffer) 
		while ((getchar()) != '\n');
		////
		//logging
		//printf("%d\n", year);
		////

		if (year > currentYear)
		{
			year = 0;
		}
	}

	return year;
}



//---------------------------
//
// Shared Methods
//
//---------------------------

struct tm getCurrentDateTime()
{
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	return *tm;
}

char charToLower(char c)
{
	printf("changing char %d", c);
	return (c <= 'Z' && c >= 'A') ? c + 32 : c;
}

void startApp()
{
	printf("\n--------------------------------\n");
}

void endApp()
{
	printf("--------------------------------\n\n");
}
