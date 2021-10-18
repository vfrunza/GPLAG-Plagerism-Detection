/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	
	std::vector<std::vector<double>> m;
	std::vector<double> rastuci;
	bool e(false);
	
	for(int i(0);i<v.size();i++){
		
		if(i==v.size()-1 && (e==false))
		break;
		
		else if(i==v.size()-1 && (e==true)){
			rastuci.push_back(v[i]);
			m.push_back(rastuci);
			break;
		}
		
		else if(v[i]<=v[i+1]){
			rastuci.push_back(v[i]);
			e=true;
		}
		
		else if(v[i]>=v[i+1]){
			
			if(e==true){
				
				rastuci.push_back(v[i]);
				m.push_back(rastuci);
		}
		rastuci={};
		e=false;
		
	}
	}
	
	return m;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	
	std::vector<std::vector<double>> m;
	std::vector<double> opadajuci;
	bool e(false);
	
	for(int i(0);i<v.size();i++){
		
		if(i==v.size()-1 && (e==true)) {
			opadajuci.push_back(v[i]);
			m.push_back(opadajuci);
			break;
		}
		
		else if(i==v.size()-1 && (e==false))
			break;
			
		else if(v[i]>=v[i+1]){
			opadajuci.push_back(v[i]);
			e=true;
		}
		
		else if(v[i]<=v[i+1]){
			if(e==true){
				opadajuci.push_back(v[i]);
				m.push_back(opadajuci);
			}
			
			opadajuci={};
			e=false;
			
		}
	}
	
	return m;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::vector<double> ve;
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i(0);i<n;i++){
		double br;
		std::cin>>br;
		ve.push_back(br);
	}
	
	std::vector<std::vector<double>> opadajuci,rastuci;
	
	rastuci=RastuciPodnizovi(ve);
	opadajuci=OpadajuciPodnizovi(ve);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0);i<rastuci.size();i++){
		for(int j(0);j<rastuci[i].size();j++){
			std::cout<<rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int k(0);k<opadajuci.size();k++){
		for(int l(0);l<opadajuci[k].size();l++){
			std::cout<<opadajuci[k][l]<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}