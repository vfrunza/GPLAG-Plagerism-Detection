#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> main_vektor) {
    Matrica oni_koji_rastu;
    if (main_vektor.size()==0) return oni_koji_rastu;
    int pamti_red(0);
    for (int i=0; i<main_vektor.size();i++) {
        if (i<main_vektor.size()-1 && main_vektor.at(i+1)>=main_vektor.at(i) ) {
            oni_koji_rastu.resize(oni_koji_rastu.size()+1);
            while (main_vektor.at(i)<=main_vektor.at(i+1)) {
                oni_koji_rastu.at(pamti_red).push_back(main_vektor.at(i));
                i++;
                if (i==main_vektor.size()-1)
                    break;
            }
            if (i>0 && i<main_vektor.size() && main_vektor.at(i)>=main_vektor.at(i-1))
                oni_koji_rastu.at(pamti_red).push_back(main_vektor.at(i));
            pamti_red++;
        }
    }
    return oni_koji_rastu;
}

Matrica OpadajuciPodnizovi (std::vector<double> main_vektor) {
    Matrica oni_koji_opadaju;
    int pamti_red(0);
    for (int i=0; i<main_vektor.size();i++) {
        if (i<main_vektor.size()-1 && main_vektor.at(i)>=main_vektor.at(i+1)) {
            oni_koji_opadaju.resize(oni_koji_opadaju.size()+1);
            while (main_vektor.at(i)>=main_vektor.at(i+1)) {
                oni_koji_opadaju.at(pamti_red).push_back(main_vektor.at(i));
                i++;
                if (i==main_vektor.size()-1)
                    break;
            }
            if (i>0 && i<main_vektor.size() && main_vektor.at(i)<=main_vektor.at(i-1))
                oni_koji_opadaju.at(pamti_red).push_back(main_vektor.at(i));
            pamti_red++;
        }
    }
    return oni_koji_opadaju;
}
int main () {
    std::cout<<"Unesite broj elemenata vektora: ";
    int elementi(0);
    for (;;) {
        std::cin>>elementi;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        else break;
    }
    std::cout<<"Unesite elemente vektora: ";
    std::vector<double> basic_vektor;   
    basic_vektor.resize(elementi);
    for (int i=0; i<elementi; i++) {
        std::cin>>basic_vektor[i];
    }
    Matrica rastuci_vektor(RastuciPodnizovi(basic_vektor));
    std::cout<<"Maksimalni rastuci podnizovi: \n";
    for (auto niz : rastuci_vektor) {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout<<std::endl;
    }
    Matrica opadajuci_vektor (OpadajuciPodnizovi(basic_vektor));
    std::cout<<"Maksimalni opadajuci podnizovi: \n";
    for (auto niz : opadajuci_vektor) {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout<<std::endl;
    }
	return 0;
}
