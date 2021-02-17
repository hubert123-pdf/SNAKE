#include "getch.hh"
#include "snake.hh"
int main()
{

    char Znak;
    Snake Snake;
    dKierunek uKierunek = static_cast<dKierunek>(-1);

 for (;;)
	{
		cout << "!\n\n";
		
		Snake.Ruch(uKierunek);
		Snake.RysujPlansze();
		
		if (Snake.CzyGameOver())
		{
			cout << "Zdobyles " << Snake.WezWynik() << " punktow.\n\n";
			break;
		}
		cout << " Punkty: " << Snake.WezWynik() << endl;
		cin>>Znak;
		
		switch (Znak)
		{
			case 'w':
				if (uKierunek != kDol) uKierunek = kGora; break;
			case 'd':
				if (uKierunek != kLewo) uKierunek = kPrawo; break;
			case 'a':
				if (uKierunek != kPrawo) uKierunek = kLewo; break;
			case 's':
				if (uKierunek != kGora) uKierunek = kDol; break;
			default: break;
		}

		sleep(Snake.WezSpeed());
		system("clear");
	}
	
	system("PAUSE");
    return EXIT_SUCCESS;
    return 0;
}