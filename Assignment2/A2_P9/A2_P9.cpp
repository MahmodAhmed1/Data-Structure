#include <iostream>
using namespace std;

class node // class for making nodes
{
public:
    int key;
    node *left, *right;
    node() { left = right = 0; }          // default constructor
    node(int x, node *l = 0, node *r = 0) // constructor
    {
        key = x;
        left = l;
        right = r;
    }
    node *getleft() { return left; }
    node *getright() { return right; }
    int getkey() { return key; }
};

bool check(node *x, node *y)
{
    if (x == 0 && y == 0) // check is two null
    {
        return true;
    }
    if (x == 0 || y == 0) // check is two not foldable
    {
        return false;
    }

    return check(x->left, y->right) && check(x->right, y->left); // recursion for right and left
}
bool fold(node *root) // check root
{
    if (root == 0)
    {
        return true;
    }

    return check(root->left, root->right);
}
int counter = 1;
void print(bool checker) // print is foldable
{
    if (checker == 1) // print foldable
    {
        cout << "case" << counter << " : is foldable" << endl;
        counter++;
    }
    else if (checker == 0) // print not foldable
    {
        cout << "case " << counter << " : is not foldable" << endl;
        counter++;
    }
}
int main()
{
    // test case 1
    node *x1 = new node(1);
    x1->left = new node(2);
    x1->right = new node(3);
    x1->right->right = new node(5);
    x1->left->left = new node(4);
    print(fold(x1));

    // test case 2
    node *x2 = new node(1);
    x2->left = new node(4);
    x2->right = new node(2);
    x2->right->left = new node(3);
    x2->left->right = new node(5);
    print(fold(x2));

    // test case 3
    node *x3 = new node(1);
    x3->left = new node(2);
    x3->right = new node(3);
    x3->right->left = new node(6);
    x3->left->left = new node(4);
    x3->left->right = new node(5);
    print(fold(x3));

    // test case 4
    node *x4 = new node(1);
    x4->left = new node(2);
    x4->right = new node(3);
    x4->right->left = new node(6);
    x4->right->right = new node(7);
    x4->left->left = new node(6);
    x4->left->right = new node(5);
    print(fold(x4));

    // test case 5
    node *x5 = new node(1);
    x5->left = new node(2);
    x5->right = new node(3);
    x5->right->left = new node(6);
    x5->right->right = new node(7);
    x5->left->left = new node(6);
    print(fold(x5));
}
