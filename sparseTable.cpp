const int N = 200000;
const int B = floor(log2(N)) + 1;
int sparse[1+N][1 + B];
int arr[1+N];
int n,q; 

void build_sparse(){
    //preprocessing
	for (int j = 0; j <= B; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (j == 0) {
				sparse[i][j] = arr[i];
			}
			else if ((i + (1 << j)) <= n+1) {
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
