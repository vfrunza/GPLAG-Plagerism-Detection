/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> igraci,int br_timova){
    int br_igraca=igraci.size();
    std::list<std::string> stvori_tim;
    int brojac(0);
    int korak(0);
    std::list<std::string> po_timu;
    //kopiranje u listu
    for(int i=0;i<igraci.size();i++){
        stvori_tim.push_back(igraci[i]);
    }
    int i(0);
    //razvrstavanje koliko clanova ce bit po timu
    while(i<br_timova){
        int n=br_igraca/br_timova;
        po_timu.push_back(n);
        i++;
    }
    int j(0);
    int m=br_igraca%br_timova;
    while(j<m){
        po_timu[j]++;
        j++;
    }
    for(int i=brojac;i<m;i++){
        int k(0);
        while(k<po_timu[i]){
            while(korak>=br_igraca){
                korak-=br_igraca;
            }
            std::string ime=igraci[korak];
            stvori_tim[brojac].insert(ime);
            for(int j=korak;j<br_igraca;j++){
                igraci[j]=igraci[j+1];
            }
            br_igraca--;
            korak+=ime.size()-1;
        }
        brojac++;
    }
    return stvori_tim;
    
}
int main ()
{
    std::list<std::set<std::string>> nestonovo;
    std::list<std::string> nestonesto={"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"};
    nestonovo=Razvrstavanje(nestonesto,3);
    for(int i=0;i<v.size();i++){
        int j(0);
        for(std::string x: nestonovo[i]){
            if(j==0){
                std::cout<<x;
                j++;
            }
            else 
            std::cout<<", "<<x;
        }
        std::cout<<std::endl;
    }
	return 0;
}