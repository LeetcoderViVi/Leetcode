class Solution {
public:
	void DF(vector<vector<char>>& board, int x,int y)
	{
		int a[4][2]={1,0,-1,0,0,1,0,-1};
		int dx,dy;
		board[x][y] = 'v';
		for(int i=0;i<4;i++)
		{
			dx = x+a[i][0];
			dy = y+a[i][1];
			if(dx<0||dy<0||dx>=board.size()||dy>=board[x].size())
				continue;
			if(board[dx][dy]=='o')
				DF(board,dx,dy);
		}

	}
    void solve(vector<vector<char>>& board) {
		//find the 'o's on edges
		for(int i=0;i<board.size();i++)
		{
			if(i==0||i==board.size()-1)
			{
				for(int j=0;j<board[i].size();j++)
					if(board[i][j]=='o')
						DF(board,i,j);
			}
			else
			{
				if(board[i][0]=='o')
					DF(board,i,0);
				if(board[i][board[i].size()-1]=='o')
					DF(board,i,board[i].size()-1);
			}
		}

		//change the rest 'o's to 'x's, 'v's to 'o's
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[i].size();j++)
			{
				if(board[i][j]=='o')
					board[i][j] = 'x';
				if(board[i][j]=='v')
					board[i][j] = 'o';
			}
    }
};
