#ifndef EARPHONES_H
#define EARPHONES_H

#include "../peri_parent.h"

class Earphones : public Peripherals{
    private:
        const std::string id_start = "AP";
        bool has_volume_control;
        bool water_resistant;
        double wire_length;
    public:
        Earphones();
        Earphones(const int, const double);
        Earphones(const std::string);

        void setVolumeControl(const bool);
        void setWaterResistant(const bool);
        void setWireLength(const double);

        bool getVolumeControl() const;
        bool getWaterResistant() const;
        double getWireLength() const;

        static std::vector<Earphones> earphones_vec;
        void purchaseDevice(const unsigned int);       
        void generateId();
        static void updateVec(const Earphones);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortWireLength();

        static std::vector<Earphones> filterBrand(const std::string);
        static std::vector<Earphones> filterVolumeControl();
        static std::vector<Earphones> filterWaterResistant();
        static std::vector<Earphones> filterOnDisplay();

        // operator overloading
        Earphones& operator=(const Earphones&);

};

#endif