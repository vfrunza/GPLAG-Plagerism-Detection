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
bool ProstBroj(int n){
	
	for(int i=2;i<abs(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
std::vector <int> IzdvojiSimetricneTernarne(std::vector<int> v,bool a){
	std::vector <int> novi;
	
	if(a){
		for(int i=0;i<v.size();i++){
			if(ProstBroj(v.at(i))) {
				novi.push_back(v[i]);
		}		
		else continue;
		}

	}
	else{
		for(int i=0;i<v.size();i++){
			if(!ProstBroj(v.at(i))) novi.push_back(v[i]); 
		}
	}
	

	std::vector <int> normalni ;
	normalni=novi;
	std::vector <int> gotov ;
	std::vector <int> tv;
	int cifra,cifra2,negativan,trbr,m=0,konacni,cifrica,duzina,jeste;
	for(int k=0;k<novi.size();k++){
		negativan=0;
	if(novi[k]<0) {
	negativan=1;
	novi[k]=novi[k]*(-1);}
		trbr=0;
	do{
		cifra=novi[k]%3;
		if(cifra==0) trbr=10*trbr;
		else trbr=trbr*10+cifra;
		novi[k]=novi[k]/3;
	
	}while(novi[k]!=0);
	if(negativan) trbr=trbr*(-1);
	tv.push_back(trbr);
	/*konacni=0;
	do{
	cifra2=trbr%10;
	if(cifra2==0) konacni=10*konacni;
	else konacni=konacni*10+cifra2;
	trbr=trbr/10;
	}while(trbr!=0);
	if(negativan) konacni=konacni*(-1);
	tv.push_back(konacni);*/
	}
	
	for(int i=0;i<tv.size();i++){
		std::vector <int> cif;
		duzina=0;
		while(tv.at(i)!=0){
			cifrica=tv.at(i)%10;
			tv.at(i)=tv.at(i)/10;
			cif.push_back(cifrica);
			duzina++;
		}
	
		jeste=0;
		for(int j=0;j<cif.size();j++){
			if(duzina%2!=0){
			if(j==cif.size()-j-1) {
                jeste =1;
				break; }
			if(cif[j]==cif[cif.size()-j-1]) continue;
			else break;
			}
			else{
				if(j==cif.size()/2) {
                jeste =1;
				break; }
			if(cif[j]==cif[cif.size()-j-1]) continue;
			else break;
				
			}
		}
		
		if(jeste){
			
		gotov.push_back(normalni[m]);
		}
		m++;
		
	}
	for(int  i=0;i<gotov.size();i++){
		for(int j=i+1;j<gotov.size();j++){
			if(gotov.at(i)==gotov.at(j)){
			for(int k=j;k<gotov.size()-1;k++){
				gotov.at(k)=gotov.at(k+1);
			}
			gotov.resize(gotov.size()-1);
			j--;
		}
		}
	}
	return gotov;
}

int main ()
   {int broj;
   std::vector <int> brojevi;
   std::vector <int> ternarni;
	std::cout <<"Unesite elemente vektora (-1 za kraj): ";
	do{
	std::cin>>broj;	
	if(broj!=-1){
		brojevi.push_back(broj);
	}
	else break;
	}while(broj!=-1);
	std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int brojic;
	std::cin >> brojic;
	do{
			
			if(brojic==0 || brojic==1) break;
	std::cout <<"Neispravan unos! Unesite ponovo: ";
	std::cin>>brojic;
		
	}while(brojic!=0 || brojic!=1);
   
	ternarni=IzdvojiSimetricneTernarne(brojevi,brojic);
	if(ternarni.size()==0 && brojic) std::cout <<"Nema prostih simetricnih brojeva u vektoru.";
	else if(ternarni.size()==0 && !brojic) std::cout <<"Nema slozenih simetricnih brojeva u vektoru.";
	else if(brojic){
	std::cout <<"Prosti simetricni brojevi iz vektora su: ";
	for(int j=0;j<ternarni.size();j++){
		if(j==ternarni.size()-1) std::cout <<ternarni[j]<<".";
	    else std::cout <<ternarni[j]<<", ";
	}
	}
	else if(!brojic){
		std::cout <<"Slozeni simetricni brojevi iz vektora su: ";
	for(int j=0;j<ternarni.size();j++){
		if(j==ternarni.size()-1) std::cout <<ternarni[j]<<".";
	    else std::cout <<ternarni[j]<<", ";
	}
	}
	
	return 0;
}