#include<iostream>
#include<vector>
#include <iomanip>
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

bool najduzi_podniz(std::vector<double>v,std::vector<double>temp){
	
	int p;
	bool najduzi(true);
																								//{1,3,2,6,7,9,10,4,3,1,7},{2,6,7,9,10}
	for(int i=0;i<v.size();i++){
		
		int j=0;
		if(v[i]==temp[j]){
			p = i;
			while(v[i]==temp[j] && i!=v.size() && j!=temp.size()){
				i++;
				j++;
				if(j==temp.size() || i==v.size())break;
			}
			
			if(j==temp.size()){
				if((p==0 && i==v.size()) || (p==0 && v[i]<v[i-1] ) || (i==v.size() && v[p-1]>=v[p]) || (v[i]<=v[i-1] && v[p-1]>=v[p] )){
					najduzi = true;
				}else return false;
				
			}else{
				
				i--;
			}
			
		}
		
		
	}
	
	return najduzi;
	
}

//fja bool za opadajuce podnizove

bool najduzi_opadajuci_podniz(std::vector<double>v,std::vector<double>temp){
	
	int p;
	bool najduzi(true);
	int brojac(0);																	//{1,3,2,6,7,9,10,4,3,1,7},{2,6,7,9,10}
	for(int i=0;i<v.size();i++){
		
		int j=0;
		if(v[i]==temp[j]){
			p = i;
			while(v[i]==temp[j] && i!=v.size() && j!=temp.size()){
				i++;
				j++;
				if(j==temp.size() || i==v.size())break;
			}
			
			if(j==temp.size()){
				if((p==0 && i==v.size()) || (p==0 && v[i]>=v[i-1] ) || (i==v.size() && v[p-1]<=v[p]) || (v[i]>=v[i-1] && v[p-1]<=v[p] )){
					
					//treba nesto iskombinovat da ako imamo vise ponavljanja istog podniza vrati true samo kad se zadnji put posalje mozda da posaljemo fji  jos jedan parametar 
					//mozda indeks pocetka niza pa naspram toga
					najduzi = true;
				}else return false;
				
			}else{
				
				i--;
			}
			
		}
		
		
	}
	
	return najduzi;
	
}

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){
	
	
	std::vector<std::vector<double>>p;
/*	if(v.size()==0)return p;
	if(v.size()==1){
		//p.push_back(v);
		return p;
	}	*/												//0.1,0.1,0.9,0.9,-0.1,0.1,-0.9,0.9,-0.1,0.1,0.9,0.9,0.1,-0.1,0.9,-0.9
	
	
	std::vector<double>temp;
	
	for(int i=0;i<(int)v.size()-1;i++){
		
		if(v[i]<=v[i+1]){
		
			while(v[i]<=v[i+1]){
				temp.push_back(v[i]);
				i++;
			if(i==v.size()-1)break;	
			}
			temp.push_back(v[i]);
		
		
			//ovdje u uslovu zadatka treba provjeriti sta se trazi da li uopste treba ovo najduzi podniz ako zatreba treba dole jos dodati else temp.clear()da izbrise prethodne elemente
			if(/*najduzi_podniz(v,temp)*/true){
				//ako je najduzi podniz u vectoru onda on postaje jedan red vektora vektora p
				//ubacujemo 
			
				p.push_back(temp);
			
				temp.clear();
				
				
			}
			
		}
	}
	return p;
}


//fja opadajuci podnizovi
std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
	
	std::vector<std::vector<double>>p;
/*	if(v.size()==0)return p;
	if(v.size()==1){
		//p.push_back(v);
		return p;
	}*/

	std::vector<double>temp;
	
	for(int i=0;i<(int)v.size()-1;i++){
		
		if(v[i]>=v[i+1]){
		
			while(v[i]>=v[i+1]){
				temp.push_back(v[i]);
				i++;
			if(i==v.size()-1)break;	
			}
			temp.push_back(v[i]);
			
		
			
			if(/*najduzi_opadajuci_podniz(v,temp)*/true){
				//ako je najduzi podniz u vectoru onda on postaje jedan red vektora vektora p
				//ubacujemo 
				
				p.push_back(temp);
				temp.clear();
				
				
			}
			
		}
	}
	return p;
}

int main ()
{
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	double x;
	std::vector<double> v;
	
	for(int i=0;i<n;i++){
		std::cin>>x;
		v.push_back(x);
	}
	
	std::vector<std::vector<double>> rp(RastuciPodnizovi(v));
	std::vector<std::vector<double>> op(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	
	for(std::vector<double>red : rp){
		for(double p: red)std::cout<<std::setprecision(12)<<p<<" ";
		std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	
	for(std::vector<double>red : op){
		for(double p: red)std::cout<<std::setprecision(12)<<p<<" ";
		std::cout<<std::endl;
	}
	return 0;
}


