// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>

/*template <typename tip>

auto IzdvojiDijagonale3D(tip kont,enum class SmjerKretanja) ->decltype(kont[0])
{
    decltype(*kont[0]+ *kont[0]) dek;
    
    
}
*/

int main ()
{
    std::vector<std::deque<std::deque<int>>> d(2,std::deque<std::deque<int>>(2,std::deque<int>(2)));
    d={1,2,3,4,5,6,7,8};
    for(auto i=d.begin(); i!=d.end(); i++)
    {
        for(auto j=d->begin(); j!=d->end(); j++)
        for(auto k=(j)->begin()); k!=(j)->begin()); k++)
        {
            std::cout<<k;
        }
    }
    
	return 0;
}