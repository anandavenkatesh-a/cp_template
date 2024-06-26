class Dsu {
public:
    int* p;
    int* rank;
    int n;

    Dsu(int n) {
        this -> n = n;
        p = new int[n + 1];
        for (int i  = 1; i <= n; ++i)
            p[i] = i;

        rank = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            rank[i] = 0;
    }

    int get(int a) {
        return p[a] = (p[a] == a) ? a : get(p[a]);
    }

    void Union(int a, int b) {
        int p_a = get(a);
        int p_b = get(b);
        
        if(p_a == p_b)
            return;

        if (rank[p_a] > rank[p_b]) {
            p[p_b] = p_a;
        }
        else if (rank[p_a] == rank[p_b]) {
            ++rank[p_a];
            p[p_b] = p_a;
        }
        else {
            p[p_a] = p_b;
        }
    }
};