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

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v,bool slucaj){
	std::vector<int> rezultat;
	
	for(int i(0);i<v.size();i++)
	{
	     int decimalni,ternarni(0),potencija(1);
	     bool prost=true;
	     decimalni=v.at(i);
	  //provjerimo da li je taj broj prost
	  for(int j(2);j<=sqrt(decimalni);j++){
	  	if(decimalni%j==0) 
	  	prost=false;
	  }
       	 if(decimalni < 0)
	       decimalni*=-1;
	   
	while(decimalni != 0)
	{
		ternarni+=(decimalni%3)*potencija;
		potencija*=10;
		decimalni/=3;
	}
	//provjerimo da li je ternarna reprezentacija simetricna
	int pomocni=ternarni,s(0),d(0);
	  while(ternarni!=0){
	  	int c=ternarni%10;
	  	s=d*10+c;
	  	d=s;
	  	ternarni/=10;
	  }
	  if(slucaj==true && prost==true){
	       if(pomocni==d)
	       rezultat.push_back(v.at(i));
	}
	else if(slucaj==false && prost==false)
	{   
	    if(pomocni==d)
		 rezultat.push_back(v.at(i));
	}
}
return rezultat;
}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
 while(true)
 { 
 	int x;
 	std::cin>>x;
 	if(x==(-1))
 	  break;
 	v.push_back(x);
 }
	
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>n;
	
	while(n!=1 && n!=0){
		std::cin.clear();
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>n;
	}

	if(n==1){
	      v=IzdvojiSimetricneTernarne(v,true);
	      if(v.size()==0)
	        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	      else{
	      std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	       for(int i(0);i<v.size();i++){
	       	   if(i==v.size()-1)
	        std::cout<<v.at(i)<<".";
	           else 
	         std::cout<<v.at(i)<<", ";
	       }
	      }
	}
	else if(n==0){
	     v=IzdvojiSimetricneTernarne(v,false);
	      if(v.size()==0)
	        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	      else{
	     std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        	for(int i(0);i<v.size();i++){
        		if(i==v.size()-1)
        		 std::cout<<v.at(i)<<".";
        		else
        std::cout<<v.at(i)<<", ";
	      }
	}
	}
	
	return 0;
}