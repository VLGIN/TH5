#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    while(n--){
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0)){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}