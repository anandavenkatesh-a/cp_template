class TrieNode {
public:
    TrieNode *next[2];
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() { root = new TrieNode();}
    void insert(int s) {
        TrieNode *p = root;
        for(int i = 30; i >= 0; --i) {
            int b = ((s&(1 << i)) != 0);
            if(p -> next[b] == NULL)
                p -> next[b] = new TrieNode();
            p = p -> next[b];
        }
    }

    int find_xor_mx(int key) {
        TrieNode *p = root;
        int mx = 0;
        for(int i = 30; i >= 0; --i){
            int b = ((key&(1 << i)) != 0);
            if(p -> next[1-b] != NULL){
                p = p -> next[1-b];
                mx = (mx|(1 << i));
            }
            else{
                p = p -> next[b];
            }
        }
        return mx;
    }
};