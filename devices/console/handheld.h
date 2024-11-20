#ifndef HANDHELD_H
#define HANDHELD_H


#include "console.h"

class Handheld : public Console {
    private:
        const std::string id_start = "BH";
        std::string battery;
        std::string power_supply;
        std::string headphone_jack;
        int microSD_slot;
        std::string size;
    public:
        Handheld();
        Handheld(const int, const double);
        Handheld(const std::string);
        
        std::string getBattery() const;
        std::string getPowerSupply() const;
        std::string getHeadphoneJack() const;
        int getMicroSDSlot() const;
        std::string getSize() const;

        void setBattery(const std::string);
        void setPowerSupply(const std::string);
        void setHeadphoneJack(const std::string);
        void setMicroSDSlot(const int);
        void setSize(const std::string);

        static std::vector<Handheld> handheld_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(Handheld);
        static void readData();

        // main sort & filter 
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortResolution();
        static void sortStorageCapacity();
        static void sortWeight();
        static void sortPowerConsumption();

        static std::vector<Handheld> filterBrand(const std::string);
        static std::vector<Handheld> filterWifi(const std::string);
        static std::vector<Handheld> filterControllerVibration(const bool);
        static std::vector<Handheld> filterTVMode(const bool);
        static std::vector<Handheld> filterOnDisplay();

        // Overloaded operators
        Handheld& operator=(const Handheld&);
};
        
#endif