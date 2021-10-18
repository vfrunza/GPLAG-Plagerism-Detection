#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *pok; 
    static GradjaninBiH *prvi;
    static int BrojCifara(long long int x){
        int brojac(0);
        while(x){
            brojac++;
            x/=10;
        }
        return brojac;
    }
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
};
 GradjaninBiH *GradjaninBiH::prvi = nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
    if(!prvi)prvi=this;
    if(!(BrojCifara(jmbg) == 12 || BrojCifara(jmbg) == 13))throw std::logic_error("Neispravni podaci");
    int mat_broj[13];
    mat_broj[12]=10;
   
   
}
int main ()
{
	return 0;
}