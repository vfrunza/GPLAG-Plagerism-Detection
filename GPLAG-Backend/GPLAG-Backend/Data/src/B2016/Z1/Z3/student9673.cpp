/*B 2016/2017, Zadaća 1, Zadatak 3*/
#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> Brojevi){
	Matrica Povratna;
	std::vector<double> Pomocni;
	int pocetak, kraj;
	
	for(int i=0; i<Brojevi.size(); i++){
		if(i+1<Brojevi.size() && Brojevi[i]<=Brojevi[i+1]){
			pocetak=i;
			while(i+1<Brojevi.size() && Brojevi[i]<=Brojevi[i+1])i++;
			kraj=i;
			for(int j=pocetak; j<=kraj; j++){
				Pomocni.push_back(Brojevi[j]);
			}
			Povratna.push_back(Pomocni);
		}
		Pomocni.resize(0);  
	}
	return Povratna;
}

Matrica OpadajuciPodnizovi(std::vector<double> Brojevi){
	Matrica Povratna;
	std::vector<double> Pomocni;
	int pocetak, kraj;
	
	for(int i=0; i<Brojevi.size(); i++){
		if(i+1<Brojevi.size() && Brojevi[i]>=Brojevi[i+1]){
			pocetak=i;
			while(i+1<Brojevi.size() && Brojevi[i]>=Brojevi[i+1])i++;
			kraj=i;
			for(int j=pocetak; j<=kraj; j++){
				Pomocni.push_back(Brojevi[j]);
			}
			Povratna.push_back(Pomocni);
		}
		Pomocni.resize(0);
	}
	return Povratna;
}

int main ()
{
	std::vector<double> Brojevi;
	int broj_elemenata;
	
	cout << "Unesite broj elemenata vektora: ";
	cin >> broj_elemenata;
	Brojevi.resize(broj_elemenata);
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<Brojevi.size(); i++)cin >> Brojevi[i];
	
	Matrica rastuca=RastuciPodnizovi(Brojevi);
	Matrica opadajuca=OpadajuciPodnizovi(Brojevi);
	
	cout << "Maksimalni rastuci podnizovi:\n";
	for(int i=0; i<rastuca.size(); i++){
		for(int j=0; j<rastuca[i].size(); j++){
			cout << std::setprecision(12)  << rastuca[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Maksimalni opadajuci podnizovi:\n";
	for(int i=0; i<opadajuca.size(); i++){
		for(int j=0; j<opadajuca[i].size(); j++){
			cout << std::setprecision(12) << opadajuca[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}