//Note:
//1.VIP.table[s[cur]] store the location of s[cur](=cur)
//2.VIP.Judge:table[s[cur]]>=start?
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if(len<=1)
			return len;
        //intit the table
		int table[256];
		for(int i=0;i<256;i++)
			table[i] = -1;
		//scan the string s
		int start = 0,maxLen = 0,cur = 0;
		while(len>cur)
		{
			if(table[s[cur]]>=start)
				start = table[s[cur]] + 1;
			if(maxLen<(cur-start+1))
					maxLen = cur - start +1;
			table[s[cur]] = cur;
			cur++;
		}
		return maxLen;
    }
};
