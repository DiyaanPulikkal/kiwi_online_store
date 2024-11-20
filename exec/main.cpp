#include "lib.h"
#include <thread>
#include <chrono>

bool already_read = false;

int main() {
    if (!already_read){
        readAllData();
        already_read = true;
    }
    std::string sales_s;
    std::ifstream file("../dev/sales_record.txt");
    std::getline(file, sales_s);
    Devices::total_sales = std::stod(sales_s);     
    std::string mode_str;
    unsigned int mode;
    std::cout << "Welcome to Kiwi!" << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "1. Developer" << std::endl;
    std::cout << "2. Customer" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Option number: ";
    std::getline(std::cin, mode_str);
    while (true){
        try{
            mode = std::stoi(mode_str);
            if (mode > 3 || mode < 1){
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number from 1 to 3: " << std::endl;
            std::getline(std::cin, mode_str);
        }
    }

    switch (mode)
    {
    case 1:
        developer_mode();
        break;
    case 2:
        customer_mode();
        break;
    case 3:
        std::cout << "Thank you for visiting Kiwi!" << std::endl;
        break;
    default:
        break;
    }
  
}