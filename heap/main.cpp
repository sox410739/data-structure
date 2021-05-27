#include <iostream>
#include <queue>
#include <stack>

using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};
struct Node* newNode(int value);
struct Node* insertValue(struct Node* root, struct Node* temp, queue<Node*>& q);
void heap(struct Node* n);
void levelOrder(struct Node* root);
void bottonUp(struct Node* root);
void compare(struct Node* n);

int main()
{
    int num = 0;
    cin >> num;
    Node* root1 = NULL;
    Node* root2 = NULL;
    queue<Node*> q1, q2;
    for(int i=0;i<num;i++){
        int temp;
        cin >> temp;
        struct Node* t1 = newNode(temp);
        struct Node* t2 = newNode(temp);
        root1 = insertValue(root1, t1, q1);
        root2 = insertValue(root2, t2, q2);
        heap(t1);
    }
    bottonUp(root2);
    levelOrder(root1);
    cout << endl;
    levelOrder(root2);

    return 0;
}

struct Node* newNode(int value){
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}

struct Node* insertValue(struct Node* root, struct Node* temp, queue<Node*>& q){
    if(root == NULL){
        root = temp;
    }
    else if(q.front()->left == NULL){
        q.front()->left = temp;
        temp->parent = q.front();
    }
    else{
        q.front()->right = temp;
        temp->parent = q.front();
        q.pop();
    }
    q.push(temp);

    return root;
}

void heap(struct Node* n){
    Node* cur = n;
    while(cur->parent != NULL && cur->data > cur->parent->data){
        int temp = cur->data;
        cur->data = cur->parent->data;
        cur->parent->data = temp;
        cur = cur->parent;
    }
}

void levelOrder(struct Node* root){
    queue<Node*> n;
    n.push(root);
    while(!n.empty()){
        cout << n.front()->data;
        if(n.front()->left != NULL){
            n.push(n.front()->left);
        }
        if(n.front()->right != NULL){
            n.push(n.front()->right);
        }
        n.pop();
        if(!n.empty()){
            cout << " ";
        }
    }
}

void bottonUp(struct Node* root){
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        s.push(q.front());
        if(q.front()->left != NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right != NULL){
            q.push(q.front()->right);
        }
        q.pop();
    }
    while(!s.empty()){
        struct Node* temp = s.top();
        compare(temp);
        s.pop();
    }
}

void compare(struct Node* n){
    if(n->left == NULL && n->right == NULL){
        return;
    }
    if(n->right == NULL){
        if(n->left->data > n->data){
            int temp = n->left->data;
            n->left->data = n->data;
            n->data = temp;
        }
    }
    else{
        if((n->left->data > n->right->data) && (n->right->data > n->data)){
            int temp = n->left->data;
            n->left->data = n->data;
            n->data = temp;
            compare(n->left);
        }
        else if((n->right->data > n->left->data) && (n->left->data > n->data)){
            int temp = n->right->data;
            n->right->data = n->data;
            n->data = temp;
            compare(n->right);
        }
        else if(n->left->data > n->data){
            int temp = n->left->data;
            n->left->data = n->data;
            n->data = temp;
            compare(n->left);
        }
        else if(n->right->data > n->data){
            int temp = n->right->data;
            n->right->data = n->data;
            n->data = temp;
            compare(n->right);
        }
    }
}
