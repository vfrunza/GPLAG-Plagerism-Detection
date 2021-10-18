/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

void IspisiMat(std::vector<std::vector<double>> mat){
	for(int i = 0; i < mat.size(); i++){
		for(int j = 0; j < mat[i].size(); j++){
			std :: cout<<std :: setprecision(12)<<mat[i][j]<<" ";
		}
		std :: cout<<std::endl;
	}
}

std :: vector<std :: vector<double>> RastuciPodnizovi(std::vector<double> vec)
{	
	//UKOLIKO JE VEKTOR PRAZAN VRATI NPRAZNU MATRICU
	if (vec.size()==0) { 
		std::vector< std::vector<double>> mat(0);
		return mat;
	}
	
	std:: vector<std :: vector<double>> matrica;
	int redovi=0;
		for(int i = 0; i<vec.size()-1; i++){
			int j=i;
			int a=i;
			int b=1;
			if (vec[i]<=vec[i+1] ) {
				while ((a+1)<vec.size() && vec[a]<=vec[a+1]) {		//MORA PAZITI NA VELICINU VEKTORA
					b++;
					a++;
			}	
			int nastavi=b+i-1;  //ODAKLE SE NASTAVLJA
				while(b!=0){
					matrica.resize(redovi+1);
					matrica[redovi].push_back(vec[j]);
					j++;
					b--;
					if (b==0) {break;}
				}
				redovi++;
				i=nastavi;
			}
		 }
	return matrica;
}

 std::vector<std :: vector<double>> OpadajuciPodnizovi(std :: vector <double> vec)
 {
 	if(vec.size()==0){
 		std::vector< std::vector<double>> mat(0);
        return mat;
 	}
 	
 	std::vector< std::vector<double>> matrica ;
 	int redovi=0;
 		for(int i = 0; i<vec.size()-1; i++){
 			int j=i;
 			int a=i;
 			int b=1;
 			if (vec[i]>=vec[i+1] ) {
 				while ((a+1)<vec.size() && vec[a]>=vec[a+1]) {
 					b++;
 					a++;
 				}
 				int nastavi=b+i-1;						//NASTAVI
 					while (b) {
 						matrica.resize(redovi+1);		//MORA SE PRVO RESIZE.AT DA BI ZNALI GDJE UBACUJEMO BROJ
 						matrica[redovi].push_back(vec[j]);
 						j++;
 						b--;
 					}
 				redovi++;
 				i=nastavi;
 			}
 		}
 	return matrica;
 }



int main ()
{
		std::cout << "Unesite broj elemenata vektora: ";
		int n;
		std::cin >> n;
		std::vector<double> vektor;
		std::cout << "Unesite elemente vektora: " ;
			for(int i = 0; i<n; i++){
				int e;
				std::cin >> e;
				vektor.push_back(e);
	 		}
		std::vector<std::vector<double>> rastuci=RastuciPodnizovi(vektor);
		std::vector< std::vector<double>> opadajuci=OpadajuciPodnizovi(vektor);

	    std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		IspisiMat(rastuci);
     	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		IspisiMat(opadajuci);
	
	return 0;
}