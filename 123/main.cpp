#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	const int len = 6;
	long num[len + 1] = { 1 };
    /*for(int i=0;i<=len;i++){
        cout << num[i] << " ";
    }
    cout << endl;*/
	for (int i = 1; i <= len; i++){
		for (int j = i; j <= len; j++)
			num[j] = num[j] + num[j - i];
	}
	for (int i = 0; i <= len; i++)
		cout << i << " " << num[i] << endl;
	return 0;
}
