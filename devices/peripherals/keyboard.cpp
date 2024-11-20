#include "keyboard.h"

Keyboard::Keyboard(): Peripherals(){
    type = "-";
    layout = "-";
    is_backlit = false;
    is_wireless = false;
    key_switch = "-";
    generateId();
}

Keyboard::Keyboard(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    layout = "-";
    is_backlit = false;
    is_wireless = false;
    key_switch = "-";
    generateId();
}

Keyboard::Keyboard(const std::string s) : Peripherals() {
    type = "-";
    layout = "-";
    is_backlit = false;
    is_wireless = false;
    key_switch = "-";
}

void Keyboard::setType(const std::string t) {
    type = t;
}

void Keyboard::setLayout(const std::string l) {
    layout = l;
}

void Keyboard::setBacklit(const bool b) {
    is_backlit = b;
}

void Keyboard::setWireless(const bool w) {
    is_wireless = w;
}

void Keyboard::setKeySwitch(const std::string ks) {
    key_switch = ks;
}

std::string Keyboard::getType() const {
    return type;
}

std::string Keyboard::getLayout() const {
    return layout;
}

bool Keyboard::getBacklit() const {
    return is_backlit;
}

bool Keyboard::getWireless() const {
    return is_wireless;
}

std::string Keyboard::getKeySwitch() const {
    return key_switch;
}

void Keyboard::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Keyboard::generateId() {
    std::ifstream file_in("../txt_files/keyboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Keyboard& kb: keyboard_vec){
            std::string id = kb.getID(); // AZ0001
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
    keyboard_vec.push_back(*this);
    std::ofstream file_out("../txt_files/keyboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Keyboard& kb: keyboard_vec){
        file_out << kb.getID() << "|";
        file_out << kb.getDescription() << "|";
        file_out << kb.getBrand() << "|";
        file_out << kb.getModel() << "|";
        file_out << kb.getPrice() << "|";
        file_out << kb.getQuantity() << "|";
        file_out << kb.getOnDisplay() << "|";
        file_out << kb.getType() << "|";
        file_out << kb.getLayout() << "|";
        file_out << kb.getBacklit() << "|";
        file_out << kb.getWireless() << "|";
        file_out << kb.getKeySwitch() << "|";
        file_out << kb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Keyboard::updateVec(const Keyboard kb_in){
    for (Keyboard& kb: keyboard_vec){
        if (kb.getID() == kb_in.getID()){
            kb.setDescription(kb_in.getDescription());
            kb.setBrand(kb_in.getBrand());
            kb.setModel(kb_in.getModel());
            kb.setPrice(kb_in.getPrice());
            kb.setQuantity(kb_in.getQuantity());
            kb.setOnDisplay(kb_in.getOnDisplay());
            kb.setType(kb_in.getType());
            kb.setLayout(kb_in.getLayout());
            kb.setBacklit(kb_in.getBacklit());
            kb.setWireless(kb_in.getWireless());
            kb.setKeySwitch(kb_in.getKeySwitch());
            kb.setImagePath(kb_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/keyboard.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Keyboard& kb: keyboard_vec){
        file_out << kb.getID() << "|";
        file_out << kb.getDescription() << "|";
        file_out << kb.getBrand() << "|";
        file_out << kb.getModel() << "|";
        file_out << kb.getPrice() << "|";
        file_out << kb.getQuantity() << "|";
        file_out << kb.getOnDisplay() << "|";
        file_out << kb.getType() << "|";
        file_out << kb.getLayout() << "|";
        file_out << kb.getBacklit() << "|";
        file_out << kb.getWireless() << "|";
        file_out << kb.getKeySwitch() << "|";
        file_out << kb.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Keyboard::readData() {
    std::ifstream file_in("../txt_files/keyboard.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string layout;
    std::string backlit;
    std::string wireless;
    std::string key_switch;
    std::string image_path;
    std::array<std::string*, 13> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &layout, &backlit, &wireless, &key_switch, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Keyboard kb("a");
        kb.setID(id);
        kb.setDescription(description);
        kb.setBrand(brand);
        kb.setModel(model);
        kb.setPrice(std::stod(price));
        kb.setQuantity(std::stoi(quantity));
        kb.setOnDisplay(std::stoi(on_display));
        kb.setType(type);
        kb.setLayout(layout);
        kb.setBacklit(std::stoi(backlit));
        kb.setWireless(std::stoi(wireless));
        kb.setKeySwitch(key_switch);
        kb.setImagePath(image_path);
        keyboard_vec.push_back(kb);
    }
    file_in.close();
    return;
}

void Keyboard::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Keyboard> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter Type" << std::endl;
        std::cout << "4. Filter Layout" << std::endl;
        std::cout << "5. Filter Backlit" << std::endl;
        std::cout << "6. Filter Wireless" << std::endl;
        std::cout << "7. Filter Key Switch" << std::endl;
        std::cout << "8. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 8 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 8: " << std::endl;
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
            std::cout << "Enter type: ";
            std::getline(std::cin, filter_input);
            filtered = filterType(filter_input);
        } else if (sort_option == 4){
            std::cout << "Enter layout: ";
            std::getline(std::cin, filter_input);
            filtered = filterLayout(filter_input);
        } else if (sort_option == 5){
            filtered = filterBacklit();
        } else if (sort_option == 6){
            filtered = filterWireless();
        } else if (sort_option == 7){
            std::cout << "Enter key switch: ";
            std::getline(std::cin, filter_input);
            filtered = filterKeySwitch(filter_input);
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (const Keyboard keyboard: keyboard_vec){
                std::cout << keyboard << std::endl;
            }
        } else {
            for (const Keyboard keyboard: filtered){
                std::cout << keyboard << std::endl;
            }
        }
    }
    return;
}

void Keyboard::sortPrice() {
    std::sort(keyboard_vec.begin(), keyboard_vec.end(), [](const Keyboard& kb1, const Keyboard& kb2){
        return kb1.getPrice() < kb2.getPrice();
    });
}

std::vector<Keyboard> Keyboard::filterBrand(const std::string b) {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getBrand() == b){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterType(const std::string t) {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getType() == t){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterLayout(const std::string l) {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getLayout() == l){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterBacklit() {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getBacklit()){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterWireless() {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getWireless()){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterKeySwitch(const std::string ks) {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getKeySwitch() == ks){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

std::vector<Keyboard> Keyboard::filterOnDisplay() {
    std::vector<Keyboard> filtered;
    for (const Keyboard kb: keyboard_vec){
        if (kb.getOnDisplay()){
            filtered.push_back(kb);
        }
    }
    return filtered;
}

Keyboard& Keyboard::operator=(const Keyboard& kb) {
    setID(kb.getID());
    setDescription(kb.getDescription());
    setBrand(kb.getBrand());
    setModel(kb.getModel());
    setPrice(kb.getPrice());
    setQuantity(kb.getQuantity());
    setOnDisplay(kb.getOnDisplay());
    setType(kb.getType());
    setLayout(kb.getLayout());
    setBacklit(kb.getBacklit());
    setWireless(kb.getWireless());
    setKeySwitch(kb.getKeySwitch());
    setImagePath(kb.getImagePath());
    return *this;
}