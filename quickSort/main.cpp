#include <iostream>
#include <string>

using namespace std;
int amountOfNumber(string temp);
void quickSort(int* arr, int num);
void SWAP(int* a, int* b);
void tran(int* arr, string input);
int AtoI(char a);

int main()
{
    string input = "";
    getline(cin, input);
    int num = amountOfNumber(input);
    int arr[num] = {0};
    tran(&arr[0], input);
    quickSort(&arr[0], num);
    for(int i=0;i<num-1;i++){
        cout << arr[i] << " ";
    }
    cout << arr[num-1];

    return 0;
}

int amountOfNumber(string temp){
    int counter = 0;
    for(int i=0;i<temp.length();i++){
        if(temp[i] == ' '){
            counter++;
        }
    }
    counter++;

    return counter;
}

void quickSort(int* arr, int num){
    if(num == 0){
        return;
    }
    int front = -1;
    int pivot = arr[num-1];
    for(int i=0;i<num-1;i++){
        if(arr[i] < pivot){
            front++;
            SWAP(&arr[front], &arr[i]);
        }
    }
    front++;
    SWAP(&arr[front], &arr[num-1]);
    quickSort(&arr[0], front);
    quickSort(&arr[front+1], num-front-1);
}

void SWAP(int* a, int* b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tran(int* arr, string input){
    int temp = 0;
    int top = 0;
    for(int j=0; j<input.length(); j++){
        if(input[j] == ' '){
            arr[top] = temp;
            top++;
            temp = 0;
        }
        else{
            temp = 10 * temp;
            temp = temp + AtoI(input[j]);
        }
    }
    arr[top] = temp;
}

int AtoI(char a){
    int temp = 0;
    switch(a){
    case '0':
        temp = 0;
        break;
    case '1':
        temp = 1;
        break;
    case '2':
        temp = 2;
        break;
    case '3':
        temp = 3;
        break;
    case '4':
        temp = 4;
        break;
    case '5':
        temp = 5;
        break;
    case '6':
        temp = 6;
        break;
    case '7':
        temp = 7;
        break;
    case '8':
        temp = 8;
        break;
    case '9':
        temp = 9;
        break;
    }

    return temp;
}
