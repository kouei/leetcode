# 307. Range Sum Query - Mutable

## Idea

Binary Indexed Tree (BIT)

## Complexity

Time:  
O(Qlog(N))  
  
Where Q is the number of queries.  

Space:  
O(N)

## C++
```C++
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class NumArray {
public:
    
    vector<int> c;
    vector<int> nums;
    int n;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    NumArray(vector<int>& A) {
        n = static_cast<int>(A.size());
        c.resize(n + 1);
        swap(A, nums);
        
        for(int i = 1; i <= n; ++i) {
            c[i] = nums[i - 1];
            for(int pos = i - 1; pos > i - lowbit(i); pos -= lowbit(pos)) {
                c[i] += c[pos];
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        for(int pos = i + 1; pos <= n; pos += lowbit(pos))
            c[pos] += diff;
    }
    
    int prefix(int x) {
        int res = 0;
        for(; x >= 1; x -= lowbit(x))
            res += c[x];
        return res;
    }
    
    int sumRange(int i, int j) {
        int start = i + 1;
        int end = j + 1;
        return prefix(end) - prefix(start - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
 ```