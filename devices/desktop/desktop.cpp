#include "desktop.h"

Desktop::Desktop() : Devices(){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    motherboard = "-";
    psu = "-";
    pc_case = "-";
    cooling = "-";
    generateId();
}

Desktop::Desktop(const int q, const double p) : Devices(q, p){
    cpu = "-";
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    motherboard = "-";
    psu = "-";
    pc_case = "-";
    cooling = "-";
    generateId();
}

Desktop::Desktop(const std::string s) : Devices(){
    cpu = s;
    gpu = "-";
    memory = "-";
    storage = {};
    os = "-";
    motherboard = "-";
    psu = "-";
    pc_case = "-";
    cooling = "-";
}

void Desktop::setCPU(const std::string c){
    cpu = c;
}

void Desktop::setGPU(const std::string g){
    gpu = g;
}

void Desktop::setMemory(const std::string m){
    memory = m;
}

void Desktop::addStorage(const std::string s){
    storage.push_back(s);
}

void Desktop::clearStorage(){
    storage.clear();
}

void Desktop::setOS(const std::string o){
    os = o;
}

void Desktop::setMotherboard(const std::string mb){
    motherboard = mb;
}

void Desktop::setPSU(const std::string p){
    psu = p;
}

void Desktop::setPCCase(const std::string pc){
    pc_case = pc;
}

void Desktop::setCooling(const std::string c){
    cooling = c;
}

std::string Desktop::getCPU() const{
    return cpu;
}

std::string Desktop::getGPU() const{
    return gpu;
}

std::string Desktop::getMemory() const{
    return memory;
}

std::vector<std::string> Desktop::getStorage() const{
    return storage;
}

std::string Desktop::getOS() const{
    return os;
}

std::string Desktop::getMotherboard() const{
    return motherboard;
}

std::string Desktop::getPSU() const{
    return psu;
}

std::string Desktop::getPCCase() const{
    return pc_case;
}

std::string Desktop::getCooling() const{
    return cooling;
}

