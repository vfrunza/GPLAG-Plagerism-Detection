/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void IzlistajOptuzbu(char **pokStr, int n)
{
	for (int i = 0; i < n; i++) {
		if (pokStr[i]) {
			int j = 0;
			while (pokStr[i][j] != '\0') {
				cout << pokStr[i][j];
				j++;
			} cout << endl;
		}
	}
}

int PotencijalniKrivci(char **&pokStr, vector<string> s)
{
	int br = 0;
	try
	{
		pokStr = new char *[s.size()];

		try
		{
			for (int i = 0; i < s.size(); i++)
			{
				pokStr[i] = new char[s[i].size() + 1];
				if (pokStr) br++;
			}

			for (int i = 0; i < s.size(); i++)
			{
				for (int j = 0; j <= s[i].size(); j++)
				{
					pokStr[i][j] = s[i][j];
					if (j == s[i].size()) pokStr[i][j] = '\0';
				}
			}

			return br;
		}
		catch (...)
		{
			throw;
		}
	}
	catch (...)
	{
		delete[] pokStr;
		throw;
	}
}

int OdbaciOptuzbu(char **&pokStr, int n, string str)
{
	int br = n;
	int brim = 0;
	for (int i = 0; i < n; i++) {
		if (!pokStr[i]) continue;
		int k = 0;
		if (pokStr[i][k] != '\0' && pokStr[i])
		{
			while (pokStr[i][k] != '\0') k++;
		}

		int j = 0;
		if (pokStr[i][j] != '\0' && pokStr[i])
		{
			while (j < str.size() && pokStr[i][j] == str[j]) j++;
		}

		if (j == k)
		{
			pokStr[i] = nullptr;
			delete[] pokStr[i];
			continue;
		}
		brim++;
	}


	return n;
}

int DodajOptuzbu(char **&pokStr, int n, string str)
{
	try
	{
		for (int i = 0; i < n; i++) {
			if (!pokStr[i])
			{
				pokStr[i] = new char[str.size() + 1];

				for (int j = 0; j <= str.size(); j++)
				{
					if (i == str.size()) pokStr[i][j] = '\0';
					pokStr[i][j] = str[j];
				}
				return n;
			}
		}

		char **pokChar;
		pokChar = new char *[n + 1];

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while (pokStr[i][j] != '\0')
			{
				j++;
			}
			pokChar[i] = new char[j];

			for (int k = 0; k <= j; k++)
			{
				pokChar[i][k] = pokStr[i][k];
			}
		}

		pokChar[n] = new char[str.size() + 1];
		for (int i = 0; i <= str.size(); i++)
		{
			if (i == str.size()) pokChar[n][i] = '\0';
			pokChar[n][i] = str[i];
		}

		for (int i = 0; i < n; i++)
		{
			delete[] pokStr[i];
		}

		delete[] pokStr;

		n++;

		pokStr = new char *[n];

		for (int i = 0; i < n; i++)
		{
			int j = 0;

			while (pokChar[i][j] != '\0') j++;

			pokStr[i] = new char[j];
		}

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while (pokChar[i][j] != '\0')
			{
				pokStr[i][j] = pokChar[i][j];
				j++;
			}
		}

		return n;
	}
	catch (...)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] pokStr[i];
		}
		
		delete[] pokStr;
	}
}

int main()
{
	try
	{
		cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
		int n;
		cin >> n;
		cin.ignore(10000, '\n');

		cout << "Unesite potencijalne krivce: " << endl;
		vector<string> s;

		for (int i = 0; i < n; i++)
		{
			string pom;
			getline(cin, pom);

			s.push_back(pom);
		}


		char **pokStr = nullptr;

		n = PotencijalniKrivci(pokStr, s);

		int input;
		do
		{
			cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
			cin >> input;

			if (input == 1)
			{
				cout << "Unesite ime novog optuzenog: " << endl;
				cin.ignore(100000, '\n');
				string ime;
				getline(cin, ime);

				n = DodajOptuzbu(pokStr, n, ime);
			}

			if (input == 2)
			{
				cout << "Unesite ime koje zelite izbaciti: " << endl;
				cin.ignore(100000, '\n');
				string ime;
				getline(cin, ime);
				n = OdbaciOptuzbu(pokStr, n, ime);
			}

			if (input == 3)
			{
				IzlistajOptuzbu(pokStr, n);
			}

		} while (input != 0);

		return 0;
	}

	catch (...)
	{
		return 0;
	}
}