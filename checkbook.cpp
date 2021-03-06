#include <iostream>
#include <fstream>
#include <regex>

int main()
{
    std::ifstream ifs("./ex_chk");

    std::string line;

    if (ifs.good())
    {
        const std::regex regex_chars("[^a-zA-Z0-9.]");
        std::string firstLine;
        std::string cost;
        std::string desc;
        int num;
        int numOfEntries = 0;
        float balance;
        float totalExpense;
        float avgExpense;

        getline(ifs, firstLine);
        balance = stof(firstLine);

        std::cout << std::fixed << std::setprecision(2) << "Original_Balance: " << balance;
        while (ifs >> num >> desc >> cost)
        {
            cost = std::regex_replace(cost, regex_chars, "");
            float fcost = std::stof(cost.c_str());
            desc = std::regex_replace(desc, regex_chars, "");

            totalExpense += fcost;
            balance -= fcost;
            numOfEntries += 1;

            std::cout << std::fixed << std::setprecision(2) << "\n"
                      << num << " " << desc << " " << cost << " Balance " << balance << "\n";
        }

        avgExpense = totalExpense / numOfEntries;
        std::cout << std::fixed << std::setprecision(2) << "Total expense " << totalExpense;
        std::cout << std::fixed << std::setprecision(2) << " Average expense " << avgExpense;

        return 0;
    }
}
