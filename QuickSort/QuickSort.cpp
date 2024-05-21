#include <iostream>
#include "QuickSort.h"


void CQuickSort::swap(int& _iFirstVariable, int& _iSecondVariable) //function to swap two integers
{
	if (_iFirstVariable != _iSecondVariable) //no point swapping if they are the same
	{
		int iTemp = _iFirstVariable;
		_iFirstVariable = _iSecondVariable;
		_iSecondVariable = iTemp;
	}
}

void CQuickSort::printArray(int _iArray[], int _iArraySize) //function to print array from left to right
{
	for (int i = 0; i < _iArraySize + 1; i++)
	{
		std::cout << _iArray[i] << " ";
	}
	std::cout << std::endl;
}

int CQuickSort::partition(int _iArray[], int _iFirstArrayNumber, int _iLastArrayNumber, int _iSortDirection) //partition function, putting all number <= pivot to left, higher to right
{
	int iPivot = _iArray[_iFirstArrayNumber]; //pivot is first number
	int iUpCounter = _iFirstArrayNumber + 1;  //array slot one after pivot
	int iDownCounter = _iLastArrayNumber; //last array slot. -1 because _iLastArrayNumber doesn't include 0 when created by user

	if (_iSortDirection == 0) //ascending order sorting
	{
		while (iUpCounter < iDownCounter)
		{
			// move up from the start and find the first number greater or equal to the pivot
			while ((iUpCounter < iDownCounter) && (_iArray[iUpCounter] <= iPivot)) 
			{
				iUpCounter++;
			}
			// if above found, then move from the end and find the first number less than or equal to the pivot
			if (iUpCounter < iDownCounter)
			{
				while ((iUpCounter < iDownCounter) && (_iArray[iDownCounter] > iPivot)) 
				{
					iDownCounter--;
				}
				if (iUpCounter < iDownCounter) //swap two numbers
				{
					CQuickSort::swap(_iArray[iUpCounter], _iArray[iDownCounter]);
				}
			}
		}
		//swap pivot with down counter
		if ((iUpCounter == _iLastArrayNumber) && (_iArray[iUpCounter] < iPivot)) //check if upcounter reached the last number of array, then downcounter is equal to last number in array
		{
			if (iDownCounter != 0)
			{
				CQuickSort::swap(_iArray[iDownCounter], _iArray[_iFirstArrayNumber]);  //swap two downcounter with pivot
			}
		}
		else //otherwise, downcounter is one number below upcounter
		{
			while ((iDownCounter > 0) && (iDownCounter >= iUpCounter)) //move downcounter one below upcounter
			{
				iDownCounter--;
			}
			if ((iDownCounter != 0) && (_iArray[iDownCounter] != iPivot)) //make sure pivot isn't swapped with itself
			{
				CQuickSort::swap(_iArray[iDownCounter], _iArray[_iFirstArrayNumber]); //swap downcounter with pivot
			}
		}
		return iDownCounter;
	}
	else //descending order sorting
	{
		while (iUpCounter < iDownCounter)
		{
			// move up from the start and find the first number less than the pivot
			while ((iUpCounter < iDownCounter) && (_iArray[iUpCounter] > iPivot)) 
			{
				iUpCounter++;
			}
			// if above found, then move from the end and find the first number larger than or equal to the pivot
			if (iUpCounter < iDownCounter)
			{
				while ((iUpCounter < iDownCounter) && (_iArray[iDownCounter] <= iPivot))
				{
					iDownCounter--;
				}
				if (iUpCounter < iDownCounter) //swap upcounter with downcounter
				{
					CQuickSort::swap(_iArray[iUpCounter], _iArray[iDownCounter]);
				}
			}
		}
		//swap pivot with down counter
		if ((iUpCounter == _iLastArrayNumber) && (_iArray[iUpCounter] > iPivot)) //check if upcounter reached the last number of array, then downcounter is equal to last number in array
		{
			if (iDownCounter != 0)
			{
				CQuickSort::swap(_iArray[iDownCounter], _iArray[_iFirstArrayNumber]); //swap downcounter with pivot
			}
		}
		else //otherwise, downcounter is one number below upcounter
		{
			while ((iDownCounter > 0) && (iDownCounter >= iUpCounter))  //make sure pivot isn't swapped with itself
			{
				iDownCounter--;
			}
			if ((iDownCounter != 0) && (_iArray[iDownCounter] != iPivot))
			{
				CQuickSort::swap(_iArray[iDownCounter], _iArray[_iFirstArrayNumber]); //swap downcounter with pivot
			}
		}
		return iDownCounter;
	}

}

void CQuickSort::quickSort(int _iArray[], int _iFirstArrayNumber, int _iLastArrayNumber, int _iSortDirection) //quicksort function, calls on partition, then recurses
{
	int iPartition = CQuickSort::partition(_iArray, _iFirstArrayNumber, _iLastArrayNumber, _iSortDirection); //get first partition placement, ie, where in the array does the first pivot end up

	if (iPartition - _iFirstArrayNumber > 1) 
	{
		CQuickSort::quickSort(_iArray, _iFirstArrayNumber, iPartition - 1, _iSortDirection); //partition everything left of iPartition
	}
	
	if ((_iLastArrayNumber - iPartition) > 0)     
	{
		CQuickSort::quickSort(_iArray, iPartition + 1, _iLastArrayNumber, _iSortDirection); //partition everything right of iPartition
	}
	
	return;
}