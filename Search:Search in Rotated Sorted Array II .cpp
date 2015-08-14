class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return true;
        return false;
    }
    bool search_2(int A[], int n, int target) {
        if (A == NULL) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) /2;
            if (A[mid] == target) return true;
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]) {
               if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                } 
            } else {
                if (A[mid] == A[right]) {
                    ++left, --right;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
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
                    if(nums[start] == nums[end])
                    {
                        start--;
                        end ++;
                    }
                    else{
                        end = mid;
                    }
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
