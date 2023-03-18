#include <iostream>
using namespace std;

bool checkRow (int);
bool checkCol(int);
bool diagonalUR(int, int);
bool diagonalDR(int, int);
bool diagonalUL(int, int);
bool diagonalDL(int, int);
bool isValid(int, int);
bool solution();
void printBoard();


int board [8][8];

int main() {
	solution();
	printBoard();
	
	return 0;
}

bool checkRow (int row){
	for(int i=0; i<8; i++){
		
		if(board[row][i]==1){
			
			return false;
		}
	}
	return true;
}

bool checkCol(int col){
	for(int i=0; i<8;i++){
		
		if(board[i][col]==1){
			
			return false;
		}
	}
	return true;
}

bool diagonalUR (int row, int col){
	//Check diagonal Up-Right (UL) is available
	//The Limit is 0,8
	
	do{
		row=row-1;
		col=col+1;
		
		if(board[row][col]==1){
			return false;
		}
	}
	while(row>=0 && col<8);
	
	return true;
}

bool diagonalDR(int row, int col){
	//Check diagonal Down-Right (DL) is available
	//The limit is 8,8
	
	do{
		row=row+1;
		col=col+1;
		
		if(board[row][col]==1){
			return false;
		}
	}
	
	while(row<8 && col<8);
	
	return true;
}

bool diagonalUL (int row, int col){
	//Check diagonal Up- Left (UL) is available
	//The limit is 0,0
	do{
		row=row-1;
		col=col-1;
		if(board[row][col]==1){
			return false;
		}
	}
	while(row>=0 && col>=0);
	return true;
}

bool diagonalDL (int row, int col){
	//Check diagonal Down-Left (DL) is available
	//The limit is 7,0
	
	do{
		row=row+1;
		col=col-1;
		
		if(board[row][col]==1){
			return false;
		}
		
	}
	while(row<=7 && col>=0);
	return true;
}

bool isValid (int row, int col){
	
	return checkRow(row) && checkCol(col) && diagonalUR(row, col) && diagonalDR(row, col) && diagonalUL(row,col) && diagonalDL(row, col);
}

bool solution (){
		
		for(int row=0; row<8; row++){
			
			for(int col=0; col<8; col++){
				
				if(board[row][col]==0){
					
					if(isValid(row, col)){
						
						board[row][col]=1;					
						
						if(solution()==false){
							
							board[row][col]=0;
						}								
					}
				}
			}
		}
		if(checkRow(0)==false && checkRow(1)==false && checkRow(2)==false && checkRow(3)==false && checkRow(4)==false 
								&& checkRow(5)==false && checkRow(6)==false  && checkRow(7)==false){
			return true;
		}
		
		return false;
}

void printBoard(){
	
	for(int row=0; row<8; row++){
		
		for(int col=0; col<8;col++){
			
			cout<<" "<<board[row][col]<<" ";
			
		}
		cout<<endl;
	}
}
