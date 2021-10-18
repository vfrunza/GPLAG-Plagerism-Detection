/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> a){
	std::vector<double> v;
	Matrica rez;
	for(int i=0;i<a.size();i++){
		if(i!=a.size()-1 && a[i]<=a[i+1]) v.push_back(a[i]);             //dok se ne dodje do zadnjeg clana provjerava se uslov da li je niz rastuci//
		else if(i!=0 && (i==a.size()-1 || a[i]>=a[i+1]) && a[i]>=a[i-1]){           //ubacivanje zadnjeg clana rastuceg podniza u vektor, ubacivanje vektora u matricu; provjera i za posljednji clan niza//
			v.push_back(a[i]);
			rez.push_back(v);
			v.clear();
		}
	}
	return rez;
}

Matrica OpadajuciPodnizovi(std::vector<double> a){
	std::vector<double> v;
	Matrica rez;
	for(int i=0;i<a.size();i++){
		if(i!=a.size()-1 && a[i]>=a[i+1]) v.push_back(a[i]);
		else if(i!=0 && a[i-1]>=a[i] && (i==a.size()-1 || a[i+1]>=a[i])){
			v.push_back(a[i]);
			rez.push_back(v);
			v.clear();
		}
	}
	return rez;
}


int main ()
{   
	int n;
	double x;
	std::vector<double>a;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>x;
		a.push_back(x);
	}
	Matrica rez=RastuciPodnizovi(a);
	std::cout<<"Maksimalni rastuci podnizovi:";
	std::cout<<std::endl;
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez[i].size();j++){
		    std::cout<<rez[i][j]<< " ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi:";
	std::cout<<std::endl;
	Matrica rez1=OpadajuciPodnizovi(a);
	for(int i=0;i<rez1.size();i++){
		for(int j=0;j<rez1[i].size();j++){
			std::cout<<rez1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	return 0;
}