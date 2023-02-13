#include <iostream>
#include <cmath>

struct balonik
{
	int x;
	int y;
	int r;
};

int trafiony(int x, int y, int N, balonik tab[]) //funkcja liczaca zestrzelone baloniki
{
	int zestrzelone = 0;
	if (x == 0 || y == 0)
	{
		for (int i = 0; i < N; i++)
		{

			if (x == 0)
			{
				if ((tab[i].y > 0 && y > 0) || (tab[i].y <0 && y<0))
				{
					if (tab[i].x < 0 && (tab[i].x + tab[i].r >= 0))
						zestrzelone++;
					if (tab[i].x > 0 && (tab[i].x - tab[i].r <= 0))
						zestrzelone++;
				}
			}
			if (y == 0)
			{
				if (tab[i].x > 0 && x > 0 || tab[i].x < 0 && x < 0)
				{
					if (tab[i].y < 0 && (tab[i].y + tab[i].r >= 0))
						zestrzelone++;
					if (tab[i].y > 0 && (tab[i].y - tab[i].r <= 0))
						zestrzelone++;
				}
			}
		}
	}
	else
	{
		float a = (static_cast<float>(y) / x);
		for (int i = 0; i < N; i++)
		{
			//odrzucenie balonikow nie wchodz¹cych w badana cwiartke
			if (x >= 0 && y >= 0 && ((tab[i].x + tab[i].r < 0) || (tab[i].y + tab[i].r < 0))) continue;
			if (x <= 0 && y >= 0 && ((tab[i].x - tab[i].r > 0) || (tab[i].y + tab[i].r < 0))) continue;
			if (x <= 0 && y <= 0 && ((tab[i].x - tab[i].r > 0) || (tab[i].y - tab[i].r > 0))) continue;
			if (x >= 0 && y <= 0 && ((tab[i].x + tab[i].r < 0) || (tab[i].y - tab[i].r > 0))) continue;
			//obliczenie punktow wspolnych
			if ((abs(a * tab[i].x - tab[i].y) / sqrt(a * a + 1)) <= tab[i].r)
				zestrzelone++;
		}
	}
	return zestrzelone;
}

int main()
{
	int T;
	std::cin >> T; //zmienna okreslajaca ilosc testow
	
	for (int i = 0; i < T; i++)
	{
		int N, x, y;
		std::cin >> N >> x >> y;
		balonik *tab = new balonik[N]; //tablica przechowujaca dane o balonikach
		for (int i = 0; i < N; i++) //wypelnienie tablicy danymi kolejnych balonikow
		{
			std::cin >> tab[i].x >> tab[i].y >> tab[i].r;
		}
		std::cout << trafiony(x, y, N, tab) << std::endl;
		delete[] tab;
	}
	
}