#include "cpu.h"

CPU::CPU() : ComputerParts(){
    socket = "-";
    form_factor = "-";
    core_no = 0;
    thread_no = 0;
    base_clock = 0.0;
    boost_clock = 0.0;
    has_overclock = false;
    memory_support = std::make_tuple("-", 0, 0);
    integrated_graphics = "-";
    generateId();
}

CPU::CPU(const int q, const double p) : ComputerParts(q, p){
    socket = "-";
    form_factor = "-";
    core_no = 0;
    thread_no = 0;
    base_clock = 0.0;
    boost_clock = 0.0;
    has_overclock = false;
    memory_support = std::make_tuple("-", 0, 0);
    integrated_graphics = "-";
    generateId();
}

CPU::CPU(const std::string s) : ComputerParts(){
    socket = s;
    form_factor = "-";
    core_no = 0;
    thread_no = 0;
    base_clock = 0.0;
    boost_clock = 0.0;
    has_overclock = false;
    memory_support = std::make_tuple("-", 0, 0);
    integrated_graphics = "-";
}

void CPU::setSocket(const std::string s){
    socket = s;
}

void CPU::setFormFactor(const std::string ff){
    form_factor = ff;
}

void CPU::setCoreNo(const int cn){
    core_no = cn;
}

void CPU::setThreadNo(const int tn){
    thread_no = tn;
}

void CPU::setBaseClock(const double basec){
    base_clock = basec;
}

void CPU::setBoostClock(const double boostc){
    boost_clock = boostc;
}

void CPU::setHasOverclock(const bool h_oc){
    has_overclock = h_oc;
}

void CPU::setMemorySupport(const std::string type, const int freq, const int no){
    memory_support = std::make_tuple(type, freq, no);
}

void CPU::setIntegratedGraphics(const std::string ig){
    integrated_graphics = ig;
}

std::string CPU::getSocket() const{
    return socket;
}

std::string CPU::getFormFactor() const{
    return form_factor;
}

int CPU::getCoreNo() const{
    return core_no;
}

int CPU::getThreadNo() const{
    return thread_no;
}

double CPU::getBaseClock() const{
    return base_clock;
}

double CPU::getBoostClock() const{
    return boost_clock;
}

bool CPU::getHasOverclock() const{
    return has_overclock;
}

std::tuple<std::string, int, int> CPU::getMemorySupport() const{
    return memory_support;
}

std::string CPU::getIntegratedGraphics() const{
    return integrated_graphics;
}

