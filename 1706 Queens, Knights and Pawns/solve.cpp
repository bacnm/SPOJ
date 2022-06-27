#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define QUEEN 0
#define KNIGHT 1
#define PAWN 2
#define DANGER 3
#define SAFE 4

int board[1000][1000];

typedef struct Queens
{
	int x;
	int y;
} Queens;


void Danger(int x, int y)
{
	if( board[x][y] == SAFE)
		board[x][y] = DANGER;
}



int main()
{
	freopen("input.txt","r",stdin);

	int rows = 0, columns = 0;

	int  queens = 0,knights = 0, pawns = 0;
	int x = 0, y = 0;
	int count_board = 0;
	int count_safe = 0;

	cin >> rows >> columns;


	while( rows != 0 && columns != 0)
	{
		count_board++;
		/* Input data*/

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				board[i][j] = SAFE;
			}
		}


		cin >> queens;
		Queens *queens_arr = new Queens[queens];
		for (int i = 0; i < queens; ++i)
		{
			cin >> x >> y;
			queens_arr[i].x  = x - 1;
			queens_arr[i].y = y - 1;
			board[queens_arr[i].x][queens_arr[i].y] = QUEEN;
		}

		cin >> knights;
		for (int i = 0; i < knights; ++i)
		{
			cin >> x >> y;
			x--,y--;
			board[x][y] = KNIGHT;

			if(x-2 >= 0)
			{
				if( y-1 >= 0) Danger(x-2,y-1);
				if( y+1 < columns) Danger( x-2,y+1);
			}
			if(x-1 >= 0)
			{
				if( y-2 >= 0) Danger(x-1,y-2);
				if( y+2 < columns) Danger( x-1,y+2);
			}
			if(x+2 < rows)
			{
				if( y-1 >= 0) Danger(x+2,y-1);
				if( y+1 < columns) Danger(x+2,y+1);
			}
			if(x+1 < rows)
			{
				if( y-2 >= 0) Danger(x+1,y-2);
				if( y+2 < columns) Danger( x+1,y+2);
			}

		}

		cin >> pawns;
		for (int i = 0; i < pawns; ++i)
		{
			cin >> x >> y;
			x--,y--;
			board[x][y] = PAWN;
		}

		/* process queens data */
		
		for (int i = 0; i < queens; ++i)
		{
			x = queens_arr[i].x;
			y = queens_arr[i].y;
			while( y > 0)
			{
				y--;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;					
				
			}
			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( y < (columns-1))
			{
				y++;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}
			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( (x> 0))
			{
				x--;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}
			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( x < (rows-1))
			{
				x++;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}
			x = queens_arr[i].x;
			y = queens_arr[i].y;
			while( x > 0 && y > 0 )
			{
				x--;
				y--;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}

			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( x < (rows - 1) && y < ( columns -1 ))
			{
				x++;
				y++;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}

			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( x > 0 && y < ( columns -1 ))
			{
				x--;
				y++;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}

			x = queens_arr[i].x;
			y = queens_arr[i].y;

			while( x < (rows - 1) && y > 0 )
			{
				x++;
				y--;
				if (board[x][y] == SAFE || board[x][y] == DANGER ) Danger(x,y);
				else break;
			}

		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if( board[i][j] == SAFE)
				{
					count_safe++;
				}
					
			}
		}

		cout<<"Board "<< count_board<<" has "<< count_safe<< " safe squares."<<endl;
		delete []queens_arr;
		count_safe = 0;
		cin >> rows >> columns;

	}

	return 0;
}