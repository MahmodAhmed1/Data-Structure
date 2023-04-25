#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

template <class T>
class BSTNode
{
public:
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;

    BSTNode(T value)
    {
        data = value;
        left = right = NULL;
    }
};
template <class T>
class BSTFCI
{
public:
    int TreeSize;
    BSTNode<T> *root;

    BSTFCI()
    {
        root = 0;
    }
    /* Returns the height of a binary tree */

    /* Returns true if binary tree
    with root as root is height-balanced */
    bool isBalance(BSTNode<T> *root)
    {
        int left_h;  /* for height of left subtree */
        int right_h; /* for height of right subtree */

        /* If tree is empty then return true */
        if (root == NULL)
            return 1;

        /* Get the height of left and right sub trees */
        left_h = height(root->left);
        right_h = height(root->right);

        if (abs(left_h - right_h) <= 1 && isBalance(root->left) && isBalance(root->right))
            return 1;

        /* If we reach here then
        tree is not height-balanced */
        return 0;
    }

    /* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

    /* returns maximum of two integers */
    int max(int a, int b)
    {
        return (a >= b) ? a : b;
    }

    /* The function Compute the "height"
    of a tree. Height is the number of
    nodes along the longest path from
    the root node down to the farthest leaf node.*/
    int height(BSTNode<T> *node)
    {
        /* base case tree is empty */
        if (node == NULL)
            return 0;

        /* If tree is not empty then
        height = 1 + max of left
            height and right heights */
        return 1 + max(height(node->left),
                       height(node->right));
    }
    BSTNode<T> *add(BSTNode<T> *node, T val)
    {

        if (node == NULL)
        {
            BSTNode<T> *tmp = new BSTNode<T>(val);
            node = tmp;
            TreeSize++;
        }
        else
        {
            if (val > (node)->data)
            {
                node->right = add((node)->right, val);
            }
            else
            {
                node->left = add((node)->left, val);
            }
        }
        return node;
    }
    void add(T val)
    {
        root = add(root, val);
    }
    // Recursion Function to check if two nodes are identical.

    bool areIdentical(BSTNode<T> *root1, BSTNode<T> *root2)
    {
        // Both equal NULLs
        if (root1 == NULL && root2 == NULL)
            return true;
        // if both nodes are not equal
        if (root1 == NULL || root2 == NULL)
            return false;

        return (root1->data == root2->data &&              // check both nodes are equal
                areIdentical(root1->left, root2->left) &&  // check left nodes are equal
                areIdentical(root1->right, root2->right)); // check right nodes are equal
    }
    // Recursion Function to check if two nodes are identical.

    bool isSubtree(BSTNode<T> *t, BSTNode<T> *S)
    {
        if (S == NULL)
            return true;

        if (t == NULL)
            return false;

        if (areIdentical(t, S))
            return true;

        return isSubtree(t->left, S) ||
               isSubtree(t->right, S);
    }
    bool isSubTree(BSTFCI<T> *t1, BSTFCI<T> *t2)
    {
        return isSubtree(t1->root, t2->root);
    }
    void printRange(BSTNode<int> *root, int lowK, int highK)
    {
        if (root == 0)
        {
            return;
        }
        if (root->data < highK)
        {
            printRange(root->left, lowK, highK);
        }
        if (highK >= root->data && lowK <= root->data)
        {
            cout << root->data << "  ";
        }
        printRange(root->right, lowK, highK);
    }
};
int main()
{
    int height = 0;

    BSTFCI<int> tree;
    cout << "Test Case 1: \n";
    int nodes[3] = {3, 4, 1};
    for (int i = 0; i < 3; i++)
    {
        tree.add(nodes[i]);
    }

    if (tree.isBalance(tree.root))
    {
        cout << "Tree is balanced\n \n";
    }
    else
    {
        cout << "Tree is not balanced\n \n";
    }
    cout << "Test Case 2: \n";
    BSTFCI<int> tree2;
    int nodes2[4] = {3, 4, 1, 2};
    for (int i = 0; i < 4; i++)
    {
        tree2.add(nodes2[i]);
    }

    if (tree.isBalance(tree2.root))
    {
        cout << "Tree is balanced\n \n";
    }
    else
    {
        cout << "Tree is not balanced\n \n";
    }

    cout << "Test Case 3: \n";
    BSTFCI<int> tree3;
    int nodes3[5] = {3, 4, 2, 1, 0};
    for (int i = 0; i < 5; i++)
    {
        tree3.add(nodes3[i]);
    }

    if (tree.isBalance(tree3.root))
    {
        cout << "Tree is balanced\n \n";
    }
    else
    {
        cout << "Tree is not balanced\n \n";
    }
    cout << "Test Case 4: \n";
    BSTFCI<int> tree4;
    int nodes4[8] = {7, 10, 9, 14, 15, 12, 5, 6};
    for (int i = 0; i < 8; i++)
    {
        tree4.add(nodes4[i]);
    }

    if (tree.isBalance(tree4.root))
    {
        cout << "Tree is balanced\n \n";
    }
    else
    {
        cout << "Tree is not balanced\n \n";
    }

    cout << "Test Case 5: \n";
    BSTFCI<int> tree5;
    int nodes5[8] = {7, 10, 9, 14, 13, 12, 5, 6};
    for (int i = 0; i < 8; i++)
    {
        tree5.add(nodes5[i]);
    }

    if (tree.isBalance(tree5.root))
    {
        cout << "Tree is balanced\n \n";
    }
    else
    {
        cout << "Tree is not balanced\n \n";
    }
    BSTFCI<int> tree6;
    int nodes6[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        tree6.add(nodes6[i]);
    }
    BSTFCI<int> tree7;
    int nodes7[3] = {8, 9, 10};
    for (int i = 0; i < 3; i++)
    {
        tree7.add(nodes7[i]);
    }
    cout << "________________________" << endl;
    cout << "  the 5 test cases for the print range function" << endl;
    cout << "  it prints 1 when the trees are branched else it prints 0" << endl;
    cout << tree.isSubtree(tree.root, tree2.root) << endl;
    cout << tree.isSubtree(tree6.root, tree7.root) << endl;
    cout << tree.isSubtree(tree.root, tree3.root) << endl;
    cout << tree.isSubtree(tree.root, tree4.root) << endl;
    cout << tree.isSubtree(tree5.root, tree2.root) << endl;

    cout << "________________________" << endl;
    cout << "  the 5 test cases for the print range function" << endl;
    tree5.printRange(tree5.root, 7, 14);
    cout << endl;
    tree4.printRange(tree4.root, 6, 10);
    cout << endl;
    tree3.printRange(tree3.root, 1, 3);
    cout << endl;
    tree2.printRange(tree2.root, 2, 3);
    cout << endl;
    tree.printRange(tree.root, 1, 4);
    cout << endl;
    return 0;
}