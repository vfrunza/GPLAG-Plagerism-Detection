/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

std::vector<int> DecToTer(int n){
	std::vector<int> t;
	do{
		int x=abs(n%3);//x=n%3
		t.push_back(x);
		n/=3;
	}
	while(n!=0);
	//std::reverse(t.begin(), t.end());
	return t;
}
bool DaLiJeOpak(int x){
	std::vector<int> h(DecToTer(x));//h(DecToTer(abs(x));
	int br0(0), br1(0), br2(0);
	for(int i=0;i<h.size();i++){
		if(h[i]==0) br0++;
		if(h[i]==1) br1++;
		if(h[i]==2) br2++;
	}
	if(br0==0 && br1%2==0 && br2%2==0) return true;
	else if(br1==0 && br2%2==0 && br0%2==0) return true;
	else if(br2==0 && br1%2==0 && br0%2==0) return true;
	else if(br0%2==0 && br1%2==0 && br2%2==0) return true;
	else if(br0==0 && br1==0 && br1%2==0) return true;
	else if(br0%2==0 && br1==0 && br2==0) return true;
	else if(br0==0 && br1%2==0 && br2==0) return true;
	return false;
}
bool DaLiJeOdvratan(int x){
	std::vector<int> h(DecToTer(x));
	int br0(0), br1(0), br2(0);
	for(int i=0;i<h.size();i++){
		if(h[i]==0) br0++;
		if(h[i]==1) br1++;
		if(h[i]==2) br2++;
	}
	if(br0==0 && br1%2!=0 && br2%2!=0) return true;
	else if(br1==0 && br0%2!=0 && br2%2!=0) return true;
	else if(br2==0 && br1%2!=0 && br0%2!=0) return true;
	else if(br0%2!=0 && br1%2!=0 && br2%2!=0) return true;
	else if(br0==0 && br1==0 && br1%2!=0) return true;
	else if(br0%2!=0 && br1==0 && br2==0) return true;
	else if(br0==0 && br1%2!=0 && br2==0) return true;
	return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool b){
	std::vector<int> fin;
	bool ima(false);
	
	if(b){
		for(unsigned int i=0;i<v.size();i++){
			if(DaLiJeOpak(v[i])) {
				ima=false;
				for(int f:fin){
					if(f==v[i]){
						ima=true; break;
					}
				}
				if(!ima)
					fin.push_back(v[i]); 
			}
		}
	}
	else{
		for(unsigned int i=0;i<v.size();i++){
			if(DaLiJeOdvratan(v[i])){
				ima=false;
				for(int f:fin){
					if(f==v[i]){
						ima=true;
						break;
					}
				}
				if(!ima) fin.push_back(v[i]);
			} 
		}
	}
	return fin;
}
int main ()
{ 
	std::vector<int> v, novi1, novi2;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int x;
		std::cin>>x;
		if(x==0) break;
		else v.push_back(x);
	}
	novi1=IzdvojiGadne(v,true);
	novi2=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int k=0;k<novi1.size();k++){
		std::cout<<novi1[k]<<" ";
	}
	std::cout<<"\nOdvratni: ";
	for(int g=0;g<novi2.size();g++){
		std::cout<<novi2[g]<<" ";
	}
	
	return 0;
}