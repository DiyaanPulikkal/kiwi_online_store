#include "headphones.h"

Headphones::Headphones(): Peripherals(){
    has_anc = false;
    is_wireless = false;
    surround_sound = false;
    generateId();
}

Headphones::Headphones(const int q, const double p) : Peripherals(q, p){
    has_anc = false;
    is_wireless = false;
    surround_sound = false;
    generateId();
}

Headphones::Headphones(const std::string s) : Peripherals(){
    has_anc = false;
    is_wireless = false;
    surround_sound = false;
}


void Headphones::setANC(const bool a){
    has_anc = a;
}

void Headphones::setWireless(const bool w){
    is_wireless = w;
}

void Headphones::setSurroundSound(const bool s){
    surround_sound = s;
}

bool Headphones::getANC() const{
    return has_anc;
}

bool Headphones::getWireless() const{
    return is_wireless;
}

bool Headphones::getSurroundSound() const{
    return surround_sound;
}

void Headphones::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Headphones::generateId(){
    std::ifstream file_in("../txt_files/headphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Headphones& headphone: headphones_vec){
            std::string id = headphone.getID();
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
    headphones_vec.push_back(*this);
    std::ofstream file_out("../txt_files/headphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Headphones& headphones: headphones_vec){
        file_out << headphones.getID() << "|";
        file_out << headphones.getDescription() << "|";
        file_out << headphones.getBrand() << "|";
        file_out << headphones.getModel() << "|";
        file_out << headphones.getPrice() << "|";
        file_out << headphones.getQuantity() << "|";
        file_out << headphones.getOnDisplay() << "|";
        file_out << headphones.getANC() << "|";
        file_out << headphones.getWireless() << "|";
        file_out << headphones.getSurroundSound() << "|";
        file_out << headphones.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Headphones::updateVec(const Headphones hp_in){
    for (Headphones& hp: headphones_vec){
        if (hp.getID() == hp_in.getID()){
            hp.setDescription(hp_in.getDescription());
            hp.setBrand(hp_in.getBrand());
            hp.setModel(hp_in.getModel());
            hp.setPrice(hp_in.getPrice());
            hp.setQuantity(hp_in.getQuantity());
            hp.setOnDisplay(hp_in.getOnDisplay());
            hp.setANC(hp_in.getANC());
            hp.setWireless(hp_in.getWireless());
            hp.setSurroundSound(hp_in.getSurroundSound());
            hp.setImagePath(hp_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/headphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Headphones& headphones: headphones_vec){
        file_out << headphones.getID() << "|";
        file_out << headphones.getDescription() << "|";
        file_out << headphones.getBrand() << "|";
        file_out << headphones.getModel() << "|";
        file_out << headphones.getPrice() << "|";
        file_out << headphones.getQuantity() << "|";
        file_out << headphones.getOnDisplay() << "|";
        file_out << headphones.getANC() << "|";
        file_out << headphones.getWireless() << "|";
        file_out << headphones.getSurroundSound() << "|";
        file_out << headphones.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Headphones::readData() {
    std::ifstream file_in("../txt_files/headphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string anc;
    std::string wireless;
    std::string surround_sound;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &anc, &wireless, &surround_sound, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Headphones hp("a");
        hp.setID(id);
        hp.setDescription(description);
        hp.setBrand(brand);
        hp.setModel(model);
        hp.setPrice(std::stod(price));
        hp.setQuantity(std::stoi(quantity));
        hp.setOnDisplay(std::stoi(on_display));
        hp.setANC(std::stoi(anc));
        hp.setWireless(std::stoi(wireless));
        hp.setSurroundSound(std::stoi(surround_sound));
        hp.setImagePath(image_path);
        headphones_vec.push_back(hp);
    }
    file_in.close();
    return;
}

void Headphones::selectSortFilter(){
        unsigned int sort_option;
    std::string filter_input;
    std::vector<Headphones> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter ANC" << std::endl;
        std::cout << "4. Filter Wireless" << std::endl;
        std::cout << "5. Filter Surround Sound" << std::endl;
        std::cout << "6. Filter for sale" << std::endl;
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
            filtered = filterSurroundSound();
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (const Headphones headphones: headphones_vec){
                std::cout << headphones << std::endl;
            }
        } else {
            for (const Headphones headphones: filtered){
                std::cout << headphones << std::endl;
            }
        }
    }
    return;
}

void Headphones::sortPrice(){
    std::sort(headphones_vec.begin(), headphones_vec.end(), [](const Headphones& a, const Headphones& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

std::vector<Headphones> Headphones::filterBrand(const std::string brand){
    std::vector<Headphones> filtered;
    for (const Headphones hp: headphones_vec){
        if (hp.getBrand() == brand){
            filtered.push_back(hp);
        }
    }
    return filtered;
}

std::vector<Headphones> Headphones::filterANC(){
    std::vector<Headphones> filtered;
    for (const Headphones hp: headphones_vec){
        if (hp.getANC()){
            filtered.push_back(hp);
        }
    }
    return filtered;
}

std::vector<Headphones> Headphones::filterWireless(){
    std::vector<Headphones> filtered;
    for (const Headphones hp: headphones_vec){
        if (hp.getWireless()){
            filtered.push_back(hp);
        }
    }
    return filtered;
}

std::vector<Headphones> Headphones::filterSurroundSound(){
    std::vector<Headphones> filtered;
    for (const Headphones hp: headphones_vec){
        if (hp.getSurroundSound()){
            filtered.push_back(hp);
        }
    }
    return filtered;
}

std::vector<Headphones> Headphones::filterOnDisplay(){
    std::vector<Headphones> filtered;
    for (const Headphones hp: headphones_vec){
        if (hp.getOnDisplay()){
            filtered.push_back(hp);
        }
    }
    return filtered;
}

Headphones& Headphones::operator=(const Headphones& hp){
    setID(hp.getID());
    setDescription(hp.getDescription());
    setBrand(hp.getBrand());
    setModel(hp.getModel());
    setPrice(hp.getPrice());
    setQuantity(hp.getQuantity());
    setOnDisplay(hp.getOnDisplay());
    setANC(hp.getANC());
    setWireless(hp.getWireless());
    setSurroundSound(hp.getSurroundSound());
    setImagePath(hp.getImagePath());
    return *this;
}
