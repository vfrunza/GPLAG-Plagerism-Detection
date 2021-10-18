/*B 2016/2017, Zadaća 1, Zadatak 3 zadnji
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

std::vector<double> Taman(std::vector<double> v){
	std::vector<double>novi ;
	for(int i(0); i<v.size(); i++){
		if(i==0 || i==1 || i%2==1) novi.push_back(v.at(i));
	}
	return novi;
}

Matrica OpadajuciPodnizovi(std::vector<double> v){
    Matrica opadajuci;

	int i;
	for(int j(1); j<v.size(); j++){
    	std::vector<double> temp;
		for(i=j; i<v.size(); i+=1){
        	if(v.at(i-1)>=v.at(i)){
        	    temp.push_back(v.at(i-1));
            	temp.push_back(v.at(i));
        	}
        	else if(i>1 && (v.at(i-1)<=v.at(i)) && v.at(i-2)>=v.at(i-1)) temp.push_back(v.at(i-1));
        	else if((i==v.size()-2) && v.at(i)>=v.at(i+1)) temp.push_back(v.at(i+1));
        	else break;
    	}
    	j=i;
    if(temp.size()>1)	opadajuci.push_back(Taman(temp));
	}

	return opadajuci;
}

Matrica RastuciPodnizovi(std::vector<double> v){
    Matrica rastuci;

	int i;
	for(int j(1); j<v.size(); j++){
    	std::vector<double> temp;
		for(i=j; i<v.size(); i+=1){
        	if(v.at(i-1)<=v.at(i)){
        	    temp.push_back(v.at(i-1));
            	temp.push_back(v.at(i));
        	}
        	else if(i>1 && (v.at(i-1)>=v.at(i)) && v.at(i-2)<=v.at(i-1)) temp.push_back(v.at(i-1));
        	else if((i==v.size()-2)  && v.at(i)>=v.at(i+1)) temp.push_back(v.at(i+1));
        	else break;
    	}
    	j=i;
    	if(temp.size()>1) rastuci.push_back(Taman(temp));
	}

	return rastuci;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++){
		double temp;
		std::cin>>temp;
		v.push_back(temp);
	}
	Matrica rastuci, opadajuci;
	rastuci=RastuciPodnizovi(v);
	opadajuci=OpadajuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0); i<rastuci.size(); i++){
		for(int j(0); j<rastuci[i].size(); j++){
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i(0); i<opadajuci.size(); i++){
		for(int j(0); j<opadajuci[i].size(); j++){
			std::cout<<opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}