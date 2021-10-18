/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>

using namespace std;
 
function<double(double)> LinearnaInterpolacija(vector<pair<double, double>> cvorovi) {
    sort(cvorovi.begin(), cvorovi.end(), [](pair<double, double> a, pair<double, double> b) {return a.first < b.first; });
    for(int i=0; i < cvorovi.size() - 1; i++) 
        if(cvorovi[i].first == cvorovi[i + 1].first)
            throw domain_error("Neispravni cvorovi");
    
    
    return 0;
}

int main ()
{
	return 0;
}
