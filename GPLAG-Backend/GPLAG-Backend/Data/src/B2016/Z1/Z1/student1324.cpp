/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> PretvoriBroj(int x){
	std::vector<int>v(10);
	int flag(1);                  //funkcija pravi vektor ciji su elementi broj ponavljanja svake cifre broja
	    if(x<0)flag=0;
	    if(x==0)v[0]++;
	    while(x!=0){
		    int a(0);             
		    a=x%3;                 //pretvorba broja
		    if(flag==0)a=a*(-1);
		    v.at(a)++;           
		    x=x/3;
	    }
	return v;
}
bool DaLiJeOpak(std::vector<int> v){
	for(int x:v)if(x%2==1 && x!=0)return 0;
	return 1;
}

bool DaLiJeOdvratan(std::vector<int>v){
	for(int x:v)if(x%2==0 && x!=0)return true;
	return false;
}
std::vector<int> IzdvojiGadne(std::vector<int>v,bool p){
	std::vector<int>v1;
	for(int x:v){
		std::vector<int>y(10);
		int flag(0);
		y=PretvoriBroj(x);         
		if(p==true){                       //u zavisnosti od uslova provjeravaju se brojevi
			if(p==DaLiJeOpak(y)){
			    for(int z:v1)if(z==x)flag=1;       //da li se mozda vec nalazi broj koji smo pretvarali u vektoru
			    if(flag)continue;
		        else v1.push_back(x);
			}
		}
		if(p==false){
			if(p==DaLiJeOdvratan(y)){
			    for(int z:v1)if(z==x)flag=1;
			    if(flag)continue;
			    else v1.push_back(x);
			}	    
		}
	}
	return v1;
}

int main ()
{
	std::vector<int>v;
    int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
    while(std::cin >> x && x!=0){
    	v.push_back(x);
    }
        std::vector<int>v1;
        v1=IzdvojiGadne(v,true);
        std::cout << "Opaki: " ;
        for(int y:v1)std::cout << y << " " ;
            std::vector<int>v2;
            v2=IzdvojiGadne(v,false);
            std::cout << std::endl << "Odvratni: " ;
            for(int y:v2)std::cout << y << " ";
    
	return 0;
}