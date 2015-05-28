class Solution {
public:
    unordered_set<int> old;
    bool isHappy(int n) {
        if(n<=0)
            return false;
        old.insert(n);
        int newN = 0;
        //decompose the number
        while(n != 0)
        {
            newN += (n%10)*(n%10);
            n = n/10;
        }
        
        if(newN == 1)
            return true;
        if(old.find(newN)!=old.end())
            return false;
        return isHappy(newN);
    }
};
