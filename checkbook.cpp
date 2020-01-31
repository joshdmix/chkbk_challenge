#include <iostream>
#include <fstream>
#include <regex>

int main()
{
    std::ifstream ifs("./ex_chk");

    std::string line;

    if (ifs.good())
    {
        const std::regex good_chars("[^a-zA-Z0-9.]");
        std::string firstLine;
        std::string cost;
        std::string desc;
        int num;
        int numOfEntries = 0;
        float fcost;
        float balance;
        float totalExpense;
        float avgExpense;
        float newBalance;

        getline(ifs, firstLine);
        balance = stof(firstLine);

        std::cout << std::fixed << std::setprecision(2) << "Original_Balance: " << balance;
        while (ifs >> num >> desc >> cost)
        {
            cost = std::regex_replace(cost, good_chars, "");
            float dcost = std::stof(cost.c_str());
            desc = std::regex_replace(desc, good_chars, "");

            totalExpense += dcost;
            balance -= dcost;
            numOfEntries += 1;

            std::cout << std::fixed << std::setprecision(2) << "\n"
                      << num << " " << desc << " " << cost << " Balance " << balance << "\n";
        }

        avgExpense = totalExpense / numOfEntries;
        std::cout << std::fixed << std::setprecision(2) << "Total expense " << totalExpense;
        std::cout << std::fixed << std::setprecision(2) << " Average expense " << avgExpense;

        ifs.close();

        return 0;
    }
}