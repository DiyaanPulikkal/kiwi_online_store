#ifndef MEMORY_H
#define MEMORY_H

#include "comp_parts_parent.h"

class Memory : public ComputerParts{
    private:
        const std::string id_start = "AC";
        std::string type;
        int capacity;
        int frequency;
        int latency;
        std::string form_factor;
        double voltage;
        bool has_ecc;
        std::string compatible_with;
    public:
        Memory();
        Memory(const int, const double);
        Memory(const std::string);
        
        void setType(const std::string);
        void setCapacity(const int);
        void setFrequency(const int);
        void setLatency(const int);
        void setFormFactor(const std::string);
        void setVoltage(const double);
        void setHasECC(const bool);
        void setCompatibleWith(const std::string);

        std::string getType() const;
        int getCapacity() const;
        int getFrequency() const;
        int getLatency() const;
        std::string getFormFactor() const;
        double getVoltage() const;
        bool getHasECC() const;
        std::string getCompatibleWith() const;

        static std::vector<Memory> memory_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Memory);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortCapacity();
        static void sortFrequency();
        static void sortLatency();
        static void sortVoltage();
        
        static std::vector<Memory> filterBrand(const std::string);
        static std::vector<Memory> filterType(const std::string);
        static std::vector<Memory> filterFormFactor(const std::string);
        static std::vector<Memory> filterHasECC(const bool);
        static std::vector<Memory> filterCompatibleWith(const std::string);
        static std::vector<Memory> filterOnDisplay();

        //operator overloading
        Memory& operator=(const Memory&);
};

#endif