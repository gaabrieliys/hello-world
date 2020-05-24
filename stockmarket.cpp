#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    srand(time(0));
    int whcompany;
    double profitornot;
    long double amount;
    long double profit;
    long double balance;

    while (true) {
        ifstream b ("currbal.txt");
        b >> balance;
        b.close();

        double paybackChance[3];
        for (int i = 0; i < 3; i++) {
            paybackChance[i]= rand() % 100;
        }

        cout << "1 kompanijos akcijos: " << paybackChance[0] << "%, uzdirbsite: " << 100 - paybackChance[0] << "%, sansas islosti: " << paybackChance[0] << "%." << endl;
        cout << "2 kompanijos akcijos: " << paybackChance[1] << "%, uzdirbsite: " << 100 - paybackChance[1] << "%, sansas islosti: " << paybackChance[1] << "%." << endl;
        cout << "3 kompanijos akcijos: " << paybackChance[2] << "%, uzdirbsite: " << 100 - paybackChance[2] << "%, sansas islosti: " << paybackChance[2] << "%." << endl;
        cout << "Jus turite " << balance << " MurDoleriu" << endl;

        cin >> whcompany;
        cin >> amount;
        if (amount > balance) {
            abort();
        }
        if (whcompany == 1) {
            profitornot = rand() % 100 ;
            if (profitornot < paybackChance[0]) {
                profit = (amount / 100) * (100 - paybackChance[0]);
                balance = balance + profit;
            } else if (profitornot > paybackChance[0]) {
                profit = (amount / 100) * (100 - paybackChance[0]);
                balance = balance - amount;
            }
        } else if (whcompany == 2) {
            profitornot = rand() % 100 ;
            if (profitornot < paybackChance[1]) {
                profit = (amount / 100) * (100 - paybackChance[1]);
                balance = balance + profit;
            } else if (profitornot > paybackChance[0]) {
                profit = (amount / 100) * (100 - paybackChance[1]);
                balance = balance - amount;
            }
        } else if (whcompany == 3) {
            profitornot = rand() % 100 ;
            if (profitornot < paybackChance[2]) {
                profit = (amount / 100) * (100 - paybackChance[2]);
                balance = balance + profit;
            } else if (profitornot > paybackChance[0]) {
                profit = (amount / 100) * (100 - paybackChance[2]);
                balance = balance - amount;
            }
        }
        ofstream a ("currbal.txt");
        a << balance;
        a.close();

        /*int whcompany = 0;
        double profitornot = 0;
        long double amount = 0;
        long double profit = 0;
        long double balance = 0;
        paybackChance[0] = 0;
        paybackChance[1] = 0;
        paybackChance[2] = 0;*/
        system("CLS");
    }
    return 0;
}
