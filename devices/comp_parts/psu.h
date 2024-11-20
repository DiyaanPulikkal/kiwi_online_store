#ifndef PSU_H
#define PSU_H

#include "comp_parts_parent.h"

class PSU : public ComputerParts{
    private:
        const std::string id_start = "AG";
        std::string form_factor;
        std::string efficiency;
        std::string modular;
        int wattage;
        std::tuple<std::string, int> fan; //(size, noise)
        std::tuple<double, double, double> dimension;
    public:
        PSU();
        PSU(const int q, const double p);
        PSU(const std::string);

        void setFormFactor(const std::string ff);
        void setEfficiency(const std::string e);
        void setModular(const std::string m);
        void setWattage(const int w);
        void setFan(const std::string size, const int noise);
        void setDimension(const double l, const double w, const double h);

        std::string getFormFactor() const;
        std::string getEfficiency() const;
        std::string getModular() const;
        int getWattage() const;
        std::tuple<std::string, int> getFan() const;
        std::tuple<double, double, double> getDimension() const;

        static std::vector<PSU> psu_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const PSU);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortWattage();
        static void sortDimension();
        static void sortEfficiency();
        static void sortFanNoise();

        static std::vector<PSU> filterBrand(const std::string);
        static std::vector<PSU> filterFormFactor(const std::string);
        static std::vector<PSU> filterModular(const std::string);
        static std::vector<PSU> filterOnDisplay();

        //operator overloading
        PSU& operator=(const PSU&);

};

#endif