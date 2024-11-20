#ifndef LAPTOP_H
#define LAPTOP_H

#include "../devices.h"

class Laptop : public Devices{
    private:
        const std::string id_start = "BE";
        std::string cpu;
        std::string gpu;
        std::string memory;
        std::vector<std::string> storage;
        std::string os;
        std::string display;
        std::tuple<double, int> battery; // capacity in Wh, number of cells
        std::tuple<double, double, double, double> dimensions; // length, width, height, diagonal in inches
        double weight; // in kg
        bool is_touchscreen;
        bool is_gaming;
              
    public:
        Laptop();
        Laptop(const int, const double);
        Laptop(const std::string);

        void setCPU(const std::string);
        void setGPU(const std::string);
        void setMemory(const std::string);
        void addStorage(const std::string);
        void clearStorage();
        void setOS(const std::string);
        void setDisplay(const std::string);
        void setBattery(const double, const int);
        void setDimensions(const double, const double, const double, const double);
        void setWeight(const double);
        void setTouchscreen(const bool);
        void setGaming(const bool);

        std::string getCPU() const;
        std::string getGPU() const;
        std::string getMemory() const;
        std::vector<std::string> getStorage() const;
        std::string getOS() const;
        std::string getDisplay() const;
        std::tuple<double, int> getBattery() const;
        std::tuple<double, double, double, double> getDimensions() const;
        double getWeight() const;
        bool getTouchscreen() const;
        bool getGaming() const;
        
        static std::vector<Laptop> laptop_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Laptop);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortBattery();
        static void sortDimensions();
        static void sortWeight();

        static std::vector<Laptop> filterBrand(const std::string);
        static std::vector<Laptop> filterCPU(const std::string);
        static std::vector<Laptop> filterGPU(const std::string);
        static std::vector<Laptop> filterOS(const std::string);
        static std::vector<Laptop> filterTouchscreen(const bool);
        static std::vector<Laptop> filterGaming(const bool);
        static std::vector<Laptop> filterOnDisplay();

        // Overloaded operators
        Laptop& operator=(const Laptop&);
};

#endif