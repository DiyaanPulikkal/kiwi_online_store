#include "smartphones.h"

Smartphones::Smartphones(): Devices(){
    display = "-";
    resolution = std::make_tuple(0, 0);
    processor = "-";
    os = "-";
    charger = "-";
    camera_spec = "-";
    num_sim = 0;
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    storage = 0;
    refresh_rate = 0;
    wifi = 0.0;
    brightness_nits = 0.0;
    bluetooth = 0.0;
    weight_g = 0.0;
    battery_mAh = 0.0;
    biometrics = {false, false, false};
    have_microSD = false;
    have_jack = false;
    has_pen = false;
    generateId();
}

Smartphones::Smartphones(const int q, const double p) : Devices(q, p) {
    display = "-";
    resolution = std::make_tuple(0, 0);
    processor = "-";
    os = "-";
    charger = "-";
    camera_spec = "-";
    num_sim = 0;
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    storage = 0;
    refresh_rate = 0;
    wifi = 0.0;
    brightness_nits = 0.0;
    bluetooth = 0.0;
    weight_g = 0.0;
    battery_mAh = 0.0;
    biometrics = {false, false, false};
    have_microSD = false;
    have_jack = false;
    has_pen = false;
    generateId();
}

Smartphones::Smartphones(const std::string s) : Devices(){
    display = s;
    resolution = std::make_tuple(0, 0);
    processor = "-";
    os = "-";
    charger = "-";
    camera_spec = "-";
    num_sim = 0;
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    storage = 0;
    refresh_rate = 0;
    wifi = 0.0;
    brightness_nits = 0.0;
    bluetooth = 0.0;
    weight_g = 0.0;
    battery_mAh = 0.0;
    biometrics = {false, false, false};
    have_microSD = false;
    have_jack = false;
    has_pen = false;
}

void Smartphones::setDisplay(const std::string d) {
    display = d;
}

void Smartphones::setResolution(const int w, const int h) {
    resolution = std::make_tuple(w, h);
}

void Smartphones::setProcessor(const std::string p) {
    processor = p;
}

void Smartphones::setOS(const std::string o) {
    os = o;
}

void Smartphones::setCharger(const std::string c) {
    charger = c;
}

void Smartphones::setCameraSpec(const std::string c) {
    camera_spec = c;
}

void Smartphones::setNumSim(const int n) {
    num_sim = n;
}

void Smartphones::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Smartphones::setStorage(const int s) {
    storage = s;
}   

void Smartphones::setRefreshRate(const int r) {
    refresh_rate = r;
}

void Smartphones::setWifi(const double w) {
    wifi = w;
}

void Smartphones::setBrightness(const double b) {
    brightness_nits = b;
}

void Smartphones::setBluetooth(const double b) {
    bluetooth = b;
}

void Smartphones::setWeight(const double w) {
    weight_g = w;
}

void Smartphones::setBattery(const double b) {
    battery_mAh = b;
}

void Smartphones::setBiometrics(const bool f, const bool fa, const bool i) {
    biometrics = {f, fa, i};
}

void Smartphones::setMicroSD(const bool ms) {
    have_microSD = ms;
}

void Smartphones::setJack(const bool j) {
    have_jack = j;
}

void Smartphones::setHasPen(const bool p) {
    has_pen = p;
}

std::string Smartphones::getDisplay() const {
    return display;
}

std::tuple<int, int> Smartphones::getResolution() const {
    return resolution;
}

std::string Smartphones::getProcessor() const {
    return processor;
}

std::string Smartphones::getOS() const {
    return os;
}

std::string Smartphones::getCharger() const {
    return charger;
}

std::string Smartphones::getCameraSpec() const {
    return camera_spec;
}

int Smartphones::getNumSim() const {
    return num_sim;
}

std::tuple<double, double, double> Smartphones::getDimensions() const {
    return dimensions;
}

int Smartphones::getStorage() const {
    return storage;
}

int Smartphones::getRefreshRate() const {
    return refresh_rate;
}

double Smartphones::getWifi() const {
    return wifi;
}

double Smartphones::getBrightness() const {
    return brightness_nits;
}

double Smartphones::getBluetooth() const {
    return bluetooth;
}

