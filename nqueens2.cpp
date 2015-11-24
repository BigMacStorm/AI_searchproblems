#include <iostream>
#include <algorithm>

using namespace std;

const int N = 14;
int counter = 0;

bool done(int state[N]){
	int check = 1;
	for(int x=0; x<N-1; x++){
		//check down right
		for(int y=x+1; y<N; y++){
			if(state[y] == state[x]+check){
				return false;
			}
			if(state[y] == state[x]-check){
				return false;
			}
			check++;
		}
		check = 1;
	}
	return true;
}

void print(int state[N]){
	cout << "Valid Board: ";
	for(int x=0; x<N; x++){
		cout << state[x] << " ";
	}
	cout << endl;
	counter++;
}


void solve(){
	int state[N];
	for(int x=0; x<N; x++){
		state[x] = x;
	}
	while(next_permutation(state, state+N)){
		if(done(state)){
			print(state);
		}
	}
}

int main()
{
	solve();
	cout << counter << endl;

	return 0;
}