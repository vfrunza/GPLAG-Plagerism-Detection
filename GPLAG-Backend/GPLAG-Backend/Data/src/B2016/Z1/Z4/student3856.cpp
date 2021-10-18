/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
string ObrniRijec(string s)
{
	string h;
	for(int i=s.size()-1; i>=0; i--)
	{
		h+=s[i];
	}
	return h;
}

string ObrniFraze(string s, vector<string> v)
{
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<v.size(); j++){
			
			for(int k=0; k<v[j].size(); k++){
				if(v[j][k]==s[i] && k==0){
				
					int pocetak=i;
					string pom;
					while(v[j][k]==s[pocetak] && pocetak!=s.size()-1 && k!=v[j].size()-1){
						pom+=s[pocetak];
						pocetak++;
						k++;
					}
					pom+=v[j][k];
					
					pocetak=i;
					if(k==v[j].size()-1)
					{
						pom=ObrniRijec(pom);
						for(int h=0; h<pom.size(); h++)
						{
							s[pocetak]=pom[h];
							pocetak++;
						}
						i=pocetak;
					}
				}
			}
		}
	}
	return s;
}

string PrebaciRijecUPig(string s)
{
	s=s.substr(1,s.size()-1)+s.substr(0,1)+'a'+'y';
	return s;
}
string IzmijeniUPigLatin(string s, vector<string> v)
{
	//Provjera da li vektor stringova sadrzi samo slova
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z')) throw domain_error("Nekorektan izbor riječi");
		}
	}
	//Ako je prazan vektor treba sve da izmijeni
	if(v.size()==0){
		int pocetak, duzina;
		string pom;
		for(int i=0;i<s.size();i++){
			if(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && (i==0 || s[i-1]==' ')){
				pocetak=i;
				duzina=1;
				while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
					i++;
					duzina++;
				}
				
				pom=s.substr(pocetak,duzina-1); 
				pom=PrebaciRijecUPig(pom);
				string prvi_dio=s.substr(0,pocetak);
				string drugi_dio=s.substr(i,s.size()-1);
				
				s=prvi_dio+pom+drugi_dio;
				
			}
		}
	}
	else{
		/*for(int i=0; i<s.size(); i++){
			
			for(int j=0; j<v.size(); j++){
			
				
				for(int k=0; k<v[j].size(); k++){
					
					if(v[j][k]==s[i] && k==0){
						
						int pocetak=i,kraj;
						string pom;
						while(v[j][k]==s[pocetak] && pocetak!=s.size()-1 && k!=v[j].size()-1)
						{
							pom+=s[pocetak];
							pocetak++;
							k++;
						}
						pom+=v[j][k];
						pocetak=i;
						kraj=pocetak;
						if(k==v[j].size()-1)
						{
							
							string pomocni=PrebaciRijecUPig(v[j]);
							string drugi_dio=s.substr(i+v[j].size(),s.size()-i-v[j].size()-1);
							string prvi_dio=s.substr(0,i);
							s=prvi_dio+pomocni+drugi_dio;
							i=kraj;
						}
					}
					
					
				}
			}
		}*/
		
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				for(int k=0;k<s.size();k++){
					
					if(s[k]==v[i][j]){
						cout<<"---"<<s[k]<<endl;
						int pocetak=k;
						
						while(s[pocetak]==v[i][j] && pocetak<s.size() && j<v[i].size()){
							pocetak++;
							j++;
							cout<<"!---"<<s[pocetak]<<endl;
							
						}
						//cout<<"Ovo je to sto pise --"<<s.substr(k,pocetak-k)<<endl;
						string dio=s.substr(k,pocetak-k);
						//cout<<"Ovo je v[i] -- "<<v[i]<<"  Ovo je  --"<<s.substr(k,pocetak-k+1)<<" a ostatak stringa je --"<<s.substr(k,s.size()-k)<<endl;
						if(dio==v[i] && (k==0 || s[k-1]==' ') && (pocetak==s.size()-1 || s[pocetak]==' ')){
							if(pocetak<s.size()-1){
								string prvi_dio=s.substr(0,k);
								string drugi_dio=s.substr(pocetak,s.size()-pocetak);
								string rijec=PrebaciRijecUPig(v[i]);
							
								s=prvi_dio+rijec+drugi_dio;
									//cout<<" za v[i] --"<<v[i]<< "-- uslo gdje treba i prvi_dio je --"<<prvi_dio<< "-- a drugi dio je --"<<drugi_dio<<"-- a rijec obrnuta je -- "<<rijec<< "-- a s je --"<< s<<endl;
							}
							else{
								string prvi_dio=s.substr(0,k-1);
								string rijec=PrebaciRijecUPig(v[i]);
								s=prvi_dio+rijec;
								
							}
						}
						/*if(j==v[i].size()-1 ){
							
							
							if(pocetak<s.size()-1){
								string prvi_dio=s.substr(0,k);
								string drugi_dio=s.substr(pocetak+1,s.size()-1-pocetak);
								string rijec=PrebaciRijecUPig(v[i]);
							
								s=prvi_dio+rijec+drugi_dio;
									cout<<" za v[i] --"<<v[i]<< "-- uslo gdje treba i prvi_dio je --"<<prvi_dio<< "-- a drugi dio je --"<<drugi_dio<<"-- a rijec obrnuta je -- "<<rijec<< "-- a s je --"<< s<<endl;
							}
							else{
								string prvi_dio=s.substr(0,k-1);
								string rijec=PrebaciRijecUPig(v[i]);
								s=prvi_dio+rijec;
								
							}
						}*/
						
					}
				}
			}
		}
	}
	return s;
}

int main ()
{
	/*string recenica;
	vector<string> fraze;
	try{
		cout<<"Unesite recenicu: ";
		getline(cin, recenica);
		cout<<"Unesite fraze: ";
		for(;;){
			string privremeni;
			getline(cin,privremeni); 
			if(privremeni=="") break;
			fraze.push_back(privremeni);
			
		}
		cout<<"Recenica nakon PigLatin transformacije: ";
		string pl=IzmijeniUPigLatin(recenica,fraze);
		cout<<pl<<endl;
	}
	catch(domain_error e){
		cout<<e.what()<<endl;
	}
	cout<<"Recenica nakon obrtanja fraza: ";
	string of=ObrniFraze(recenica,fraze);
	cout<<of;*/
	 try
    {
        std::string s{"Svaka elementarna funkcija je neprekidna gdje je definisana."};
        std::cout <<  ObrniFraze (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
        std::cout <<  IzmijeniUPigLatin (s, {"elementarna", "je", "gdje", "prekidna"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}