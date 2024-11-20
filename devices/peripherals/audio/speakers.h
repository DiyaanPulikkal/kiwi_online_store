#ifndef SPEAKERS_H
#define SPEAKERS_H

#include "../peri_parent.h"

class Speakers : public Peripherals{
    private:
        const std::string id_start = "AS";
        double power_output; // watts
        double configuration; // 2.1, 5.1, 7.1, etc
        bool is_wireless;
        double battery_life; // hours
    public:
        Speakers();
        Speakers(const int, const double);
        Speakers(const std::string);

        void setPowerOutput(const double);
        void setConfiguration(const double);
        void setWireless(const bool);
        void setBatteryLife(const double);

        double getPowerOutput() const;
        double getConfiguration() const;
        bool getWireless() const;
        double getBatteryLife() const;

        static std::vector<Speakers> speakers_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Speakers);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortPowerOutput();
        static void sortConfiguration();
        static void sortBatteryLife();
        
        static std::vector<Speakers> filterBrand(const std::string);
        static std::vector<Speakers> filterWireless();
        static std::vector<Speakers> filterOnDisplay();

        // operator overloading
        Speakers& operator=(const Speakers&);

};

#endif