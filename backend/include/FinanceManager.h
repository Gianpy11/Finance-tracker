#pragma once

#include <vector>
#include <nlohmann/json.hpp>
#include "Expense.h"

class FinanceManager
{
    public:
        FinanceManager(const std::string& f) : filePath(f) 
        {
            loadFromFile();
        }

        bool loadFromFile();
        bool saveToFile();

        void add(const Expense& item) {myExpenses.push_back(item);}

        bool remove(int to_delete_id)
        {
            for (auto it = myExpenses.begin(); it != myExpenses.end(); ++it) {
                if (it->getId() == to_delete_id) {
                    myExpenses.erase(it);
                    return true;
                }
            }
            return false;
        }

        int getCount() const {
            return myExpenses.size();
        }

    private:
        std::vector<Expense> myExpenses;
        std::string filePath;
};