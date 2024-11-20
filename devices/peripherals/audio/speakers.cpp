#include "speakers.h"

Speakers::Speakers(): Peripherals(){
    power_output = 0;
    configuration = 0;
    is_wireless = false;
    battery_life = 0;
    generateId();
}

Speakers::Speakers(int q, double p) : Peripherals(q, p){
    power_output = 0;
    configuration = 0;
    is_wireless = false;
    battery_life = 0;
    generateId();
}

Speakers::Speakers(const std::string s) : Peripherals(){
    power_output = 0;
    configuration = 0;
    is_wireless = false;
    battery_life = 0;
}

void Speakers::setPowerOutput(const double p){
    power_output = p;
}

void Speakers::setConfiguration(const double c){
    configuration = c;
}

void Speakers::setWireless(const bool w){
    is_wireless = w;
}

void Speakers::setBatteryLife(double b){
    battery_life = b;
}

double Speakers::getPowerOutput() const{
    return power_output;
}

double Speakers::getConfiguration() const{
    return configuration;
}

bool Speakers::getWireless() const{
    return is_wireless;
}

double Speakers::getBatteryLife() const{
    return battery_life;
}

void Speakers::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Speakers::generateId(){
    std::ifstream file_in("../txt_files/speakers.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Speakers& speaker: speakers_vec){
            std::string id = speaker.getID();
            std::string id_num = id.substr(2);
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
    speakers_vec.push_back(*this);
    std::ofstream file_out("../txt_files/speakers.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Speakers& speaker: speakers_vec){
        file_out << speaker.getID() << "|";
        file_out << speaker.getDescription() << "|";
        file_out << speaker.getBrand() << "|";
        file_out << speaker.getModel() << "|";
        file_out << speaker.getPrice() << "|";
        file_out << speaker.getQuantity() << "|";
        file_out << speaker.getOnDisplay() << "|";
        file_out << speaker.getPowerOutput() << "|";
        file_out << speaker.getConfiguration() << "|";
        file_out << speaker.getWireless() << "|";
        file_out << speaker.getBatteryLife() << "|";
        file_out << speaker.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Speakers::updateVec(const Speakers speaker_in) {
    for (Speakers& speaker: speakers_vec){
        if (speaker.getID() == speaker_in.getID()){
            speaker.setDescription(speaker_in.getDescription());
            speaker.setBrand(speaker_in.getBrand());
            speaker.setModel(speaker_in.getModel());
            speaker.setPrice(speaker_in.getPrice());
            speaker.setQuantity(speaker_in.getQuantity());
            speaker.setOnDisplay(speaker_in.getOnDisplay());
            speaker.setPowerOutput(speaker_in.getPowerOutput());
            speaker.setConfiguration(speaker_in.getConfiguration());
            speaker.setWireless(speaker_in.getWireless());
            speaker.setBatteryLife(speaker_in.getBatteryLife());
            speaker.setImagePath(speaker_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/speakers.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Speakers& speaker: speakers_vec){
        file_out << speaker.getID() << "|";
        file_out << speaker.getDescription() << "|";
        file_out << speaker.getBrand() << "|";
        file_out << speaker.getModel() << "|";
        file_out << speaker.getPrice() << "|";
        file_out << speaker.getQuantity() << "|";
        file_out << speaker.getOnDisplay() << "|";
        file_out << speaker.getPowerOutput() << "|";
        file_out << speaker.getConfiguration() << "|";
        file_out << speaker.getWireless() << "|";
        file_out << speaker.getBatteryLife() << "|";
        file_out << speaker.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Speakers::readData() {
    std::ifstream file_in("../txt_files/speakers.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string power_o;
    std::string config;
    std::string wireless;
    std::string battery_l;
    std::string image_path;
    std::array<std::string*, 12> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &power_o, &config, &wireless, &battery_l, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Speakers speaker("a");
        speaker.setID(id);
        speaker.setDescription(description);
        speaker.setBrand(brand);
        speaker.setModel(model);
        speaker.setPrice(std::stod(price));
        speaker.setQuantity(std::stoi(quantity));
        speaker.setOnDisplay(std::stoi(on_display));
        speaker.setPowerOutput(std::stod(power_o));
        speaker.setConfiguration(std::stod(config));
        speaker.setWireless(std::stoi(wireless));
        speaker.setBatteryLife(std::stod(battery_l));
        speaker.setImagePath(image_path);
        speakers_vec.push_back(speaker);
    }
    file_in.close();
    return;
}

void Speakers::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Speakers> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Power Output" << std::endl;
        std::cout << "3. Configuration" << std::endl;
        std::cout << "4. Battery Life" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
        std::cout << "6. Filter Wireless" << std::endl;
        std::cout << "7. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 7 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 7: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortPowerOutput();
        } else if (sort_option == 3){
            sortConfiguration();
        } else if (sort_option == 4){
            sortBatteryLife();
        } else if (sort_option == 5){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 6){
            filtered = filterWireless();
        } else if (sort_option == 7){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 5){
            for (const Speakers speakers: speakers_vec){
                std::cout << speakers;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Power Output: " << speakers.getPowerOutput() << " W" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Configuration: " << speakers.getConfiguration() << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Battery Life: " << speakers.getBatteryLife() << " hours" << std::endl;
                    break;                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Speakers speakers: filtered){
                std::cout << speakers << std::endl;
            }
        }
    }
    return;
}

void Speakers::sortPrice(){
    std::sort(speakers_vec.begin(), speakers_vec.end(), [](const Speakers& a, const Speakers& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void Speakers::sortPowerOutput(){
    std::sort(speakers_vec.begin(), speakers_vec.end(), [](const Speakers& a, const Speakers& b){
        return a.getPowerOutput() < b.getPowerOutput();
    });
    return;
}

void Speakers::sortConfiguration(){
    std::sort(speakers_vec.begin(), speakers_vec.end(), [](const Speakers& a, const Speakers& b){
        return a.getConfiguration() < b.getConfiguration();
    });
    return;
}

void Speakers::sortBatteryLife(){
    std::sort(speakers_vec.begin(), speakers_vec.end(), [](const Speakers& a, const Speakers& b){
        return a.getBatteryLife() < b.getBatteryLife();
    });
    return;
}

std::vector<Speakers> Speakers::filterBrand(const std::string brand){
    std::vector<Speakers> brand_vec;
    for (const Speakers speaker: speakers_vec){
        if (speaker.getBrand() == brand){
            brand_vec.push_back(speaker);
        }
    }
    return brand_vec;
}

std::vector<Speakers> Speakers::filterWireless(){
    std::vector<Speakers> wireless_vec;
    for (const Speakers speaker: speakers_vec){
        if (speaker.getWireless()){
            wireless_vec.push_back(speaker);
        }
    }
    return wireless_vec;
}

std::vector<Speakers> Speakers::filterOnDisplay(){
    std::vector<Speakers> on_display_vec;
    for (const Speakers speaker: speakers_vec){
        if (speaker.getOnDisplay()){
            on_display_vec.push_back(speaker);
        }
    }
    return on_display_vec;
}

Speakers& Speakers::operator=(const Speakers& speaker){
    setID(speaker.getID());
    setDescription(speaker.getDescription());
    setBrand(speaker.getBrand());
    setModel(speaker.getModel());
    setPrice(speaker.getPrice());
    setQuantity(speaker.getQuantity());
    setOnDisplay(speaker.getOnDisplay());
    setPowerOutput(speaker.getPowerOutput());
    setConfiguration(speaker.getConfiguration());
    setWireless(speaker.getWireless());
    setBatteryLife(speaker.getBatteryLife());
    setImagePath(speaker.getImagePath());
    return *this;
}