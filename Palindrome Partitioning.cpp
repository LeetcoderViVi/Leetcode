class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(!s.size()){
            return result;
        }
        
        vector<string> path;
        dfs(s,result,path,0);
        return result;
    }
    
    void dfs(string s, vector<vector<string>>& result, vector<string>& path, int index){
        if(index == s.size()){
            result.push_back(path);
        }
        
        for(int i = index; i < s.size();i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index,i-index+1));
                dfs(s,result,path,i + 1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};
