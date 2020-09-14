class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int a[n];
        a[0]=nums[0];
        a[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
            a[i]=max(nums[i]+a[i-2],a[i-1]);
        return a[n-1];
    }
};

// O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int incl=nums[0],excl=0;
        for(int i=1;i<nums.size();i++){
            int old_excl=excl;
            excl=max(incl,old_excl);
            incl=max(incl,old_excl+nums[i]);
        }
        return max(excl,incl);
    }
};
