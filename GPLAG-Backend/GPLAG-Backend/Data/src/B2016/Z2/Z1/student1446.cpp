#include <iostream>
#include <string>
enum class Smjer {Nalijevo,Nadesno}na_koju_stranu;
enum class Pravci {Sjever,Istok,Jug,Zapad}; 
enum class Status {aktivan,neaktivan}status_robota;
enum class KodoviGresaka{PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar}kod_greske;
enum class Komande{Aktiviraj,Deaktiviraj,Nalijevo,Nadesno,Idi,Kraj}komanda;
void AktivirajRobota(){
    status_robota=Status::aktivan;
}
void DeaktivirajRobota(){
    status_robota=Status::neaktivan;
}
void Rotiraj(Pravci &orjentacija,Smjer na_koju_stranu){
    if(status_robota==Status::aktivan){
        if(na_koju_stranu==Smjer::Nalijevo){
            int alala=(int)orjentacija;
            if(orjentacija>Pravci(0))
                orjentacija=Pravci(alala-1);
            else
                orjentacija=Pravci::Zapad;
        }
        else{
            int lalala=(int)orjentacija;
            if(orjentacija<Pravci(3))
                orjentacija=Pravci(lalala+1);
            else
                orjentacija=Pravci::Sjever;
        }
    }    
}
void Idi(int &x,int &y,Pravci orjentacija,int korak){
    if(status_robota==Status::aktivan){
        if(orjentacija==Pravci::Sjever)
            y+=korak;
        if(orjentacija==Pravci::Istok)
            x+=korak;
        if(orjentacija==Pravci::Jug)
            y-=korak;
        if(orjentacija==Pravci::Zapad)
            x-=korak;
    }        
}
void IspisiPoziciju(int x,int y,Pravci orjentacija){
    std::string a,b;
    if(status_robota==Status::aktivan)
        a="aktivan";
    else
        a="neaktivan";
    if(orjentacija==Pravci::Sjever)
        b="sjever";
    if(orjentacija==Pravci::Istok)
        b="istok";
    if(orjentacija==Pravci::Jug)
        b="jug";
    if(orjentacija==Pravci::Zapad)
        b="zapad";
    std::cout << "Robot je trenutno "<<a<<", nalazi se na poziciji ("<<x<<","<<y<<") i gleda na "<<b<<"." << std::endl;    
}
void PrijaviGresku(KodoviGresaka kod_greske){
    std::string greska;
    if(status_robota==Status::aktivan){
        if(kod_greske==KodoviGresaka::PogresnaKomanda)
            greska="Nerazumljiva komanda!";
        if(kod_greske==KodoviGresaka::NedostajeParametar)
            greska="Komanda trazi parametar koji nije naveden!";
        if(kod_greske==KodoviGresaka::SuvisanParametar)
            greska="Parametar komande nije ispravan!";
        if(kod_greske==KodoviGresaka::NeispravanParametar)
            greska="Zadan je suvisan parametar nakon komande!"; 
        std::cout << greska << std::endl;    
    }    
}
void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orjentacija){
    if(komanda==Komande::Aktiviraj)
        AktivirajRobota();
    if(komanda==Komande::Deaktiviraj)
        DeaktivirajRobota();
    if(komanda==Komande::Nalijevo)
        Rotiraj(orjentacija,Smjer::Nalijevo);
    if(komanda==Komande::Nadesno)
        Rotiraj(orjentacija,Smjer::Nadesno);
    if(komanda==Komande::Idi)
        Idi(x,y,orjentacija,parametar);
    if(komanda==Komande::Kraj){
        std::cout << "Dovidjenja!" << std::endl;
    }
}
bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske ){
    std::string unos;
    std::getline(std::cin,unos);
    if(unos=="A+"){
        komanda=Komande::Aktiviraj;
        return true;
    }
    if(unos=="A-"){
        komanda=Komande::Deaktiviraj;
        return true;
    }
    if(unos=="L"){
        komanda=Komande::Nalijevo;
        return true;
    }
    if(unos=="D"){
        komanda=Komande::Nadesno;
        return true;
    }
    if(unos[0]=='I' && unos[1]>='0' && unos[1]<='9'){
        parametar=(int)(unos[1]-'0');
        komanda=Komande::Idi;
        return true;
    }
    if(unos=="K"){
        komanda=Komande::Kraj;
        return true;
    }
    if(unos[0]!='K' && unos[0]!='I' && unos[0]!='D' && unos[0]!='A')
        kod_greske=KodoviGresaka::PogresnaKomanda;
    if(unos[0]=='I' && (unos[1]<'0'||unos[1]>'9'))
        kod_greske=KodoviGresaka::SuvisanParametar;
    if((unos[0] =='K' || unos[0] =='L' || unos[0] == 'D') && unos[1]!='\n')
        kod_greske=KodoviGresaka::NeispravanParametar;
    if((unos[0]=='A'||unos[0]=='A') && unos[1]=='\n')
        kod_greske=KodoviGresaka::NedostajeParametar;
    return false;
}
int main() {
    Pravci orjentacija;
    int k(0);
    orjentacija=Pravci::Sjever;
    int x(0),y(0);
    IspisiPoziciju(x,y,orjentacija);
    while(komanda!=Komande::Kraj){
        std::cout << "Unesi komandu: ";
        if(UnosKomande(komanda,k,kod_greske)){
            IzvrsiKomandu(komanda,k,x,y,orjentacija);
            if(komanda==Komande::Kraj){
                break;
            }
            IspisiPoziciju(x,y,orjentacija);
        }
        else{
            PrijaviGresku(kod_greske);
        }    
    }
    return 0;
}

