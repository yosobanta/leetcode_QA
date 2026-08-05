class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0,j=0;
        int length = 1;
        unordered_map<int,int> buckets;
        while(j<fruits.size()){
            buckets[fruits[j]]++;
            while(buckets.size()>2){
                buckets[fruits[i]]--;
                if(buckets[fruits[i]]==0) buckets.erase(fruits[i]);
                i++;
            }
            // if(bucket.len)
            length = max(length,j-i+1);
            j++;
        }
        return length;
    }
};