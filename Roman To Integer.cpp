class Solution {
public:
    int romanToInt(string s) {
		if(s.size()==0)
			return 0;
		unordered_map<char,int> hmsi;
		hmsi['M'] = 1000;
		hmsi['D'] = 500;
		hmsi['C'] = 100;
		hmsi['L'] = 50;
		hmsi['X'] = 10;
		hmsi['V'] = 5;
		hmsi['I'] = 1;
		int result = 0,i;
		for(i=0;i<s.size()-1;i++)
		{
			if(hmsi[s[i]]<hmsi[s[i+1]])
				result -= hmsi[s[i]];
			else
				result +=hmsi[s[i]];
		}
		result += hmsi[s[s.size()-1]];
		return result;
    }
};
