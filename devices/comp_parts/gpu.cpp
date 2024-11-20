#include "gpu.h"

GPU::GPU(): ComputerParts(){
    base_clock = 0.0;
    boost_clock = 0.0;
    memory_support = std::make_tuple("-", 0, 0); // type, vram, buswidth
    output_ports = {};
    power_consumption = std::make_tuple(0.0, 0); // power consumption, pin
    cooling_type = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    kiwi_benchmark_score = 0;
    generateId();
}

GPU::GPU(const int q, const double p) : ComputerParts(q, p){
    base_clock = 0.0;
    boost_clock = 0.0;
    memory_support = std::make_tuple("-", 0, 0); // type, vram, buswidth
    output_ports = {};
    power_consumption = std::make_tuple(0.0, 0); // power consumption, pin
    cooling_type = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    kiwi_benchmark_score = 0;
    generateId();
}

GPU::GPU(const std::string s) : ComputerParts(){
    base_clock = 0.0;
    boost_clock = 0.0;
    memory_support = std::make_tuple("-", 0, 0); // type, vram, buswidth
    output_ports = {};
    power_consumption = std::make_tuple(0.0, 0); // power consumption, pin
    cooling_type = "-";
    dimension = std::make_tuple(0.0, 0.0, 0.0);
    kiwi_benchmark_score = 0;
}

void GPU::setBaseClock(const double bc){
    base_clock = bc;
}

void GPU::setBoostClock(const double bc){
    boost_clock = bc;
}

void GPU::setMemorySupport(const std::string type, const int vram, const int buswidth){
    memory_support = std::make_tuple(type, vram, buswidth);
}

void GPU::addOutputPorts(const std::string op){
    output_ports.push_back(op);
}

void GPU::setPowerConsumption(const double pc, const int pin){
    power_consumption = std::make_tuple(pc, pin);
}

void GPU::setCoolingType(const std::string ct){
    cooling_type = ct;
}

void GPU::setDimension(const double l, const double w, const double h){
    dimension = std::make_tuple(l, w, h);
}

void GPU::setBenchmarkScore(const int bs){
    kiwi_benchmark_score = bs;
}

void GPU::clearOutputPorts(){
    output_ports.clear();
}

double GPU::getBaseClock() const{
    return base_clock;
}

double GPU::getBoostClock() const{
    return boost_clock;
}

std::tuple<std::string, int, int> GPU::getMemorySupport() const{
    return memory_support;
}

std::vector<std::string> GPU::getOutputPorts() const{
    return output_ports;
}

std::tuple<double, int> GPU::getPowerConsumption() const{
    return power_consumption;
}

std::string GPU::getCoolingType() const{
    return cooling_type;
}

std::tuple<double, double, double> GPU::getDimension() const{
    return dimension;
}

int GPU::getBenchmarkScore() const{
    return kiwi_benchmark_score;
}

void GPU::purchaseDevice(const unsigned int q){
    Devices::purchaseDevice(q);
    updateVec(*this);
}

