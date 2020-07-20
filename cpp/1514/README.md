# 1514. Path with Maximum Probability

## Idea

Dijkstra Algorithm

## Complexity

Time:  
O(NlogE)

Where N is the number of nodes and E is the number of edges.

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

class Solution {
public:
    
    struct Edge {
        int next;
        double prob;
        
        bool operator<(Edge rhs) const {
            return prob < rhs.prob;
        }
    };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probs(n);
        probs[start] = 1.0;
        vector<int> max_prob_found(n);
        
        vector<vector<Edge>> my_edges(n);
        for(int i = 0; i < edges.size(); ++i) {
            my_edges[edges[i][0]].push_back({edges[i][1], succProb[i]});
            my_edges[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
            
        priority_queue<Edge> heap;
        heap.push({start, 1.0});
        
        for(int max_prob_found_count = 1; max_prob_found_count < n; ++max_prob_found_count) {
            
            Edge picked_edge{ -1, 0.0 };
            while(heap.size()) {
                int top = heap.top();
                heap.pop();
                
                if(!max_prob_found[top.next]) {
                    picked_edge = top;
                    break;
                }
            }
            
            if(picked_edge.next == -1)
                break;
            
            max_prob_found[picked_edge.next] = 1;
            
            if(picked_edge.next == end)
                return picked_edge.prob;
            
            for(Edge e : my_edges[picked_edge.next]) {
                if(probs[e.next] < picked_edge.prob * e.prob) {
                    probs[e.next] = picked_edge.prob * e.prob;
                    heap.push({e.next, probs[e.next]});
                }
            }
        }
        
        return probs[end];
    }
};
```