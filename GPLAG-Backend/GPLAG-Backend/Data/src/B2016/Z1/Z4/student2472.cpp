/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>

std::string IzmijeniSveRijeci(std::string s){
	int pocetak, kraj;
	for(int i=0;i<s.length();i++){
		while(s[i]==' ' && i<s.length())i++;
		pocetak=i;
		while(s[i]!=' ' && i<s.length())i++;
		kraj=i;
		{			
				s.resize(s.length()+2);
				char poc(s[pocetak]);
				//brisanje prvog slova
					for(int k=pocetak;k<kraj;k++)
						s[k]=s[k+1];
						
				//prebacivanje prvog na kraj
					s[kraj-1]=poc;
					
					for(int k=s.length()-1;k>kraj;k--){
						s[k]=s[k-2];
					}
					s[kraj]='a';
					s[kraj+1]='y';
					i+=2;
		}
	}
	
	return s;
}


typedef std::vector<std::string> vektor;

std::string IzmijeniUPigLatin(std::string s, vektor fraze){
	using std::string;
	int slovo,setajuci;
	
	if(fraze.size()==0) return IzmijeniSveRijeci(s);
	
	for(int i=0;i<fraze.size();i++){
		string fraza;
		fraza=fraze[i];
		int kraj(fraza.length());
		
		for(int i=0;i<fraza.length();i++)
			if(fraza[i]<'A' || fraza[i]>'z' || (fraza[i]>'Z' && fraza[i]<'a') || fraza[i]==' ')
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		
		//potraga za frazom:\|/
		for(int j=0;j<s.length();j++){
			slovo=0;
			if(s[j]==fraza[0]){
			 slovo=0;
			 setajuci=j;
				while(setajuci<s.length() && slovo<fraza.length() && s[setajuci]==fraza[slovo]){
					slovo++;
					setajuci++;
				}
			}

				if(slovo==kraj && (/*s[j-1]==s[0] ||*/ j==0 || (s[j-1]<'A' || s[j-1]>'z' || (s[j-1]>'Z'&&s[j-1]<'a'))) && ((s[j+fraza.length()]<'A' || s[j+fraza.length()]>'z' || (s[j+fraza.length()]>'Z'&&s[j+fraza.length()]<'a')) || s[j+fraza.length()]==s[s.length()-1])){
				s.resize(s.length()+2);
				
				//brisanje prvog slova
					for(int k=j;k<fraza.length()+j-1;k++)
						s[k]=s[k+1];
						
				//prebacivanje prvog na kraj
					s[fraza.length()+j-1]=fraza[0];
					for(int k=s.length()-1;k>j+fraza.length();k--){
						s[k]=s[k-2];
					}
					s[fraza.length()+j]='a';
					s[fraza.length()+j+1]='y';
					j+=fraza.length();
				}
			}
		}
		

	return s;
}

std::string ObrniFraze(std::string s, vektor fraze){
	using std::string;
	int slovo,setajuci;
	
	for(int i=0;i<fraze.size();i++){
		string fraza;
		fraza=fraze[i];
		int kraj(fraza.length());
	
		//potraga za frazom:\|/
		for(int j=0;j<s.length();j++){
			slovo=0;
			if(s[j]==fraza[0]){
			 slovo=0;
			 setajuci=j;
				while(setajuci<s.length() && slovo<fraza.length() && s[setajuci]==fraza[slovo]){
					slovo++;
					setajuci++;
				}
			}

				if(slovo==kraj){
					//obrtanje fraze u stringu tek sada
					char temp;
					setajuci=kraj-1;
					for(int k=j;k<j+(kraj/2);k++){
						temp = s[k];
						s[k] = s[j+setajuci];
						s[j+setajuci] = temp;
						setajuci--;
					}
				}
			}
		}
		

	return s;
}

int main ()
{
	vektor v;
	std::string s; 
	std::string f;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	do{
	std::getline(std::cin, f);
	if(f.length()!=0)v.push_back(f);
	}while(f.length()!=0);
	try{
		std::string pomocni;
		pomocni=IzmijeniUPigLatin(s,v);
	std::cout << "Recenica nakon PigLatin transformacije: ";
	std::cout << pomocni;
	}catch(std::domain_error cigla){
	std::cout << cigla.what(); 
	}
	std::cout << "\nRecenica nakon obrtanja fraza: ";
	std::cout << ObrniFraze(s,v);
	
	return 0;
}