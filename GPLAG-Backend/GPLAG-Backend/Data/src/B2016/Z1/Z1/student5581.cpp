/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

typedef std::vector<int> IntVektor;

int BrojPonavljanja(int x,int y){
	
	int brojac(0);

	do{
		if(std::abs(x%3)==y)
		brojac++;
		x/=3;
	}
	while(x);
	
	return brojac;
}

bool PonavljaSe(IntVektor v, int x){
	for(int i=0;i<v.size();i++){
		if(v[i]==x)
			return true;
	}
	return false;
}

bool JeOpak(int broj){
	if(BrojPonavljanja(broj,0)%2==0&&BrojPonavljanja(broj,1)%2==0&&BrojPonavljanja(broj,2)%2==0)
		return true;
	return false;
}

bool JeOdvratan(int broj){
	if((BrojPonavljanja(broj,0)%2!=0||BrojPonavljanja(broj,0)==0)&&(BrojPonavljanja(broj,1)%2!=0||BrojPonavljanja(broj,1)==0)&&(BrojPonavljanja(broj,2)%2!=0||BrojPonavljanja(broj,2)==0))
		return true;
	return false;
}

IntVektor IzdvojiGadne(IntVektor brojevi, bool x){
	
	IntVektor gadni;
	
	if(x){
		for(int i=0;i<brojevi.size();i++){
			if(JeOpak(brojevi[i])&&!PonavljaSe(gadni, brojevi[i]))
				gadni.push_back(brojevi[i]);
		}
	}
	else {
		for(int i=0;i<brojevi.size();i++){
			if(!PonavljaSe(gadni, brojevi[i])&&JeOdvratan(brojevi[i]))
				gadni.push_back(brojevi[i]);
		}
	}
	return gadni;
}

int main (){

	IntVektor v;
	int x;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(std::cin>>x,x!=0){
		
		v.push_back(x);
	}
	
	 auto opaki(IzdvojiGadne(v,true));
	 auto odvratni(IzdvojiGadne(v,false));
	 
	 std::cout<<"Opaki: ";
	 for(int t : opaki) std::cout<<t<<" ";
	
	 std::cout<<std::endl;
	 
	 std::cout<<"Odvratni: ";
	 for(int t : odvratni) std::cout<<t<<" ";

	return 0;
}