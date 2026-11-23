class ProductOfNumbers {
    private:
    vector<int> productOfNumbers;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        productOfNumbers.push_back(num);
    }
    
    int getProduct(int k) {
        int multiply=1;
        for(int i=productOfNumbers.size()-k; i<=productOfNumbers.size()-1; i++){
            multiply=multiply*productOfNumbers[i];
        }

       return multiply;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->push_back(num);
 * int param_2 = obj->getProduct(k);
 */