#ifndef PCCASE_H
#define PCCASE_H

#include "comp_parts_parent.h"

class PCCase : public ComputerParts{
    private:
        const std::string id_start = "AE";
        std::string form_factor;
        std::tuple<double, double, double> dimension;
        std::string cooling_type;
        double max_gpu_length;
        double max_cpu_height;
        std::array<std::tuple<std::string, int>, 3> fan_support; //(size, noise)
    public:
        PCCase();
        PCCase(const int, const double);
        PCCase(const std::string);

        void setFormFactor(const std::string);
        void setDimension(const double, const double, const double);
        void setCoolingType(const std::string);
        void setMaxGPULength(const double);
        void setMaxCPUHeight(const double);
        void setFanSupport(const int, const std::string, const int);

        std::string getFormFactor() const;
        std::tuple<double, double, double> getDimension() const;
        std::string getCoolingType() const;
        double getMaxGPULength() const;
        double getMaxCPUHeight() const;
        std::array<std::tuple<std::string, int>, 3> getFanSupport() const;

        static std::vector<PCCase> pc_case_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const PCCase);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortDimension();
        static void sortMaxGPULength();
        static void sortMaxCPUHeight();

        static std::vector<PCCase> filterBrand(const std::string);
        static std::vector<PCCase> filterFormFactor(const std::string);
        static std::vector<PCCase> filterCoolingType(const std::string);
        static std::vector<PCCase> filterOnDisplay();

        //operator overloading
        PCCase& operator=(const PCCase&);


};

#endif