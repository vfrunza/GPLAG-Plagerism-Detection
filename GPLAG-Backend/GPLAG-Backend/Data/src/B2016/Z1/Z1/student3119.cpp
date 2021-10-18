/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool istinitost){
	std::vector<int> vektor;
	for(int i=0; i<v.size(); i++){
		int kopija(v[i]), ternarni_broj(0),ostatak(0), brojac(0), broj_nula(0), broj_jedinica(0), broj_dvica(0);
		while(kopija!=0){
			ostatak=kopija%3;
			//Naredne tri linije koda broje nule, jedinice i dvice u ternarnom broju
			if(ostatak==0) broj_nula++;
			else if(ostatak==1) broj_jedinica++;
			else if(ostatak==2) broj_dvica++;
			if(ternarni_broj==0 && ostatak==0) brojac++; //Ako je nekoliko prvih ostataka==0, da uveca brojac, kako bi poslije nogli taj ternarni broj koji dobijemo mogli toliko puta pomnoziti sa 10, kako bi se uracunale i te pocetne nule 
			ternarni_broj+=ostatak;
			kopija=kopija/3;
			if(kopija!=0) ternarni_broj*=10;
		}
		for(int i=0; i<brojac; i++)	ternarni_broj=ternarni_broj*10; //Ovo sam napisla cisto da mi nakraju ispise terarni broj (ali ce naopako biti napisan)
		
		bool parne_nule(false), parne_jedinice(false), parne_dvice(false); 
		if(v[i]==0) broj_nula=1; //Ako je 0 elemenat vektora
		if(broj_nula!=0 && broj_jedinica!=0 && broj_dvica!=0){
			if(broj_nula%2==0) parne_nule=true;
			if(broj_jedinica%2==0) parne_jedinice=true;
			if(broj_dvica%2==0) parne_dvice=true;
			if(parne_nule==istinitost && parne_jedinice==istinitost && parne_dvice==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_nula!=0 && broj_jedinica!=0 && broj_dvica==0){
			if(broj_nula%2==0) parne_nule=true;
			if(broj_jedinica%2==0) parne_jedinice=true;
			if(parne_nule==istinitost && parne_jedinice==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_nula!=0 && broj_dvica!=0 && broj_jedinica==0){
			if(broj_nula%2==0) parne_nule=true;
			if(broj_dvica%2==0) parne_dvice=true;
			if(parne_nule==istinitost && parne_dvice==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_jedinica!=0 && broj_dvica!=0 && broj_nula==0){
			if(broj_jedinica%2==0) parne_jedinice=true;
			if(broj_dvica%2==0) parne_dvice=true;
			if(parne_jedinice==istinitost && parne_dvice==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_nula!=0 && broj_jedinica==0 && broj_dvica==0){
			if(broj_nula%2==0) parne_nule=true;
			if(parne_nule==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_jedinica!=0 && broj_dvica==0 && broj_nula==0){
			if(broj_jedinica%2==0) parne_jedinice=true;
			if(parne_jedinice==istinitost) vektor.push_back(v[i]);
		}
		
		else if(broj_dvica!=0 && broj_nula==0 && broj_jedinica==0){
			if(broj_dvica%2==0) parne_dvice=true;
			if(parne_dvice==istinitost) vektor.push_back(v[i]);
		}
	
	}
	
	//Brisanje brojeva (koji se ponavljaju) iz rezultujuceg vektora
	for(int i=0; i<vektor.size()-1; i++){
		for(int j=i+1; j<vektor.size(); j++){
			if(vektor[i]==vektor[j]) vektor.erase(vektor.begin() + j);
		}
	}
	
	return vektor;
}



int main (){
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;){
		int a;
		std::cin>>a;
		if(a==0) break;
		else v.push_back(a);	
	} 
	std::vector<int> opaki(IzdvojiGadne(v,true));
	std::cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++) std::cout<<opaki[i]<<" ";
	
	std::vector<int> odvratni(IzdvojiGadne(v,false));
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++) std::cout<<odvratni[i]<<" ";
	
	
	
	return 0;
}