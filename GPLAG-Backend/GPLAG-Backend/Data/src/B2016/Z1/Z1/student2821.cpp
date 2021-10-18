/*B 2016/2017, Zadaća 1, Zadatak 1
	
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
typedef std::vector<int> Vec;

Vec IzdvojiGadne(Vec fvektor, bool x){

	for(int e=0;e<fvektor.size();e++){
		for(int a=e+1;a<fvektor.size();a++){
			if(fvektor[e]==fvektor[a]) fvektor.erase(fvektor.begin()+a);
			
		}
	}
	
	for(int z=0;z<fvektor.size();z++){
		for(int s=z+1;s<fvektor.size();s++){
			if(fvektor[z]==fvektor[s]) fvektor.erase(fvektor.begin()+s);
			
		}
	}
	
    Vec Opaki;
	Vec Odvratni;
	Vec Faktori;
	Vec Pomocni;
	Vec Brojaci;
	
	for(int i=0;i<fvektor.size();i++){
	
	int n;
	n=fvektor[i];
	int modul;
	
 
	while(n!=0){
		modul=n%3;
		Faktori.push_back(modul);
		n=n/3;
	}
 	int brojac=0;
	for(int i=0;i<Faktori.size();i++){
		int br;
		br=0;
		for(int k=0;k<Pomocni.size();k++){
			if(Faktori[i]==Pomocni[k]) br++;
		}
		if(br!=0) {
		continue;
		}	
		
		
	for(int j=0;j<Faktori.size();j++){
		if(Faktori[i]==Faktori[j]) brojac++;
	}
	Brojaci.push_back(brojac);
	brojac=0;
	
	Pomocni.push_back(Faktori[i]);
	} int pbr=0 , nbr=0;
	    for(int m=0;m<Brojaci.size();m++){
	    	if(Brojaci[m]%2==0) pbr++;
	    	if(Brojaci[m]%2!=0) nbr++;
	    	
	    }
	    if (pbr==Brojaci.size() and Faktori.size()!=0) Opaki.push_back(fvektor[i]);
	    if (nbr==Brojaci.size()) Odvratni.push_back(fvektor[i]);
	   
	
	Faktori=Vec (0);
	Pomocni=Vec (0);
	Brojaci=Vec (0);
	}
	 
	if(x==true) return Opaki;
	else return Odvratni;
}



int main ()
{   Vec Ispitaj;
   cout<< "Unesite brojeve (0 za prekid unosa): ";
    int a;
    do{
    	cin>>a;
    	if(a!=0) Ispitaj.push_back(a);
    } while(a!=0);
    Vec op=IzdvojiGadne(Ispitaj,true);
    Vec od=IzdvojiGadne(Ispitaj,false);
    
    cout<< "Opaki: ";
    for(int x=0;x<op.size();x++){
    	cout<< op[x] << " " ;
    }
    cout<<std::endl;
    cout<<"Odvratni: ";
    for(int y=0;y<od.size();y++){
    	
    	cout<< od[y] << " ";
    }
	return 0;
}


















