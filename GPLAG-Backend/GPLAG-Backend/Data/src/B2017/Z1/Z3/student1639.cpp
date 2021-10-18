/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>
enum Smjer {Rastuci=1,Opadajuci=2};

std::vector<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer smjer1){
	
	if(smjer1==Rastuci){
		std::vector<std::vector<int>> pomoc (10, std::vector<int>(5, 0));
		int brojac(0);
		int j(0);
		for(int i=1;i<v.size();i++){
			/* Broj postaje clan i-1*/
			int broj=v.at(i-1),istina;
			/* provjera da li je stepen 2 */ 
			while(broj!=0){
				if(broj%2!=0 && broj!=1){
					istina=0;
					break;
				}else
				istina=1;
				broj/=2;
			}
			/* ako je stepen 2 i clan veci od prijasnjeg dodaj u "matricu" */
			if((v.at(i)>v.at(i-1) && istina==1)){
				
				pomoc.at(j).at(brojac)=v.at(i-1);
			brojac++;
			
			}else {	
				
				if(istina==0){
				brojac=0;
				pomoc.at(j+1).at(brojac)=v.at(i-1);
				j++;
			continue;}
				pomoc.at(j).at(brojac)=v.at(i-1);
			if((i==v.size()-1) && v.at(i)>v.at(i-1) && v.at(i-1)>v.at(i-2))
			pomoc.at(j).at(brojac+1)=v.at(i-1);
				brojac=0;
			j++;
			}
			
		}
		return pomoc;
	}
	if(smjer1==Opadajuci){
			std::vector<std::vector<int>> pomoc (10, std::vector<int>(9, 0));
		int brojac(0),brojac1(0);
		int j(0);
		for(int i=1;i<v.size();i++){
			
			
			int broj=v.at(i-1),istina;
			while(broj!=0){
				if(broj%2!=0 && broj!=1){
					istina=0;
					break;
				}else
				istina=1;
				broj/=2;
			}
			if(v.at(i)<v.at(i-1) && istina==1){
				
				pomoc.at(j).at(brojac)=v.at(i-1);
			brojac++;
			if(i==v.size()-1)
			brojac1=brojac;
			}else {if(istina==0){
				brojac=0;
				pomoc.at(j+1).at(brojac)=v.at(i-1);
				j++;
			continue;}
				pomoc.at(j).at(brojac)=v.at(i-1);
			if((i==v.size()-1) && v.at(i)<v.at(i-1) && v.at(i-1)<v.at(i-2))
			pomoc.at(j).at(brojac+1)=v.at(i-1);
				brojac=0;
			j++;
			}
			
		}
		return pomoc;
	}
}

std::vector<std::vector<int>> Velicina(std::vector<std::vector<int>> v){
	for(int i=0; i<v.size();i++){
		int brojac(0);
		int j;
		for(j=0;j<v.size();j++){
			if(v.at(i).at(j)==0)
			brojac++;
		}
		v.at(i).size()-brojac;
	}
	return v;
}
int main ()
{
	int a;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<a;i++){
		int element;
		std::cin>>element;
		v.push_back(element);
		}
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		Smjer y;
		int x;
		for(;;){
			std::cin>>x;
			if(x==1 || x==2)
			break;
			else std::cout<<"Pogresan unos: ";
		}
		if(x==1)
		y=Rastuci;
		else
		y=Opadajuci;
		std::vector<std::vector<int>> ispis(10, std::vector<int>(9, 0)),nizovi ;
		ispis=MaksimalniPodnizoviStepenaDvojke(v,y);
		for(int i=0; i<ispis.size();i++){
		int brojac(0);
		int j,k;
		for(j=0;j<ispis.at(i).size();j++){
			if(ispis.at(i).at(j)==0)
			brojac++;
		}
		k=ispis.at(i).size()-brojac;
		ispis.at(i).resize(k);
	} 
	if(x==1){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0;i<ispis.size();i++){
			for(int j=0;j<ispis.at(i).size();j++){
				
				if(ispis.at(i).size()<2)
				break;
				if(ispis.at(i).at(j)!=0)
				std::cout<<ispis.at(i).at(j)<<" ";
			}
			if(ispis.at(i).size()>1)
			std::cout<<std::endl;
		}
	}else
	{
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0;i<ispis.size();i++){
			for(int j=0;j<ispis.at(i).size();j++){
				
				if(ispis.at(i).size()<2)
				break;
				if(ispis.at(i).at(j)!=0)
				std::cout<<ispis.at(i).at(j)<<" ";
			}
			if(ispis.at(i).size()>1)
			std::cout<<std::endl;
		}
	}
	
	
	
	return 0;
}