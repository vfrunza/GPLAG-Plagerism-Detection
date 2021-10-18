#include <iostream>
#include <vector>

typedef std::vector<int> Vektori;

std::vector<int> IzdvojiGadne(Vektori prvi, bool istina) {
	
	Vektori opaki;
	Vektori odvratni;
	Vektori obicni;
	
int  o, s, brojac0=0, brojac1=0, brojac2=0;
for(int i=0;i<prvi.size();i++){
	int n = prvi[i];
    int brojac=0;
	for(int i=0;i<opaki.size();i++)
	{
		if(n==opaki[i])
		{
			brojac++;
			break;
		}
	}
	for(int i=0;i<odvratni.size();i++)
	{
		if(n==odvratni[i])
		{
			brojac++;
			break;
		}
	}
	if(brojac==0){
		n=abs(n);
	while(n!=0){
	
	o=n/3;
	s=n%3;
	if(s==0)brojac0++;
	else if(s==1)brojac1++;  
	else if(s==2)brojac2++;
	n=o;
	if(n==0)break;
	                 
}


	int ostatak0,ostatak1,ostatak2;
			ostatak0=(brojac0%2);
			ostatak1=(brojac1%2);
			ostatak2=(brojac2%2);
			
			if(ostatak0==0 && ostatak1==0 && ostatak2==0)
			{
				opaki.push_back(prvi[i]);
			}
			if(ostatak0==1 && ostatak1==1 && ostatak2==1)
			{
				odvratni.push_back(prvi[i]);
			}
			
			if((ostatak0==1 && ostatak1==1 && brojac2==0)||(brojac0==0 && ostatak1==1 && ostatak2==1) || (ostatak0==1 && brojac1==0 && ostatak2==1))
			{
				odvratni.push_back(prvi[i]);
			}
		
		
	}
	    brojac0=0;
		brojac1=0;
		brojac2=0;
}



	
		 if(istina==true) return opaki;               
		 else if(istina==false) return odvratni;
		
	
}



	
	
	





int main ()
{
	
	
	
	
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	
	
	Vektori vektor, vraceni;
	
	int a;                        
	for(int i=0;i<100;i++){
		std::cin >> a;
		if(a==0)break;
		vektor.push_back(a);
	}
		
	

	
	
	
		Vektori b;
		b=IzdvojiGadne(vektor,true);
		Vektori c;
		c=IzdvojiGadne(vektor,false);
		
	
	
	
	
	
	
	
	
	
		std::cout << "Opaki: ";
		for(int i: b) {std::cout << i << " ";   
		}
		std::cout << std::endl;
		
		std::cout << "Odvratni: ";
		for(int j: c){
			std::cout << j << " ";
		}
		

	
		return 0;
}