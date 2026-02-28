#include "crow.h"
#include "FinanceManager.h"

int main() {
    FinanceManager manager("my_expenses.json");
    crow::SimpleApp app;

    CROW_ROUTE(app, "/expenses")([&manager]() {

        auto j_list = nlohmann::json::array();
        std::vector<Expense> myExpenses = manager.getExpenses();

        for (const auto& expense: myExpenses) {
            nlohmann::json item;
            item["id"] = expense.getId();
            item["amount"] = expense.getAmount();
            item["category"] = expense.getCategory();
            item["date"] = expense.getDate();
            item["description"] = expense.getDescription();

            j_list.push_back(item);
        }

        return j_list.dump();
    });

    CROW_ROUTE(app, "/expenses").methods("POST"_method)([&manager](const crow::request& req) {
        auto item = nlohmann::json::parse(req.body);

        double tmp_amount = item["amount"];
        std::string tmp_category = item["category"];
        std::string tmp_date = item["date"];
        std::string tmp_description = "No description";

        if (item.contains("description")) {
            tmp_description = item["description"];
        }

        manager.add(tmp_amount, tmp_category, tmp_date, tmp_description);
        return crow::response(201);
    });

    CROW_ROUTE(app, "/expenses/<int>").methods("DELETE"_method)([&manager](int id) {
        bool deleted = manager.remove(id);
        
        if (deleted) {
            return crow::response(200);
        }
        return crow::response(404);
    });

    app.port(8080).multithreaded().run();

    return 0;
}