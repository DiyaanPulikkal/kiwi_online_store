#ifndef CONSOLE_H
#define CONSOLE_H

#include "../devices.h"

class Console : public Devices{
    private:
        std::tuple<int, int> resolution;
        std::string main_processor;
        std::string graphics_processor;
        int storage_capacity;
        std::string USB;
        std::string display;
        std::string input_output_port;
        std::string wifi;
        double weight;
        std::string bluetooth;
        double power_consumption;
        bool controller_vibration;
        bool TV_mode;

    public:
        Console();
        Console(const int q, const double p);

        std::tuple<int, int> getResolution() const;
        std::string getMainProcessor() const;
        std::string getGraphicsProcessor() const;
        int getStorageCapacity() const;
        std::string getUSB() const;
        std::string getDisplay() const;
        std::string getInputOutputPort() const;
        std::string getWifi() const;
        double getWeight() const;
        std::string getBluetooth() const;
        double getPowerConsumption() const;
        bool getControllerVibration() const;
        bool getTVMode() const;
        
        void setResolution(const int, const int);
        void setMainProcessor(const std::string);
        void setGraphicsProcessor(const std::string);
        void setStorageCapacity(const int s);
        void setUSB(const std::string);
        void setDisplay(const std::string);
        void setInputOutputPort(const std::string);
        void setWifi(const std::string);
        void setWeight(const double);
        void setBluetooth(const std::string);
        void setControllerVibration(const bool);
        void setTVMode(const bool);
        void setPowerConsumption(const double);
};

#endif