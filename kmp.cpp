vi prefix_function(string& pattern) {
    int n = (int)pattern.length();
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j-1];
        if (pattern[i] == pattern[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int pattern_match(string& arr,string& pattern){
	int cnt = 0;
    vi pi = prefix_function(pattern);
    
    int m = (int)pi.size();
    int n = (int)arr.size();
    
    int j = 0,i = 0;
    while(i < n){
    	if(j == m){
             ++cnt;
             j = pi[j-1];
        }
        
        if(arr[i] == pattern[j]){
        	++i;
        	++j;
        }
        else{
        	if(j == 0){
    		   ++i;
    		   continue; 	
    		}
    		
    		j = pi[j-1];
        }
    }
    
    if(j == m)
        ++cnt;
    return cnt;    
}