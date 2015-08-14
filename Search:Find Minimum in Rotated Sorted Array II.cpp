class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};


class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int size = num.size();
        int left = 0;
        int right = size - 1;
        while (left < right && num[left] >= num[right]) {
            int mid = (left + right) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else if (num[mid] < num[left]) {
                right = mid;
            } else {
                ++left;
            }
        }
        return num[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        
        while((start+1<end)&&(nums[start]>=nums[end])){
            mid = start + (end - start)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if((nums[mid]>nums[end])){
                start = mid;
            }
            else if(nums[mid]<nums[end]){
                end = mid;
            }
            else{
                start++;
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
