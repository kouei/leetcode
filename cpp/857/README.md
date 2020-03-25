# 857. Minimum Cost to Hire K Workers

## Idea
Greedy Algorithm.  
First sort the workers in unit_price ascending order.  
unit_price = wage / quality  
Then maintain a heap to store the K workers quality.  
The top of the heap is the highest quality among the K workers.  
Iterate through all workers, add each worker to the current group.  
If the size of current group equals K,  
we calculate total wage for these K workers and update the result.  
If the size of current group goes beyond K,  
we remove the worker with the highest quality.  

## Complexity
Time:  
O(NlogN) for sorting  
O(NlogK) for iterating through all workers with our heap  

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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        
        struct Worker{
            double unit_price;
            int quality;
        };
        
        vector<Worker> w(n);
        for(auto i = 0; i < n; ++i)
            w[i] = { (double)wage[i] / quality[i], quality[i] };
        
        sort(w.begin(), w.end(), [](Worker & a, Worker & b){
            return a.unit_price < b.unit_price;
        });
        
        priority_queue<int> heap;
        auto quality_sum = 0;
        auto res = numeric_limits<double>::max();
        for(auto i = 0; i < n; ++i) {
            quality_sum += w[i].quality;
            heap.push(w[i].quality);
            
            if(heap.size() > K) {
                quality_sum -= heap.top();
                heap.pop();
            }
            
            if(heap.size() == K)
                res = min(res, quality_sum * w[i].unit_price);
        }
        
        return res;
    }
};
```