#include <iostream>
#include <string>
#include <vector>

std::string PalindromiSaPopisa (std::string s)  // Pravi palindrome od rijeci sa liste
{
	std::string vrati;
	for (int i = s.length()-1; i>=0; i--)
		vrati.push_back(s.at(i));
	return s+vrati;
}  // Pravi palindrome od rijeci sa liste

std::string PolupalindromiSaPopisa (std::string s)
{
	std::string vrati,pomocni;
	int i;
	for (i = 0; i<s.length()/2; i++) {
		vrati.push_back(s.at(i));
		pomocni.push_back(s.at(i));
	}
	if (s.length()%2==1)
		pomocni.push_back(s.at(i));
	for (int i= (pomocni.length()-1); i>=0; i--)
		vrati.push_back(pomocni.at(i));
	return vrati;
} // Pravi polupalindrome od rijeci sa liste

// Vjerovatno je moglo jednostavnije ali sam bas iskomplikovao :)
std::string NapraviPalindrom (std::string recenica, std::vector <std::string> lista)
{
	for (int i = 0; i< lista.size(); i++) {
		if (lista.at(i).length()==0)   // U slučaju da je neki od stringova vektora prazan on se preskače
			continue;
		for (int j=0; j< recenica.length(); j++) {
			std::string pomocni;      // Pomoćni string koji će provjeravati da li je neka riječ u rečenici jednaka riječi na listi
			int k(0),s(j);        // k- k-ato slovo rijeci na listi, s- s-to slovo unutar rečenice
			while (k<lista.at(i).length() && s<recenica.length() && lista.at(i).at(k)==recenica.at(s)) {
				pomocni.push_back(recenica.at(s));     // Pišem u pomoćni slova koja zadovoljavaju uvijet petlje
				s++;
				k++;
			}
			if (s<recenica.length() && ((recenica.at(s)>='a' && recenica.at(s)<='z') || (recenica.at(s)>='A' && recenica.at(s)<='Z'))) {  // Da ne bi bio slucajno samo dio rijeci vec cijela rijec
				while (s<recenica.length() && ((recenica.at(s)>='a' && recenica.at(s)<='z') || (recenica.at(s)>='A' && recenica.at(s)<='Z')))
				s++;
				j=s;
				continue;
			}
			// Uvijet if - 1. pomocni mora biti jednak trenutnoj rijeci na listi   2. u slučaju da je riječ na kraju rečenice provjerava se da li je zadnje slovo rečenice jedanko 
			// zadnjem slovu i-te rijeci sa liste i da li je s-to slovo u stvari kraj rečenice 3. znak poslije zadnjeg slova unutar rijeci koja zadovoljava pomocni mora biti razlicit
			// od nekog slova inace bi to bila rijec koja sadrži drugu rijec (npr. danas i dan)
			if (pomocni==lista.at(i) && ((recenica.at(s-1)==lista.at(i).at(lista.at(i).length()-1) && s==recenica.length()) || (!(recenica.at(s)>='a' && recenica.at(s)<='z') && !(recenica.at(s)>='A' && recenica.at(s)<='Z')))) {
				int r(0);
				while (pomocni.length()>r) {      // r ce biti duzina rijeci sa liste, zatim se brise onoliko slova koliko ima ta rijec slova
					recenica.erase(recenica.begin()+j);
					r++;
				}
				r=0;   // u ovom kontekstu r predstavlja duzinu palindroma i on se pomocu insert funkcije ubacuje unutar mjesta gdje se nalazila prvobitna rijec
				while (PalindromiSaPopisa(lista.at(i)).length()>r) {
					recenica.insert(recenica.begin()+j, PalindromiSaPopisa(lista.at(i)).at(r));
					r++;
				}
				j=s;
			}
		}
	}
	return recenica;
}

// U NapraviPoluPalindrom samo iskopirao NapraviPolindrom funkciju jer rade istu stvar tako da ne mislite da sam prepisao
// Svi komenatari u gornjoj funkciji važe i za donju funkciju
std::string NapraviPoluPalindrom (std::string recenica, std::vector <std::string> lista)
{
	for (int i = 0; i< lista.size(); i++) {
		if (lista.at(i).length()==0)
			continue;
		for (int j=0; j< recenica.length(); j++) {
			std::string pomocni;
			int k(0),s(j);
			while (k<lista.at(i).length() && s<recenica.length() && lista.at(i).at(k)==recenica.at(s)) {
				pomocni.push_back(recenica.at(s));
				s++;
				k++;
			}
			if (s<recenica.length() && ((recenica.at(s)>='a' && recenica.at(s)<='z') || (recenica.at(s)>='A' && recenica.at(s)<='Z'))) {
				while (s<recenica.length() && ((recenica.at(s)>='a' && recenica.at(s)<='z') || (recenica.at(s)>='A' && recenica.at(s)<='Z')))
				s++;
				j=s;
				continue;
			}
			if (pomocni==lista.at(i) && ((recenica.at(s-1)==lista.at(i).at(lista.at(i).length()-1) && s==recenica.length()) || (!(recenica.at(s)>='a' && recenica.at(s)<='z') && !(recenica.at(s)>='A' && recenica.at(s)<='Z')))) {
				int r(0);
				while (pomocni.length()>r) {
					recenica.erase(recenica.begin()+j);
					r++;
				}
				r=0;
				while (PolupalindromiSaPopisa(lista.at(i)).length()>r) {
					recenica.insert(recenica.begin()+j, PolupalindromiSaPopisa(lista.at(i)).at(r));
					r++;
				}
				j=s;
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout <<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> lista;
	std::cout<<"Unesite fraze: ";
	std::string s;
	do {
		std::getline (std::cin,s);
		lista.push_back(s);
		if (s.length()==0)
			s=" ";
	} while (s!=" ");
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,lista)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,lista);
	return 0;
}