//DP!Fighting~lalalala~~~

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        int n = nums.size();
        int *maxRob = new int[n];
        maxRob[0] = nums[0];
        maxRob[1] = max(nums[0],nums[1]);
        for(int i =2;i<nums.size();i++)
            maxRob[i] = max(maxRob[i-2]+nums[i],maxRob[i-1]);
        return maxRob[n-1];
    }
};
