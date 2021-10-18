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
typedef std::vector<int> IntVector;
using std::cout;
using std::cin;
using std::endl;

bool Provjeri(IntVector a, int n){
	if(n==0) return false;
	for(int i(n-1);i>=0;i--){
		if(a[n]==a[i]){return true;}
	}
	
	return false;
}
IntVector Pretvori(int n){
	IntVector a;
	

	int brojac2(0);
	int brojac1(0);
	int brojac0(0);

	do{
		int k(0);
		k=n%3;
		if(k<0) k=abs(k);
		if(k==0) brojac0++;
		else if(k==1) brojac1++;
		else
			brojac2++;
		n/=3;
	}while(n!=0);
	a={brojac0,brojac1,brojac2};
	return a;
}
IntVector IzdvojiGadne (IntVector a, bool b){
	
	IntVector h;
	if(b==true){
		for(int i(0);i<a.size();i++){
			
			bool imal_ga(Provjeri(a,i));
			if(imal_ga==true){}
			else{
			IntVector c(Pretvori(a.at(i)));
			bool valjal(false);
			int brojac(0);
			for(int j(0);j<c.size();j++){
				if(c.at(j)%2==0)brojac++;
				if(brojac==3)valjal=true;
			}
			if(valjal==true) h.push_back(a.at(i));
			}
			if(i==a.size()) break;
		}
		return h;
	}else
	{
		for(int i(0);i<a.size();i++){
			bool imal_ga(Provjeri(a,i));
			if(imal_ga==true){}
			else{
			IntVector c(Pretvori(a.at(i)));
			bool valjal(false);
			int brojac(0);
			for(int j(0);j<c.size();j++){
				if(c[j]%2!=0 || c[j]==0)brojac++;
				if(brojac==3)valjal=true;
			}
			if(valjal==true) h.push_back(a.at(i));
			
		}if(i==a.size()) break;
		}
		return h;
	}
}
int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	IntVector a;
	int k(1);
	do{
		cin>>k;
		a.push_back(k);
	}while(k!=0);
	if(a.size()!=1) a.resize(a.size()-1);
	
	IntVector b(IzdvojiGadne(a,true));
	IntVector c(IzdvojiGadne(a,false));
	
	cout<<"Opaki: ";
	for(int i(0);i<b.size();i++)
		cout<<b.at(i)<<" ";
	
	cout<<"\nOdvratni: ";
	
	for(int i(0);i<c.size();i++)
		cout<<c.at(i)<<" ";

	return 0;
}