double Smartphones::getWeight() const {
    return weight_g;
}

double Smartphones::getBattery() const {
    return battery_mAh;
}

std::array<bool, 3> Smartphones::getBiometrics() const {
    return biometrics;
}

bool Smartphones::getMicroSD() const {
    return have_microSD;
}

bool Smartphones::getJack() const {
    return have_jack;
}

bool Smartphones::getHasPen() const {
    return has_pen;
}

void Smartphones::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Smartphones::generateId() {
    std::ifstream file_in("../txt_files/smartphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Smartphones& smartphone: smartphones_vec){
            std::string id = smartphone.getID(); // AZ0001
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
    smartphones_vec.push_back(*this);
    std::ofstream file_out("../txt_files/smartphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartphones& smartphone: smartphones_vec){
        file_out << smartphone.getID() << "|";
        file_out << smartphone.getDescription() << "|";
        file_out << smartphone.getBrand() << "|";
        file_out << smartphone.getModel() << "|";
        file_out << smartphone.getPrice() << "|";
        file_out << smartphone.getQuantity() << "|";
        file_out << smartphone.getOnDisplay() << "|";
        file_out << smartphone.getDisplay() << "|";
        file_out << std::get<0>(smartphone.getResolution()) << "|" << std::get<1>(smartphone.getResolution()) << "|";
        file_out << smartphone.getProcessor() << "|";
        file_out << smartphone.getOS() << "|";
        file_out << smartphone.getCharger() << "|";
        file_out << smartphone.getCameraSpec() << "|";
        file_out << smartphone.getNumSim() << "|";
        file_out << std::get<0>(smartphone.getDimensions()) << "|" << std::get<1>(smartphone.getDimensions()) << "|" << std::get<2>(smartphone.getDimensions()) << "|";
        file_out << smartphone.getStorage() << "|";
        file_out << smartphone.getRefreshRate() << "|";
        file_out << smartphone.getWifi() << "|";
        file_out << smartphone.getBrightness() << "|";
        file_out << smartphone.getBluetooth() << "|";
        file_out << smartphone.getWeight() << "|";
        file_out << smartphone.getBattery() << "|";
        file_out << smartphone.getBiometrics()[0] << "|" << smartphone.getBiometrics()[1] << "|" << smartphone.getBiometrics()[2] << "|";
        file_out << smartphone.getMicroSD() << "|";
        file_out << smartphone.getJack() << "|";
        file_out << smartphone.getHasPen() << "|";
        file_out << smartphone.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Smartphones::updateVec(const Smartphones smartphone_in) {
    for (Smartphones& smartphone: smartphones_vec){
        if (smartphone.getID() == smartphone_in.getID()){
            smartphone.setDescription(smartphone_in.getDescription());
            smartphone.setBrand(smartphone_in.getBrand());
            smartphone.setModel(smartphone_in.getModel());
            smartphone.setPrice(smartphone_in.getPrice());
            smartphone.setQuantity(smartphone_in.getQuantity());
            smartphone.setOnDisplay(smartphone_in.getOnDisplay());
            smartphone.setDisplay(smartphone_in.getDisplay());
            smartphone.setResolution(std::get<0>(smartphone_in.getResolution()), std::get<1>(smartphone_in.getResolution()));
            smartphone.setProcessor(smartphone_in.getProcessor());
            smartphone.setOS(smartphone_in.getOS());
            smartphone.setCharger(smartphone_in.getCharger());
            smartphone.setCameraSpec(smartphone_in.getCameraSpec());
            smartphone.setNumSim(smartphone_in.getNumSim());
            smartphone.setDimensions(std::get<0>(smartphone_in.getDimensions()), 
                                    std::get<1>(smartphone_in.getDimensions()), 
                                    std::get<2>(smartphone_in.getDimensions()));
            smartphone.setStorage(smartphone_in.getStorage());
            smartphone.setRefreshRate(smartphone_in.getRefreshRate());
            smartphone.setWifi(smartphone_in.getWifi());
            smartphone.setBrightness(smartphone_in.getBrightness());
            smartphone.setBluetooth(smartphone_in.getBluetooth());
            smartphone.setWeight(smartphone_in.getWeight());
            smartphone.setBattery(smartphone_in.getBattery());
            smartphone.setBiometrics(smartphone_in.getBiometrics()[0], 
                                    smartphone_in.getBiometrics()[1], 
                                    smartphone_in.getBiometrics()[2]);
            smartphone.setMicroSD(smartphone_in.getMicroSD());
            smartphone.setJack(smartphone_in.getJack());
            smartphone.setHasPen(smartphone_in.getHasPen()); 
            smartphone.setImagePath(smartphone_in.getImagePath());           
            break;
        }
    }
    std::ofstream file_out("../txt_files/smartphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartphones& smartphone: smartphones_vec){
        file_out << smartphone.getID() << "|";
        file_out << smartphone.getDescription() << "|";
        file_out << smartphone.getBrand() << "|";
        file_out << smartphone.getModel() << "|";
        file_out << smartphone.getPrice() << "|";
        file_out << smartphone.getQuantity() << "|";
        file_out << smartphone.getOnDisplay() << "|";
        file_out << smartphone.getDisplay() << "|";
        file_out << std::get<0>(smartphone.getResolution()) << "|";
        file_out << std::get<1>(smartphone.getResolution()) << "|";
        file_out << smartphone.getProcessor() << "|";
        file_out << smartphone.getOS() << "|";
        file_out << smartphone.getCharger() << "|";
        file_out << smartphone.getCameraSpec() << "|";
        file_out << smartphone.getNumSim() << "|";
        file_out << std::get<0>(smartphone.getDimensions()) << "|";
        file_out << std::get<1>(smartphone.getDimensions()) << "|";
        file_out << std::get<2>(smartphone.getDimensions()) << "|";
        file_out << smartphone.getStorage() << "|";
        file_out << smartphone.getRefreshRate() << "|";
        file_out << smartphone.getWifi() << "|";
        file_out << smartphone.getBrightness() << "|";
        file_out << smartphone.getBluetooth() << "|";
        file_out << smartphone.getWeight() << "|";
        file_out << smartphone.getBattery() << "|";
        file_out << smartphone.getBiometrics()[0] << "|";
        file_out << smartphone.getBiometrics()[1] << "|";
        file_out << smartphone.getBiometrics()[2] << "|";
        file_out << smartphone.getMicroSD() << "|";
        file_out << smartphone.getJack() << "|";
        file_out << smartphone.getHasPen() << "|";
        file_out << smartphone.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Smartphones::readData(){
    std::ifstream file_in("../txt_files/smartphones.txt", std::ios::in);
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
    std::string resw;
    std::string resh;
    std::string processor;
    std::string os;
    std::string charger;
    std::string camera_spec;
    std::string num_sim;
    std::string dimensions_l;
    std::string dimensions_w;
    std::string dimensions_h;
    std::string storage;
    std::string refresh_rate;
    std::string wifi;
    std::string brightness;
    std::string bluetooth;
    std::string weight;
    std::string battery;
    std::string biometrics_f;
    std::string biometrics_fa;
    std::string biometrics_i;
    std::string microsd;
    std::string jack;
    std::string has_pen;
    std::string image_path;
    std::array<std::string*, 32> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &display, &resw, &resh, &processor, &os, &charger, &camera_spec, &num_sim, &dimensions_l, &dimensions_w, &dimensions_h, &storage, &refresh_rate, &wifi, &brightness, &bluetooth, &weight, &battery, &biometrics_f, &biometrics_fa, &biometrics_i, &microsd, &jack, &has_pen, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                
        }
        Smartphones smartphone("a");
        smartphone.setID(id);
        smartphone.setDescription(description);
        smartphone.setBrand(brand);
        smartphone.setModel(model);
        smartphone.setPrice(std::stod(price));
        smartphone.setQuantity(std::stoi(quantity));
        smartphone.setOnDisplay(std::stoi(on_display));
        smartphone.setDisplay(display);
        smartphone.setResolution(std::stoi(resw), std::stoi(resh));
        smartphone.setProcessor(processor);
        smartphone.setOS(os);
        smartphone.setCharger(charger);
        smartphone.setCameraSpec(camera_spec);
        smartphone.setNumSim(std::stoi(num_sim));
        smartphone.setDimensions(std::stod(dimensions_l), std::stod(dimensions_w), std::stod(dimensions_h));
        smartphone.setStorage(std::stoi(storage));
        smartphone.setRefreshRate(std::stoi(refresh_rate));
        smartphone.setWifi(std::stod(wifi));
        smartphone.setBrightness(std::stod(brightness));
        smartphone.setBluetooth(std::stod(bluetooth));
        smartphone.setWeight(std::stod(weight));
        smartphone.setBattery(std::stod(battery));
        smartphone.setBiometrics(std::stoi(biometrics_f), std::stoi(biometrics_fa), std::stoi(biometrics_i));
        smartphone.setMicroSD(std::stoi(microsd));
        smartphone.setJack(std::stoi(jack));
        smartphone.setHasPen(std::stoi(has_pen));
        smartphone.setImagePath(image_path);
        smartphones_vec.push_back(smartphone);
    }
    file_in.close();
    return;
}

void Smartphones::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Smartphones> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Resolution" << std::endl;
        std::cout << "3. Dimensions" << std::endl;
        std::cout << "4. Storage" << std::endl;
        std::cout << "5. Refresh Rate" << std::endl;
        std::cout << "6. Wifi" << std::endl;
        std::cout << "7. Brightness" << std::endl;
        std::cout << "8. Bluetooth" << std::endl;
        std::cout << "9. Weight" << std::endl;
        std::cout << "10. Battery" << std::endl;
        std::cout << "11. Filter Brand" << std::endl;
        std::cout << "12. Filter OS" << std::endl;
        std::cout << "13. Filter Fingerprint available" << std::endl;
        std::cout << "14. Filter Face available" << std::endl;
        std::cout << "15. Filter Iris available" << std::endl;
        std::cout << "16. Filter MicroSD available" << std::endl;
        std::cout << "17. Filter Jack available" << std::endl;
        std::cout << "18. Filter Pen available" << std::endl;
        std::cout << "19. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 19 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 19: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortResolution();
        } else if (sort_option == 3){
            sortDimensions();
        } else if (sort_option == 4){
            sortStorage();
        } else if (sort_option == 5){
            sortRefreshRate();
        } else if (sort_option == 6){
            sortWifi();
        } else if (sort_option == 7){
            sortBrightness();
        } else if (sort_option == 8){
            sortBluetooth();
        } else if (sort_option == 9){
            sortWeight();
        } else if (sort_option == 10){
            sortBattery();
        } else if (sort_option == 11){
            std::cout << "Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 12){
            std::cout << "OS: ";
            std::getline(std::cin, filter_input);
            filtered = filterOS(filter_input);
        } else if (sort_option == 13){
            filtered = filterFingerprint();
        } else if (sort_option == 14){
            filtered = filterFace();
        } else if (sort_option == 15){
            filtered = filterIris();
        } else if (sort_option == 16){
            filtered = filterMicroSD();
        } else if (sort_option == 17){
            filtered = filterJack();
        } else if (sort_option == 18){
            filtered = filterPen();
        } else if (sort_option == 19){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 11){
            for (const Smartphones smartphones: smartphones_vec){
                std::cout << smartphones;
                switch (sort_option)
                {
                case 2:
                    std::cout << "     " << "Resolution: " << std::get<0>(smartphones.getResolution()) << "x" << std::get<1>(smartphones.getResolution()) << std::endl;
                    break;

                case 3:
                    std::cout << "     " << "Dimensions: " << std::get<0>(smartphones.getDimensions()) << "x" << std::get<1>(smartphones.getDimensions()) << "x" << std::get<2>(smartphones.getDimensions()) << std::endl;
                    break;
                
                case 4:
                    std::cout << "     " << "Storage: " << smartphones.getStorage() << "GB" << std::endl;
                    break;

                case 5:
                    std::cout << "     " << "Refresh Rate: " << smartphones.getRefreshRate() << "Hz" << std::endl;
                    break;

                case 6:
                    std::cout << "     " << "Wifi: " << smartphones.getWifi() << "GHz" << std::endl;
                    break;

                case 7:
                    std::cout << "     " << "Brightness: " << smartphones.getBrightness() << "nits" << std::endl;
                    break;

                case 8:
                    std::cout << "     " << "Bluetooth: " << smartphones.getBluetooth() << "v" << std::endl;
                    break;

                case 9:
                    std::cout << "     " << "Weight: " << smartphones.getWeight() << "g" << std::endl;
                    break;

                case 10:
                    std::cout << "     " << "Battery: " << smartphones.getBattery() << "mAh" << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Smartphones smartphones: filtered){
                std::cout << smartphones << std::endl;
            }
        }
    }
    return;
}

void Smartphones::sortPrice(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getPrice() < s2.getPrice();
    });
}

