# 1352. Product of the Last K Numbers

## Idea
Keep all prefix products of numbers in an array,  
then calculate the product of last K elements in O(1) complexity.  
When a zero number is added, clean the array of prefix products.  

## Complexity
Let K = total number of operations  
Time: O(K)  
Space: O(K)

## C++
```C++
static auto io_accelerator = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class ProductOfNumbers {
public:
    
    vector<int> prefix;
    
    ProductOfNumbers() {
        prefix = {1}; // Sentinel
    }
    
    void add(int num) {
        if(num) 
            prefix.push_back(prefix.back() * num);
        else
            prefix = {1};
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        return k < n ? prefix[n - 1] / prefix[n - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```