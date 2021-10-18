/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <stdexcept>


int** KreirajTrougao (int n)
{
	if (n<=0)
		throw std::domain_error ("Broj redova mora biti pozitivan");


	int **matrica = nullptr;
	try
	{
		matrica = new int* [n];
		for (int i{};i<n;i++)
			matrica[i] = nullptr;
	}
	catch (...)
	{
		delete [] matrica;
		matrica = nullptr;

		std::bad_alloc e;
		throw e;
	}

	try
	{
	    int k = 0;
		matrica[0] = new int [n*n];
		for (int i{1};i<n;i++)
			{
			    matrica[i] = matrica[i-1]+2*k+1;
			    k++;
			}
	}
	catch (...)
	{
		delete [] matrica[0];
		delete [] matrica;
		matrica = nullptr;

		std::bad_alloc e;
		throw e;
	}


	for (int i{};i<n;i++)
		{
			int broj = i+1;
			bool uslov = false;
			for (int j{};j<2*i+1;j++)
				{
					if (broj == 1)
						{
							matrica[i][j] = 1;
							broj = 2;
							uslov = true;
						}
					else if (uslov == false)
						{
							matrica[i][j] = broj;
							broj--;
						}
					else if (uslov == true)
						{
							matrica[i][j] = broj;
							broj++;
						}
				}
		}



	return matrica;


}


int main ()
{
	try
	{
		std::cout<<"Koliko zelite redova: ";
		int n;
		std::cin>>n;
		std::cin.ignore(100000,'\n');

		int **matrica = KreirajTrougao(n);

		for (int i{};i<n;i++)
			{
				for (int j{};j<2*i+1;j++)
					std::cout<<matrica[i][j]<<" ";

				std::cout<<std::endl;
			}

		delete [] matrica[0];
		delete [] matrica;
		matrica = nullptr;
	}
	catch (std::domain_error e)
		{
			std::cout<<"Izuzetak: "<<e.what();
		}
	catch (std::bad_alloc)
		{
			std::cout<<"Izuzetak: Nedovoljno memorije!";
		}







	return 0;
}









































#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>


template<typename kontejner_tip>
auto KreirajDinamickuKopiju2D (kontejner_tip struktura) -> decltype (struktura[0][0] + struktura[0][0])**
{
    decltype (struktura[0][0] + struktura[0][0])** matrica = nullptr;

    try
    {
        matrica = new decltype (struktura[0][0] + struktura[0][0])* [struktura.size()];
        for (int i{};i<struktura.size();i++)
            matrica[i] = nullptr;

    }
    catch (...)
    {
        delete [] matrica;
        matrica = nullptr;

        std::bad_alloc e;
        throw e;
    }

    try
    {
        int velicina = 0;
        for (int i{};i<struktura.size();i++)
            velicina+=struktura[i].size();

        matrica[0] = new decltype (struktura[0][0] + struktura[0][0]) [velicina];
        for (int i{1};i<struktura.size();i++)
            matrica[i] = matrica[i-1] + struktura[i-1].size();
    }
    catch(...)
    {
        delete [] matrica[0];
        delete [] matrica;
        matrica = nullptr;

        std::bad_alloc e;
        throw e;
    }

    for (int i{};i<struktura.size();i++)
        {
            for (int j{};j<struktura[i].size();j++)
                matrica[i][j] = struktura[i][j];
        }

    return matrica;
}


int main ()
{

    try
    {
        std::cout<<"Unesite broj redova kvadratne matrice: ";
        int n;
        std::cin>>n;

        std::vector<std::deque<int>> struktura (n, std::deque<int> (n));
        std::cout<<"Unesite elemente matrice: ";

        for (int i{};i<n;i++)
            {
                for (int j{};j<n;j++)
                    std::cin>>struktura[i][j];
            }

        int **matrica = KreirajDinamickuKopiju2D(struktura);

        for (int i{};i<n;i++)
            {
                for (int j{};j<n;j++)
                    std::cout<<matrica[i][j]<<" ";

                std::cout<<std::endl;
            }


        delete [] matrica[0];
        delete [] matrica;
        matrica = nullptr;

    }
    catch (std::bad_alloc)
        {
            std::cout<<"Nedovoljno memorije";
        }



	return 0;
}
