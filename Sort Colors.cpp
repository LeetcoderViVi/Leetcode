//First Solution. Quick Sort. It is not beautiful.%>_<%
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//change the nums to 0/2
		QuickSort(nums,0,nums.size()-1,1);
    }

	void QuickSort(vector<int>& nums,int x,int y,float kk)
	{
		int i =x,j = y,temp;
		while(i<=j)
		{
			while(i<=j&&nums[i]<=kk) i++;
			while(j>=i&&nums[j]>=kk) j--;
			if(i<j)
			{temp = nums[i];nums[i]=nums[j];nums[j]=temp;}
		}
		if(kk==1)
		{
			QuickSort(nums,x,i-1,0.5);
			QuickSort(nums,j+1,y,1.5);
		}
	}
};

//https://github.com/leetcoders/LeetCode/blob/master/SortColors.h
//This solution can pass the data only once! Very Beautiful!
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
		int zero = -1, two = nums.size(), i = two-1;
		while(zero<i)
		{
			switch(nums[i])
			{
			case 2:
				swap(nums[--two],nums[i--]);
				break;
			case 1:
				i--;
				break;
			case 0:
				swap(nums[++zero],nums[i]);
				break;
			}
		}
    }
};
