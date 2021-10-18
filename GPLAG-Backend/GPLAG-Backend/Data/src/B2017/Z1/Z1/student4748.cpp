/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> ProstiSlozeni(vector<int> y,bool x){
       vector<int> prosti,slozeni;
       int brojac=0,predznak=1;
       for(int i=0;i<y.size();i++){
       	   if(y.at(i)<0){
       	   	predznak=-1;
       	   	y.at(i)=fabs(y.at(i));
       	   }
       	 for(int j=1;j<=y.at(i);j++){
       	 	 if(y.at(i)%j==0){
       	 	 	brojac++;
       	 	 }
       	 }
       	 y.at(i)=predznak*y.at(i);
       	 predznak=1;
       	 if(brojac==2){
       	 	prosti.push_back(y.at(i));
       	 }
       	 else{
       	 	slozeni.push_back(y.at(i));
       	 } 
       	 brojac=0;
         }
       if(x==true){
       return prosti;
       }
       else{
       	return slozeni;
       }
}
int Obrnut(int t){
	int obrnut=0,pomoc;
	while(t>0){
		pomoc=t%10;
		obrnut=obrnut*10+pomoc;
		t/=10;
	}
	return obrnut;
}
vector<int> Filter(vector<int> f){
	vector<int> h;
	if(f.size()!=0){
	h.push_back(f.at(0));
	for(int i=1;i<f.size();i++){
		for(int j=0;j<h.size();j++){
			if((f.at(i)!=h.at(j))){
				if(j==(h.size()-1)){
				h.push_back(f.at(i));
			   }
			}
			else{
				break;
			}
		  }
	    }
      }
	return h;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> v,bool b){
	vector<int> z,konacni;
	int temp,pom=0,pocetna,predznak=1;
	z=ProstiSlozeni(v,b);
	for(int i=0;i<z.size();i++){
		if(z.at(i)<0){
			predznak=-1;
			z.at(i)=fabs(z.at(i));
		}	pocetna=z.at(i);
		while(z.at(i)>0){
			temp=z.at(i)%3;
			pom=pom*10+temp;
			z.at(i)=z.at(i)/3;
		}
		z.at(i)=pocetna*predznak;
		predznak=1;
		if(Obrnut(pom)==pom){
			konacni.push_back(z.at(i));
		}
		pom=0;	
		
	}
	konacni=Filter(konacni);
   return konacni;
}

int main (){
	vector<int> unos,zavrsni;
	int n,l,k;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		cin>>n;
		if(n!=-1){
		unos.push_back(n);
		}
	}while(n!=-1);
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	    cin>>l;
    	while(l!=1 && l!=0){
        	cout<<"Neispravan unos! Unesite ponovo: ";
		    cin>>k;
	    	l=k;
    	  }
	if(l==false){
		zavrsni=IzdvojiSimetricneTernarne(unos,l);
		if(zavrsni.size()==0){
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	    	}
		else{
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
	    for(int i=0;i<zavrsni.size();i++){
	   	 if(i!=(zavrsni.size()-1)){
	   	  cout<<zavrsni.at(i)<<", ";
	   	}
	   	else{
	   		cout<<zavrsni.at(i)<<".";
	    	}
	      }
	   	}
   	 }
	if(l==true){
	zavrsni=IzdvojiSimetricneTernarne(unos,l);
	if(zavrsni.size()==0){
       	cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else{
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	   for(int i=0;i<zavrsni.size();i++){
	   	if(i!=(zavrsni.size()-1)){
	   	cout<<zavrsni.at(i)<<", ";
	   	}
	   	else{
	   		cout<<zavrsni.at(i)<<".";
	   	}
	  }
	}
	return 0;
 }
}