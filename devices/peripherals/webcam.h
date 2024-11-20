#ifndef WEBCAM_H
#define WEBCAM_H

#include "peri_parent.h"

class Webcam : public Peripherals {
    private:
        const std::string id_start = "AV";
        std::tuple<int, int> resolution;
        int fps;
        int field_of_view; //degrees
        bool has_microphone;
        std::tuple<double, double, double> dimensions;
    public:
        Webcam();
        Webcam(const int, const double);
        Webcam(const std::string);

        void setResolution(const int, const int);
        void setFps(const unsigned int);
        void setFieldOfView(const int);
        void setHasMicrophone(const bool);
        void setDimensions(const double, const double, const double);

        std::tuple<int, int> getResolution() const;
        int getFps() const;
        int getFieldOfView() const;
        bool getHasMicrophone() const;
        std::tuple<double, double, double> getDimensions() const;

        static std::vector<Webcam> webcam_vec;
        void purchaseDevice(const unsigned int);
        void generateId();
        static void updateVec(const Webcam);
        static void readData();


        // main sort & filter
        static void selectSortFilter();

        // sort & filter
        static void sortPrice();
        static void sortResolution();
        static void sortFps();
        static void sortFieldOfView();
        static void sortDimensions();

        static std::vector<Webcam> filterBrand(const std::string);
        static std::vector<Webcam> filterHasMicrophone();
        static std::vector<Webcam> filterOnDisplay();

        // operator overloading
        Webcam& operator=(const Webcam&);
};

#endif