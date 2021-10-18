/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 

std::vector<std::vector<double> > RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> rastuca_mat;
	for (int i=0;i<v.size()-1;i++){
		std::vector<double> PomVekt(0.);
		if (v[i+1]>=v[i]){
			while (v[i+1]>=v[i]){
				PomVekt.push_back(v[i]);
				i++;
				if (i==(v.size()-1))
					break;
			}
			PomVekt.push_back(v[i]);
			rastuca_mat.push_back(PomVekt);
		}
		if(i<(v.size()-1) && v[i+1]<v[i]){
			while (v[i+1]<v[i]){
				i++;
				if (i==(v.size()-1))
					break;
			}
		}
		i--;
		
	}
	return rastuca_mat;
}

std::vector<std::vector<double> > OpadajuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> opad_mat;
	for (int i=0;i<v.size()-1;i++){
		std::vector<double> PomVekt(0);
		if (v[i+1]<=v[i]){
			while (v[i+1]<=v[i]){
				PomVekt.push_back(v[i]);
				i++;
				if (i==(v.size()-1))
					break;
			}
		PomVekt.push_back(v[i]);
		opad_mat.push_back(PomVekt);
	}
	if (i<(v.size()-1) && v[i+1]>v[i]){
		while (v[i+1]>v[i]){
			i++;
			if (i==(v.size()-1))
				break;
			}
		}
	i--;
	}
	return opad_mat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	double elementi;
	std::vector<double> v1;
	for (int i=0;i<n;i++){
		std::cin >> elementi;
		v1.push_back(elementi);
	}
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> mat;
	mat=RastuciPodnizovi(v1);
	for (int i=0;i<mat.size();i++){
		for (int j=0;j<mat[i].size();j++)
			std::cout << mat[i][j] << " ";
		std::cout<< std::endl;
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	std::vector<std::vector<double>> mat_opad;
	mat_opad=OpadajuciPodnizovi(v1);
	for (int i=0;i<mat_opad.size();i++){
		for (int j=0;j<mat_opad[i].size();j++)
			std::cout << mat_opad[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}