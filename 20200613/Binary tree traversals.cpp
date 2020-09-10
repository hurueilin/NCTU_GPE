#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};
static int preorderIndex;


node* newNode(char data){
    node* ptr = new node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    
    return ptr;
}

int searchInorder(char target, vector<char> &inorder){
    for(int i=0; i<inorder.size(); i++){
        if(target == inorder[i])
            return i;
    }
    return -1;
}

node* buildTree(int left, int right, vector<char> &preorder, vector<char> &inorder){
    if(left > right)
        return NULL;
    else{
        preorderIndex++;
        char data = preorder[preorderIndex];

        if(left == right) // this node has no child
            return newNode(data);

        int k = searchInorder(data, inorder);
        node* root = newNode(data);
        root->left = buildTree(left, k-1, preorder, inorder);
        root->right = buildTree(k+1, right, preorder, inorder);

        return root;
    }
}

void postorderTraversal(node* root, vector<char> &postorder){
    if(root != NULL){
        postorderTraversal(root->left, postorder);
        postorderTraversal(root->right, postorder);
        postorder.push_back(root->data);
    }
}


int main(){
    int caseNum;
    cin>>caseNum;
    while(caseNum--){
        int nodeNum;
        cin>>nodeNum;

        vector<char> preorder;
        vector<char> inorder;
        char c;
        for(int i=0; i<nodeNum; i++){
            cin>>c;
            preorder.push_back(c);
        }
        for(int i=0; i<nodeNum; i++){
            cin>>c;
            inorder.push_back(c);
        }
        

        preorderIndex = -1; // init
        node* TreeRoot = buildTree(0, nodeNum-1, preorder, inorder);
        
        vector<char> postorder;
        postorderTraversal(TreeRoot, postorder);
        for(int i=0; i<nodeNum; i++){
            cout<<postorder[i];
            if(i != nodeNum-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}