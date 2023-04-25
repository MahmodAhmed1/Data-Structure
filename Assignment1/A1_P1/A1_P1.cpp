#include <bits/stdc++.h>

using namespace std;

class BigInt {
    string str;

    bool isNegative = 0;
    void isNeg() {
        isNegative = (str[0] == '-');
        if (isNegative) {
            std::reverse(str.begin(), str.end());
            str.pop_back();
            std::reverse(str.begin(), str.end());
        }
    }

    BigInt SumToStrings(BigInt &other) {
        string str1 = this->str;
        string str2 = other.str;

        if (str1.length() > str2.length())
            swap(str1, str2);

        string str = "";

        int n1 = str1.length(), n2 = str2.length();

        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;
        for (int i = 0; i < n1; i++) {

            int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');

            carry = sum / 10;
        }

        for (int i = n1; i < n2; i++) {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            str.push_back(carry + '0');

        reverse(str.begin(), str.end());

        BigInt temp(str);
        return temp;
    }

    bool fisrtSmallerThanSecond(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++) {
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
        }
        return false;
    }

    BigInt subToSTrings(BigInt &other) {
        BigInt temp;
        if (fisrtSmallerThanSecond(str, other.str))
            swap(str, other.str);

        int n1 = str.length(), n2 = other.str.length();
        int diff = n1 - n2;

        int carry = 0;

        for (int i = n2 - 1; i >= 0; i--) {
            int sub = ((str[i + diff] - '0') - (other.str[i] - '0')
                       - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            temp.str.push_back(sub + '0');
        }

        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str[i] == '0' && carry) {
                temp.str.push_back('9');
                continue;
            }
            int sub = ((str[i] - '0') - carry);
            if (i > 0 || sub > 0)
                temp.str.push_back(sub + '0');
            carry = 0;
        }

        reverse(temp.str.begin(), temp.str.end());
        return temp;
    }

public:

    BigInt() {
        str = "";
    }

    BigInt(long long num) {
        str = to_string(num);
        isNeg();
    }

    BigInt(string str) {
        this->str = str;
        isNeg();
        bool flag = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] < '0' && str[i] >= '9') {
                flag = 1;
                break;
            }
        }
        if (flag)throw ("this is not a number");
    }

    BigInt(BigInt &other) {
        this->str = other.str;
        this->isNegative = other.isNegative;
    }

    BigInt(BigInt &&other) {
        this->str = other.str;
        this->isNegative = other.isNegative;
    }

    BigInt operator+(BigInt &other) {
        BigInt temp("0");
        if (fisrtSmallerThanSecond(str, other.str) && isNegative && !other.isNegative)
            temp = subToSTrings(other), temp.isNegative = false;
        else if (!fisrtSmallerThanSecond(str, other.str) && isNegative && !other.isNegative)
            temp = subToSTrings(other), temp.isNegative = true;
        else if (!fisrtSmallerThanSecond(str, other.str) && !isNegative && other.isNegative)
            temp = subToSTrings(other), temp.isNegative = false;
        else if (fisrtSmallerThanSecond(str, other.str) && !isNegative && other.isNegative)
            temp = subToSTrings(other), temp.isNegative = true;

        else if (isNegative && other.isNegative)
            temp = SumToStrings(other), temp.isNegative = true;
        else if (!isNegative && !other.isNegative)
            temp = SumToStrings(other), temp.isNegative = false;

        return temp;
    }
    BigInt operator+(BigInt &&other) {
        BigInt temp("0");
        if (fisrtSmallerThanSecond(str, other.str) && isNegative && !other.isNegative)
            temp = subToSTrings(other), temp.isNegative = false;
        else if (!fisrtSmallerThanSecond(str, other.str) && isNegative && !other.isNegative)
            temp = subToSTrings(other), temp.isNegative = true;
        else if (!fisrtSmallerThanSecond(str, other.str) && !isNegative && other.isNegative)
            temp = subToSTrings(other), temp.isNegative = false;
        else if (fisrtSmallerThanSecond(str, other.str) && !isNegative && other.isNegative)
            temp = subToSTrings(other), temp.isNegative = true;

        else if (isNegative && other.isNegative)
            temp = SumToStrings(other), temp.isNegative = true;
        else if (!isNegative && !other.isNegative)
            temp = SumToStrings(other), temp.isNegative = false;

        return temp;
    }

    void operator=(BigInt &other) {
        if (other.str != this->str) {
            this->str = other.str;
        }
    }

    void operator=(BigInt &&other) {
        if (other.str != this->str) {
            this->str = other.str;
        }
    }

    friend ostream &operator<<(ostream &out, BigInt &&other) {
        if (other.isNegative)
            out << '-';
        while (other.str[0] == '0' && other.str.size() != 1) {
            std::reverse(other.str.begin(), other.str.end());
            other.str.pop_back();
            std::reverse(other.str.begin(), other.str.end());
        }
        out << other.str;
    }

    friend ostream &operator<<(ostream &out, BigInt &other) {
        if (other.isNegative)
            out << '-';
        out << other.str;
    }

    bool operator==(BigInt other) {
        return this->str == other.str && this->isNegative == other.isNegative;
    }

    bool operator==(const char *other) {
        BigInt x = string(other);
        return this->str == x.str && this->isNegative == x.isNegative;
    }

    int size() {
        return str.length();
    }
};

void Test1() {
    BigInt x = 1007, y = -1;
    BigInt ans = x + y;
    if (ans == "1006")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test2() {
    BigInt x = -1007, y = -1;
    BigInt ans = x + y;
    if (ans == "-1008")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test3() {
    BigInt x = -1007, y = 1;
    BigInt ans = x + y;
    if (ans == "-1006")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test4() {
    BigInt x = 1007, y = 1;
    BigInt ans = x + y;
    if (ans == "1008")cout << "test pass\n";
    else cout << "Test failed\n";
}
void Test5() {
    BigInt x = 1007, y  ("-1");
    BigInt ans = x + y;
    if (ans == "1006")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test6() {
    BigInt x ("-1007"), y ("-1");
    BigInt ans = x + y;
    if (ans == "-1008")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test7() {
    BigInt x  ("-1007"), y ("1");
    BigInt ans = x + y;
    if (ans == "-1006")cout << "test pass\n";
    else cout << "Test failed\n";
}

void Test8() {
    BigInt x  ("1007"), y  ("1");
    BigInt ans = x + y;
    if (ans == "1008")cout << "test pass\n";
    else cout << "Test failed\n";
}
void Test9() {
    BigInt x("0000001");
    cout << BigInt("000000001") + BigInt("000001");
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    return 0;
}
