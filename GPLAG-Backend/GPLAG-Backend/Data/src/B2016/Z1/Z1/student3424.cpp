/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool sadrziLiGa(vector<int> vektor, int broj){
	for(int j=0;j<vektor.size();j++)
		if(vektor[j]==broj) return true;
	return false;
}

bool daLiSuParni(vector<int> v){
	if(v[0]%2==0 && v[1]%2==0 && v[2]%2==0) return true;
	return false;
}

bool daLiJeOdvratan(vector<int> brojaci){
	if((brojaci[0]%2!=0 || brojaci[0]==0) && (brojaci[1]%2!=0 || brojaci[1]==0) && (brojaci[2]%2!=0 || brojaci[2]==0)) return true;
	return false;
}

vector<int> izdvojiOpake(vector<int> vektor){
	vector<int> vrati, brojaci(3);
	for(int i=0;i<vektor.size();i++){
		bool sadrzavanje=sadrziLiGa(vrati, vektor[i]);
		if(sadrzavanje==true) continue;
		int zavrzlama=vektor[i];
		while(zavrzlama!=0){
			brojaci[abs(zavrzlama%3)]++;
			zavrzlama=zavrzlama/3;
		}
		if(daLiSuParni(brojaci))
			vrati.push_back(vektor[i]);
		brojaci[0]=0;
		brojaci[1]=0;
		brojaci[2]=0;
	}
	return vrati;
}

vector <int> izdvojiOdvratne(vector<int> vektor){
	vector<int> vrati, brojaci(3);
	for(int i=0; i<vektor.size();i++){
		bool sadrzavanje=sadrziLiGa(vrati, vektor[i]);
		if(sadrzavanje==true) continue;
		int havarija=vektor[i];
		while (havarija!=0){
			brojaci[abs(havarija%3)]++;
			havarija=havarija/3;
		}
		if(daLiJeOdvratan(brojaci))
			vrati.push_back(vektor[i]);
		brojaci[0]=0;
		brojaci[1]=0;
		brojaci[2]=0;
	}
	return vrati;
}

vector<int> IzdvojiGadne(vector<int>v, bool bul){
	if(bul==true){
		vector<int> vrati=izdvojiOpake(v);
		return vrati;
	}
	if(bul==false){
		vector<int> vrati=izdvojiOdvratne(v);
		return vrati;
	}
}

int main (){
	vector<int> vektor;
	int broj;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		cin >> broj;
		if(broj==0) break;
		vektor.push_back(broj);
	}
	while (broj!=0);
	vector<int> temp(IzdvojiGadne(vektor, true));
	cout << "Opaki: ";
	for(int i=0; i<temp.size(); i++) cout << temp[i] << " ";
	temp=IzdvojiGadne(vektor, false);
	cout << endl << "Odvratni: ";
	for(int i=0; i<temp.size(); i++) cout << temp[i] << " ";
	return 0;
}