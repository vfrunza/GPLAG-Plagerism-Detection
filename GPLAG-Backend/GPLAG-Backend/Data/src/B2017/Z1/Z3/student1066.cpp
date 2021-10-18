#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

typedef std::deque<std::vector<int>> DekVektora; // Da manje pisem

enum Smjer {Opadajuci,Rastuci}; // Definicija smjera

bool DaLiJeStepenOdDva (int n)
{
	if (n<=0)
	return false;
	return abs(ceil(log2(n))-floor(log2(n)))<0.0000000001; // Preko logaritma baze dva se trazi da li su brojevi 2 na neku pa gleda zaoukruživanje na najmanji i najveci cijeli broj
} // Da li je broj stepen od dva

DekVektora Raste (std::vector<int> numbers)
{
	DekVektora dek;
	for (int i = 0; i<numbers.size(); i++) {
		std::vector <int> pomocni(0);   // Vektor u koji upisujem brojeve koji zadovoljavaju uslove 
		bool uspjelo(false);       // Da li je uspjelo sa ispitivanjem da mogu ubaciti taj vektor u dek na kraju petlje
		if ((i<(numbers.size()-1)) && (numbers.at(i)<=numbers.at(i+1)) && DaLiJeStepenOdDva(numbers.at(i)) && DaLiJeStepenOdDva(numbers.at(i+1))) {
			pomocni.push_back(numbers.at(i));    // Stavljam prvi element koji odgovara na prvo mjesto u vektoru koji je u deku
			uspjelo=true;   
		}
		while ((i<(numbers.size()-1)) && numbers.at(i)<=numbers.at(i+1) && DaLiJeStepenOdDva(numbers.at(i)) && DaLiJeStepenOdDva(numbers.at(i+1))) {
			pomocni.push_back(numbers.at(i+1));   //Iz gornjeg komentara se vidi zasto sam stavio i-ti element u vektor jer da mogu staviti (i+1)-i element
			i++;
		}
		if (uspjelo)	dek.push_back(pomocni);
	}
	return dek;
}  //Funkcija koja samo vraca dek rastucih

// Kopirao sam sve sto je pisalo u funkciji Raste u funkciju Opada jer se razlikuju samo u znako manje-vece, sve sto pise od komentara u funkciji
// Raste vazi i za funkciju Opada, tako da ne mislite da sam nesto od nekoga prepisao

DekVektora Opada (std::vector<int> numbers)
{
	DekVektora dek;
	for (int i = 0; i<numbers.size(); i++) {
		std::vector <int> pomocni(0);
		bool uspjelo(false);
		if ((i<(numbers.size()-1)) && (numbers.at(i)>=numbers.at(i+1)) && DaLiJeStepenOdDva(numbers.at(i)) && DaLiJeStepenOdDva(numbers.at(i+1))) {
			pomocni.push_back(numbers.at(i));    
			uspjelo=true;
		}
		while ((i<(numbers.size()-1)) && numbers.at(i)>=numbers.at(i+1) && DaLiJeStepenOdDva(numbers.at(i)) && DaLiJeStepenOdDva(numbers.at(i+1))) {
			pomocni.push_back(numbers.at(i+1));   
			i++;
		}
		if (uspjelo)	dek.push_back(pomocni);
	}
	return dek;
} 

DekVektora MaksimalniPodnizoviStepenaDvojke (std::vector<int> numbers,Smjer smjer)
{
	if (smjer)
		return Raste(numbers);
	return Opada(numbers);
}  //Ova funkcija ce imati funkciju da samo oderdi da li treba vratiti rastuce ili opadajuce
// Funkcije Raste i Opada ce raditi posao

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> vektor;
	int j;
	for (int i=0; i<n; i++) {
		std::cin>>j;
		vektor.push_back(j);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int i;
	std::cin>>i;
	DekVektora kraj;
	if (i==1) {
		kraj = MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	} else if (i==2) {
		kraj = MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for (int i=0; i<kraj.size(); i++) {
		for (int j=0; j<kraj.at(i).size(); j++)
			std::cout<<kraj.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
	return 0;
}