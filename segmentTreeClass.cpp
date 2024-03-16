class Node{
   public:
   int val;    
   int prop; 
   
   Node(int v){
      val = v;
      prop = 0;
   }
 
    Node operator+(const Node& b){
        return Node(val + b.val); 
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
        seg.resize(8*n,Node(0));
        build(0,n-1,0,arr);
    }

    void prop(int i,int j,int k){
        if(seg[k].prop == 0){
            return;
        }
        
        seg[k].val = seg[k].prop*(j-i+1);
        seg[2*k+1].prop = seg[k].prop;
        seg[2*k+2].prop = seg[k].prop;
        seg[k].prop = 0;
    }
 
    void _update(int l,int r,int x,int i,int j,int k){
        prop(i,j,k);
        if(l > j || r < i){
            return;
        }
        
        if((l <= i)&&(j <= r)){
            seg[k].prop = x;
            prop(i,j,k);
            return;
        }
        
        int mid = (i+j) >> 1;
        _update(l,r,x,i,mid,2*k+1);
        _update(l,r,x,mid+1,j,2*k+2);
        
        seg[k] = seg[2*k+1] + seg[2*k+2]; 
    }
    
    void update(int i,int j,int x){
        _update(i,j,x,0,n-1,0);
    }
    
    Node _sum(int l,int r,int i,int j,int k){
        prop(i,j,k);
        if(l > j || r < i){
            return Node(0);
        }
        
        if(l <= i && j <= r){
            return seg[k];
        }
        
        int mid = (i+j) >> 1;
        return _sum(l,r,i,mid,2*k+1) + _sum(l,r,mid+1,j,2*k+2);
    }
    
    int sum(int l,int r){
        if(l > r){
            return 0;
        }
        return _sum(l,r,0,n-1,0).val;
    }
};
