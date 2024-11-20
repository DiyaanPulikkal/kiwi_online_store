#ifndef HEADPHONES_H
#define HEADPHONES_H

#include "../peri_parent.h"

class Headphones : public Peripherals{
    private:
        const std::string id_start = "AR";
        bool has_anc;
        bool is_wireless;
        bool surround_sound;
    public:
        Headphones();
        Headphones(const int, const double);
        Headphones(const std::string);

        void setANC(const bool);
        void setWireless(const bool);
        void setSurroundSound(const bool);

        bool getANC() const;
        bool getWireless() const;
        bool getSurroundSound() const;

        static std::vector<Headphones> headphones_vec;
        void purchaseDevice(const unsigned int);        
        void generateId();
        static void updateVec(const Headphones);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();

        static std::vector<Headphones> filterBrand(const std::string);
        static std::vector<Headphones> filterANC();
        static std::vector<Headphones> filterWireless();
        static std::vector<Headphones> filterSurroundSound();
        static std::vector<Headphones> filterOnDisplay();

        // operator overloading
        Headphones& operator=(const Headphones&);
};

#endif