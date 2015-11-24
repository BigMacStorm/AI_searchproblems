#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class board{
	public:
		vector<vector<int> > data;
		int moveCount;

		board(){
			vector<int> temp;
			temp.push_back(7);
			temp.push_back(2);
			temp.push_back(4);
			data.push_back(temp);
			temp[0] = 5;
			temp[1] = -1;
			temp[2] = 6;
			data.push_back(temp);
			temp[0] = 8;
			temp[1] = 3;
			temp[2] = 1;
			data.push_back(temp);
			moveCount = 0;
		}

		bool done(){
			int temp = 3;
			if(data[0][0] != -1 ||
				data[0][1] != 1 ||
				data[0][2] != 2){
				return false;
			}
			for(int x=1; x<3; x++){
				for(int y=0; y<3; y++){
					if(data[x][y] != temp) return false;
					temp++;
				}
			}
			cout << "Board done" << endl;
			return true;
		}

		void getEmpty(int& one, int& two){
			for(int x=0; x<3; x++){
				for(int y=0; y<3; y++){
					if(data[x][y] == -1){
						one = x;
						two = y;
						return;
					}
				}
			}
		}

		bool up(){
			int x, y;
			getEmpty(x,y);
			if(x==0) return false;
			swap(data[x][y], data[x-1][y]);
			moveCount++;
			return true;
		}

		bool down(){
			int x, y;
			getEmpty(x,y);
			if(x==2) return false;
			swap(data[x][y], data[x+1][y]);
			moveCount++;
			return true;
		}

		bool left(){
			int x, y;
			getEmpty(x,y);
			if(y==0) return false;
			swap(data[x][y], data[x][y-1]);
			moveCount++;
			return true;
		}

		bool right(){
			int x, y;
			getEmpty(x,y);
			if(y==2) return false;
			swap(data[x][y], data[x][y+1]);
			moveCount++;
			return true;
		}

};

int main(){
	queue<board> bfs;
	board current;
	board trash;
	set<vector<vector<int> > > storage;

	//seed queue and set with start
	bfs.push(current);
	storage.insert(current.data);

	while(!bfs.empty()){
		current = bfs.front();
		bfs.pop();

		if(current.done()){
			break;
		}

		trash = current;
		if(trash.up()){
			if(storage.find(trash.data) == storage.end()){
				storage.insert(trash.data);
				bfs.push(trash);
			}
			trash = current;
		}
		if(trash.down()){
			if(storage.find(trash.data) == storage.end()){
				storage.insert(trash.data);
				bfs.push(trash);
			}
			trash = current;
		}
		if(trash.left()){
			if(storage.find(trash.data) == storage.end()){
				storage.insert(trash.data);
				bfs.push(trash);
			}
			trash = current;
		}
		if(trash.right()){
			if(storage.find(trash.data) == storage.end()){
				storage.insert(trash.data);
				bfs.push(trash);
			}
			trash = current;
		}
	}

	cout << endl << current.moveCount << endl;
}