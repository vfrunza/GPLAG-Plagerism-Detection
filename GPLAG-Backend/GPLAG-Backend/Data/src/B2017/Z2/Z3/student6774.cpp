#include <iostream>
#include<cmath>
#include<iomanip>
#include<deque> 
#include<limits>
#include<stdexcept>
#include<vector>
#include <memory>
int treba;
int brojper;
int broj;
bool josjedanperiodicnafunkcija(std::vector<int> const &v, int a){
	int dokle=v.size()/a;
	int nekibroj=v.size()%a;
	dokle--;
	int i;
	for(i=0;i<dokle*a;i++){
		if(v[i]!=v[i+a])return false;
	}int rekt=i;
	for(;i<rekt+nekibroj;i++){
		if(v[i]!=v[i+a])return false;
	}
	return true;
}
int koliko(std::vector<int> v,int nekibroj,int brojper){
	int suma1=1000;
	int suma=0;
	int i;
	for (i=0;i<brojper;i++){
		suma+=v[i]*nekibroj;
	}
	return suma1*10;
	
}
bool periodican (std::vector<int> const &v,int &brojper){
	for(int i=2;i<=v.size()/2;i++){
		if(josjedanperiodicnafunkcija(v,i)){brojper=i;return true;}
	}
	return false;
}

int ** AlocirajFragmentirano(std::vector<int> const &v,int  &broj){
	if(v.size()==0)throw std::domain_error  {"Prazan vektor!"};
	for(int i=0;i<v.size();i++){
		if(v[i]<1)throw std::domain_error {"Neispravan vektor!"};
	}

	
	
	int nekibroj;
	bool istina=false;
	if(periodican(v,brojper))istina=true;
	if(istina){
	if(v.size()%brojper==0){broj=v.size()/brojper;nekibroj=0;}
	else{ nekibroj=brojper-v.size()%brojper;broj=(v.size()/brojper)+1;}
	}
	else{
		brojper=v.size();
		nekibroj=v.size();
		broj=2;
	}
	int ** p(new int * [v.size()+nekibroj]);
	int i;
	try{
	for( i=0;i<v.size();i++){
		p[i]=new int [v[i]];
	}
	int pomocna=brojper-nekibroj;
	for(int j=0;j<nekibroj;j++){
		p[i]=new int[v[pomocna]];
		pomocna++;i++;
	}
	treba=i;
	}catch(...){
		for(int ss=0;ss<treba;ss++)delete []p[ss];
		delete[]p;
		throw;
	}
	
	int j=0;
	for(int k=0;k<broj*brojper;k++){
		if(j==brojper)j=0;
		int counter=0;
		for(int l=v[j]-1;l>=0;l--){
			p[k][l]=brojper-counter;
			counter++;
			
		}j++;
	}

	
	return p;
}


int ** AlocirajKontinualno(std::vector<int> const &v,int  &broj){
		if(v.size()==0)throw std::domain_error  {"Prazan vektor!"};
		for(int i=0;i<v.size();i++){
		if(v[i]<1)throw std::domain_error {"Neispravan vektor!"};
	}

	
	int nekibroj;
	bool istina=false;
	if(periodican(v,brojper))istina=true;
	if(istina){
	if(v.size()%brojper==0){broj=v.size()/brojper;nekibroj=0;}
	else{ nekibroj=brojper-v.size()%brojper;broj=(v.size()/brojper)+1;}
	}
	else{
		brojper=v.size();
		nekibroj=v.size();
		broj=2;
	}
	int ** p(new int * [v.size()+nekibroj]);
	int i;
	try{
		p[0]=new int [koliko(v,broj,brojper)];
		int pomocna=0;
	for( i=1;i<v.size()+nekibroj;i++){
		if(pomocna==brojper)pomocna=0;
		p[i]=p[0]+v[pomocna]*i;
		pomocna++;
	}
	treba=i;
	}catch(...){
	delete []p[0];
	delete[]p;
		throw;
	}
	int j=0;
	for(int k=0;k<broj*brojper;k++){
		if(j==brojper)j=0;
		int counter=0;

		for(int l=v[j]-1;l>=0;l--){
			p[k][l]=counter+1;
			
			counter++;
		}
		j++;
	}j=0;
	int sfs=0;
	int fsf=0;
	for(int fk=0;fk<broj;fk++){
		sfs=0;
		for(int k=brojper*broj-brojper;k<brojper*broj;k++){
			if(j==brojper)j=0;
			for(int l=0;l<v[j];l++){
				p[fsf][sfs]=p[k][l];
			//std::cout << p[k][l]<<" " ;
				sfs++;
			}j++;
		}fsf++;
	}

	
	return p;
}


int main (){
	std::vector<int>v;
	std::cout << "Unesite broj elemenata vektora: Unesite elemente vektora: Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		std::cin >> temp;
		v.push_back(temp);
	}
	int al;
	std::cin >> al;
	if(al){
		int j=0;
		try{
		auto p(AlocirajFragmentirano(v,broj));
		std::cout  <<"Dinamicki alocirana matrica:"<< std::endl;
			for(int k=0;k<broj*brojper;k++){
		if(j==brojper)j=0;
		for(int l=0;l<v[j];l++){
			std::cout <<  p[k][l]<<"  ";
			
		}std::cout  << std::endl;j++;
	}
		for(int ss=0;ss<treba;ss++)delete []p[ss];
		delete[]p;}catch(std::domain_error er){
		std::cout << "Izuzetak: " <<er.what()<< std::endl;
	}
	}
	else{try{auto p(AlocirajKontinualno(v,broj));
	int j=0;
	std::cout  <<"Dinamicki alocirana matrica:"<< std::endl;
				for(int k=0;k<broj*brojper;k++){
		if(j==brojper)j=0;
		for(int l=0;l<v[j];l++){
			std::cout <<  p[k][l]<<"  ";
			
		}std::cout  << std::endl;j++;
	
		delete []p[0];
	delete[]p;}}catch(std::domain_error er){std::cout << "Izuzetak: " <<er.what()<< std::endl;}
	} 
	
	
	return 0;
}