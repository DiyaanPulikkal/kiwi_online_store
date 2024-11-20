#ifndef EARBUDS_H
#define EARBUDS_H

#include "../peri_parent.h"

class Earbuds : public Peripherals
{
    private:
        const std::string id_start = "AO";
        double battery_life;
        bool has_anc;
        bool water_resistant;
    public:
        Earbuds();
        Earbuds(const int, const double);
        Earbuds(const std::string);

        void setBatteryLife(const double);
        void setANC(const bool);
        void setWaterResistant(const bool);

        double getBatteryLife() const;
        bool getANC() const;
        bool getWaterResistant() const;

        static std::vector<Earbuds> earbuds_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Earbuds);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortBatteryLife();

        static std::vector<Earbuds> filterBrand(const std::string);
        static std::vector<Earbuds> filterANC();
        static std::vector<Earbuds> filterWaterResistant();
        static std::vector<Earbuds> filterOnDisplay();

        // operator overloading
        Earbuds& operator=(const Earbuds&);
};

#endif 