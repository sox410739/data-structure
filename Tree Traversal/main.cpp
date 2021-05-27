#include <iostream>

using namespace std;
void print(int current, int number, int* tree);

int main()
{
    int number = 0;
    int current = 1;
    cin >> number;
    int tree[number];
    for(int i=0;i<number;i++){
        cin >> tree[i];
    }
    print(current, number, &tree[0]);
    if(tree[0] == -1){
        cout << "Empty tree!!";
    }

    return 0;
}

void print(int current, int number, int* tree){
    if(current*2 <= number){
        print(2*current, number, &tree[0]);
    }
    if(current*2+1 <= number){
        print(2*current+1, number, &tree[0]);
    }
    if(tree[current-1] != -1){
        cout << tree[current-1] << " ";
    }
}
