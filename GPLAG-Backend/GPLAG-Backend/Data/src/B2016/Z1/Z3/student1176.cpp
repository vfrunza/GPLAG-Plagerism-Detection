#include<iostream> 
#include<vector> 
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor){
	std::vector<std::vector<double>> x;
	std::vector<double> pomocni;
	for(int i(0); i<vektor.size()-1; i++){
		while(i<vektor.size()-1 && vektor[i]<=vektor[i+1]){
			pomocni.push_back(vektor[i]);
			i++;
		}  
		 
		if(pomocni.size()!=0){
			pomocni.push_back(vektor[i]);
			x.push_back(pomocni);
		} 
		pomocni.resize(0);
	}  
	return x;	
} 
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor){
	std::vector<std::vector<double>> x; 
	std::vector<double> pomocni;
	for(int i(0); i<vektor.size()-1; i++){
		while(i<vektor.size()-1 && vektor[i]>=vektor[i+1]){
			pomocni.push_back(vektor[i]);
			i++;
		}   
		 
		if(pomocni.size()!=0) {
			pomocni.push_back(vektor[i]);
			x.push_back(pomocni);
		}
		pomocni.resize(0);
	} 
	return x;
}
int main ()
{
	int n; 
	std::vector<double> brojevi;
	std::cout << "Unesite broj elemenata vektora: "; 
	std::cin >> n;
	brojevi.resize(n); 
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<brojevi.size(); i++) std::cin >> brojevi[i]; 
	std::vector<std::vector<double>> Rastuca(RastuciPodnizovi(brojevi)); 
	std::vector<std::vector<double>> Opadajuca(OpadajuciPodnizovi(brojevi)); 
	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<Rastuca.size(); i++){
		for(int j=0; j<Rastuca[i].size(); j++) std::cout << Rastuca[i][j] << " "; 
		std::cout << std::endl;
	} 
	std::cout << "Maksimalni opadajuci podnizovi: \n"; 
	for(int i(0); i<Opadajuca.size(); i++){
		for(int j(0); j<Opadajuca[i].size(); j++) std::cout << Opadajuca[i][j] << " ";  
		std::cout << std::endl;
	}
	return 0;
}