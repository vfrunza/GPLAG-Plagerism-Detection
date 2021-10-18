/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>


typedef std::vector<std::vector<double>> Matrica;


Matrica RastuciPodnizovi(std::vector<double>v){
	Matrica rastuci;
    int brojredova(0);
	int i(0);
    while(i< int((v.size())-1)){
    	std::vector<double>pomocni;
    	int k=i;
    	while( i<int(v.size())-1 && v[i]<=v[i+1])
    		i++;
    	if (i!=k){
    		for(int j=k;j<=i;j++){
    			pomocni.push_back(v[j]);
    		}
    		brojredova++;
    		rastuci.resize(brojredova);
    		for(int j=0;j<int(pomocni.size());j++){
    			rastuci[brojredova-1].push_back(pomocni[j]);
    		}
    	}
    	i++;
    }
	
    return rastuci;
    
}
Matrica OpadajuciPodnizovi(std::vector<double>v){
	Matrica opadajuci;
    int brojredova(0);
	int i(0);
    while(i< int((v.size())-1)){
    	std::vector<double>pomocni;
    	int k=i;
    	while( i<int(v.size())-1 && v[i]>=v[i+1])
    		i++;
    	if (i!=k){
    		for(int j=k;j<=i;j++){
    			pomocni.push_back(v[j]);
    		}
    		brojredova++;
    		opadajuci.resize(brojredova);
    		for(int j=0; j<int(pomocni.size()); j++){
    			opadajuci[brojredova-1].push_back(pomocni[j]);
    		}
    	}
    	i++;
    }
	
    return opadajuci;
    
}



int main (){
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>v;
	double broj;

	for(int i=0;i<n;i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	auto rastuci=RastuciPodnizovi(v);
	auto opadajuci=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> x: rastuci){
		for(double y: x){
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> x: opadajuci){
		for(double y: x){
			std::cout<<y<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	return 0;
}