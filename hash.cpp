const int base = 29;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
 
string text,pattern;
 
#define N 1000000
pii prefix[1+N];
int pw1[1+N];
int pw2[1+N];
void _build(){
	//text
    pw1[0] = 1;
    pw2[0] = 1;
    
    for(int i = 1;i <= text.size();++i){
    	pw1[i] = mul(pw1[i-1],base,mod1);
    	pw2[i] = mul(pw2[i-1],base,mod2);
    }
    
	prefix[0].ff = 0;
	prefix[0].ss = 0;
	
	for(int i = 1;i <= text.size();++i){
		prefix[i].ff = prefix[i-1].ff;
		add_self(prefix[i].ff,mul(text[i-1]-'a',pw1[i-1],mod1),mod1);
		
		prefix[i].ss = prefix[i-1].ss;
		add_self(prefix[i].ss,mul(text[i-1]-'a',pw2[i-1],mod2),mod2);
	}
}
 
pii _hash(){
	//patern
	int ans1 = 0,ans2 = 0;
	for(int i = 0;i < pattern.size();++i){
		add_self(ans1,mul(pattern[i]-'a',pw1[i],mod1),mod1);
		add_self(ans2,mul(pattern[i]-'a',pw2[i],mod2),mod2);
	}
	return {ans1,ans2};
}
 
pii _hash(int l,int r){
	//text
	int ans1 = mul(sub(prefix[r].ff,prefix[l-1].ff,mod1),modInverse(pw1[l-1],mod1),mod1);
	int ans2 = mul(sub(prefix[r].ss,prefix[l-1].ss,mod2),modInverse(pw2[l-1],mod2),mod2);
	return {ans1,ans2};
}
