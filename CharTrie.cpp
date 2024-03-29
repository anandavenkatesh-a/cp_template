class Trie {
public:
    TrieNode *root;
    Trie() { root = new TrieNode();}
    void insert(string s) {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i) {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
            p->cnt++;
        }
        p -> is_word = true;
    }
    bool search(string key) {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }
    int startsWith(string prefix) {
        TrieNode* prefNode=find(prefix);
        return prefNode==NULL ? 0LL : prefNode->cnt;
    }
    int get_sum(string key) {
        TrieNode *p = root;
        int sum=0;
        for(int i = 0; i < key.size(); ++ i) {
            p = p -> next[key[i] - 'a'];
            if(p == 0){
                break;
            }
            sum += p -> cnt;
        }
        return sum;
    }
    TrieNode* find(string key) {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};