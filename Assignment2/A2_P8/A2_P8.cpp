#include <iostream>
using namespace std;
#define COUNT 10

struct node
{
    char value;
    node *left, *right;
    node(char x)
    {
        value = x;
        left = right = 0;
    }
};
node *newnode(char x)
{
    node *n = new node(x);
    return (n);
}
static int preindex = 0;

int search(string inorder, char value, int start, int end) // return the place of the value from in order
{
    int i;
    for (i = start; i < end; i++)
    {
        if (inorder[i] == value)
        {

            return i;
        }
    }
    return i;
}
// build a tree from the pre and in order
node *tree(string preorder, string inorder, int start, int end)
{
    if (start > end) // check end
    {
        return NULL;
    }
    if (preindex >= preorder.size()) // check index
    {
        preindex = 0;
    }

    node *n = newnode(preorder[preindex++]); // make new child
    if (start == end)                        // check same start and end
    {
        return n;
    }
    int index = search(inorder, n->value, start, end);   // return index of char
    n->left = tree(preorder, inorder, start, index - 1); // build left tree
    n->right = tree(preorder, inorder, index + 1, end);  // build right tree
    return n;
}

void printTree(node *root, int distance)
{
    if (root == NULL)
        return;

    distance += COUNT; // increase distance between blocks

    // access right child recursivly
    printTree(root->right, distance);

    // count
    cout << endl;
    for (int i = COUNT; i < distance; i++)
        cout << " ";
    cout << root->value << endl;

    // access left child recursivly
    printTree(root->left, distance);
}

void print(node *root)
{
    printTree(root, 0);
}

void postorder(node *root) // print postorder
{
    if (root == 0)
    {
        return;
    }
    postorder(root->left);      // print left first
    postorder(root->right);     // print right
    cout << root->value << " "; // print value
}
void printPostOrder(string preorder, string inorder)
{
    node *n = tree(preorder, inorder, 0, preorder.size() - 1);
    postorder(n);
    cout << endl;
    print(n);
}

int main()
{
    // test case 1
    /*
                           A
            B                       C
        F       G
    */
    cout << "case number 1 :";
    printPostOrder("ABFGC", "FBGAC");
    cout << endl;

    // test case 2
    /*
                          A
           B                       C
       F       G
   */
    cout << "case number 2 :";
    printPostOrder("ABCDG", "BADCG");
    cout << endl;

    // test case 3
    /*
                    A
                             B
                        C         D
                           E
   */
    cout << "case number 3 :";
    printPostOrder("ABCED", "ACEBD");
    cout << endl;

    // // test case 4
    /*
                 A
            B       C
       E                D
   */
    cout << "case number 4 :";
    printPostOrder("ABECD", "EBACD");
    cout << endl;

    // test case 5
    /*
                          A
           B
       C       D
     E
   */
    cout << "case number 5 :";
    printPostOrder("ABCED", "ECBDA");
    cout << endl;
}
