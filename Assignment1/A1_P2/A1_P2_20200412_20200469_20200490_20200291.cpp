#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

class fraction
{
    int numerator, denominator;

public:
    fraction()
    {
    }
    fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }
    int get_num() const
    {
        return numerator;
    }
    int get_den() const
    {
        return denominator;
    }
    int fraction_gcd(fraction obj)
    {
        return gcd(denominator, obj.denominator);
    }
    int fraction_lcm(fraction obj)
    {
        return (denominator * obj.denominator) / fraction_gcd(obj);
    }
    fraction operator+(fraction obj)
    {
        int res_num;
        int lcd = fraction_lcm(obj);
        numerator *= (lcd / denominator);
        obj.numerator *= (lcd / obj.denominator);
        res_num = numerator + obj.numerator;
        fraction res(res_num, lcd);
        return res;
    }
    fraction operator-(fraction obj)
    {
        int res_num;
        int lcd = fraction_lcm(obj);
        numerator *= (lcd / denominator);
        obj.numerator *= (lcd / obj.denominator);
        res_num = numerator - obj.numerator;
        fraction res(res_num, lcd);
        return res;
    }
    fraction operator*(fraction obj)
    {
        int res_num;
        int res_denom;
        res_num = numerator * obj.numerator;
        res_denom = denominator * obj.denominator;
        fraction res(res_num, res_denom);
        return res;
    }
    fraction operator/(fraction obj)
    {
        int res_num;
        int res_denom;
        res_num = numerator * obj.denominator;
        res_denom = denominator * obj.numerator;
        fraction res(res_num, res_denom);
        return res;
    }
    void reduce()
    {
        int greatestCD = gcd(numerator, denominator);
        numerator /= greatestCD;
        denominator /= greatestCD;
    }
    bool operator==(fraction obj)
    {
        reduce();
        obj.reduce();
        if (numerator == obj.numerator && denominator == obj.denominator)
        {
            return true;
        }
        else
            return false;
    }
    void set_num(int n)
    {
        numerator = n;
    }
    void set_denom(int d)
    {
        denominator = d;
    }
    friend ostream &operator<<(ostream &out, const fraction &f);
    friend istream &operator>>(istream &in, fraction &f);
};

ostream &operator<<(ostream &out, const fraction &f)
{
    out << f.get_num() << '/' << f.get_den() << endl;
    return out;
}

istream &operator>>(istream &in, fraction &f)
{
    std::cout << "enter numerator: ";
    in >> f.numerator;
    std::cout << "enter denominator: ";
    in >> f.denominator;
    f.reduce();
    return in;
}


class fractionCalculator
{
    fraction result;
    fraction f1, f2;
    int option;

public:
    void start_calculator()
    {
        std::cout << "starting calculator..." << endl;
        do
        {
            std::cout << "enter option from the following 1-add 2-subtract 3-multiply 4-divide 5-reduce 6-exit" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "enter first fraction..." << endl;
                cin >> f1;
                cout << "enter second fraction..." << endl;
                cin >> f2;
                result = f1 + f2;
                result.reduce();
                cout << "result is " << result;
                break;
            case 2:
                cout << "enter first fraction..." << endl;
                cin >> f1;
                cout << "enter second fraction..." << endl;
                cin >> f2;
                result = f1 - f2;
                result.reduce();
                cout << "result is " << result;
                break;
            case 3:
                cout << "enter first fraction..." << endl;
                cin >> f1;
                cout << "enter second fraction..." << endl;
                cin >> f2;
                result = f1 * f2;
                result.reduce();
                cout << "result is " << result;
                break;
            case 4:
                cout << "enter first fraction..." << endl;
                cin >> f1;
                cout << "enter second fraction..." << endl;
                cin >> f2;
                result = f1 / f2;
                result.reduce();
                cout << "result is " << result;
                break;
            case 5:
                cout << "enter first fraction..." << endl;
                cin >> f1;
                result = f1;
                result.reduce();
                cout << "result is " << result;
                break;
            default:
                cout << "exiting the program...";
                break;
            }
        } while (option != 6);
    }
};

int main()
{
    fractionCalculator calc1;
    calc1.start_calculator();
    return 0;
}
