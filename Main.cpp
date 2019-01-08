#include <iostream>
#include <fstream>
#include <vector>
#include "Slovo.h"

using namespace std;

vector <vector <Slovo *>> zoznam;

void nachystajPole() //uloha 4
{
	for (int i = 0; i < 51; i++)
	{
		vector<Slovo *> zoznamPreXPismen; //uloha 4: pre kazdy pocet 1 zoznam
		zoznam.push_back(zoznamPreXPismen);
	}
}

void nacitaj() //uloha 3
{
	FILE * vstup = nullptr;
	vstup = fopen("subor.txt", "rt");
	if (vstup)
	{
		int dlzka = 0;
		while (!feof(vstup))
		{
			char * nacitane = new char[50];
			fscanf(vstup, "%s", nacitane);
			dlzka = strlen(nacitane);
			if (dlzka <= 50) //max 50
			{
				Slovo * nove = new Slovo(nacitane);
				zoznam.at(dlzka).push_back(nove); //uloha 5
			}
		}
		fclose(vstup);
	}
}

void zapisPoctySlovDoSuboru() //uloha 6
{
	ofstream vystup("poctySlov.txt");
	if (vystup.is_open())
	{
		for (int i = 1; i < 51; i++)
		{
			vystup << i << ":" << zoznam.at(i).size() << endl;
		}
		vystup.close();
	}
	else cout << "Neda sa otvorit subor";
}

void vypisSlovaPodlaPismen(int pocetPismen) //uloha 7
{
	if (pocetPismen < 50 && zoznam.at(pocetPismen).size() > 0)
	{
		for (int i = 0; i < zoznam.at(pocetPismen).size(); i++)
		{
			cout << zoznam.at(pocetPismen).at(i)->getSlovo() << ", ";
		}
	}
	else cout << "Text neobsahuje slovo so zadanym poctom pismen";
}

int main()
{
	nachystajPole();
	nacitaj();
	zapisPoctySlovDoSuboru();
	int pocetPismen;
	cout << "Zvolte pocet pismen:";
	cin >> pocetPismen;
	vypisSlovaPodlaPismen(pocetPismen);
	return 0;
}