#include "earphones.h"

Earphones::Earphones(): Peripherals(){
    has_volume_control = false;
    water_resistant = false;
    wire_length = 0;
    generateId();
}

Earphones::Earphones(const int q, const double p) : Peripherals(q, p){
    has_volume_control = false;
    water_resistant = false;
    wire_length = 0;
    generateId();
}

Earphones::Earphones(const std::string s) : Peripherals(){
    has_volume_control = false;
    water_resistant = false;
    wire_length = 0;
}

void Earphones::setVolumeControl(const bool v){
    has_volume_control = v;
}

void Earphones::setWaterResistant(const bool w){
    water_resistant = w;
}

void Earphones::setWireLength(const double l){
    wire_length = l;
}

bool Earphones::getVolumeControl() const{
    return has_volume_control;
}

bool Earphones::getWaterResistant() const{
    return water_resistant;
}

double Earphones::getWireLength() const{
    return wire_length;
}

void Earphones::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Earphones::generateId(){
    std::ifstream file_in("../txt_files/earphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Earphones& earphone: earphones_vec){
            std::string id = earphone.getID();
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
    earphones_vec.push_back(*this);
    std::ofstream file_out("../txt_files/earphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Earphones& earphone: earphones_vec){
        file_out << earphone.getID() << "|";
        file_out << earphone.getDescription() << "|";
        file_out << earphone.getBrand() << "|";
        file_out << earphone.getModel() << "|";
        file_out << earphone.getPrice() << "|";
        file_out << earphone.getQuantity() << "|";
        file_out << earphone.getOnDisplay() << "|";
        file_out << earphone.getVolumeControl() << "|";
        file_out << earphone.getWaterResistant() << "|";
        file_out << earphone.getWireLength() << "|";
        file_out << earphone.getImagePath();
        file_out << std::endl;
    }  
    file_out.close();
    return;
}

void Earphones::updateVec(const Earphones ep_in){
    for (Earphones& ep: earphones_vec){
        if (ep.getID() == ep_in.getID()){
            ep.setDescription(ep_in.getDescription());
            ep.setBrand(ep_in.getBrand());
            ep.setModel(ep_in.getModel());
            ep.setPrice(ep_in.getPrice());
            ep.setQuantity(ep_in.getQuantity());
            ep.setOnDisplay(ep_in.getOnDisplay());
            ep.setVolumeControl(ep_in.getVolumeControl());
            ep.setWaterResistant(ep_in.getWaterResistant());
            ep.setWireLength(ep_in.getWireLength());
            ep.setImagePath(ep_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/earphones.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Earphones& earphone: earphones_vec){
        file_out << earphone.getID() << "|";
        file_out << earphone.getDescription() << "|";
        file_out << earphone.getBrand() << "|";
        file_out << earphone.getModel() << "|";
        file_out << earphone.getPrice() << "|";
        file_out << earphone.getQuantity() << "|";
        file_out << earphone.getOnDisplay() << "|";
        file_out << earphone.getVolumeControl() << "|";
        file_out << earphone.getWaterResistant() << "|";
        file_out << earphone.getWireLength() << "|";
        file_out << earphone.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Earphones::readData(){
    std::ifstream file_in("../txt_files/earphones.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string has_v;
    std::string is_w;
    std::string wire_len;
    std::string image_path;
    std::array<std::string*, 11> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &has_v, &is_w, &wire_len, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::stringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Earphones ep("a");
        ep.setID(id);
        ep.setDescription(description);
        ep.setBrand(brand);
        ep.setModel(model);
        ep.setPrice(std::stod(price));
        ep.setQuantity(std::stoi(quantity));
        ep.setOnDisplay(std::stoi(on_display));
        ep.setVolumeControl(std::stoi(has_v));
        ep.setWaterResistant(std::stoi(is_w));
        ep.setWireLength(std::stod(wire_len));
        ep.setImagePath(image_path);
        earphones_vec.push_back(ep);
    }
    file_in.close();
    return;
}

void Earphones::selectSortFilter(){
        unsigned int sort_option;
    std::string filter_input;
    std::vector<Earphones> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Wire Length" << std::endl;
        std::cout << "3. Filter Brand" << std::endl;
        std::cout << "4. Filter Volume Control" << std::endl;
        std::cout << "5. Filter Water Resistant" << std::endl;
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
            sortWireLength();
        } else if (sort_option == 3){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 4){
            filtered = filterVolumeControl();
        } else if (sort_option == 5){
            filtered = filterWaterResistant();
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (const Earphones earphones: earphones_vec){
                std::cout << earphones;
                ((sort_option == 1)? std::cout << std::endl : std::cout << "        " << "Wire length " << earphones.getWireLength() << " m" << std::endl);
            }
        } else {
            for (const Earphones earphones: filtered){
                std::cout << earphones << std::endl;
            }
        }
    }
    return;
}

void Earphones::sortPrice(){
    std::sort(earphones_vec.begin(), earphones_vec.end(), [](const Earphones& a, const Earphones& b){
        return a.getPrice() < b.getPrice();
    });
    return;
}

void Earphones::sortWireLength(){
    std::sort(earphones_vec.begin(), earphones_vec.end(), [](const Earphones& a, const Earphones& b){
        return a.getWireLength() < b.getWireLength();
    });
    return;
}

std::vector<Earphones> Earphones::filterBrand(const std::string brand){
    std::vector<Earphones> filtered;
    for (const Earphones earphone: earphones_vec){
        if (earphone.getBrand() == brand){
            filtered.push_back(earphone);
        }
    }
    return filtered;
}

std::vector<Earphones> Earphones::filterVolumeControl(){
    std::vector<Earphones> filtered;
    for (const Earphones earphone: earphones_vec){
        if (earphone.getVolumeControl()){
            filtered.push_back(earphone);
        }
    }
    return filtered;
}

std::vector<Earphones> Earphones::filterWaterResistant(){
    std::vector<Earphones> filtered;
    for (const Earphones earphone: earphones_vec){
        if (earphone.getWaterResistant()){
            filtered.push_back(earphone);
        }
    }
    return filtered;
}

std::vector<Earphones> Earphones::filterOnDisplay(){
    std::vector<Earphones> filtered;
    for (const Earphones earphone: earphones_vec){
        if (earphone.getOnDisplay()){
            filtered.push_back(earphone);
        }
    }
    return filtered;
}

Earphones& Earphones::operator=(const Earphones& ep){
    setID(ep.getID());
    setDescription(ep.getDescription());
    setBrand(ep.getBrand());
    setModel(ep.getModel());
    setPrice(ep.getPrice());
    setQuantity(ep.getQuantity());
    setOnDisplay(ep.getOnDisplay());
    setVolumeControl(ep.getVolumeControl());
    setWaterResistant(ep.getWaterResistant());
    setWireLength(ep.getWireLength());
    setImagePath(ep.getImagePath());
    return *this;
}