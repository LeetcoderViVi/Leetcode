class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        int leftBound = -1, rightBound = -1;
        
        //left bound
        while(start + 1 < end)
        {
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                end = mid;
            }
            else if(nums[mid] < target){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        if(nums[start] == target){
            leftBound = start;
        }
        else if(nums[end] == target){
            leftBound = end;
        }
        else{
            return vector<int>{-1,-1};
        }
        
        //right bound
        start = 0;
        end = nums.size()-1;
        while(start + 1 < end)
        {
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                start = mid;
            }
            else if(nums[mid] < target){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        if(nums[end] == target){
            rightBound = end;
        }
        else if(nums[start] == target){
            rightBound = start;
        }
        else{
            return vector<int>{leftBound,leftBound};
        }
        
        return vector<int>{leftBound,rightBound};
    }
};
