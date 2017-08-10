#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int bubbleSort(vector<int> &bubSort, int size)
{
	int temp = 0;
	int count = 0;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			count++;
			if (count % (size * 100) == (size * 50)) cout << "\r OoOoOoOoOoOoOoOoOoOoOoOoOoOoO We working oOoOoOoOoOoOoOoOoOoOoOoOoOoOoO";
			else if (count % (size * 100) == (size * 100 - 1)) cout << "\r oOoOoOoOoOoOoOoOoOoOoOoOoOoOo We working OoOoOoOoOoOoOoOoOoOoOoOoOoOoOo";
			// Switch arr[i] and arr[i+] when arr[i] > arr[i+1]
			if (bubSort[j] > bubSort[j + 1]) {
				temp = bubSort[j];
				bubSort[j] = bubSort[j + 1];
				bubSort[j + 1] = temp;
			}
		}
	}
	cout.width(65);
	cout << endl << "Bubble sort count : " << count << endl << endl;
	return count;
}

int bubbleSortAdvanced(vector<int> &bubSort, int size)
{
	int temp = 0;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		bool flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (count % (size*100) == (size*50)) cout << "\r OoOoOoOoOoOoOoOoOoOoOoOoOoOoO We working oOoOoOoOoOoOoOoOoOoOoOoOoOoOoO";
			else if (count % (size * 100) == (size*100 -1 )) cout << "\r oOoOoOoOoOoOoOoOoOoOoOoOoOoOo We working OoOoOoOoOoOoOoOoOoOoOoOoOoOoOo";
			// Switch arr[i] and arr[i+] when arr[i] > arr[i+1], and make flag true(means there is something to switch)
			if (bubSort[j] > bubSort[j + 1])
			{
				count++;
				flag = true;
				int temp = bubSort[j + 1];
				bubSort[j + 1] = bubSort[j];
				bubSort[j] = temp;
			}
		}
		// When there is nothing to switch, finish algorithm
		if (!flag) {
			cout.width(65);
			cout << endl << "Advanced Bubble sort count : " << count << endl << endl;
			return count;
		}
	}

}

void main()
{
	vector<int> bubSort;
	vector<int> bubAdvSort;

	int max = 0;
	int temp = 0;
	int menu = 0;
	int resBubsort = 0;
	int resAdvBubsort = 0;

	// Input bubble sort array's Maximum
	do {
		cout << "Enter Maximum(100~100000) : ";
		cin >> max;
	} while (max < 100 || max>100000);

	do {
		cout << "Do you want to display arr? ( 0. Yes , 1. No)" << endl << "Enter Number : ";
		cin >> menu;
	} while (menu != 0 && menu != 1);

	bubSort.reserve(max);
	bubAdvSort.reserve(max);

	// Set random integers in bubble sort array(=vector)
	srand(time(NULL));
	for (int i = 0; i < max; i++)
	{
		temp = rand() % max;
		bubSort.push_back(temp);
		bubAdvSort.push_back(temp);
	}

	// Display original Array
	if (menu == 0)
	{
		cout << endl << "----------------------------- Original Array ---------------------------" << endl;
		for (int i = 0; i < max; i++)
		{
			cout.width(7);
			cout << bubSort[i];
			if (i % 10 == 9) cout << endl;
		}
	}

	// Display Bubble Sorted Array
	cout << endl << "------------------------------ Bubble Sort -----------------------------" << endl;
	resBubsort = bubbleSort(bubSort, max);
	if (menu == 0)
	{
		for (int i = 0; i < max; i++)
		{
			cout.width(7);
			cout << bubSort[i];
			if (i % 10 == 9) cout << endl;
		}
	}

	// Display Advanced Bubble Sorted Array
	cout << endl << "------------------------- Advanced Bubble Sort -------------------------" << endl;

	resAdvBubsort = bubbleSortAdvanced(bubAdvSort, max);
	if (menu == 0)
	{
		for (int i = 0; i < max; i++)
		{
			cout.width(7);
			cout << bubAdvSort[i];
			if (i % 10 == 9) cout << endl;
		}
	}
	// Display result
	cout << endl << "------------------------- Reulst two algorithms ------------------------" << endl;
	cout << "Origianl Bubble sort count : " << resBubsort << endl;
	cout << "Advanced Bubble sort count : " << resAdvBubsort << endl;
}