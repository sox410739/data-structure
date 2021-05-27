#include <iostream>
#include <stack>

using namespace std;

struct operat{
    char fix;
    int icp;
    int isp;
};

int main()
{
    string input = "";
    string outcome = "";
    cin >> input;
    stack<struct operat> postfix;
    for(int i=0;i<input.size();i++){
        if(input[i] == '+' || input[i] == '-'){
            struct operat temp = {input[i], 12, 12};
            if(postfix.empty() || postfix.top().isp<temp.icp){
                postfix.push(temp);
            }
            else{
                while(!postfix.empty() && postfix.top().isp>=temp.icp){
                    outcome = outcome + postfix.top().fix;
                    postfix.pop();
                }
                postfix.push(temp);
            }
        }
        else if(input[i] == '*' || input[i] == '/' || input[i] == '%'){
            struct operat temp = {input[i], 13, 13};
            if(postfix.empty() || postfix.top().isp<temp.icp){
                postfix.push(temp);
            }
            else{
                while(!postfix.empty() && postfix.top().isp>=temp.icp){
                    outcome = outcome + postfix.top().fix;
                    postfix.pop();
                }
                postfix.push(temp);
            }
        }
        else if(input[i] == '('){
            struct operat temp = {input[i], 20, 0};
            if(postfix.empty() || postfix.top().isp<temp.icp){
                postfix.push(temp);
            }
            else{
                while(!postfix.empty() && postfix.top().isp>=temp.icp){
                    outcome = outcome + postfix.top().fix;
                    postfix.pop();
                }
                postfix.push(temp);
            }
        }
        else if(input[i] == ')'){
            while(postfix.top().fix != '('){
                outcome = outcome + postfix.top().fix;
                postfix.pop();
            }
            postfix.pop();
        }
        else{
            outcome = outcome + input[i];
        }
    }
    while(!postfix.empty()){
        if(postfix.top().fix != '('){
           outcome = outcome + postfix.top().fix;
            postfix.pop();
        }
    }
    cout << outcome << endl;

    return 0;
}
