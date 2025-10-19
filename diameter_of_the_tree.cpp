pii max_dist_dfs(int i, int p, vector<vi>& adj, int dist){
    // returns {max dist, node}
    pii ans{0, i};
    for(int j: adj[i]){
        if(j == p) continue;
        auto sub_ans = max_dist_dfs(j, i, adj, dist + 1);
        if(sub_ans.ff + 1 > ans.ff){
            ans.ff = sub_ans.ff + 1;
            ans.ss = sub_ans.ss;
        }
    }

    return ans;
}

vi diameter(vector<vi>& adj){
    // returns {dia, a, b}
    pii a = max_dist_dfs(0, -1, adj, 0);
    pii b = max_dist_dfs(a.ss, -1, adj, 0);

    return vi{b.ff, a.ss, b.ss};
}
