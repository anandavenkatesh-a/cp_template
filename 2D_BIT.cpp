int n,q; 
const int N = 1000;
int Tree[1+N][1+N];

/*
   x >= 1 y >= 1 
*/
 
void update_y(int x,int y,int v){
    while(y <= n){
        Tree[x][y] += v; 
        y += (y&(-y));
    }
}
 
int query_y(int x,int y){
    int sum = 0;
    while(y > 0){
        sum += Tree[x][y];
        y -= (y&(-y));
    }
    return sum;
}

//update at point (x,y) 
void update(int x,int y,int v){
    while(x <= n){
        update_y(x,y,v);
        x += (x&(-x));
    }
}


//sum from (1,1) => (x,y) 
int query(int x,int y){
    if(x == 0 || y == 0){
        return 0;
    }
 
    int sum = 0;
    while(x > 0){
        sum += query_y(x,y);
        x -= (x&(-x));
    }
 
    return sum;
}

//sum from (x1,y1) => (x2,y2) 
int query(int x1,int y1,int x2,int y2){
    int lrc = query(x1-1,y1-1);
    int lr = query(x1-1,y2);
    int lc = query(x2,y1-1);
    int r = query(x2,y2);
 
    return r + lrc - lc - lr;
}
