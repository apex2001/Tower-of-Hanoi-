#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

void move(int disc, string from, string to);
void toh(int disc, string S, string D, string A1, string A2, string A3,
         string A4);
void StoA4(int disc, string S, string D, string A1, string A2, string A3,
           string A4);
void A4toA2(int disc, string S, string D, string A1, string A2, string A3,
            string A4);
void A4toD(int disc, string S, string D, string A1, string A2, string A3,
           string A4);

int main() {
  int n;
  cout << "Enter number of pegs: ";
  cin >> n;

  toh(n, "S", "D", "A1", "A2", "A3", "A4");
  return 0;
}

void move(int disc, string from, string to) {
  sleep(1);
  cout << "move disk " << disc << " from " << from << " to " << to << endl;
}

void toh(int disc, string S, string D, string A1, string A2, string A3,
         string A4) {
  if (disc == 0) {
    return;
  }

  StoA4(disc - 1, S, D, A1, A2, A3, A4);
  move(disc, S, D);
  A4toD(disc - 1, S, D, A1, A2, A3, A4);
}

void StoA4(int disc, string S, string D, string A1, string A2, string A3,
           string A4) {
  if (disc == 0) {
    return;
  }

  StoA4(disc - 1, S, D, A1, A2, A3, A4);
  move(disc, S, D);
  move(disc, D, A1);
  move(disc, A1, A2);
  move(disc, A2, A3);
  A4toA2(disc - 1, S, D, A1, A2, A3, A4);
  move(disc, A3, A4);
  A4toA2(disc - 1, S, D, A3, A4, A1, A2);
}

void A4toA2(int disc, string S, string D, string A1, string A2, string A3,
            string A4) {
  if (disc == 0) {
    return;
  }
  A4toA2(disc - 1, S, D, A1, A2, A3, A4);
  move(disc, A4, A1);
  A4toA2(disc - 1, S, D, A3, A4, A1, A2);
  move(disc, A1, A2);
  A4toA2(disc - 1, S, D, A1, A2, A3, A4);
}

void A4toD(int disc, string S, string D, string A1, string A2, string A3,
           string A4) {
  if (disc == 0) {
    return;
  }
  A4toA2(disc - 1, S, D, A1, A2, A3, A4);
  move(disc, A4, A1);
  move(disc, A1, D);
  A4toA2(disc - 1, S, D, A3, A4, A1, A2);
  A4toD(disc - 1, S, D, A1, A2, A3, A4);
}