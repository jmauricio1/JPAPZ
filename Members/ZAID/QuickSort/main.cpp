#include <iostream>

using namespace std;

const int size = 8;
bool sortChecker( int arr[], int size){

    // find mid index/

    // if array has one or no element, return true.
    if((size == 1) || (size == 0)){

        return 1;
    }

    if(arr[size - 1] < arr[size - 2]){
        return 0;
    }

    return sortChecker(arr,size - 1);


}

















int partition(int a[],int startIndex,int endIndex)
{
    // assign pivot to last element in the list.
    int pivot=a[endIndex];
    //  create pivot index and place at index = 0;
    int pivotIndex =startIndex;


    int temp; // temp varible to help swapping.

    // for loop to go through the list and swap if needed.
    for(int i=startIndex ;i<endIndex;i++)
    {
        // if element at index i < pivot, swap.
        if(a[i]<=pivot)
        {
            temp=a[i]; // store element at index i in temp.
            a[i]=a[pivotIndex];// store element at pivotIndex in index i.
            a[pivotIndex]=temp; // store the value in temp in pivotIndex.
            pivotIndex++; // increment pivotIndex.
        }
     }

       // when done with loop, do the final swap. swap the value at pivotIndex with pivot.
      temp=a[endIndex]; // store pivot in temp.
      a[endIndex]=a[pivotIndex];// store the value at pivotIndex to the end of the list.
      a[pivotIndex]=temp; // store the pivot in pivotIndex.

     //return the index of pivot.
     return pivotIndex;
 }
 void Quicksort(int a[],int start,int end)
 {
    if(start<end)
    {
         // store the value in pivotIndex.
         int pivotIndex=partition(a,start,end);
         //Now, recursivly split the list and sort them.
             Quicksort(a,start,pivotIndex-1);
             Quicksort(a,pivotIndex+1,end);
    }

 }


int main()
{
    int arr[] = {15, 3, 14, 13, 7, 8, 4, 9};

    //elements before sorting.
    cout << "numbers are: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Are the number sorted? return 1 if its true and 0 if its false: " << sortChecker(arr,size) << endl;

    cout << endl;
    cout << "   -------------------   " << endl;


           int num = partition(arr,0,size-1);
           cout << "Pivot index is: " << num << endl;
          cout << " the first pivot is:  " << arr[num]  << endl;

          cout << "elements after sorting first pivot" << endl;
          for(int i = 0; i < size; i++){
              cout << arr[i] << "  ";
          }

//          Quicksort(arr,0,size -1);
//          cout << "final sorted elements" << endl;


//          for(int i = 0; i < size; i++){
//              cout << arr[i] << "  ";
//          }

}
