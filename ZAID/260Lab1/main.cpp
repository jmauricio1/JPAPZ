#include <iostream>
#include <ctime>  // time
#include <stdlib.h> // srand, rand
/**
 *Name : Zeed Alsuwayyigh
 * Date : 1/27/2019
 * Lab1
 * Data Structure
 */

using namespace std;
 const int length = 10;


void bubbleSort(int arr[], int size){

    int holder; // to hold the element that will be swapped.
    int i, j;
    int counter = 0;
    clock_t startTime = clock(); // a method to  start counting the execution time for this function.

    for(i = 0; i < size; i++){

        for(j = 0; j < size - 1; j++){

            counter++; // to count how many times it lopped.
            if(arr[j] > arr[j + 1]){
                holder = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = holder;
            }


        }



    }

    for(int a = 0; a < size; a++){
        cout << arr[a] << "  ";

    }
         cout << endl;
    clock_t endTime = clock(); // the ending time for the execution.

    cout << " the counter is: " << counter << endl;

    cout << "the execution time for the bubble sort is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;


//    for(int a = 0; a < size; a++){
//        cout << arr[a] << "  ";
//    }

    cout << endl;

}


void insertionSort(int arr[], int size){

    int counter = 0;

    clock_t startTime = clock();
    int holder;
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0; j--){

             counter++;
            if(arr[j] < arr[j - 1]){
                holder = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = holder;
            }
            for(int a = 0; a < size; a++){
                cout << arr[a] << "  ";

            }
            cout << endl;
        }
    }
//    for(int a = 0; a < size; a++){
//        cout << arr[a] << "  ";

//    }
//    cout << endl;

    clock_t endTime = clock();

    cout << " the counter is: " << counter << endl;
    cout << "the execution time for the Insertion sort is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

}

void selectionSort(int arr[], int size){

     clock_t startTime = clock();
    int counter = 0;
    for(int i = 0; i < size; i++){

        int minValue = arr[i];
        int indexValue = i;

        for(int j = i; j < size; j++){
            counter++;
            if(arr[j] < minValue){
                minValue = arr[j];
                indexValue = j;
            }

        }

        swap(arr[i], arr[indexValue]);



//        cout << endl;
    }

    for(int a = 0; a < size; a++){

        cout << arr[a] << " ";
    }
    cout << endl;
    clock_t endTime = clock();

    cout << " the counter is: " << counter << endl;
    cout << "the execution time for the Selection sort is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;
}

int linearSearch(int array[],  int size, int searchValue, int counter){

    counter = 0;
    for(int i = 0; i < size; i++){

        counter++;
        if(searchValue == array[i]){

            return i;
            return counter;
        }


    }
    return -1;

}





int binarySearch(int arr[], int searchedValue, int left, int right, int counter = 0){

   // counter = 0;

    while(left <= right){


        counter++;

        int mid = (left + right) / 2;

        counter++;
        if(arr[mid] == searchedValue){
            return mid;
            //return  counter;
        }

        else if(arr[mid] > searchedValue){

            right = mid - 1;
        }

        else{

            left = mid + 1;
        }

         //counter++;
        //return counter;

    }
  return counter;

   // return -1;


}



int main()
{

    srand(time(0));
    int myArray[length];
    cout << "Random values are: ";
    for(int i = 0; i < length; i++){

        myArray[i] = rand() % 100000;

        cout << myArray[i] << " ";
    }
    cout << endl;

    cout << "bubble Sort:    ";

    bubbleSort(myArray,length);

    cout << " ------------------------------------------------------- " << endl;

    cout << "Insertion Sort: ";
    insertionSort(myArray,length);

     cout << " ------------------------------------------------------- " << endl;
    cout << "Selection Sort: ";
    selectionSort(myArray,length);

      cout << " ------------------------------------------------------- " << endl;
    clock_t startTime = clock();
    int linearCounter;
    int keyNum;
    cout << "Enter an integer: ";
    cin >> keyNum;

  int result = linearSearch(myArray,length, keyNum, linearCounter);

  if(result >= 0){
      cout << "the element " << myArray[result] << " is found at index " << result << endl;
      cout << "the linear counter is: " << linearCounter << endl;

  }
  else{
      cout << "not found" << endl;
}
clock_t endTime = clock();


cout << "the execution time for linear search: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << endl;

cout << "--------------------------------------------------" << endl;
clock_t startTime1 = clock();
int binaryCounter = 0;
int numWanted;
cout << " enter the number you're looking for: ";
cin >> numWanted;

int result1 = binarySearch(myArray,numWanted,0, length - 1, binaryCounter);
if(result1 < 0){
    cout << "number " << binaryCounter << " is not found in the list" << endl;
}

else{

    cout << "the element is: " << myArray[result1] << " at index: " << result1 << endl;
    cout << "the counter for binary search is: " << binaryCounter << endl;

}
clock_t endTime1 = clock();

//cout << "the elemnt is: " << myArray[result1] << " at index: " << result1 << endl;
cout << "the execution time for binary search: " << (double) (endTime1 - startTime1) / CLOCKS_PER_SEC << endl;
//cout << "the counter for binary search is: " << binaryCounter << endl;
}

