#include <iostream>
#include <iomanip>
#include <vector>
typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica RastuciPodnizovi(Vektor brojevi){
	Matrica rastuca;
	int red=0, dodato=0;
	
	for(int i=0;i<(int)brojevi.size()-1;i++){
		dodato=0;
		if(brojevi[i]<=brojevi[i+1]){
			rastuca.resize(1+red);
			rastuca[red].push_back(brojevi[i]);
			dodato=1;
		}
		while((i+1)<brojevi.size() && brojevi[i+1]>=brojevi[i]){
			rastuca[red].push_back(brojevi[i+1]);
			i++;
		}
		if(dodato==1) red++;
	}
	
	return rastuca;
}

Matrica OpadajuciPodnizovi(Vektor brojevi){
	Matrica opadajuca;
	int red=0, dodato=0;
	for(int i=0;i<int(brojevi.size())-1;i++){
		dodato=0;
		if(brojevi[i]>=brojevi[i+1]){
			opadajuca.resize(1+red);
			opadajuca[red].push_back(brojevi[i]);
			dodato=1;
		}
		while((i+1)<brojevi.size() && brojevi[i+1]<=brojevi[i]){
			opadajuca[red].push_back(brojevi[i+1]);
			i++;
		}
		if(dodato) red++;
	}
	
	return opadajuca;
}
void IspisiMatricu(Matrica matrica){
	for(auto red: matrica){
		for(auto broj : red)
			std::cout<<broj<<" ";
		std::cout<<std::endl;
	}
}

int main ()
{	
	int broj_elemenata;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	Vektor brojevi;
	double broj;
	for(int i=0;i<broj_elemenata;i++){
		std::cin>>broj;
		brojevi.push_back(broj);
	}
	
	std::cout<<"Maksimalni rastuci podnizovi:\n";
	IspisiMatricu(RastuciPodnizovi(brojevi));
	std::cout<<"Maksimalni opadajuci podnizovi:\n";
	IspisiMatricu(OpadajuciPodnizovi(brojevi));
	
	return 0;
}