class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*if(numRows==0)
			return;*/
	vector<vector<int>> vvi;
	vector<int> vi;
	for(int i=1;i<=numRows;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1||j==i)
				vi.push_back(1);
			else
				vi.push_back(vvi[i-2][j-2]+vvi[i-2][j-1]);
		}
		vvi.push_back(vi);
		vi.clear();
	}
	return vvi;
    }
};
