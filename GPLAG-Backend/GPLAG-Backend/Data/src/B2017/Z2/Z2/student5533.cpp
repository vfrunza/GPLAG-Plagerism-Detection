#include <iostream>
#include <stdexcept>
class Vrijeme {
	int sati, minute, sekunde;
public:
    Vrijeme (int sat, int min, int sek) {
    	if (sat <0 || min<0 || sek<0) throw std::domain_error ("Nisu valini podaci");
    	if (sek > =60) { minute++; sekunde-=60; }
    	if (min>=60) { sati++; minute-=60; }
    }
};


int main ()
{
	return 0;
}