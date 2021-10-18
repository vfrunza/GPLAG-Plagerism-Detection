/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
const double E(1e-10);

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi (std::vector<double> a){
	int p,q;
	matrica d;
	for(int i(0); i< int(a.size())-1;i++){
		if(a[i]<=a[i+1] || std::fabs(a[i]-a[i+1])<=E*(std::fabs(a[i])+std::fabs(a[i+1]))){
			std::vector<double> s;
			p=i;
			q=i+1;
			s.push_back(a[p]);
			s.push_back(a[q]);
			while((q+1)<a.size() && (a[q]<=a[q+1] || std::fabs(a[q]-a[q+1])<=E*(std::fabs(a[q])+std::fabs(a[q+1])))){
					s.push_back(a[q+1]);
					q++;
			}
			
			d.push_back(s);
		
			i=q;
		}
	}
	
	return d;
}

matrica OpadajuciPodnizovi( std::vector<double> a){
	int p, q;
	matrica d;
	for(int i(0);i< int(a.size())-1;i++){
		if(a[i]>=a[i+1] || std::fabs(a[i+1]-a[i])<= E*(std::fabs(a[i])+std::fabs(a[i+1]))){
			std::vector<double> s;
			p=i;
			q=i+1;
			s.push_back(a[p]);
			s.push_back(a[q]);
			while((q+1)<a.size() && (a[q]>=a[q+1] || std::fabs(a[q]-a[q+1])<=E*(std::fabs(a[q])+std::fabs(a[q+1])))){
			s.push_back(a[q+1]);
			q++;
		}
		d.push_back(s);
		i=q;
		
	}
	}
	return d;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int a;
	std::cin >> a;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>b ;
	double x;
	for(int i(0);i<a;i++){
		std::cin >> x;
		b.push_back(x);
	}
	matrica c,d;
	c=RastuciPodnizovi(b);
	d=OpadajuciPodnizovi(b);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0);i<c.size();i++){
		for(int j(0);j<c[i].size();j++) std::cout<<c[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;

	for(int i(0);i<d.size();i++){
		for(int j(0);j<d[i].size();j++) std::cout<<d[i][j]<<" ";
		std::cout<<std::endl;
	}
	
	return 0;

}





