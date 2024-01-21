class Segtree{
   public:	
	int n;
	vi seg;
	
	void init(int n){
		this -> n = n;
		seg.resize(4*n,0);
	}
	
	void _add(int l,int x,int i,int j,int k){
		if(l > j || l < i){
			return;
		}
		
		if(i == j){
			seg[k] += x;
			return;
		}
		
	    int mid = (i+j) >> 1;
	    _add(l,x,i,mid,2*k+1);
	    _add(l,x,mid+1,j,2*k+2);
	    
	    seg[k] = seg[2*k+1] + seg[2*k+2]; 
	}
	
	void add(int i,int x){
		_add(i,x,0,n-1,0);
	}
	
	int _sum(int l,int r,int i,int j,int k){
		if(l > j || r < i){
			return 0;
		}
		
		if(l <= i && j <= r){
			return seg[k];
		}
		
		int mid = (i+j) >> 1;
		return _sum(l,r,i,mid,2*k+1) + _sum(l,r,mid+1,j,2*k+2);
	}
	
	int sum(int l,int r){
		return _sum(l,r,0,n-1,0);
	}
};