/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor_brojeva) {

std::vector<std::vector<double>>matrica ;

	for( int i(0); i<vektor_brojeva.size()-1; i++){
		if(vektor_brojeva.at(i+1)>=vektor_brojeva.at(i)) {
			std::vector<double>vektor;
			
			vektor.push_back(vektor_brojeva.at(i));
			
			while((vektor_brojeva.at(i+1)>=vektor_brojeva.at(i))) {
				vektor.push_back(vektor_brojeva.at(i+1));
				i++;
				if(i == vektor_brojeva.size()-1) break;
			}
			matrica.push_back(vektor);
		}
	}
	return matrica;

}

std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> vektor_brojeva) {
	
	std::vector<std::vector<double>>matrica;
	
	for(int i(0); i<vektor_brojeva.size()-1; i++){
		if(vektor_brojeva.at(i+1) <= vektor_brojeva.at(i)) {
			std::vector<double>vektor ;
			vektor.push_back(vektor_brojeva.at(i));
			
			while((vektor_brojeva.at(i+1) <= vektor_brojeva.at(i))) {
				vektor.push_back(vektor_brojeva.at(i+1));
				i++;
				if(i==vektor_brojeva.size()-1) break;
			}
			matrica.push_back(vektor);
		}
	}
	return matrica;
}
int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> vektor_brojeva;
	
	std::cout << "Unesite elemente vektora: ";
	double broj;
	for(int i(0); i<n; i++){
		std::cin>>broj;
		vektor_brojeva.push_back(broj);
	}
	
	std::vector<std::vector<double>> MaksimalniRastuci(RastuciPodnizovi(vektor_brojeva));

	std::cout << "Maksimalni rastuci podnizovi: \n";
	for(auto x: MaksimalniRastuci) {
		for(auto y:x)
		std::cout << y << " ";
		std::cout << "\n";
	}
	
	std::vector<std::vector<double>>MaksimalniOpadajuci(OpadajuciPodnizovi(vektor_brojeva));
		
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(auto x:MaksimalniOpadajuci) {
			for(auto y:x)
			std::cout << y <<" ";
			std::cout << "\n";
		}
	
	
	return 0;
}