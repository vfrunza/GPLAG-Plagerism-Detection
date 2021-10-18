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

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> rijeci)
{
    std::string temp;
    std::string glavnarecenica="";



    int zaj=0,zaj2=0;


    for (int i=0; i<rijeci.size();  i++) {
        temp=rijeci.at(i);

        for (int j=0; j<recenica.size(); j++) {
            int brojac2=0;
            zaj=j;

            if( brojac2<temp.size() &&recenica.at(j)==temp.at(brojac2) && ((j>0 && recenica.at(j-1)==' ') || j==0)) {

                brojac2=0;

                do {

                    j++;
                    brojac2++;
                } while( brojac2< temp.size() && j<recenica.size() &&recenica.at(j)==temp.at(brojac2));
                zaj2=j;
                std::string nekis="";
                if((brojac2==temp.size() && j==recenica.size()) || (brojac2==temp.size() && (recenica.at(j)==' ' || recenica.at(j)==',' || recenica.at(j)=='.' || recenica.at(j)=='!' || recenica.at(j)==':' || recenica.at(j)=='?'))) {
                    if(j!=recenica.size())
                        nekis=recenica.at(j);

                    glavnarecenica+=temp;
                    int brojac3 = glavnarecenica.size();
                    glavnarecenica+=temp;
                    for(int q=temp.size()-1; q>=0; q--) {

                        glavnarecenica.at(brojac3)=temp.at(q);
                        brojac3++;
                    }
                    glavnarecenica+=nekis;

                } else {
                    //else od malog ifa
                    if(zaj2==recenica.size())zaj2--;
                    for(int z(zaj); z<=zaj2; z++) {
                        glavnarecenica+=recenica.at(z);
                    }
                }


            } else {
                //else od velikog ifa
                glavnarecenica+=recenica.at(j);
            }
        }
        recenica=glavnarecenica;
        glavnarecenica="";
    }
    return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> rijeci)

{
    std::string temp;
    std::string glavnarecenica="";



    int zaj=0,zaj2=0;


    for (int i=0; i<rijeci.size();  i++) {
        temp=rijeci.at(i);

        for (int j=0; j<recenica.size(); j++) {
            int brojac2=0;
            zaj=j;

            if( brojac2<temp.size() &&recenica.at(j)==temp.at(brojac2) && ((j>0 && recenica.at(j-1)==' ') || j==0)) {

                brojac2=0;

                do {

                    j++;
                    brojac2++;
                } while( brojac2< temp.size() && j<recenica.size() &&recenica.at(j)==temp.at(brojac2));
                zaj2=j;
                std::string nekis="";
                if((brojac2==temp.size() && j==recenica.size()) || (brojac2==temp.size() && (recenica.at(j)==' ' || recenica.at(j)==',' || recenica.at(j)=='.' || recenica.at(j)=='!' || recenica.at(j)==':' || recenica.at(j)=='?'))) {
                    if(j!=recenica.size())
                        nekis=recenica.at(j);

                    glavnarecenica+=temp;
                    int brojac3 = glavnarecenica.size()-temp.size()/2;

                    for(int q=temp.size()/2-1; q>=0; q--) {


                        glavnarecenica.at(brojac3)=temp.at(q);
                        brojac3++;
                    }
                    glavnarecenica+=nekis;

                } else {
                    //else od malog ifa
                    if(zaj2==recenica.size())zaj2--;
                    for(int z(zaj); z<=zaj2; z++) {
                        glavnarecenica+=recenica.at(z);
                    }
                }


            } else {
                //else od velikog ifa
                glavnarecenica+=recenica.at(j);
            }
        }
        recenica=glavnarecenica;
        glavnarecenica="";
    }
    return recenica;
}

int main ()
{

    std::string glavnarecenica;
    std::vector<std::string> vektorrijeci;
    std::string testrijeci;
    std::cout<< "Unesite recenicu: ";
    std::getline (std::cin, glavnarecenica);
    std::cout<< "Unesite fraze: ";
    do {
        vektorrijeci.push_back (testrijeci);
    } while (std::getline (std::cin, testrijeci) && testrijeci.size()>0);
    std::string novi=NapraviPalindrom (glavnarecenica, vektorrijeci);
    std::cout<< "Recenica nakon Palindrom transformacije: ";
    for (int i=0; i<novi.size(); i++)
        std::cout<< novi.at(i);
    std::cout<< std::endl;
    std::string novip=NapraviPoluPalindrom (glavnarecenica, vektorrijeci);
    std::cout<< "Recenica nakon PoluPalindrom transformacije: ";
    for (int i=0; i<novip.size(); i++)
        std::cout<< novip.at(i);
    return 0;
}