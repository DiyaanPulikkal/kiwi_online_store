#include "wire.h"

Wire::Wire(): Peripherals(){
    length = 0;
    type = "-";
    generateId();
}

Wire::Wire(const int q, const double p) : Peripherals(q, p) {
    length = 0;
    type = "-";
    generateId();
}

Wire::Wire(const std::string s) : Peripherals(){
    length = 0;
    type = "-";
}

void Wire::setLength(const double l) {
    length = l;
}

void Wire::setType(const std::string t) {
    type = t;
}

double Wire::getLength() const{
    return length;
}

std::string Wire::getType() const{
    return type;
}

void Wire::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Wire::generateId() {
    std::ifstream file_in("../txt_files/wire.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Wire& wire: wire_vec){
            std::string id = wire.getID(); // AZ0001
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
    wire_vec.push_back(*this);
    std::ofstream file_out("../txt_files/wire.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Wire& wire: wire_vec){
        file_out << wire.getID() << "|";
        file_out << wire.getDescription() << "|";
        file_out << wire.getBrand() << "|";
        file_out << wire.getModel() << "|";
        file_out << wire.getPrice() << "|";
        file_out << wire.getQuantity() << "|";
        file_out << wire.getOnDisplay() << "|";
        file_out << wire.getLength() << "|";
        file_out << wire.getType() << "|";
        file_out << wire.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Wire::updateVec(const Wire wire_in){
    for (Wire& wire: wire_vec){
        if (wire.getID() == wire_in.getID()){
            wire.setDescription(wire_in.getDescription());
            wire.setBrand(wire_in.getBrand());
            wire.setModel(wire_in.getModel());
            wire.setPrice(wire_in.getPrice());
            wire.setQuantity(wire_in.getQuantity());
            wire.setOnDisplay(wire_in.getOnDisplay());
            wire.setLength(wire_in.getLength());
            wire.setType(wire_in.getType());
            wire.setImagePath(wire_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/wire.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Wire& wire: wire_vec){
        file_out << wire.getID() << "|";
        file_out << wire.getDescription() << "|";
        file_out << wire.getBrand() << "|";
        file_out << wire.getModel() << "|";
        file_out << wire.getPrice() << "|";
        file_out << wire.getQuantity() << "|";
        file_out << wire.getOnDisplay() << "|";
        file_out << wire.getLength() << "|";
        file_out << wire.getType() << "|";
        file_out << wire.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Wire::readData() {
    std::ifstream file_in("../txt_files/wire.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string length;
    std::string type;
    std::string image_path;
    std::array<std::string*, 10> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &length, &type, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                   
        } 
        Wire wire("a");
        wire.setID(id);
        wire.setDescription(description);
        wire.setBrand(brand);
        wire.setModel(model);
        wire.setPrice(std::stod(price));
        wire.setQuantity(std::stoi(quantity));
        wire.setOnDisplay(std::stoi(on_display));
        wire.setLength(std::stod(length));
        wire.setType(type);
        wire.setImagePath(image_path);
        wire_vec.push_back(wire);
    }
    file_in.close();
    return;
}

void Wire::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Wire> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Length" << std::endl;
        std::cout << "3. Type" << std::endl;
        std::cout << "4. Filter Brand" << std::endl;
        std::cout << "5. Filter Type" << std::endl;
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
            sortLength();
        } else if (sort_option == 3){
            std::cout << "Type: ";
            std::getline(std::cin, filter_input);
            filtered = filterType(filter_input);
        } else if (sort_option == 4){
            std::cout << "Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 5){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 3){
            for (const Wire wire: wire_vec){
                std::cout << wire;
                ((sort_option == 2)? std::cout << "     " << "Wire Length: " << wire.getLength() << "m" << std::endl : std::cout << std::endl);
            }
        } else {
            for (const Wire wire: filtered){
                std::cout << wire << std::endl;
            }
        }
    }
    return;
}

void Wire::sortPrice() {
    std::sort(wire_vec.begin(), wire_vec.end(), [](const Wire& wire1, const Wire& wire2){
        return wire1.getPrice() < wire2.getPrice();
    });
}

void Wire::sortLength() {
    std::sort(wire_vec.begin(), wire_vec.end(), [](const Wire& wire1, const Wire& wire2){
        return wire1.getLength() < wire2.getLength();
    });
}

std::vector<Wire> Wire::filterBrand(const std::string brand) {
    std::vector<Wire> filtered;
    for (const Wire wire: wire_vec){
        if (wire.getBrand() == brand){
            filtered.push_back(wire);
        }
    }
    return filtered;
}

std::vector<Wire> Wire::filterType(const std::string type) {
    std::vector<Wire> filtered;
    for (const Wire wire: wire_vec){
        if (wire.getType() == type){
            filtered.push_back(wire);
        }
    }
    return filtered;
}

std::vector<Wire> Wire::filterOnDisplay() {
    std::vector<Wire> filtered;
    for (const Wire wire: wire_vec){
        if (wire.getOnDisplay() == 1){
            filtered.push_back(wire);
        }
    }
    return filtered;
}

Wire& Wire::operator=(const Wire& wire_in) {
    setID(wire_in.getID());
    setDescription(wire_in.getDescription());
    setBrand(wire_in.getBrand());
    setModel(wire_in.getModel());
    setPrice(wire_in.getPrice());
    setQuantity(wire_in.getQuantity());
    setOnDisplay(wire_in.getOnDisplay());
    setLength(wire_in.getLength());
    setType(wire_in.getType());
    setImagePath(wire_in.getImagePath());
    return *this;
}