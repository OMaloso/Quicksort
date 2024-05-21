

class CQuickSort
{
public:

	static void swap(int& _iFirstVariable, int& _iSecondVariable); //function to swap two integers

	static void printArray(int _iArray[], int _iArraySize); //function to print array from left to right

	static int partition(int _iArray[], int _iFirstArrayNumber, int _iLastArrayNumber, int _iSortDirection); //partition function, putting all number <= pivot to left, higher to right

	static void quickSort(int _iArray[], int _iFirstArrayNumber, int _iLastArrayNumber, int _iSortDirection); //quicksort function, calls on partition, then recurses

};