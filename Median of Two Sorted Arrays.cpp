class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        //valid?
        if(m == 0){
            if(n&0x1){
                return nums2[n/2];
            }
            return (nums2[n/2-1] + nums2[n/2])/2.0;
        }
        if(n==0){
            if(m&0x1){
                return nums1[m/2];
            }
            return (nums1[m/2-1] + nums1[m/2])/2.0;
        }
        
        int i = 0, j = 0;
        int a = 0 ,b = 0;
        int min1 = 0, min2 = 0;
        
        for(int k = 0; k <= (m+n)/2; k++){
            a = (i == m)?INT_MAX:nums1[i];
            b = (j == n)?INT_MAX:nums2[j];
            
            if(a < b){
                i++;
            }
            else{
                j++;
            }
            min1 = min2;
            min2 = min(a,b);
        }
        
        if((m+n)&0x1){
            return min2;
        }
        else{
            return (min1+min2)/2.0;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // get the length of nums1 and nums2
        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        
        if(total&0x1)
            return findKth(nums1,0,m,nums2,0,n,total/2+1);
        else
            return (findKth(nums1,0,m,nums2,0,n,total/2)+findKth(nums1,0,m,nums2,0,n,total/2+1))*1.0/2;
    }
    
    int findKth(vector<int>& nums1,int m1,int m2,vector<int>& nums2,int n1,int n2,int k)
    {
        if((m2-m1)>(n2-n1))
            return findKth(nums2,n1,n2,nums1,m1,m2,k);
        if((m2-m1)==0||(m2-m1)<0)
            return nums2[k-1];
        if(k==1)
            return min(nums1[m1],nums2[n1]);
        int i = min(m1+k/2,m2);
        int j = n1+k-(i-m1);
        int a = nums1[i-1], b = nums2[j-1];
        if(a>b)
            return findKth(nums1,m1,m2,nums2,j,n2,k-j+n1);
        else if(a<b)
            return findKth(nums1,i,m2,nums2,n1,n2,k-i+m1);
        else
            return a;
    }
};
