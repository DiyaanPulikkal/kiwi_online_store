#include "printer.h"

Printer::Printer(): Peripherals(){
    type = "-";
    has_scanner = false;
    is_wireless = false;
    speed = 0;
    max_res = 0;
    is_duplex = false;
    ink_or_toner = std::make_tuple("-", 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight = 0;
    generateId();
}

Printer::Printer(const int q, const double p) : Peripherals(q, p) {
    type = "-";
    has_scanner = false;
    is_wireless = false;
    speed = 0;
    max_res = 0;
    is_duplex = false;
    ink_or_toner = std::make_tuple("-", 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight = 0;
    generateId();
}

Printer::Printer(const std::string s) : Peripherals() {
    type = "-";
    has_scanner = false;
    is_wireless = false;
    speed = 0;
    max_res = 0;
    is_duplex = false;
    ink_or_toner = std::make_tuple("-", 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0);
    weight = 0;
}

void Printer::setType(const std::string t) {
    type = t;
}

void Printer::setHasScanner(const bool hs) {
    has_scanner = hs;
}

void Printer::setWireless(const bool w) {
    is_wireless = w;
}

void Printer::setSpeed(const int s) {
    speed = s;
}

void Printer::setMaxRes(const int mr) {
    max_res = mr;
}

void Printer::setDuplex(const bool d) {
    is_duplex = d;
}

void Printer::setInkOrToner(const std::string iot, const int py) {
    ink_or_toner = std::make_tuple(iot, py);
}

void Printer::setDimensions(const double l, const double w, const double h) {
    dimensions = std::make_tuple(l, w, h);
}

void Printer::setWeight(const double w) {
    weight = w;
}

std::string Printer::getType() const {
    return type;
}

bool Printer::getHasScanner() const {
    return has_scanner;
}

bool Printer::getWireless() const {
    return is_wireless;
}

int Printer::getSpeed() const {
    return speed;
}

int Printer::getMaxRes() const {
    return max_res;
}

bool Printer::getDuplex() const {
    return is_duplex;
}

std::tuple<std::string, int> Printer::getInkOrToner() const {
    return ink_or_toner;
}

std::tuple<double, double, double> Printer::getDimensions() const {
    return dimensions;
}

double Printer::getWeight() const {
    return weight;
}

void Printer::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Printer::generateId() {
    std::ifstream file_in("../txt_files/printer.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Printer& printer: printer_vec){
            std::string id = printer.getID(); // AZ0001
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
    printer_vec.push_back(*this);
    std::ofstream file_out("../txt_files/printer.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Printer& printer: printer_vec){
        file_out << printer.getID() << "|";
        file_out << printer.getDescription() << "|";
        file_out << printer.getBrand() << "|";
        file_out << printer.getModel() << "|";
        file_out << printer.getPrice() << "|";
        file_out << printer.getQuantity() << "|";
        file_out << printer.getOnDisplay() << "|";
        file_out << printer.getType() << "|";
        file_out << printer.getHasScanner() << "|";
        file_out << printer.getWireless() << "|";
        file_out << printer.getSpeed() << "|";
        file_out << printer.getMaxRes() << "|";
        file_out << printer.getDuplex() << "|";
        file_out << std::get<0>(printer.getInkOrToner()) << "|";
        file_out << std::get<1>(printer.getInkOrToner()) << "|";
        file_out << std::get<0>(printer.getDimensions()) << "|";
        file_out << std::get<1>(printer.getDimensions()) << "|";
        file_out << std::get<2>(printer.getDimensions()) << "|";
        file_out << printer.getWeight();
        file_out << printer.getImagePath();
        file_out << std::endl;        
    }
    file_out.close();
    return;
}

void Printer::updateVec(const Printer pr_in){
    for (Printer& pr: printer_vec){
        if (pr.getID() == pr_in.getID()){
            pr.setDescription(pr_in.getDescription());
            pr.setBrand(pr_in.getBrand());
            pr.setModel(pr_in.getModel());
            pr.setPrice(pr_in.getPrice());
            pr.setQuantity(pr_in.getQuantity());
            pr.setOnDisplay(pr_in.getOnDisplay());
            pr.setType(pr_in.getType());
            pr.setHasScanner(pr_in.getHasScanner());
            pr.setWireless(pr_in.getWireless());
            pr.setSpeed(pr_in.getSpeed());
            pr.setMaxRes(pr_in.getMaxRes());
            pr.setDuplex(pr_in.getDuplex());
            pr.setInkOrToner(std::get<0>(pr_in.getInkOrToner()), std::get<1>(pr_in.getInkOrToner()));
            pr.setDimensions(std::get<0>(pr_in.getDimensions()), std::get<1>(pr_in.getDimensions()), std::get<2>(pr_in.getDimensions()));
            pr.setWeight(pr_in.getWeight());
            pr.setImagePath(pr_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/printer.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Printer& printer: printer_vec){
        file_out << printer.getID() << "|";
        file_out << printer.getDescription() << "|";
        file_out << printer.getBrand() << "|";
        file_out << printer.getModel() << "|";
        file_out << printer.getPrice() << "|";
        file_out << printer.getQuantity() << "|";
        file_out << printer.getOnDisplay() << "|";
        file_out << printer.getType() << "|";
        file_out << printer.getHasScanner() << "|";
        file_out << printer.getWireless() << "|";
        file_out << printer.getSpeed() << "|";
        file_out << printer.getMaxRes() << "|";
        file_out << printer.getDuplex() << "|";
        file_out << std::get<0>(printer.getInkOrToner()) << "|";
        file_out << std::get<1>(printer.getInkOrToner()) << "|";
        file_out << std::get<0>(printer.getDimensions()) << "|";
        file_out << std::get<1>(printer.getDimensions()) << "|";
        file_out << std::get<2>(printer.getDimensions()) << "|";
        file_out << printer.getWeight() << "|";
        file_out << printer.getImagePath();
        file_out << std::endl;        
    }
    file_out.close();
    return;
}

void Printer::readData() {
    std::ifstream file_in("../txt_files/printer.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()) {
        file_in.close();
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string type;
    std::string has_scanner;
    std::string is_wireless;
    std::string speed;
    std::string max_res;
    std::string is_duplex;
    std::string iot_type;
    std::string est_page_yield;
    std::string length;
    std::string width;
    std::string height;
    std::string weight;
    std::string image_path;
    std::array<std::string*, 20> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &type, &has_scanner, &is_wireless, &speed, &max_res, &is_duplex, &iot_type, &est_page_yield, &length, &width, &height, &weight, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');                 
        }
        Printer pr("a");
        pr.setID(id);
        pr.setDescription(description);
        pr.setBrand(brand);
        pr.setModel(model);
        pr.setPrice(std::stod(price));
        pr.setQuantity(std::stoi(quantity));
        pr.setOnDisplay(std::stoi(on_display));
        pr.setType(type);
        pr.setHasScanner(std::stoi(has_scanner));
        pr.setWireless(std::stoi(is_wireless));
        pr.setSpeed(std::stoi(speed));
        pr.setMaxRes(std::stoi(max_res));
        pr.setDuplex(std::stoi(is_duplex));
        pr.setInkOrToner(iot_type, std::stoi(est_page_yield));
        pr.setDimensions(std::stod(length), std::stod(width), std::stod(height));
        pr.setWeight(std::stod(weight));
        pr.setImagePath(image_path);
        printer_vec.push_back(pr);
    }
    file_in.close();
    return;
}

void Printer::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Printer> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Speed" << std::endl;
        std::cout << "3. Max Resolution" << std::endl;
        std::cout << "4. Dimensions" << std::endl;
        std::cout << "5. Weight" << std::endl;
        std::cout << "6. Filter Brand" << std::endl;
        std::cout << "7. Filter Wireless" << std::endl;
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
            sortSpeed();
        } else if (sort_option == 3){
            sortMaxRes();
        } else if (sort_option == 4){
            sortDimensions();
        } else if (sort_option == 5){
            sortWeight();
        } else if (sort_option == 6){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 7){
            filtered = filterWireless();
        } else if (sort_option == 8){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 6){
            for (const Printer printer: printer_vec){
                std::cout << printer;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Speed: " << printer.getSpeed() << " ppm" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Max Resolution: " << printer.getMaxRes() << " dpi" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Dimensions: " << std::get<0>(printer.getDimensions()) << " x " << std::get<1>(printer.getDimensions()) << " x " << std::get<2>(printer.getDimensions()) << " mm" << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Weight: " << printer.getWeight() << " kg" << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Printer printer: filtered){
                std::cout << printer << std::endl;
            }
        }
    }
    return;
}

void Printer::sortPrice(){
    std::sort(printer_vec.begin(), printer_vec.end(), [](const Printer& pr1, const Printer& pr2){
        return pr1.getPrice() < pr2.getPrice();
    });
    return;
}

void Printer::sortSpeed(){
    std::sort(printer_vec.begin(), printer_vec.end(), [](const Printer& pr1, const Printer& pr2){
        return pr1.getSpeed() < pr2.getSpeed();
    });
    return;
}

void Printer::sortMaxRes(){
    std::sort(printer_vec.begin(), printer_vec.end(), [](const Printer& pr1, const Printer& pr2){
        return pr1.getMaxRes() < pr2.getMaxRes();
    });
    return;
}

void Printer::sortDimensions(){
    std::sort(printer_vec.begin(), printer_vec.end(), [](const Printer& pr1, const Printer& pr2){
        return std::get<0>(pr1.getDimensions()) < std::get<0>(pr2.getDimensions());
    });
    return;
}

void Printer::sortWeight(){
    std::sort(printer_vec.begin(), printer_vec.end(), [](const Printer& pr1, const Printer& pr2){
        return pr1.getWeight() < pr2.getWeight();
    });
    return;
}

std::vector<Printer> Printer::filterBrand(const std::string brand){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getBrand() == brand){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

std::vector<Printer> Printer::filterType(const std::string type){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getType() == type){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

std::vector<Printer> Printer::filterHasScanner(){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getHasScanner()){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

std::vector<Printer> Printer::filterWireless(){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getWireless()){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

std::vector<Printer> Printer::filterDuplex(){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getDuplex()){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

std::vector<Printer> Printer::filterOnDisplay(){
    std::vector<Printer> filtered;
    for (const Printer pr: printer_vec){
        if (pr.getOnDisplay()){
            filtered.push_back(pr);
        }
    }
    return filtered;
}

Printer& Printer::operator=(const Printer& pr){
    setID(pr.getID());
    setDescription(pr.getDescription());
    setBrand(pr.getBrand());
    setModel(pr.getModel());
    setPrice(pr.getPrice());
    setQuantity(pr.getQuantity());
    setOnDisplay(pr.getOnDisplay());
    setType(pr.getType());
    setHasScanner(pr.getHasScanner());
    setWireless(pr.getWireless());
    setSpeed(pr.getSpeed());
    setMaxRes(pr.getMaxRes());
    setDuplex(pr.getDuplex());
    setInkOrToner(std::get<0>(pr.getInkOrToner()), std::get<1>(pr.getInkOrToner()));
    setDimensions(std::get<0>(pr.getDimensions()), std::get<1>(pr.getDimensions()), std::get<2>(pr.getDimensions()));
    setWeight(pr.getWeight());
    setImagePath(pr.getImagePath());
    return *this;
}