#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
std::string Obrcem(std::string s) {
	char temp;
	for(int i=0; i<s.length()/2; i++) {
		temp=s[i];
		s[i]=s[s.length()-1-i];
		s[s.length()-1-i]=temp;}
		return s;
}
int prostor(std::string s) {
	int brojac(0);
	for(int i=0; i<s.size(); i++) brojac++;
	return brojac;
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
	std::string pomocni, prazni, rezultat;
	std::vector<int> krajevi;
	std::vector<std::string> reversed;
	std::string zamjena(recenica);
	for(int i=0; i<recenica.length(); i++) {
		for(int j=recenica.length()-1; j>=0; j--) {
			bool zaobrnut=false;
			pomocni=prazni;
			  int pocetak=i;
			for(int l=i; l<=j; l++) {
					pomocni.push_back(recenica[l]);	}
		 for(int k=0; k<fraze.size(); k++) {
				if(pomocni==fraze[k]) {zaobrnut=true; break;}
			} if(zaobrnut==true) {krajevi.push_back(pocetak); 
				reversed.push_back(Obrcem(pomocni));
			}
		}
	}
	for(int i=0; i<recenica.length(); i++) {
		for(int j=0; j<krajevi.size(); j++) {
			if(i==krajevi[j]) {rezultat=rezultat+reversed[j]; 
			i=i+prostor(reversed[j]); 
			break;}
		}
	rezultat.push_back(recenica[i]);
	} return rezultat;
}
std::string Modificiraj(std::string s) {
	char pomocna(s[0]);
	for(int i=0; i<s.length(); i++) {
		if(i!=s.length()-1) s[i]=s[i+1];
		else s[i]=pomocna;
	} s=s+"ay";
	return s;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci) {
	std::string rezultat;
	
		bool ispravanunos=true;
		for(int i=0; i<rijeci.size(); i++) {
			for(int j=0; j<rijeci[i].length(); j++) {
				if(rijeci[i][j]<'A' || (rijeci[i][j]>'Z' && rijeci[i][j]<'a') || rijeci[i][j]>'z') ispravanunos=false; break;
				if(rijeci[i][j]==' ') ispravanunos=false; break;
			} if(ispravanunos==false) break;
		} if(ispravanunos==false) throw std::domain_error("Nekorektan izbor rijeci");
	else{
	if(rijeci.size()>0) {
	std::string pomocni, prazni;
	std::vector<int> krajevi;
	std::vector<std::string> modificirani;
	std::string zamjena(recenica);
	for(int i=0; i<recenica.length(); i++) {
		for(int j=recenica.length()-1; j>=0; j--) {
			bool zamodificirat=false;
			pomocni=prazni;
			  int pocetak=i;
			for(int l=i; l<=j; l++) {
					pomocni.push_back(recenica[l]);	}
		 for(int k=0; k<rijeci.size(); k++) {
				if(pomocni==rijeci[k] && i==0) {zamodificirat=true; break;}
				else if(pomocni==rijeci[k] && i!=0) {
					if(recenica[pocetak-1]<'A' ||(recenica[pocetak-1]>'Z' && recenica[pocetak-1]<'a') || recenica[pocetak-1]>'z') {
						if(j==recenica.length()-1) {zamodificirat=true; break;}
						else if(j!=recenica.length()-1 && (recenica[j+1]<'A' ||(recenica[j+1]>'Z' && recenica[j+1]<'a') ||recenica[j+1]>'z')) {zamodificirat=true; break;}
					}
				}
			} if(zamodificirat==true) {krajevi.push_back(pocetak); 
			modificirani.push_back(Modificiraj(pomocni));
			}
		}
	}
	for(int i=0; i<recenica.length(); i++) {
		for(int j=0; j<krajevi.size(); j++) {
			if(i==krajevi[j]) {rezultat=rezultat+modificirani[j]; 
			i=i+prostor(modificirani[j])-2; 
			break;}
		} 
	rezultat.push_back(recenica[i]);
	}}
	else if(rijeci.size()==0) {
		std::vector<std::string> modified;
		std::string prazan, jednarijec;
		std::vector<int> jednaodgranica;
		for(int i=0; i<recenica.size(); i++) {
			if(i==0 && ((recenica[0]>='A' && recenica[0]<='Z') ||(recenica[0]>='a' && recenica[0]<='z'))) {
				int j=i;
				jednaodgranica.push_back(i);
				jednarijec=prazan;
				while((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z')) {
				 jednarijec.push_back(recenica[j]);
				 j++;
			} modified.push_back(Modificiraj(jednarijec));
		} else if(i!=0 && ((recenica[i-1]<'A' || (recenica[i]>'Z' && recenica[i]<'a') || recenica[i-1]>'z'))){
			int j=i;
				jednaodgranica.push_back(i);
				jednarijec=prazan;
				while((recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z')) {
				 jednarijec.push_back(recenica[j]);
				 j++;
			} modified.push_back(Modificiraj(jednarijec));
		}
	}
	for(int i=0; i<recenica.length(); i++) {
		for(int j=0; j<jednaodgranica.size(); j++) {
			if(i==jednaodgranica[j]) {
				rezultat=rezultat+modified[j];
				i=i+prostor(modified[j])-2;
				break;
			} rezultat.push_back(' ');
		}
	}
	} 
	return rezultat;  }
}
int main ()
{
	std::vector<std::string> popiszaobrnut;
	std::string recenica, fraza;
	cout<<"Unesite recenicu: ";
	std::getline(cin, recenica);
	cout<<"Unesite fraze: ";
	for(;;) {
		std::getline(cin, fraza);
		popiszaobrnut.push_back(fraza);
		if(fraza=="") break;
	}
	try{ std::string platin=IzmijeniUPigLatin(recenica, popiszaobrnut);
			cout<<"Recenica nakon PigLatin transformacije: "<<platin;}
	
	catch(std::domain_error e) {
		cout<<e.what();
	}
		std::string rezultatobrni=ObrniFraze(recenica, popiszaobrnut);
		cout<<"\nRecenica nakon obrtanja fraza: ";
		cout<<rezultatobrni;
		
	return 0;
}