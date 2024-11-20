#ifndef GPU_H
#define GPU_H

#include "comp_parts_parent.h"

class GPU : public ComputerParts{
    private:
        const std::string id_start = "AB";
        double base_clock;
        double boost_clock;
        std::tuple<std::string, int, int> memory_support; // (type, VRAM(GB), BusWidth(Bit))
        std::vector<std::string> output_ports;
        std::tuple<double, int> power_consumption; // (watt, pin)
        std::string cooling_type;
        std::tuple<double, double, double> dimension;
        int kiwi_benchmark_score;
    public:
        GPU();
        GPU(const int, const double);
        GPU(const std::string);

        void setBaseClock(const double);
        void setBoostClock(const double);
        void setMemorySupport(const std::string, const int, const int);
        void addOutputPorts(const std::string);
        void setPowerConsumption(const double, const int);
        void setCoolingType(const std::string);
        void setDimension(const double, const double, const double);
        void setBenchmarkScore(const int);
        void clearOutputPorts();

        double getBaseClock() const;
        double getBoostClock() const;
        std::tuple<std::string, int, int> getMemorySupport() const;
        std::vector<std::string> getOutputPorts() const;
        std::tuple<double, int> getPowerConsumption() const;
        std::string getCoolingType() const;
        std::tuple<double, double, double> getDimension() const;
        int getBenchmarkScore() const;

        static std::vector<GPU> gpu_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const GPU);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortBaseClock();
        static void sortBoostClock();
        static void sortMemoryVRAM();
        static void sortMemoryBusWidth();
        static void sortPowerConsumption();
        static void sortBenchmarkScore();
        static void sortDimension();

        static std::vector<GPU> filterBrand(const std::string);
        static std::vector<GPU> filterCoolingType(const std::string);
        static std::vector<GPU> filterOutputPorts(const std::string);
        static std::vector<GPU> filterOnDisplay();

        // Operator overloading
        GPU& operator=(const GPU&);
};

#endif