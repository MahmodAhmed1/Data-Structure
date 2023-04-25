#include <iostream>

using namespace std;

struct BSTNode
{
    int key;
    BSTNode* left;
    BSTNode* right;

    BSTNode()
    {
        key = 0;
        left = right = nullptr;
    }
    BSTNode(int data)
    {
        key = data;
        left = right = nullptr;
    }
};

class BST
{
private:
    BSTNode* root;

public:
    static int x,res;
    BST()
    {
        root = nullptr;

    }
    BST(int data)
    {
        root = new BSTNode(data);
    }

    void Insert(int data)
    {
        BSTNode* p = root, *prev = 0;
        while(p != nullptr)
        {
            prev = p;
            if(root->key < data)
            {
                p = p->right;
            }
            else
                p = p->left;
        }
        if(root == nullptr)
        {
            root = new BSTNode(data);
            x++;
        }

        else if(data < prev->key)
        {
            prev->left = new BSTNode(data);
            x++;
        }

        else
        {
            prev->right = new BSTNode(data);
            x++;
        }

    }

    int summationOfElementRec(BSTNode* node, int k, int &counter)
    {
        if(node == nullptr)
            return 0;
        if(counter > k)
            return 0;
        int res;
        res = summationOfElementRec(node->left, k, counter);
        if(counter >= k)
            return res;
        res += node->key;
        counter++;

        if(counter >= k)
            return res;
        return res + summationOfElementRec(node->right, k, counter);

    }
    int summationOfElement(int k)
    {
        int counter = 0;
        if(k<0)
        {
            cout<<"Wrong Number.....! ";
            return -1;
        }
        else if(k>x)
            cout<<"The Number You Need To Calculate it Grater Than The Number Of The Nodes ("<< x <<")....\n"
            <<"But The Summation Of All Nodes Is :  ";
        else if(k == x)
            cout<<"It's The Summation Of All Nodes Is :  ";
        else
            cout<<"The Summation Of "<<k<<" nodes Is :  ";
        x=0;
        return summationOfElementRec(root, k, counter);
    }
    /*
    int summationOfElementRec(int k, BSTNode* p, int &counter)
    {
        if(p != 0)
        {
            summationOfElementRec(k, p->left,counter);
            if(counter < k)
            {
                res +=  p->key;
                counter++;
            }
            summationOfElementRec(k, p->right,counter);
        }
        return res;
    }
    int summationOfElement(int k)
    {
        int counter = 0;
        if(k<0)
        {
            cout<<"Wrong Number.....! ";
            return -1;
        }
        else if(k>x)
            cout<<"The Number You Need To Calculate it Grater Than The Number Of The Nodes ("<< x <<")....\n"
            <<"But The Summation Of All Nodes Is :  ";
        else if(k == x)
            cout<<"It's The Summation Of All Nodes Is :  ";
        else
            cout<<"The Summation Of "<<k<<" nodes Is :  ";
        x=0;
        return summationOfElementRec(k, root, counter);

    }
    */

    void inorder(BSTNode* node)
    {
        if (node == nullptr)
            return;
        else if(node != 0)
        {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }

    }
    void print()
    {
        inorder(root);
        cout<<endl;
    }
    ~BST()
    {
        delete root;
    }

};

int BST :: x = 0;
int BST :: res = 0;


void test1()
{
    BST test1;
    /*
    the example of binary tree
              54
            /    \
           /      \
          51      75
         /  \     / \
        49   52  74  85
    */
    cout<<"TEST 1"<<endl;
    test1.Insert(54);
    test1.Insert(51);
    test1.Insert(52);
    test1.Insert(49);
    test1.Insert(75);
    test1.Insert(74);
    test1.Insert(85);
    test1.print();
    //the smallest three nodes is 49, 51, 52
    cout<<test1.summationOfElement(3)<<endl;
    BST::res = 0;
}

void test2()
{
    BST test2;
    /*
    the example of binary tree
          20
        /    \
       8      22
     /   \      \
    7     14     30

    */
    cout<<"\n\nTEST 2"<<endl;
    test2.Insert(20);
    test2.Insert(22);
    test2.Insert(8);
    test2.Insert(14);
    test2.Insert(7);
    test2.Insert(30);
    //the smallest three nodes is 7, 8
    test2.print();
    cout<<test2.summationOfElement(2)<<endl;
    BST::res = 0;

}

void test3()
{
    BST test3;
    /*
    the example of binary tree
              8
            /   \
           7     10
         /      /   \
        2      9     13
     */

    cout<<"\n\nTEST 3"<<endl;
    test3.Insert(8);
    test3.Insert(7);
    test3.Insert(2);
    test3.Insert(10);
    test3.Insert(9);
    test3.Insert(13);
    //the smallest six nodes is 2, 7, 8, 9, 10, 13
    test3.print();
    cout<<test3.summationOfElement(7)<<endl;
    BST::res = 0;
}

void test4()
{
    BST test4;
    /*
    the example of binary tree
           8
         /   \
        5    11
      /  \
     2    7
      \
       3
    */
    cout<<"\n\nTEST 4"<<endl;
    test4.Insert(8);
    test4.Insert(5);
    test4.Insert(7);
    test4.Insert(2);
    test4.Insert(3);
    test4.Insert(11);
    //the smallest six nodes is 2, 3, 5, 7, 8, 11
    test4.print();
    cout<<test4.summationOfElement(6)<<endl;
    BST::res = 0;

}

void test5()
{
    BST test5;
    /*
    the example of binary tree
           8
         /   \
        5    11
      /  \
     2    7
      \
       3
    */
    cout<<"\n\nTEST 5"<<endl;
    test5.Insert(8);
    test5.Insert(5);
    test5.Insert(7);
    test5.Insert(2);
    test5.Insert(3);
    test5.Insert(11);
    //the smallest one node is 2
    test5.print();
    cout<<test5.summationOfElement(-1)<<endl;
    BST::res = 0;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
