class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        
        while(start+1<end){
            mid = start + (end - start)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if((nums[mid]<nums[mid+1])&&(nums[mid]>nums[0])){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        if(nums[start]<nums[0]){
            return nums[start];
        }
        else if(nums[end]<nums[0]){
            return nums[end];
        }
        else{
            return nums[0];
        }
    }
};
