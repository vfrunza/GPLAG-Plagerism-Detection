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
using std::cin;
using std::cout;
using std::endl;

std::string Obrnuto(std::string s){
	std::string obrnuti;
	for(int i=s.length()-1; i>=0; i--){
		obrnuti.push_back(s[i]);
	}
	obrnuti.push_back(' ');
	return obrnuti;
}
std::string ObrniFraze(std::string s, std::vector<std::string> v){
	std::string rijec;
	for (int i=0; i<v.size(); i++){
		rijec=v[i];
		for (int j=0; j<s.length()+1; j++){
			if (s[j]==rijec[0]){
				int b=j;
				int k=0;
				while(k<rijec.length() && s[j]==rijec[k]){
					j++;
					k++;
				}
				if(k==rijec.length() && !((s[b-1]>='a'&&s[b-1]<='z') || (s[b-1]>='A'&&s[b-1]<='Z'))  && !((s[b+1]>='a'&&s[b+1]<='z') || (s[b+1]>='A'&&s[b+1]<='Z'))   ) {
					std::string obrnuti=Obrnuto(rijec);
					int l(0);
					while (l<k+1){
						s[b]=obrnuti[l];
						b++;
						l++;
					}
			//j=j-1;
				}
			}
		}
	}
return s;
}
std::string PigLatin(std::string rijec){
	std::string pgltn;
	for (int i=1; i<rijec.length(); i++){
		pgltn.push_back(rijec[i]);
	}
	pgltn.push_back(rijec[0]);
	return pgltn;
}
std::string IzmijeniUPigLAtin(std::string s, std::vector<std::string> v){
	std::string rijec;

	for (int i=0; i<v.size(); i++){
		rijec=v[i];
		for (int j=0; j<s.length(); j++){
			if (s[j]==rijec[0]){
				int b=j;
				int k=0;
				while(k<rijec.length() && s[j]==rijec[k]){
					j++;
					k++;
				}
				if(k==rijec.length() && !((s[b-1]>='a'&&s[b-1]<='z') || (s[b-1]>='A'&&s[b-1]<='Z'))  && !((s[b+1]>='a'&&s[b+1]<='z') || (s[b+1]>='A'&&s[b+1]<='Z'))   ) {
					std::string pgltn=PigLatin(rijec);
					int l=0;
					while (l<k){
						s[b]=pgltn[l];
						b++;
						l++;
					}
					s.insert(s.begin() + b, 'a');
					s.insert(s.begin() + b+1, 'y');
				j=b-1;
				}
			}	
			
		
		}
	}
	return s;
}
int main ()
{
try{	
	std::string s;
	cout<<"Unesite recenicu: ";
	std::getline(cin, s);
	std::vector<std::string> v;
	//std::cin.ignore(10000, '\n');
	cout<<"Unesite fraze: ";
	for (;;){
		std::string nesto;
		std::getline(cin, nesto);
		if (nesto.length()==0) break;
		for(int i=0; i<nesto.length(); i++){
		if(!((nesto[i]>='A' && nesto[i]<='Z') || (nesto[i]>='a' && nesto[i]<='z')))
		throw std::domain_error("Nekorektan izbor rijeci");
		}
		v.push_back(nesto);
	}
	
	std::string pgltn=IzmijeniUPigLAtin(s, v);
	cout<<"Recenica nakon PigLatin transformacije: "<<pgltn<<endl;
	std::string obrt=ObrniFraze(s,v);
	cout<<"Recenica nakon obrtanja fraza: "<<obrt<<endl;
}
catch(std::domain_error x){
	cout<<x.what();
}
	return 0;
}