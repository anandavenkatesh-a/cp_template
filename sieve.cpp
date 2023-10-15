bool sieve[((int)1e7)+1];

void fill_sieve(int n){
    fill(sieve+2,sieve+n+1,true);
    
    for(int i = 1;i <= n;i++){
      if(sieve[i]){
         for(int mul = 2;mul*i <= n;mul++){
            sieve[mul*i] = false;
         }
      }
    }
}