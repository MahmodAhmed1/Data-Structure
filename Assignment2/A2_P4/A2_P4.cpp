#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

// Function to create a new Node in heap
TreeNode* CreatNewNode(int val) {
	TreeNode* newNode = new TreeNode();
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Function To insert data in TreeNode, returns address of root node
TreeNode* Insert(TreeNode* root,int val) {
    //if tree is empty creates a new node
	if(root == NULL) {
		root = CreatNewNode(val);
		return root;
	}
	//A queue to store all the nodes that are currently being compared
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
	    TreeNode* current = Q.front();
	    Q.pop();
        // checks left subtree, inserts in left subtree if its empty.
        if(current->left == NULL) {
            current->left = Insert(current->left,val);
            return root;
        }
        //else is pushes its left child into the queue
        else{
            Q.push(current -> left);
        }
        // checks right subtree, insert in right subtree if its empty.
        if(current->right == NULL){
            current->right = Insert(current->right,val);
            return root;
        }
        //else is pushes its right child into the queue
        else{
            Q.push(current -> right);
        }
	}

}

class Solution {
    public:
    //function that checks if the two trees are the same
    bool isSymmetric(TreeNode* root){
    //Condition to check if the node is empty
    if(root == NULL) return true;
    //A queue to store the left and right nodes of every subtree
    queue<TreeNode*> Q;
    Q.push(root->left);
    Q.push(root->right);
    //two pointers one to point on each node
    TreeNode *l, *r;
    while(!Q.empty()){
        l = Q.front();
        Q.pop();
        r = Q.front();
        Q.pop();
        //Condition to check if the two nodes are empty
        if(l==NULL && r==NULL) continue;
        //Condition checks if the values of both nodes are equal or not
        if(l==NULL || r==NULL || l->val != r->val) return false;
        Q.push(l->left);
        Q.push(r->right);
        Q.push(l->right);
        Q.push(r->left);
            }
        return true;
        }
};

//Test cases

void test_case1(){
    TreeNode* root = NULL;
    int tree[7] = {1,2,2,3,4,4,3};
    for(int i=0 ; i<7 ;i++){
        root = Insert(root , tree[i]);
    }
    cout << "Input: root = {1,2,2,3,4,4,3}" << endl;
    Solution s1;
    if(s1.isSymmetric(root)){
       cout << "Output: True" <<endl;
       }
    else{
        cout << "Output: False" << endl;
    }
    cout <<endl;
}

void test_case2(){
    TreeNode* root = NULL;
    int tree[7] = {1,2,2,3,4,3,4};
    for(int i=0 ; i<7 ;i++){
        root = Insert(root , tree[i]);
    }
    cout << "Input: root = {1,2,2,3,4,3,4}" << endl;
    Solution s1;
    if(s1.isSymmetric(root)){
       cout << "Output: True" <<endl;
       }
    else{
        cout << "Output: False" << endl;
    }
    cout <<endl;
}

void test_case3(){
    TreeNode* root = NULL;
    int tree[7] = {1,2,2,NULL,3,NULL,3};
    for(int i=0 ; i<7 ;i++){
        root = Insert(root , tree[i]);
    }
    cout << "Input: root = {1,2,2,null,3,null,3}" << endl;
    Solution s1;
    if(s1.isSymmetric(root)){
       cout << "Output: True" <<endl;
       }
    else{
        cout << "Output: False" << endl;
    }
    cout <<endl;
}

void test_case4(){
    TreeNode* root = NULL;
    int tree[7] = {1,2,2,3,NULL,NULL,3};
    for(int i=0 ; i<7 ;i++){
        root = Insert(root , tree[i]);
    }
    cout << "Input: root = {1,2,2,3,null,null,3}" << endl;
    Solution s1;
    if(s1.isSymmetric(root)){
       cout << "Output: True" <<endl;
       }
    else{
        cout << "Output: False" << endl;
    }
    cout <<endl;
}

//A test case that enables the user to enter the tree by himself
void test_case5(){
    TreeNode* root = NULL;
    int n;
    cout << "Enter the number of elements the tree: ";
    cin >> n;
    int tree[n];
    cout << "Enter the elements of the tree: " << endl;
    for(int i=0 ; i<n;i++){
        cin >> tree[i];
    }
    for(int i=0 ; i<n ;i++){
        root = Insert(root , tree[i]);
    }
    cout << "Input: root = {";
    for(int i = 0 ; i<n ; i++){
        cout << tree[i];
        if(i != n-1){
            cout << ",";
        }
    }
    cout << "}" << endl;

    Solution s1;
    if(s1.isSymmetric(root)){
       cout << "Output: True" << endl;
       }
    else{
        cout << "Output: False" << endl;
    }
}

int main()
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
//  test_case5();
    return 0;
}
