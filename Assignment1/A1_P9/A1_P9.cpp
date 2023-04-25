#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;


class sorter
{
protected:
    int *arr;
    int size;
public:
    virtual void sort(int *a, int s) {}
    ~sorter()
    {
        delete []arr;
    }
};


//class selection sort inherit from class sorter
class SelectSorter: public sorter
{
protected:
    int *arr;
    int size;
public:
    void sort(int *a, int s)
    {
        size = s;
        arr = new int[size];
        arr = a;
        int mini;
        for(int i = 0; i < size-1; i++)
        {
            mini = i;
            for(int j = i + 1; j < size; j++)
            {
                if(arr[mini] > arr[j])
                    mini = j;
            }
            swap(arr[mini], arr[i]);
        }
    }
    ~SelectSorter()
    {
        delete []arr;
    }
};

class QuickSorter: public sorter
{
protected:
    int *arr;
    int size;
    int start;
public:
    void sort(int *a, int s)
    {
        size = s;
        arr = new int[size];
        arr = a;
        start = 0;
        quickSort(arr,start,size);
    }

    int partition(int arr[], int start, int end)
    {
        int pivot = arr[start];
        int count = 0;
        for (int i = start + 1; i <= end; i++)
        {
            if (arr[i] <= pivot)
                count++;
        }
        // Giving pivot element its correct position
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);
        // Sorting left and right parts of the pivot element
        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex)
        {

            while (arr[i] <= pivot)
            {
                i++;
            }

            while (arr[j] > pivot)
            {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex)
            {
                swap(arr[i++], arr[j--]);
            }
        }
        return pivotIndex;
    }

    void quickSort(int arr[], int start, int end)
    {

        // base case
        if (start >= end)
            return;

        // partitioning the array
        int p = partition(arr, start, end);

        // Sorting the left part
        quickSort(arr, start, p - 1);

        // Sorting the right part
        quickSort(arr, p + 1, end);
    }


    ~QuickSorter()
    {
        delete []arr;
    }
};

class Testbed
{
private:
    int size;
public:
    int* GenerateRandomList(int min, int max, int s)
    {
        size = s;
        int *arr;
        arr = new int[size];
        for(int i = 0; i < size; i++)
        {
            arr[i] = rand() % (max-min+1) + min;
        }
        return arr;
    }

    int* GenerateReverseOrderedList(int min, int max, int s)
    {
        int *arr;
        size = s;
        arr = new int[size];
        arr = GenerateRandomList(min,max,s);
        int mini = 0;
        for(int i = 0; i < s-1; i++)
        {
            mini = i;
            for(int j = i+1; j < s; j++)
            {
                if(arr[mini] < arr[j])
                    mini = j;
            }
            swap(arr[mini], arr[i]);
        }
        return arr;

    }
    double RunOnce(sorter *a, int *data, int s)
    {
        auto start = high_resolution_clock::now();
        a -> sort(data,s);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        return double(duration.count());
    }
    double RunAndAverage(sorter *a, string type, int min, int max, int s, int sets_num)
    {
        int *arr;
        size = s;
        arr = new int[size];
        double avrgRun = 0.0;
        if(type == "random")
        {
            arr = GenerateRandomList(min, max, s);
            for(int i = 0; i < sets_num; i++)
            {
                avrgRun += RunOnce(a, arr, s);
            }
        }

        else if(type == "reversed")
        {
            arr = GenerateReverseOrderedList(min, max, s);

            for(int i = 0; i < sets_num; i++)
            {
                avrgRun += RunOnce(a, arr, s);
            }
        }
        return double(avrgRun/sets_num);

    }
    void RunExperient(sorter *a, string type, int min, int max, int min_val, int max_val, int sets_num, int step)
    {
        int s = min_val;
        while(s < max_val)
        {
            s = s + step;
            cout << "|" << setw(5) << s << " |->|" << setw(8) << int(RunAndAverage(a, type, min, max, s, sets_num)) << " msec |" << endl;
        }
    }
};

int main()
{
    sorter *b;
    b = new QuickSorter;
    Testbed a;
    cout << "-------------------" << endl;
    cout << "|Quick Sort Random|" << endl;
    cout << "-------------------" << endl;
    cout << " [size]" << setw(18) << "[average time]" << endl;

    a.RunExperient(b, "random", 100, 100000, 0, 10000, 4, 1000);
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "---------------------" << endl;
    cout << "|Quick Sort Reversed|" << endl;
    cout << "---------------------" << endl;
    cout << " [size]" << setw(18) << "[average time]" << endl;
    a.RunExperient(b, "reversed", 100, 100000, 0, 10000, 4, 1000);
    sorter *s;
    s = new SelectSorter;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "|Selection Sort Random|" << endl;
    cout << "-----------------------" << endl;
    cout << " [size]" << setw(18) << "[average time]" << endl;
    a.RunExperient(s, "random", 100, 100000, 0, 10000, 4, 1000);
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "|Selection Sort reversed|" << endl;
    cout << "-------------------------" << endl;
    cout << " [size]" << setw(18) << "[average time]" << endl;
    a.RunExperient(s, "reversed", 100, 100000, 0, 10000, 4, 1000);

    return 0;
}
