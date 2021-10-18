#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int Rijec_trazi(const std::string &T, const std::string &P,int i = 0)
{
    int n = T.length();
    int m = P.length();

    for (; i <= n-m; ++i) {
        int j = 0;
        while (j < m && T[i+j] == P[j]) {
            ++j;
        }
        if (j == m) {

            return i;
        }
    }
    return -1;
}

int Rijec_trazi2(const std::string &s, const std::string &rijec)
{
    int duz_str = s.length();
    int duz_rj = rijec.length();

	int k(0);
	int j(0);
    for (int i = 0; i < duz_str; i++) {
    	k = i;
		j = 0;
		while (j < duz_rj && k < duz_str && rijec[j] == s[k]) {
			k++;
			j++;
		}
		if (j == duz_rj && (i == 0 || !((s[i-1] >= 'A' && s[i-1] <= 'Z')||(s[i-1] >= 'a' && s[i-1] <= 'z'))) && (k == duz_str || !((s[k] >= 'A' && s[k] <= 'Z')||(s[k] >= 'a' && s[k] <= 'z'))))
			return i;
    }
    return -1;
}

bool ima_li_ne_slova (std::string s)
{

    for (auto i : s) {
        if (!(( i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z' ))) {
            return true;
        }
    }
    return false;
}

std::string ObrniFraze (std::string s, std::vector<std::string> rijeci)
{
	if (rijeci.empty()) return s;
    int t(0);
    int k(0);
    for (int i = 0; i < rijeci.size(); i++) {

        if (Rijec_trazi(s,rijeci[i]) != -1) {
            k = 0;
            while (Rijec_trazi(s,rijeci[i],k) != -1) {
                t = Rijec_trazi(s,rijeci[i]); // provjeravamo da li se nalazi i vracamo poziciju

                for (int j = rijeci[i].length()-1; j >= 0 ; j--) {
                    s[t] = rijeci[i][j];
                    t++;
                }
                k++;
            }
        }
    }
    return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> rijeci)
{
    if (rijeci.empty()) {
        int pocetak(0);

        for (int i = 0; i < s.size(); i++) {
            pocetak = i;
            if ((( s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z' ))) {
                while (i < s.size() and (( s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z' ))) {
                    i++;
                }
                s.insert(s.begin() + i, s[pocetak]);
                s.insert(s.begin() + i+1, 'a');
                s.insert(s.begin() + i+2, 'y');
                s.erase(s.begin()+pocetak);
				i+=2;
            }//anasDay ejay ijeplay anday
               
        }
    }
    else {
        int t(0);

        for (int i = 0; i < rijeci.size(); i++) {
            if (ima_li_ne_slova(rijeci[i]) == true) { throw std::domain_error("Nekorektan izbor rijeci"); }
            if (Rijec_trazi2(s,rijeci[i]) != -1) {

                while (Rijec_trazi2(s,rijeci[i]) != -1) {
                    t = Rijec_trazi2(s,rijeci[i]); // provjeravamo da li se nalazi i vracamo poziciju
                    s.insert(s.begin() + t + rijeci[i].size(), s[t]);
                    s.insert(s.begin() + t + rijeci[i].size()+1, 'a');
                    s.insert(s.begin() + t + rijeci[i].size()+2, 'y');
                    s.erase(s.begin()+t);

                }
            }
        }
    }
    return s;
}

int main()
{


    std::string recenica {};
    std::vector<std::string> rijeci {};

    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);

    std::cout << "Unesite fraze: ";

    std::string rijec{""};

    while(1){
      std::getline(std::cin,rijec);
      if(rijec.empty())break;
      rijeci.push_back(rijec);

	}
	try {
    std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,rijeci) <<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica,rijeci);
    return 0;
}
