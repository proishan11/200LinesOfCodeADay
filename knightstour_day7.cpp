#include<bits/stdc++.h>
using namespace std;

#define N 8

int chess[N][N] = {0};

int moveX[] = {2,1,-1,-2,-2,-1,1,2};
int moveY[] = {1,2,2,1,-1,-2,-2,-1};

int SafeMove(int x, int y){
	return (x>=0 && x<N && y>=0 && y<N && chess[x][y]==0);
}

void printChess(){
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cout<<chess[i][j]<<"\t";
		cout<<endl;
	}
}

bool knightsTour(int x, int y, int ithMove){
	int nextX, nextY;
	if(ithMove==N*N) return true;
	for(int i=0; i<8; ++i){
		nextX = x + moveX[i];
		nextY = y + moveY[i];
		if(SafeMove(nextX, nextY)){
			chess[nextX][nextY] = ithMove;
			//if recursively tour completed then return true
			if(knightsTour(nextX, nextY, ithMove+1))
				return true;
			//else undo the move and try other moves
			else
				chess[nextX][nextY] = 0;
		}
	}
	return false;
}

int main(){
	//initiate backtracking algorithm
	chess[0][0]=1;
	printChess();
	if(knightsTour(0,0,1)){
		cout<<"The knights tour to cover all of the chess is\n";
		printChess();
	}
	else
		cout<<"No such tour possible\n";
}