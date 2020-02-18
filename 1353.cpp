/****************************************************
 * Idea:
 * Sort events in startTime ascending order.
 * Iterate through from d = 1 to d = 10^5 and maintain
 * a heap, where the top of the heap is the current
 * min endTime.
 * 
 * Let N = total number of events
 * 
 * Time:  
 * O(NlogN) for sorting
 * O(NlogN) for the while loop
 * 
 * Space:
 * O(logN) for the sorting
 * O(N) for the heap
 *****************************************************/

static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0] < b[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> heap;
        
        auto res = 0;
        auto d = 1;
        auto i = 0;
        
        for(;;) {
            
            while(i < n && events[i][0] <= d) {
                heap.push(events[i][1]);
                ++i;
            }
            
            while(!heap.empty() && heap.top() < d) heap.pop();
            
            if(!heap.empty()) {
                res += 1;
                d += 1;
                heap.pop();
            }
            else if(i < n) d = events[i][0];
            else break;
        }
        
        return res;
    }
};