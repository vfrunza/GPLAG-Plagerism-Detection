/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>         

std::vector<int> IzdvojiGadne (std::vector<int>v, bool a){
	std::vector<int> parni;
	std::vector<int> neparni;
	std::vector<long long int> binarni;
	if (v.size()==0){
		if (a) return parni;
		return neparni;
	}
	
	for (int i=0; i<v.size(); i++){
		for (int j=i+1; j<v.size(); j++){
			if (v[j]==v[i]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	for (int i=0; i<v.size(); i++){
		long long int suma=0;
		long long int j=1;
		long long int c=v[i];
		if (v[i]<0) c=-c;
		while (c!=0){
			suma+=(c%3)*j;
			c/=3;
			j*=10;
		}
		binarni.push_back(suma);
	}
	std::vector<int> cifre={0, 0, 0};
	for(int i=0; i<binarni.size(); i++){
		cifre={0, 0, 0};
		while (binarni[i]!=0){
			cifre[binarni[i]%10]++;
			binarni[i]/=10;
		}
		if (cifre[0]%2==0 && cifre[1]%2==0 && cifre[2]%2==0) parni.push_back(v[i]);
		if ((cifre[0]==0 && cifre[1]==0 && cifre[2]%2!=0) || (cifre[0]==0 && cifre[2]==0 && cifre[1]%2!=0) || (cifre[1]==0 && cifre[2]==0 && cifre[0]%2!=0) || (cifre[0]%2!=0 && cifre[1]%2!=0 && cifre[2]%2!=0) || (cifre[0]==0 && (cifre[1]%2!=0 && cifre[2]%2!=0)) || ((cifre[1]==0) && (cifre[0]%2!=0 && cifre[2]%2!=0)) || ((cifre[2]==0 && (cifre[0]%2!=0 && cifre[1]%2!=0))) )neparni.push_back(v[i]);
	}
 if (a) return parni;
 return neparni;
}


int main ()
{
	std::vector<int> brojevi;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int i=0;
	for (;;){
		int elementi;
		std::cin>>elementi;
		while (!(std::cin)){
			std::cout<<"Niste unijeli broj. Ponovite unos elementa (0 za prekid unosa): ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin>>elementi;
		}
		if (elementi==0) break;
		brojevi.push_back(elementi);
		i++;
	}
	
	std::vector<int> opaki;
	std::vector<int> odvratni;
	opaki=IzdvojiGadne(brojevi, true);
	odvratni=IzdvojiGadne(brojevi, false);
	std::cout<<"Opaki: ";
	for (int i=0; i<opaki.size(); i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for (int i=0; i<odvratni.size(); i++){
		std::cout<<odvratni[i]<<" ";
	}
	return 0;
}