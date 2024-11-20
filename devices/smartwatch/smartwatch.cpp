#include "smartwatch.h"

Smartwatch::Smartwatch(): Devices(){
    display = "-";
    battery_mAh = 0.0;
    bluetooth = 0.0;
    screen_size_mm = 0.0;
    case_size_mm = 0.0;
    weight_g = 0.0;
    brightness_nits = 0.0;
    water_resistance_m = 0.0;
    heartrate_monitoring = false;
    has_microphones = false;
    wifi = 0.0;
    capacity_GB = 0.0;
    has_gps = false;
    has_blood_oxygen_sensor = false;
    has_speaker = false;
    sim = false;
    generateId();
}

Smartwatch::Smartwatch(int q, double p) : Devices(q, p){
    display = "-";
    battery_mAh = 0.0;
    bluetooth = 0.0;
    screen_size_mm = 0.0;
    case_size_mm = 0.0;
    weight_g = 0.0;
    brightness_nits = 0.0;
    water_resistance_m = 0.0;
    heartrate_monitoring = false;
    has_microphones = false;
    wifi = 0.0;
    capacity_GB = 0.0;
    has_gps = false;
    has_blood_oxygen_sensor = false;
    has_speaker = false;
    sim = false;
    generateId();
}

Smartwatch::Smartwatch(const std::string s) : Devices(){
    display = s;
    battery_mAh = 0.0;
    bluetooth = 0.0;
    screen_size_mm = 0.0;
    case_size_mm = 0.0;
    weight_g = 0.0;
    brightness_nits = 0.0;
    water_resistance_m = 0.0;
    heartrate_monitoring = false;
    has_microphones = false;
    wifi = 0.0;
    capacity_GB = 0.0;
    has_gps = false;
    has_blood_oxygen_sensor = false;
    has_speaker = false;
    sim = false;
}

double Smartwatch::getWifi() const {
    return wifi;
}

double Smartwatch::getCapacity() const {
    return capacity_GB;
}

bool Smartwatch::getHasGps() const {
    return has_gps;
}


bool Smartwatch::getHasBloodOxygenSensor() const {
    return has_blood_oxygen_sensor;
}

bool Smartwatch::getHasSpeaker() const {
    return has_speaker;
}

std::string Smartwatch::getDisplay() const {
    return display;
}

bool Smartwatch::getSim() const {
    return sim;
}

double Smartwatch::getBluetooth() const {
    return bluetooth;
}

double Smartwatch::getScreenSize() const {
    return screen_size_mm;
}

double Smartwatch::getCaseSize() const {
    return case_size_mm;
}

double Smartwatch::getBrightness() const {
    return brightness_nits;
}

double Smartwatch::getWaterResistance() const {
    return water_resistance_m;
}

double Smartwatch::getBattery() const {
    return battery_mAh;
}

double Smartwatch::getWeight() const {
    return weight_g;
}

bool Smartwatch::getHeartrateMonitoring() const {
    return heartrate_monitoring;
}

bool Smartwatch::getHasMicrophones() const {
    return has_microphones;
}

void Smartwatch::setDisplay(const std::string d) {
    display = d;
}
void Smartwatch::setSim(const bool s) {
    sim = s;
}

void Smartwatch::setBluetooth(const double b) {
    bluetooth = b;
}

void Smartwatch::setScreenSize(const double s) {
    screen_size_mm = s;
}

void Smartwatch::setCaseSize(const double c) {
    case_size_mm = c;
}

void Smartwatch::setBrightness(const double b) {
    brightness_nits = b;
}

void Smartwatch::setWaterResistance(const double w) {
    water_resistance_m = w;
}

void Smartwatch::setBattery(const double b) {
    battery_mAh = b;
}

void Smartwatch::setWeight(const double w) {
    weight_g = w;
}

void Smartwatch::setHeartrateMonitoring(const bool h) {
    heartrate_monitoring = h;
}

void Smartwatch::setHasMicrophones(const bool m) {
    has_microphones = m;
}

void Smartwatch::setWifi(const double w) {
    wifi = w;
}

void Smartwatch::setCapacity(const double c) {
    capacity_GB = c;
}

void Smartwatch::setHasGps(const bool g) {
    has_gps = g;
}


void Smartwatch::setHasBloodOxygenSensor(const bool b) {
    has_blood_oxygen_sensor = b;
}

void Smartwatch::setHasSpeaker(const bool s) {
    has_speaker = s;
}

