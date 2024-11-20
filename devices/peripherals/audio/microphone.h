#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "../peri_parent.h"

class Microphone : public Peripherals{
    private:
        const std::string id_start = "AT";
        std::string directionality;
        bool has_usb;
        bool has_xlr;
    public:
        Microphone();
        Microphone(const int, const double);
        Microphone(const std::string);

        void setDirectionality(const std::string);
        void setUSB(const bool);
        void setXLR(const bool);

        std::string getDirectionality() const;
        bool getUSB() const;
        bool getXLR() const;

        static std::vector<Microphone> microphone_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Microphone);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();

        static std::vector<Microphone> filterBrand(const std::string);
        static std::vector<Microphone> filterDirectionality(const std::string);
        static std::vector<Microphone> filterUSB();
        static std::vector<Microphone> filterXLR();
        static std::vector<Microphone> filterOnDisplay();

        // operator overloading
        Microphone& operator=(const Microphone&);        
};

#endif