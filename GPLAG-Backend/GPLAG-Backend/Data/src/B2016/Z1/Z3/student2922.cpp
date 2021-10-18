/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<double> Vektor;
typedef vector<Vektor> Matrica;

//Funkcija koja formira vektor rastucih podnizova prosl. niza
//U formi matrice
Matrica RastuciPodnizovi (Vektor vFunk){
	Matrica pomocna;
	//Sad kretanje element po element po prosl. nizu
	int duzina{(int)vFunk.size()};
	for(int i{0}; i<duzina-1; i++){
		//Ukoliko smo naisli na rast => posebno "setanje"
		if(vFunk[i]<=vFunk[i+1]){
			int brojac;
			Vektor rPodniz;
			rPodniz.push_back(vFunk[i]);
			for(brojac=i+1; brojac<duzina; brojac++){
				if(vFunk [brojac] < vFunk[brojac-1] ) break;
				rPodniz.push_back(vFunk[brojac]);
			}
			
			pomocna.push_back(rPodniz);
			//Da izbjegnemo ostatak podniza, slanje i na poziciju brojaca
			i=brojac-1;
		}
		
	}
	return pomocna;
}

//Funkcija koja formira vektor opadajucih podnizova prosl. niza
Matrica OpadajuciPodnizovi (Vektor vFunk){
	Matrica pomocna;
	//Sad kretanje element po element po prosl. nizu
	int duzina{(int)vFunk.size()};
	for(int i{0}; i<duzina-1; i++){
		//Ukoliko smo naisli na opadanje, => posebno "setanje"
		if(vFunk[i]>=vFunk[i+1]){
			int brojac;
			Vektor oPodniz;
			oPodniz.push_back(vFunk[i]);
			for(brojac=i+1; brojac<duzina; brojac++){
				if(vFunk [brojac] > vFunk[brojac-1]  ) break;
				oPodniz.push_back(vFunk[brojac]);
			}
			i=brojac-1;
			pomocna.push_back(oPodniz);
			
		}
	}
	return pomocna;
}


int main (){
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	Vektor vMain;
	for(int i{0}; i<n; i++){
		double x;
		cin>>x;
		vMain.push_back(x);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	Matrica Podnizovi{RastuciPodnizovi(vMain)};
	
	for(int i{0}; i<Podnizovi.size(); i++){
		for(int j{0}; j<(int)Podnizovi[i].size(); j++){
			cout<<Podnizovi[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	Podnizovi = OpadajuciPodnizovi(vMain);
	
	for(int i{0}; i<Podnizovi.size(); i++){
		for(int j{0}; j<(int)Podnizovi[i].size(); j++){
			cout<<Podnizovi[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}