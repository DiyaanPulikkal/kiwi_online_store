#include "laptop.h"

Laptop::Laptop() : Devices(){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    display = "-";
    battery = std::make_tuple(0.0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0, 0.0);
    weight = 0.0;
    is_touchscreen = false;
    is_gaming = false;
    generateId();
}

Laptop::Laptop(const int q, const double p) : Devices(q, p){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    display = "-";
    battery = std::make_tuple(0.0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0, 0.0);
    weight = 0.0;
    is_touchscreen = false;
    is_gaming = false;
    generateId();
}

Laptop::Laptop(const std::string s) : Devices(){
    cpu = s;
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    display = "-";
    battery = std::make_tuple(0.0, 0);
    dimensions = std::make_tuple(0.0, 0.0, 0.0, 0.0);
    weight = 0.0;
    is_touchscreen = false;
    is_gaming = false;
}

void Laptop::setCPU(const std::string c){
    cpu = c;
}

void Laptop::setGPU(const std::string g){
    gpu = g;
}

void Laptop::setMemory(const std::string m){
    memory = m;
}

void Laptop::addStorage(const std::string s){
    storage.push_back(s);
}

void Laptop::clearStorage(){
    storage.clear();
}

void Laptop::setOS(const std::string o){
    os = o;
}

void Laptop::setDisplay(const std::string d){
    display = d;
}

void Laptop::setBattery(const double c, const int n){
    battery = std::make_tuple(c, n);
}

void Laptop::setDimensions(const double l, const double w, const double h, const double d){
    dimensions = std::make_tuple(l, w, h, d);
}

void Laptop::setWeight(const double w){
    weight = w;
}

void Laptop::setTouchscreen(const bool t){
    is_touchscreen = t;
}

void Laptop::setGaming(const bool g){
    is_gaming = g;
}

std::string Laptop::getCPU() const{
    return cpu;
}

std::string Laptop::getGPU() const{
    return gpu;
}

std::string Laptop::getMemory() const{
    return memory;
}

std::vector<std::string> Laptop::getStorage() const{
    return storage;
}

std::string Laptop::getOS() const{
    return os;
}

std::string Laptop::getDisplay() const{
    return display;
}

std::tuple<double, int> Laptop::getBattery() const{
    return battery;
}

std::tuple<double, double, double, double> Laptop::getDimensions() const{
    return dimensions;
}

double Laptop::getWeight() const{
    return weight;
}

bool Laptop::getTouchscreen() const{
    return is_touchscreen;
}

bool Laptop::getGaming() const{
    return is_gaming;
}

