#ifndef WIRE_H
#define WIRE_H

#include "peri_parent.h"

class Wire : public Peripherals {
    private:
        const std::string id_start = "AJ";
        double length; //m
        std::string type;
    public:
        Wire();
        Wire(const int, const double);
        Wire(const std::string);

        void setLength(const double);
        void setType(const std::string);
        
        double getLength() const;
        std::string getType() const;

        static std::vector<Wire> wire_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Wire);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortLength();
        
        static std::vector<Wire> filterBrand(const std::string);
        static std::vector<Wire> filterType(const std::string);
        static std::vector<Wire> filterOnDisplay();

        // operator overloading
        Wire& operator=(const Wire&);
};

#endif