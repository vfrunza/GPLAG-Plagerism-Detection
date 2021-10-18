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

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> IzdvojiGadne (vector<int> n, bool x) {
	
	for(int i=0; i<n.size(); i++) 
		for(int k=0; k<n.size(); k++) 
			if(n[i]==n[k] && k!=i) n.erase(n.begin()+k);
			
			
			
	vector <int> a,b,stari(n.size());
	const double e(0.00001);
		for(int i=0; i<n.size(); i++) {
			double ostatak, broj[50];
			int j=0;
			stari[i]=n[i];
			while(n[i]!=0){
	
				ostatak=double(n[i])/3;
				broj[j]=(ostatak-int(ostatak))*3;
				n[i]=int(ostatak);
				
				j++;
			} 
			
			
			int brojac[50],br(0);
			for(int k=0; k<j; k++) {
				for(int l=0; l<j; l++)
				if(fabs(broj[k]-broj[l])<e) br++;
				
				brojac[k]=br;
				br=0;
			}
			if(x==true) {
			int m(0);
			for(int k=0; k<j; k++) 
				if(brojac[k]%2==0) m++;
				
			if(m==j) a.push_back(stari[i]);
			}
			
			else{
			int c(0);
			for(int k=0; k<j; k++) {
				if(brojac[k]%2!=0) c++;
			}
			if(c==j) b.push_back(stari[i]);
			}	
		}
	for(int i=0; i<a.size(); i++) 
		for(int k=0; k<a.size(); k++) 
			if(a[i]==a[k] && k!=i) a.erase(a.begin()+k);
			
	for(int i=0; i<b.size(); i++) {
		for(int k=0; k<b.size(); k++) 
			if(b[i]==b[k] && k!=i) b.erase(b.begin()+k);
	}
	
	
	if(x==true) return a;
	else return b;
}


int main ()
{
	
	vector<int> n;
	int a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	do{
		cin>>a;
		if(a!=0) n.push_back(a);
	
	} while(a!=0);
	
	cout<<"Opaki: ";
	for(int i=0; i<IzdvojiGadne(n,true).size(); i++) {
		cout<<IzdvojiGadne(n,true)[i]<<" ";
		
	
	}
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0; i<IzdvojiGadne(n,false).size(); i++)
	cout<<IzdvojiGadne(n,false)[i]<<" ";
	
	
	return 0;
}

