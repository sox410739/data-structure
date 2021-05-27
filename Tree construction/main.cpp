#include <iostream>

using namespace std;
typedef struct node {
    node *left;
    node *right;
    int data;
};
node* recursive(int* pre, int* in, int num);

int main()
{
    int num = 0;
    cin >> num;
    int pre[num];
    int in[num];
    for(int i=0;i<num;i++){
        cin >> pre[i];
    }
    for(int i=0;i<num;i++){
        cin >> in[i];
    }
    node *root = NULL;
    root = recursive(&pre[0], &in[0], num);
    node *k;
    k->data = 5;
    cout << k->data << endl;

    return 0;
}

node* recursive(int* pre, int* in, int num){
    node *temp = NULL;
    for(int i=0;i<num;i++){
        if(pre[0] == in[i]){
            temp->data = pre[0];
            if(i >= 1){
                temp->left = recursive(&pre[1], &in[0], i);
            }
            else{
                temp->left = NULL;
            }
            if(num-i-1 >= 1){
                temp->right = recursive(&pre[i+1], &in[i+1], num-i-1);
            }
            else{
                temp->right = NULL;
            }
        }
    }

    return temp;
}

