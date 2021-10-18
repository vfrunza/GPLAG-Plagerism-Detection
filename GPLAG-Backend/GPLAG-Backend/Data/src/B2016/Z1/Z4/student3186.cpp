/*B 2016/2017, Zadaća 1, Zadatak 4 */
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze)
{
    for (int i=0; i<fraze.size(); ++i) {
        
        for (int j=0; j<recenica.length(); ++j) {
            
            int x(0), y(j);
            while ((x < fraze[i].length() and y < recenica.length()) and (fraze[i][x] == recenica[y])) {
                x++; y++;
            }
            
            if (x == fraze[i].length()) {
                for (int q=j, w=(j+fraze[i].length()-1); q<w; ++q, --w) {
                    char znak{recenica[q]};
                    recenica[q] = recenica[w];
                    recenica[w] = znak;
                }   j += fraze[i].length()-1;
            }
        }
    }   return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijeci)
{
    if ( rijeci.size() == 0 ) {
        for (int i=0; i<recenica.length(); ++i) {
            if ((recenica[i] >= 'a' and recenica[i] <= 'z') or (recenica[i] >= 'A' and recenica[i] <= 'Z')) {
                int pocetak_rijeci(i);
                while ( i<recenica.length() and ((recenica[i] >= 'a' and recenica[i] <= 'z') or (recenica[i] >= 'A' and recenica[i] <= 'Z')))
                    i++;
                
                recenica = recenica.substr(0, i) + "ay" + recenica.substr(i, recenica.length());
                char znak{recenica[pocetak_rijeci]};
                for (int q=pocetak_rijeci; q<i-1; ++q)
                    recenica[q] = recenica[q+1];
                recenica[i-1] = znak; i += 2;
            }   else continue;
        }   return recenica;
    }
    
    // Test ispravnosti (samo jedna rijec)
    for (auto red : rijeci)
        for (auto x : red)
            if ((x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z')) continue;
            else throw std::domain_error("Nekorektan izbor rijeci");
            
    for (int i=0; i<rijeci.size(); ++i) {
        
        for (int j=0; j<recenica.length(); ++j) {
            
            if (j==0 or not((recenica[j-1] >= 'a' and recenica[j-1] <= 'z') or (recenica[j-1] >= 'A' and recenica[j-1] <= 'Z'))) {
                
                int x(0), y(j);
                while ((x < rijeci[i].length() and y < recenica.length()) and (rijeci[i][x] == recenica[y])) {
                    x++; y++;
                }
                
                if (not((recenica[y] >= 'a' and recenica[y] <= 'z') or (recenica[y] >= 'A' and recenica[y] <= 'Z')) and x == rijeci[i].length()) {
                    recenica = recenica.substr(0, j+rijeci[i].length()) + "ay" + recenica.substr(j+rijeci[i].length(), recenica.length());
                    char znak{recenica[j]};
                    for (int q=j; q<(j+rijeci[i].length()-1); ++q)
                        recenica[q] = recenica[q+1];
                    recenica[j+rijeci[i].length()-1] = znak;
                    j += rijeci[i].length()+2;
                }
            }
        }
    }   return recenica;
}

int main ()
{
    std::string recenica;
    std::cout << "Unesite recenicu: ";
    std::getline (std::cin, recenica);
    
    std::vector<std::string> fraze;
    std::cout << "Unesite fraze: ";
    for (;;) {
        std::string input;
        std::getline (std::cin, input);
        if (input == "")  break;
        else fraze.push_back(input);
    }
    
    try {
        std::string output(IzmijeniUPigLatin(recenica, fraze));
        std::cout << "Recenica nakon PigLatin transformacije: ";
        for (auto x : output)
            std::cout << x;
    }
    catch (std::domain_error txt) {
        std::cout << "Izuzetak: " << txt.what();
    }
    
    std::cout << std::endl;
    std::cout << "Recenica nakon obrtanja fraza: ";
    std::string output(ObrniFraze(recenica, fraze));
    for (auto x : output)
        std::cout << x;
    
	return 0;   
}