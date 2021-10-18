#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> matrica;
matrica RastuciPodnizovi(std::vector<double> v){
	std::vector<double>podniz[100];
	int brojac(0),k(0),n(0);
	for(int i=0; i<v.size(); i++){
		if(i>0){
		k=0;
		while(v[i]>=v[i-1] && i<v.size()){
			if(i>=2 && k==0 && n!=0){
				if(v[i-1]<=v[i-2]) podniz[brojac].push_back(v[i-1]);
				k++;
			}
			if(i-1==0) podniz[brojac].push_back(v[i-1]);
			podniz[brojac].push_back(v[i]);
			if(i==v.size()-1) break;
			i++; 
			if(v[i]<v[i-1]){
				brojac++;
				n++;
				i--;
				break;
			
			}
		}
		}
	}

	matrica povratna(brojac+1);
	for(int i=0; i<brojac+1; i++){
		povratna[i]=podniz[i];
	}
	return povratna;
}
matrica OpadajuciPodnizovi(std::vector<double> v){
	std::vector<double>podniz[100];
	int brojac(0),k(0),n(0);
	for(int i=0; i<v.size(); i++){
		if(i>0){
		k=0;
		while(v[i]<=v[i-1] && i<v.size()){
			if( (i>=2 && k==0 && n!=0) || (i>=2 && k==0 && brojac==0)){
				if(v[i-1]>v[i-2]) podniz[brojac].push_back(v[i-1]);
				k++;
			}
			if(i-1==0) podniz[brojac].push_back(v[i-1]);
			podniz[brojac].push_back(v[i]);
			if(i==v.size()-1) break;
			i++; 
			if(v[i]>v[i-1]){
				brojac++;
				n++;
				i--;
				break;
			
			}
		}
		}
	}
	
	matrica povratna(brojac+1);
	for(int i=0; i<brojac+1; i++){
		povratna[i]=podniz[i];
	}
	return povratna;
}

int main ()
{
	int n;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;
std::vector<double> v(n);
std::cout<<"Unesite elemente vektora: ";
for(int i=0; i<n; i++){
	std::cin>>v[i];
}
matrica ispis;
ispis=RastuciPodnizovi(v);
std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
for(int i=0; i<ispis.size(); i++){
	for(int j=0; j<ispis[i].size(); j++){
		std::cout<<ispis[i][j]<<" ";
	}
	std::cout<<std::endl;
}
ispis=OpadajuciPodnizovi(v);
std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
for(int i=0; i<ispis.size(); i++){
	for(int j=0; j<ispis[i].size(); j++){
		std::cout<<ispis[i][j]<<" ";
	}
	std::cout<<std::endl;
}

return 0;
}