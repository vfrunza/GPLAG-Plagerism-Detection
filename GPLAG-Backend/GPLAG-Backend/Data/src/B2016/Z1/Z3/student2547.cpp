/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
/*
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){

	std::vector<std::vector<double>>mat;
	std::vector<double>pomocni;
	
...SVI ELEMENTI PO USLOVU...
	 int i {0}
	for(int i = 0 && int j = i + 1; i < v.size() && j < v.size();i++ && j++){
		
		if(i - 1 >= 0){
			
			
			if(v.at(i - 1) <= v.at(i) && v.at(i) >= v.at(j)){
			.... 3 10 
				pomocni.push_back(v.at(i));
			}
			
			if(v.at(i) <= v.at(j)){
			...	2 6 7 9 1 
				pomocni.push_back(v.at(i));
				
				if(j == v.size() - 1){
					.... 7 
					pomocni.push_back(v.at(j));
				}
			}
		
			 
			else{
				... OSTALI ELEMENTI
				continue;
			}
			
		}
	}
...PUSH_BACK PO USLOVU 
	mat.push_back(std::vector<double>());
...CITAV VEKTOR ELEMENATA IZ USLOVA U MATRICU RED PO RED
	int poc = 0, k = 0;
	for(int i = 0 && j = i + 1; i < pomocni.size() &&  j < pomocni.size(); i++ && j++){
		if(pomocni.at(i) > pomocni.at(j)){
			for(int l = poc; l < j; l++){
				mat[k].push_back(pomocni.at(l));
				mat.push_back(std::vector<double>());
			}
			k++;
			poc = j;
		}
...ZADNJI VEKTOR...
	if(j == pomocni.size() - 1){
		mat.push_back(std::vector<double>());
		for(int p = poc; p <= j; p++){
			mat[k].push_back(pomocni.at(p));
		}
	}
	}
return mat;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
	
	std::vector<std::vector<double>>mat;
	std::vector<double>pomocni;
	
... SVI ELEMENTI PO USLOVU
	for(int i = 1 &&  j = i + 1; i < v.size() && j < v.size(); i++ && j++){
		if(i - 1 >= 0){
			
			
			if(v.at(i - 1) >= v.at(i) && v.at(i) <= v.at(j)){
			... 2 1 
				std::cout<<v.at(i - 1) <<" > "<< v.at(i)<< " < " << v.at(j) <<"\n";
					if(i - 1 == 0) pomocni.push_back(v.at(i - 1));
				
				pomocni.push_back(v.at(i));
					
					if(j == v.size() - 1) pomocni.push_back(v.at(j));
			}
			
			else if(v.at(j) <= v.at(i) && v.at(i) <= v.at(i - 1)){
				 3 10 4 3
				std::cout<<v.at(i - 1) << " < " << v.at(i) << " > " << v.at(j)<<" \n ";
				
				pomocni.push_back(v.at(i));
				
				if(j == v.size() - 1) pomocni.push_back(v.at(j));
				
			}
			
			
		 
			if(v.at(j) <= v.at(i)){
				... 3 10 4 3 
				pomocni.push_back(v.at(i));
				if(j == v.size() - 1){
					pomocni.push_back(v.at(j));
				}
			}
			
		
			
			else{
				... OSTALI ELEMENTI
				continue;
			}
		
		}
	}
	
...PUSH_BACK PRAZAN VEKTOR
	mat.push_back(std::vector<double>());
... CITAV VEKTOR ELEMENATA
	int poc = 0,k = 0;
	for(int i = 0 &&  j < i + 1; i < pomocni.size() && j < pomocni.size(); i++ && j++){
		if(pomocni.at(i) < pomocni.at(j)){
			for(int l = poc; l <= j; l++){
				mat[k].push_back(pomocni.at(l));
				...DODAJE NOVI PRAZAN...
				mat.push_back(std::vector<double>());
			}
			k++;
			poc = j;
		}
		
		if( j == pomocni.size() - 1){
			mat.push_back(std::vector<double>());
			for(int p = poc; p <= j;p++){
				mat[k].push_back(pomocni.at(p));
			}
		}
	}
	return mat;
}
*/


std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double> m){
	std::vector<std::vector<double>>mat;
	
	int k {0};
	mat.push_back(std::vector<double>());
	
	int i {0}, j {1};
	while(i < m.size() && j < m.size()){
		
		if(m.at(i) <= m.at(j)){
			
			mat[k].push_back(m.at(i));
			
				if(j + 1 < m.size() - 1){
					
					if(m.at(j + 1) <= m.at(j)){
						
						mat[k].push_back(m.at(j));
					}
				}
			
				if(j == m.size() - 1 && m.at(i) <= m.at(j)){
					mat[k].push_back(m.at(j));
				}
		}else{
			
				if(mat[k].size() != 0){
					mat.push_back(std::vector<double>() );
					k++;
				}
			}
		i++;
		j++;
	}
	return mat;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>m){
	
	std::vector<std::vector<double>> mat;
	
	int k {0};
	mat.push_back(std::vector<double>());
	
	int i {0}, j {1};
	
	while(i < m.size() && j < m.size()){
		
		if(m.at(i) >= m.at(j)){
			
			mat[k].push_back(m.at(i));
			
				if(j + 1 < m.size() - 1){
					
					if(m.at(j + 1) >= m.at(j)){
						
						mat[k].push_back(m.at(j));
					}
				}
				
			if(j == m.size() - 1 && m.at(i) >= m.at(j)){
				mat[k].push_back(m.at(j));
			}
		}
		else{
			
			if(mat[k].size() != 0){
				mat.push_back(std::vector<double>());
				k++;
			}
		}
	i++;
	j++;
	}
	
	return mat;
}
int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<double>v;
	std::cout<<"Unesite elemente vektora: ";
	for(int i = 0; i < n; i++){
		double br;
		std::cin>> br;
		v.push_back(br);
	}

	
	
	std::cout<<"Maksimalni rastuci podnizovi:\n";
	std::vector<std::vector<double>>rastuci = RastuciPodnizovi(v);
	for(int i = 0; i < rastuci.size();i++){
		for(int j = 0; j < rastuci[i].size();j++){
			std::cout<< rastuci[i][j] <<" ";
		}
		std::cout<<"\n";
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi:\n";
	std::vector<std::vector<double>>opadajuci = OpadajuciPodnizovi(v);
	for(int i = 0; i < opadajuci.size();i++){
		for(int j = 0; j < opadajuci[i].size();j++){
			std::cout<< opadajuci[i][j] <<" ";
		}
		std::cout<<"\n";
	}
}