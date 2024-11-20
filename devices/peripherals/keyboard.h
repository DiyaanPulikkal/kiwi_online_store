#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "peri_parent.h"

class Keyboard : public Peripherals {
    private:
        const std::string id_start = "AL";
        std::string type; //Mechanical, Membrane, etc.
        std::string layout; //QWERTY, AZERTY, etc.
        bool is_backlit;
        bool is_wireless;
        std::string key_switch; //Cherry MX, Romer-G, etc.
    public:
        Keyboard();
        Keyboard(const int, const double);
        Keyboard(const std::string);

        void setType(const std::string);
        void setLayout(const std::string);
        void setBacklit(const bool);
        void setWireless(const bool);
        void setKeySwitch(const std::string);

        std::string getType() const;
        std::string getLayout() const;
        bool getBacklit() const;
        bool getWireless() const;
        std::string getKeySwitch() const;

        static std::vector<Keyboard> keyboard_vec;
        void purchaseDevice(const unsigned int);        
        void generateId();
        static void updateVec(const Keyboard);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        
        static std::vector<Keyboard> filterBrand(const std::string);
        static std::vector<Keyboard> filterType(const std::string);
        static std::vector<Keyboard> filterLayout(const std::string);
        static std::vector<Keyboard> filterBacklit();
        static std::vector<Keyboard> filterWireless();
        static std::vector<Keyboard> filterKeySwitch(const std::string);
        static std::vector<Keyboard> filterOnDisplay();

        // operator overloading
        Keyboard& operator=(const Keyboard&);
};

#endif