#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
void Biased_Sort(vector<string> &arr)
{

    int n = arr.size();
    // sorting_start variable is to count the number of untitled songs and start sorting after them
    int sorting_start = 0;
    for (int i = 0; i < n; i++)
    { // checking whether the title is "Untitled" or not to put it in the front
        if (arr[i] == "Untitled")
        {
            swap(arr[i], arr[sorting_start]);
            sorting_start++;
        }
    }

    int j;
    // bubble sort to sort the rest of the songs
    for (sorting_start = 0; sorting_start < n - 1; sorting_start++)

        for (j = 0; j < n - sorting_start - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    vector<string> arr = {"Untitled", "Untitled", "Untitled", "b1", "a1", "Untitled"};
    Biased_Sort(arr);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}