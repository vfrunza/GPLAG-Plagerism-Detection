/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
/*U ovom zadatku potrebno je implementirati dvije funkcije za procesiranje teksta, nazvane
“ObrniFraze” i “IzmijeniUPigLatin”. Prvo ćemo opisati funkciju “ObrniFraze”. Njen prvi
parametar je neki string (tj. njegov tip je “std::string”) koji sadrži rečenicu u kojoj treba
obrnuti riječi ili fraze. Drugi parametar je vektor stringova (tj. vektor čiji su elementi tipa
“std::string”) koji sadrži popis riječi odnosno fraza koje treba obrnuti. Funkcija treba da kao
rezultat vrati modificiranu rečenicu u kojoj je svaka riječ odnosno fraza iz spiska izvrnuta
naopačke. Na primjer, ukoliko se kao prvi parametar funkciji proslijedi rečenica “Izasla je prva
zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih
predmeta”, a kao drugi parametar vektor koji sadrži stringove “zadaca”, “Tehnike programiranja”,
“drugih predmeta” i “meso od sira”, kao rezultat treba da se dobije string koji sadrži rečenicu
“Izasla je prva acadaz iz predmeta ajnarimargorp ekinheT, a ovih dana ocekujemo i jos acadaz iz
atemderp higurd”. Iz primjera je vidljivo i to da ukoliko se neka od fraza ne pronađe nigdje
unutar zadane rečenice (poput “meso od sira” u prethodnom primjeru), ne treba da se desi
ništa posebno. Postupak zamjene treba precizno da teče ovako. Uzima se redom jedan po jedan
string iz spiska fraza. Za svaki takav string traže se njegova pojavljivanja kao podstringa u
rečenici, redom slijeva nadesno (razmatra se samo potpuno poklapanje, uključujući i
eventualne razmake). Ukoliko se pronađe takav podstring, on se obrće, te nakon obrtanja
pomjeramo jedan znak udesno i nastavljamo dalje dok se eventualno ne obrnu sve pjave te
riječi/fraze. Nakon toga prelazimo na sljedeću riječ/frazu iz spiska, itd.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
string ObrniFraze(string recenica,vector<string> SpisakFraza){
	int br(0);
	string temp=recenica;
	for( int i=0;i<temp.length();i++){
		while(temp[i]==' '&& i<(int)temp.length())
		i++;
		if(i==temp.length()) break;
		br++;
		while(temp[i]!=' '&&i<(int)temp.length()-1)
		i++;
	}
	string rijeci[1000];
	int brojac=0;
	for(int i=0;i<recenica.length();i++){
		if(recenica[i]==' '){
			brojac++;
		}
		else {
			rijeci[brojac]+=recenica[i];
		}
	}
	string trazena;
	int duzina=0;
	int broj;
	for(int i=0;i<br;i++){
		for(int j=0;j<SpisakFraza.size();j++){
			if(rijeci[i]==SpisakFraza[j]){
				broj=i;
				trazena=rijeci[i];
				duzina=trazena.size();
				reverse(trazena.begin(),trazena.end());
				rijeci[i].replace(0,duzina,trazena);
			}
		}
	}
	string konacna;
	for(int i=0;i<br;i++){
		konacna+=rijeci[i];
		konacna+=' ';
	}
	return konacna;
}
string IzmijeniUPigLatin(string recenica,vector<string>SpisakRijeci){
	int br(0);
	string temp=recenica;
	for(int i=0;i<temp.length();i++){
		while(temp[i]==' '&& i<temp.length()) 
		i++;
		if(i==temp.length())
		break;
		br++;
		while(temp[i]!=' ' &&i < (int)temp.length()-1)
		i++;
	}
	string rijeci[1000];
	int brojac=0;
	for(int i=0;i<recenica.length();i++){
		if(recenica[i]==' '){
			brojac++;
		}
		else{
			rijeci[brojac]+=recenica[i];
		}
	}
	string trazena;
	int duzina(0);
	int broj;
	for(int i=0;i<br;i++){
		for(int j=0;j<SpisakRijeci.size();j++){
			
			if(rijeci[i]==SpisakRijeci[j]){
				broj=i;
				trazena=rijeci[i]; 
				string nova;
				for(int i=0;i<trazena.length();i++){
					if(i==0)i++;
					nova+=trazena[i];
				}
				nova+=trazena[0];
				nova=nova+"a";
				nova=nova+"y";
				duzina=nova.length();
				rijeci[i].replace(0,duzina,nova);
			}
		}
	}
	string konacna;
	for(int i=0;i<br;i++){
		konacna+=rijeci[i];
		konacna+=' ';
	}
	return konacna;
}
int main ()
{
	vector<string> SpisakRijeci;
	string rijeci;
	string recenica;
	cout<<"Unesite recenicu: ";
	getline(cin,recenica);
	cout<<"Unesite fraze: ";
	while(getline(cin,rijeci)){
		if(rijeci.size()==0) break;
		SpisakRijeci.push_back(rijeci);
	}
	string Rec1(ObrniFraze(recenica,SpisakRijeci));
	string Rec2(IzmijeniUPigLatin(recenica,SpisakRijeci));
	cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0;i<1;i++){
		cout<<Rec2;
	}
	cout<<endl;
	cout<<"Recenica nakon obrtanja fraza: ";
	for(int i=0;i<1;i++){
		cout<<Rec1;
	}
	
	return 0;
}