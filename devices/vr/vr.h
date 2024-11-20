#ifndef VR_H
#define VR_H

#include "../devices.h"

class VR : public Devices {
private:
    const std::string id_start = "AZ";
    std::tuple<int, int> resolution;
    bool with_controllers;
    std::string display;
    std::string type_USB_cable;
    int max_refresh_rate;
    double field_of_view;
    double size_display_inch;

public:
    VR();
    VR(const int, const double);
    VR(const std::string);

    void setResolution(const int x, const int y);
    void setWithControllers(const bool w);
    void setDisplay(const std::string d);
    void setUsbCable(const std::string u);
    void setRefreshRate(const int r);
    void setFieldOfView(const double f);
    void setSizeDisplayInch(const double s);

    std::tuple<int, int> getResolution() const;
    bool getWithControllers() const;
    std::string getDisplay() const;
    std::string getHaveUsbCable() const;
    int getRefreshRate() const;
    double getFieldOfView() const;
    double getSizeDisplayInch() const;

    static std::vector<VR> vr_vec;
    void purchaseDevice(const unsigned int);    
    void generateId();
    static void updateVec(const VR);
    static void readData();

    // main sort & filter
    static void selectSortFilter();

    // sort & filter
    static void sortPrice();
    static void sortResolution();
    static void sortRefreshRate();
    static void sortFieldOfView();
    static void sortSizeDisplayInch();

    static std::vector<VR> filterBrand(const std::string);
    static std::vector<VR> filterWithControllers();
    static std::vector<VR> filterOnDisplay();

    // operator overloading
    VR& operator=(const VR&);

};

#endif

