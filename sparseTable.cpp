#define N 
#define M 

int arr[N];

int msb(int n){
    int k = __builtin_clzll(n);
    return 63 - k;	
}

int sparse[N][M];

int n;

void build_sparse(){
    //preprocessing
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < n; ++i) {
			if (j == 0) {
				sparse[i][j] = arr[i];
			}
			else if ((i + (1 << j)) <= n) {
			    sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

int query(int l,int r){
    int len = (r - l + 1);
    int j = msb(len);

    return min(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}