void Laptop::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Laptop::generateId(){
    std::ifstream file_in("../txt_files/laptop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Laptop& laptop: laptop_vec){
            std::string id = laptop.getID();
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
    laptop_vec.push_back(*this);
    std::ofstream file_out("../txt_files/laptop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Laptop& laptop: laptop_vec){
        file_out << laptop.getID() << "|";
        file_out << laptop.getDescription() << "|";
        file_out << laptop.getBrand() << "|";
        file_out << laptop.getModel() << "|";
        file_out << laptop.getPrice() << "|";
        file_out << laptop.getQuantity() << "|";
        file_out << laptop.getOnDisplay() << "|";
        file_out << laptop.getCPU() << "|";
        file_out << laptop.getGPU() << "|";
        file_out << laptop.getMemory() << "|";
        for (const std::string s: laptop.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << laptop.getOS() << "|";
        file_out << laptop.getDisplay() << "|";
        file_out << std::get<0>(laptop.getBattery()) << "|"; 
        file_out << std::get<1>(laptop.getBattery()) << "|";
        file_out << std::get<0>(laptop.getDimensions()) << "|";
        file_out << std::get<1>(laptop.getDimensions()) << "|";
        file_out << std::get<2>(laptop.getDimensions()) << "|";
        file_out << std::get<3>(laptop.getDimensions()) << "|";
        file_out << laptop.getWeight() << "|";
        file_out << laptop.getTouchscreen() << "|";
        file_out << laptop.getGaming() << "|";
        file_out << laptop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Laptop::updateVec(const Laptop lap_in){
    for (Laptop& lap: laptop_vec){
        if (lap.getID() == lap_in.getID()){
            lap.setDescription(lap_in.getDescription());
            lap.setBrand(lap_in.getBrand());
            lap.setModel(lap_in.getModel());
            lap.setPrice(lap_in.getPrice());
            lap.setQuantity(lap_in.getQuantity());
            lap.setOnDisplay(lap_in.getOnDisplay());
            lap.setCPU(lap_in.getCPU());
            lap.setGPU(lap_in.getGPU());
            lap.setMemory(lap_in.getMemory());
            lap.clearStorage();
            for (const std::string storage: lap_in.getStorage()){
                lap.addStorage(storage);
            }
            lap.setOS(lap_in.getOS());
            lap.setDisplay(lap_in.getDisplay());
            lap.setBattery(std::get<0>(lap_in.getBattery()), std::get<1>(lap_in.getBattery()));
            lap.setDimensions(std::get<0>(lap_in.getDimensions()), 
                            std::get<1>(lap_in.getDimensions()), 
                            std::get<2>(lap_in.getDimensions()), 
                            std::get<3>(lap_in.getDimensions()));
            lap.setWeight(lap_in.getWeight());
            lap.setTouchscreen(lap_in.getTouchscreen());
            lap.setGaming(lap_in.getGaming());
            lap.setImagePath(lap_in.getImagePath());
            break;            
        }
    }
    std::ofstream file_out("../txt_files/laptop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const Laptop& laptop: laptop_vec){
        file_out << laptop.getID() << "|";
        file_out << laptop.getDescription() << "|";
        file_out << laptop.getBrand() << "|";
        file_out << laptop.getModel() << "|";
        file_out << laptop.getPrice() << "|";
        file_out << laptop.getQuantity() << "|";
        file_out << laptop.getOnDisplay() << "|";
        file_out << laptop.getCPU() << "|";
        file_out << laptop.getGPU() << "|";
        file_out << laptop.getMemory() << "|";
        for (const std::string s: laptop.getStorage()){
            file_out << s << ",";
        }
        file_out << "|";
        file_out << laptop.getOS() << "|";
        file_out << laptop.getDisplay() << "|";
        file_out << std::get<0>(laptop.getBattery()) << "|"; 
        file_out << std::get<1>(laptop.getBattery()) << "|";
        file_out << std::get<0>(laptop.getDimensions()) << "|";
        file_out << std::get<1>(laptop.getDimensions()) << "|";
        file_out << std::get<2>(laptop.getDimensions()) << "|";
        file_out << std::get<3>(laptop.getDimensions()) << "|";
        file_out << laptop.getWeight() << "|";
        file_out << laptop.getTouchscreen() << "|";
        file_out << laptop.getGaming() << "|";
        file_out << laptop.getImagePath();
        file_out << std::endl;
    }
}

void Laptop::readData(){
    std::ifstream file_in("../txt_files/laptop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string cpu;
    std::string gpu;
    std::string memory;
    std::string storage;
    std::string os;
    std::string display;
    std::string battery_capacity;
    std::string battery_no_cells;
    std::string length;
    std::string width;
    std::string height;
    std::string diagonal;
    std::string weight;
    std::string touchscreen;
    std::string gaming;
    std::string image_path;
    std::array<std::string*, 24> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &cpu, &gpu, &memory, &storage, &os, &display, &battery_capacity, &battery_no_cells, &length, &width, &height, &diagonal, &weight, &touchscreen, &gaming, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Laptop lap("a");
        lap.setID(id);
        lap.setDescription(description);
        lap.setBrand(brand);
        lap.setModel(model);
        lap.setPrice(std::stod(price));
        lap.setQuantity(std::stoi(quantity));
        lap.setOnDisplay(std::stoi(on_display));
        lap.setCPU(cpu);
        lap.setGPU(gpu);
        lap.setMemory(memory);
        std::stringstream s_storage(storage);
        std::string storage_type;
        while (std::getline(s_storage, storage_type, ',')){
            lap.addStorage(storage_type);
        }
        lap.setOS(os);
        lap.setDisplay(display);
        lap.setBattery(std::stod(battery_capacity), std::stoi(battery_no_cells));
        lap.setDimensions(std::stod(length), std::stod(width), std::stod(height), std::stod(diagonal));
        lap.setWeight(std::stod(weight));
        lap.setTouchscreen(std::stoi(touchscreen));
        lap.setGaming(std::stoi(gaming));
        lap.setImagePath(image_path);
        laptop_vec.push_back(lap);
    }
    file_in.close();
    return;
}

void Laptop::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Laptop> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Battery" << std::endl;
        std::cout << "3. Dimensions" << std::endl;
        std::cout << "4. Weight" << std::endl;
        std::cout << "5. Filter Brand" << std::endl;
        std::cout << "6. Filter CPU" << std::endl;
        std::cout << "7. Filter GPU" << std::endl;
        std::cout << "8. Filter OS" << std::endl;
        std::cout << "9. Filter Touchscreen" << std::endl;
        std::cout << "10. Filter Gaming" << std::endl;
        std::cout << "11. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 11 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 9: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortBattery();
        } else if (sort_option == 3){
            sortDimensions();
        } else if (sort_option == 4){
            sortWeight();
        } else if (sort_option == 5){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 6){
            std::cout << "Enter CPU: ";
            std::getline(std::cin, filter_input);
            filtered = filterCPU(filter_input);
        } else if (sort_option == 7){
            std::cout << "Enter GPU: ";
            std::getline(std::cin, filter_input);
            filtered = filterGPU(filter_input);
        } else if (sort_option == 8){
            std::cout << "Enter OS: ";
            std::getline(std::cin, filter_input);
            filtered = filterOS(filter_input);
        } else if (sort_option == 9){
            std::cout << "Enter 1 for touchscreen, 0 for non-touchscreen: ";
            std::getline(std::cin, filter_input);
            while (true){
                try{
                    unsigned int touchscreen_input = std::stoi(filter_input);
                    if (touchscreen_input != 0 && touchscreen_input != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterTouchscreen(touchscreen_input);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, filter_input);
                }
            }
        } else if (sort_option == 10){
            std::cout << "Enter 1 for gaming, 0 for non-gaming: ";
            std::getline(std::cin, filter_input);
            while (true){
                try{
                    unsigned int gaming_input = std::stoi(filter_input);
                    if (gaming_input != 0 && gaming_input != 1){
                        throw std::invalid_argument("");
                    }
                    filtered = filterGaming(gaming_input);
                    break;
                } catch (std::invalid_argument){
                    std::cout << "Please enter 1 or 0: ";
                    std::getline(std::cin, filter_input);
                }
            }
        } else if (sort_option == 11){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 5){
            for (const Laptop laptop: laptop_vec){
                std::cout << laptop;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Battery: " << std::get<0>(laptop.getBattery()) << " Wh, " << std::get<1>(laptop.getBattery()) << " cells" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Dimensions: " << std::get<0>(laptop.getDimensions()) << " x " << std::get<1>(laptop.getDimensions()) << " x " << std::get<2>(laptop.getDimensions()) << " x " << std::get<3>(laptop.getDimensions()) << " inches" << std::endl;
                    break;
                
                case 4:
                    std::cout << "      " << "Weight: " << laptop.getWeight() << " kg" << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const Laptop laptop: filtered){
                std::cout << laptop << std::endl;
            }
        }
    }
    return;
}

void Laptop::sortPrice(){
    std::sort(laptop_vec.begin(), laptop_vec.end(), [](const Laptop &lap1, const Laptop &lap2){
        return lap1.getPrice() < lap2.getPrice();
    });
}

void Laptop::sortBattery(){
    std::sort(laptop_vec.begin(), laptop_vec.end(), [](const Laptop &lap1, const Laptop &lap2){
        return std::get<0>(lap1.getBattery()) < std::get<0>(lap2.getBattery());
    });
}

void Laptop::sortDimensions(){
    std::sort(laptop_vec.begin(), laptop_vec.end(), [](const Laptop &lap1, const Laptop &lap2){
        return std::get<3>(lap1.getDimensions()) < std::get<3>(lap2.getDimensions());
    });
}

void Laptop::sortWeight(){
    std::sort(laptop_vec.begin(), laptop_vec.end(), [](const Laptop &lap1, const Laptop &lap2){
        return lap1.getWeight() < lap2.getWeight();
    });
}

std::vector<Laptop> Laptop::filterBrand(const std::string brand){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getBrand() == brand){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterCPU(const std::string cpu){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getCPU() == cpu){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterGPU(const std::string gpu){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getGPU() == gpu){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterOS(const std::string os){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getOS() == os){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterTouchscreen(const bool touchscreen){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getTouchscreen() == touchscreen){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterGaming(const bool gaming){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getGaming() == gaming){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

std::vector<Laptop> Laptop::filterOnDisplay(){
    std::vector<Laptop> filtered_laptop;
    for (const Laptop lap: laptop_vec){
        if (lap.getOnDisplay() == 1){
            filtered_laptop.push_back(lap);
        }
    }
    return filtered_laptop;
}

Laptop& Laptop::operator=(const Laptop &lap){
    setID(lap.getID());
    setDescription(lap.getDescription());
    setBrand(lap.getBrand());
    setModel(lap.getModel());
    setPrice(lap.getPrice());
    setQuantity(lap.getQuantity());
    setOnDisplay(lap.getOnDisplay());
    setCPU(lap.getCPU());
    setGPU(lap.getGPU());
    setMemory(lap.getMemory());
    clearStorage();
    for (const std::string storage: lap.getStorage()){
        addStorage(storage);
    }
    setOS(lap.getOS());
    setDisplay(lap.getDisplay());
    setBattery(std::get<0>(lap.getBattery()), std::get<1>(lap.getBattery()));
    setDimensions(std::get<0>(lap.getDimensions()), 
                std::get<1>(lap.getDimensions()), 
                std::get<2>(lap.getDimensions()), 
                std::get<3>(lap.getDimensions()));
    setWeight(lap.getWeight());
    setTouchscreen(lap.getTouchscreen());
    setGaming(lap.getGaming());
    setImagePath(lap.getImagePath());
    return *this;
}
