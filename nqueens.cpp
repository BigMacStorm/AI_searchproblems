#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int position[N];
int counter;

bool legal(int number, int row){
	for (int x = 0; x < number; x++){
		int check = position[x];

		if (check == row ||
			check == row - (number - x) || 
			check == row + (number - x))
			return false;
	}
	return true;
}

void recurse(int sent){
	if (sent == N){
		cout << "Valid board: ";
		for (int x = 0; x < N; x++)
			cout << position[x] << " ";
		cout << endl;
	}else{
		for (int x = 0; x < N; x++){
			if (legal(sent, x)){
				position[sent] = x;
				counter++;
				recurse(sent + 1);
			}
		}
	}
}

int main(){
	counter = 0;
	recurse(0);
	cout << counter << endl;

	return 0;
}