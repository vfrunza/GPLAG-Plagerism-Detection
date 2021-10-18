/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
typedef std::vector<int> vektor;

vektor IzbaciElement(vektor v){
	for( int i=0 ; i<v.size() ; i++){
		for( int j=i+1 ; j<v.size() ; j++){
			if(v[i]==v[j]) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	
	   return v;
}

vektor IzdvojiGadne (vektor v , bool n ){
	vektor a;
	vektor b;
	
	for(int x : v){
		int br0(0),br1(0),br2(0);
		int y(x);
		do{
			if(y<0) y *= (-1);
			int z(y);
			z=z%3;
			if(z==0) br0++;
			if(z==1) br1++;
			if(z==2) br2++;
			y=y/3;
		}while(y!=0);
		if(br0%2==0 && br1%2==0 && br2%2==0) a.push_back(x);
		else if((br0%2!=0 || br0==0)  && (br1%2!=0 || br1==0) && ( br2%2!=0 || br2==0) ) b.push_back(x);
		
	}

		
	
	if(n==true) return IzbaciElement(a);
	else return IzbaciElement(b);
}
int main ()
{
  
   vektor v(0);
   std::cout<<"Unesite brojeve (0 za prekid unosa): ";
  long long int x;
  std::cin>>x;
   while(x!=0){
   v.push_back(x);
   std::cin>>x;
 
   }

vektor opaki = IzdvojiGadne(v, true);
vektor odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (int y : opaki) std::cout << y << " ";
std::cout << std::endl << "Odvratni: ";
for (int y : odvratni) std::cout << y << " ";
   
	return 0;
}

