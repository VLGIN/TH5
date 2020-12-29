#include <bits/stdc++.h>
using namespace std;

int random(int L, int H){
	int temp = (rand()<<16|rand());
	temp = (temp>0)? temp: -temp;
	return temp% (H-L+1) + L;
}

int main(int argc, char** argv){
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
	freopen("LIS.inp", "w", stdout);
	int n, m;
	int amax = 1000;
	for (int t = 0; t<3; t++){
		n = random(8, 20);
		m = random(n-1, n * (n-1) / 2);
		cout << n <<" "<< m<< endl;
		map<pair<int,int>, int> edges;
		for (int i = 1; i <= m; ++i) {
			int x = random(1, n);
			int y = random(1, n);
			while(edges[{x, y}] == 1 || x == y){
				x = random(1, n);
				y = random(1, n);
			}
			edges[{x, y}] = 1;
			cout<<x<<" "<<y<<" "<<random(1, amax)<<endl;
		}
	}
}