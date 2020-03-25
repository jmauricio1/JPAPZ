#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

const int size = 100;

void bubSort(int size, int array[])
{
    clock_t startTime = clock();
    int counter = 0;
    int pocket; // going to store temporary variable
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            counter++;
            if(array[j] > array[j+1])
            {
                pocket = array[j+1];
                array[j+1] = array[j];
                array[j] = pocket;
            }
        }
        for (int i = 0; i < size;i++) // this for loop allows me to see the sort in action line by line
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    clock_t endTime = clock();
    cout << endl << "The counter is: " << counter << endl;
    cout << "The execution time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

void seleSort(int size, int array[])
{
    //create a variable that holds the index value and elemental value
    clock_t startTime = clock();
    int counter = 0;
    int finder;
    int value;
    for (int i = 0; i < size; i++)
    {
        finder = i; // assigning variable to the index in order to call it
        value  = array[i];
        for (int j = i; j < size; j++)
        {
            counter++;
            if(array[j] < value)
            {
                finder = j;
                value = array[j];
            }
        }

        swap (array[i], array[finder]);

        for (int i = 0; i < size;i++) // this for loop allows me to see the sort in action line by line
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    clock_t endTime = clock();
    cout << endl << "The counter is: " << counter << endl;
    cout << "The execution time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

void insSort(int size, int array[])
{
    clock_t startTime = clock();
    int counter = 0;
    int pocket;
    for (int i = 1; i < size; i++)
    {
        for(int j = i; j > 0; j--)
        {
            counter++;
            if(array[j] < array[j-1])
            {
               pocket = array[j-1];
               array[j-1] = array[j];
               array[j] = pocket;
            }
        }
        for (int i = 0; i < size;i++) // this for loop allows me to see the sort in action line by line
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    clock_t endTime = clock();
    cout << endl << "The counter is: " << counter << endl;
    cout << "The execution time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

int linearSearch(int length, int array[], int value, int counter = 0)
{

    for(int i = 0; i < length; i++)
    {
        counter++;
        if(value == array[i])
        {
             return i;
             return counter;
        }
    }
        return -1;
}

int binarySearch(int array[], int value, int firstHalf, int secondHalf, int counter = 0)
{

    while(firstHalf <= secondHalf)
    {
        counter++;
        int middle = (firstHalf + secondHalf) / 2;

        counter++;
        if(array[middle] == value)
        {
            return middle;
        }

        else if(array[middle] > value)
        {
            secondHalf = middle - 1;
        }
        else
        {
            firstHalf = middle + 1;
        }
    }
    return counter;
}

int main()
{
    srand(time(0));
////////////////////////////////////////////////////////////////////////////////
    int array[size];
    cout << "The numbers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100000; //random numbers from 0 to 99999
        cout << array[i] << " ";
    }
//    cout << endl << endl << "Bubble Sort: " << endl;
//    cout << endl;
//    bubSort(size,array);
//    cout << endl;

//    cout << endl << endl << "Selection Sort: " << endl;
//    cout << endl;
//    seleSort(size,array);
//    cout << endl;

//    cout << endl << endl << "Insertion Sort: " << endl;
//    cout << endl;
//    insSort(size,array);
//    cout << endl;
///////////////////////////////////////////////////////////////////////////
clock_t startTime = clock();
    int linearCounter;
    int keyNum;
        cout << endl << "Enter an integer from the list above: ";
        cin >> keyNum;

    int result = linearSearch(size, array, keyNum, linearCounter);
        if(result >= 0)
        {
            cout << "The element " << array[result]
                 << " was found at index " << result << endl;

            cout << "The linear counter is: "
                 << linearCounter << endl;
        }
        else
        {
            cout << "Dunno where it is bruh " << endl;
        }
clock_t endTime = clock();
   cout << "The execution time for the linear search: "
        << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
   cout << endl;
////////////////////////////////////////////////////////////////////////
clock_t startTime1 = clock();
   int binaryCounter = 0;
   int numWanted;
        cout << "Select the number you want: ";
        cin >> numWanted;

   int result1 = binarySearch(array,numWanted,0, size - 1, binaryCounter);
        if(result1 < 0)
        {
            cout << "Number " << binaryCounter
                 << " ain't on the list " << endl;
        }
        else
        {
            cout << "The element is: " << array[result1]
                 << " at index: " << result1 << endl;
            cout << "The counter for binary search is: "
                 << binaryCounter << endl;
        }
clock_t endTime1 = clock();
   cout << "The execution time for binary search: "
        << (double) (endTime1 - startTime1) / CLOCKS_PER_SEC << endl;
}
