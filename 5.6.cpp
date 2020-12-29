#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    else return 'A';
}

int main(){
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    char temp;
    while(n--){
        int a;
        cin >> a;
        temp = cal(a);
        if (temp == 'A') ++A;
        else if (temp == 'B') ++B;
        else if (temp == 'C') ++C;
        else if (temp == 'D') ++D;
        else ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}