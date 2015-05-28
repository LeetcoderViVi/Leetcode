//https://leetcode.com/problems/count-primes/
//A good solution in the hint
class Solution {
public:
    bool isPrime(int n){
        if(n<=1)
            return true;
        for(int i = 2;i*i<n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        if(n<=0)
            return 0;
        char *tag = new char[n];
        int numP = 0;
        for(int i = 2;i<n;i++)
            tag[i] = 'y';
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for(int i=2;i*i<n;i++)
        {
            if(tag[i]=='n')
                continue;
            if(isPrime(i))
                for(int j = i*i;j<n;j += i)
                    tag[j] = 'n';
        }
        for(int i=2;i<n;i++)
            if(tag[i]=='y')
                numP+=1;
        return numP;
    }
};
