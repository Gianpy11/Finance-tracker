#include <iostream>
#include "FinanceManager.h"

int main()
{
    FinanceManager manager("my_expenses.json");

    Expense expense1(1, 20.00, "Food", "2023-10-16", "Supermarket shopping");
    Expense expense2(2, 15.00, "Transport", "2023-10-25", "Train ticket");
    Expense expense3(3, 60.00, "Entertainment", "2023-10-26", "Metal concert");

    manager.add(expense1);
    manager.add(expense2);
    manager.add(expense3);

    manager.saveToFile();
    
    std::cout << "Operation completed!" << std::endl;
    std::cout << "Total number of recorded expenses: " << manager.getCount() << std::endl;
}