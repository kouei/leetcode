# 1348. Tweet Counts Per Frequency

## Idea
Simple simulation. Binary search can be used to do some  
constant level acceleration. 

## Complexity
Let K = total number of operations  
Let N = total number of tweets  

Time: O(K^2)  
Space: O(N)

## C++
```C++
static int io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class TweetCounts {
public:
    
    static const int SECOND = 1;
    static const int MINUTE = 60 * SECOND;
    static const int HOUR = 60 * MINUTE;
    static const int DAY = 24 * HOUR;
    
    unordered_map<string, multiset<int>> m;
    
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(const string & freq, const string & tweetName, int startTime, int endTime) {
        
        int unit = -1;
        if(freq[0] == 'm')
            unit = MINUTE;
        else if(freq[0] == 'h')
            unit = HOUR;
        else
            unit = DAY;
        
        int span = endTime - startTime;
        int n = span / unit + 1;
        vector<int> res(n);
        
        int & times = m[tweetName];
        for(int itr = times.lower_bound(startTime); itr != times.end() && *itr <= endTime; ++itr) {
            int index = (*itr - startTime) / unit;
            res[index] += 1;
        }
        
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```