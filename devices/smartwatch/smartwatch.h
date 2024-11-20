#ifndef SMARTWATCHES_H
#define SMARTWATCHES_H

#include "../devices.h"

class Smartwatch : public Devices {
    private:
        const std::string id_start = "BB";
        std::string display;
        bool sim;
        double bluetooth;
        double wifi;
        double capacity_GB;
        double screen_size_mm;
        double case_size_mm;
        double brightness_nits;
        double water_resistance_m;
        double battery_mAh;
        double weight_g;
        bool heartrate_monitoring;
        bool has_microphones;
        bool has_gps;
        bool has_blood_oxygen_sensor;
        bool has_speaker;

    public:
        Smartwatch();
        Smartwatch(const int, const double);
        Smartwatch(const std::string);

        void setDisplay(const std::string d);
        void setSim(const bool s);
        void setBluetooth(const double b);
        void setScreenSize(const double s);
        void setCaseSize(const double c);
        void setBrightness(const double b);
        void setWaterResistance(const double w);
        void setBattery(const double b);
        void setWeight(const double w);
        void setHeartrateMonitoring(const bool h);
        void setHasMicrophones(const bool h);
        void setWifi(const double w);
        void setCapacity(const double c);
        void setHasGps(const bool h);
        void setHasBloodOxygenSensor(const bool h);
        void setHasSpeaker(const bool h);

        std::string getDisplay() const;
        bool getSim() const;
        double getBluetooth() const;
        double getWifi() const;
        double getCapacity() const;
        double getScreenSize() const;
        double getCaseSize() const;
        double getBrightness() const;
        double getWaterResistance() const;
        double getBattery() const;
        double getWeight() const;
        bool getHeartrateMonitoring() const;
        bool getHasMicrophones() const;
        bool getHasGps() const;
        bool getHasBloodOxygenSensor() const;
        bool getHasSpeaker() const;
        
        static std::vector<Smartwatch> smartwatch_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Smartwatch);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortBluetooth();
        static void sortWifi();
        static void sortCapacity();
        static void sortScreenSize();
        static void sortCaseSize();
        static void sortBrightness();
        static void sortWaterResistance();
        static void sortBattery();
        static void sortWeight();

        static std::vector<Smartwatch> filterBrand(const std::string);
        static std::vector<Smartwatch> filterSim();
        static std::vector<Smartwatch> filterHeartrateMonitoring();
        static std::vector<Smartwatch> filterHasMicrophones();
        static std::vector<Smartwatch> filterHasGps();
        static std::vector<Smartwatch> filterHasBloodOxygenSensor();
        static std::vector<Smartwatch> filterHasSpeaker();
        static std::vector<Smartwatch> filterOnDisplay();

        // operator overloading
        Smartwatch& operator=(const Smartwatch&);

};

#endif