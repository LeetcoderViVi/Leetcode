class Solution {
public:
	int row,col;
	
	bool dfs(vector<vector<char>> &board,string word, int x,int y,int idx)
	{
		if(idx>word.size()-1)
			return true;
		const int xy[2][4]={1,0,-1,0,0,1,0,-1};
		int dx,dy;
		board[x][y] = '\1';
		for(int k=0;k<4;k++)
		{
			dx = x+xy[0][k];
			dy = y+xy[1][k];
			if(dx<0||dy<0||dx>=row||dy>=col)
				continue;
			if(board[dx][dy]!=word[idx])
				continue;
			else
				if(dfs(board,word,dx,dy,idx+1))
					return true;
		}
		board[x][y] = word[idx-1];
		return false;
		
	}

    bool exist(vector<vector<char> > &board, string word) {
		if(word.size()==0) return false;
		row = board.size();
		col = board[0].size();
		if(row==0||col==0) return false;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				if(board[i][j]==word[0])
					if(dfs(board,word,i,j,1))
						return true;
			}
			return false;
    }
};