void GPU::generateId(){
    std::ifstream file_in("../txt_files/gpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()) {
        setID(id_start + "0000");
    } else {
        unsigned int max_id = 0;
        for (const GPU& gpu: gpu_vec){
            std::string id = gpu.getID(); // AZ0001
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
    gpu_vec.push_back(*this);
    std::ofstream file_out("../txt_files/gpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const GPU& gpu: gpu_vec){
        file_out << gpu.getID() << "|";
        file_out << gpu.getDescription() << "|";
        file_out << gpu.getBrand() << "|";
        file_out << gpu.getModel() << "|";
        file_out << gpu.getPrice() << "|";
        file_out << gpu.getQuantity() << "|";
        file_out << gpu.getOnDisplay() << "|";
        file_out << gpu.getBaseClock() << "|";
        file_out << gpu.getBoostClock() << "|";
        file_out << std::get<0>(gpu.getMemorySupport()) << "|";
        file_out << std::get<1>(gpu.getMemorySupport()) << "|";
        file_out << std::get<2>(gpu.getMemorySupport()) << "|";
        for (std::string op: gpu.getOutputPorts()){
            file_out << op << ",";
        }
        file_out << "|";
        file_out << std::get<0>(gpu.getPowerConsumption()) << "|";
        file_out << std::get<1>(gpu.getPowerConsumption()) << "|";
        file_out << gpu.getCoolingType() << "|";
        file_out << std::get<0>(gpu.getDimension()) << "|";
        file_out << std::get<1>(gpu.getDimension()) << "|";
        file_out << std::get<2>(gpu.getDimension()) << "|";
        file_out << gpu.getBenchmarkScore() << "|";
        file_out << gpu.getImagePath();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void GPU::updateVec(const GPU gpu_in){
    for (GPU& gpu: gpu_vec){
        if (gpu.getID() == gpu_in.getID()){
            gpu.setDescription(gpu_in.getDescription());
            gpu.setBrand(gpu_in.getBrand());
            gpu.setModel(gpu_in.getModel());
            gpu.setPrice(gpu_in.getPrice());
            gpu.setQuantity(gpu_in.getQuantity());
            gpu.setOnDisplay(gpu_in.getOnDisplay());
            gpu.setBaseClock(gpu_in.getBaseClock());
            gpu.setBoostClock(gpu_in.getBoostClock());
            gpu.setMemorySupport(std::get<0>(gpu_in.getMemorySupport()),
                                 std::get<1>(gpu_in.getMemorySupport()),
                                 std::get<2>(gpu_in.getMemorySupport()));
            gpu.clearOutputPorts();
            for (std::string op: gpu_in.getOutputPorts()){
                gpu.addOutputPorts(op);
            }
            gpu.setPowerConsumption(std::get<0>(gpu_in.getPowerConsumption()),
                                    std::get<1>(gpu_in.getPowerConsumption()));
            gpu.setCoolingType(gpu_in.getCoolingType());
            gpu.setDimension(std::get<0>(gpu_in.getDimension()),
                             std::get<1>(gpu_in.getDimension()),
                             std::get<2>(gpu_in.getDimension()));
            gpu.setBenchmarkScore(gpu_in.getBenchmarkScore());
            break;
        }
    }
    std::ofstream file_out("../txt_files/gpu.txt", std::ios::out);
    if (!file_out.is_open() || file_out.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    for (const GPU& gpu: gpu_vec){
        file_out << gpu.getID() << "|";
        file_out << gpu.getDescription() << "|";
        file_out << gpu.getBrand() << "|";
        file_out << gpu.getModel() << "|";
        file_out << gpu.getPrice() << "|";
        file_out << gpu.getQuantity() << "|";
        file_out << gpu.getOnDisplay() << "|";
        file_out << gpu.getBaseClock() << "|";
        file_out << gpu.getBoostClock() << "|";
        file_out << std::get<0>(gpu.getMemorySupport()) << "|";
        file_out << std::get<1>(gpu.getMemorySupport()) << "|";
        file_out << std::get<2>(gpu.getMemorySupport()) << "|";
        for (std::string op: gpu.getOutputPorts()){
            file_out << op << ",";
        }
        file_out << "|";
        file_out << std::get<0>(gpu.getPowerConsumption()) << "|";
        file_out << std::get<1>(gpu.getPowerConsumption()) << "|";
        file_out << gpu.getCoolingType() << "|";
        file_out << std::get<0>(gpu.getDimension()) << "|";
        file_out << std::get<1>(gpu.getDimension()) << "|";
        file_out << std::get<2>(gpu.getDimension()) << "|";
        file_out << gpu.getBenchmarkScore();
        file_out << std::endl;
    }
    file_out.close();
    return;
}

void GPU::readData(){
    std::ifstream file_in("../txt_files/gpu.txt", std::ios::in);
    if (!file_in.is_open() || file_in.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (file_in.peek() == std::ifstream::traits_type::eof()){
        file_in.close();
        return;
    }
    std::string id, description, brand, model, price, quantity, on_display;
    std::string base_clock;
    std::string boost_clock;
    std::string type;
    std::string vram;
    std::string buswidth;
    std::string output_ports;
    std::string power_consumption;
    std::string pin;
    std::string cooling_type;
    std::string length;
    std::string width;
    std::string height;
    std::string kiwi_benchmark_score;
    std::string image_path;
    std::array<std::string*, 21> data{&id, &description, &brand, &model, &price, &quantity, &on_display, &base_clock, &boost_clock, &type, &vram, &buswidth, &output_ports, &power_consumption, &pin, &cooling_type, &length, &width, &height, &kiwi_benchmark_score, &image_path};

    std::string row;
    while (std::getline(file_in, row)){
        std::istringstream s_row(row);
        for (std::string* data_ptr: data){
            std::getline(s_row, *data_ptr, '|');
        }
        GPU gpu("a");
        gpu.setID(id);
        gpu.setDescription(description);
        gpu.setBrand(brand);
        gpu.setModel(model);
        gpu.setPrice(std::stod(price));
        gpu.setQuantity(std::stoi(quantity));
        gpu.setOnDisplay(std::stoi(on_display));
        gpu.setBaseClock(std::stod(base_clock));
        gpu.setBoostClock(std::stod(boost_clock));
        gpu.setMemorySupport(type, std::stoi(vram), std::stoi(buswidth));
        std::stringstream ss_output_ports(output_ports);
        std::string output_port;
        while (std::getline(ss_output_ports, output_port, ',')){
            gpu.addOutputPorts(output_port);
        }
        gpu.setPowerConsumption(std::stod(power_consumption), std::stoi(pin));
        gpu.setCoolingType(cooling_type);
        gpu.setDimension(std::stod(length), std::stod(width), std::stod(height));
        gpu.setBenchmarkScore(std::stoi(kiwi_benchmark_score));
        gpu.setImagePath(image_path);
        gpu_vec.push_back(gpu);
    }
    file_in.close();
    return;
}

void GPU::selectSortFilter(){
    unsigned int sort_option;
    std::string filter_input;
    std::vector<GPU> filtered;
    while (true){
        std::string option_str;
        std::cout << "Sort Options: " << std::endl;
        std::cout << "1. Price" << std::endl;
        std::cout << "2. Base Clock" << std::endl;
        std::cout << "3. Boost Clock" << std::endl;
        std::cout << "4. Memory VRAM" << std::endl;
        std::cout << "5. Memory Bus Width" << std::endl;
        std::cout << "6. Power Consumption" << std::endl;
        std::cout << "7. Benchmark Score" << std::endl;
        std::cout << "8. Dimension" << std::endl;
        std::cout << "9. Filter Brand" << std::endl;
        std::cout << "10. Filter Cooling Type" << std::endl;
        std::cout << "11. Filter Output Ports" << std::endl;
        std::cout << "12. Filter for sale" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Option number: ";
        std::getline(std::cin, option_str);
        while (true){
            try{
                sort_option = std::stoi(option_str);
                if (sort_option > 12 || sort_option < 0){
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument){
                std::cout << "Please enter a number from 0 to 12: " << std::endl;
                std::getline(std::cin, option_str);
            }
        }
        if (sort_option == 1){
            sortPrice();
        } else if (sort_option == 2){
            sortBaseClock();
        } else if (sort_option == 3){
            sortBoostClock();
        } else if (sort_option == 4){
            sortMemoryVRAM();
        } else if (sort_option == 5){
            sortMemoryBusWidth();
        } else if (sort_option == 6){
            sortPowerConsumption();
        } else if (sort_option == 7){
            sortBenchmarkScore();
        } else if (sort_option == 8){
            sortDimension();
        } else if (sort_option == 9){
            std::cout << "Enter brand: ";
            std::getline(std::cin, filter_input);
            filtered = filterBrand(filter_input);
        } else if (sort_option == 10){
            std::cout << "Enter cooling type: ";
            std::getline(std::cin, filter_input);
            filtered = filterCoolingType(filter_input);
        } else if (sort_option == 11){
            std::cout << "Enter output port: ";
            std::getline(std::cin, filter_input);
            filtered = filterOutputPorts(filter_input);
        } else if (sort_option == 12){
            filtered = filterOnDisplay();
        } else{
            break;
        }
        if (sort_option < 9){
            for (const GPU gpu: gpu_vec){
                std::cout << gpu;
                switch (sort_option)
                {
                case 2:
                    std::cout << "      " << "Base Clock: " << gpu.getBaseClock() << " GHz" << std::endl;
                    break;

                case 3:
                    std::cout << "      " << "Boost Clock: " << gpu.getBoostClock() << " GHz" << std::endl;
                    break;

                case 4:
                    std::cout << "      " << "Memory Support: " << std::get<1>(gpu.getMemorySupport()) << " GB " << std::get<0>(gpu.getMemorySupport()) << " " << std::get<2>(gpu.getMemorySupport()) << " bit" << std::endl;
                    break;

                case 5:
                    std::cout << "      " << "Memory Bus Width: " << std::get<2>(gpu.getMemorySupport()) << " bit" << std::endl;
                    break;

                case 6:
                    std::cout << "      " << "Power Consumption: " << std::get<0>(gpu.getPowerConsumption()) << " W" << std::endl;
                    break;

                case 7:
                    std::cout << "      " << "Benchmark Score: " << gpu.getBenchmarkScore() << std::endl;
                    break;

                case 8:
                    std::cout << "      " << "Dimension: " << std::get<0>(gpu.getDimension()) << " x " << std::get<1>(gpu.getDimension()) << " x " << std::get<2>(gpu.getDimension()) << " cm" << std::endl;
                    break;
                          
                default:
                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            for (const GPU gpu: filtered){
                std::cout << gpu << std::endl;
            }
        }
    }
    return;
}

void GPU::sortPrice(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return a.getPrice() < b.getPrice();
    });
}

void GPU::sortBaseClock(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return a.getBaseClock() < b.getBaseClock();
    });
}

void GPU::sortBoostClock(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return a.getBoostClock() < b.getBoostClock();
    });
}

void GPU::sortMemoryVRAM(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return std::get<1>(a.getMemorySupport()) < std::get<1>(b.getMemorySupport());
    });
}

void GPU::sortMemoryBusWidth(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return std::get<2>(a.getMemorySupport()) < std::get<2>(b.getMemorySupport());
    });
}

