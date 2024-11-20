#ifndef MOUSE_H
#define MOUSE_H

#include "peri_parent.h"

class Mouse: public Peripherals {
    private:
        const std::string id_start = "AK";
        std::string type; //Gaming, Office, etc.
        std::string sensor; //Optical, Laser, etc.
        bool is_wireless;
        std::tuple<int, int> sensitivity; //(min, max) DPI
        double weight; //g
        double battery_life; //hours
        bool is_rechargeable;

    public:
        Mouse();
        Mouse(const int, const double);
        Mouse(const std::string);

        void setType(const std::string);
        void setSensor(const std::string);
        void setWireless(const bool);
        void setSensitivity(const int, const int);
        void setWeight(const double);
        void setBatteryLife(const double);
        void setRechargeable(const bool);

        std::string getType() const;
        std::string getSensor() const;
        bool getWireless() const;
        std::tuple<int, int> getSensitivity() const;
        double getWeight() const;
        double getBatteryLife() const;
        bool getRechargeable() const;

        static std::vector<Mouse> mouse_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Mouse);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortMaxSensitivity();
        static void sortDpiRange();
        static void sortWeight();
        static void sortBatteryLife();

        static std::vector<Mouse> filterBrand(const std::string);
        static std::vector<Mouse> filterType(const std::string);
        static std::vector<Mouse> filterSensor(const std::string);
        static std::vector<Mouse> filterWireless();
        static std::vector<Mouse> filterRechargeable();
        static std::vector<Mouse> filterOnDisplay();

        // operator overloading
        Mouse& operator=(const Mouse&);
};

#endif