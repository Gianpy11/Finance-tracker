#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "FinanceManager.h"

using json = nlohmann::json;

bool FinanceManager::loadFromFile()
{
    std::ifstream in_file(filePath);
    if (!in_file) {
        std::cerr << "No existing data file found" << std::endl;
        return false;
    }
    
    json dataJson;
    in_file >> dataJson;

    for (const auto& el: dataJson) {
        int tmp_id = el["id"];
        double tmp_amount = el["amount"];
        std::string tmp_category = el["category"];
        std::string tmp_date = el["date"];
        std::string tmp_description = "No description";

        if (el.contains("description")) {
            tmp_description = el["description"];
        }

        if (maxId < tmp_id) {
            maxId = tmp_id;
        }
        
        Expense newExpense(tmp_id, tmp_amount, tmp_category, tmp_date, tmp_description);
        myExpenses.push_back(newExpense);
    }

    in_file.close();
    return true;
}

bool FinanceManager::saveToFile()
{
    std::ofstream out_file(filePath);
    if (!out_file) {
        std::cerr << "Error creating file during saving" << std::endl;
        return false;
    }

    json j_list = json::array();

    for (const auto& expense: myExpenses) {
        json item;
        item["id"] = expense.getId();
        item["amount"] = expense.getAmount();
        item["category"] = expense.getCategory();
        item["date"] = expense.getDate();
        item["description"] = expense.getDescription();

        j_list.push_back(item);
    }

    out_file << j_list.dump(4);
    out_file.close();

    return true;
}