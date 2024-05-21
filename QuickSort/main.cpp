#include <iostream>

#include "QuickSort.h"

//Clear input function
void ClearInput();

//Enter to continue function
void EnterContinue();

int main()
{
	int iSortingOrder = 0; //variable to hold value to determine if list will be sorted ascending or descending
	int iElementNumber = 0; //variable to hold value for how many data elements to be sorted
	int iElements = 0; //variable to hold input values for data elements

	std::cout << std::endl << "Enter 0 for ascending order sorting; or enter 1 for descending order sorting: ";
	std::cin >> iSortingOrder;

	if (iSortingOrder < 0 || iSortingOrder > 1) //Check if input is != 0 or 1. Exit program is true
	{
		std::cin.ignore();
		std::cout << std::endl << "Number entered was not 0 or 1. Exiting program." << std::endl;
		EnterContinue();
	}
	if (std::cin.fail()) //Check if input is character. Exit program is true
	{
		ClearInput();
		std::cout << std::endl << "Entered a character instead of 0 or 1. Exiting program." << std::endl;
		EnterContinue();
	}

	std::cout << std::endl;
	std::cout << "Enter number of data elements for sorting (non-negative): ";
	std::cin >> iElementNumber;

	while (iElementNumber < 0 || std::cin.fail())
	{
		if (iElementNumber < 0) //Check if input is negative. Exit program if true
		{
			std::cout << "Entered number was negative. Enter a positive integer: ";
			std::cin >> iElementNumber;
		}
		if (std::cin.fail()) //Check if input is character. Exit program if true
		{
			ClearInput();
			std::cout << "Entered a character instead of an integer. Try again: ";
			std::cin >> iElementNumber;
		}
	}
	if (iElementNumber == 0) //if user enters 0, then nothing to sort, so report and end program
	{
		std::cout << std::endl << "No data elements to sort. Exiting program." << std::endl;
		ClearInput();
		EnterContinue();
	}

	int *arrayToSort = new int[iElementNumber] (); //create dynamic array to store elements and initialise all elements to 0
	std::cout << std::endl;
	
	std::cout << "Enter " << iElementNumber << " data elements (integers), separated by spaces: "; 
	ClearInput();
	
	for (int i = 0; i < iElementNumber; i++) //read input and place into array
	{
		std::cin >> arrayToSort[i];
		if ((std::cin.get() == '\n') && (i != iElementNumber-1)) //check if user did not enter enough numbers, if true, then exits
		{
			std::cout << std::endl << "You did not enter enough data elements. Exiting program" << std::endl;
			EnterContinue();
		}
	}
	std::cout << std::endl;
	while (std::cin.fail()) //check if user does not enter a number
	{
		ClearInput();
		std::cout << "Please only enter integers." << std::endl;
		std::cout << "Enter " << iElementNumber << " data elements (integers), separated by spaces: ";
		for (int i = 0; i < iElementNumber; i++) //read input and place into array
		{
			std::cin >> arrayToSort[i];
			if ((std::cin.get() == '\n') && (i != iElementNumber - 1)) //check if user did not enter enough numbers, if true, then exits
			{
				std::cout << std::endl << "You did not enter enough data elements. Exiting program" << std::endl;
				EnterContinue();
			}
		}
	}
	
	CQuickSort::quickSort(arrayToSort, 0, iElementNumber-1, iSortingOrder); //run quicksort function

	if (iSortingOrder == 0)
	{
		std::cout << "The above entered numbers have been sorted by Quicksort in ascending order." << std::endl;
	}
	else
	{
		std::cout << "The above entered numbers have been sorted by Quicksort in descending order." << std::endl;
	}

	CQuickSort::printArray(arrayToSort, iElementNumber-1); //print sorted array

	EnterContinue();
	
}

void ClearInput() //Clear input function
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

void EnterContinue() //Enter to exit function
{
	std::cout << std::endl;
	std::cout << "Press any key to exit.";
	std::cin.ignore();
	system("CLS");
	exit(0);
} 