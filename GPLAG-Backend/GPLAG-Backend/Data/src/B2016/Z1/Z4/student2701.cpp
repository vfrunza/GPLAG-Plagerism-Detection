/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<stdexcept>
#include<iomanip>
#include<cstring>

using namespace std;

string ObrniFraze(string a, vector<string> b){
	string pomocni;
	string oprez;
	string vracanje;
	for(int i=0;i<a.size();i++){
		while(a[i]!='\0' && a[i]!=' '){
			pomocni.push_back(a[i]);
			i++;
		}
         
		for(int j=0;j<b.size();j++){
			if(pomocni==b[j]){
				oprez=b[j];
				for(int k=pomocni.size()-1;k>=0;k--){
					pomocni[k]=oprez[pomocni.size()-1-k];
				}
			}
		}
				vracanje+=pomocni;
				vracanje+=' ';
				pomocni.clear();
	}
	
return vracanje;	
}

string IzmijeniUPigLatin(string a, vector<string> b){
	string pigilatin;
	string pomocni;
	string oprez;
	string pomoc;
	
	for(int i=0;i<b.size();i++){
		pomoc=b[i];
		
		for(int j=0;j<pomoc.size();j++){
		if(pomoc[j]<'A' || (pomoc[j]>'Z' && pomoc[j]<'a') || pomoc[j]>'z') throw domain_error("Izuzetak: Nekorektan izbor rijeci");}}
	
	
	if(b.size()==0){
		for(int i=0;i<a.size();i++){
			while(a[i]!='\0' && a[i]!=' '){
				pomocni.push_back(a[i]);
				i++;
			}
				pomocni.insert(pomocni.begin()+pomocni.size(), pomocni[0]);
				pomocni.erase(pomocni.begin());
				pomocni.insert(pomocni.begin()+pomocni.size(), 'y');
				pomocni.insert(pomocni.begin()+pomocni.size()-1, 'a');
				pigilatin+=pomocni;
				pigilatin+=' ';
				pomocni.clear();
		}
	return pigilatin;	
	}
	
	
		for(int i=0;i<a.size();i++){
		while(a[i]!='\0' && a[i]!=' '){
			pomocni.push_back(a[i]);
			i++;
		}

			for(int j=0;j<b.size();j++){
			if(pomocni==b[j]){
				oprez=b[j];
			    pomocni.insert(pomocni.begin()+pomocni.size(), oprez[0]);
				pomocni.erase(pomocni.begin());
				pomocni.insert(pomocni.begin()+pomocni.size(), 'y');
				pomocni.insert(pomocni.begin()+pomocni.size()-1, 'a');
				}
			}
		
				pigilatin+=pomocni;
				pigilatin+=' ';
				pomocni.clear();
	}
	
	
	return pigilatin;
}


int main ()
{

	string h;
	string g;
	cout<<"Unesite recenicu: ";
	getline(cin,h);
	cout<<"Unesite fraze: ";
	vector<string> rijeci;
	
	do{
		getline(cin,g);
		
		rijeci.push_back(g);
	}while(cin.peek()!= '\n');
	
	
	string transformacione;
	try{
	transformacione=IzmijeniUPigLatin(h,rijeci);
	cout<<"Recenica nakon PigLatin transformacije: "<< transformacione<<endl;}
    catch(domain_error izuzetak){ cout<<izuzetak.what()<<endl;}
	string fraze;
	fraze=ObrniFraze(h,rijeci);
	cout<<"Recenica nakon obrtanja fraza: "<<fraze <<endl;

	return 0;
}