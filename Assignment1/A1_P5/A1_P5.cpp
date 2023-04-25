#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class StudentName
{
private:
    string name;
    vector<string> ListName;
public:
    StudentName(string n)
    {
        int posofspace = 0, numofspace = 0;
        for(int i = 0; i < n.length(); i++)
        {
            if(n[i] == ' ')
            {
                numofspace++;
                posofspace = i;
            }
        }

        if(numofspace >= 2)
            name = n;
        else if(numofspace == 0)
            name = n + " " + n + " " + n;
        else
            name = n + " " + n.substr(posofspace+1);

        string subname;
        for(int i = 0; i < name.length(); i++)
        {
            subname = subname + name[i];
            if(name[i] == ' ')
            {
                ListName.push_back(subname);
                subname = "";
            }
        }
        ListName.push_back(subname);

    }

    bool replaces(int i, int j)
    {
        if(i > ListName.size() || j > ListName.size())
            return false;
        else
        {
            string Rname;
            swap(ListName[i-1], ListName[j-1]);
            return true;
        }
    }


    void print()
    {
        int j = 1;
        for(auto it : ListName)
            cout << j++ << ")" << it << endl;
    }

};


int main()
{

    StudentName test1("ahmed mohamed sayed");
    if(test1.replaces(3, 2))
    {
        cout << "Test 1" << endl;
        test1.print();
        cout << "------------------------" << endl;
    }
    StudentName test2("sara ahmed");
    if(test2.replaces(3, 1))
    {
        cout << "Test 2" << endl;
        test2.print();
        cout << "------------------------" << endl;
    }

    StudentName test3("khaled");
    if(test3.replaces(3, 2))
    {
        cout << "Test 3" << endl;
        test3.print();
        cout << "------------------------" << endl;
    }

    StudentName test4("aya ali ahmed sayed");
    if(test2.replaces(1, 2))
    {
        cout << "Test 4" << endl;
        test4.print();
        cout << "------------------------" << endl;
    }

    StudentName test5("ahmed hassan ali");
    if(test5.replaces(1, 2))
    {
        cout << "Test 5" << endl;
        test5.print();
    }

    return 0;
}
