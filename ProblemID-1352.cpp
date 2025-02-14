class ProductOfNumbers {
    public:
        vector<int> v;
        ProductOfNumbers() : v() {}
        
        void add(int num) {
            v.push_back(num);
        }
        
        int getProduct(int k) {
            int prod = 1;
            int j = v.size() - k;
            for(int i=j; i<v.size(); i++)
            {
                prod *= v[i];
            }
            return prod;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */