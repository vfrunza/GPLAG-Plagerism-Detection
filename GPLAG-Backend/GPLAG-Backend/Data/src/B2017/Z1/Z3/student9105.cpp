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
#include <deque>
#include <vector>
#include <iomanip>

typedef std::deque<std::vector<int>> dek_vektora;
dek_vektora KreirajDekVektora(int broj_vektora_deka,int broj_cijelih_brojeva_u_vektoru)
{
    return dek_vektora(broj_vektora_deka, std::vector<int>(broj_cijelih_brojeva_u_vektoru));
}
enum Smjer {Rastuci=1, Opadajuci=2};
dek_vektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	dek_vektora D_V;
	int a(0),m(0),n(0),p2(1),brojac(0),brojac_r(0);
	std::vector<int> potenc,brojac_k;
		for(int i=0; i<v.size(); i++){
			if(v.at(i)==0){
				p2=0;
				potenc.push_back(p2);
			}
			else{
			a=v.at(i);
			do{
			if(a%2!=0 && a!=1){
				p2=0;
				potenc.push_back(p2);
				break;
			}
			a/=2;
			}
			while(a!=0);
			if(potenc.size()!=i+1){
				p2=1;
				potenc.push_back(p2);
			}
			}
		}
		if(s==Rastuci){
			for(int i=0; i<potenc.size(); i++){
			while(i+1<potenc.size() && potenc.at(i)==1 && v.at(i)<v.at(i+1) && potenc.at(i+1)==1){
				brojac++;
				i++;
			}
			if(brojac!=0){
				brojac_k.push_back(brojac+1);
				brojac_r++;
				brojac=0;
			}
		}
		D_V.resize(brojac_r);
		for(int i=0; i<brojac_r; i++) D_V.at(i).resize(brojac_k.at(i));
		for(int i=0; i<v.size(); i++){
			while(i+1<potenc.size() && potenc.at(i)==1 && v.at(i)<v.at(i+1) && potenc.at(i+1)==1){
				D_V.at(m).at(n)=v.at(i);
				n++;
				i++;
			}
			if(n!=0){
			D_V.at(m).at(n)=v.at(i);
			m++;
			n=0;
			}
		}
	}	
	if(s==Opadajuci){
		for(int i=0; i<potenc.size(); i++){
			while(i+1<potenc.size() && potenc.at(i)==1 && v.at(i)>v.at(i+1) && potenc.at(i+1)==1){
				brojac++;
				i++;
			}
			if(brojac!=0){
				brojac_k.push_back(brojac+1);
				brojac_r++;
				brojac=0;
			}
		}
		D_V.resize(brojac_r);
		for(int i=0; i<brojac_r; i++) D_V.at(i).resize(brojac_k.at(i));
		for(int i=0; i<v.size(); i++){
			while(i+1<potenc.size() && potenc.at(i)==1 && v.at(i)>v.at(i+1) && potenc.at(i+1)==1){
				D_V.at(m).at(n)=v.at(i);
				n++;
				i++;
			}
			if(n!=0){
			D_V.at(m).at(n)=v.at(i);
			m++;
			n=0;
			}
		}
	}	
	return D_V;
}
int main ()
{
	std::vector<int> vektor;
	dek_vektora pod_niz;
	int n,a,x;
	Smjer X;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>a;
		vektor.push_back(a);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>x;
	if(x==1) X=Smjer(1);
	if(x==2) X=Smjer(2);
	pod_niz=MaksimalniPodnizoviStepenaDvojke(vektor,X);
	if(X==Smjer(1)) std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	if(X==Smjer(2)) std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<pod_niz.size(); i++){
		for(int j=0; j<pod_niz.at(i).size(); j++){
			std::cout<<pod_niz.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}