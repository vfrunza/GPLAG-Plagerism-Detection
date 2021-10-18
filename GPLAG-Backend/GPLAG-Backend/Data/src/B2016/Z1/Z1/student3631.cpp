/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int> IzdvojiGadne (vector<int> a, bool t)
{

	vector<int> b;
	vector<int> c;
 
	for (int i=0; i<a.size(); i++) {
		int brojac1=0,brojac2=0,brojac0=0;
		int pomocnibrojac=0;
	    int pomocnibrojac1=0;
		int clan;
		clan=a[i];
		int k;
		k=0;
		
		if (clan==0) {brojac0++; }
		while (clan!=0) {
			
			k=abs(clan%3);
			if(k==0) brojac0++; 
			if(k==1) brojac1++; 
			if(k==2) brojac2++; 
			clan=clan/3;
		}

	        if(brojac0%2==0) pomocnibrojac++;
            if(brojac0==0 || brojac0%2!=0) pomocnibrojac1++;
            
			if (brojac1%2==0) pomocnibrojac++;
		    if(brojac1==0 || brojac1%2!=0) pomocnibrojac1++;
		
		    if(brojac2%2==0) pomocnibrojac++;
		    if(brojac2==0 || brojac2%2!=0) pomocnibrojac1++; 
		    
       
		if (pomocnibrojac==3) {   
	     int brojacistih1=0;
	     
		for(int j=0;j<b.size();j++){
	    
        if(b[j]!=a[i]) brojacistih1++;
      
		}
			  if(brojacistih1==b.size()) b.push_back(a[i]);
		}
		
		else if (pomocnibrojac1==3)  {
		int brojacistih2=0;
			   
		for(int j=0;j<c.size();j++){
		if(c[j]!=a[i]) brojacistih2++;
	
		
	}
		if(brojacistih2==c.size()) c.push_back(a[i]);
	}
	
	}

	if (t==true) return b;
	else return c;
}


int main ()
{
	int n;
    vector<int> a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
do{
	cin>>n;
	if(n==0) break;
	a.push_back(n);
}while(n!=0);
	

	vector<int> poziv;
	vector<int> poziv1;
	poziv=IzdvojiGadne(a,true);
	poziv1=IzdvojiGadne(a,false);
	

	
    cout<<"Opaki: ";
    for(int i=0; i<poziv.size();i++){
    	cout<<poziv[i]<<" ";
    }
	cout<<endl;
	cout<<"Odvratni: ";
	    for(int i=0; i<poziv1.size();i++){
    	cout<<poziv1[i]<<" ";
    }

	return 0;
}