class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<0)
			return vector<int>();
		vector<int> vi(rowIndex+1,1);
		for(int i=0;i<=rowIndex;i++)
			for(int j=i-1;j>=1;j--)
				vi[j] += vi[j-1];
		return vi;
    }
};
