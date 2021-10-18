#include <iostream>
#include <string>
#include <vector>

int DaLiImaPodstring(std::string s, std::string vs)
{
	
	for(int i=0; i<s.length(); i++) {
		if((s[i]==vs[0] && i!=0 && s[i-1]==' ') ||(i==0 && s[i]==vs[0])) {
			for(int j=0; j<vs.length(); j++) {
				if(s[i]!=vs[j])
					break;
				
				i++;
				if(j==vs.length()-1 && i==s.length()){
				
				
					return i;}
				if(j==vs.length()-1 &&  s[i]==' ' ){
					return i;
				}
				if(j==vs.length()-1 &&  (s[i]<'A' || (s[i]>'Z'&& s[i]<'a') || s[i]>'z') ){
					return i;
				}
				
			
			}
		}
	}
	return -1;
}
int KolikoSePutaPOnavlja(std::string s, std:: string vs, int index)
{

	for(int i=index; i<s.length(); i++) {
		if((s[i]==vs[0] && i!=0 && s[i-1]==' ') ||(i==0 && s[i]==vs[0])) {
			for(int j=0; j<vs.length(); j++) {
				if(s[i]!=vs[j])
					break;
				i++;
				if(j==vs.length()-1 && i==s.length()){
				
				
					return 1;}
				if(j==vs.length()-1 &&  s[i]==' ' ){
					return 1;
				}
				if(j==vs.length()-1 &&  (s[i]<'A' || (s[i]>'Z'&& s[i]<'a') || s[i]>'z') ){
					return 1;
				}
			}
		}
	}
	return 0;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> vs)
{
	for(int i=0; i<vs.size(); i++) {
		int pon=0;
		int dal=DaLiImaPodstring(s,vs[i]);
		if(KolikoSePutaPOnavlja(s,vs[i],dal))
			pon=1;//vraca index i od s[i] koji je znak na kraju rijeci koja se poklapa,tj na prvi razmak poslije stringa ne prije, ako nema poklapanja vraca -1
		if(dal>-1) {
			int k=s.length()-1; // k je zadnji index s stringa
			int duzina=s.length()+vs[i].length();
			s.resize(duzina);
			int j=s.length()-1; // j je zadji index prosirenog s stringa za duzinu stringa vs

			for(j=s.length()-1; j>dal; j-- ) {
				s[j]=s[k];
				k--;
			} // j==dal sada
			for(int k=vs[i].size()-1; k>=0; k--) {
				s[j]=vs[i][k];
				j++;
			}
		}
		if(pon==1)
			i--; //Ako se ovaj string ponavlja ponovoga ispitujemo sa narednim
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> vs)
{
	for(int i=0; i<vs.size(); i++) {
		int pon=0;
		int dal=DaLiImaPodstring(s,vs[i]);
		if(KolikoSePutaPOnavlja(s,vs[i],dal))
			pon=1;
		if(dal>=0) {
			int duzina=vs[i].length();
			int poc=dal-duzina; //poc je pocetak fraze u stringu s, a dal je zadnji znak fraze u tom stringu
			dal--;
			while(poc<dal) {
				s[dal]=s[poc];
				poc++;
				dal--;
			}
		}
		if(pon==1)
			i--;
	}
	return s;
}

int main ()
{
	std::string recenica,nova,nova2,nekistring;
	std::cout<< "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector <std::string> fraze;
	bool pamti(false);
	while(std::getline(std::cin, nekistring)) {
		if(std::cin.peek()=='\n')
			pamti=true;
		fraze.push_back(nekistring);
		if(pamti)
			break;
	}

	nova=NapraviPalindrom(recenica,fraze);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<nova;
	nova2=NapraviPoluPalindrom(recenica,fraze);
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<nova2;
return 0;

}