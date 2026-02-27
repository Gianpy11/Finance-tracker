#pragma once

#include <vector>
#include <nlohmann/json.hpp>
#include "Expense.h"

class FinanceManager
{
    public:
        FinanceManager(const std::string& f) : filePath(f), maxId(0)
        {
            loadFromFile();
        }

        bool loadFromFile();
        bool saveToFile();

        void add(const double price, const std::string& category, const std::string& date, const std::string& description) {
            Expense item(++maxId, price, category, date, description);
            myExpenses.push_back(item);
            saveToFile();
        }

        bool remove(int to_delete_id)
        {
            for (auto it = myExpenses.begin(); it != myExpenses.end(); ++it) {
                if (it->getId() == to_delete_id) {
                    myExpenses.erase(it);
                    saveToFile();
                    return true;
                }
            }
            return false;
        }

        int getCount() const {
            return myExpenses.size();
        }

        const std::vector<Expense>& getExpenses() const {
            return myExpenses;
        }

    private:
        std::vector<Expense> myExpenses;
        std::string filePath;
        int maxId;
};