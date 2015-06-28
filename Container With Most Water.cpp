//Time Limit Exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> container;
        if(height.size()<=1)
            return 0;
        if(height.size()==2)
            return min(height[1],height[0]);
        for(int i=0;i<height.size()-1;i++)
            for(int j=i+1;j<height.size();j++)
                container.push_back(min(height[i],height[j])*(j-i));
        //find the max area
        int max = 0;
        for(int i=0;i<container.size();i++)
            if(container[i]>max)
                max = container[i];
        return max;
    }
};
