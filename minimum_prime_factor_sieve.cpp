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