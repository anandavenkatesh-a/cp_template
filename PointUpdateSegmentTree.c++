class Node{
   public:
   //data items for segment tree nodes
   int mn;    
   
   Node(int v){
      mn = v;
   }
 
    Node operator+(const Node& b){
        //combine operation for segment tree nodes
        return Node(min(mn, b.mn)); 
    }  
};
 
class Segtree{
   public:  
    int n;
    vector<Node> seg;
    
    void build(int i,int j,int k,vi& arr){
        if(i == j){
            seg[k] = Node(arr[i]);
            return;
        }
 
        int mid = (i+j) >> 1;
        build(i,mid,2*k+1,arr);
        build(mid+1,j,2*k+2,arr);
 
        seg[k] = seg[2*k+1] + seg[2*k+2];
    }
 
    void init(int n,vi& arr){
        this -> n = n;
        seg.resize(8*n,Node(inf));
        build(0,n-1,0,arr);
    }
 
    void _update(int ind, int x,int i,int j,int k){
        //point update
        if(ind > j || ind < i){
            return;
        }
        
        if(i == j){
            seg[k].mn = x;
            return;
        }
        
        int mid = (i+j) >> 1;
        _update(ind, x, i, mid, 2*k+1);
        _update(ind, x, mid+1, j, 2*k+2);
        
        seg[k] = seg[2*k+1] + seg[2*k+2]; 
    }
    
    void update(int ind, int x){
        _update(ind, x, 0, n-1, 0);
    }
    
    Node _sum(int l,int r,int i,int j,int k){
        //find segment tree node for given segment
        if(l > j || r < i){
            return Node(inf);
        }
        
        if(l <= i && j <= r){
            return seg[k];
        }
        
        int mid = (i+j) >> 1;
        return _sum(l,r,i,mid,2*k+1) + _sum(l,r,mid+1,j,2*k+2);
    }
    
    int sum(int l,int r){
        if(l > r){
            return inf;
        }
        return _sum(l,r,0,n-1,0).mn;
    }
};
