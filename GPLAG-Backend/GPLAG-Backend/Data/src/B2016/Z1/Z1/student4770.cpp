/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
long long int baza3(long long int b){
		long long int cifra(0),c(1);
			while(b!=0){
			cifra+=(b/3)*c;
			b/=3;
			c*=10;
			}
	return cifra;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool iskaz){
	std::vector<int> v1;
	std::vector<long long int> f;
	if(iskaz){
		for(long long int i:v){
			long long int k;
			k=baza3(i);
			f.push_back(k);
			int nule(0),jedinice(0),dvice(0),rastavi;
			for(long long int j: f){
				while(j){
					rastavi=j%10;
					if(rastavi==0){nule++;}
					if(rastavi==1){jedinice++;}
					if(rastavi==2){dvice++;}
					j/=10;
				}
			}
				if(nule%2==0 && jedinice%2==0 && dvice%2==0) v1.push_back(i);
		}
		return v1;
	}
	else{
		for(long long int i:v){
			long long int k;
			k=baza3(i);
			f.push_back(k);
			int nule(0),jedinice(0),dvice(0),rastavi;
			for(long long int j: f){
				while(j){
					rastavi=j%10;
					if(rastavi==0)nule++;
					if(rastavi==1)jedinice++;
					else dvice++;
					j/=10;
				}
			}
			if((nule%2!=0 || nule==0) && (jedinice%2!=0 || jedinice ==0)&&(dvice==0 || dvice%2!=0)) v1.push_back(i);
		}
		return v1;
	}
}
int main(){
	std::vector<int> v;
	int f;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>f;
		if(f!=0){
			v.push_back(f);
		}
	}while(f!=0);
	auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
	std::cout << "Opaki: ";
	for (const auto &x : opaki) std::cout << x << " ";
	std::cout << std::endl << "Odvratni: ";
	for (const auto &x : odvratni) std::cout << x << " ";
	return 0;
}