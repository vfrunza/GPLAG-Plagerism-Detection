/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	int brojnizova(0), lijevo;
	std::vector<std::vector<double>> Rezultat;
	std::vector<int> lijevagranica, desnagranica;
	for(int i=1; i<v.size(); i++) {
		for(int j=0; j<i; j++) {
			bool rastuci=true;
			lijevo=j;
			for(int k=j; k<i; k++) {
				if(v[k]>v[k+1]) {rastuci=false;
								break;}
			} if(rastuci==true ) {
				if(i!=v.size()-1 &&  v[i]>v[i+1]) {
				if(lijevo!=0 && v[lijevo]<v[lijevo-1]) {
				brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i); }
				else if(lijevo==0) {
					brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i);
				} } else if(i==v.size()-1) {
				if(lijevo!=0 && v[lijevo]<v[lijevo-1]) {
				brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i); }
				else if(lijevo==0) {
					brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i);
				}
				
			 } } }
		
	} Rezultat.resize(brojnizova);
	for(int i=0; i<Rezultat.size(); i++) {
		for(int j=lijevagranica[i]; j<=desnagranica[i]; j++) {

			Rezultat[i].push_back(v[j]); 
		} 
	}
	return Rezultat;
} 
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
	int brojnizova(0), lijevo;
	std::vector<std::vector<double>> maxopadajuci;
	std::vector<int> lijevagranica, desnagranica;
	for(int i=1; i<v.size(); i++) {
		for(int j=0; j<i; j++) {
			bool opadajuci=true;
			lijevo=j;
			for(int k=j; k<i; k++) {
				if(v[k]<v[k+1]) {opadajuci=false;
								break;}
			} if(opadajuci==true) {
				if(i!=v.size()-1  && v[i]<v[i+1]) {
				if(lijevo!=0 && v[lijevo]>v[lijevo-1]) {
				brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i); }
				else if(lijevo==0) {
					brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i);
				} } else if(i==v.size()-1) {
						if(lijevo!=0 && v[lijevo]>v[lijevo-1]) {
				brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i); }
				else if(lijevo==0) {
					brojnizova++;
				lijevagranica.push_back(lijevo);
				desnagranica.push_back(i);
				}
			} 
		} }
	} maxopadajuci.resize(brojnizova);
	for(int i=0; i<maxopadajuci.size(); i++) {
		for(int j=lijevagranica[i]; j<=desnagranica[i]; j++) {

			maxopadajuci[i].push_back(v[j]); 
		} 
	}
	return maxopadajuci;
} 
int main ()
{ 
int n;
cout<<"Unesite broj elemenata vektora: ";
cin>>n;
std::vector<double> v;
v.resize(n);
cout<<"Unesite elemente vektora: ";
for(int i=0; i<n; i++) cin>>v[i];
    std::vector<std::vector<double>> vektor(RastuciPodnizovi(v));
    cout<<"Maksimalni rastuci podnizovi: "<<endl;
    for(int i=0; i<vektor.size(); i++) {
    	for(int j=0; j<vektor[i].size(); j++) {
    		cout<<vektor[i][j]<<" ";
    	} cout<<endl;
    }
    std::vector<std::vector<double>> matmaxopadajucih(OpadajuciPodnizovi(v));
    cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    for(int i=0; i<matmaxopadajucih.size(); i++) {
    	for(int j=0; j<matmaxopadajucih[i].size(); j++) {
    	cout<<matmaxopadajucih[i][j]<<" "; }
    	cout<<endl;
    } 
    
	return 0;
}