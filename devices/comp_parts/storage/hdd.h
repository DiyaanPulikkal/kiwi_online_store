#ifndef HDD_H
#define HDD_H

#include "storage_parent.h"

class HDD : public Storage{
    private:
        const std::string id_start = "AI";
        int rotation_speed; //rpm
        int cache; //MB
        std::tuple<double, double, double> power_consumption; //idle, read, write
    public:
        HDD();
        HDD(const int, const double);
        HDD(const std::string);

        void setRotationSpeed(const int);
        void setCache(const int);
        void setPowerConsumption(const double, const double, const double);
        
        int getRotationSpeed() const;
        int getCache() const;
        std::tuple<double, double, double> getPowerConsumption() const;
        
        static std::vector<HDD> hdd_vec;
        void purchaseDevice(unsigned int);
        void generateId();
        static void updateVec(const HDD);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort (ascending) & filter 
        static void sortPrice();
        static void sortCapacity();
        static void sortSpeed();
        static void sortRotationSpeed();
        static void sortCache();
        static void sortIdlePower();
        static void sortReadPower();
        static void sortWritePower();

        static std::vector<HDD> filterBrand(const std::string); 
        static std::vector<HDD> filterOnDisplay();    

        // Operator overloading
        HDD& operator=(const HDD&);    
};
#endif