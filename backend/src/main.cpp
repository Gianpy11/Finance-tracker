#include <iostream>
#include "FinanceManager.h"

int main()
{
    FinanceManager manager("my_expenses.json");

    manager.add(20.00, "Food", "2023-10-16", "Supermarket shopping");
    manager.add(15.00, "Transport", "2023-10-25", "Train ticket");
    manager.add(60.00, "Entertainment", "2023-10-26", "Metal concert");
    
    std::cout << "Operation completed!" << std::endl;
    std::cout << "Total number of recorded expenses: " << manager.getCount() << std::endl;
}