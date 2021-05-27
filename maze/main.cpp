#include <iostream>

using namespace std;

struct Road{
    int row = 0;
    int col = 0;
};

struct Direction{
    int direct = 0;
    int point = 8;
    bool D0 = false;
    bool D1 = false;
    bool D2 = false;
    bool D3 = false;
    bool D4 = false;
    bool D5 = false;
    bool D6 = false;
    bool D7 = false;
};

struct Direction num(int *Map, int row, int col, int Max);
void mov(struct Direction temp, int* row, int* col);
void mov2(struct Direction temp, int* row, int* col);

int main()
{
    int row = 0;
    int column = 0;
    cin >> row >> column;
    int Map[row+2][column+2] = {1};
    struct Road road[row*column];
    int top = 0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=column;j++){
            cin >> Map[i][j];
        }
    }

    for(int i=0;i<row+2;i++){
        for(int j=0;j<column+2;j++){
            if(i==0 || j==0 || i==row+1 || j==column+1){
                Map[i][j] = 1;
            }
        }
    }
    Map[1][1] = 2;
    int Rtemp = 1;
    int Ctemp = 1;
    struct Direction temp;
    while(Rtemp!=row || Ctemp!=column){
        Map[row][column] = 0;
        temp = num(&Map[0][0], Rtemp, Ctemp, column+2);
        switch(temp.direct){
        case 0:
            while(Map[Rtemp][Ctemp] != 2){
                Map[Rtemp][Ctemp] = 1;
                top--;
                Rtemp = road[top].row;
                Ctemp = road[top].col;
                road[top].row = 0;
                road[top].col = 0;
            }
            break;
        case 1:
            Map[Rtemp][Ctemp] = 1;
            road[top].row = Rtemp;
            road[top].col = Ctemp;
            top++;
            mov(temp, &Rtemp, &Ctemp);
            break;
        default:
            Map[Rtemp][Ctemp] = 2;
            road[top].row = Rtemp;
            road[top].col = Ctemp;
            top++;
            if(Rtemp > Ctemp){
                mov2(temp, &Rtemp, &Ctemp);
            }
            else if(Rtemp < Ctemp){
                mov(temp, &Rtemp, &Ctemp);
            }
            else if(Map[Rtemp+1][Ctemp+1] == 0){
                mov(temp, &Rtemp, &Ctemp);
            }
            else{
                int UpRight = 0;
                int DownLeft = 0;
                for(int i=Rtemp;i<row+2;i++){
                    for(int j=Ctemp;j<column+2;j++){
                        if(i>j && Map[i][j]==0)
                            DownLeft = DownLeft + num(&Map[0][0], i, j, column + 2).point;
                        else if(i<j && Map[i][j]==0)
                            UpRight = UpRight + num(&Map[0][0], i, j, column + 2).point;
                    }
                }
                if(UpRight > DownLeft)
                    mov(temp, &Rtemp, &Ctemp);
                else
                    mov2(temp, &Rtemp, &Ctemp);
            }
            break;
        }
    }
    road[top].row = Rtemp;
    road[top].col = Ctemp;
    top++;
    for(int i=0;i<top;i++){
        if(i<top-1)
            cout << road[i].row <<" "<< road[i].col << endl;
        else
            cout << road[i].row <<" "<< road[i].col;
    }

    return 0;
}

struct Direction num(int *Map, int row, int col, int Max){
    struct Direction temp;
    if(Map[(row-1)*Max + col-1] == 0){
        temp.D7 = true;
        temp.direct++;
        temp.point = 7;
    }
    if(Map[(row-1)*Max + col] == 0){
        temp.D6 = true;
        temp.direct++;
        if(row > col)
            temp.point = 5;
        else if(row<col && temp.point>6)
            temp.point = 6;
    }
    if(Map[(row-1)*Max + col+1] == 0){
        temp.D4 = true;
        temp.direct++;
        if(row > col)
            temp.point = 3;
        else if(row<col && temp.point>4)
            temp.point = 4;
    }
    if(Map[row*Max + col-1] == 0){
        temp.D5 = true;
        temp.direct++;
        if(row < col)
            temp.point = 5;
        else if(row<col && temp.point>6)
            temp.point = 6;
    }
    if(Map[row*Max + col+1] == 0){
        temp.D2 = true;
        temp.direct++;
        if(row > col)
            temp.point = 1;
        else if(row<col && temp.point>2)
            temp.point = 2;
    }
    if(Map[(row+1)*Max + col-1] == 0){
        temp.D3 = true;
        temp.direct++;
        if(row < col)
            temp.point = 3;
        else if(row>col && temp.point>4)
            temp.point = 4;
    }
    if(Map[(row+1)*Max + col] == 0){
        temp.D1 = true;
        temp.direct++;
        if(row < col)
            temp.point = 1;
        else if(row>col && temp.point>2)
            temp.point = 2;
    }
    if(Map[(row+1)*Max + col+1] == 0){
        temp.D0 = true;
        temp.direct++;
        temp.point = 0;
    }

    return temp;
}

void mov2(struct Direction temp, int* row, int* col){
    if(temp.D0){
        *row = *row + 1;
        *col = *col + 1;
    }
    else if(temp.D2){
        *col = *col + 1;
    }
    else if(temp.D1){
        *row = *row + 1;
    }
    else if(temp.D4){
        *row = *row - 1;
        *col = *col + 1;
    }
    else if(temp.D3){
        *row = *row + 1;
        *col = *col - 1;
    }
    else if(temp.D6){
        *row = *row - 1;
    }
    else if(temp.D5){
        *col = *col - 1;
    }
    else if(temp.D7){
        *row = *row - 1;
        *col = *col - 1;
    }
}

void mov(struct Direction temp, int* row, int* col){
    if(temp.D0){
        *row = *row + 1;
        *col = *col + 1;
    }
    else if(temp.D1){
        *row = *row + 1;
    }
    else if(temp.D2){
        *col = *col + 1;
    }
    else if(temp.D3){
        *row = *row + 1;
        *col = *col - 1;
    }
    else if(temp.D4){
        *row = *row - 1;
        *col = *col + 1;
    }
    else if(temp.D5){
        *col = *col - 1;
    }
    else if(temp.D6){
        *row = *row - 1;
    }
    else if(temp.D7){
        *row = *row - 1;
        *col = *col - 1;
    }
}