void Smartwatch::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Smartwatch::generateId() {
    std::ifstream file_in("../txt_files/smartwatch.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Smartwatch& smartwatch: smartwatch_vec){
            std::string id = smartwatch.getID(); // AZ0001
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
    smartwatch_vec.push_back(*this);
    std::ofstream file_out("../txt_files/smartwatch.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartwatch& smartwatch: smartwatch_vec){
        file_out << smartwatch.getID() << "|";
        file_out << smartwatch.getDescription() << "|";
        file_out << smartwatch.getBrand() << "|";
        file_out << smartwatch.getModel() << "|";
        file_out << smartwatch.getPrice() << "|";
        file_out << smartwatch.getQuantity() << "|";
        file_out << smartwatch.getOnDisplay() << "|";
        file_out << smartwatch.getDisplay() << "|";
        file_out << smartwatch.getSim() << "|";
        file_out << smartwatch.getBluetooth() << "|";
        file_out << smartwatch.getWifi() << "|";
        file_out << smartwatch.getCapacity() << "|";
        file_out << smartwatch.getScreenSize() << "|";
        file_out << smartwatch.getCaseSize() << "|";
        file_out << smartwatch.getBrightness() << "|";
        file_out << smartwatch.getWaterResistance() << "|";
        file_out << smartwatch.getBattery() << "|";
        file_out << smartwatch.getWeight() << "|";
        file_out << smartwatch.getHeartrateMonitoring() << "|";
        file_out << smartwatch.getHasMicrophones() << "|";
        file_out << smartwatch.getHasGps() << "|";
        file_out << smartwatch.getHasBloodOxygenSensor() << "|";
        file_out << smartwatch.getHasSpeaker() << "|";
        file_out << smartwatch.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Smartwatch::updateVec(const Smartwatch smartwatch_in) {
    for (Smartwatch& smartwatch: smartwatch_vec){
        if (smartwatch.getID() == smartwatch_in.getID()){
            smartwatch.setDescription(smartwatch_in.getDescription());
            smartwatch.setBrand(smartwatch_in.getBrand());
            smartwatch.setModel(smartwatch_in.getModel());
            smartwatch.setPrice(smartwatch_in.getPrice());
            smartwatch.setQuantity(smartwatch_in.getQuantity());
            smartwatch.setOnDisplay(smartwatch_in.getOnDisplay());
            smartwatch.setDisplay(smartwatch_in.getDisplay());
            smartwatch.setSim(smartwatch_in.getSim());
            smartwatch.setBluetooth(smartwatch_in.getBluetooth());
            smartwatch.setWifi(smartwatch_in.getWifi());
            smartwatch.setCapacity(smartwatch_in.getCapacity());
            smartwatch.setScreenSize(smartwatch_in.getScreenSize());
            smartwatch.setCaseSize(smartwatch_in.getCaseSize());
            smartwatch.setBrightness(smartwatch_in.getBrightness());
            smartwatch.setWaterResistance(smartwatch_in.getWaterResistance());
            smartwatch.setBattery(smartwatch_in.getBattery());
            smartwatch.setWeight(smartwatch_in.getWeight());
            smartwatch.setHeartrateMonitoring(smartwatch_in.getHeartrateMonitoring());
            smartwatch.setHasMicrophones(smartwatch_in.getHasMicrophones());
            smartwatch.setHasGps(smartwatch_in.getHasGps());
            smartwatch.setHasBloodOxygenSensor(smartwatch_in.getHasBloodOxygenSensor());
            smartwatch.setHasSpeaker(smartwatch_in.getHasSpeaker());
            smartwatch.setImagePath(smartwatch_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/smartwatch.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Smartwatch& smartwatch: smartwatch_vec){
        file_out << smartwatch.getID() << "|";
        file_out << smartwatch.getDescription() << "|";
        file_out << smartwatch.getBrand() << "|";
        file_out << smartwatch.getModel() << "|";
        file_out << smartwatch.getPrice() << "|";
        file_out << smartwatch.getQuantity() << "|";
        file_out << smartwatch.getOnDisplay() << "|";
        file_out << smartwatch.getDisplay() << "|";
        file_out << smartwatch.getSim() << "|";
        file_out << smartwatch.getBluetooth() << "|";
        file_out << smartwatch.getWifi() << "|";
        file_out << smartwatch.getCapacity() << "|";
        file_out << smartwatch.getScreenSize() << "|";
        file_out << smartwatch.getCaseSize() << "|";
        file_out << smartwatch.getBrightness() << "|";
        file_out << smartwatch.getWaterResistance() << "|";
        file_out << smartwatch.getBattery() << "|";
        file_out << smartwatch.getWeight() << "|";
        file_out << smartwatch.getHeartrateMonitoring() << "|";
        file_out << smartwatch.getHasMicrophones() << "|";
        file_out << smartwatch.getHasGps() << "|";
        file_out << smartwatch.getHasBloodOxygenSensor() << "|";
        file_out << smartwatch.getHasSpeaker() << "|";
        file_out << smartwatch.getImagePath();

        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Smartwatch::readData(){
    std::ifstream file_in("../txt_files/smartwatch.txt", std::ios::in);
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
    std::string battery_mAh;
    std::string bluetooth;
    std::string screen_size_mm;
    std::string case_size_mm;
    std::string weight_g;
    std::string brightness_nits;
    std::string water_resistance_m;
    std::string heartrate_monitoring;
    std::string has_microphones;
    std::string wifi;
    std::string capacity_GB;
    std::string has_gps;
    std::string has_blood_oxygen_sensor;
    std::string has_speaker;
    std::string sim;
    std::string image_path;
    std::array<std::string*, 24> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &display, &battery_mAh, &bluetooth, &screen_size_mm, &case_size_mm, &weight_g, &brightness_nits, &water_resistance_m, &heartrate_monitoring, &has_microphones, &wifi, &capacity_GB, &has_gps, &has_blood_oxygen_sensor, &has_speaker, &sim, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                  
        }
        Smartwatch smartwatch("a");
        smartwatch.setID(id);
        smartwatch.setDescription(description);
        smartwatch.setBrand(brand);
        smartwatch.setModel(model);
        smartwatch.setPrice(std::stod(price));
        smartwatch.setQuantity(std::stoi(quantity));
        smartwatch.setOnDisplay(std::stoi(on_display));
        smartwatch.setDisplay(display);
        smartwatch.setBattery(std::stod(battery_mAh));
        smartwatch.setBluetooth(std::stod(bluetooth));
        smartwatch.setScreenSize(std::stod(screen_size_mm));
        smartwatch.setCaseSize(std::stod(case_size_mm));
        smartwatch.setWeight(std::stod(weight_g));
        smartwatch.setBrightness(std::stod(brightness_nits));
        smartwatch.setWaterResistance(std::stod(water_resistance_m));
        smartwatch.setHeartrateMonitoring(std::stoi(heartrate_monitoring));
        smartwatch.setHasMicrophones(std::stoi(has_microphones));
        smartwatch.setWifi(std::stod(wifi));    
        smartwatch.setCapacity(std::stod(capacity_GB));
        smartwatch.setHasGps(std::stoi(has_gps));
        smartwatch.setHasBloodOxygenSensor(std::stoi(has_blood_oxygen_sensor));
        smartwatch.setHasSpeaker(std::stoi(has_speaker));
        smartwatch.setSim(std::stoi(sim));
        smartwatch.setImagePath(image_path);
        smartwatch_vec.push_back(smartwatch);
    }
    file_in.close();
    return;
}

void Smartwatch::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Smartwatch> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Bluetooth" << std::endl;
        std::cout << "3. Wifi" << std::endl;
        std::cout << "4. Capacity" << std::endl;
        std::cout << "5. Screen Size" << std::endl;
        std::cout << "6. Case Size" << std::endl;
        std::cout << "7. Brightness" << std::endl;
        std::cout << "8. Water Resistance" << std::endl;
        std::cout << "9. Battery" << std::endl;
        std::cout << "10. Weight" << std::endl;
        std::cout << "11. Filter Brand" << std::endl;
        std::cout << "12. Filter cellular support" << std::endl;
        std::cout << "13. Filter Heartrate Monitoring available" << std::endl;
        std::cout << "14. Filter Microphones available" << std::endl;
        std::cout << "15. Filter GPS available" << std::endl;
        std::cout << "16. Filter Blood Oxygen Sensor available" << std::endl;
        std::cout << "17. Filter Speaker available" << std::endl;
        std::cout << "18. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 18 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 18: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortBluetooth();
        } else if (sort_option == 3){
            sortWifi();
        } else if (sort_option == 4){
            sortCapacity();
        } else if (sort_option == 5){
            sortScreenSize();
        } else if (sort_option == 6){
            sortCaseSize();
        } else if (sort_option == 7){
            sortBrightness();
        } else if (sort_option == 8){
            sortWaterResistance();
        } else if (sort_option == 9){
            sortBattery();
        } else if (sort_option == 10){
            sortWeight();
        } else if (sort_option == 11){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 12){
            filtered = filterSim();
        } else if (sort_option == 13){
            filtered = filterHeartrateMonitoring();
        } else if (sort_option == 14){
            filtered = filterHasMicrophones();
        } else if (sort_option == 15){
            filtered = filterHasGps();
        } else if (sort_option == 16){
            filtered = filterHasBloodOxygenSensor();
        } else if (sort_option == 17){
            filtered = filterHasSpeaker();
        } else if (sort_option == 18){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 11){
            for (const Smartwatch smartwatch: smartwatch_vec){
                std::cout << smartwatch;
                switch (sort_option)
                {
                case 2:
                    std::cout << "     " << "Bluetooth: " << smartwatch.getBluetooth() << "m" << std::endl;
                    break;

                case 3:
                    std::cout << "     " << "Wifi: " << smartwatch.getWifi() << "m" << std::endl;
                    break;
                
                case 4:
                    std::cout << "     " << "Capacity: " << smartwatch.getCapacity() << "GB" << std::endl;
                    break;

                case 5:
                    std::cout << "     " << "Screen Size: " << smartwatch.getScreenSize() << "mm" << std::endl;
                    break;

                case 6:
                    std::cout << "     " << "Case Size: " << smartwatch.getCaseSize() << "mm" << std::endl;
                    break;

                case 7:
                    std::cout << "     " << "Brightness: " << smartwatch.getBrightness() << "nits" << std::endl;
                    break;

                case 8:
                    std::cout << "     " << "Water Resistance: " << smartwatch.getWaterResistance() << "m" << std::endl;
                    break;

                case 9:
                    std::cout << "     " << "Battery: " << smartwatch.getBattery() << "mAh" << std::endl;
                    break;

                case 10:
                    std::cout << "     " << "Weight: " << smartwatch.getWeight() << "g" << std::endl;
                    break;

                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Smartwatch smartwatch: filtered){
                std::cout << smartwatch << std::endl;
            }
        }
    }
    return;
}

void Smartwatch::sortPrice(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getPrice() < b.getPrice();
    });
}

void Smartwatch::sortBluetooth(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getBluetooth() < b.getBluetooth();
    });
}

