/******************************************************************************
 * Idea:
 * Instead of transforming [1,1,...,1] to target,
 * try transforming target back to [1,1,...,1].
 * Always pick up the biggest value, and subtract 
 * the sum of other values from it.
 * 
 * Let D = max max value in target
 * 
 * Time:  
 * O(N) for build the heap
 * O(log(D)log(N)) for the while loop
 * 
 * Space:
 * O(N) for the heap
 * 
 * Supplementary Test Case:
 * [1,1,2]
 * [1, 1000000000]
 * [5, 50]
 ******************************************************************************/

static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        int64_t total = 0;
        
        priority_queue<int> heap;
        for (auto i : target) {
            total += i;
            heap.push(i);
        }
        
        while (true) {
            auto a = heap.top();
            
            heap.pop();
            total -= a;
            
            if (a == 1 || total == 1) return true;
            
            if (a < total || a % total == 0) return false;
            
            a %= total;

            total += a;
            heap.push(a);
        }
        
        assert(false); // cannot reach here
        return true;
    }
};