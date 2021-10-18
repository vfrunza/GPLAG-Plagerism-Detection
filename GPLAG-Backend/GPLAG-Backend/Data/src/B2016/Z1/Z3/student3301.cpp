/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


typedef std::vector<std::vector<double>> Matrica ;

Matrica RastuciPodnizovi (std::vector<double> v){
	Matrica m;
	int n(v.size());
	for(int i=0; i<n-1; i++){
		if(i<n-1 && v[i]<=v[i+1] ){
			m.resize(m.size()+1);
			
			while(i<n-1 && v[i]<=v[i+1] ){
				m[m.size()-1].push_back(v[i]);
				i++;
			}
			m[m.size()-1].push_back(v[i]);
		}
	}
return m;
}

Matrica OpadajuciPodnizovi (std::vector<double> v){
	Matrica m;
	int n(v.size());
	for(int i=0; i<n-1; i++){
		if(i<n-1 && v[i]>=v[i+1]){
			m.resize(m.size()+1);
			while(i<n-1 && v[i]>=v[i+1]){
				m[m.size()-1].push_back(v[i]);
				i++;
			}
			m[m.size()-1].push_back(v[i]);
		}
	}
return m;
}

int main ()
{
	int broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v(broj);
	for(int i=0; i<broj; i++)
	  std::cin>>v[i];
	Matrica m(RastuciPodnizovi(v)), n(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
    for(int i=0; i<m.size(); i++){
    	for(int j=0; j<m[i].size(); j++){
    		std::cout<<m[i][j]<<" ";
    	
    	}
    std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
    for(int i=0; i<n.size(); i++){
    	for(int j=0; j<n[i].size(); j++){
    		std::cout<<n[i][j]<<" ";
    	}
    std::cout<<std::endl;
    }
	return 0;
}