int sieve[((int)1e7)+1];

void fill_sieve(int n){
    for(int i = 1;i <= n;i++)
       sieve[i] = i;

    for(int i = 2;i <= n;i++){
       if(sieve[i] == i){
          for(int mul = 2;mul*i <= n;mul++){
             sieve[i*mul] = min(sieve[i*mul],i);
          }
       }
    }   
}

map<int,int> fact(int x){
    //factorize
    map<int,int> f;
    while(x > 1){
        int cnt = 0;
        int p = sieve[x];
        while(x%p == 0){
            ++cnt;
            x /= p;
        }

        f[p] = cnt;
    }

    return f;
}

void add(map<int,int>& a,int x){
   //add factors to x to a
   auto y = fact(x); 
   for(auto it : y){
      a[it.ff] += it.ss;
   }
}

bool divi(map<int,int>& a,int x){
   //is a divisble by b
   for(auto it : a){
      int cnt = it.ss;
      int p = it.ff;

      while(x%p == 0 && cnt){
         --cnt;
         x /= p;
      } 
   } 

   return (x == 1);
}

int dcount(map<int,int>& a){
   int d = 1;
   for(auto it : a){
      d = (d*(it.ss+1));
   }

   return d;
}