/*B 2016/2017, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <ostream>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<std::vector<std::vector<std::vector<double>>>> MMatrica;

Matrica OgledaloMatrica(Matrica m){
        for(int i=0;i<m.size();i++){        //HVATANJE GRBAVE MATRICE I BACANJE KAO IZUZETAK
        if(m[0].size()!=m[i].size())throw std::domain_error("Matrica nije korektna");
        }
    if(m.size()==0){
            m=Matrica({});
            return m;
    }
    Matrica h=m;
    Matrica v=m;
    Matrica hv=m;
    MMatrica Povratna;
    Povratna.resize(3);                     //KREIRANJE MATRICE MATRICA
    if((m.size())>=1 && (m[0].size())>0){
    for(int i=0;i<3;i++){
        Povratna[i].resize(3);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<Povratna[i].size();j++)
        Povratna[i][j].resize(m.size());
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<Povratna[i].size();j++){
            for(int k=0;k<Povratna[i][j].size();k++){
                Povratna[i][j][k].resize(m[0].size());
            }
        }
    }
    for(int i=(m.size()-1);i>=0;i--){ // HORIZONTALNA//
        for(int j=0;j<m[i].size();j++){
            h[i][j]=m[(m.size()-(i+1))][j];
        }
    }

    for(int i=0;i<m.size();i++){    //VERTIKALNA
        for(int j=(m[i].size()-1);j>=0;j--)
        {
            v[i][j]=m[i][m[i].size()-(j+1)];
        }
    }
    for(int i=0;i<m.size();i++){    //VERTIKALNA/HORIZONTALNA
        for(int j=(m[i].size()-1);j>=0;j--)
        {
            hv[i][j]=h[i][m[i].size()-(j+1)];
        }
    }
    }
    else{
        if(m.size()==1 && m[0].size()>=1){
            for(int i=0;i<m[0].size();i++){
                h[0][i]=m[0][(m[0].size())-(i+1)];
                hv=h;
                v=m;
            }
        }
        else if(m[0].size()==1 && m.size()>=1){
            for(int i=0;i<m.size();i++){
                v[i][0]=m[m[0].size()-(i+1)][0];
                hv=v;
                h=m;
            }
        }
    }

    //POPUNJAVANJE MATRICE MATRICAMA(horizontalna-vertikalna,horizontalna,vertikalna,orginalna)
    for(int i(0);i<3;i++)
    {
        for(int j(0);j<3;j++)
        {
           if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2)){
                for(int k=0;k<m.size();k++){
                    for(int l=0;l<m[0].size();l++){
                        Povratna[i][j][k][l]=hv[k][l];

                    }
                }
            }

            else if((i==0 && j==1) || (i==2 && j==1)){;
                for(int k=0;k<m.size();k++){
                    for(int l=0;l<m[k].size();l++){
                        Povratna[i][j][k][l]=h[k][l];
                    }
                }
            }
            else if(i==1 && (j==0 || j==2)){
                for(int k=0;k<m.size();k++){
                    for(int l=0;l<m[k].size();l++){
                        Povratna[i][j][k][l]=v[k][l];
                    }
                }
            }
            else if(i==1 && j==1){
                for(int k=0;k<m.size();k++){
                    for(int l=0;l<m[k].size();l++){
                        Povratna[i][j][k][l]=m[k][l];
                    }
                }
            }
        }
    }
    int redovi,kolone;
    redovi=m.size();
    kolone=m[0].size();
    Matrica Povratna1;
        Povratna1.resize((m.size())*3);
    for(int i=0;i<m.size()*3;i++){              //Prebacivanje elemenata matrice matrica u jednu matricu
        Povratna1[i].resize(3*m[0].size());
    }
    int brojac1 (0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<redovi;j++)
        {
            int brojac=0;
            for(int k=0;k<3;k++)
            {
                for(int z=0;z<kolone;z++){
                        Povratna1[brojac1][brojac]=Povratna[i][k][j][z];
                        brojac++;
                }
            }
            brojac1++;
        }
    }


return Povratna1;
}
int main(){
    Matrica povratna;
    Matrica c;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    int m,n;
    std::cin>>m>>n;
    if(m<0 || n<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice: ";

    c=Matrica(m,std::vector<double>(n));
    for(int i(0);i<m;i++){
        for(int j=0;j<n;j++){
            double x;
            std::cin>>x;
            c[i][j]=x;
        }
    }
    try{
    povratna=OgledaloMatrica(c);
    }
    catch(std::domain_error izuzetak){//HVATANJE DOMAIN ERORA grbave matrice
        std::cout <<izuzetak.what();
        return 0;
    }
    std::cout<<std::endl;
    std::cout<<"Rezultantna matrica:"<<std::endl;
for(auto i:povratna){
    for(auto j:i){
        std::cout<<std::setw(4)<<std::setfill(' ')<<std::right<<j;
    }std::cout<<std::endl;
}
return 0;
}
