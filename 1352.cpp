/****************************************************
 * Idea:
 * Keep all prefix products of numbers in an array, then calculate the product of last K elements in O(1) complexity.
 * When a zero number is added, clean the array of prefix products.
 * 
 * Let K = total number of operations
 * 
 * Time:  
 * O(K)
 * 
 * Space:
 * O(K)
 *****************************************************/

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
    }
    
    void add(int num) {
        if(num == 0) 
            prefix.clear();
        else {
            if(prefix.size()) 
                prefix.push_back(prefix.back() * num);
            else 
                prefix.push_back(num);
        }
    }
    
    int getProduct(int k) {
        if(k < prefix.size()) 
            return prefix.back() / prefix[prefix.size() - k - 1];
        else if(k == prefix.size())
            return prefix.back();
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */