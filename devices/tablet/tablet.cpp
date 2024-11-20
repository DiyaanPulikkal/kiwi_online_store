#include "tablet.h"

Tablet::Tablet(): Devices(){
    display = "-";
    processor = "-";
    os = "-";
    storage = "-";
    camera = "-";
    battery_mAh = 0.0;
    bluetooth = "-";
    resolution = std::make_tuple(0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight_g = 0.0;
    brightness_nits = 0.0;
    wifi = "-";
    have_pen = false;
    Internal_Memory = "-";
    External_Memory = "-";
    camera = "-";
    is_waterproof = false;
    biometrics = {false, false, false};
    generateId();
};

Tablet::Tablet(const int q, const double p) : Devices(q, p){
    display = "-";
    processor = "-";
    os = "-";
    storage = "-";
    camera = "-";
    battery_mAh = 0.0;
    bluetooth = "-";
    resolution = std::make_tuple(0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight_g = 0.0;
    brightness_nits = 0.0;
    wifi = "-";
    have_pen = false;
    Internal_Memory = "-";
    External_Memory = "-";
    camera = "-";
    is_waterproof = false;
    biometrics = {false, false, false};
    generateId();
}

Tablet::Tablet(const std::string s) : Devices(){
    display = s;
    processor = "-";
    os = "-";
    storage = "-";
    camera = "-";
    battery_mAh = 0.0;
    bluetooth = "-";
    resolution = std::make_tuple(0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight_g = 0.0;
    brightness_nits = 0.0;
    wifi = "-";
    have_pen = false;
    Internal_Memory = "-";
    External_Memory = "-";
    camera = "-";
    is_waterproof = false;
    biometrics = {false, false, false};
}

std::string Tablet::getSpeaker() const {
    return speaker;
}

std::string Tablet::getDisplay() const {
    return display;
}

std::string Tablet::getProcessor() const {
    return processor;
}

std::string Tablet::getOs() const {
    return os;
}

std::string Tablet::getStorage() const {
    return storage;
}

std::string Tablet::getCamera() const {
    return camera;
}

double Tablet::getBattery() const {
    return battery_mAh;
}

std::string Tablet::getBluetooth() const {
    return bluetooth;
}

std::tuple<int, int> Tablet::getResolution() const {
    return resolution;
}

std::tuple<double, double, double> Tablet::getDimensions() const {
    return dimensions;
}

double Tablet::getWeight() const {
    return weight_g;
}

double Tablet::getBrightness() const {
    return brightness_nits;
}

std::string Tablet::getWifi() const {
    return wifi;
}

bool Tablet::getHavePen() const {
    return have_pen;
}

std::string Tablet::getInternal_Memory() const {
    return Internal_Memory;
}

std::string Tablet::getExternal_Memory() const {
    return External_Memory;
}

bool Tablet::getIsWaterproof() const {
    return is_waterproof;
}

std::array<bool, 3> Tablet::getBiometrics() const {
    return biometrics;
}

void Tablet::setDisplay(const std::string d) {
    display = d;
}

void Tablet::setProcessor(const std::string p) {
    processor = p;
}

void Tablet::setOs(const std::string o) {
    os = o;
}

void Tablet::setStorage(const std::string s) {
    storage = s;
}

void Tablet::setBattery(const double b) {
    battery_mAh = b;
}

void Tablet::setBluetooth(const std::string b) {
    bluetooth = b;
}

void Tablet::setResolution(const int w, const int h) {
    resolution = std::make_tuple(w, h);
}

void Tablet::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Tablet::setWeight(const double w) {
    weight_g = w;
}
void Tablet::setBrightness(const double b) {
    brightness_nits = b;
}

void Tablet::setWifi(const std::string w) {
    wifi = w;
}

void Tablet::setHavePen(const bool h) {
    have_pen = h;
}

void Tablet::setInternal_Memory(const std::string m) {
    Internal_Memory = m;
}

void Tablet::setExternal_Memory(const std::string m) {
    External_Memory = m;
}

void Tablet::setIsWaterproof(const bool w) {
    is_waterproof = w;
}

void Tablet::setCamera(const std::string c) {
    camera = c;
}

void Tablet::setSpeaker(const std::string s) {
    speaker = s;
}

void Tablet::setBiometrics(const bool fin, const bool i, const bool f) {
    biometrics = {fin, i, f};
}

void Tablet::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Tablet::generateId() {
    std::ifstream file_in("../txt_files/tablet.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Tablet& tablet: tablet_vec){
            std::string id = tablet.getID(); // AZ0001
            std::string id_num = id.substr(2); // 0001
            unsigned int id_num_int = std::stoi(id_num);
            if (id_num_int > max_id){
                max_id = id_num_int;
            }
        }
        unsigned int no_of_zeros = 4 - std::to_string(max_id).length();
        std::string id = id_start;
        for (unsigned int i = 0; i < no_of_zeros; i++){
            id += "0";
        }
        id += std::to_string(max_id + 1);
        setID(id);
    }
    file_in.close();
    tablet_vec.push_back(*this);
    std::ofstream file_out("../txt_files/tablet.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Tablet& tablet: tablet_vec){
        file_out << tablet.getID() << "|";
        file_out << tablet.getDescription() << "|";
        file_out << tablet.getBrand() << "|";
        file_out << tablet.getModel() << "|";
        file_out << tablet.getPrice() << "|";
        file_out << tablet.getQuantity() << "|";
        file_out << tablet.getDisplay() << "|";
        file_out << tablet.getDisplay() << "|";
        file_out << tablet.getProcessor() << "|";
        file_out << tablet.getOs() << "|";
        file_out << tablet.getStorage() << "|";
        file_out << tablet.getCamera() << "|";
        file_out << tablet.getBattery() << "|";
        file_out << tablet.getBluetooth() << "|";
        file_out << std::get<0>(tablet.getResolution()) << "|" << std::get<1>(tablet.getResolution()) << "|";
        file_out << std::get<0>(tablet.getDimensions()) << "|" << std::get<1>(tablet.getDimensions()) << "|" << std::get<2>(tablet.getDimensions()) << "|";
        file_out << tablet.getWeight() << "|";
        file_out << tablet.getBrightness() << "|";
        file_out << tablet.getWifi() << "|";
        file_out << tablet.getHavePen() << "|";
        file_out << tablet.getInternal_Memory() << "|";
        file_out << tablet.getExternal_Memory() << "|";
        file_out << tablet.getSpeaker() << "|";
        file_out << tablet.getBiometrics()[0] << "|" << tablet.getBiometrics()[1] << "|" << tablet.getBiometrics()[2] << "|";
        file_out << tablet.getIsWaterproof() << "|";
        file_out << tablet.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    
    return;
}

void Tablet::updateVec(const Tablet tablet_in) {
    for (Tablet& tablet: tablet_vec){
        if (tablet.getID() == tablet_in.getID()){
            tablet.setDescription(tablet_in.getDescription());
            tablet.setBrand(tablet_in.getBrand());
            tablet.setModel(tablet_in.getModel());
            tablet.setPrice(tablet_in.getPrice());
            tablet.setQuantity(tablet_in.getQuantity());
            tablet.setOnDisplay(tablet_in.getOnDisplay());
            tablet.setDisplay(tablet_in.getDisplay());
            tablet.setProcessor(tablet_in.getProcessor());
            tablet.setOs(tablet_in.getOs());
            tablet.setStorage(tablet_in.getStorage());
            tablet.setCamera(tablet_in.getCamera());
            tablet.setBattery(tablet_in.getBattery());
            tablet.setBluetooth(tablet_in.getBluetooth());
            tablet.setResolution(std::get<0>(tablet_in.getResolution()), std::get<1>(tablet_in.getResolution()));
            tablet.setDimensions(std::get<0>(tablet_in.getDimensions()), std::get<1>(tablet_in.getDimensions()), std::get<2>(tablet_in.getDimensions()));
            tablet.setWeight(tablet_in.getWeight());
            tablet.setBrightness(tablet_in.getBrightness());
            tablet.setWifi(tablet_in.getWifi());
            tablet.setHavePen(tablet_in.getHavePen());
            tablet.setInternal_Memory(tablet_in.getInternal_Memory());
            tablet.setExternal_Memory(tablet_in.getExternal_Memory());
            tablet.setSpeaker(tablet_in.getSpeaker());
            tablet.setBiometrics(tablet_in.getBiometrics()[0], tablet_in.getBiometrics()[1], tablet_in.getBiometrics()[2]);
            tablet.setIsWaterproof(tablet_in.getIsWaterproof());
            tablet.setImagePath(tablet_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/tablet.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Tablet& tablet: tablet_vec){
        file_out << tablet.getID() << "|";
        file_out << tablet.getDescription() << "|";
        file_out << tablet.getBrand() << "|";
        file_out << tablet.getModel() << "|";
        file_out << tablet.getPrice() << "|";
        file_out << tablet.getQuantity() << "|";
        file_out << tablet.getOnDisplay() << "|";
        file_out << tablet.getDisplay() << "|";
        file_out << tablet.getProcessor() << "|";
        file_out << tablet.getOs() << "|";
        file_out << tablet.getStorage() << "|";
        file_out << tablet.getCamera() << "|";
        file_out << tablet.getBattery() << "|";
        file_out << tablet.getBluetooth() << "|";
        file_out << std::get<0>(tablet.getResolution()) << "|" << std::get<1>(tablet.getResolution()) << "|";
        file_out << std::get<0>(tablet.getDimensions()) << "|" << std::get<1>(tablet.getDimensions()) << "|" << std::get<2>(tablet.getDimensions()) << "|";
        file_out << tablet.getWeight() << "|";
        file_out << tablet.getBrightness() << "|";
        file_out << tablet.getWifi() << "|";
        file_out << tablet.getHavePen() << "|";
        file_out << tablet.getInternal_Memory() << "|";
        file_out << tablet.getExternal_Memory() << "|";
        file_out << tablet.getSpeaker() << "|";
        file_out << tablet.getBiometrics()[0] << "|" << tablet.getBiometrics()[1] << "|" << tablet.getBiometrics()[2] << "|";
        file_out << tablet.getIsWaterproof() << "|";
        file_out << tablet.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}


void Tablet::readData() {
    std::ifstream file_in("../txt_files/tablet.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string display;
    std::string processor;
    std::string os;
    std::string storage;
    std::string camera;
    std::string battery;
    std::string bluetooth;
    std::string resolution_w;
    std::string resolution_h;
    std::string dimensions_l;
    std::string dimensions_w;
    std::string dimensions_h;
    std::string weight;
    std::string brightness;
    std::string wifi;
    std::string have_pen;
    std::string internal_memory;
    std::string external_memory;
    std::string speaker;
    std::string fingerprint;
    std::string iris;
    std::string face;
    std::string is_waterproof;
    std::string image_path;
    std::array<std::string*, 31> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &display, &processor, &os, &storage, &camera, &battery, &bluetooth, &resolution_w, &resolution_h, &dimensions_l, &dimensions_w, &dimensions_h, &weight, &brightness, &wifi, &have_pen, &internal_memory, &external_memory, &speaker, &fingerprint, &iris, &face, &is_waterproof, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                   
        }
        Tablet tablet("a");
        tablet.setID(id);
        tablet.setDescription(description);
        tablet.setBrand(brand);
        tablet.setModel(model);
        tablet.setPrice(std::stod(price));
        tablet.setQuantity(std::stoi(quantity));
        tablet.setOnDisplay(std::stoi(on_display));
        tablet.setDisplay(display);
        tablet.setProcessor(processor);
        tablet.setOs(os);
        tablet.setStorage(storage);
        tablet.setCamera(camera);
        tablet.setBattery(std::stod(battery));
        tablet.setBluetooth(bluetooth);
        tablet.setResolution(std::stoi(resolution_w), std::stoi(resolution_h));
        tablet.setDimensions(std::stod(dimensions_l), std::stod(dimensions_w), std::stod(dimensions_h));
        tablet.setWeight(std::stod(weight));
        tablet.setBrightness(std::stod(brightness));
        tablet.setWifi(wifi);
        tablet.setHavePen(std::stoi(have_pen));
        tablet.setInternal_Memory(internal_memory);
        tablet.setExternal_Memory(external_memory);
        tablet.setSpeaker(speaker);
        tablet.setBiometrics(std::stoi(fingerprint), std::stoi(iris), std::stoi(face));
        tablet.setIsWaterproof(std::stoi(is_waterproof));
        tablet.setImagePath(image_path);
        tablet_vec.push_back(tablet);
    }
    file_in.close();
    return;
}

void Tablet::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Tablet> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Battery" << std::endl;
        std::cout << "3. Resolution" << std::endl;
        std::cout << "4. Dimensions" << std::endl;
        std::cout << "5. Brightness" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter OS" << std::endl;
        std::cout << "8. Filter Wifi" << std::endl;
        std::cout << "9. Filter Bluetooth" << std::endl;
        std::cout << "10. Filter Waterproof" << std::endl;
        std::cout << "11. Filter Pen" << std::endl;
        std::cout << "12. Filter Fingerprint" << std::endl;
        std::cout << "13. Filter Face" << std::endl;
        std::cout << "14. Filter Iris" << std::endl;
        std::cout << "15. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 15 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 15: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortBattery();
        } else if (sort_option == 3){
            sortResolution();
        } else if (sort_option == 4){
            sortDimensions();
        } else if (sort_option == 5){
            sortBrightness();
        } else if (sort_option == 6){
            std::cout << "Brand: ";
            std::getline(std::cin, filter_input);
            filterBrand(filter_input);
        } else if (sort_option == 7){
            std::cout << "OS: ";
            std::getline(std::cin, filter_input);
            filterOs(filter_input);
        } else if (sort_option == 8){
            std::cout << "Wifi: ";
            std::getline(std::cin, filter_input);
            filterWifi(filter_input);
        } else if (sort_option == 9){
            std::cout << "Bluetooth: ";
            std::getline(std::cin, filter_input);
            filterBluetooth(filter_input);
        } else if (sort_option == 10){
            filterWaterproof();
        } else if (sort_option == 11){
            filterPen();
        } else if (sort_option == 12){
            filterFingerprint();
        } else if (sort_option == 13){
            filterFace();
        } else if (sort_option == 14){
            filterIris();
        } else if (sort_option == 15){
            filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const Tablet tablet: tablet_vec){
                std::cout << tablet;
                switch (sort_option)
                {
                case 2:
                    std::cout << "     " << "Battery: " << tablet.getBattery() << "mAh" << std::endl;
                    break;
                case 3:
                    std::cout << "     " << "Resolution: " << std::get<0>(tablet.getResolution()) << "x" << std::get<1>(tablet.getResolution()) << std::endl;
                    break;
                case 4:
                    std::cout << "     " << "Dimensions: " << std::get<0>(tablet.getDimensions()) << "x" << std::get<1>(tablet.getDimensions()) << "x" << std::get<2>(tablet.getDimensions()) << std::endl;
                    break;
                case 5:
                    std::cout << "     " << "Brightness: " << tablet.getBrightness() << "nits" << std::endl;
                    break;
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Tablet tablet: filtered){
                std::cout << tablet << std::endl;
            }
        }
    }
    return;
}

void Tablet::sortPrice(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void Tablet::sortBattery(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return a.getBattery() > b.getBattery();
    });
    return;
}

void Tablet::sortWeight(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return a.getWeight() > b.getWeight();
    });
    return;
}

void Tablet::sortResolution(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return std::get<0>(a.getResolution()) * std::get<1>(a.getResolution()) > std::get<0>(b.getResolution()) * std::get<1>(b.getResolution());
    });
    return;
}

void Tablet::sortDimensions(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return std::get<0>(a.getDimensions()) * std::get<1>(a.getDimensions()) * std::get<2>(a.getDimensions()) > std::get<0>(b.getDimensions()) * std::get<1>(b.getDimensions()) * std::get<2>(b.getDimensions());
    });
    return;
}

void Tablet::sortBrightness(){
    std::sort(tablet_vec.begin(), tablet_vec.end(), [](const Tablet& a, const Tablet& b){
        return a.getBrightness() > b.getBrightness();
    });
    return;
}

void Tablet::filterBrand(const std::string brand){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getBrand() == brand){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterOs(const std::string os){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getOs() == os){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterWifi(const std::string wifi){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getWifi() == wifi){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterBluetooth(const std::string bluetooth){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getBluetooth() == bluetooth){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterWaterproof(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getIsWaterproof()){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterPen(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getHavePen()){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterFingerprint(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getBiometrics()[0]){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterFace(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getBiometrics()[1]){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterIris(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getBiometrics()[2]){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

void Tablet::filterOnDisplay(){
    std::vector<Tablet> temp;
    for (const Tablet& tablet: tablet_vec){
        if (tablet.getOnDisplay()){
            temp.push_back(tablet);
        }
    }
    tablet_vec = temp;
    return;
}

Tablet& Tablet::operator=(const Tablet& tablet){
    setID(tablet.getID());
    setDescription(tablet.getDescription());
    setBrand(tablet.getBrand());
    setModel(tablet.getModel());
    setPrice(tablet.getPrice());
    setQuantity(tablet.getQuantity());
    setOnDisplay(tablet.getOnDisplay());
    setDisplay(tablet.getDisplay());
    setProcessor(tablet.getProcessor());
    setOs(tablet.getOs());
    setStorage(tablet.getStorage());
    setCamera(tablet.getCamera());
    setBattery(tablet.getBattery());
    setBluetooth(tablet.getBluetooth());
    setResolution(std::get<0>(tablet.getResolution()), std::get<1>(tablet.getResolution()));
    setDimensions(std::get<0>(tablet.getDimensions()), std::get<1>(tablet.getDimensions()), std::get<2>(tablet.getDimensions()));
    setWeight(tablet.getWeight());
    setBrightness(tablet.getBrightness());
    setWifi(tablet.getWifi());
    setHavePen(tablet.getHavePen());
    setInternal_Memory(tablet.getInternal_Memory());
    setExternal_Memory(tablet.getExternal_Memory());
    setSpeaker(tablet.getSpeaker());
    setBiometrics(tablet.getBiometrics()[0], tablet.getBiometrics()[1], tablet.getBiometrics()[2]);
    setIsWaterproof(tablet.getIsWaterproof());
    setImagePath(tablet.getImagePath());
    return *this;
}
