/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>

template <typename tip>
void Razvrstaj (tip niz1[], int n1, tip niz2[], int &n2, tip niz3[], int &n3, tip min, tip max)
{
    n2=0;
    n3=0;

    for (int i{};i<n1;i++)
        {
            if (niz1[i]>=min && niz1[i]<=max)
                niz2[n2++]=niz1[i];
            else
                niz3[n3++]=niz1[i];
        }


}
int main()
{
    std::cout<<"Uzet je proizvoljan niz, zajedno sa proizvoljnim granicama."<<std::endl<<std::endl;
    int niz[10] {1,2,3,4,5,6,7,8,9,10};
    int opseg[10], van_opsega[10];

    int br1,br2;

    Razvrstaj(niz,10,opseg,br1,van_opsega,br2,2,5);

    std::cout<<"Elementi koji se nalaze u opsegu: "<<std::endl;
    for (int i{};i<br1;i++)
        std::cout<<opseg[i]<<" ";
    std::cout<<std::endl<<std::endl<<"Elementi koji se nalaze van opsega: "<<std::endl;
    for (int i{};i<br2;i++)
        std::cout<<van_opsega[i]<<" ";
    std::cout<<std::endl;



    return 0;
}
