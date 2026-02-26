#pragma once

#include <string>
#include <vector>

class Expense
{
    public:
        Expense(int i, double a, const std::string& c, const std::string& da, const std::string& de)
            : id(i), amount(a), category(c), date(da), description(de)
        {}

        int getId() const {return id;}
        double getAmount() const {return amount;}
        std::string getCategory() const {return category;}
        std::string getDate() const {return date;}
        std::string getDescription() const {return description;}

    private:
        int id;
        double amount;
        std::string category;
        std::string date;
        std::string description;
};