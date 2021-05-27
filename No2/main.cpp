#include <iostream>

using namespace std;

class Nzero{
private:
    int _row = 0;
    int _column = 0;
    int _value = 0;
public:
    Nzero();
    int getRow();
    int getCol();
    int getValue();
    void setRow(int);
    void setCol(int);
    void setValue(int);
};

int main()
{
    int row1, col1;
    int row2, col2;
    cin >> row1 >> col1;
    int temp = 0;
    Nzero arr1[50];
    Nzero arr2[50];
    Nzero Farr[50];
    int top1 = 0;
    int top2 = 0;
    int Ftop = 0;
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            cin >> temp;
            if(temp !=0){
                arr1[top1].setRow(i);
                arr1[top1].setCol(j);
                arr1[top1].setValue(temp);
                top1++;
            }
        }
    }
    cin >> row2 >> col2;
    for(int i=0;i<row2;i++){
        for(int j=0;j<col2;j++){
            cin >> temp;
            if(temp !=0){
                arr2[top2].setRow(i);
                arr2[top2].setCol(j);
                arr2[top2].setValue(temp);
                top2++;
            }
        }
    }
    for(int i=0;i<top1;i++){
        for(int j=0;j<top2;j++){
            if(arr1[i].getCol() == arr2[j].getRow()){
                Farr[Ftop].setRow(arr1[i].getRow());
                Farr[Ftop].setCol(arr2[j].getCol());
                Farr[Ftop].setValue(arr1[i].getValue() * arr2[j].getValue());
                Ftop++;
            }
        }
    }
    Ftop = 0;
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            if(j != 0){
                cout << " ";
            }
            if(Farr[Ftop].getRow()==i && Farr[Ftop].getCol()==j){
                cout << Farr[Ftop].getValue();
                Ftop++;
            }
            else{
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}

Nzero::Nzero(){
    _row = 0;
    _column = 0;
    _value = 0;
}

int Nzero::getRow(){
    return _row;
}

int Nzero::getCol(){
    return _column;
}

int Nzero::getValue(){
    return _value;
}

void Nzero::setRow(int row){
    _row = row;
}

void Nzero::setCol(int col){
    _column = col;
}

void Nzero::setValue(int val){
    _value = val;
}
