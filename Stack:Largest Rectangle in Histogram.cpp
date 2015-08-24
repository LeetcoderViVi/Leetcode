class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        if(height.size() == 0){
            return 0;
        }
        
        int sum = 0;
        stack<int> heightStack;
        
        for(int i = 0; i <= height.size();i++){
            int cur = (i == height.size())?-1:height[i];
            while(!heightStack.empty() && height[heightStack.top()] > cur){
                int h = height[heightStack.top()];
                heightStack.pop();
                int w = heightStack.empty()?i:(i - heightStack.top() - 1);
                sum = max(sum, h * w);
            }
            
            heightStack.push(i);
        }
        
        return sum;
    }
};
