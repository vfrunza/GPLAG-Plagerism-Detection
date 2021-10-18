/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std::vector;
vector<int> IzbaciIste(vector<int> v){   //funkcija za izbacivanje istih brojeva iz vektora
	for(int i=0; i<v.size()-1; i++){
		for(int j=i+1; j<v.size(); j++)
			if(v[i]==v[j]){
				for(int k=j; k<v.size()-1; k++)
				v[k]=v[k+1];
				j--;
				v.resize(v.size()-1);
		}
	}
	return v;
}
vector<int> IzdvojiGadne(vector<int>v, bool ind){
	vector<int> a;
	for(int i=0; i<v.size(); i++){
		int x=v[i];
		int br0=0, br1=0, br2=0;
		while(x!=0){
			int ost=(x % 3);
			if(ost==0) br0++;
			else if(ost==1) br1++;
			else if(ost==2) br2++;
		x/=3;
		}
	    if(ind==true && ((br0%2==0 && br1%2==0 && br2%2==0)||(br0==0 && br1%2==0 && br2%2==0))) a.push_back(v[i]);
	    else if(ind==true && ((br0%2==0 && br1==0 && br2%2==0)||(br0%2==0 && br1%2==0 && br2==0))) a.push_back(v[i]);
	    else if(ind== true && ((br0%2==0 && br1==0 && br2==0) ||(br0==0 && br1%2==0 && br2==0)||(br0==0 && br1==0 && br2%2==0))) a.push_back(v[i]);
	    else if(ind==false && ((br0%2==1 && br1%2==1 && br2%2==1)||(br0==0 && br1%2==1 && br2%2==1))) a.push_back(v[i]);
	    else if(ind==false && ((br0%2==1 && br1==0 && br2%2==1)||(br0%2==1 && br1%2==1 && br2==0))) a.push_back(v[i]);
	    else if(ind==false && ((br0%2==1 && br1==0 && br2==0) ||(br0==0 && br1%2==1 && br2==0)||(br0==0 && br1==0 && br2%2==1))) a.push_back(v[i]);
	}
	return IzbaciIste(a);
}
int main ()
{
	vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do{                 //Unos vektora brojeva
		std::cin>>broj;
		if(broj==0) break;
		v.push_back(broj);
	} while(broj!=0);
	vector<int> opaki=IzdvojiGadne(v,true);
	vector<int> odvratni=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	if(opaki.size()!=0){
	for(int i:opaki) std::cout<<i<<" "; //ispis opakih brojeva
	std::cout<<"\n";
	} else std::cout<<"0";
	std::cout<<"Odvratni: ";
	if(odvratni.size()!=0){
	for(int i:odvratni) std::cout<<i<<" "; // ispis odvratnih brojeva
	std::cout<<"\n";
	} else std::cout<<"0";
	return 0;
}