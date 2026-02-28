#include "crow.h"
#include "FinanceManager.h"

int main() {
    FinanceManager manager("expenses.json");
    crow::SimpleApp app;

    app.port(8080).multithreaded().run();
    return 0;
}