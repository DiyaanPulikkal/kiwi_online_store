#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "comp_parts_parent.h"

class Motherboard : public ComputerParts{
    private:
        const std::string id_start = "AF";
        std::string form_factor;
        std::string socket;
        std::tuple<std::string, int> memory; //(type, capacity)
        std::string chipset;
        std::vector<std::string> expansion_slots;
        std::vector<std::string> connectivity;
        std::vector<std::string> storage; //list of (type, capacity)
        std::string audio;
        bool multi_gpu;
        std::string bios;
    public:
        Motherboard();
        Motherboard(const int q, const double p);
        Motherboard(const std::string);
        
        void setFormFactor(const std::string ff);
        void setSocket(const std::string s);
        void setMemory(const std::string t, const int c);
        void setChipset(const std::string c);
        void addExpansionSlots(const std::string es);
        void clearExpansionSlots();
        void addConnectivity(const std::string c);
        void clearConnectivity();
        void addStorage(const std::string t);
        void clearStorage();
        void setAudio(const std::string a);
        void setMultiGPU(const bool mg);
        void setBios(const std::string b);
        
        std::string getFormFactor() const;
        std::string getSocket() const;
        std::tuple<std::string, int> getMemory() const;
        std::string getChipset() const;
        std::vector<std::string> getExpansionSlots() const;
        std::vector<std::string> getConnectivity() const;
        std::vector<std::string> getStorage() const;
        std::string getAudio() const;
        bool getMultiGPU() const;
        std::string getBios() const;

        static std::vector<Motherboard> motherboard_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(Motherboard);
        static void readData();

        //main sort & filter
        static void selectSortFilter();

        //sort & filter
        static void sortPrice();

        static std::vector<Motherboard> filterBrand(const std::string);
        static std::vector<Motherboard> filterFormFactor(const std::string);
        static std::vector<Motherboard> filterSocket(const std::string);
        static std::vector<Motherboard> filterChipset(const std::string);
        static std::vector<Motherboard> filterExpansionSlots(const std::string);
        static std::vector<Motherboard> filterConnectivity(const std::string);
        static std::vector<Motherboard> filterMultiGPU(const bool);
        static std::vector<Motherboard> filterOnDisplay();

        // Operator overloading
        Motherboard& operator=(const Motherboard&);

};

#endif