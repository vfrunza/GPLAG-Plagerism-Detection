//B 2016/2017, Zadaća 1, Zadatak 3
#include<iostream>
#include<vector>

typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> VektorVektora;

VektorVektora RastuciPodnizovi(vektor VEK)
{
    vektor Pomocni;
    VektorVektora MATRICA;

    double n(VEK.at(0));
    bool X(true);

    for(int i=1; i<VEK.size(); i++) {
        if(n!=VEK.at(i)) {
            X=false;
            break;
        }
    }

    if(X==true) {
        MATRICA.push_back(VEK);
        return MATRICA;
    }

    int i(0), j(i+1);
    bool BiljeziPromjenu(false);
    bool DodatnaPromjena(false);
    while(i<int(int(VEK.size())-1) && j<int(VEK.size())) {
        if(VEK.at(i)==VEK.at(j)) {
            Pomocni.push_back(VEK.at(i));
            BiljeziPromjenu=true;
            i++;
            j++;
        }

        if(VEK.at(i)<VEK.at(j)) {
            Pomocni.push_back(VEK.at(i));
            DodatnaPromjena=true;
            if(j==int(int(VEK.size())-1))
                Pomocni.push_back(VEK.at(j));
        }

        if(VEK.at(i)>VEK.at(j) && int(Pomocni.size())>0) {
            if(BiljeziPromjenu==true && DodatnaPromjena!=true) {
                Pomocni.push_back(VEK.at(i));
                BiljeziPromjenu=false;
            }

            if(DodatnaPromjena==true) {
                Pomocni.push_back(VEK.at(i));
                DodatnaPromjena=false;
            }
            MATRICA.push_back(Pomocni);
            Pomocni.resize(0);
        }
        i++;
        j++;

    }

    if(int(Pomocni.size())>0) {
        MATRICA.push_back(Pomocni);
        Pomocni.resize(0);
    }

    return MATRICA;
}

VektorVektora OpadajuciPodnizovi(vektor VEK)
{
    vektor Pomocni;
    VektorVektora MATRICA;

    double n(VEK.at(0));
    bool X(true);

    for(int i=1; i<VEK.size(); i++) {
        if(n!=VEK.at(i)) {
            X = false;
            break;
        }
    }

    if(X==true) {
        MATRICA.push_back(VEK);
        return MATRICA;
    }

    int i(0), j(i+1);

    while(i<int(int(VEK.size())-1) && j<int(VEK.size())) {
        if(VEK.at(i)==VEK.at(j)) {
            Pomocni.push_back(VEK.at(i));
            i++;
            j++;
        }

        if(VEK.at(i)>VEK.at(j)) {
            Pomocni.push_back(VEK.at(i));
            if(j==int(int(VEK.size())-1))
                Pomocni.push_back(VEK.at(j));
        }


        if(VEK.at(i)<VEK.at(j) && int(Pomocni.size())>0) {

            Pomocni.push_back(VEK.at(i));

            MATRICA.push_back(Pomocni);
            Pomocni.resize(0);
        }
        i++;
        j++;
    }
    if(int(Pomocni.size())>1 || int(Pomocni.size()==1)) {
        MATRICA.push_back(Pomocni);
        Pomocni.resize(0);
    }

    return MATRICA;
}

int main ()
{
    double ElementiVektora;
    vektor VEKTOR;
    int BrojElemenata;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>BrojElemenata;
    std::cout<<"Unesite elemente vektora: ";

    for(int i=0; i<BrojElemenata; i++) {
        std::cin>>ElementiVektora;
        VEKTOR.push_back(ElementiVektora);
    }

    VektorVektora Opadajuci(OpadajuciPodnizovi(VEKTOR));
    VektorVektora Rastuci(RastuciPodnizovi(VEKTOR));

    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0; i<Rastuci.size(); i++) {
        for(int j=0; j<Rastuci.at(i).size(); j++) {
            std::cout<<Rastuci.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0; i<Opadajuci.size(); i++) {
        for(int j=0; j<Opadajuci.at(i).size(); j++) {
            std::cout<<Opadajuci.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
