#ifndef SNAKE_HH
#define SNAKE_HH
#define SIZE_X 40
#define SIZE_Y 20
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

enum dPlansza { pPuste, pOwoc, pOgon };
enum dKierunek { kGora, kDol, kPrawo, kLewo };

class Snake
{
    private:
    int Dlugosc,Waz[SIZE_X][SIZE_Y],Wynik,ilosc_Zebranych,Zebranych,Speed,KrokPunktow;
    dPlansza sPlansza[SIZE_X][SIZE_Y];

    	int x, y;
		bool GameOver;

		void RamkaX();
		void UpuscOwoc();

    public:
    Snake();
    	void RysujPlansze();
		// ruch w Kierunku
		void Ruch(dKierunek Kierunek);
		// czy nadal pilka w grze ?
		bool CzyGameOver();
		// zwraca aktualny wynik
		int WezWynik();
		// speed wezyka
		int WezSpeed();
		int WezY()
		{
			return y;
		}
};
#endif