#include <iostream>
#include <vector>

using namespace std;

template<typename tip1, typename tip2>
auto f(tip1 x, tip2 y) -> decltype(x+y) {
    return -2*x+y;
}

template<typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti()


int main() {
    cout << "Unesite broj elemenata: ";
    int br_el;
    cin >> br_el;
    vector<int> v1(br_el), v2(br_el), v3(br_el);
    cout << "Unesite elemente prvog vektora: ";
    for(int i=0;i<br_el;i++) cin >> v1[i];
    cout << "Unesite elemente drugog vektora: ";
    for(int i=0;i<br_el;i++) cin >> v2[i];
    cout << "Unesite elemente treceg vektora: ";
    for(int i=0;i<br_el;i++) cin >> v3[i];
    cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << endl;
	return 0;
}