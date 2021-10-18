/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

/*Matrica NadjiMaxRed(Matrica mat) {
	
	Matrica pomMat;
	int max = 0;
	for(int i = 0; i < mat.size(); i++) {                 // nadjemo najduzi red
		if(mat[i].size() > max) max = mat[i].size();
	}
	
	for(int i = 0; i < mat.size(); i++) {
		if(mat[i].size() == max) pomMat.push_back(mat[i]);
	}
	return pomMat;
}*/

Matrica IzbaciRed(Matrica mat) {
	
	for(int i = 0; i < mat.size(); i++) {
		int temp = i;
		if(mat[i].size() == 1) {
		for(int j = i + 1; j < mat.size(); j++){
			mat[i] = mat[j];
			i++;
		} 
		
		mat.resize(mat.size() - 1);
		i = temp;
		i--;
		}
	}
	return mat;
}

Matrica RastuciPodnizovi(std::vector<double> v) {
	
	std::vector<double> pomV;
	Matrica mat;
	
	for(int i = 0; i < v.size(); i++) {
		double temp = v[i];
		int br_rastucih(1);
		int j(i + 1);
		pomV.resize(0);
		while ((j < v.size()) && (v[j] >= temp)) {       // brojimo rastuce
			br_rastucih++;
			temp = v[j];
			j++;
		}
		for(int k = i; k < i + br_rastucih; k++) pomV.push_back(v[k]);
		i = i + br_rastucih - 1;
		mat.push_back(pomV);
	}
	Matrica pomMat = IzbaciRed(mat);
/*	for(int i = 0; i < mat.size(); i++)
	   if(mat[i].size() == 1) mat.erase(mat.begin() + i); */
	   
	return pomMat;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
	
	std::vector<double> pomV;
	Matrica mat;
	
	for(int i = 0; i < v.size(); i++) {
		double temp = v[i];
		int br_opadajucih(1);
		int j(i + 1);
		pomV.resize(0);
		while ((j < v.size()) && (v[j] <= temp)) {        // brojimo opadajuce
			br_opadajucih++;
			temp = v[j];
			j++;
		}
		for(int k = i; k < i + br_opadajucih; k++) pomV.push_back(v[k]);
		i = i + br_opadajucih - 1;
		mat.push_back(pomV);
	}
	Matrica pomMat = IzbaciRed(mat);
/*	for(int i = 0; i < mat.size(); i++) {
		if(mat[i].size() == 1) mat.erase(mat.begin() + i);
	} */
	return pomMat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v(n);
	for(int i = 0; i < v.size(); i++)
	   std::cin >> v[i];
	   
	Matrica rastuci = RastuciPodnizovi(v);
	Matrica opadajuci = OpadajuciPodnizovi(v);
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i = 0; i < rastuci.size(); i++) {
		for(int j = 0; j < rastuci[i].size(); j++) 
		   std::cout << rastuci[i][j] << " ";
		
		std::cout << std::endl;
	}
	
	std::cout << std::endl << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i = 0; i < opadajuci.size(); i++) {
		for(int j = 0; j < opadajuci[i].size(); j++)
		   std::cout << opadajuci[i][j] << " ";
		   
		std::cout << std::endl;
	}
	return 0;
}