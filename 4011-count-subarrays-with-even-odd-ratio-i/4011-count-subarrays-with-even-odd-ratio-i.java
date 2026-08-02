class Solution {
    public int countRatioSubarrays(int[] nums, int a, int b) {
        int count = 0;
        int cutof = a/b;
        for(int i=0;i<nums.length;i++){
            int y = 0, x = 0;
            for(int j=i;j<nums.length;j++){
                if(nums[j]%2==0) x++;
                else y++;
                if(y>0 && x*b<=y*a) count++;
            }
        }  
        return count;
    }
}
/*
x
y 
*/