void Desktop::purchaseDevice(unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void Desktop::generateId(){
    std::ifstream file_in("../txt_files/desktop.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const Desktop& desktop: desktop_vec){
            std::string id = desktop.getID(); // AZ0001
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
    desktop_vec.push_back(*this);
    std::ofstream file_out("../txt_files/desktop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Desktop& desktop: desktop_vec){
        file_out << desktop.getID() << "|";
        file_out << desktop.getDescription() << "|";
        file_out << desktop.getBrand() << "|";
        file_out << desktop.getModel() << "|";
        file_out << desktop.getPrice() << "|";
        file_out << desktop.getQuantity() << "|";
        file_out << desktop.getOnDisplay() << "|";
        file_out << desktop.getCPU() << "|";
        file_out << desktop.getGPU() << "|";
        file_out << desktop.getMemory() << "|";
        for (std::string storage: desktop.getStorage()){
            file_out << storage << ",";
        }
        file_out << "|";
        file_out << desktop.getOS() << "|";
        file_out << desktop.getMotherboard() << "|";
        file_out << desktop.getPSU() << "|";
        file_out << desktop.getPCCase() << "|";
        file_out << cooling << "|";
        file_out << desktop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Desktop::updateVec(const Desktop dt_in){
    for (Desktop& dt: desktop_vec){
        if (dt.getID() == dt_in.getID()){
            dt.setDescription(dt_in.getDescription());
            dt.setBrand(dt_in.getBrand());
            dt.setModel(dt_in.getModel());
            dt.setPrice(dt_in.getPrice());
            dt.setQuantity(dt_in.getQuantity());
            dt.setOnDisplay(dt_in.getOnDisplay());
            dt.setCPU(dt_in.getCPU());
            dt.setGPU(dt_in.getGPU());
            dt.setMemory(dt_in.getMemory());
            dt.clearStorage();
            for (const std::string storage: dt_in.getStorage()){
                dt.addStorage(storage);
            }
            dt.setOS(dt_in.getOS());
            dt.setMotherboard(dt_in.getMotherboard());
            dt.setPSU(dt_in.getPSU());
            dt.setPCCase(dt_in.getPCCase());
            dt.setCooling(dt_in.getCooling());
            dt.setImagePath(dt_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/desktop.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File error" << std::endl;
        return;
    }
    for (const Desktop& desktop: desktop_vec){
        file_out << desktop.getID() << "|";
        file_out << desktop.getDescription() << "|";
        file_out << desktop.getBrand() << "|";
        file_out << desktop.getModel() << "|";
        file_out << desktop.getPrice() << "|";
        file_out << desktop.getQuantity() << "|";
        file_out << desktop.getOnDisplay() << "|";
        file_out << desktop.getCPU() << "|";
        file_out << desktop.getGPU() << "|";
        file_out << desktop.getMemory() << "|";
        for (const std::string storage: desktop.getStorage()){
            file_out << storage << ",";
        }
        file_out << "|";
        file_out << desktop.getOS() << "|";
        file_out << desktop.getMotherboard() << "|";
        file_out << desktop.getPSU() << "|";
        file_out << desktop.getPCCase() << "|";
        file_out << desktop.getCooling() << "|";
        file_out << desktop.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void Desktop::readData(){
    std::ifstream file_in("../txt_files/desktop.txt", std::ios::in);
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
    std::string motherboard;
    std::string psu;
    std::string pc_case;
    std::string cooling;
    std::string image_path;
    std::array<std::string*, 17> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &cpu, &gpu, &memory, &storage, &os, &motherboard, &psu, &pc_case, &cooling, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream rowstream(row);
        for (std::string* data_ptr: data){
            std::getline(rowstream, *data_ptr, '|');
        }
        Desktop dt("a");
        dt.setID(id);
        dt.setDescription(description);
        dt.setBrand(brand);
        dt.setModel(model);
        dt.setPrice(std::stod(price));
        dt.setQuantity(std::stoi(quantity));
        dt.setOnDisplay(std::stoi(on_display));
        dt.setCPU(cpu);
        dt.setGPU(gpu);
        dt.setMemory(memory);
        std::stringstream s_storage(storage);
        std::string storage_type;
        while (std::getline(s_storage, storage_type, ',')){
            dt.addStorage(storage_type);
        }
        dt.setOS(os);
        dt.setMotherboard(motherboard);
        dt.setPSU(psu);
        dt.setPCCase(pc_case);
        dt.setCooling(cooling);
        dt.setImagePath(image_path);
        desktop_vec.push_back(dt);
    }
    file_in.close();
    return;
}

void Desktop::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<Desktop> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Filter Brand" << std::endl;
        std::cout << "3. Filter CPU" << std::endl;
        std::cout << "4. Filter GPU" << std::endl;
        std::cout << "5. Filter OS" << std::endl;
        std::cout << "6. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        
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
            std::cout << "Enter Brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 3){
            std::cout << "Enter CPU: ";
            std::getline(std::cin, filter_input);
            filtered = filterCPU(filter_input);
        } else if (sort_option == 4){
            std::cout << "Enter GPU: ";
            std::getline(std::cin, filter_input);
            filtered = filterGPU(filter_input);
        } else if (sort_option == 5){
            std::cout << "Enter OS: ";
            std::getline(std::cin, filter_input);
            filtered = filterOS(filter_input);
        } else if (sort_option == 6){
            filtered = filterOnDisplay();
        } else {
            break;
        }
        if (sort_option < 2){
            for (const Desktop desktop: desktop_vec){
                std::cout << desktop << std::endl;
            }
        } else {
            for (const Desktop desktop: filtered){
                std::cout << desktop << std::endl;
            }
        }
    }
    return;
}

void Desktop::sortPrice(){
    std::sort(desktop_vec.begin(), desktop_vec.end(), [](const Desktop& dt1, const Desktop& dt2){
        return dt1.getPrice() < dt2.getPrice();
    });
    return;
}

std::vector<Desktop> Desktop::filterBrand(const std::string brand){
    std::vector<Desktop> filtered;
    for (const Desktop& dt: desktop_vec){
        if (dt.getBrand() == brand){
            filtered.push_back(dt);
        }
    }
    return filtered;
}

std::vector<Desktop> Desktop::filterCPU(const std::string cpu){
    std::vector<Desktop> filtered;
    for (const Desktop& dt: desktop_vec){
        if (dt.getCPU() == cpu){
            filtered.push_back(dt);
        }
    }
    return filtered;
}

std::vector<Desktop> Desktop::filterGPU(const std::string gpu){
    std::vector<Desktop> filtered;
    for (const Desktop& dt: desktop_vec){
        if (dt.getGPU() == gpu){
            filtered.push_back(dt);
        }
    }
    return filtered;
}

std::vector<Desktop> Desktop::filterOS(const std::string os){
    std::vector<Desktop> filtered;
    for (const Desktop& dt: desktop_vec){
        if (dt.getOS() == os){
            filtered.push_back(dt);
        }
    }
    return filtered;
}

std::vector<Desktop> Desktop::filterOnDisplay(){
    std::vector<Desktop> filtered;
    for (const Desktop& dt: desktop_vec){
        if (dt.getOnDisplay() == 1){
            filtered.push_back(dt);
        }
    }
    return filtered;
}

Desktop& Desktop::operator=(const Desktop& dt){
    setID(dt.getID());
    setDescription(dt.getDescription());
    setBrand(dt.getBrand());
    setModel(dt.getModel());
    setPrice(dt.getPrice());
    setQuantity(dt.getQuantity());
    setOnDisplay(dt.getOnDisplay());
    setCPU(dt.getCPU());
    setGPU(dt.getGPU());
    setMemory(dt.getMemory());
    clearStorage();
    for (const std::string storage: dt.getStorage()){
        addStorage(storage);
    }
    setOS(dt.getOS());
    setMotherboard(dt.getMotherboard());
    setPSU(dt.getPSU());
    setPCCase(dt.getPCCase());
    setCooling(dt.getCooling());
    setImagePath(dt.getImagePath());
    return *this;
}