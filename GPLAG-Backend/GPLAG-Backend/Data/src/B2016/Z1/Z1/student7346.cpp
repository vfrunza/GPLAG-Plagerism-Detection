/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;

bool Opaki(int z){
	int brojac0(0), brojac1(0), brojac2(0);
	while(z!=0){
		int n=z%3;
	    if(n==0) brojac0++;
	    if(n==1) brojac1++;
	    if(n==2) brojac2++;
	    z=z/3;
	}
	if((brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2%2==0 || brojac2==0))
		return true; 
	else return false;
}

bool Odvratni(int z){
	int brojac0(0), brojac2(0), brojac1(0);
	while(z!=0){
		if(z<0) z=z*(-1);
		int m=z%3;
	    if(m==0) brojac0++;
	    if(m==1) brojac1++;
	    if(m==2) brojac2++;
	    z/=3;
	}
	if((brojac0%2==1 || brojac0==0) && (brojac1%2==1 || brojac1==0) && (brojac2%2==1 || brojac2==0))
		 return true;
	else return false;
}

vector<int> IzdvojiGadne(vector<int> v, bool tacno_netacno){
	vector<int> v5;
	for(int i=0; i<v.size(); i++){
		if(Opaki(v[i])==true && tacno_netacno==true)  
		   v5.push_back(v[i]);
		if(Odvratni(v[i])==true && tacno_netacno!=true)
		   v5.push_back(v[i]);
	}
	for(int n=0; n<v5.size(); n++)
	    for(int m=n+1; m<v5.size(); m++)
	        if(v5[n]==v5[m]){
	        	for(int l=m; l<v5.size()-1; l++)
	        	    v5[l]=v5[l+1];
	        	v5.resize(v5.size() - 1);
	        	m--;
	        }
	return v5;
}

int main (){
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    vector<int>v;
    vector<int>opaki;
    vector<int>odvratni;
    int n; 
    
    do{
    	cin>>n;
    	if(n==0) break;
    	else v.push_back(n);
    } while(n!=0); 
    
    opaki=IzdvojiGadne(v, true); 
    odvratni=IzdvojiGadne(v, false);
    cout<<"Opaki: ";
    for(int x:opaki) cout<<x<<" ";
    cout<<endl<<"Odvratni: ";
    for(int x:odvratni) cout<<x<<" ";
    return 0;
}