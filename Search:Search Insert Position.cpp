class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        
        //find the first number >= target
        while(start+1<end){
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
        if(nums[start] >= target){
            return start;
        }
        else if(nums[end] >= target){
            return end;
        }
        else{
            return end + 1;
        }
    }
};
