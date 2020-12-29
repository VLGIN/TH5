#include <bits/stdc++.h>

using namespace std;

int random(int a, int b){
    return rand();
}

int main(int argc, char** argv){
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    
    int n = random(1, 10);
    cout<<n<<endl;

    for (int i = 0; i<n; i++){
        cout<<random(1, 10)<<endl;
    }
}