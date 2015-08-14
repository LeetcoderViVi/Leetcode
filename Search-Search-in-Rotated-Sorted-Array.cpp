class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[i] <= A[mid])
            {
                if (A[i] <= target && target < A[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > nums[start]){
                if((target<nums[mid])&&(target>=nums[start])){
                    end = mid;
                }
                else{
                    start = mid;
                }
            }
            else{
                if((target>nums[mid])&&(target <= nums[end])){
                    start = mid;
                }
                else{
                    end = mid;
                }
            }
        }
        
        if(nums[start] == target){
            return start;
        }
        else if(nums[end] == target){
            return end;
        }
        
        return -1;
    }
    
};
