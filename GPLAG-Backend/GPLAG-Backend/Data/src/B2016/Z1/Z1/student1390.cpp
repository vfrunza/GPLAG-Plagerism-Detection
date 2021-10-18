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

std::vector<int> IzdvojiGadne(std::vector<int> v1,bool a){
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j]){
				v1.erase(v1.begin()+j);
				j--;
			}
		}
	}
	
	std::vector<int> ternarni;
	int broj,cifre,novi;
	int index(0);
	std::vector<int> preslikani;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	for(int i=0;i<v1.size();i++){
		preslikani.push_back(v1[i]);
	}
	for(int i=0; i<v1.size(); i++){
		if(v1[i]==0)break;
		int suma(0);
		int b;
		std::vector<long int> stepenitrice={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323};
		for(int i=0;i<stepenitrice.size();i++){
				if(stepenitrice[i]>abs(v1[index])){
					b=i-1;
					break;
			}
		}
		
		index++;
		while(v1[i]!=0){
		broj=v1[i];
		v1[i]/=pow(3,b);
		cifre=(int)v1[i];
		novi=cifre*pow(10,b);
		suma+=novi;
		v1[i]=broj-cifre*pow(3,b);
		b--;
		}
		ternarni.push_back(suma);
	}
	

		for(int i=0;i<ternarni.size();i++){
			if(ternarni[i]==0)break;
			std::vector<int> cifre;
			int pamti(0);
			bool nisu(1),nijedan(0);
			while(ternarni[i]!=0){
				cifre.push_back(ternarni[i]%10);
				ternarni[i]/=10;
				pamti=i;
			}
			for(int i=0;i<cifre.size();i++){
				if(cifre[i]>2)nijedan=1;
			}
			if(nijedan==1)continue;
			int parni(0);
			for(int j=0;j<3;j++){
			for(int i=0;i<cifre.size();i++){
				if(abs(cifre[i])==j)parni++;
			}
			if((parni%2)!=0){
				nisu=0;
				break;
			}
			if(nisu==0)break;
			}
			if(nisu==1){
				for(int i=0;i<preslikani.size();i++){
					if(pamti==i)opaki.push_back(preslikani[i]);
				}
			}
			if(nisu==0){
				int nijedan(0);
			for(int j=0;j<3;j++){
				int nijedan1(0);
				int neparni(0);
			for(int i=0;i<cifre.size();i++){
				if(abs(cifre[i])==j)neparni++;
			}
			if(neparni==0)continue;
			if((neparni%2)==0){
				nijedan1=1;
				nijedan=nijedan1;
				break;
			}
			if(nijedan==1)break;
			}
			for(int i=0;i<cifre.size();i++){
				if(abs(cifre[i])>2)nijedan=1;
			}
			
			if(nijedan!=1){
				for(int i=0;i<preslikani.size();i++){
					if(pamti==i)odvratni.push_back(preslikani[i]);
				}
			}
		}
	
		}
		if(a==1)return opaki;
		if(a==0)return odvratni;

}

int main ()
{
	int a(1);
	std::vector<int> v1;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while (a!=0){
		std::cin>>a;
		v1.push_back(a);
	}
	
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j])v1.erase(v1.begin()+j);
		}
	}
	bool n(1);
	std::cin>>n;
	std::vector<int> konacni=IzdvojiGadne(v1,n);
	
	std::cout << "Opaki: ";
	for(int i=0;i<konacni.size();i++){
		std::cout << konacni[i]<<" ";
	}
	std::cout << std::endl;
	n=0;
	std::vector<int> konacni2=IzdvojiGadne(v1,n);
	std::cout << "Odvratni: ";
	for(int i=0;i<konacni2.size();i++){
		std::cout << konacni2[i]<<" ";
	}
	
	return 0;
}