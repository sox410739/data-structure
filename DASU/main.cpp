#include <iostream>
#include <string>

using namespace std;
int CtoI(char a);
char ItoC(int i);
string bigAdd(string str1, string str2);
string bigMinus(string str1, string str2);
string bigMul(string str1, string str2);

int main()
{
    string input1, input2, operation;
    getline(cin, input1);
    getline(cin, input2);
    cout << bigAdd(input1, input2) << endl;
    cout << bigMinus(input1, input2) << endl;
    cout << bigMul(input1, input2) << endl;

    return 0;
}

string bigAdd(string str1, string str2){
    string temp = "";
    int carry = 0;
    while(str1.length() > str2.length()){
        str2 = '0' + str2;
    }
    for(int i=str1.length()-1;i>=0;i--){
        int a = CtoI(str1[i]);
        int b = CtoI(str2[i]);
        a = a + b + carry;
        if(a >= 10){
            a = a - 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        temp = ItoC(a) + temp;
    }
    if(carry == 1){
        temp = '1' + temp;
    }

    return temp;
}

string bigMinus(string str1, string str2){
    string temp = "";
    int carry = 0;
    while(str1.length() > str2.length()){
        str2 = '0' + str2;
    }
    for(int i=str1.length()-1;i>=0;i--){
        int a = CtoI(str1[i]);
        int b = CtoI(str2[i]);
        a = a - b + carry;
        if(a < 0){
            a = a + 10;
            carry = -1;
        }
        else{
            carry = 0;
        }
        temp = ItoC(a) + temp;
    }
    while(temp[0] == '0'){
        string a = "";
        for(int i=1;i<temp.length();i++){
            a = a + temp[i];
        }
        temp = a;
    }
    if(temp == ""){
        temp = "0";
    }

    return temp;
}

string bigMul(string str1, string str2){
    string temp = "";
    string mulTemp = "";
    int carry = 0;
    for(int j=str1.length()-1;j>=0;j--){
            int a = CtoI(str1[j]);
            int b = CtoI(str2[str2.length()-1]);
            a = a * b + carry;
            if(a >= 10){
                carry = a / 10;
                a = a % 10;
            }
            else{
                carry = 0;
            }
            temp = ItoC(a) + temp;
    }
    if(carry != 0){
            temp = ItoC(carry) + temp;
            carry = 0;
    }
    for(int i=str2.length()-2;i>=0;i--){
        for(int j=str1.length()-1;j>=0;j--){
            int a = CtoI(str1[j]);
            int b = CtoI(str2[i]);
            a = a * b + carry;
            if(a >= 10){
                carry = a / 10;
                a = a % 10;
            }
            else{
                carry = 0;
            }
            mulTemp = ItoC(a) + mulTemp;
        }
        if(carry != 0){
            mulTemp = ItoC(carry) + mulTemp;
            carry = 0;
        }
        for(int i=0;i<str2.length()-1-i;i++){
             mulTemp = mulTemp + '0';
        }
        temp = bigAdd(mulTemp, temp);
    }

    return temp;
}

int CtoI(char a){   //char to int
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

char ItoC(int i){      //int to char
    char temp;
    switch(i){
    case 0:
        temp = '0';
        break;
    case 1:
        temp = '1';
        break;
    case 2:
        temp = '2';
        break;
    case 3:
        temp = '3';
        break;
    case 4:
        temp = '4';
        break;
    case 5:
        temp = '5';
        break;
    case 6:
        temp = '6';
        break;
    case 7:
        temp = '7';
        break;
    case 8:
        temp = '8';
        break;
    case 9:
        temp = '9';
        break;
    }

    return temp;
}
