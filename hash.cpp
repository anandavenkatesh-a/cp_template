class StringHash {
private:
    string text;
    int base;
    int mod1, mod2;
    vector<pair<int, int>> prefix;
    vector<int> pw1, pw2;
    
    void build() {
        int n = text.size();
        
        // Initialize power arrays
        pw1.resize(n + 1);
        pw2.resize(n + 1);
        pw1[0] = 1;
        pw2[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            pw1[i] = mul(pw1[i-1], base, mod1);
            pw2[i] = mul(pw2[i-1], base, mod2);
        }
        
        // Build prefix hash
        prefix.resize(n + 1);
        prefix[0] = {0, 0};
        
        for (int i = 1; i <= n; ++i) {
            prefix[i].first = prefix[i-1].first;
            add_self(prefix[i].first, mul(text[i-1] - 'a', pw1[i-1], mod1), mod1);
            
            prefix[i].second = prefix[i-1].second;
            add_self(prefix[i].second, mul(text[i-1] - 'a', pw2[i-1], mod2), mod2);
        }
    }

public:
    // Constructor
    StringHash(const string& s, int b = 29, int m1 = 1e9+7, int m2 = 1e9+9) 
        : text(s), base(b), mod1(m1), mod2(m2) {
        build();
    }
    
    // Get hash of substring [l, r] (1-indexed)
    pair<int, int> getHash(int l, int r) {
        int ans1 = mul(sub(prefix[r].first, prefix[l-1].first, mod1), 
                      modInverse(pw1[l-1], mod1), mod1);
        int ans2 = mul(sub(prefix[r].second, prefix[l-1].second, mod2), 
                      modInverse(pw2[l-1], mod2), mod2);
        return {ans1, ans2};
    }
    
    // Get hash of entire string
    pair<int, int> getHash() {
        return getHash(1, text.size());
    }
    
    // Get text
    string getText() const {
        return text;
    }
    
    // Get length
    int length() const {
        return text.size();
    }
};
