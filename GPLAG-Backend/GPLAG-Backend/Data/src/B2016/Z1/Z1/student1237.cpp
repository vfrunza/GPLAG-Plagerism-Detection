/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> brojevi,bool tacnost){
	std::vector<int> odvratni;
	std::vector<int> opaki;
	
	int x;
	for(int i=0;i<brojevi.size();i++){
		x=brojevi[i];
		int brojac(0),brojac1(0),brojac2(0),y;
		
		while(x!=0){
			y=x%3;
			x=x/3;
			if(y==0) brojac++;
			if(y==1) brojac1++;
			if(y==2) brojac2++;
			
		}
		if(brojac%2==0 && brojac1%2==0 && brojac2%2==0){
			int br=0;
			for(int vrag:opaki){
				if(vrag==brojevi[i])
				br++;
			}
			if(br==0) opaki.push_back(brojevi[i]);
		}
		else if((brojac%2!=0 || brojac==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)){
			int br=0;
			for(int vrag: odvratni){
				if(vrag==brojevi[i])
				br++;
			}
			if(br==0) odvratni.push_back(brojevi[i]);
		}
		else ;
	}
	if(tacnost==true) return opaki;
	 return odvratni;
}
int main ()
{
	std::vector<int> brojevi;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>n;
	while(n!=0){
		
	
	brojevi.push_back(n);
	std::cin>>n;	
	}
	std::vector<int> opaki;
	std::vector<int> odvratni;
	opaki=IzdvojiGadne(brojevi,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	odvratni=IzdvojiGadne(brojevi,false);
	std::cout<<"Odvratni: ";
	for(int i=0;i<odvratni.size();i++){
		std::cout<<odvratni[i]<<" ";
	}

	
	
	return 0;
}