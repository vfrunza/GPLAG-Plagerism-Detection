/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>

bool PocetakRijeci (const char &x) {
    if ((x>='A' && x<='Z') || (x>='a' && x<='z')  || (x>='0' && x<='9')) {
    	std::cout<<"Pozitivno"<<std::endl;
    	return true;
    	
    }
     return false;
}

int VratiVel (const std::string &str) {
    int Velicina(0);
    for (int i(0); i<str.size(); i++) {
         if (PocetakRijeci(str[i])) Velicina++;
    }
    std::cout<<Velicina<<std::endl;
    return Velicina;
}



int main ()
{ 
	std::string unesi {" 123  432 // //  "};
	
	VratiVel(unesi);
	/*for (int i(0); i<unesi.size(); i++) {
		VratiVel(unesi[i]);
	} */
	return 0;
}