void CPU::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void CPU::generateId(){
    std::ifstream file_in("../txt_files/cpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const CPU& cpu: cpu_vec){
            std::string id = cpu.getID(); // AZ0001
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
    cpu_vec.push_back(*this);
    std::ofstream file_out("../txt_files/cpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CPU& cpu: cpu_vec){
        file_out << cpu.getID() << "|";
        file_out << cpu.getDescription() << "|";
        file_out << cpu.getBrand() << "|";
        file_out << cpu.getModel() << "|";
        file_out << cpu.getPrice() << "|";
        file_out << cpu.getQuantity() << "|";
        file_out << cpu.getOnDisplay() << "|";
        file_out << cpu.getSocket() << "|";
        file_out << cpu.getFormFactor() << "|";
        file_out << cpu.getCoreNo() << "|";
        file_out << cpu.getThreadNo() << "|";
        file_out << cpu.getBaseClock() << "|";
        file_out << cpu.getBoostClock() << "|";
        file_out << cpu.getHasOverclock() << "|";
        file_out << std::get<0>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<1>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<2>(cpu.getMemorySupport()) << "|";
        file_out << cpu.getIntegratedGraphics() << "|";
        file_out << cpu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CPU::updateVec(const CPU cpu_in){
    for (CPU& cpu: cpu_vec){
        if (cpu.getID() == cpu_in.getID()){
            cpu.setDescription(cpu_in.getDescription());
            cpu.setBrand(cpu_in.getBrand());
            cpu.setModel(cpu_in.getModel());
            cpu.setPrice(cpu_in.getPrice());
            cpu.setQuantity(cpu_in.getQuantity());
            cpu.setOnDisplay(cpu_in.getOnDisplay());
            cpu.setSocket(cpu_in.getSocket());
            cpu.setFormFactor(cpu_in.getFormFactor());
            cpu.setCoreNo(cpu_in.getCoreNo());
            cpu.setThreadNo(cpu_in.getThreadNo());
            cpu.setBaseClock(cpu_in.getBaseClock());
            cpu.setBoostClock(cpu_in.getBoostClock());
            cpu.setHasOverclock(cpu_in.getHasOverclock());
            cpu.setMemorySupport(std::get<0>(cpu_in.getMemorySupport()),
                                 std::get<1>(cpu_in.getMemorySupport()),
                                 std::get<2>(cpu_in.getMemorySupport()));
            cpu.setIntegratedGraphics(cpu_in.getIntegratedGraphics());
            cpu.setImagePath(cpu_in.getImagePath());
            break;
        }
    }
    std::ofstream file_out("../txt_files/cpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const CPU& cpu: cpu_vec){
        file_out << cpu.getID() << "|";
        file_out << cpu.getDescription() << "|";
        file_out << cpu.getBrand() << "|";
        file_out << cpu.getModel() << "|";
        file_out << cpu.getPrice() << "|";
        file_out << cpu.getQuantity() << "|";
        file_out << cpu.getOnDisplay() << "|";
        file_out << cpu.getSocket() << "|";
        file_out << cpu.getFormFactor() << "|";
        file_out << cpu.getCoreNo() << "|";
        file_out << cpu.getThreadNo() << "|";
        file_out << cpu.getBaseClock() << "|";
        file_out << cpu.getBoostClock() << "|";
        file_out << cpu.getHasOverclock() << "|";
        file_out << std::get<0>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<1>(cpu.getMemorySupport()) << "|"; 
        file_out << std::get<2>(cpu.getMemorySupport()) << "|";
        file_out << cpu.getIntegratedGraphics() << "|";
        file_out << cpu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void CPU::readData(){
    std::ifstream file_in("../txt_files/cpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, desc, brand, model, price, quantity, on_display;
    std::string socket;
    std::string form_factor;
    std::string core_no;
    std::string thread_no;
    std::string base_clock;
    std::string boost_clock;
    std::string has_overclock;
    std::string type;
    std::string freq;
    std::string no;
    std::string integrated_graphics;
    std::string image_path;
    std::array<std::string*, 19> data{&id, &desc, &brand, &model, &price, &quantity, &on_display, &socket, &form_factor, &core_no, &thread_no, &base_clock, &boost_clock, &has_overclock, &type, &freq, &no, &integrated_graphics, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        CPU cpu("a");
        cpu.setID(id);
        cpu.setDescription(desc);
        cpu.setBrand(brand);
        cpu.setModel(model);
        cpu.setPrice(std::stod(price));
        cpu.setQuantity(std::stoi(quantity));
        cpu.setOnDisplay(std::stoi(on_display));
        cpu.setSocket(socket);
        cpu.setFormFactor(form_factor);
        cpu.setCoreNo(std::stoi(core_no));
        cpu.setThreadNo(std::stoi(thread_no));
        cpu.setBaseClock(std::stod(base_clock));
        cpu.setBoostClock(std::stod(boost_clock));
        cpu.setHasOverclock(std::stoi(has_overclock));
        cpu.setMemorySupport(type, std::stoi(freq), std::stoi(no));
        cpu.setIntegratedGraphics(integrated_graphics);
        cpu.setImagePath(image_path);
        cpu_vec.push_back(cpu);
    }
    file_in.close();
    return;
}

void CPU::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<CPU> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Core No." << std::endl;
        std::cout << "3. Thread No." << std::endl;
        std::cout << "4. Base Clock" << std::endl;
        std::cout << "5. Boost Clock" << std::endl;
        std::cout << "6. Memory Frequency" << std::endl;
        std::cout << "7. Memory No." << std::endl;
        std::cout << "8. Filter Brand" << std::endl;
        std::cout << "9. Filter Socket" << std::endl;
        std::cout << "10. Filter Form Factor" << std::endl;
        std::cout << "11. Filter Overclock" << std::endl;
        std::cout << "12. Filter Memory Type" << std::endl;
        std::cout << "13. Filter Integrated Graphics" << std::endl;
        std::cout << "14. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 14 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 14: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortCoreNo();
        } else if (sort_option == 3){
            sortThreadNo();
        } else if (sort_option == 4){
            sortBaseClock();
        } else if (sort_option == 5){
            sortBoostClock();
        } else if (sort_option == 6){
            sortMemoryFreq();
        } else if (sort_option == 7){
            sortMemoryNo();
        } else if (sort_option == 8){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 9){
            std::cout << "Enter socket: ";
            std::getline(std::cin, filter_input);
            filtered = filterSocket(filter_input);
        } else if (sort_option == 10){
            std::cout << "Enter form factor: ";
            std::getline(std::cin, filter_input);
            filtered = filterFormFactor(filter_input);
        } else if (sort_option == 11){
            std::cout << "Enter 1 for overclockable, 0 for non-overclockable: ";
            std::getline(std::cin, filter_input);
            filtered = filterOverclock(std::stoi(filter_input));
        } else if (sort_option == 12){
            std::cout << "Enter memory type: ";
            std::getline(std::cin, filter_input);
            filtered = filterMemoryType(filter_input);
        } else if (sort_option == 13){
            std::cout << "Enter integrated graphics: ";
            std::getline(std::cin, filter_input);
            filtered = filterIntegratedGraphics(filter_input);
        } else if (sort_option == 14){
            filtered = filterOnDisplay();
        } else{
            break;
        }
        if (sort_option < 8){
            for (const CPU cpu: cpu_vec){
                std::cout << cpu;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Core No.: " << cpu.getCoreNo() << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Thread No.: " << cpu.getThreadNo() << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Base Clock: " << cpu.getBaseClock() << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Boost Clock: " << cpu.getBoostClock() << std::endl;
                    break;

                case 6:
                    std::cout << "      " << "Memory Frequency: " << std::get<1>(cpu.getMemorySupport()) << std::endl;
                    break;

                case 7:
                    std::cout << "      " << "Memory No.: " << std::get<2>(cpu.getMemorySupport()) << std::endl;
                    break;
                
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const CPU cpu: filtered){
                std::cout << cpu << std::endl;
            }
        }
    }
    return;
}

void CPU::sortPrice(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return a.getPrice() < b.getPrice();
    });
}

void CPU::sortCoreNo(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return a.getCoreNo() < b.getCoreNo();
    });
}