void Smartphones::sortResolution(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return (std::get<0>(s1.getResolution()) * std::get<1>(s1.getResolution())) < (std::get<0>(s2.getResolution()) * std::get<1>(s2.getResolution()));
    });
}

void Smartphones::sortDimensions(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return (std::get<0>(s1.getDimensions()) * std::get<1>(s1.getDimensions()) * std::get<2>(s1.getDimensions())) < (std::get<0>(s2.getDimensions()) * std::get<1>(s2.getDimensions()) * std::get<2>(s2.getDimensions()));
    });
}

void Smartphones::sortStorage(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getStorage() < s2.getStorage();
    });
}

void Smartphones::sortRefreshRate(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getRefreshRate() < s2.getRefreshRate();
    });
}

void Smartphones::sortWifi(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getWifi() < s2.getWifi();
    });
}

void Smartphones::sortBrightness(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getBrightness() < s2.getBrightness();
    });
}

void Smartphones::sortBluetooth(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getBluetooth() < s2.getBluetooth();
    });
}

void Smartphones::sortWeight(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getWeight() < s2.getWeight();
    });
}

void Smartphones::sortBattery(){
    std::sort(smartphones_vec.begin(), smartphones_vec.end(), [](const Smartphones& s1, const Smartphones& s2){
        return s1.getBattery() < s2.getBattery();
    });
}

