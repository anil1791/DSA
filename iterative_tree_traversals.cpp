// C++ program for preorder traversals

#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

// Function to print preorder traversal
void printPreorder(struct Node* node)
{
    if (node == nullptr)
        return;

    // Deal with the node
    cout << node->data << " ";

    // Recur on left subtree
    printPreorder(node->left);

    // Recur on right subtree
    printPreorder(node->right);
}

void pre_in_post(Node *root){
    
    stack<Node*>st;
    map<Node*,int>mp;
    mp[root]=1;
    st.push(root);
    vector<int>pre;
     vector<int>in;
      vector<int>post;
    while(!st.empty()){
        Node * top = st.top();
        if(mp[top] == 1){
            pre.push_back(top->data);
            mp[top] =2;
            if(top->left){
                st.push(top->left);
                mp[top->left] = 1;
            }
        }
        else
        if(mp[top] == 2){
            in.push_back(top->data);
            mp[top] = 3;
            if(top->right){
                st.push(top->right);
                mp[top->right] = 1;
            }
        }
        else
            if(mp[top] == 3){
                post.push_back(top->data);
                mp.erase(top);
                st.pop();
            }
    }
    cout<<"preorder -> ";
    for(int x:pre){
        cout<<x<<" ";
    }cout<<endl;
    cout<<"inorder -> ";
    for(int x:in){
        cout<<x<<" ";
    }cout<<endl;
    cout<<"postorder -> ";
    for(int x:post){
        cout<<x<<" ";
    }cout<<endl;
    
}
  

// Driver code
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    pre_in_post(root);

    return 0;
}
