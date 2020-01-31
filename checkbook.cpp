#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
using namespace std;

int main()
{
    ifstream ifs("./ex_chk");

    string line;

    if (ifs.good())
    {
        const regex good_chars("[^a-zA-Z0-9.]");
        string firstLine;
        string cost;
        string desc;
        int num;
        int numOfEntries = 0;
        float fcost;
        float balance;
        float totalExpense;
        float avgExpense;
        float newBalance;

        getline(ifs, firstLine);
        balance = stof(firstLine);

        cout << fixed << setprecision(2) << "Original_Balance: " << balance;
        while (ifs >> num >> desc >> cost)
        {
            cost = std::regex_replace(cost, good_chars, "");
            float dcost = ::stof(cost.c_str());
            desc = std::regex_replace(desc, good_chars, "");

            totalExpense += dcost;
            balance -= dcost;
            numOfEntries += 1;

            cout << fixed << setprecision(2) << "\n"
                 << num << " " << desc << " " << cost << " Balance " << balance << "\n";
        }

        avgExpense = totalExpense / numOfEntries;
        cout << fixed << setprecision(2) << "Total expense " << totalExpense;
        cout << fixed << setprecision(2) << " Average expense " << avgExpense;

        ifs.close();

        return 0;
    }
}