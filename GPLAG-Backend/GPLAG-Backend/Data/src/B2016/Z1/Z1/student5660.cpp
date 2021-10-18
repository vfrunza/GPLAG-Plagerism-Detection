#include <vector>
#include <iostream>
#include <cmath>
const double epsilon =0.000001;
int stat(int broj){
	std::vector<int>cifre(0);
	if(broj<0)broj*=-1;
	int cifra(0);
	if(broj!=0){
		while(broj!=0){
			cifra=broj%3;
			cifre.push_back(cifra);
			broj=broj/3;
		//	std::cout << cifra << std::endl;
		}
	}else cifre.push_back(0);
	cifra=0;
	int ponavljanja(0);
	bool checked(false);
	bool paran(true);
	bool neparan(true);
	for(int i=0; i<cifre.size();i++){
		cifra=cifre[i];
		checked=false;
		for(int j=0;j<i;j++){
			if(cifre[j]==cifra){checked=true;break;}
		}
		ponavljanja=0;
		if(!checked){
			for(int j=i;j<cifre.size();j++){
				if(cifre[i]==cifre[j])ponavljanja++;
			}
			if(ponavljanja%2!=0)paran=false;
			else neparan=false;
		}
	}
	if(!neparan && !paran)return 0;//ni opak ni odvratan
	else if(!neparan && paran)return 2; //opak
	else if(neparan && !paran)return 1; //odvratan
	else return 7; // petlje se nisu izvrsile,popraviti!
}
bool nemaga(std::vector<int> rezbr,int br){
	for(int i=0; i<rezbr.size();i++){
		if(rezbr[i]==br){return false;}
	}
	return true;
}
std::vector<int> IzdvojiGadne(std::vector<int> brojevi,bool status){
	std::vector<int> a(0);
	int wanted(0);
	if(status)wanted=2;
	else wanted=1;
	for(int i=0; i<brojevi.size();i++){
		if(stat(brojevi[i])==wanted && nemaga(a,brojevi[i]))a.push_back(brojevi[i]);
	}
	return a;
}
int main ()
{
	std::vector<int>x(0);
	double hankapaldum(0);
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(std::cin>>hankapaldum,std::fabs(hankapaldum-0.0)>epsilon || !std::cin){
		 if(!std::cin || std::fabs(hankapaldum-double(int(hankapaldum)))>epsilon){
            std::cout<< "Niste unijeli cio broj!"<< std::endl;
            std::cin.clear();
            std::cin.ignore(100000,'\n');
        }else
        	x.push_back(int(hankapaldum));
	}
	
	std::vector<int>y(0);
	y=IzdvojiGadne(x,true);
	std::cout<<"Opaki: ";
	for(int a:y)
		std::cout<<a<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	y=IzdvojiGadne(x,false);
	for(int a:y)
		std::cout<<a<<" ";
	return 0;
}