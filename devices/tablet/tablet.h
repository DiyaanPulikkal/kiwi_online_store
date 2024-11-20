#ifndef TABLET_H
#define TABLET_H

#include "../devices.h"

class Tablet : public Devices {
    private:
        const std::string id_start = "BD";
        std::string display;
        std::string processor;
        std::string os;
        std::string storage;
        std::string camera;
        double battery_mAh;
        std::string bluetooth;
        std::tuple<int, int> resolution;
        std::tuple<double, double, double> dimensions;
        double weight_g;
        double brightness_nits;
        std::string wifi;
        bool have_pen;
        std::string Internal_Memory;
        std::string External_Memory;
        std::string speaker;
        std::array<bool, 3> biometrics; // 0: fingerprint, 1: iris, 2: face
        bool is_waterproof;

    public:
        Tablet();
        Tablet(const int, const double);
        Tablet(const std::string);

        void setDisplay(const std::string d);
        void setProcessor(const std::string p);
        void setOs(const std::string o);
        void setStorage(const std::string s);
        void setCamera(const std::string c);
        void setBattery(double b);
        void setBluetooth(const std::string b);
        void setResolution(const int w, const int h);
        void setDimensions(const double l, const double w, const double h);
        void setWeight(const double w);
        void setBrightness(const double b);
        void setWifi(const std::string w);
        void setHavePen(const bool h);
        void setInternal_Memory(const std::string h);
        void setExternal_Memory(const std::string h);
        void setSpeaker(const std::string s);
        void setBiometrics(const bool fin, const bool i, const bool f);
        void setIsWaterproof(const bool w);

        std::string getDisplay() const;
        std::string getProcessor() const;
        std::string getOs() const;
        std::string getStorage() const;
        std::string getCamera() const;
        double getBattery() const;
        std::string getBluetooth() const;
        std::tuple<int, int> getResolution() const;
        std::tuple<double, double, double> getDimensions() const;
        double getWeight() const;
        double getBrightness() const;
        std::string getWifi() const;
        bool getHavePen() const;
        std::string getInternal_Memory() const;
        std::string getExternal_Memory() const;
        std::string getSpeaker() const;
        std::array<bool, 3> getBiometrics() const;
        bool getIsWaterproof() const;

        static std::vector<Tablet> tablet_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Tablet);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortBattery();
        static void sortResolution();
        static void sortDimensions();
        static void sortWeight();
        static void sortBrightness();

        static void filterBrand(const std::string);
        static void filterOs(const std::string);
        static void filterWifi(const std::string);
        static void filterBluetooth(const std::string);
        static void filterWaterproof();
        static void filterPen();
        static void filterFingerprint();
        static void filterFace();
        static void filterIris();
        static void filterOnDisplay();

        // operator overloading
        Tablet& operator=(const Tablet&);

        
};

#endif