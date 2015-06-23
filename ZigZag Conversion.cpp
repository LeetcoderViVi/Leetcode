//Note: How to control the direct

class Solution {
public:
    string convert(string s, int numRows) {
        if (s == "" || numRows == 1) return s;
        vector<string> vecstr(numRows);
        string res;
        int bounce = 0, direct = 1;
        for (int i = 0; i<=s.size()-1; ++i) {
            vecstr[bounce].push_back(s[i]);
            if (bounce == numRows-1) direct = -1;
            else if (bounce == 0) direct = 1;
            bounce += direct;
        }
        for (int i = 0; i<=numRows-1; ++i) res += vecstr[i];
        return res;
    }
};
