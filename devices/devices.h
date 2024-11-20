#ifndef DEVICES_H
#define DEVICES_H

#include <string>
#include <array>
#include <tuple>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

class Devices{
    private:
        std::string id;
        std::string brand;
        std::string model;
        int quantity;
        double price;
        std::string description;
        bool on_display;
        std::string image_path;
    
    public:
        // constructor
        Devices();
        Devices(const int, const double);

        // getters
        double getPrice() const;
        double getQuantity() const;
        std::string getDescription() const;
        static double getTotalSales();
        std::string getID() const;
        bool getOnDisplay() const;
        std::string getBrand() const;
        std::string getModel() const;
        std::string getImagePath() const;
        
        // setters
        void setID(const std::string);
        void setQuantity(const int);
        void setPrice(const double);
        void setDescription(const std::string);
        void setOnDisplay(const bool);
        void setBrand(const std::string);
        void setModel(const std::string);
        void setImagePath(const std::string);

        // methods
        void removeFromStock(const int);
        void purchaseDevice(const unsigned int);
        void restock(const int);

        friend std::ostream& operator<<(std::ostream&, const Devices&);
        static double total_sales;

};

#endif