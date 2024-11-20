#ifndef STORAGE_H
#define STORAGE_H

#include "../comp_parts_parent.h"

class Storage : public ComputerParts{
    private:
        int storage_capacity;
        int storage_speed;
        std::string interface;
        std::string form_factor;
    public:
        Storage();
        Storage(const int, const double);

        void setStorageCapacity(const int);
        void setStorageSpeed(const int);
        void setInterface(const std::string);
        void setFormFactor(const std::string);
    
        int getStorageCapacity() const;
        int getStorageSpeed() const;
        std::string getInterface() const;
        std::string getFormFactor() const;
};

#endif
