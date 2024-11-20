#ifndef CPU_H
#define CPU_H

#include "comp_parts_parent.h"

class CPU : public ComputerParts{
    private:
        const std::string id_start = "AA";
        std::string socket;
        std::string form_factor;
        int core_no;
        int thread_no;
        double base_clock;
        double boost_clock;
        bool has_overclock;
        std::tuple<std::string, int, int> memory_support; // (type, freq, no.)
        std::string integrated_graphics;

    public:
        CPU();
        CPU(const int q, const double p);
        CPU(const std::string);

        void setSocket(const std::string);
        void setFormFactor(const std::string);
        void setCoreNo(const int);
        void setThreadNo(const int);
        void setBaseClock(const double);
        void setBoostClock(const double);
        void setHasOverclock(const bool);
        void setMemorySupport(const std::string, const int, const int);
        void setIntegratedGraphics(const std::string);

        std::string getSocket() const;
        std::string getFormFactor() const;
        int getCoreNo() const;
        int getThreadNo() const;
        double getBaseClock() const;
        double getBoostClock() const;
        bool getHasOverclock() const;
        std::tuple<std::string, int, int> getMemorySupport() const;
        std::string getIntegratedGraphics() const;

        static std::vector<CPU> cpu_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const CPU);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();
        static void sortCoreNo();
        static void sortThreadNo();
        static void sortBaseClock();
        static void sortBoostClock();
        static void sortMemoryFreq();
        static void sortMemoryNo();

        static std::vector<CPU> filterBrand(const std::string);
        static std::vector<CPU> filterSocket(const std::string);
        static std::vector<CPU> filterFormFactor(const std::string);
        static std::vector<CPU> filterOverclock(const bool);
        static std::vector<CPU> filterMemoryType(const std::string);
        static std::vector<CPU> filterIntegratedGraphics(const std::string);
        static std::vector<CPU> filterOnDisplay();

        // Operator overloading
        CPU& operator=(const CPU&);
};
#endif