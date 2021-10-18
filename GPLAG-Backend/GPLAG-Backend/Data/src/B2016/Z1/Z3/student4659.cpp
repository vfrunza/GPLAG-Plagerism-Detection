/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(Vektor v){
	Vektor a;
	Matrica m;
	for(int i=0;i<(int)v.size()-1;i++){
		while(v[i]<=v[i+1]){
			a.push_back(v[i]);
			i++;
			if(i==v.size()-1)break;
		}
	if(!a.empty()){
	    a.push_back(v[i]);
		m.push_back(a);
	}	
		a.clear();
	}
	return m;
}
Matrica OpadajuciPodnizovi(Vektor v){
	Vektor a;
	Matrica m;
	for(int i=0;i<(int)v.size()-1;i++){
		while(v[i]>=v[i+1]){
			a.push_back(v[i]);
			i++;
			if(i==v.size()-1)break;
		}
		if(!a.empty()){
			a.push_back(v[i]);
			m.push_back(a);
		}
		
		a.clear();
	}
	return m;
}
int main (){   
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	    std::cout << "Unesite elemente vektora: ";
	    Vektor v;
	    for(int i=0;i<n;i++){
	    	double x;
	    	std::cin >> x;
	    	v.push_back(x);
	    }
	        std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
	        Matrica a;
	        a=RastuciPodnizovi(v);
	            for(int i=0;i<a.size();i++){
	            	for(int j=0;j<a[i].size();j++){
	            		std::cout << a[i][j] << " ";
	            	}
	            	std::cout << std::endl;
	            }
	        std::cout << "Maksimalni opadajuci podnizovi: "<< std::endl;
	        Matrica b;
	        b=OpadajuciPodnizovi(v);
	            for(int i=0;i<b.size();i++){
	            	for(int j=0;j<b[i].size();j++){
	            		std::cout << b[i][j] << " ";
	            	}
	            	std::cout << std::endl;
	            }    
	
	return 0;
}