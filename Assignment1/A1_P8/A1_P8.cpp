#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace std;
void Insertion_Sort(int arr[] , int n){
    for(int i=1 ; i<n ; i++){
        int value = arr[i];
        int hole = i;
        while(hole >0 && arr[hole-1] > value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

int Binary_Search(int arr[], int value, int low, int high){
    if(high <= low){
        if(value > arr[low]){
            low++;
        }
        else{
            return low;
        }
    }
    int mid = (low+high)/2;
    if(arr[mid] == value)
        return mid+1;
    if(arr[mid] > value){
        return Binary_Search(arr, value, low, mid-1);
    }
    else{
        return Binary_Search(arr, value, mid+1, high);
    }
}

void Binary_Insertion_Sort(int arr[], int n){
   int i, location, high, value;
   for (i = 1; i < n; ++i) {
      high = i - 1;
      value = arr[i];
      location = Binary_Search(arr, value, 0, high);
      while (high >= location) {
         arr[high+1] = arr[high];
         high--;
      }
      arr[high+1] = value;
   }
}

int main(){
    for (int i=0 ; i<6 ; i++){
    int* arr;
    int n;
    auto f = []() -> int{return rand()%10000 ;}; //generate random numbers
    cout << "enter the array size: ";
    cin >> n; // get the array size
    arr = new int[n]; // allocate the array
    generate(arr , arr+n , f); // filling the array with the random generated numbers
    auto start = high_resolution_clock::now(); // capture the time before running the algorithm
    Binary_Insertion_Sort(arr , n); // calling the algorithm
    auto stop = high_resolution_clock::now(); // capture the time after running the algorithm
    auto duration = duration_cast<milliseconds>(stop - start); // calculate the time taken by the algorithm
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
    }
    return 0;
}
