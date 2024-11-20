#ifndef TOUCHPAD_H
#define TOUCHPAD_H

#include "peri_parent.h"

class Touchpad : public Peripherals {
    private:
        const std::string id_start = "AM";
        std::string type; //Capacitive, Resistive, etc.
        std::tuple<double, double> dimensions; //(l, w) in mm
    public:
        Touchpad();
        Touchpad(const int, const double);
        Touchpad(const std::string);

        void setType(const std::string);
        void setDimensions(const double, const double);

        std::string getType() const;
        std::tuple<double, double> getDimensions() const;

        static std::vector<Touchpad> touchpad_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Touchpad);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortDimensions();

        static std::vector<Touchpad> filterBrand(const std::string);
        static std::vector<Touchpad> filterType(const std::string);
        static std::vector<Touchpad> filterOnDisplay();

        // operator overloading
        Touchpad& operator=(const Touchpad&);
};

#endif