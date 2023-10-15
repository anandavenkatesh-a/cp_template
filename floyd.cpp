#define N 
int d[1+N][1+N];

void floyd(int n){
   for (int k = 0; k < n; ++k) {
	    for (int i = 0; i < n; ++i) {
	        for (int j = 0; j < n; ++j) {
	            if (d[i][k] < inf && d[k][j] < inf)
	                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
	        }
	    }
	}	
}