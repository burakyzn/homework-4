#include <iostream>

using namespace std;

class Sifre {
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char* sifrele(char*);
	char* sifreCoz(char*);
	void sifreKelimesiAta(char*);

private:

	char* alfabe;
	char* sifreKelimesi;
};

int main() {
	char* alfabe = new char[26];
	char* sifre = new char[10];
	char* metin = new char[26];

	cout << "Alfabe Gir.........: ";
	cin >> alfabe;
	cout << "Sifre Gir..........: ";
	cin >> sifre;
	cout << "Metin Gir..........: ";
	cin >> metin;

	Sifre yeniSifre(alfabe, sifre);

	cout << "Sifrelenmis Metin..: " << yeniSifre.sifrele(metin) << endl;
	cout << "Desifre Metin......: " << yeniSifre.sifreCoz(metin) << endl;
	
	delete[] alfabe;
	delete[] sifre;
	delete[] metin;

	system("pause");
}

Sifre::Sifre() {

	this->alfabe = new char[26];

	for (int i = 0; i < 26; i++)
	{
		*(this->alfabe + i) = 65 + i;
	}

	*(this->alfabe + 26) = NULL;
}
Sifre::Sifre(char* alfabe, char* sifre) {
	this->alfabe = alfabe;
	this->sifreKelimesi = sifre;
}
char* Sifre::sifrele(char* metin)
{
	int alfabeBoyut = 0;
	int sifreBoyut = 0;
	int sira = 0;
	int sifreSira = 0;
	int metinSira = 0;
	int j = 0;

	for (int i = 0; *(alfabe + i) != NULL; i++)
	{
		alfabeBoyut++;
	}
	
	for (int i = 0; *(sifreKelimesi + i) != NULL; i++)
	{
		sifreBoyut++;
	}
	
	for (int i = 0; *(metin + i) != NULL; i++)
	{
		for (sira = 0; *(this->alfabe + sira) != NULL; sira++)
		{
			if (*(this->sifreKelimesi + j) == *(alfabe + sira))
			{
				sifreSira = sira;
				break;
			}
		}
		
		for (sira = 0; *(this->alfabe + sira) != NULL; sira++)
		{
			if (*(metin + i) == *(alfabe + sira)) {
				metinSira = sira; 
				break;
			}
		}

		if ((metinSira + sifreSira) > alfabeBoyut - 1)
			*(metin + i) = *(this->alfabe + metinSira + sifreSira - alfabeBoyut);
		else
			*(metin + i) = *(this->alfabe + metinSira + sifreSira);

		j++;

		if (j == sifreBoyut)
			j = 0;
	}

	return metin;
}
char* Sifre::sifreCoz(char* metin) {
	int alfabeBoyut = 0;
	int sifreBoyut = 0;
	int sira = 0;
	int sifreSira = 0;
	int metinSira = 0;
	int j = 0;
	int fark = 0;
	
	for (int i = 0; *(alfabe + i) != NULL; i++)
	{
		alfabeBoyut++;
	}
	
	for (int i = 0; *(sifreKelimesi + i) != NULL; i++)
	{
		sifreBoyut++;
	}
	
	for (int i = 0; *(metin + i) != NULL; i++)
	{
		for (sira = 0; *(this->alfabe + sira) != NULL; sira++)
		{
			if (*(this->sifreKelimesi + j) == *(alfabe + sira))
			{
				sifreSira = sira; 
				break;
			}
		}

		for (sira = 0; *(this->alfabe + sira) != NULL; sira++)
		{
			if (*(metin + i) == *(alfabe + sira)) {
				metinSira = sira;
				break;
			}
		}

		if (sifreSira > metinSira) {
			fark = sifreSira - metinSira;
			*(metin + i) = *(this->alfabe + (alfabeBoyut - fark));
		}
		else
			*(metin + i) = *(this->alfabe + (metinSira - sifreSira));

		j++;

		if (j == sifreBoyut)
			j = 0;
	}

	return metin;
}
void Sifre::sifreKelimesiAta(char* sifre) {
	this->sifreKelimesi = sifre;
}
