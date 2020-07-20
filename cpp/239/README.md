# 239. Sliding Window Maximum

## Idea
Maintain a deque.
The front element of the deque is the index of the current max element of the window.

## Complexity
Time: O(N)  
Space: O(N)

## C++
```C++
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            
            while(q.size() && i - q.front() >= k)
                q.pop_front();
            
            while(q.size() && nums[q.back()] <= nums[i])
                q.pop_back();
            
            q.push_back(i);
            
            if(i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        
        return res;
    }
};
```