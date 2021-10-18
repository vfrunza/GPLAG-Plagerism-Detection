/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
std::vector<int> Ternar(long long int broj){
	std::vector<int> br;
	broj=abs(broj);
	while (broj!=0){
		br.push_back(broj%3);
		broj=broj/3;
	}
	return br;
}
std::vector<int> Izbaci(std::vector<int> v){
	for (int i=0; i<v.size()-1; i++){
 		for(int j=i+1; j<v.size(); j++){
			if (v[i]==v[j] || v[j]==0) {
				v.erase(v.begin()+(j));
				j--;
			}
		}
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool p){
	std::vector<int> a=(Izbaci(v));
	std::vector<int> c;
	int br1=0, br2=0, br0=0;
	for(int i=0; i<a.size(); i++){
		std::vector<int>b=Ternar(a[i]) ;
		br1=0, br2=0, br0=0;
		for(int j=0; j<b.size();j++){
			if (b[j]==1) br1++;
			if (b[j]==2) br2++;
			if (b[j]==0) br0++;
		}
		/*if(( (br0!=0 && br1!=0 && br2!=0) && (br0%2==0 && br1%2!=0 && br2%2!=0) 
		|| (br0%2!=0 && br1%2!=0 && br2%2==0) || (br0%2!=0 && br1%2==0 && br2%2!=0) 
		|| (br0%2==0 && br1%2==0 && br2%2!=0)) ) a.erase(a.begin()+i);*/
		
		if (p) {
		if(br1%2==0 && br2%2==0 && br0%2==0) c.push_back(a[i]);
		}
		else if(p==false){
			if (br1==0) br1++;
			if (br2==0) br2++;
			if (br0==0) br0++;
			if (br1%2!=0 && br2%2!=0 && br0%2!=0)
			c.push_back(a[i]);
			
		}
		
	}
	return c;
}
int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj=1;
	while(broj!=0){
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<int> opaki=IzdvojiGadne(v,1);
	std::cout<<"Opaki: ";
	for(int i:opaki){
		std::cout<<i<<" ";
	}
	std::vector<int> odvratni=IzdvojiGadne(v,0);
	std::cout<<"\n"<<"Odvratni: ";
	for(int i:odvratni){
		std::cout<<i<<" ";
	}
	return 0;
}
