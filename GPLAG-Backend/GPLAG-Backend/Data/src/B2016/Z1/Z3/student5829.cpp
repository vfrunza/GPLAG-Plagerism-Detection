/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector <std::vector<double>> Vektor_vektora;

int Vel1 (std::vector <double> v){
int vel(1);
	for (int i=1; i<v.size(); i++){
	if(v[i]<=v[i-1]){
		vel++;
		}
	}
	return vel;
}


int Vel2 (std::vector <double> v){
int vel(1);
	for (int i=1; i<v.size(); i++){
	if(v[i]>=v[i-1]){
		vel++;
		}
	}
	return vel;
}

Vektor_vektora Izbaci (Vektor_vektora v){
	int max(0);
	 for (int i=0; i<v.size(); i++){
    
    		if (v[i].size()<max) { 
    			max=v[i].size();
    		}
    	
    }
 
    for (int i=0; i<v.size(); i++){
    
    		if (v[i].size()<max) { v.erase (v.begin()+i);
    			i--;
    		}
    	
    }
    
    return v;
}

Vektor_vektora Izbaci1 (Vektor_vektora v){
	
	    for (int i=0; i<v.size(); i++){
    
    		if (v[i].size()==1) { v.erase (v.begin()+i);
    			i--;
    		}
    	
    }
    
    return v;
}
	




Vektor_vektora RastuciPodnizovi (std::vector  <double> v){
	
	int vel=Vel1(v);
	int p=0;
	int k;
	
	Vektor_vektora podnizovi (vel, std::vector <double>());
	int s=0;
	for (int i=1; i<v.size(); i++){
		if(v[i]<v[i-1] || i==v.size()-1){
			k=i;
			
			if (i!=v.size()-1){
			for(int l=p; l<k; l++){
				podnizovi[s].push_back(v[l]);
			}}
			
			else {
				if(v[i]<v[i-1]){
					k=i-1;
				}
				for(int l=p; l<=k; l++){
				podnizovi[s].push_back(v[l]);
			
			
				
			}}
			
			if (i==v.size()-1) break;
			
			s++;
			i=k;
			p=k;
			
		}
	}
	
	podnizovi=Izbaci1(podnizovi);
	
	return podnizovi;
		
	
}


Vektor_vektora OpadajuciPodnizovi (std::vector  <double> v){
	
	int vel=Vel2(v);
	int p=0;
	int k;
	
	Vektor_vektora podnizovi (vel, std::vector <double>());
	int s=0;
	for (int i=1; i<v.size(); i++){
		if(v[i]>v[i-1] || i==v.size()-1){
			k=i;
			
			if (i!=v.size()-1){
			for(int l=p; l<k; l++){
				podnizovi[s].push_back(v[l]);
			}}
			
			else {
				if(v[i]>v[i-1]){
					k=i-1;
				}
				for(int l=p; l<=k; l++){
				podnizovi[s].push_back(v[l]);
			
				
			}}
			
			if (i==v.size()-1) break;
			
			s++;
			i=k;
			p=k;
			
		}
	}
	
	podnizovi=Izbaci1(podnizovi);
	
	return podnizovi;
		
	
}
int main ()
{
    int n;
	
	std::cout <<"Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector <double> v(n);
	
	std::cout <<"Unesite elemente vektora: ";
	
	for(int i=0; i<n; i++){
		std::cin >> v[i];
	}

	Vektor_vektora mat_r=Izbaci(RastuciPodnizovi(v));
	Vektor_vektora mat_o=Izbaci(OpadajuciPodnizovi(v));
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;

	for(int i=0; i<mat_r.size(); i++){
        for (int j=0; j<mat_r[i].size(); j++){
            std::cout<<mat_r[i][j] << " ";

        }
        std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;

	for(int i=0; i<mat_o.size(); i++){
        for (int j=0; j<mat_o[i].size(); j++){
            std::cout<<mat_o[i][j] << " ";

        }
        std::cout << std::endl;
	}
	return 0;
}