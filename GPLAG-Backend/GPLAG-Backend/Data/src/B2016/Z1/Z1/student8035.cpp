/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 
std::vector<int> IzdvojiGadne(std::vector<int>a,bool b) 
{
	std::vector<int> opaki;
	std::vector<int> odvratni;
	int broj,cifra;
	int suma_0=0,suma_1=0,suma_2=0;
	for(int i=0;i<a.size();i++)
	{
		broj=a[i];
	    if(broj==0) continue;
	    
		while (broj!=0) 
		{
			cifra=broj%3;
			if(cifra==0) suma_0++;
			else if(cifra==1) suma_1++;
			else suma_2++;
			broj/=3;
		}
	    
        
		if(suma_0%2==0&&suma_1%2==0&&suma_2%2==0) opaki.push_back(a[i]);
		else if((suma_0%2!=0||suma_0==0)&&(suma_1%2!=0||suma_1==0)&&(suma_2!=0||suma_2==0)) odvratni.push_back(a[i]);
	    else continue;
	             
	             continue;
		suma_0=0;
		suma_1=0;
		suma_2=0;
	
		}
	    
		if(b) return opaki;
		else return odvratni;
}

int main ()
{
	std::vector<int> unos;
	std::vector<int> parni;
	std::vector<int> neparni;

	std::cout << "Unesite elemente(0 za prekid): ";
	int x;
     while(x!=0)
     {
     	std::cin >> x;
     	unos.push_back(x);
     	if(x==0) break;
     }
    parni=IzdvojiGadne(unos,true);
    neparni=IzdvojiGadne(unos,false);
   
    std::cout << "Opaki: ";
    
    for(int x:parni)
    {
    	std::cout << x << " ";
    }
    std::cout<< std::endl;
    std::cout <<"Odvratni: ";
    for(int y:neparni)
    {
    	std::cout << y <<" ";
    }
    
    
    
	return 0;
}