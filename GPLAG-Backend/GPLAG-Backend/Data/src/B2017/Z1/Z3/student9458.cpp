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
	enum  Smjer {Rastuci,Opadajuci};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector <int> v, Smjer smjeric){
	std::deque<std::vector<int>> m;
	int k=0;
	m.resize(k+1);
	if(smjeric==Rastuci){
		for(int i=0;i<v.size()-1;i++){
				if(v.at(i)<0) continue;
				else{
			if(i==v.size()) break;
			bool ubacen=false;
			bool jeste=false;
			bool jestedrugi=false;
		
			int dvica=v.at(i);
			int idrugi=v.at(i+1);
			
		     
			while(dvica%2==0 && dvica>=1 ){
				dvica=dvica/2;
			}
			while(idrugi%2==0 && idrugi>=1 ){
				idrugi=idrugi/2;
			}
			if(dvica==1) jeste=true;
			if(idrugi==1) jestedrugi=true;
		
			if( i>0 && v.at(i)<v.at(i-1) && (v.at(i)>v.at(i+1) || !jestedrugi)) continue;
			
			if(v.at(i)<v.at(i+1) && jeste && jestedrugi){
		      m[k].push_back(v[i]);
		      ubacen=true;
		}
		if((i>0 && v.at(i+1)<v.at(i) && jeste )||(v.at(i+1)>v.at(i) && !jestedrugi && jeste)){
			m[k].push_back(v[i]);
            
		}
		if(i==v.size()-2 && jestedrugi && jeste) m[k].push_back(v[i]);
		if(!ubacen && jeste && jestedrugi) {
			
			k++;
			m.resize(k+1);		}
	}
		}
}

   else if(smjeric==Opadajuci){
   	bool bio=true;
   for(int i=0;i<v.size()-1;i++){
   						if(i==v.size()) break;
			bool ubacen=false;
			bool jeste=false;
			bool jestedrugi=false;
	
			int dvica=v.at(i);
			int idrugi=v.at(i+1);
			  
		    
			while(dvica%2==0 && dvica>=1 ){
				dvica=dvica/2;
			}
			while(idrugi%2==0 && idrugi>=1 ){
				idrugi=idrugi/2;
			}
			if(dvica==1) jeste=true;
			if(idrugi==1) jestedrugi=true;
			
		     /*if(i==v.size()-2 && !jestedrugi && jeste) break;*/
			if( i>0 && v.at(i)>v.at(i-1) && v.at(i)<v.at(i+1) ) continue;
			
			if(v.at(i)>v.at(i+1) && jeste && jestedrugi){
		      m[k].push_back(v[i]);
	      ubacen=true;
		}
		if(i>0 && v.at(i+1)>v.at(i) && jeste && bio ||(v.at(i+1)<v.at(i) && !jestedrugi && jeste)){
			m[k].push_back(v[i]);
           
		}
		if(i==v.size()-2 && jestedrugi && jeste)
			m[k].push_back(v[v.size()-1]);
		if(!ubacen && jeste && jestedrugi) {
			
			k++;
			m.resize(k+1);		}
	 
   
   	bio=jeste;
   			}
   }
   
   return m;
}

int main ()
{

	int n,tip,broj;
	std::vector <int> a;
	std::cout <<"Unesite broj elemenata vektora: ";
	std::cin>> n;
	std::cout <<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin >> broj;
	   a.push_back(broj);
		
	}
	std::cout <<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >>tip;
	std::deque<std::vector<int>> konacni;
	if(tip==1) 	konacni=MaksimalniPodnizoviStepenaDvojke(a,Rastuci);
	else if( tip==2)	konacni=MaksimalniPodnizoviStepenaDvojke(a,Opadajuci);
	
	if(tip==1){
	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else std::cout <<"Maksimalni opadajuci podnizovi: ";
	for(int i=0;i<konacni.size();i++){
		for(int j=0;j<konacni[i].size();j++){
			std::cout <<konacni[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}