std::vector<Smartphones> Smartphones::filterBrand(const std::string brand){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getBrand() == brand){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterOS(const std::string os){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getOS() == os){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterFingerprint(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getBiometrics()[0]){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterFace(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getBiometrics()[1]){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterIris(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getBiometrics()[2]){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterMicroSD(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getMicroSD()){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterJack(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getJack()){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterPen(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getHasPen()){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

std::vector<Smartphones> Smartphones::filterOnDisplay(){
    std::vector<Smartphones> filtered;
    for (const Smartphones smartphone: smartphones_vec){
        if (smartphone.getOnDisplay()){
            filtered.push_back(smartphone);
        }
    }
    return filtered;
}

Smartphones& Smartphones::operator=(const Smartphones& smartphone){
    setID(smartphone.getID());
    setDescription(smartphone.getDescription());
    setBrand(smartphone.getBrand());
    setModel(smartphone.getModel());
    setPrice(smartphone.getPrice());
    setQuantity(smartphone.getQuantity());
    setOnDisplay(smartphone.getOnDisplay());
    setDisplay(smartphone.getDisplay());
    setResolution(std::get<0>(smartphone.getResolution()), std::get<1>(smartphone.getResolution()));
    setProcessor(smartphone.getProcessor());
    setOS(smartphone.getOS());
    setCharger(smartphone.getCharger());
    setCameraSpec(smartphone.getCameraSpec());
    setNumSim(smartphone.getNumSim());
    setDimensions(std::get<0>(smartphone.getDimensions()), 
                std::get<1>(smartphone.getDimensions()), 
                std::get<2>(smartphone.getDimensions()));
    setStorage(smartphone.getStorage());
    setRefreshRate(smartphone.getRefreshRate());
    setWifi(smartphone.getWifi());
    setBrightness(smartphone.getBrightness());
    setBluetooth(smartphone.getBluetooth());
    setWeight(smartphone.getWeight());
    setBattery(smartphone.getBattery());
    setBiometrics(smartphone.getBiometrics()[0], 
                smartphone.getBiometrics()[1], 
                smartphone.getBiometrics()[2]);
    setMicroSD(smartphone.getMicroSD());
    setJack(smartphone.getJack());
    setHasPen(smartphone.getHasPen());
    setImagePath(smartphone.getImagePath());
    return *this;
}