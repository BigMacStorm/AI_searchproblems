#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int position[N];

bool legal(int number, int row){
	for (int i = 0; i < number; i++)
	{
		int check = position[i];

		if (check == row ||
			check == row - (number - i) || 
			check == row + (number - i))
			return false;
	}
	return true;
}

void recurse(int sent){
	if (sent == N){
		cout << "Valid board: ";
		for (int x = 0; x < N; x++)
			cout << position[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (legal(sent, i))
			{
				position[sent] = i;
				recurse(sent + 1);
			}
		}
	}
}

int main()
{
	recurse(0);

	return 0;
}