void CPU::sortThreadNo(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return a.getThreadNo() < b.getThreadNo();
    });
}

void CPU::sortBaseClock(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return a.getBaseClock() < b.getBaseClock();
    });
}

void CPU::sortBoostClock(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return a.getBoostClock() < b.getBoostClock();
    });
}

void CPU::sortMemoryFreq(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return std::get<1>(a.getMemorySupport()) < std::get<1>(b.getMemorySupport());
    });
}

void CPU::sortMemoryNo(){
    std::sort(cpu_vec.begin(), cpu_vec.end(), [](const CPU& a, const CPU& b){
        return std::get<2>(a.getMemorySupport()) < std::get<2>(b.getMemorySupport());
    });
}

std::vector<CPU> CPU::filterBrand(const std::string brand){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getBrand() == brand){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterSocket(const std::string socket){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getSocket() == socket){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterFormFactor(const std::string form_factor){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getFormFactor() == form_factor){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterOverclock(const bool has_overclock){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getHasOverclock() == has_overclock){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterMemoryType(const std::string type){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (std::get<0>(cpu.getMemorySupport()) == type){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterIntegratedGraphics(const std::string ig){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getIntegratedGraphics() == ig){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

std::vector<CPU> CPU::filterOnDisplay(){
    std::vector<CPU> filtered;
    for (const CPU cpu: cpu_vec){
        if (cpu.getOnDisplay()){
            filtered.push_back(cpu);
        }
    }
    return filtered;
}

CPU& CPU::operator=(const CPU& cpu){
    setID(cpu.getID());
    setDescription(cpu.getDescription());
    setBrand(cpu.getBrand());
    setModel(cpu.getModel());
    setPrice(cpu.getPrice());
    setQuantity(cpu.getQuantity());
    setOnDisplay(cpu.getOnDisplay());
    setSocket(cpu.getSocket());
    setFormFactor(cpu.getFormFactor());
    setCoreNo(cpu.getCoreNo());
    setThreadNo(cpu.getThreadNo());
    setBaseClock(cpu.getBaseClock());
    setBoostClock(cpu.getBoostClock());
    setHasOverclock(cpu.getHasOverclock());
    setMemorySupport(std::get<0>(cpu.getMemorySupport()),
                     std::get<1>(cpu.getMemorySupport()),
                     std::get<2>(cpu.getMemorySupport()));
    setIntegratedGraphics(cpu.getIntegratedGraphics());
    setImagePath(cpu.getImagePath());
    return *this;
}