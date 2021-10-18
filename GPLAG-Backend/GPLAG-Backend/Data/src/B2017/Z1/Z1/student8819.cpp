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
#include <cmath>
#include <vector>

bool ProstSlozen(int n)
{
int a=n;
	if(a<=1) return false;

	for(int i=2;unsigned (i*i)<=a;i++)
	{
		if(a%i==0) return false;
	}
	return true;
}


std::vector<int>IzvediSimetricneTernarne(std::vector<int>c, int a){ 
	int i,j=0 ,k ,s, y,  temp[100];
	int n=c.size();
	int ternarni[100] ;
	std::vector<int>brojevi;
  std::vector<int>vraca;
    if(a==1) {
	for(int p = 0; p < n; p++) {
		
		
	
		if(ProstSlozen(c.at(p))) brojevi.push_back(c.at(p));
	}
	
	y=brojevi.size();
	std::vector<int>pok;
	for(int i=0;i<y;i++) {
		int p=brojevi.at(i);
		int r;
		int br=0;
		while(p!=0) {
			r=p%3;
			br=(br*10)+r;
			p=p/3;
			
		}
		pok.push_back(br);
	}

	
	int z=pok.size();
	for(int i=0;i<z;i++){
		int q=brojevi.at(i);
		int e=pok.at(i);
		int M=0;
		int w;
		while(e!=0){
			w=n%10;
			M=M*10+w;
			e=e/10;
		}
		if(M<0) M=M*-1;
	
	if(pok.at(i)==M && ((M)/10)>0) vraca.push_back(q);
	
return vraca;
	
	}
	return vraca;
}

else if(a==0) {
	for(int p = 0; p < n; p++) {
		
		if((ProstSlozen(c.at(p)))==false) brojevi.push_back(c.at(p));
		

}
	y=brojevi.size();
	std::vector<int>pok;
	for(int i=0;i<y;i++) {
		int p=brojevi.at(i);
		int r;
		int br=0;
		while(p!=0) {
			r=p%3;
			br=(br*10)+r;
			p=p/3;
			
		}
		pok.push_back(br);
	}

	int z=pok.size();
	for(int i=0;i<z;i++){
		int q=brojevi.at(i);
		int e=pok.at(i);
		int M=0;
		int w;
		while(e!=0){
			w=n%10;
			M=M*10+w;
			e=e/10;
		}
		if(M<0) M=M*-1;
	
	if(pok.at(i)==M && ((M)/10)>0)vraca.push_back(q);
	
	}
	return vraca;
}

}





			
		
		
int main ()
{
	
std::vector<int>m;
std::cout<<"Unesite elemente vektora (-1 za kraj):";

while(1)
	{
		int  unos;
		std::cin>>unos;
		if(unos==-1) break;
		else m.push_back(unos);
	}
	int a, n;
	std::cout<<" Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>a;
std::vector<int>p(IzvediSimetricneTernarne(m, a));
n=p.size();

if(a!=1 && a!=0){ std::cout<<"Neispravan unos! ";
std::cout<<"Unesite ponovo: ";
std::cin>>a;
}
 
	if(a==1 )
	{
		if(n>0){

		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i = 0; i < n; i++) 
		{
			if(i<n) std::cout<<p.at(i)<<", ";
			else std::cout<<p.at(i);
		}
		}
		else std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else {
		if(n>0){
		
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for (int i = 0; i < n; i++) 
		{
			if(i<n) std::cout<<p.at(i)<<", ";
			else std::cout<<p.at(i);
		}
	}

else	std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
}
	
	
	
	
	
	return 0;
}






