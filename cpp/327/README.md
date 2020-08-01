# 327. Count of Range Sum

## Idea
Binary Indexed Tree.

## Complexity
Time: O(NlogN)  
Space: O(N)  

## C++
```C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    
    vector<int> c;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int pos) {
        for(pos += 1; pos < c.size(); pos += lowbit(pos))
            c[pos] += 1;
    }
    
    int prefix(int pos) {
        int res = 0;
        for(pos += 1; pos >= 1; pos -= lowbit(pos))
            res += c[pos];
        return res;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = static_cast<int>(nums.size());
        c = vector<int>(n + 1);
        
        vector<int64_t> sums(n);
        for(int64_t i = 0; i < n; ++i)
            sums[i] = nums[i] + (i == 0 ? 0 : sums[i - 1]);
        
        sort(sums.begin(), sums.end());
        
        int res = 0;
        int64_t sum = 0;
        for(int i : nums) {
            sum += i;
            int l = lower_bound(sums.begin(), sums.end(), sum - upper) - sums.begin();
            int r = upper_bound(sums.begin(), sums.end(), sum - lower) - sums.begin();
            
            res += (r == 0 ? 0 : prefix(r - 1)) - (l == 0 ? 0 : prefix(l - 1));
            res += lower <= sum && sum <= upper;    
            
            int s = lower_bound(sums.begin(), sums.end(), sum) - sums.begin();
            add(s);
        }
        return res;
    }
};
```