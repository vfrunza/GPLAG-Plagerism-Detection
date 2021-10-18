/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> a){
	matrica pov_mat;
	if(a.size()==0) return pov_mat;
	std::vector<double> rastuci;
	for(int i=0; i<a.size()-1; i++){
		rastuci.resize(0);
		rastuci.push_back(a[i]);
			if(a.at(i)<=a.at(i+1)){
			while(a.at(i)<=a.at(i+1)) {
      	      rastuci.push_back(a.at(i+1));
      	      i++;
      	      if(i==a.size()-1) break;
			}
	 if(rastuci.size()>1){ pov_mat.push_back(rastuci); }
            }
    }return pov_mat;
}

matrica OpadajuciPodnizovi(std::vector<double> b){
	matrica pov_mat;
	if(b.size()==0) return pov_mat;
	std::vector<double> opadajuci;
	for(int i=0; i<b.size()-1; i++){
		opadajuci.resize(0);
		opadajuci.push_back(b[i]);
			if(b.at(i)>=b.at(i+1)){
			while(b.at(i)>=b.at(i+1)) {
			opadajuci.push_back(b.at(i+1));
			i++;
			if(i==b.size()-1) break;
		    } 
	if(opadajuci.size()>1){ pov_mat.push_back(opadajuci); }
		   }
    }return pov_mat;
}

int main ()
{
	std::vector<double> vek;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout<<"Unesite elemente vektora: ";
	int br;
	for(int i=0; i<n; i++){
		std::cin >> br;
		vek.push_back(br);
	}
	
	std::vector<std::vector<double>> Rastuci(RastuciPodnizovi(vek));
	std::vector<std::vector<double>> Opadajuci(OpadajuciPodnizovi(vek));
	
		std::cout<<"Maksimalni rastuci podnizovi: " << std::endl;
		for(int i=0; i<Rastuci.size(); i++){
			for(int j=0; j<Rastuci[i].size(); j++){
				std::cout << Rastuci[i][j] << " ";
			} std::cout<<std::endl;
		}
		std::cout<<"Maksimalni opadajuci podnizovi: " << std::endl;
		for(int k=0; k<Opadajuci.size(); k++){
			for(int l=0; l<Opadajuci[k].size(); l++){
				std::cout << Opadajuci[k][l] << " ";
			}
		}
	return 0;
}