/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void IspisiVektor(vector<int> vektor)
{
	for(unsigned int i=0; i<vektor.size(); i++) {
		cout << vektor.at(i) << " ";
	}

	cout << endl;
}

vector<int> PretvoriUTernarni(int n)
{
	vector<int> ternarni; 
	unsigned long long johnson;
	
	if ( n < 0 ) {
		johnson = -static_cast<unsigned long long>(n);
	} else {
		johnson = static_cast<unsigned long long>(n);
	}
	
	while(johnson!=0)
	{
		ternarni.push_back(johnson%3);
		johnson /= 3;
	}
	
	return ternarni;
}

bool DaLiJeOdvratan(int broj)
{
	if(broj==0) return true;
	
	if ( broj <0 ) broj = - broj;
	
	vector <int> brojaci(4,0); // 0 1 2 3 
	
	for ( int cifra : PretvoriUTernarni(broj) )
	{
		brojaci.at(cifra)++;
	}
	
	for(unsigned int i=0; i<brojaci.size(); i++)
	{
		if(brojaci.at(i)%2==0 && brojaci.at(i) != 0) return false;
	}
	
	
	return true;
}

bool DaLiJeOpak(int broj)
{
	if(broj==0) return false;
	
	if ( broj < 0 ) {
		broj = -broj;
	}
	//sada je sigurno pozitivan...
	vector <int> brojaci(4,0); // 0 1 2 3
	
	for ( int cifra : PretvoriUTernarni(broj) ) 
		brojaci.at(cifra)++;
		
	
	for(unsigned int i=0; i<brojaci.size(); i++)
	{
		if(brojaci.at(i)%2!=0) return false;
	}
	
	return true;
}

bool VektorSadrzi(vector<int> v, int n) {
	for ( int a : v )
	  if ( a == n ) return true;
	return false;
}

vector<int> IzdvojiGadne(vector<int> vektor, bool tn )
{
    vector <int> povratni;

	for(unsigned int i=0; i<vektor.size(); i++) {
		
		if(tn==true && DaLiJeOpak(vektor.at(i))==true && !VektorSadrzi(povratni, vektor.at(i))) povratni.push_back(vektor.at(i));
		else if (tn==false && DaLiJeOdvratan(vektor.at(i))==true && !VektorSadrzi(povratni, vektor.at(i))) povratni.push_back(vektor.at(i));
	}
		
	return povratni;
}
 
int main () {
	int broj;
	vector <int> brojevi, opaki, odvratni;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin >> broj;
		brojevi.push_back(broj);
	}
	while(broj!=0);

	brojevi.pop_back();

	opaki=IzdvojiGadne(brojevi, true);
	odvratni=IzdvojiGadne(brojevi, false);

	cout << "Opaki: ";
	IspisiVektor(opaki); cout << endl << "Odvratni: ";
	
	IspisiVektor(odvratni);

	return 0;
}