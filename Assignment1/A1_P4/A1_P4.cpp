#include <iostream>
#include <set>

using namespace std;

void RecPermute(string soFar, string rest)
{

    set<string> arr;
    if (rest == "") // No more characters
        cout << soFar << endl;
    else// Still more chars
        // For each remaining char
    {
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i+1);
            int siz = arr.size();
            auto it = arr.begin();
            it = arr.emplace_hint(it,next); //best in time complexity by O(1).
            //arr.insert(next); O(logn).
            if(arr.size() > siz)
                RecPermute(next, remaining);
        }
    }


}

void ListPermutations(string s)
{
    RecPermute("", s);
}

int main()
{
    ListPermutations( "MAKKA" );
    return 0;
}



