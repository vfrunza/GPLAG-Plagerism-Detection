/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using std::vector;
using std::cin;
using std::cout;
using std::string;
string ObrniFraze(string a,vector<string> b){
	string recenica;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.size();j++){
		if(a[i]==b[j][0]){
			int t=i;
			int k(0);
			while(a[i]==b[j][k]){
				if(k+1==b[j].size()) break;
				i++;
				k++;
			}
			if(k==b[j].size()-1  && a[i]==b[j][k]){
				for(int p=i;p>=t;p--){
					recenica.push_back(a[p]);
				}
								if(i+1==a.length()) return recenica;	i++;}
				else {i=t;}
		}}
		recenica.push_back(a[i]);
		if(i+1==a.length()) break;
	}
	return recenica;
}
string IzmijeniUPigLatin(string a,vector<string> b){
	string recenica;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.size();j++){
		if(a[i]==b[j][0]){
			int t=i;
			int k(0);
			while(a[i]==b[j][k]){
						if(b[j][k]<'A' || b[j][k]>'z' || (b[j][k]>'Z' && b[j][k]<'a')) throw std::domain_error("Nekorektan izbor rijeci");
				if(k+1==b[j].size()) break;
				i++;
				k++;
			}
			if(k==b[j].size()-1 && a[i]==b[j][k]){
				for(int p=t+1;p<=i;p++){
					recenica.push_back(a[p]);
				}
				recenica.push_back(a[t]);
				recenica.push_back('a');
				recenica.push_back('y');
					if(i+1==a.length()) return recenica;
i++;}
				else{ i=t;}
		}}
		recenica.push_back(a[i]);
		if(i+1==a.length()) break;
	}
	return recenica;
}
int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
    getline(cin,recenica);
    string fraza;
    vector<string> a;
    cout<<"Unesite fraze: ";
    do{
    	getline(cin,fraza);
    	if(fraza.size()==0) break;
        a.push_back(fraza);
    }while(1);
        	try{
    string pig=IzmijeniUPigLatin(recenica,a);
    cout<<"Recenica nakon PigLatin transformacije: ";
    cout<<pig;}
        catch(std::domain_error izuzetak){cout<<"Izuzetak: "<<izuzetak.what();
        }
                string obrni=ObrniFraze(recenica,a);
    cout<<"\nRecenica nakon obrtanja fraza: ";
    cout<<obrni;
	return 0;
}