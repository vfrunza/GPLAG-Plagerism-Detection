/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>

using std::string;

// PROTOTIPI funkcija
// Pomocne funkcije
bool isLetter(char);
string reverseString(string);

// Funkcije zadate za implementaciju
string NapraviPalindrom(string, std::vector<string>);
string NapraviPoluPalindrom(string, std::vector<string>);

int main ()
{
	string sentence;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, sentence);
	
	std::vector<string> vect;
	std::cout << "Unesite fraze: ";
	do {
		string tmpUnos;
		std::getline(std::cin, tmpUnos);
		
		if (tmpUnos == "")
			break;
			
		vect.push_back(tmpUnos);
	}
	while(true);
	
	std::cout << "Recenica nakon Palindrom transformacije: "
		<< NapraviPalindrom(sentence, vect) << std::endl;
	
	std::cout << "Recenica nakon PoluPalindrom transformacije: "
		<< NapraviPoluPalindrom(sentence, vect) << std::endl;
	
	return 0;
}

string NapraviPalindrom(string sentence, std::vector<string> phrases)
{
	for (auto phrase : phrases)
	{
		for (int i{0};
			 i <= static_cast<int>(sentence.length()) - static_cast<int>(phrase.length());
			 i++)
		{
			int j{0};
			
			// Ne mozemo mijenjati usred rijeci
			if (i > 0 && isLetter(sentence.at(i - 1)))
				continue;
			
			while (j < phrase.length() && sentence.at(i + j) == phrase.at(j))
				j++;
			
			// Ako nismo dosli do kraja rijeci, u sredini smo rijeci,
			// a dosli smo do kraja fraze, nista se ne treba desiti, nije to to
			if (i + j < sentence.length() && isLetter(sentence.at(i + j)))
				continue;
			
			// Ako smo dosli do kraja fraze, i nalazimo se na kraju rijeci, ubaci obrnuti string
			if (j == phrase.length())
			{
				sentence.insert(i + j, reverseString(phrase));
				i += 2 * phrase.length();
			}
		}
	}
	
	return sentence;
}

// Funkcija je vecinom implementirana kao i NapraviPalindrom
// Objasnjenja ce biti tamo gdje se razlikuje od iste
string NapraviPoluPalindrom(string sentence, std::vector<string> phrases)
{
	for (auto phrase : phrases)
	{
		for (int i{0};
			 i <= static_cast<int>(sentence.length()) - static_cast<int>(phrase.length());
			 i++)
		{
			int j{0};
			
			if (i > 0 && isLetter(sentence.at(i - 1)))
				continue;
			
			while (j < phrase.length() && sentence.at(i + j) == phrase.at(j))
				j++;
			
			if (i + j < sentence.length() && isLetter(sentence.at(i + j)))
				continue;
			
			if (j == phrase.length()) 
			{
				// Idi do polovine rijeci i mijenjaj svako slovo u recenici za
				// nasuprotnim slovom u frazi
				while (j-- > phrase.length() / 2)
					sentence.at(i + j) = phrase.at(phrase.length() - 1 - j);
				
				i += phrase.length();
			}
		}
	}
	
	return sentence;
}

// Funkcija vraca string obrnut
string reverseString(string str)
{
	string res{""};
	
	for (int i{static_cast<int>(str.length() - 1)}; i >= 0; i--)
		res += str.at(i);
		
	return res;
}

// Funkcija vraca true ukoliko je parametar slovo,
// a false u suprotnom
bool isLetter(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}