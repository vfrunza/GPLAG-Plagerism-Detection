/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> matrica;

matrica BrisanjePraznina(matrica m){
    for(int i=0; i<m.size(); i++){
        if(m[i].size()==1){
            m.erase(m.begin()+1);
        }
    }
    return m;
}

matrica RastuciPodnizovi(std::vector<double> v){
    matrica m(1, std::vector<double> ());
    int a(0),b(1);
    for(int i=1; i<v.size(); i++){
        if(v[i]<=v[i-1]){
           m[a].push_back(v[i]);
           //OVDJE JE KRAJ PODNIZA, TREBA NASTAVITi PROVJERU SA RESIZE ITD
        }
    }
    return m;
}

matrica OpadajuciPodnizovi(std::vector<double> v){
    matrica m(1, std::vector<double> ());
    int a(0),b(1);
    for(int i=1; i<v.size(); i++){
        if(v[i]>=v[i-1]){
           m[a].push_back(v[i]);
           //OVDJE JE KRAJ PODNIZA, TREBA NASTAVITi PROVJERU SA RESIZE ITD
        }
    }
    return m;
}

int main()
{
    int n;
    std::vector<double> v;
    matrica rp,op;
    std::cout<<"Unesite broj elemenata vektora:"<<std::endl;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora:"<<std::endl;
    for(int i=0; i<n; i++){
        double a;
        std::cin>>a;
        v.push_back(a);
    }
    rp=RastuciPodnizovi(v);
    op=OpadajuciPodnizovi(v);
    std::cout<<"Maksimalno rastuci nizovi:"<<std::endl;
    for(int i=0; i<rp.size(); i++){
        for(int j=0; j<rp[i].size(); j++)
           std::cout<<rp[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Maksimalno opadajuci nizovi:"<<std::endl;
     for(int i=0; i<op.size(); i++){
        for(int j=0; j<op[i].size(); j++)
           std::cout<<op[i][j]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
