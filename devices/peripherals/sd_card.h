#ifndef SD_CARD_H
#define SD_CARD_H

#include "peri_parent.h"

class SdCard : public Peripherals {
    private:
        const std::string id_start = "AY";
        std::string type; //SD, MicroSD, etc.
        int capacity; //GB
        int speed; //MB/s
        std::string class_rating; //Class 4, UHS-I, etc.
        std::string form_factor; //Standard, Mini, Micro, etc.

    public:
        SdCard();
        SdCard(const int, const double);
        SdCard(const std::string);

        void setType(const std::string);
        void setCapacity(const unsigned int);
        void setSpeed(const unsigned int);
        void setClassRating(const std::string);
        void setFormFactor(const std::string);

        std::string getType() const;
        int getCapacity() const;
        int getSpeed() const;
        std::string getClassRating() const;
        std::string getFormFactor() const;

        static std::vector<SdCard> sd_card_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const SdCard);
        static void readData();

        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortCapacity();
        static void sortSpeed();

        static std::vector<SdCard> filterBrand(const std::string);
        static std::vector<SdCard> filterType(const std::string);
        static std::vector<SdCard> filterClassRating(const std::string);
        static std::vector<SdCard> filterFormFactor(const std::string);
        static std::vector<SdCard> filterOnDisplay();

        // operator overloading
        SdCard& operator=(const SdCard&);
};

#endif