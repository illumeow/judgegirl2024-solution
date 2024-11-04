#include<bits/stdc++.h>
using namespace std;

int randint(int small, int big){
	return small+(rand()%(big+1-small));
}

unsigned long long power(int a,int b){
	unsigned long long ret=1,now=a;
	while(b){
		if(b%2) ret*=now;
		now*=now;
		b/=2;
	}
	return ret;
}

int main(){
	string morse[26] = {".-b","-...b","-.-.b","-..b",".b","..-.b","--.b","....b","..b",".---b","-.-b",".-..b","--b","-.b","---b",".--.b","--.-b",".-.b","...b","-b","..-b","...-b",".--b","-..-b","-.--b","--..b"};
    srand((unsigned int)time(NULL));
    int length[21];
	char iname[]="a.in",
		oname[]="a.out";
	for(int i=0;i<21;i++){
		length[i]=randint(100,1000);
		if(i==0) length[i]=3;
		if(i==20) length[i]=1000;
	}
	for(int t=0;t<21;t++){
		iname[0]=t+'a';
		oname[0]=t+'a';
		const char *inname=iname,*outname=oname;
		freopen(inname,"w",stdout);
		string s="";
		if(!t) s="SOS";
		else for(int i=0;i<length[t];i++) s+='A'+randint(0,25);
		cout<<s;
		fclose(stdout);
		vector<unsigned long long> ans;
		unsigned long long now=0;
		int digit=63;
		for(int i=0;i<length[t];i++){
			string add=morse[s[i]-'A'];
			for(int j=0;j<add.size();j++){
				if(digit==-1){
					ans.push_back(now);
					now=0;
					digit=63;
				}
				if(add[j]=='b') now+=power(2,digit);
				digit--;
				if(add[j]=='-') now+=power(2,digit);
				digit--;
			}
		}
		digit++;
		while(digit>-1){
			now+=power(2,digit);
			digit--;
		}
		ans.push_back(now);
		freopen(outname,"w",stdout);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			if(i<ans.size()-1) cout<<' ';
		}
		fclose(stdout);
	}
	return 0;
}
