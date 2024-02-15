/*
* FILE: m2.cpp
* PROJECT: SENG1000 - Major Assignment 2
* PROGRAMMER: Virajsinh Dharmendrasinh Solanki
* FIRST VERSION: 2024-02-6
* student id: 8981864
* DESCRIPTION: This program is used to create a menu which
*			   is used to get the base and exponent from the
*			   user and the program can even display the output
*			   depending upon the users choice.
*/

#include <stdio.h>
int getNum(void);
int powerCalculation(int, int);
int numberRangeChecker(int, int, int);
// the above are prototypes  for all the functions
int main() {
	int i = 0;
	int userChoics = 0;
	int v = 1;
	int exponent = 1;
	int base = 1;
	// all the variables intialised above
	while (i < v) { //loop for menu and its functions
		printf("\n\n"); // to leave space between menus
		printf("Menu: \n");
		printf("1. Change base\n");
		printf("2. Change exponent\n");
		printf("3. Display base raised to exponent\n");
		printf("4. Exit program\n");
		printf("Option? "); // all the options user can choose
		userChoics = getNum();
		switch (userChoics) {
		case 1: {
			// first option for the user to input base
			printf("Enter new base: ");
			base = getNum();
			int baseRange = numberRangeChecker(1, base, 30);
			//checks base range
			if (baseRange == 0){
				/* if the base is out of range base will become
				1 and the ouput will say its invalid*/
				base = 1;
				printf("Invalid base. Please enter a number between 1 and 30.\n");
			}
			break;
		}
		case 2: {
			// second option for the user to input base
			printf("Enter new exponent: ");
			exponent = getNum();
			int exponentRange = numberRangeChecker(1, exponent, 6);
			if (exponentRange == 0) {
				/* if the exponent is out of range it will become
				1 and the ouput will say its invalid*/
				exponent = 1;
				printf("Invalid exponent. Please enter a number between 1 and 6.\n");
			}
			break;
		}
		case 3: {
			int finalOutput = powerCalculation(base, exponent);
			// to display the base raised to the power
			printf("%d raised to the power of %d is %d.\n", base, exponent, finalOutput);
			break;
		}

		case 4: {
			i = v;
			break;
			// this will null the loop condition of i<v and break the loop
		}
		default: {
			printf("Invalid entry\n");
			break;
		}
			   v++;
		}

	}
}
/*
* FUNCTION : powerCalculation
*
* DESCRIPTION : These Function is used to raise the power of the base
				to the expomnent provided by the user and as we cannot
				use math function a loop is used to multiply the value and
				get the final answer.

* PARAMETERS : base: to get the base from the user and raise it to the exponent.
*			   exponent: to get the exponent from user which the base needs to
*			   be raised to.
*
* RETURNS :    answer: will return the base raised to the exponent.
*/
int powerCalculation(int base, int exponent) {
	int i = 0;
	int answer = 1;
	for (i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}
/*
* FUNCTION : numberRangeChecker
*
* DESCRIPTION : These function will be called 2 times and is used to check
				the value of the base and the exponent to make sure that
				the base stays between 1 to 30 and the value of the exponent
				stays between 1 to 6 according to SET Requirements.
*
  PARAMETERS :  Min: the minimum value of exponent and base.
*			    MAX: the maximum value of exponent and base.
*			    BEValue: Value of base and the exponent to check the range.
*
* RETURNS :  returns 0 if it is out of range.
*			 returns 1 if is inside the range.
*/
int numberRangeChecker(int min, int bEValue, int max) {

	if (min <= bEValue && bEValue <= max) {
		return 1;
	}
	else {
		return 0;
	}
}
#pragma warning(disable: 4996)	
int getNum(void) {
	/* we will see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: indent and brace this function consistent with
	your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1) {
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}
