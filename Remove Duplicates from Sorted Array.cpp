class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i==0||nums[i] != nums[i-1]){
                nums[len++] = nums[i];
            }
        }
        
        return len;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        vector<int>::iterator vii;
        for(vii=nums.begin();vii!=nums.end()-1;)
        {
            if((*vii)==(*(vii+1)))
                vii = nums.erase(vii);
            else
                vii++;
        }
        return nums.size();
    }
};
