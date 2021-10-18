#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> Matrica;
Matrica OpadajuciPodnizovi(std::vector<double>v){
	Matrica a;
	int kolona{1}, red{1}, ind{0}, poz, broj{0}, i, k, pokaz{0};
	if(v.size()==1){}
	else{
	for(i=0; i<v.size(); i++){
		if(i==0){
			kolona=1;
			poz=i;
			i++;
		}
		if(v[i]<=v[i-1]){kolona++; pokaz=1; if(ind==0){poz=i-1; ind=1;}}
		else{
			if(kolona>1){
				a.resize(red);
				a[red-1].resize(kolona);
				broj=0;
				pokaz=0;
				for(k=poz; k<poz+kolona; k++){
					if(ind==1){a[red-1][broj]=v[poz]; broj++; ind=0; k=poz+1;}
					a[red-1][broj]=v[k];
					broj++;
				}
				red++;
				kolona=1;
				poz=i;
			}
			else{kolona=1; poz=i; }
		}
	}
	}
	if(pokaz==1){
		a.resize(red);
		a[red-1].resize(kolona);
		broj=0;
		for(k=poz; k<poz+kolona; k++){
			if(ind==1){a[red-1][broj]=v[poz]; broj++; ind=0; k++;}
			a[red-1][broj]=v[k]; broj++;
		}
	}
	return a;
}
Matrica RastuciPodnizovi(std::vector<double>v){
	Matrica a;
	int kolona{1}, red{1}, ind{0}, poz, broj{0}, i, k, pokaz{0};
	if(v.size()==1) {}
	else{
	for(i=0; i<v.size(); i++){
     if(i==0){
     	kolona=1;
     	poz=i;
    	i++;
     }
     if(v[i]>=v[i-1]){kolona++; pokaz=1; if(ind==0) {poz=i-1; ind=1;}}
     else{
     	if(kolona>1){
     		a.resize(red);
     		a[red-1].resize(kolona);
     		broj=0;
     		pokaz=0;
     		for(k=poz; k<poz+kolona; k++){
     			if(ind==1){a[red-1][broj]=v[poz]; broj++; ind=0; k=poz+1;}
     			a[red-1][broj]=v[k];
     			broj++;
     		}
     		red++;
     		kolona=1;
     		poz=i;
     	}
     	else{kolona=1; poz=i;}
     }
	}
	}
	if(pokaz==1){
		a.resize(red);
		a[red-1].resize(kolona);
		broj=0;
		for(k=poz; k<poz+kolona; k++){
		if(ind==1){a[red-1][broj]=v[poz]; broj++; ind=0; k++;}
		a[red-1][broj]=v[k]; broj++;
		}
	} 
	return a;
}
int main ()
{
	try{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin >>n;
	if(n<1) throw "Broj elemenata vektora mora biti veci od nule!";
	std::vector<double>v;
	double broj;
	std::cout <<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin >>broj;
		v.push_back(broj);
	}
	Matrica a{RastuciPodnizovi(v)};
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout <<a[i][j]<<" ";
		}
		std::cout <<std::endl;
	}
	Matrica b{OpadajuciPodnizovi(v)};
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout <<b[i][j]<<" ";
		}
		std::cout <<std::endl;
	}
	}
	catch(const char poruka[]){
		std::cout <<poruka<<std::endl;
	}
	return 0;
}