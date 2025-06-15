/*
  => 1-based indexing
  => using rank
  => can store informations like min and max weight of components.
*/

class Dsu {
public:
    vi p, rank, min_weight, max_weight;
    
    int n;

    Dsu(int n) {
        this -> n = n;
        p = vi (n+1);
        for (int i  = 1; i <= n; ++i)
            p[i] = i;

        rank = vi (n+1);
        for (int i = 1; i <= n; ++i)
            rank[i] = 0;
        
        min_weight = vi (n+1, inf);
        max_weight = vi (n+1, ninf);
    }

    int get(int a) {
        return p[a] = (p[a] == a) ? a : get(p[a]);
    }
    
    int get_min_plus_max(int a){
        int p_a = get(a);
        return min_weight[p_a] + max_weight[p_a];
    }

    void Union(int a, int b, int w) {
        int p_a = get(a);
        int p_b = get(b);
        
        if(p_a == p_b){
            min_weight[p_a] = min(w, min_weight[p_a]);
            max_weight[p_a] = max(w, max_weight[p_a]);
            return;
        }

        if (rank[p_a] > rank[p_b]) {
            p[p_b] = p_a;
            min_weight[p_a] = min(w,min(min_weight[p_a], min_weight[p_b]));
            max_weight[p_a] = max(w,max(max_weight[p_a], max_weight[p_b]));
        }
        else if (rank[p_a] == rank[p_b]) {
            ++rank[p_a];
            p[p_b] = p_a;
            min_weight[p_a] = min(w,min(min_weight[p_a], min_weight[p_b]));
            max_weight[p_a] = max(w,max(max_weight[p_a], max_weight[p_b]));
        }
        else {
            p[p_a] = p_b;
            min_weight[p_b] = min(w,min(min_weight[p_a], min_weight[p_b]));
            max_weight[p_b] = max(w,max(max_weight[p_a], max_weight[p_b]));
        }
    }
};
