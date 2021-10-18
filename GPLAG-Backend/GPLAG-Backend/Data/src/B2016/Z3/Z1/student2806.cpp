#include <iostream>
#include <funkiconal>
template<class left>
std::function<left(left be1, left be2, left be3)>
ProslijediLijevo(std::function<left(left be1, left be2, left be3)> l)
{
    return l;
}


template<class right>
std::function<right(std::function<right(right q, right w, right e)>)>
ProslijediDesno(right q, right w, right e)
{
    return [q,w,e](std::function<right(right q, right w, right e)>r)
    {
        return r(q, w, e);
    };
}


template<class monster>
std::function<std::function<std::function<std::function<monster(monster g)>(std::function<monster(monster sum, monster skalar)>t)>(monster w, monster e)>(monster q)>
MonstrumFunkcija(std::function<monster(monster q, monster w, monster e)> m)
{
    return[m](monster q)
    {
        return [m, q](monster w, monster e)
        {
            return [m, q, w, e](std::function<monster(monster sum, monster skalar)> t)
            {
                return [m, q, w, e, t](monster g)
                {
                    return t(m(q, w, e), g);
                };
            };
        };
    };
}
int main() {
    std::cout << "Unesite x y z: " ;
    double x,y,z;
    std::cin >> x>>y>>z;
    std::cout << "Unesite faktor skaliranja: ";
    double k;
    std::cin >> k;
    std::cout << "Prosljedjivanje ulijevo: "<<std::endl;
    std::cout << "Prosljedjivanje udesno: "<<std::endl;
    std::cout << "Monstrum: " << std::endl;
    return 0;
}

