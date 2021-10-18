/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
typedef vector<int> tip;
tip IzdvojiGadne(tip v,bool a){
	tip x; //
	tip y; //

	int br0(0);
	int br1(0);
	int br2(0);
	bool isti(false);
	
 for(int i=0;i<v.size();i++){
 	
	int m(v[i]);
	
	while(m!=0){
		if(m%3==0) br0++;
		if(m%3==1) br1++;
		if(m%3==2) br2++;
		if(m%3==-1) br1++;
		if(m%3==-2) br2++;
		m/=3;
	}
	
	if((br0%2==0 && br1%2==0 && br2%2==0) && a==true){
	    if(v.size()==0)  x.push_back(v[i]);
	else {
	    for(int j=0;j<x.size();j++){
		if(x[j]==v[i]) {
		    isti=true;
		    break; }
		else isti=false;
	}
	if(isti==false) x.push_back(v[i]);
	}
		}
	if((br0%2==1 && br1%2==1 && br2%2==1)  && a==false){
	    if(v.size()==0) y.push_back(v[i]);
	else{
	    for(int k=0;k<y.size();k++){
		if(y[k]==v[i]) {
		    isti=true; 
		    break; }
		else isti=false;
	}
	if(isti==false) y.push_back(v[i]);
	}
	}
	if((br0==0 && br1%2==1 && br2%2==1) || (br0%2==1 && br1==0 && br2%2==1) || (br0%2==1 && br1%2==1 && br2==0)|| (br0==0 && br1==0 && br2%2==1) || (br0==0 && br1%2==1 && br2==0) || (br0%2==1 && br1==0 && br2==0)) {
	    if(v.size()==0) y.push_back(v[i]);
	else{
	    for(int z=0;z<y.size();z++){
		if(y[z]==v[i]) {
		    isti=true;
		    break; }
		else isti=false;
	}
	if(isti==false) y.push_back(v[i]);
	}
	}
	br0=0;
	br1=0;
	br2=0;
	
}

if(a) return x;
return y;


}

int main ()
{
	tip v;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	if(!(cin>>broj)){
		cin.clear();
		cin.ignore(10000,'\n');
	}
	while (broj!=0) {v.push_back(broj);
		cin>>broj;
	}
	tip x (IzdvojiGadne(v,true));
	tip y (IzdvojiGadne(v,false));
	
	
	cout<<"Opaki: ";
	for(int i=0;i<x.size();i++)
	cout<<x[i]<<" ";
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0;i<y.size();i++)
	cout<<y[i]<<" ";
	return 0;
}