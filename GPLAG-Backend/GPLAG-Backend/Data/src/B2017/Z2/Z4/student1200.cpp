#include <iostream>
#include <set>
#include <algorithm>
#include <stdexcept>

template <typename PokTip1, typename PokTip2, typename PokTip3>
void SortirajPodrucjeVrijednosti(PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip3 p4, [] f(PokTip1 p1, PokTip2 p2){return 2*(*p1+*p2)}, [] fs(PokTip1 p1, PokTip2 p2){auto sumac1(0); auto sumac2(0); auto pom1(*p1); auto pom2(*p2); 
while(*pom1!=0){sumac1+=pom1%10; pom1/=10;} while(*pom2!=0){sumac2+=pom2%10; pom2/=10;} return sumac1<sumac2}){
    std::sort(p1, p2, fs);
    int n(p2-p1);
    std::sort(p3, p3+n, fs);
    while(p1!=p2){
    auto k=std::find(*f(p1,p3),p4);
    if(k==p4+n) throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
    p1++;
    p3++;
    }
}

int main ()
{
    std::set<int>S1{35, 12, 8, 111, 20, 4},S2{61, 39, 5, 313, 42, 13},S3{195, 46, 634, 22, 113, 126};
	return 0;
}