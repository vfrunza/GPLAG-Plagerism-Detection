/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include<stdexcept>
#include<cmath>
using namespace std;
string ObrniAkoImaFraza(string recenica, string fraza)
{
	int j=0,brojacznakova=0;
	for(int i=0; i<recenica.length(); i++) {
		int k=i;
		brojacznakova=0;
		j=0;
		while(k<recenica.length() && j<fraza.length() && recenica[k]==fraza[j]) {
			brojacznakova++;
			j++;
			k++;
		}
		if(brojacznakova==fraza.length()) {
			k=i;
			j=0;
			while(k<(i+fraza.length()))	{
				recenica[k]=fraza[fraza.length()-j-1];
				j++;
				k++;
			}
			brojacznakova=0;
		}

		if(recenica[i]!=fraza[j]) {
			brojacznakova=0;
			j=0;
		}
	}
	return recenica;
}
string ObrniFraze(string recenica, vector<string> nizrijeci)
{
	if(recenica.size()==0)return recenica;
	for(int j=0; j<nizrijeci.size(); j++) {
		recenica=ObrniAkoImaFraza(recenica, nizrijeci[j]);
	}
	return recenica;
}
string PiglatajNekako(string recenica, string fraza)
{
	int j=0,brojacznakova=0;
	for(int i=0; i<recenica.length(); i++) {
		int k=i;
		brojacznakova=0;
		j=0;
		while(k<recenica.length() && j<fraza.length() && ((fraza[j]>='A' && fraza[j]<='Z') || (fraza[j]>='a' && fraza[j]<='z')) && recenica[k]==fraza[j]) {
			brojacznakova++;
			j++;
			k++;
		}
		if(brojacznakova==fraza.length() && (k+1)<recenica.size() && !((recenica[k+1]>='a' && recenica[k+1]<='z') || (recenica[k+1]>='A' && recenica[k+1]<='Z'))) {
			k=i;
			j=0;

			recenica.insert(recenica.begin()+k+fraza.length(), recenica[k]);
			recenica.insert(recenica.begin()+(k+fraza.length()+1), 'a');
			recenica.insert(recenica.begin()+(k+fraza.length()+2),'y' );
			recenica.erase(recenica.begin()+k);

			brojacznakova=0;
		}

		if(recenica[i]!=fraza[j]) {
			brojacznakova=0;
			j=0;
		}
	}
	return recenica;
}
string PiglatajNekakoCijelu(string recenica)
{
	int brojacznakova=0;
	for(int i=0; i<recenica.length(); i++) {
		if(!((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')))continue;
		int k=i;
		int pocetno=i;
		while((recenica[k]>='a' && recenica[k]<='z') || (recenica[k]>='A' && recenica[k]<='Z')) {
			brojacznakova++;
			k++;
		}
		recenica.insert(recenica.begin()+pocetno+brojacznakova, recenica[pocetno]);
		recenica.insert(recenica.begin()+(pocetno+brojacznakova+1), 'a');
		recenica.insert(recenica.begin()+(pocetno+brojacznakova+2),'y' );
		recenica.erase(recenica.begin()+pocetno);
		i=pocetno+1+brojacznakova;
		brojacznakova=0;
	}
	return recenica;
}
string IzmijeniUPigLatin(string recenica, vector<string> nizrijeci)
{
	for(int i=0; i<nizrijeci.size(); i++) {
		for(int j=0; j<nizrijeci[i].size(); j++) {
			if(!((nizrijeci[i][j]>='a' && nizrijeci[i][j]<='z') || (nizrijeci[i][j]>='A' && nizrijeci[i][j]<='Z')))
				throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	if(recenica.size()==0)return recenica;
	if(nizrijeci.size()==0) {
		recenica=PiglatajNekakoCijelu(recenica);
		return recenica;
	}
	for(int j=0; j<nizrijeci.size(); j++) {
		recenica=PiglatajNekako(recenica, nizrijeci[j]);
	}

	return recenica;
}
int main ()
{
	string recenica,fraza;
	vector<string> fraze;
	cout<<"Unesite recenicu: ";
	getline (cin,recenica);
	cout<<"Unesite fraze: ";
	do {
		getline (cin,fraza);
		if(fraza.length()>0)
			fraze.push_back(fraza);
		else break;
	} while(true);


	try {
		cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica,fraze)<<endl;
	} catch(std::domain_error izuzetak) {
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}

	cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica,fraze)<<endl;
	return 0;
}

