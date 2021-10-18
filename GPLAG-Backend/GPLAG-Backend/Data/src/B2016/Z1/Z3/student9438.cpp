/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	

#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

std::vector<bool> Funkcija (std::vector<double> v, bool t){
	std::vector<bool> clanovi;
	if(t){
	if(v[0]>v[1]) clanovi.push_back(false);
	else clanovi.push_back(true);
	for(int i=1; i<v.size()-1; i++){
		if(v[i]>=v[i-1]||v[i]<=v[i+1]) clanovi.push_back(true);
		else clanovi.push_back(false);
	}
	if(v[v.size()-2]<=v[v.size()-1]) clanovi.push_back(true);
	else clanovi.push_back(false);
	}
	else{
		if(v[0]<v[1]) clanovi.push_back(false);
		else clanovi.push_back(true);
		for(int i=1; i<v.size()-1; i++){
			if(v[i]<=v[i-1]||v[i]>=v[i+1]) clanovi.push_back(true);
			else clanovi.push_back(false);
		}
		if(v[v.size()-2]>=v[v.size()-1]) clanovi.push_back(true);
		else clanovi.push_back(false);
	}
	return clanovi;
}

matrica RastuciPodnizovi(std::vector<double> v){
	matrica podniz;
	if(!v.size()) return podniz;
	podniz.resize(1);
	std::vector<bool> b(Funkcija(v, true));
	int brojac(0);
	for(int i=0; i<v.size(); i++){
		if(!b[i]) continue;
		if(b[i]) podniz[brojac].push_back(v[i]);
		if(i!=v.size()-1&&b[i]&&!b[i+1]){
			podniz.resize(brojac+2);
			brojac++;
		}
	}
	return podniz;
}

matrica OpadajuciPodnizovi(std::vector<double> v){
	matrica podniz;
	if(!v.size()) return podniz;
	podniz.resize(1);
	std::vector<bool> b(Funkcija(v, false));
	int brojac(0);
	for(int i=0; i<v.size(); i++){
		if(!b[i]) continue;
		if(b[i]) podniz[brojac].push_back(v[i]);
		if(i!=v.size()-1&&b[i]&&!b[i+1]){
			podniz.resize(brojac+2);
			brojac++;
		}
	}
	return podniz;
}

int main ()
{
	/*std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i=0; i<n; i++){
		std::cin>>v[i];
	}
	matrica m=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> red: m){
		for(double x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	matrica o=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> red: o){
		for(double x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	std::vector<double> brojevi {0.1, 0.1, 0.9, 0.9, -0.1, 0.1, -0.9, 0.9, -0.1, 0.1, 0.9, 0.9, 0.1, -0.1, 0.9, -0.9};
    std::vector<std::vector<double>> rastuci {RastuciPodnizovi(brojevi)}, opadajuci {OpadajuciPodnizovi(brojevi)};

    for (auto niz : rastuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "_" << std::endl;
    for (auto niz : opadajuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }
	return 0;
}
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> matrica;

matrica Izbaci( matrica c){
	for(int i=0; i<c.size(); i++){
		if(c[i].size()==0){
			 c.erase(c.begin()+i);
			 i--;
		}
	}
	return c;
}

matrica RastuciPodnizovi(std::vector<double> v){
	matrica c;
	if(v.size()==0) return c;
	c.resize(1);
	double x=v[0];
	int br=0;
	for(int i=1; i<v.size(); i++){
		if(v[i]>=x){
			if(c[br].size()==0) c[br].push_back(x);
			c[br].push_back(v[i]);
			x=v[i];
		}
		else{
		c.resize(br+2);
		br++;
		x=v[i];
		} 
	}
	c=Izbaci(c);
	return c;
}

matrica OpadajuciPodnizovi(std::vector<double> v){
	matrica c;
	if(v.size()==0) return c;
	c.resize(1);
	double x=v[0];
	int br=0;
	for(int i=1; i<v.size(); i++){
		if(v[i]<=x){
			if(c[br].size()==0) c[br].push_back(x);
			c[br].push_back(v[i]);
			x=v[i];
		}
		else{
			c.resize(br+2);
			br++;
			x=v[i];
		}
	}
	c=Izbaci(c);
	return c;
}

int main(){
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i=0; i<n; i++){
		std::cin>>v[i];
	}
	matrica m=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> red: m){
		for(double x: red) std::cout<<std::setprecision(12)<<x<<" ";
		std::cout<<std::endl;
	}
	matrica o=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> red: o){
		for(double x: red) std::cout<<std::setprecision(12)<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}