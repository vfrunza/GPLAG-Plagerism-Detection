#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;


bool ispravanSpisakRijeci(vector<string> rijeci){
	for(string rijec:rijeci){
		for(char slovo:rijec){
			if(! ( (slovo>='a'&&slovo<='z') || (slovo>='A'&&slovo<='Z') || slovo==' ') ) return false;
		}
	}
	return true;
}


void izvrniString(string& s){
	
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		char temp = s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}
string ObrniFraze(string  recenica, vector<string> rijeciFraze){
	if(!ispravanSpisakRijeci(rijeciFraze)) throw domain_error("Nekorektan izbor rijeci");
	
	
	for(string rijec : rijeciFraze){
		for(int i=0;i<=int(recenica.size())-int(rijec.size());i++){
			string podString = recenica.substr(i,rijec.size());
			
			if(podString==rijec){
				izvrniString(podString);
				for(int j=i,k=0; j<i+rijec.size();j++,k++){
					recenica[j]=podString[k];
				}
			}
		}
		
	}
	
	return recenica;
}

void UPigLatin(string&s){
  string pom="ay";
	s= s.substr(1,s.size()-1)+s.substr(0,1) +pom;
}

string IzmijeniUPigLatin(string  recenica, vector<string> rijeciFraze){
	if(!ispravanSpisakRijeci(rijeciFraze)) throw domain_error("Nekorektan izbor rijeci");

	
	for(string rijec : rijeciFraze){
		for(int i=0;i<=int(recenica.size())-int(rijec.size());i++){
			string podString = recenica.substr(i,rijec.size());
			
			if(podString==rijec){
				UPigLatin(podString);
				recenica.resize(recenica.size()+2);
				for(int t=recenica.size()-1;t>=i+2;t--){
					recenica[t]=recenica[t-2];
				}
				for(int j=i,k=0; j<i+podString.size();j++,k++){
					recenica[j]=podString[k];
				}
			}
		}
		
	}
	
	return recenica;
}

int main ()
{
	string recenica;
	cout<<"Unesite recenicu: ";
	
	getline(cin,recenica);

	vector<string> rijeciFraze;
	string pomocnaRijecFraza;
		cout<<"Unesite fraze: ";
	do{
	
		getline(cin,pomocnaRijecFraza);
		if(pomocnaRijecFraza == "") break;
		rijeciFraze.push_back(pomocnaRijecFraza);
	}while(true);
	
	
	try{
		cout<<"Recenica nakon PigLatin transformacije: ";
		string modPigLatin = IzmijeniUPigLatin(recenica,rijeciFraze);
		cout<<modPigLatin<<endl;
	}catch(domain_error e){
		cout<<e.what()<<endl;
	}
	
	
	try{
		string modRec =  ObrniFraze(recenica,rijeciFraze);
		
		cout<<"Recenica nakon obrtanja fraza: ";
		cout<<modRec<<endl;
	}catch(domain_error e){
		cout<<e.what()<<endl;
	}
	
	
	
	return 0;
}