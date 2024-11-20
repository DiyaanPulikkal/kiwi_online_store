#ifndef DEV_H
#define DEV_H

#include "../logic_classes.h"
#include <filesystem>

class Dev{
    private:
        const std::vector<std::tuple<std::string, std::string>> dev_credentials = {
            {"admin", "admin"},
            {"root", "root"},
            {"dev", "dev"}
        };
    public:
        Dev();

        bool verify(const std::string, const std::string) const;
        
        void addCPU() const;
        void addGPU() const;
        void addMemory() const;
        void addMotherboard() const;
        void addCase() const;
        void addPSU() const;
        void addHDD() const;
        void addSSD() const;
        void addCooling_U() const;
        void addHandheld() const;
        void addStationed() const;
        void addDesktop() const;
        void addLaptop() const;
        void addEarbuds() const;
        void addEarphones() const;
        void addHeadphones() const;
        void addHeadset() const;
        void addMicrophone() const;
        void addSpeakers() const;
        void addDisplay() const;
        void addKeyboard() const;
        void addMouse() const;
        void addPortable_HDD() const;
        void addPrinter() const;
        void addSD_Card() const;
        void addTouchpad() const;
        void addUSB_Drive() const;
        void addWebcam() const;
        void addWire() const;
        void addSmartphones() const;
        void addSmartwatch() const;
        void addTablet() const;
        void addVR() const;

        void removeDevice(const std::string) const;
        void putOnDisplay(const std::string) const;
        void removeFromDisplay(const std::string) const;
};

#endif