void GPU::sortPowerConsumption(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return std::get<0>(a.getPowerConsumption()) < std::get<0>(b.getPowerConsumption());
    });
}

void GPU::sortBenchmarkScore(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return a.getBenchmarkScore() < b.getBenchmarkScore();
    });
}

void GPU::sortDimension(){
    std::sort(gpu_vec.begin(), gpu_vec.end(), [](const GPU& a, const GPU& b){
        return std::get<0>(a.getDimension()) * std::get<1>(a.getDimension()) * std::get<2>(a.getDimension()) < std::get<0>(b.getDimension()) * std::get<1>(b.getDimension()) * std::get<2>(b.getDimension());
    });
}

std::vector<GPU> GPU::filterBrand(const std::string brand){
    std::vector<GPU> filtered;
    for (const GPU gpu: gpu_vec){
        if (gpu.getBrand() == brand){
            filtered.push_back(gpu);
        }
    }
    return filtered;
}

std::vector<GPU> GPU::filterCoolingType(const std::string ct){
    std::vector<GPU> filtered;
    for (const GPU gpu: gpu_vec){
        if (gpu.getCoolingType() == ct){
            filtered.push_back(gpu);
        }
    }
    return filtered;
}

std::vector<GPU> GPU::filterOutputPorts(const std::string op){
    std::vector<GPU> filtered;
    for (const GPU gpu: gpu_vec){
        for (std::string output_port: gpu.getOutputPorts()){
            if (output_port == op){
                filtered.push_back(gpu);
                break;
            }
        }
    }
    return filtered;
}

