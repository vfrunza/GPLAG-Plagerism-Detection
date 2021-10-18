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

std::vector<int>vratiCifre(std::vector<int> g){
	std::vector<int>cifre;
	int c;
for(int i=g.size();i>0;i--){
	   c=g[i]%3;
		cifre.push_back(c);
		g[i]/=3;
		
	}
	return cifre;
	
}

bool ImaDuplih(std::vector<int> broj){
	int k=0;
	std::vector<int>cifre=vratiCifre(broj);
	for(int i=0;i<cifre.size();i++){
		for(int j=i+1;j<=cifre.size();j++){
			if(cifre[i]==cifre[j])
			k++;
			if(k%2==0)
			return true;
				
			
		}
		
	}
	return false;
}

std::vector<int>IzdvojiGadne(std::vector<int>a, bool h){
	std::vector<int>v1;
	std::vector<int>v2;
	int c=0,d=0;
	bool b=ImaDuplih(a);
	if(b==true){
		for(int i=0;i<a.size();i++){
			v2=vratiCifre(a);
			for(int z=0;z<v2.size();z++ ){
	           d+=v2[i]*std::pow(3,z);
		//d+=v2[i]*std::pow(3,i);
			
			v1.push_back(d);
			
		}
		}
		
	}else{
		for(int j=0;j<a.size();j++){
			v2=vratiCifre(a);
			for(int t=0;t<v2.size();t++){
				c+=v2[j]*std::pow(3,t);
			//c+=v2[j]*std::pow(3,j);
			v1.push_back(c);
			}
		}
		
		
	}
	return v1;
	
}

int main ()
{
	int broj;
	std::vector<int>v1;
	
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): \n";
	do{
	std::cin>>broj;
		v1.push_back(broj);
		
	}while(broj!=0);
	
	std::vector<int>v2(IzdvojiGadne(v1,true));
	std::vector<int>v3(IzdvojiGadne(v1,false));
	
	std::cout<<"Opaki: ";
	for(int i=0;i<v2.size();i++){
		std::cout<<v2[i];
	}
	std::cout<<"\nOdvratni: ";
	for(int i=0;i<v3.size();i++){
		std::cout<<v3[i];
	}
	
	
	
	return 0;
}