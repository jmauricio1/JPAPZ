//Joshua Jacob Mauricio and Zeed
//assignment 7 Lab 7
#include <iostream>

using namespace std;

void getData(int heights[], int size){
    int i = 0;
    int height = 0;
    while (i < size){
        cin >> height;
        heights[i] = height;
        i++;
    }
}

int getHighestPointBetween(const int heights[], int startMile, int endMile){
    int highPoint = heights[startMile];
    while(startMile < endMile){
        if((heights[startMile] > heights[startMile + 1]) && (heights[startMile] > highPoint))
            highPoint = heights[startMile];
        startMile++;
    }
    return highPoint;
}

double getAverage(const int heights[], int size){
    int i = 0;
    int sum = 0;
    while(i < size){
        sum = sum + heights[i];
        i++;
    }
    double average = static_cast<double>(sum) / size;
    return average;
}

int getNumPeaks(const int heights[], int size){
    int i = 1;
    int peaks = 0;
    while (i < (size - 1)){
        if ((heights[i] > heights[i-1]) && (heights[i]) > heights[i + 1])
            peaks = peaks + 1;
        i++;

    }
    return peaks;
}

int getNumSteepSegments(const int heights[], int size){
    int i = 0;
    int segments = 0;
    while(i < (size - 1)){
        if(((heights[i] - heights[i+1]) > 1000) || ((heights[i + 1] - heights[i]) > 1000))
            segments = segments + 1;
        i++;
    }
    return segments;
}

int getTotalChange(const int heights[], int startMile, int endMile){
    int i = startMile;
    int change = 0;
    while(i < endMile){
        change = change + abs(heights[i] - heights[i + 1]);
        i++;
    }
    return change;
}

int main()
{
    const int HIKE_LENGTH = 9;
    int elevations[HIKE_LENGTH];

    cout << "Please enter height elevations:" << endl;
    getData(elevations, HIKE_LENGTH);

    cout << "Now enter two points to find the highest elevation." << endl;
    int start = 0;
    int end = 0;
    cin >> start;
    cin >> end;
    cout << "Highest elevation: " << getHighestPointBetween(elevations, start, end) << endl;

    cout << "Average elevation: " << getAverage(elevations, HIKE_LENGTH) << endl;

    cout << "Peaks: " << getNumPeaks(elevations, HIKE_LENGTH) << endl;
    cout << "Steep segments: " << getNumSteepSegments(elevations, HIKE_LENGTH) << endl;
    cout << "Total elevation change: " << getTotalChange(elevations, start, end) << endl;

}
