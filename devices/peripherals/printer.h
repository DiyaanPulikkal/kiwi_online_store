#ifndef PRINTER_H
#define PRINTER_H

#include "peri_parent.h"

class Printer : public Peripherals {
    private:
        const std::string id_start = "AU";
        std::string type; //Laser, Inkjet, etc.
        bool has_scanner;
        bool is_wireless;
        int speed; //ppm
        int max_res; //dpi
        bool is_duplex;
        std::tuple<std::string, int> ink_or_toner; //(Ink/Toner, estimated page yield)
        std::tuple<double, double, double> dimensions; //(L, W, H) in mm
        double weight; //kg

    public:
        Printer();
        Printer(const int, const double);
        Printer(const std::string);

        void setType(const std::string);
        void setHasScanner(const bool);
        void setWireless(const bool);
        void setSpeed(const int);
        void setMaxRes(const int);
        void setDuplex(const bool);
        void setInkOrToner(const std::string, const int);
        void setDimensions(const double, const double, const double);
        void setWeight(const double);

        std::string getType() const;
        bool getHasScanner() const;
        bool getWireless() const;
        int getSpeed() const;
        int getMaxRes() const;
        bool getDuplex() const;
        std::tuple<std::string, int> getInkOrToner() const;
        std::tuple<double, double, double> getDimensions() const;
        double getWeight() const;

        static std::vector<Printer> printer_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Printer);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortSpeed();
        static void sortMaxRes();
        static void sortDimensions();
        static void sortWeight();

        static std::vector<Printer> filterBrand(const std::string);
        static std::vector<Printer> filterType(const std::string);
        static std::vector<Printer> filterHasScanner();
        static std::vector<Printer> filterWireless();
        static std::vector<Printer> filterDuplex();
        static std::vector<Printer> filterOnDisplay();

        // operator overloading
        Printer& operator=(const Printer&);
};

#endif