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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Condition to check if the two nodes are empty
        if(p == NULL && q == NULL){
            return true;
        }
        //Two Conditions to check if weather one of the nodes is empty or  not
        else if(p != NULL && q == NULL){
            return false;
        }
        else if(p == NULL && q != NULL){
            return false;
        }
        //Recursively calling the isSameTree() function to check if the subtrees are equal or not
        else{
            if (p->val == q->val && isSameTree(p->left, q->left)&& isSameTree(p->right, q->right)){
                return true;
            }
            else{
                return false;
            }
        }
    }
};


void test_case1(){
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int tree1[3] = {1,2,3} , tree2[3] = {1,2,3};
    for(int i=0 ; i<3 ;i++){
        root1 = Insert(root1 , tree1[i]);
        root2 = Insert(root2 , tree2[i]);
    }
    cout << "Input: p = {1,2,3}, q = {1,2,3} " << endl;
    Solution s1;
    if(s1.isSameTree(root1 , root2)){
       cout << "Output: True" <<endl;
       }
    else{
        cout << "Output: False" << endl;
    }
}


void test_case2(){
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int tree1[2] = {1,2} , tree2[3] = {1,NULL,2};
    for(int i=0 ; i<3 ;i++){
        root1 = Insert(root1 , tree1[i]);
        root2 = Insert(root2 , tree2[i]);
    }
    cout << "Input: p = {1,2}, q = {1,null,2} " << endl;
    Solution s1;
    if(s1.isSameTree(root1 , root2)){
       cout << "Output: True" << endl;
       }
    else{
        cout << "Output: False" << endl;
    }
}

void test_case3(){
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int tree1[3] = {1,2,1} , tree2[3] = {1,1,2};
    for(int i=0 ; i<3 ;i++){
        root1 = Insert(root1 , tree1[i]);
        root2 = Insert(root2 , tree2[i]);
    }
    cout << "Input: p = {1,2,1}, q = {1,1,2} " << endl;
    Solution s1;
    if(s1.isSameTree(root1 , root2)){
       cout << "Output: True" << endl;
       }
    else{
        cout << "Output: False" << endl;
    }
}


void test_case4(){
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int tree1[6] = {9,8,3,4,1,6} , tree2[6] = {9,8,3,4,1,6};
    for(int i=0 ; i<6 ;i++){
        root1 = Insert(root1 , tree1[i]);
        root2 = Insert(root2 , tree2[i]);
    }
    cout << "Input: p = {9,8,3,4,1,6}, q = {9,8,3,4,1,6} " << endl;
    Solution s1;
    if(s1.isSameTree(root1 , root2)){
       cout << "Output: True" << endl;
       }
    else{
        cout << "Output: False" << endl;
    }
}
//A test case that enables the user to enter the tree by himself
void test_case5(){
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int n1 , n2;
    cout << "Enter the number of elements in first tree: ";
    cin >> n1;
    int tree1[n1];
    cout << "Enter the elements of the first tree: " << endl;
    for(int i=0 ; i<n1;i++){
        cin >> tree1[i];
    }
    cout << "Enter the number of elements in second tree: ";
    cin >> n2;
    int tree2[n2];
    cout << "Enter the elements of the second tree: " << endl;
    for(int i=0 ; i<n2;i++){
        cin >> tree2[i];
    }
    for(int i=0 ; i<n1 ;i++){
        root1 = Insert(root1 , tree1[i]);
    }
    for(int i=0 ; i<n2 ;i++){
        root2 = Insert(root2 , tree2[i]);
    }
    cout << "Input: p = {";
    for(int i = 0 ; i<n1 ; i++){
        cout << tree1[i];
        if(i != n2-1){
            cout << ",";
        }
    }
    cout << "}";
    cout << " q = {";
    for(int i = 0 ; i<n2 ; i++){
        cout << tree2[i];
        if(i != n2-1){
            cout << ",";
        }
    }
    cout << "}" << endl;

    Solution s1;
    if(s1.isSameTree(root1 , root2)){
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