std::vector<GPU> GPU::filterOnDisplay(){
    std::vector<GPU> filtered;
    for (const GPU gpu: gpu_vec){
        if (gpu.getOnDisplay()){
            filtered.push_back(gpu);
        }
    }
    return filtered;
}

GPU& GPU::operator=(const GPU& gpu_in){
    setID(gpu_in.getID());
    setDescription(gpu_in.getDescription());
    setBrand(gpu_in.getBrand());
    setModel(gpu_in.getModel());
    setPrice(gpu_in.getPrice());
    setQuantity(gpu_in.getQuantity());
    setOnDisplay(gpu_in.getOnDisplay());
    setBaseClock(gpu_in.getBaseClock());
    setBoostClock(gpu_in.getBoostClock());
    setMemorySupport(std::get<0>(gpu_in.getMemorySupport()),
                     std::get<1>(gpu_in.getMemorySupport()),
                     std::get<2>(gpu_in.getMemorySupport()));
    clearOutputPorts();
    for (std::string op: gpu_in.getOutputPorts()){
        addOutputPorts(op);
    }
    setPowerConsumption(std::get<0>(gpu_in.getPowerConsumption()),
                        std::get<1>(gpu_in.getPowerConsumption()));
    setCoolingType(gpu_in.getCoolingType());
    setDimension(std::get<0>(gpu_in.getDimension()),
                 std::get<1>(gpu_in.getDimension()),
                 std::get<2>(gpu_in.getDimension()));
    setBenchmarkScore(gpu_in.getBenchmarkScore());
    setImagePath(gpu_in.getImagePath());
    return *this;
}

