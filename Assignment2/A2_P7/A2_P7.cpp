#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        this->left = this->right = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to convert a given binary tree into its mirror
void flip(Node* root = nullptr)
{
    if (root == nullptr) {
        return;
    }

    flip(root->left);
    flip(root->right);
    swap(root->left, root->right);

}

// Function to perform pre order traversal on a given binary tree
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform in order traversal on a given binary tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to perform post order traversal on a given binary tree
void postorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void test1()
{
    /*
    Construct the following tree before flip method
              1
            /   \
           2     3
          / \
         4   5
    Construct the following tree after flip method
              1
            /   \
           3     2
                / \
               5   4
    */
    cout<<"TEST 1"<<endl;
    Node* test1 = new Node(1);
    test1 -> left = new Node(2);
    test1 -> right = new Node(3);
    test1 -> left -> left = new Node(4);
    test1 -> left -> right = new Node(5);
    cout<<"perform inorder traversal"<<endl;
    inorder(test1);
    cout<<endl;
    flip(test1);
    cout<<"inorder traversal after flip method"<<endl;
    inorder(test1);
}

void test2()
{
    /*
    Construct the following tree before flip method
              1
            /   \
           3     2
                / \
               5   4
    Construct the following tree after flip method
              1
            /   \
           2     3
          / \
         4   5
    */
    cout<<"\n\n\nTEST 2"<<endl;
    Node* test2 = new Node(1);
    test2 -> left = new Node(3);
    test2 -> right = new Node(2);
    test2 -> right -> right = new Node(4);
    test2 -> right -> left = new Node(5);
    cout<<"perform inorder traversal"<<endl;
    inorder(test2);
    cout<<endl;
    flip(test2);
    cout<<"inorder traversal after flip method"<<endl;
    inorder(test2);

}

void test3()
{
    /*
    Construct the following tree before flip method
             1
            /
           3
          /
         2
        /
       4
    Construct the following tree after flip method
           1
            \
             3
              \
               2
                \
                 4
    */
    cout<<"\n\n\nTEST 3"<<endl;
    Node* test3 = new Node(1);
    test3 -> left = new Node(3);
    test3 -> left -> left = new Node(2);
    test3 -> left -> left -> left = new Node(4);
    cout<<"perform inorder traversal"<<endl;
    inorder(test3);
    cout<<endl;
    flip(test3);
    cout<<"inorder traversal after flip method"<<endl;
    inorder(test3);

}

void test4()
{
    /*
    Construct the following tree before flip method
           8
          / \
         /   \
        3     10
       / \     \
      1   6     14
         / \    /
        4   7  13
    Construct the following tree after flip method
           8
         /   \
        /     \
       10      3
       /      / \
      14     6   1
       \    / \
        13 7   4
    */
    cout<<"\n\n\nTEST 4"<<endl;
    Node* test4 = new Node(8);
    test4 -> left = new Node(3);
    test4 -> left -> left = new Node(1);
    test4 -> left -> right = new Node(6);
    test4 -> left -> right -> left = new Node(4);
    test4 -> left -> right -> right = new Node(7);
    test4 -> right = new Node(10);
    test4 -> right -> right = new Node(14);
    test4 -> right -> right -> left = new Node(13);
    cout<<"perform inorder traversal"<<endl;
    inorder(test4);
    cout<<endl;
    flip(test4);
    cout<<"inorder traversal after flip method"<<endl;
    inorder(test4);

}

void test5()
{
    /*
    Construct the following tree before flip method
              1
            /   \
           3     2
          / \   / \
         7   6 5   4
    Construct the following tree after flip method
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */
    cout<<"\n\n\nTEST 5"<<endl;
    Node* test5 = new Node(1);
    test5 -> left = new Node(3);
    test5 -> right = new Node(2);
    test5 -> left -> right = new Node(6);
    test5 -> left -> left = new Node(7);
    test5 -> right -> right = new Node(4);
    test5 -> right -> left = new Node(5);
    cout<<"perform inorder traversal"<<endl;
    inorder(test5);
    cout<<endl;
    flip(test5);
    cout<<"inorder traversal after flip method"<<endl;
    inorder(test5);
    cout<<endl;

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
