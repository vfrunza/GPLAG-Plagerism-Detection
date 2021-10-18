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
  using namespace std;
  
long long Ternarni(long long broj)
{ 
 if(broj<0) 
broj*=-1;
	vector <long long> Ostaci;
long long pretvoreni(0);

	while (broj!=0) 
	{
	 Ostaci.push_back(broj%3);
 	broj=broj/3;
	}
	
	for(int i = Ostaci.size() ; i>0 ; i--){
		pretvoreni=pretvoreni*10+Ostaci.at(i-1);
		cout << " ";
		/*long long kopija=pretvoreni;
		int brojac(0);
		while(kopija>0){ kopija/=10; brojac++;
    if(brojac>10) return 331;}*/
	}
return pretvoreni;

}

bool Opaki (long long uneseni){
            long long kopija = uneseni;
            
           bool rezultat=false;
           int Dvice(0);
           int Nule(0);
           int Jedinice(0);
          
           
           while(kopija>0){
            
             	if(kopija%10==0) Nule++;
             	else if(kopija%10==1) Jedinice++;
             	else Dvice++;
             	kopija=kopija/10;
             	
           }
             
           if((Nule%2==0) && (Jedinice%2==0) && (Dvice%2==0)){
           rezultat=true;}
           return rezultat;
}
 
  
  bool Odvratni (long long uneseni){
  bool rezultat(false);
 
  long long kopija(uneseni);
   int Dvice(0);
   int Jedinice(0);
   int Nule(0);
  bool Ispravno_nule=true;
  bool Ispravno_jedinice=true;
  bool Ispravno_dvice=true;
  
 
   while(kopija>0){
   
   	if(kopija%10==0) Nule++;
   	else if (kopija%10==1) Jedinice++;
   	else Dvice++;
   	kopija/=10;
   }
   
  if(Nule%2==0 && Nule>0){
   Ispravno_nule=false;
  }
  if(Jedinice%2==0 && Jedinice>0){
   Ispravno_jedinice=false;
  }
  if(Dvice%2==0 && Dvice>0){
   Ispravno_dvice=false;
  }
   
  if(Ispravno_nule&&Ispravno_jedinice&&Ispravno_dvice){
   rezultat=true;
  }
  return rezultat;
   
  }
   
  bool Neponavljanje(vector<long long>a,long long x){
  bool rez=true;
 for(int i(0);i<a.size();i++)
  if(a.at(i)==x) rez=false;
  return rez;
  } 
  
  
		 vector<long long> IzdvojiGadne(vector<int> Unos, bool Izbor){
   	
   	vector <long long> lokalni_brojevi;
   	for(int i = 0 ; i < Unos.size(); i++)
   	{
   	 lokalni_brojevi.push_back(Unos.at(i));
   	}
  vector<long long> rezultat ;
   long long trenutni;
   
  for(int  i(0);i<Unos.size();i++){
  trenutni= Unos.at(i);
  if(Izbor && Opaki(Ternarni ( trenutni)) && Neponavljanje(rezultat,trenutni))
  rezultat.push_back(trenutni);
  
  else if (!Izbor && Odvratni (Ternarni(trenutni)) && Neponavljanje(rezultat,trenutni))
  rezultat.push_back(trenutni);
		 	
		 }
  return rezultat; }
  
  

int main ()
{
 vector<int> brojevi;
 int temp;
 cout<<"Unesite brojeve (0 za prekid unosa): ";
 cin>>temp;
if(temp!=0){
 
 do { 

  brojevi.push_back(temp);
cin>>temp; 
} while (temp!=0);
 
}

vector<long long> opaki = IzdvojiGadne(brojevi, true);
vector<long long> odvratni = IzdvojiGadne(brojevi, false);

cout<<"Opaki: "; 
for(int i = 0; i < opaki.size(); i++)
cout << opaki.at(i) << " ";
cout<<endl;
cout<<"Odvratni: ";
for(int i = 0; i < odvratni.size(); i++)
cout << odvratni.at(i) << " ";
cout << endl;

	return 0;
}