#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class balancedRandom {
    private: double luck;
    private: double koef;
    private: double savedPercent;

    public: balancedRandom(double probabilityPercent = 0.0, double koefficient = 0.06)
    {
        srand (time(NULL));
        koef = koefficient;
        savedPercent = probabilityPercent;
    };

    public: bool getChance(double probabilityPercent) {
      int randVal = rand() % 100000 + 1;
      if (randVal <= probabilityPercent * (1 + abs(luck) / (abs(luck) + 1) * (luck > 0 ? 1 : -1)) * 1000)
      {
          luck -= (100 - probabilityPercent) * koef;
          return true;
      }
      else
      {
          luck += probabilityPercent * koef;
          return false;
      }
    }

    public: bool getChance() {
      int randVal = rand() % 100000 + 1;
      if (randVal <= savedPercent * (1 + abs(luck * koef) / (abs(luck* koef) + 1) * (luck > 0 ? 1 : -1)) * 1000)
      {
          luck -= (100 - savedPercent) * koef;
          return true;
      }
      else
      {
          luck += savedPercent * koef;
          return false;
      }
    }

    public: getLuck()
    {
        return luck;
    }

    public: setLuck(double value)
    {
        luck = value;
    }

    public: getKoef()
    {
        return koef;
    }

    public: setKoef(double value)
    {
        koef = value;
    }

    public: getPercent()
    {
        return savedPercent;
    }

    public: setPercent(double value)
    {
        percent = value;
    }


};
int main ()
{
  const int N = 10000;
  const double P = 2;
  double iSecret, sum, r;
  double luck = 0;

  /* initialize random seed: */
  srand (time(NULL));
  std::freopen("res.txt", "w", stdout);
  sum = 0;
  balancedRandom gen(50.0, 0.1);
  for (int i=0; i<N; ++i)
  {
        int v = gen.getChance();
        cout << v;
        sum += v;
  }
  cout << endl;
  cout << endl << sum / N * 100;

  return 0;
}
