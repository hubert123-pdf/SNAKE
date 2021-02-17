#include "snake.hh"

Snake::Snake()
{
    for (int i=0;i<=SIZE_X;i++)
    {
        for(int j=0;j<=SIZE_Y;j++)
        {
            sPlansza[i][j]=pPuste;
        }
    }
    for (int i=0;i<=SIZE_X;i++)
    {
        for(int j=0;j<=SIZE_Y;j++)
        {
            Waz[i][j]=0;
        }
    }
    GameOver=false;
    x=SIZE_X/2;
    y=SIZE_Y/2;
    Dlugosc=4;

    Wynik=0;
    Speed=1;
    ilosc_Zebranych=0;
    KrokPunktow=1;
    UpuscOwoc();
}
void Snake::RamkaX()
{
	cout << " +";
	for (int i=0;i<SIZE_X;i++)
		cout << "-";
	cout << "+" << endl;
}
void Snake::RysujPlansze()
{
	RamkaX();

	for (int i=0;i<SIZE_Y;i++)
	{
		cout << " |";
		for (int j=0;j<SIZE_X;j++)
		{
			if (Waz[j][i] > 0)
				Waz[j][i]--;
			else if (sPlansza[j][i] != pOwoc)
				sPlansza[j][i] = pPuste;
			
			switch (sPlansza[j][i])
			{
				case pPuste:
					cout << ' ';
					break;
				case pOwoc:
					cout << '*';
					break;
				case pOgon:
					// nasza glowa ?
					if (j == x && i == y)
					{

						cout << char(206);
			
					}
					else
					{
		
						cout << 'o';
		
					}
					break;
				default: break;
			}			
		}
		cout << "|" << endl;
	}

	RamkaX();
}
void Snake::UpuscOwoc()
{
	unsigned tempX, tempY;

	do
	{
		srand (static_cast<unsigned>(time(NULL)));

		tempX = rand()%SIZE_X-1;
		tempY = rand()%SIZE_Y-1;
	} while ((sPlansza[tempX][tempY] != pPuste) && (tempX < SIZE_X-1) && (tempY < SIZE_Y-1));

	sPlansza[tempX][tempY] = pOwoc;
}
void Snake::Ruch(dKierunek Kierunek)
{
	switch (Kierunek)
	{
		case kGora:
			if (--y == -1) GameOver = true; break;
		case kDol:
			if (++y > SIZE_Y-1) GameOver = true; break;
		case kLewo:
			if (--x == -1) GameOver = true; break;
		case kPrawo:
			if (++x > SIZE_X-1) GameOver = true; break;
		default: return;
	}
	
	if (sPlansza[x][y] == pOgon)
	{
		GameOver = true;
		return;
	}
	
	if (GameOver)
		return;

	if (sPlansza[x][y] == pOwoc)
	{
		Zebranych++;
		Wynik += KrokPunktow;
		UpuscOwoc();
	}
		
	sPlansza[x][y] = pOgon;
	Waz[x][y] = Dlugosc;
}
bool Snake::CzyGameOver()
{
	return GameOver;
}

int Snake::WezWynik()
{
	return Wynik;
}

int Snake::WezSpeed()
{
	return Speed;
}