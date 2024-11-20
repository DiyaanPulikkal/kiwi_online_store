#ifndef DISPLAY_H
#define DISPLAY_H

#include "peri_parent.h"

class Display : public Peripherals {
    private:
        const std::string id_start = "AN";
        std::tuple<int, int> resolution; //px
        int refresh_rate; //Hz
        std::tuple<double, double> dimensions; //inches
        bool hdr_supported;
        int response_time; //ms
    public:
        Display();
        Display(const int, const double);
        Display(const std::string);

        void setResolution(const int, const int);
        void setRefreshRate(const int);
        void setDimensions(const double, const double);
        void setHDR(const bool);
        void setResponseTime(const int);

        std::tuple<int, int> getResolution() const;
        int getRefreshRate() const;
        std::tuple<double, double> getDimensions() const;
        bool getHDR() const;
        int getResponseTime() const;

        static std::vector<Display> display_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Display);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortResolution();
        static void sortRefreshRate();
        static void sortDimensions();
        static void sortResponseTime();

        static std::vector<Display> filterBrand(const std::string);
        static std::vector<Display> filterHDR();
        static std::vector<Display> filterOnDisplay();

        // operator overloading
        Display& operator=(const Display&);
};

#endif