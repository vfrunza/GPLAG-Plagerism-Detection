#include <iostream>
#include <string>
#include <cctype>
#include <vector>

typedef std::string string;

int NadjiRijec(string s1, string s2, int a) {
	for(int i=a; i<s1.size()-1; i++) {
		int j=0;
		if(s1.at(i)==s2.at(j)){
			j++;
		}
		if(j==s2.size()-1){
			if((s1.at(i+1)>='A' && s1.at(i+1)<='Z')) continue;
			if((s1.at(i+1)>='a' && s1.at(i+1)<='z')) continue;
		}
		return i+1;
	}
		return -1;	//vracamo vrijednost koja ce nam oznaciti kraj provjere stringa za odredjenu rijec
}

string ObrniRijec(string s1) {	//fukncija za obrtanje rijeci
	string s2;
	for(int i=s1.size()-1; i>=0; i--) {
		s2.push_back(s1.at(i));
	}
	return s2;
	
}

string NapraviPalindrom(string s1, std::vector<string> s2) {
	string s3,s4,s5;
	for(auto x: s2) {	//petlja kojom citamo rijeci iz vektora stringova sa rijecima
		int a=0;	//promjenljiva koja nam cuva indeks dijela stringa u kojeg upisujemo novu rijec
		while(true) {	//beskonacna while petlja koju prisilno prekidamo fukncijom brake
			a=NadjiRijec(s1,x,a);	//promjenljiva a nam postaje indeks elementa poslije kojeg trebamo upisati rijeci
			if(a<0) break;	//prisilno prekidanje beskonacne while petlje ako nam fukncija vrati -1
			s3=s1.substr(0,a);	//string koji cuva dio pocetnog stringa 
			s4=ObrniRijec(x);	//string u koji pohranjujemo obrnutu rijec
			s5=s1.substr(a,s1.size());	//string koji nam cuva ostatak stringa (tj. string poslije indeksa)
			s1=s3+s4+s5;	//sklapamo sve indekse u jedan
		}
	}


	return s1;

}


int main () {
	string s;
	std::vector<string> s1;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	for(;;) {
		string s3;	//deklarisemo novu promjenljivu u koju upisujemo rijeci sa ulaznog toga
		if(std::cin.peek()=='\n') break;	//ukoliko je na ulaznom toku samo \n prisilno izadji iz petlje
		std::getline(std::cin,s3);	//ucitavamo fraze sa ulaznog toga (svaki put pri pritisku entera se definise nova fraza)
		s1.push_back(s3);	//nove rijeci ubacujemo u string s1
		if(std::cin.peek()=='\n') break;	//ukoliko je sljedeci znak na ulaznom toku '\n' prisilno prekini petlju
	}
	s=NapraviPalindrom(s,s1); 
	std::cout<<"Recenica nakon Palindrom transformacije: "<<s;
	return 0;
}