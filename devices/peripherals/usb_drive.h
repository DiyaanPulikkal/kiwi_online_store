#ifndef USB_DRIVE_H
#define USB_DRIVE_H

#include "peri_parent.h"

class UsbDrive : public Peripherals {
    private:
        const std::string id_start = "AW";
        int capacity; //GB
        std::string interface; //USB 2.0, USB 3.0, etc.
        int transfer_speed; //MB/s
    public:
        UsbDrive();
        UsbDrive(const int, const double);
        UsbDrive(const std::string);

        void setCapacity(const unsigned int);
        void setInterface(const std::string);
        void setTransferSpeed(const int);

        int getCapacity() const;
        std::string getInterface() const;
        int getTransferSpeed() const;

        static std::vector<UsbDrive> usb_drive_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const UsbDrive);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortCapacity();
        static void sortTransferSpeed();

        static std::vector<UsbDrive> filterBrand(const std::string);
        static std::vector<UsbDrive> filterInterface(const std::string);
        static std::vector<UsbDrive> filterOnDisplay();

        // operator overloading
        UsbDrive& operator=(const UsbDrive&);
};

#endif