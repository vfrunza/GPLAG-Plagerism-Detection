#include <iostream>
#include <string>
#include <vector>
typedef std::vector<std::string> Vektor_Stringova;
bool NeSlovo(char c){
	if(c>='A' && c<='Z') return false;
	if(c>='a' && c<='z') return false;
	return true;
}
std::string NapraviPalindrom(std::string recenica, Vektor_Stringova fraze)
{
	std::string rec(recenica);
	for(int i=0; i<fraze.size(); i++) {
		int k(0);
		while(k<rec.length()) {
			if(rec.at(k)==fraze.at(i).at(0)) {
				int j(0);
				
				while(k<rec.length() && j<fraze.at(i).length()) {
					if(rec.at(k)!=fraze.at(i).at(j)) break;
					j++;
					k++;
				}
				//fazon sa insertom pokusati
				if(fraze.at(i).length()==j && (k==rec.length() || NeSlovo(rec.at(k)))) {
					int l(0);
					while(l<fraze.at(i).length()) {
						rec.insert(rec.begin()+k, fraze.at(i).at(l));
						l++;
					}
				}
			}
			k++;
		}
	}
	return rec;

}
std::string NapraviPoluPalindrom (std::string recenica, Vektor_Stringova fraze){
	std::string rec(recenica);
	for(int i=0; i<fraze.size(); i++) {
		int k(0);
		while(k<rec.length()) {
			if(rec.at(k)==fraze.at(i).at(0)) {
				int j(0);
				int pocetak(k);
				while(k<rec.length() && j<fraze.at(i).length()) {
					if(rec.at(k)!=fraze.at(i).at(j)) break;
					j++;
					k++;
				}
				int pozicija((k-pocetak)/2);
				if(fraze.at(i).length()%2==1) {
					pozicija++;
					
				}
				//fazon sa insertom pokusati
				if(fraze.at(i).length()==j && (k==rec.length() || NeSlovo(rec.at(k)))) {
					int l(fraze.at(i).length()-1-pozicija);
					
					while(l>=0) {
						rec[k-l-1]=fraze.at(i).at(l);
						l--;
					}
				}
			}
			k++;
		}
	}
	return rec;
}
int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	Vektor_Stringova fraze;
	std::string pomoc;
	do {

		std::getline(std::cin, pomoc);
		if(pomoc.length()>0) {
			fraze.push_back(pomoc);
		}
	} while(pomoc.length()>0);
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << NapraviPalindrom(s, fraze)<< std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::cout << NapraviPoluPalindrom(s, fraze);
	return 0;
}