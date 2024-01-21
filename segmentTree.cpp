#define N 
int seg[4*N];
int arr[N];
int n,q;

//range query 
int sum(int l,int r,int i = 0,int j = n-1,int k = 0){
	if((l <= i)&&(j <= r)){
		return seg[k];
	}
	
	if((l > j)||(r < i)){
		return 0;
	}
	
	int mid = (i+j) >> 1;
	return sum(l,r,i,mid,2*k+1)^sum(l,r,mid+1,j,2*k+2);
}

//point query with lazy propagation
int get(int index,int i = 0,int j = n-1,int k = 0){
	if(i == j){
	    return seg[k];	
	}
	
	int mid = (i+j) >> 1;
	
	if(seg[k]){
	    seg[2*k+1] = seg[k];
    	seg[2*k+2] = seg[k];	
    	seg[k] = 0;
	}
	
	if(index > mid){
		return get(index,mid+1,j,2*k+2);
	}
	else{
		return get(index,i,mid,2*k+1);
	}
}

//range update with lazy propagation
void update(int l,int r,int u,int i = 0,int j = n-1,int k = 0){
	if((l > j) || (r < i)){
		return;
	}
	
	if((l <= i)&&(r >= j)){
		seg[k] = u;
		return;
	}
	
	int mid = (i+j) >> 1;
	if(seg[k]){
	    seg[2*k+1] = seg[k];
    	seg[2*k+2] = seg[k];
    	seg[k] = 0;	
	}
	
	update(l,r,u,i,mid,2*k+1);
	update(l,r,u,mid+1,j,2*k+2);
}

//bianry search with segments 
int get(int val,int i = 0,int j = n-1,int k = 0){
	if(seg[k] < val){
		return inf;
	}
	
	if(i == j){
		return i;
	}

	int mid = (i+j) >> 1;
	if(seg[2*k+1] >= val){
	    return get(val,i,mid,2*k+1);	
	}

	return get(val,mid+1,j,2*k+2);
}
 
void init(int i = 0,int j = n-1,int k = 0){
	if(i == j){
		seg[k] = arr[i];
		return;
	}
	
	int mid = (i+j) >> 1;
	init(i,mid,2*k+1);
	init(mid+1,j,2*k+2);
	
	seg[k] = (seg[2*k+1]^seg[2*k+2]);
}