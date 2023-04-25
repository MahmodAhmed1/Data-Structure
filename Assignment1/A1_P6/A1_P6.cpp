#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class PhoneDirectory
{
    char *first_name;
    char *last_name;
    char *phone_number;

public:
    PhoneDirectory()
    {
    }
    char *get_fN() const
    {
        return first_name;
    }
    char *get_lN() const
    {
        return last_name;
    }
    char *get_pN() const
    {
        return phone_number;
    }
    void set_fn()
    {
        char *fn;
        fn = new char[100];
        cout << "enter first name: ";
        cin >> fn;
        first_name = fn;
    }
    void set_ln()
    {
        char *ln;
        ln = new char[100];
        cout << "enter last name: ";
        cin >> ln;
        last_name = ln;
    }
    void set_pn()
    {
        char *pn;
        pn = new char[100];
        cout << "enter phone number: ";
        cin >> pn;
        phone_number = pn;
    }
    void print_data()
    {
        cout << "first name: " << first_name << endl;
        cout << "last name: " << last_name << endl;
        cout << "phone number: " << phone_number << endl;
    }
    void clear()
    {
        delete[] first_name;
        delete[] last_name;
        delete[] phone_number;
    }
    ~PhoneDirectory()
    {
    }
};
void bubble_sort(vector<PhoneDirectory> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (strcmp(arr[j].get_fN(), arr[j - 1].get_fN()) < 0)
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
void insertionSort(vector<PhoneDirectory> &data, int n)
{
    for (int i = 1, j; i < n; i++)
    {
        PhoneDirectory temp = data[i];
        for (j = i; j > 0 && strcmp(temp.get_fN(), data[j - 1].get_fN()) < 0; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = temp;
    }
}

void selSort(vector<PhoneDirectory> &arr, int size)
{
    for (int i = 0, j, least; i < size - 1; i++)
    {
        for (j = i + 1, least = i; j < size; j++)
        {
            if (strcmp(arr[j].get_fN(), arr[least].get_fN()) < 0)
            {
                least = j;
                swap(arr[least], arr[i]);
            }
        }
    }
}
int main()
{
    vector<PhoneDirectory> dir;
    int option;
    int index = 0;
    do
    {
        option = 0;
        cout << "\n1 Add an entry to the directory" << endl
             << "2 Look up by phone number" << endl
             << "3 Look up by first name" << endl
             << "4 Delete an entry from the directory" << endl
             << "5 List All entries in phone directory" << endl
             << "6 Exit form this program\n"
             << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            dir.push_back(PhoneDirectory());
            dir[index].set_fn();
            dir[index].set_ln();
            dir[index].set_pn();
            index++;
            break;
        case 2:
            char *pn_searched;
            pn_searched = new char[100];
            cout << "enter phone number: ";
            cin >> pn_searched;
            for (int i = 0; i < index; i++)
            {
                if (*pn_searched == *dir[i].get_pN())
                {
                    cout << endl;
                    dir[i].print_data();
                    delete[] pn_searched;
                    break;
                }
                else if (*pn_searched != *dir[i].get_pN() && i == index - 1)
                {
                    cout << "entry not found!" << endl;
                }
            }
            delete[] pn_searched;
            break;
        case 3:
            char *fn_searched;
            fn_searched = new char[100];
            cout << "enter first name: ";
            cin >> fn_searched;
            for (int i = 0; i < index; i++)
            {
                if (*fn_searched == *dir[i].get_fN())
                {
                    cout << endl;
                    dir[i].print_data();
                    delete[] fn_searched;
                    break;
                }
                else if (*fn_searched != *dir[i].get_fN() && i == index - 1)
                {
                    cout << "entry not found!" << endl;
                }
            }
            delete[] fn_searched;
            break;
        case 4:
            char *fn_delete;
            fn_delete = new char[100];
            cout << "enter first name: ";
            cin >> fn_delete;
            for (int i = 0; i < index; i++)
            {
                if (*fn_delete == *dir[i].get_fN())
                {
                    dir.erase(dir.begin() + i);
                    index--;
                    delete[] fn_delete;
                    break;
                }
                else if (*fn_delete != *dir[i].get_fN() && i == index - 1)
                {
                    cout << "entry not found!" << endl;
                }
            }
            delete[] fn_delete;
            break;
        case 5:
            insertionSort(dir, index);
            for (int i = 0; i < index; i++)
            {
                cout << endl;
                dir[i].print_data();
                cout << endl;
            }
            break;
        default:
            cout << "Ending program" << endl;
            break;
        }
    } while (option != 6);
    for (int i = 0; i < index; i++)
    {
        dir[index].clear();
    }
    return 0;
}