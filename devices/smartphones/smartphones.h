#ifndef SMARTPHONES_H
#define SMARTPHONES_H

#include "../devices.h"

class Smartphones : public Devices{
    private:
        const std::string id_start = "BA";
        std::string display;
        std::tuple<int, int> resolution;
        std::string processor;
        std::string os;
        std::string charger;
        std::string camera_spec;
        int num_sim;
        std::tuple<double, double, double> dimensions;
        int storage;
        int refresh_rate;
        double wifi;
        double brightness_nits;
        double bluetooth;
        double weight_g;
        double battery_mAh;
        std::array<bool, 3> biometrics; // 0: fingerprint, 1: face, 2: iris
        bool have_microSD;
        bool have_jack;
        bool has_pen;
    public:
        Smartphones();
        Smartphones(const int, const double);
        Smartphones(const std::string);

        void setDisplay(const std::string);
        void setResolution(const int, const int);
        void setProcessor(const std::string);
        void setOS(const std::string);
        void setCharger(const std::string);
        void setCameraSpec(const std::string);
        void setNumSim(const int);
        void setDimensions(double, double, double);
        void setStorage(const int); 
        void setRefreshRate(const int);
        void setWifi(const double);
        void setBrightness(const double);
        void setBluetooth(const double);
        void setWeight(const double);
        void setBattery(const double);
        void setBiometrics(const bool, const bool, const bool); // 0: fingerprint, 1: face, 2: iris
        void setMicroSD(const bool);
        void setJack(const bool);
        void setHasPen(const bool);

        std::string getDisplay() const;
        std::tuple<int, int> getResolution() const;
        std::string getProcessor() const;
        std::string getOS() const;
        std::string getCharger() const;
        std::string getCameraSpec() const;
        int getNumSim() const;
        std::tuple<double, double, double> getDimensions() const;
        int getStorage() const;
        int getRefreshRate() const;
        double getWifi() const;
        double getBrightness() const;
        double getBluetooth() const;
        double getWeight() const;
        double getBattery() const;
        std::array<bool, 3> getBiometrics() const;
        bool getMicroSD() const;
        bool getJack() const;
        bool getHasPen() const;

        static std::vector<Smartphones> smartphones_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(Smartphones);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortResolution();
        static void sortDimensions();
        static void sortStorage();
        static void sortRefreshRate();
        static void sortWifi();
        static void sortBrightness();
        static void sortBluetooth();
        static void sortWeight();
        static void sortBattery();

        static std::vector<Smartphones> filterBrand(const std::string);
        static std::vector<Smartphones> filterOS(const std::string);
        static std::vector<Smartphones> filterFingerprint();
        static std::vector<Smartphones> filterFace();
        static std::vector<Smartphones> filterIris();
        static std::vector<Smartphones> filterMicroSD();
        static std::vector<Smartphones> filterJack();
        static std::vector<Smartphones> filterPen();
        static std::vector<Smartphones> filterOnDisplay();

        // operator overloading
        Smartphones& operator=(const Smartphones&);
};

#endif 
