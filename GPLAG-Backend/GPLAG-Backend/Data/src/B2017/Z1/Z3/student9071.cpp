#include <iostream>
#include <vector>
#include <deque>
using std::deque;
using std::cout;
using std::cin;
using std::vector;
enum Smjer {Rastuci=1,Opadajuci=2};
vector<int> UnesiVektor(int n)
{
	//Unos vektora sa n elemenata
	vector<int>vektor;
	int a;
	for(int i=0; i<n; i++) {
		cin>>a;
		vektor.push_back(a);
	}
	return vektor;
}
bool JelStepen2(int n)
{
	//provjera dijeljenjem da li je n stepen od 2
	if(n<1) {
		return false;
	}
	if (n==1) {
		return true;
	}
	while (n > 1) {
		if(n%2!=0) {
			return false;
		}
		n/=2;
	}
	return true;
}
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int>vektor, Smjer dir)
{
	//funkcija funkcionise (heh) tako sto ide element po element dok ne nadje
	//jedan sto je stepen od dva, provjerava sljedece elemente (uporedi prethodnni)
	//sa trenutnim te upisuje u vektor pbvektor. Ako je velicine jedan, brise ga
	//u suprotnom se upisuje u deque vektora.
	deque<vector<int>> rez;
	vector<int> pbvektor;
	int i,j;
	for(i=0; i<vektor.size(); i++) {
		if(!JelStepen2(vektor.at(i))) {
			continue;
		}
		pbvektor.push_back(vektor.at(i));
		for(j=i+1; j<vektor.size(); j++) {
			if(vektor.at(j)>=vektor.at(j-1)&&dir==Rastuci&&JelStepen2(vektor.at(j))) {
				pbvektor.push_back(vektor.at(j));
			} else if (vektor.at(j)<=vektor.at(j-1)&&dir==Opadajuci&&JelStepen2(vektor.at(j))) {
				pbvektor.push_back(vektor.at(j));
			} else {
				break;
			}
			i=j;
		}
		if(pbvektor.size()!=1) {
			rez.push_back(pbvektor);
		}
		pbvektor.clear();
	}
	return rez;
}
void IspisiMatricu(deque<vector<int>> matrica,Smjer dir)
{
	//Ispis
	if(dir==Rastuci) {
		cout<<"Maksimalni rastuci podnizovi: \n";
	} else if(dir==Opadajuci) {
		cout<<"Maksimalni opadajuci podnizovi: \n";
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica.at(i).size(); j++) {
			cout<<matrica.at(i).at(j)<<" ";
		}
		cout<<"\n";
	}
}
int main ()
{

	int n;
	int option;
	Smjer dir(Rastuci);
	vector<int>vektor;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vektor=UnesiVektor(n);
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>option;
	if(option==1) {
		dir=Rastuci;
	} else if (option==2) {
		dir=Opadajuci;
	}
	IspisiMatricu(MaksimalniPodnizoviStepenaDvojke(vektor,dir),dir);
	return 0;
}