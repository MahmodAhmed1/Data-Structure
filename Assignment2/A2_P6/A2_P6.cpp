#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include<stack>
using namespace std;

//tree node declaring
class TreeNode
{
public:
    char data;
    TreeNode* Left;
    TreeNode* Right;
    // parameterized constructor;
    TreeNode(char d)
    {
        data = d;
        Left = NULL;
        Right = NULL;
    }
};

class Expression_Tree
{
public:
    stack <TreeNode*>StackNode;
    TreeNode* root;
    //The “push()” function that push node into stack.
    void push(TreeNode* ptr)
    {
        StackNode.push(ptr);
    }
    //The “pop()” function that pop top most node in the stack.
    TreeNode* pop()
    {
        if (!StackNode.top())
        {
            cout << "the top most node is empty" << endl;
            return NULL;
        }
        else
        {
            TreeNode* temp = StackNode.top();
            StackNode.pop();
            return temp;
        }
    }
    TreeNode* getRoot() {
        return root;
    }
    int CharToDigit(char ch)
    {
        return ch - '0';
    }
    bool isDigit(char ch)
    {

        return ch >= '0' && ch <= '9';
    }
    bool OperatorCheck(char ch)
    {

        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    //The “insertion()” function that insert the node if its value is a digit ,
    //if the value is operator, pop two nodes and assign it to “left” and “right” pointer of new node and insert into stack.
    void insert(char x,int indx)
    {
        TreeNode* nptr = new TreeNode(x);
        if (isDigit(x))
        {
            push(nptr);
        }
        else if (OperatorCheck(x))
        {

            nptr->Left = pop();
            nptr->Right = pop();
            push(nptr);
        }
        else
        {
            cout << "The Expression is invalid" << endl;
            return;
        }
        if (indx == 0)
        {
            root = nptr;
        }
    }
    //The “CreateTree()” function that create tree from given prefix notation.
    void CreateTree(string expression)
    {

        for (int i = expression.length()-1; i >= 0; i--)
            insert(expression[i],i);

    }
    //
    void PreOrder(TreeNode* ptr)
    {
        if (ptr != NULL)
        {
            cout << ptr->data;
            PreOrder(ptr->Left);
            PreOrder(ptr->Right);
        }
    }


    void inOrder(TreeNode* ptr)
    {
        if (ptr != NULL)
        {
            inOrder(ptr->Left);
            cout << ptr->data;
            inOrder(ptr->Right);
        }
    }
    int evaluation(TreeNode* root)
    {
        if (!root)
            return 0;

        if (!root->Right && !root->Left)
            return CharToDigit(root->data);

        int leftValue = evaluation(root->Left);
        int rightValue = evaluation(root->Right);
        if (root->data == '+')
            return leftValue + rightValue;
        if (root->data == '-')
            return leftValue - rightValue;
        if (root->data == '*')
            return leftValue * rightValue;

        return leftValue / rightValue;
    }

};

int main()
{
    string test_case_1 = "+3*4/82";     //the infix answestring (3+4*8/2)
    string test_case_2 = "++1*234";    //the infix answer is (1+2*3+4)
    string test_case_3 = "*+12+34";   //the infix answer is (3+4+6+8)
    string test_case_4 = "+1*23";    //the infix answer is (1+2*3)
    string test_case_5 = "+++1234"; //the infix answer is (1+2+3+4)
    Expression_Tree et;

    cout<<"Test Case 1  (3+4*8/2)"<<endl;
    et.CreateTree(test_case_1);
    cout <<"Answer: "<<et.evaluation(et.getRoot())<<endl;

    cout<<"\n\nTest Case 2  (1+2*3+4)"<<endl;
    et.CreateTree(test_case_2);
    cout <<"Answer: "<<et.evaluation(et.getRoot())<<endl;

    cout<<"\n\nTest Case 3  (3+4+6+8)"<<endl;
    et.CreateTree(test_case_3);
    cout <<"Answer: "<<et.evaluation(et.getRoot())<<endl;

    cout<<"\n\nTest Case 4  (1+2*3)"<<endl;
    et.CreateTree(test_case_4);
    cout <<"Answer: "<<et.evaluation(et.getRoot())<<endl;

    cout<<"\n\nTest Case 5  (1+2+3+4)"<<endl;
    et.CreateTree(test_case_5);
    cout <<"Answer: "<<et.evaluation(et.getRoot())<<endl;



    return 0;
}
