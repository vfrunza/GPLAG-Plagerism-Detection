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
typedef std::vector<double> vec;

vec podniz_rastuci (vec vektor, int i){
	vec v;
	if (i == (int(vektor.size()))-1) return vec{0};
	v.push_back(vektor[i]);
	while (vektor[i+1]>=vektor[i]){
		v.push_back(vektor[i+1]);
		i++;
		if ((i+1) == (int(vektor.size()))) break;
	}
	return v;
}

vec podniz_opadajuci (vec vektor, int i){
	vec v;
	if (i == (int(vektor.size()))-1) return vec{0};
	v.push_back(vektor[i]);
	while (vektor[i+1]<=vektor[i]){
	
		v.push_back(vektor[i+1]);
		i++;
		if (i == (int(vektor.size()))-1) break;
	}
	return v;
}

Matrica RastuciPodnizovi (vec vektor){
	Matrica mat;

	for (int i=0; i<int(vektor.size()); i++){
		if (podniz_rastuci(vektor,i).size()>1) mat.push_back(podniz_rastuci(vektor,i));
		i+=(podniz_rastuci(vektor,i).size()-1);
		if (i==int(vektor.size())-1) break;
	}
	return mat;
}

Matrica OpadajuciPodnizovi (vec vektor){
	Matrica mat;


	for (int i=0; i<int(vektor.size()); i++){
		if (podniz_opadajuci(vektor,i).size()>1) mat.push_back(podniz_opadajuci(vektor,i));
		i+=(podniz_opadajuci(vektor,i).size()-1);
		if (i==int(vektor.size())-1) break;
	}
	return mat;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    vec vektor(n);
    for (double &i: vektor) std::cin>>i;
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for (vec x: RastuciPodnizovi(vektor)){
    	for (double y: x) std::cout<<y<<" ";
    	std::cout<<std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for (vec x: OpadajuciPodnizovi(vektor)){
    	for (double y: x) std::cout<<y<<" ";
    	std::cout<<std::endl;
    }
	
	return 0;
}