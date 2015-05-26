//Hash map: key:(target - nums[i]), value:the index of nums[i];
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> uoMap;
		vector<int> res;
		for(int i=0;i<nums.size();i++)
		{
			if(uoMap.find(nums[i]) == uoMap.end())
				uoMap.insert(pair<int,int>{target-nums[i],i+1});
			else
			{
				res.push_back(uoMap[nums[i]]);
				res.push_back(i+1);
				return res;
			}
		}
		return res;
    }
};
