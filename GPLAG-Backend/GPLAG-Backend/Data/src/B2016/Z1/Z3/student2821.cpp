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
#include <stdexcept>

using std::cout;
using std::cin;
typedef std::vector<double> Vec;
typedef std::vector<std::vector<double>> Matrica;

int Brojredova(Matrica M)
{
	return M.size();
}

int Brojkolona(Matrica M)
{
	if(M.size()==0) return 0;
	else {
		return M[0].size();
	}
}

Matrica OpadajuciPodnizovi(Vec vektor)
{ 
	Matrica Povratna;
	int y=0;
	int v=0;
	for(int i=0; i<vektor.size()-1; i++) {
		int br(0);
		int x=i;
		if(i<y) continue;
		y=i;
		while(x<vektor.size()-1) {
			if(x+1==vektor.size()) break;
			if(vektor[x]<vektor[x+1])break;
		    if(vektor[x]>=vektor[x+1]){
		    	
			br++;
			x++;
			y=x;
		    }
		    //if(vektor[x]<=vektor[x+1]) break;
		
		}
		int z;
		z=i;
	    int brr;
	    brr=z+br;
		if(br>0){
		Povratna.resize(v+1);
        Povratna[v].resize(br+1);
        int k=0,n=i;
		for(int j=brr; j>=i; j--) {
			Povratna[v][k]=vektor[n];
			k++;
			n++;
		}
		v++;
		}
		br=0;
		brr=0;
	}
		
	return Povratna;

   
}

Matrica RastuciPodnizovi(Vec vektor)
{   
	
	Matrica Povratna;
	int y=0;
	int v=0;
	for(int i=0; i<vektor.size()-1; i++) {
		int br(0);
		int x=i;
		if(i<y) continue;
		y=i;
		while(x<vektor.size()-1) {
			if(x+1==vektor.size()) break;
			if(vektor[x]>vektor[x+1])break;
		    if(vektor[x]<=vektor[x+1]){
			br++;
			x++;
			y=x;
		    }
		   // if(vektor[x]>=vektor[x+1]) break;
		   
		
		}
		int z;
		z=i;
	    int brr;
	    brr=z+br;
		if(br>0){
		Povratna.resize(v+1);
        Povratna[v].resize(br+1);
        int k=0;
		for(int j=i; j<=brr; j++) {
			Povratna[v][k]=vektor[j];
			k++;
		}
		v++;
		}
		br=0;
		
	}

	return Povratna;
}



int main ()
{
	int n;
	Vec Niz;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<< "Unesite elemente vektora: ";
	double e;
	for(int i=0; i<n; i++) {
		cin>> e;
		Niz.push_back(e);
	}
	cout<<"Maksimalni rastuci podnizovi:";
	cout<<std::endl;
	Matrica Ra=RastuciPodnizovi(Niz);
	for(int i=0; i<Ra.size(); i++) {
		for(int j=0; j<Ra[i].size(); j++) {
			cout<<Ra[i][j] << " ";
		}
		cout<<std::endl;
	}
	cout<<"Maksimalni opadajuci podnizovi:";
	cout<<std::endl;
	Matrica Op=OpadajuciPodnizovi(Niz);
	for(int i=0; i<Op.size(); i++) {
		for(int j=0; j<Op[i].size(); j++) {
			cout << Op[i][j] << " ";
		}
		cout<<std::endl;
	}


	return 0;
}