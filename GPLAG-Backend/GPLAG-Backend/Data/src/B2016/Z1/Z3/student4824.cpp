#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cin;
using std::cout;
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double> ulazni_vektor){
	vector<vector<double>> Rastuci_podnizovi;
    vector<double> temp;
    int brojac_podnizova(0);
    
    //Prolazimo kroz vektor i poredimo clanove, trazimo max rastuce podnizove
    //i smjestamo ih u pomocni vektor
    if(ulazni_vektor.size()!=0){
	for(int i=0;i<ulazni_vektor.size()-1;i++){
		temp.push_back(ulazni_vektor.at(i));
		int j(i+1),k(i);
		while(ulazni_vektor.at(j)>=ulazni_vektor.at(k)){
			temp.push_back(ulazni_vektor.at(j));
			j++;
			if(j==ulazni_vektor.size()) break;
			k++;
		}
		
	//Ispitujemo velicinu podniza ako je zadovoljena upisujemo ga u matricu 
		if(temp.size()>1){
    	   brojac_podnizova++;
           Rastuci_podnizovi.resize(brojac_podnizova);
           Rastuci_podnizovi[brojac_podnizova-1]=temp;
       }
     i=j-1;
    temp.resize(0);
	}
    }
	return Rastuci_podnizovi;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> ulazni_vektor){
	vector<vector<double>> Opadajuci_podnizovi;
	vector<double> temp;
	int brojac_podnizova(0);
	
	//Prolazimo kroz vektor poredimo clanove i trazimo max opadajuce podnizove 
	//i smjestamo ih u pomocni vektor
	if(ulazni_vektor.size()!=0){
	for(int i=0;i<ulazni_vektor.size()-1;i++){
		temp.push_back(ulazni_vektor.at(i));
		int j(i+1),k(i);
		while(ulazni_vektor.at(j)<=ulazni_vektor.at(k)){
			temp.push_back(ulazni_vektor.at(j));
			j++;
			if(j==ulazni_vektor.size()) break;
			k++;
		}
		
		//Ispitujemo velicinu podniza ako je zadovoljena upisujemo ga u matricu
		if(temp.size()>1){
			brojac_podnizova++;
			Opadajuci_podnizovi.resize(brojac_podnizova);
			Opadajuci_podnizovi[brojac_podnizova-1]=temp;
		}
		i=j-1;
		temp.resize(0);
	}
	}
	return Opadajuci_podnizovi;
}
int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> V(n);
	for(int i=0;i<n;i++)
	    cin>>V[i];
	vector<vector<double>> Rastuci,Opadajuci;
	Rastuci=RastuciPodnizovi(V);
	Opadajuci=OpadajuciPodnizovi(V);
	cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<Rastuci.size();i++){
		for(int j=0;j<Rastuci[i].size();j++){
			cout<<Rastuci[i][j]<<" ";
		}
		cout<<std::endl;
	}
	cout<<std::endl<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<Opadajuci.size();i++){
		for(int j=0;j<Opadajuci[i].size();j++){
			cout<<Opadajuci[i][j]<<" ";
		}
		cout<<std::endl;
	}
	return 0;
}