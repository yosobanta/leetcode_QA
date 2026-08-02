class Solution {
    public int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public long maxPairStrength(int[] nums) {
        long maxi = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                long g = gcd(nums[i], nums[j]);
                long strength = (1L * nums[i] * nums[j]) / (g * g);
                maxi = Math.max(maxi, strength);
            }
        }
        return maxi;
    }
}