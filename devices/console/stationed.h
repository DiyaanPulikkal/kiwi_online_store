#ifndef STATIONED_H
#define STATIONED_H

#include "console.h"

class Stationed : public Console {
    private:
        const std::string id_start = "BC";
        std::string ssd;
        std::string size;

    public:
        Stationed();
        Stationed(const int, const double);
        Stationed(const std::string);
        
        std::string getSSD() const;
        std::string getSize() const;

        void setSSD(const std::string);
        void setSize(const std::string);

        static std::vector<Stationed> stationed_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Stationed);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortResolution();
        static void sortStorageCapacity();
        static void sortPowerConsumption();

        static std::vector<Stationed> filterBrand(const std::string);
        static std::vector<Stationed> filterWifi(const std::string);
        static std::vector<Stationed> filterControllerVibration(const bool);
        static std::vector<Stationed> filterTVMode(const bool);
        static std::vector<Stationed> filterOnDisplay();

        // Overloaded operators
        Stationed& operator=(const Stationed&);

};

#endif