/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


bool DaLiJeOpak(int n){
	int cifra;
	std :: vector<int> pomocni;

	while(n!=0){
		cifra=n%3;
		pomocni.push_back(cifra);
		n=n/3;
	}
	
	int jedinica(0), dvica(0), nula(0), i(0);  //Trebaju mi brojaci za svaki broj
	
	while(i<pomocni.size()){
		if(pomocni[i]==0) nula++;
		if(pomocni[i]==1) jedinica++;
		if(pomocni[i]==2) dvica++;
		i++;
		
	}
	
	if(nula%2==1 && jedinica%2==1  && dvica%2==1 ) return false;
	else if(nula%2==0  && jedinica%2==0  && dvica%2==0 ) return true;

}

//Kako bool vraca samo dvije vrijednosti, trebam potvrditi da li je neki broj zaista gadni, 
//kako ne bi brojevi koji nisu gadni zavrsili u vektorima odvratnih ili opakih.

bool SigurnoOdvratan(int n){
	int cifra;
	std :: vector<int> pomocni;
	while(n!=0){
		cifra=n%3;
		pomocni.push_back(cifra);
		n=n/3;
	}
	
	int jedinica(0), dvica(0), nula(0), i(0);
	while(i<pomocni.size()){
		if(pomocni[i]==0) nula++;
		if(pomocni[i]==1) jedinica++;
		if(pomocni[i]==2) dvica++;
		i++;
	}
	
	if((nula%2==1 || nula==0) && (jedinica%2==1 || jedinica==0) && (dvica%2==1 || dvica==0)) return true;
	return false;
}

std :: vector<int> IzdvojiGadne(std :: vector <int> v, bool a){

	std :: vector<int> opaki;
	std :: vector<int> odvratan;
	std :: vector<int> nepotrebni;
	
	for(int i(0);i<v.size(); i++){
		if(DaLiJeOpak(v[i])==false && SigurnoOdvratan(v[i])==true) odvratan.push_back(v[i]);
		else if(DaLiJeOpak(v[i])==false && SigurnoOdvratan(v[i])==false) nepotrebni.push_back(v[i]);
		else opaki.push_back(v[i]);
		}
	
	for(int i(0); i<opaki.size(); i++){
		for(int j=i+1; j<opaki.size(); j++){
			if(opaki[j]==opaki[i]){
				opaki.erase(opaki.begin()+j);
				j--;
			}
		}
	}
	
	for(int i(0); i<odvratan.size(); i++){
		for(int j=i+1; j<odvratan.size(); j++){
			if(odvratan[j]==odvratan[i]){
				odvratan.erase(odvratan.begin()+j);
				j--;
			}
		}
	}
	
	if(a==true) return opaki;
	return odvratan;

}

int main ()
{
	std :: vector<int> v;
	int n;
	
	std :: cout << "Unesite brojeve (0 za prekid unosa): ";
	
	do{
		std :: cin>>n;
		if(n==0) break;
		v.push_back(n);
		
		
	} while(1);
	
	std :: vector<int> opaki=IzdvojiGadne(v, true);
	std :: vector<int> odvratni=IzdvojiGadne(v, false);
	
	std :: cout << "Opaki: ";
	for(int i=0; i<opaki.size(); i++){
		
		std :: cout << opaki[i]<<" ";
	}
	
	std :: cout << std :: endl;
	
	std :: cout << "Odvratni: ";
	for(int i=0; i<odvratni.size(); i++){
	
	
		std :: cout << odvratni[i]<<" ";
	}
	
	
	return 0;
}