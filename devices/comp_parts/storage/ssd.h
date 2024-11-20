#ifndef SSD_H
#define SSD_H

#include "storage_parent.h"

class SSD : public Storage{
    private:
        const std::string id_start = "AH";
        int power_consumption;
    public:
        SSD();
        SSD(const int, const double);
        SSD(const std::string);

        void setPowerConsumption(const int);

        int getPowerConsumption() const;
        
        static std::vector<SSD> ssd_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const SSD);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortCapacity();
        static void sortSpeed();
        static void sortPowerConsumption();

        static std::vector<SSD> filterBrand(const std::string);
        static std::vector<SSD> filterOnDisplay();

        // Operator overloading
        SSD& operator=(const SSD&);
};

#endif