#include "headset.h"

Headset::Headset() : Peripherals(){
    is_wireless = false;
    has_anc = false;
    is_rgb = false;
    surround_sound = false;
    generateId();
}

Headset::Headset(const int q, const double p) : Peripherals(q, p){
    is_wireless = false;
    has_anc = false;
    is_rgb = false;
    surround_sound = false;
    generateId();
}

Headset::Headset(const std::string s) : Peripherals(){
    is_wireless = false;
    has_anc = false;
    is_rgb = false;
    surround_sound = false;
}

void Headset::setANC(const bool a){
    has_anc = a;
}

void Headset::setWireless(const bool w){
    is_wireless = w;
}

void Headset::setRGB(const bool r){
    is_rgb = r;
}

void Headset::setSurroundSound(const bool s){
    surround_sound = s;
}

bool Headset::getANC() const{
    return has_anc;
}

bool Headset::getWireless() const{
    return is_wireless;
}

bool Headset::getRGB() const{
    return is_rgb;
}

bool Headset::getSurroundSound() const{
    return surround_sound;
}

void Headset::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Headset::generateId(){
    std::ifstream file_in("../txt_files/headset.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Headset& headset: headset_vec){
            std::string id = headset.getID();
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
    headset_vec.push_back(*this);
    std::ofstream file_out("../txt_files/headset.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headset& headset: headset_vec){
        file_out << headset.getID() << "|";
        file_out << headset.getDescription() << "|";
        file_out << headset.getBrand() << "|";
        file_out << headset.getModel() << "|";
        file_out << headset.getPrice() << "|";
        file_out << headset.getQuantity() << "|";
        file_out << headset.getOnDisplay() << "|";
        file_out << headset.getWireless() << "|";
        file_out << headset.getANC() << "|";
        file_out << headset.getRGB() << "|";
        file_out << headset.getSurroundSound() << "|";
        file_out << headset.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headset::updateVec(const Headset headset_in){
    for (Headset& headset: headset_vec){
        if (headset.getID() == headset_in.getID()){
            headset.setDescription(headset_in.getDescription());
            headset.setBrand(headset_in.getBrand());
            headset.setModel(headset_in.getModel());
            headset.setPrice(headset_in.getPrice());
            headset.setQuantity(headset_in.getQuantity());
            headset.setOnDisplay(headset_in.getOnDisplay());
            headset.setWireless(headset_in.getWireless());
            headset.setANC(headset_in.getANC());
            headset.setRGB(headset_in.getRGB());
            headset.setSurroundSound(headset_in.getSurroundSound());
            headset.setImagePath(headset_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/headset.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headset& headset: headset_vec){
        file_out << headset.getID() << "|";
        file_out << headset.getDescription() << "|";
        file_out << headset.getBrand() << "|";
        file_out << headset.getModel() << "|";
        file_out << headset.getPrice() << "|";
        file_out << headset.getQuantity() << "|";
        file_out << headset.getOnDisplay() << "|";
        file_out << headset.getWireless() << "|";
        file_out << headset.getANC() << "|";
        file_out << headset.getRGB() << "|";
        file_out << headset.getSurroundSound() << "|";
        file_out << headset.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headset::readData() {
    std::ifstream file_in("../txt_files/headset.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }

    std::string id, description, brand, model, price, quantity, on_display;
    std::string wireless;
    std::string anc;
    std::string rgb;
    std::string surround_sound;
    std::string image_path;
    std::array<std::string*, 12> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &wireless, &anc, &rgb, &surround_sound, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::stringstream rowstream{row};
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }        
        Headset headset("a");
        headset.setID(id);
        headset.setDescription(description);
        headset.setBrand(brand);
        headset.setModel(model);
        headset.setPrice(std::stod(price));
        headset.setQuantity(std::stoi(quantity));
        headset.setOnDisplay(std::stoi(on_display));
        headset.setWireless(std::stoi(wireless));
        headset.setANC(std::stoi(anc));
        headset.setRGB(std::stoi(rgb));
        headset.setSurroundSound(std::stoi(surround_sound));
        headset.setImagePath(image_path);
        headset_vec.push_back(headset);
    }
    file_in.close();
    return;
}

void Headset::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Headset> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter ANC" << std::endl;
        std::cout << "4. Filter Wireless" << std::endl;
        std::cout << "5. Filter RGB" << std::endl;
        std::cout << "6. Filter Surround Sound" << std::endl;
        std::cout << "7. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 6 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 6: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 3){
            filtered = filterANC();
        } else if (sort_option == 4){
            filtered = filterWireless();
        } else if (sort_option == 5){
            filtered = filterRGB();
        } else if (sort_option == 6){
            filtered = filterSurroundSound();
        } else if (sort_option == 7){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (const Headset headset: headset_vec){
                std::cout << headset << std::endl;
            }
        } else {
            for (const Headset headset: filtered){
                std::cout << headset << std::endl;
            }
        }
    }
    return;
}

void Headset::sortPrice(){
    std::sort(headset_vec.begin(), headset_vec.end(), [](const Headset& a, const Headset& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

std::vector<Headset> Headset::filterBrand(const std::string brand){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getBrand() == brand){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

std::vector<Headset> Headset::filterANC(){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getANC()){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

std::vector<Headset> Headset::filterWireless(){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getWireless()){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

std::vector<Headset> Headset::filterRGB(){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getRGB()){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

std::vector<Headset> Headset::filterSurroundSound(){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getSurroundSound()){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

std::vector<Headset> Headset::filterOnDisplay(){
    std::vector<Headset> filtered;
    for (const Headset headset: headset_vec){
        if (headset.getOnDisplay()){
            filtered.push_back(headset);
        }
    }
    return filtered;
}

Headset& Headset::operator=(const Headset& hs){
    setID(hs.getID());
    setDescription(hs.getDescription());
    setBrand(hs.getBrand());
    setModel(hs.getModel());
    setPrice(hs.getPrice());
    setQuantity(hs.getQuantity());
    setOnDisplay(hs.getOnDisplay());
    setWireless(hs.getWireless());
    setANC(hs.getANC());
    setRGB(hs.getRGB());
    setSurroundSound(hs.getSurroundSound());
    setImagePath(hs.getImagePath());
    return *this;
}