void Smartwatch::sortWifi(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getWifi() < b.getWifi();
    });
}

void Smartwatch::sortCapacity(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getCapacity() < b.getCapacity();
    });
}

void Smartwatch::sortScreenSize(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getScreenSize() < b.getScreenSize();
    });
}

void Smartwatch::sortCaseSize(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getCaseSize() < b.getCaseSize();
    });
}

void Smartwatch::sortBrightness(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getBrightness() < b.getBrightness();
    });
}

void Smartwatch::sortWaterResistance(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getWaterResistance() < b.getWaterResistance();
    });
}

void Smartwatch::sortBattery(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getBattery() < b.getBattery();
    });
}

void Smartwatch::sortWeight(){
    std::sort(smartwatch_vec.begin(), smartwatch_vec.end(), [](const Smartwatch& a, const Smartwatch& b){
        return a.getWeight() < b.getWeight();
    });
}

std::vector<Smartwatch> Smartwatch::filterBrand(const std::string brand){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getBrand() == brand){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterSim(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getSim()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterHeartrateMonitoring(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getHeartrateMonitoring()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterHasMicrophones(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getHasMicrophones()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterHasGps(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getHasGps()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterHasBloodOxygenSensor(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getHasBloodOxygenSensor()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterHasSpeaker(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getHasSpeaker()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

std::vector<Smartwatch> Smartwatch::filterOnDisplay(){
    std::vector<Smartwatch> filtered;
    for (const Smartwatch smartwatch: smartwatch_vec){
        if (smartwatch.getOnDisplay()){
            filtered.push_back(smartwatch);
        }
    }
    return filtered;
}

Smartwatch& Smartwatch::operator=(const Smartwatch& smartwatch){
    setID(smartwatch.getID());
    setDescription(smartwatch.getDescription());
    setBrand(smartwatch.getBrand());
    setModel(smartwatch.getModel());
    setPrice(smartwatch.getPrice());
    setQuantity(smartwatch.getQuantity());
    setOnDisplay(smartwatch.getOnDisplay());
    setDisplay(smartwatch.getDisplay());
    setSim(smartwatch.getSim());
    setBluetooth(smartwatch.getBluetooth());
    setWifi(smartwatch.getWifi());
    setCapacity(smartwatch.getCapacity());
    setScreenSize(smartwatch.getScreenSize());
    setCaseSize(smartwatch.getCaseSize());
    setBrightness(smartwatch.getBrightness());
    setWaterResistance(smartwatch.getWaterResistance());
    setBattery(smartwatch.getBattery());
    setWeight(smartwatch.getWeight());
    setHeartrateMonitoring(smartwatch.getHeartrateMonitoring());
    setHasMicrophones(smartwatch.getHasMicrophones());
    setHasGps(smartwatch.getHasGps());
    setHasBloodOxygenSensor(smartwatch.getHasBloodOxygenSensor());
    setHasSpeaker(smartwatch.getHasSpeaker());
    setImagePath(smartwatch.getImagePath());
    return *this;
}
