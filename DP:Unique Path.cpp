class Solution {
public:
    int uniquePaths(int m, int n) {
        //valid?
        if(m<=0 || n<=0){
            return 0;
        }
        else if(m == 1 || n == 1){
            return 1;
        }
        
        //init
        vector<vector<int>> path(m, vector<int>(n,1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        
        return path[m - 1][n - 1];
    }
};