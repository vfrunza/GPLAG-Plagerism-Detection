/B2017/2018: Zadaća 5, Zadatak 6
#include<iostream>
#include<vector>
#include<stdexcept>
class Berza {
    std::vector<int> cijene;
    public:
    Berza(int min, int max) {
        if(min<0 || max<0) throw std::range_error("Ilegalne granice cijene");
        cijene.push_back(min);
        cijene.push_back(max);
    }
    Berza(int max) {
        if(max<0) throw std::range_error("Ilegalne granice cijene");
        cijene.push_back(0);
        cijene.push_back(max);
    }
};
int main ()
{
	return 0;
}
