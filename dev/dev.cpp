#include "dev.h"

Dev::Dev(){}

void checkInt(std::string &s, int &i){
    while (true){
        try{
            i = std::stoi(s);
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number: ";
            std::getline(std::cin, s);
        }
    }
}

void checkDouble(std::string &s, double &d){
    while (true){
        try{
            d = std::stod(s);
            break;
        } catch (std::invalid_argument){
            std::cout << "Please enter a number: ";
            std::getline(std::cin, s);
        }
    }
}

void checkBool(std::string &s, bool &b){
    while (true){
        if (s == "1"){
            b = true;
            break;
        } else if (s == "0"){
            b = false;
            break;
        } else {
            std::cout << "Please enter 1 or 0: ";
            std::getline(std::cin, s);
        }
    }
}

void checkImage(std::string &s){
    while (true){
        if (s == "n"){
            s = "../img/no_image.png";
            break;
        } else {
            if (std::filesystem::exists("../img/" + s + ".png")){
                s = "../img/" + s + ".png";
                break;
            } else if (std::filesystem::exists("../img/" + s + ".jpg")){
                s = "../img/" + s + ".jpg";
                break;
            } else {
                std::cout << "Image does not exist. Please enter a valid name or \"n\" for no image: ";
                std::getline(std::cin, s);
            }
        }
    }
}

bool Dev::verify(const std::string username, const std::string password) const{
    for (auto cred : dev_credentials){
        if (std::get<0>(cred) == username && std::get<1>(cred) == password){
            return true;
        }
    }
    return false;
}

void Dev::addCPU() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string socket_s;
    std::string form_factor_s;
    std::string core_no_s;
    std::string thread_no_s;
    std::string base_clock_s;
    std::string boost_clock_s;
    std::string has_overclock_s;
    std::string type_s;
    std::string freq_s;
    std::string no_s;
    std::string integrated_graphics_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    int core_no, thread_no;
    double base_clock, boost_clock;
    bool has_overclock;
    int freq, no;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Socket: ";
    std::getline(std::cin, socket_s);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Core number: ";
    std::getline(std::cin, core_no_s);
    checkInt(core_no_s, core_no);
    std::cout << "Thread number: ";
    std::getline(std::cin, thread_no_s);
    checkInt(thread_no_s, thread_no);
    std::cout << "Base clock (GHz): ";
    std::getline(std::cin, base_clock_s);
    checkDouble(base_clock_s, base_clock);
    std::cout << "Boost clock (GHz): ";
    std::getline(std::cin, boost_clock_s);
    checkDouble(boost_clock_s, boost_clock);
    std::cout << "Has overclock (1 for yes, 0 for no): ";
    std::getline(std::cin, has_overclock_s);
    checkBool(has_overclock_s, has_overclock);
    std::cout << "Memory type: ";
    std::getline(std::cin, type_s);
    std::cout << "Memory frequency (MHz): ";
    std::getline(std::cin, freq_s);
    checkInt(freq_s, freq);
    std::cout << "Memory number: ";
    std::getline(std::cin, no_s);
    checkInt(no_s, no);
    std::cout << "Integrated graphics: ";
    std::getline(std::cin, integrated_graphics_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    CPU cpu;
    cpu.setDescription(desc_s);
    cpu.setBrand(brand_s);
    cpu.setModel(model_s);
    cpu.setPrice(price);
    cpu.setQuantity(quantity);
    cpu.setOnDisplay(on_display);
    cpu.setSocket(socket_s);
    cpu.setFormFactor(form_factor_s);
    cpu.setCoreNo(core_no);
    cpu.setThreadNo(thread_no);
    cpu.setBaseClock(base_clock);
    cpu.setBoostClock(boost_clock);
    cpu.setHasOverclock(has_overclock);
    cpu.setMemorySupport(type_s, freq, no);
    cpu.setIntegratedGraphics(integrated_graphics_s);
    cpu.setImagePath(image_path_s);
    CPU::updateVec(cpu);

    std::cout << "CPU added successfully" << std::endl;
}

void Dev::addGPU() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string base_clock_s;
    std::string boost_clock_s;
    std::string type_s;
    std::string vram_s;
    std::string buswidth_s;
    std::string output_ports_s;
    std::string power_consumption_s;
    std::string pin_s;
    std::string cooling_type_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string kiwi_benchmark_score_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    double base_clock, boost_clock;
    int vram, buswidth;
    double power_consumption;
    int pin;
    double length, width, height;
    int kiwi_benchmark_score;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Base clock (GHz): ";
    std::getline(std::cin, base_clock_s);
    checkDouble(base_clock_s, base_clock);
    std::cout << "Boost clock (GHz): ";
    std::getline(std::cin, boost_clock_s);
    checkDouble(boost_clock_s, boost_clock);
    std::cout << "Memory type: ";
    std::getline(std::cin, type_s);
    std::cout << "VRAM (GB): ";
    std::getline(std::cin, vram_s);
    checkInt(vram_s, vram);
    std::cout << "Bus width (bit): ";
    std::getline(std::cin, buswidth_s);
    checkInt(buswidth_s, buswidth);
    std::cout << "Output ports (comma separated): ";
    std::getline(std::cin, output_ports_s);
    std::cout << "Power consumption (W): ";
    std::getline(std::cin, power_consumption_s);
    checkDouble(power_consumption_s, power_consumption);
    std::cout << "Pin: ";
    std::getline(std::cin, pin_s);
    checkInt(pin_s, pin);
    std::cout << "Cooling type: ";
    std::getline(std::cin, cooling_type_s);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Kiwi benchmark score: ";
    std::getline(std::cin, kiwi_benchmark_score_s);
    checkInt(kiwi_benchmark_score_s, kiwi_benchmark_score);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    GPU gpu;
    gpu.setDescription(desc_s);
    gpu.setBrand(brand_s);
    gpu.setModel(model_s);
    gpu.setPrice(price);
    gpu.setQuantity(quantity);
    gpu.setOnDisplay(on_display);
    gpu.setBaseClock(base_clock);
    gpu.setBoostClock(boost_clock);
    gpu.setMemorySupport(type_s, vram, buswidth);
    std::istringstream s_output_ports(output_ports_s);
    std::string op;
    while (std::getline(s_output_ports, op, ',')){
        gpu.addOutputPorts(op);
    }
    gpu.setPowerConsumption(power_consumption, pin);
    gpu.setCoolingType(cooling_type_s);
    gpu.setDimension(length, width, height);
    gpu.setBenchmarkScore(kiwi_benchmark_score);
    gpu.setImagePath(image_path_s);
    GPU::updateVec(gpu);        
}

void Dev::addMemory() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string capacity_s;
    std::string frequency_s;
    std::string latency_s;
    std::string voltage_s;
    std::string ecc_s;
    std::string compat_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display, ecc;
    int capacity, frequency, cas_latency;
    double voltage;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Capacity (GB): ";
    std::getline(std::cin, capacity_s);
    checkInt(capacity_s, capacity);
    std::cout << "Frequency (MHz): ";
    std::getline(std::cin, frequency_s);
    checkInt(frequency_s, frequency);
    std::cout << "CAS Latency: ";
    std::getline(std::cin, latency_s);
    checkInt(latency_s, cas_latency);
    std::cout << "Voltage (V): ";
    std::getline(std::cin, voltage_s);
    checkDouble(voltage_s, voltage);
    std::cout << "Has ECC (1 for yes, 0 for no): ";
    std::getline(std::cin, ecc_s);
    checkBool(ecc_s, ecc);
    std::cout << "Compatible with: ";
    std::getline(std::cin, compat_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Memory mem;
    mem.setDescription(desc_s);
    mem.setBrand(brand_s);
    mem.setModel(model_s);
    mem.setPrice(price);
    mem.setQuantity(quantity);
    mem.setOnDisplay(on_display);
    mem.setType(type_s);
    mem.setCapacity(capacity);
    mem.setFrequency(frequency);
    mem.setLatency(cas_latency);
    mem.setVoltage(voltage);
    mem.setHasECC(ecc);
    mem.setCompatibleWith(compat_s);
    mem.setImagePath(image_path_s);
    Memory::updateVec(mem);
}

void Dev::addMotherboard() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string form_factor_s;
    std::string socket_s;
    std::string mem_type_s;
    std::string mem_capacity_s;
    std::string chipset_s;
    std::string expansion_slots_s;
    std::string connectivity_s;
    std::string storage_type_s;
    std::string storage_capacity_s;
    std::string audio_s;
    std::string multi_gpu_s;
    std::string bios_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display, multi_gpu;
    int mem_capacity;
    
    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Socket: ";
    std::getline(std::cin, socket_s);
    std::cout << "Memory type: ";
    std::getline(std::cin, mem_type_s);
    std::cout << "Memory capacity (GB): ";
    std::getline(std::cin, mem_capacity_s);
    checkInt(mem_capacity_s, mem_capacity);
    std::cout << "Chipset: ";
    std::getline(std::cin, chipset_s);
    std::cout << "Expansion slots (comma separated): ";
    std::getline(std::cin, expansion_slots_s);
    std::cout << "Connectivity (comma separated): ";
    std::getline(std::cin, connectivity_s);
    std::cout << "Storage type (comma separated): ";
    std::getline(std::cin, storage_type_s);
    std::cout << "Audio: ";
    std::getline(std::cin, audio_s);
    std::cout << "Multi GPU (1 for yes, 0 for no): ";
    std::getline(std::cin, multi_gpu_s);
    checkBool(multi_gpu_s, multi_gpu);
    std::cout << "BIOS: ";
    std::getline(std::cin, bios_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Motherboard mb;
    mb.setDescription(desc_s);
    mb.setBrand(brand_s);
    mb.setModel(model_s);
    mb.setPrice(price);
    mb.setQuantity(quantity);
    mb.setOnDisplay(on_display);
    mb.setFormFactor(form_factor_s);
    mb.setSocket(socket_s);
    mb.setMemory(mem_type_s, mem_capacity);
    mb.setChipset(chipset_s);
    std::istringstream s_expansion_slots(expansion_slots_s);
    std::string es;
    while (std::getline(s_expansion_slots, es, ',')){
        mb.addExpansionSlots(es);
    }
    std::istringstream s_connectivity(connectivity_s);
    std::string c;
    while (std::getline(s_connectivity, c, ',')){
        mb.addConnectivity(c);
    }
    std::istringstream s_storage_type(storage_type_s);
    std::string st;
    while (std::getline(s_storage_type, st, ',')){
        mb.addStorage(st);
    }
    mb.setAudio(audio_s);
    mb.setMultiGPU(multi_gpu);
    mb.setBios(bios_s);
    mb.setImagePath(image_path_s);
    Motherboard::updateVec(mb);
}

void Dev::addHDD() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string storage_c_s;
    std::string storage_s_s;
    std::string interface_s;
    std::string form_factor_s;
    std::string rotation_speed_s;
    std::string cache_s;
    std::string idle_power_s;
    std::string read_power_s;
    std::string write_power_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    int storage_c, storage_s, rotation_speed, cache;
    double idle_power, read_power, write_power;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_c_s);
    checkInt(storage_c_s, storage_c);
    std::cout << "Storage speed (MB/s): ";
    std::getline(std::cin, storage_s_s);
    checkInt(storage_s_s, storage_s);
    std::cout << "Interface: ";
    std::getline(std::cin, interface_s);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Rotation speed (rpm): ";
    std::getline(std::cin, rotation_speed_s);
    checkInt(rotation_speed_s, rotation_speed);
    std::cout << "Cache (MB): ";
    std::getline(std::cin, cache_s);
    checkInt(cache_s, cache);
    std::cout << "Idle power (W): ";
    std::getline(std::cin, idle_power_s);
    checkDouble(idle_power_s, idle_power);
    std::cout << "Read power (W): ";
    std::getline(std::cin, read_power_s);
    checkDouble(read_power_s, read_power);
    std::cout << "Write power (W): ";
    std::getline(std::cin, write_power_s);
    checkDouble(write_power_s, write_power);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    HDD hdd;
    hdd.setDescription(desc_s);
    hdd.setBrand(brand_s);
    hdd.setModel(model_s);
    hdd.setPrice(price);
    hdd.setQuantity(quantity);
    hdd.setOnDisplay(on_display);
    hdd.setStorageCapacity(storage_c);
    hdd.setStorageSpeed(storage_s);
    hdd.setInterface(interface_s);
    hdd.setFormFactor(form_factor_s);
    hdd.setRotationSpeed(rotation_speed);
    hdd.setCache(cache);
    hdd.setPowerConsumption(idle_power, read_power, write_power);
    hdd.setImagePath(image_path_s);
    HDD::updateVec(hdd);
}

void Dev::addSSD() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string storage_c_s;
    std::string storage_s_s;
    std::string interface_s;
    std::string form_factor_s;
    std::string power_consumption_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    int storage_c, storage_s;
    double power_consumption;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_c_s);
    checkInt(storage_c_s, storage_c);
    std::cout << "Storage speed (MB/s): ";
    std::getline(std::cin, storage_s_s);
    checkInt(storage_s_s, storage_s);
    std::cout << "Interface: ";
    std::getline(std::cin, interface_s);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Power consumption (W): ";
    std::getline(std::cin, power_consumption_s);
    checkDouble(power_consumption_s, power_consumption);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    SSD ssd;
    ssd.setDescription(desc_s);
    ssd.setBrand(brand_s);
    ssd.setModel(model_s);
    ssd.setPrice(price);
    ssd.setQuantity(quantity);
    ssd.setOnDisplay(on_display);
    ssd.setStorageCapacity(storage_c);
    ssd.setStorageSpeed(storage_s);
    ssd.setInterface(interface_s);
    ssd.setFormFactor(form_factor_s);
    ssd.setPowerConsumption(power_consumption);
    ssd.setImagePath(image_path_s);
    SSD::updateVec(ssd);
}

void Dev::addPSU() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string form_factor_s;
    std::string efficiency_s;
    std::string modular_s;
    std::string wattage_s;
    std::string fan_size_s;
    std::string fan_noise_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string image_path_s;

    double price, length, width, height;
    int quantity, wattage, fan_noise;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Efficiency (%): ";
    std::getline(std::cin, efficiency_s);
    std::cout << "Modularity: ";
    std::getline(std::cin, modular_s);
    std::cout << "Wattage (W): ";
    std::getline(std::cin, wattage_s);
    checkInt(wattage_s, wattage);
    std::cout << "Fan size: ";
    std::getline(std::cin, fan_size_s);
    std::cout << "Fan noise: ";
    std::getline(std::cin, fan_noise_s);
    checkInt(fan_noise_s, fan_noise);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);
    
    PSU psu;
    psu.setDescription(desc_s);
    psu.setBrand(brand_s);
    psu.setModel(model_s);
    psu.setPrice(price);
    psu.setQuantity(quantity);
    psu.setOnDisplay(on_display);
    psu.setFormFactor(form_factor_s);
    psu.setEfficiency(efficiency_s);
    psu.setModular(modular_s);
    psu.setWattage(wattage);
    psu.setFan(fan_size_s, fan_noise);
    psu.setDimension(length, width, height);
    psu.setImagePath(image_path_s);
    PSU::updateVec(psu);
}

void Dev::addCase() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string form_factor_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string cooling_type_s;
    std::string max_gpu_length_s;
    std::string max_cpu_height_s;
    std::string fan_size1_s;
    std::string fan_noise1_s;
    std::string fan_size2_s;
    std::string fan_noise2_s;
    std::string fan_size3_s;
    std::string fan_noise3_s;
    std::string image_path_s;

    double price, length, width, height, max_gpu_length, max_cpu_height;
    int quantity, fan_noise1, fan_noise2, fan_noise3;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Cooling type: ";
    std::getline(std::cin, cooling_type_s);
    std::cout << "Max GPU length (mm): ";
    std::getline(std::cin, max_gpu_length_s);
    checkDouble(max_gpu_length_s, max_gpu_length);
    std::cout << "Max CPU height (mm): ";
    std::getline(std::cin, max_cpu_height_s);
    checkDouble(max_cpu_height_s, max_cpu_height);
    std::cout << "Fan size 1 (type n to skip): ";
    std::getline(std::cin, fan_size1_s);
    if (fan_size1_s != "n"){
        std::cout << "Fan noise 1 (dB): ";
        std::getline(std::cin, fan_noise1_s);
        checkInt(fan_noise1_s, fan_noise1);
        std::cout << "Fan size 2 (type n to skip): ";
        std::getline(std::cin, fan_size2_s);
        if (fan_size2_s != "n"){
            std::cout << "Fan noise 2 (dB): ";
            std::getline(std::cin, fan_noise2_s);
            checkInt(fan_noise2_s, fan_noise2);
            std::cout << "Fan size 3 (type n to skip): ";
            std::getline(std::cin, fan_size3_s);
            if (fan_size3_s != "n"){
                std::cout << "Fan noise 3 (dB): ";
                std::getline(std::cin, fan_noise3_s);
                checkInt(fan_noise3_s, fan_noise3);
            }
        }
    }
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    PCCase pc_case;
    pc_case.setDescription(desc_s);
    pc_case.setBrand(brand_s);
    pc_case.setModel(model_s);
    pc_case.setPrice(price);
    pc_case.setQuantity(quantity);
    pc_case.setOnDisplay(on_display);
    pc_case.setFormFactor(form_factor_s);
    pc_case.setDimension(length, width, height);
    pc_case.setCoolingType(cooling_type_s);
    pc_case.setMaxGPULength(max_gpu_length);
    pc_case.setMaxCPUHeight(max_cpu_height);
    pc_case.setFanSupport(0, fan_size1_s, fan_noise1);
    if (fan_size2_s != "n"){
        pc_case.setFanSupport(1, fan_size2_s, fan_noise2);
        if (fan_size3_s != "n"){
            pc_case.setFanSupport(2, fan_size3_s, fan_noise3);
        }
    }
    pc_case.setImagePath(image_path_s);
    PCCase::updateVec(pc_case);
}

void Dev::addCooling_U() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string form_factor_s;
    std::string type_s;
    std::string cool_capacity_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string noise_level_s;
    std::string fan_speed_s;
    std::string is_rgb_s;
    std::string image_path_s;

    double price, length, width, height;
    int quantity, cool_capacity, noise_level, fan_speed;
    bool on_display, is_rgb;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Cooling capacity (W): ";
    std::getline(std::cin, cool_capacity_s);
    checkInt(cool_capacity_s, cool_capacity);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Noise level (dB): ";
    std::getline(std::cin, noise_level_s);
    checkInt(noise_level_s, noise_level);
    std::cout << "Fan speed (rpm):";
    std::getline(std::cin, fan_speed_s);
    checkInt(fan_speed_s, fan_speed);
    std::cout << "Is RGB (1 for yes, 0 for no): ";
    std::getline(std::cin, is_rgb_s);
    checkBool(is_rgb_s, is_rgb);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    CoolingUnit cooling_u;
    cooling_u.setDescription(desc_s);
    cooling_u.setBrand(brand_s);
    cooling_u.setModel(model_s);
    cooling_u.setPrice(price);
    cooling_u.setQuantity(quantity);
    cooling_u.setOnDisplay(on_display);
    cooling_u.setFormFactor(form_factor_s);
    cooling_u.setType(type_s);
    cooling_u.setCoolCapacity(cool_capacity);
    cooling_u.setDimension(length, width, height);
    cooling_u.setNoiseLevel(noise_level);
    cooling_u.setFanSpeed(fan_speed);
    cooling_u.setIsRgb(is_rgb);
    cooling_u.setImagePath(image_path_s);
    CoolingUnit::updateVec(cooling_u);
}

void Dev::addHandheld() const {
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string main_proc_s;
    std::string grap_proc_s;
    std::string storage_cap_s;
    std::string usb_s;
    std::string display_s;
    std::string in_out_s;
    std::string wifi_s;
    std::string weight_s;
    std::string blue_tooth_s;
    std::string power_con_s;
    std::string cont_s;
    std::string tv_s;
    std::string battery_s;
    std::string pow_supp_s;
    std::string headphone_j_s;
    std::string microSD_s;
    std::string size_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    int res_w, res_h;
    int storage_cap;
    double weight;
    bool cont, tv;
    double power_con;
    int microSD;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "Main processor: ";
    std::getline(std::cin, main_proc_s);
    std::cout << "Graphics processor: ";
    std::getline(std::cin, grap_proc_s);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_cap_s);
    checkInt(storage_cap_s, storage_cap);
    std::cout << "USB: ";
    std::getline(std::cin, usb_s);
    std::cout << "Display: ";
    std::getline(std::cin, display_s);
    std::cout << "In/Out: ";
    std::getline(std::cin, in_out_s);
    std::cout << "Wifi: ";
    std::getline(std::cin, wifi_s);
    std::cout << "Weight: ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Bluetooth: ";
    std::getline(std::cin, blue_tooth_s);
    std::cout << "Power consumption: ";
    std::getline(std::cin, power_con_s);
    checkDouble(power_con_s, power_con);
    std::cout << "Controller vibration: ";
    std::getline(std::cin, cont_s);
    checkBool(cont_s, cont);
    std::cout << "TV mode: ";
    std::getline(std::cin, tv_s);
    checkBool(tv_s, tv);
    std::cout << "Battery: ";
    std::getline(std::cin, battery_s);
    std::cout << "Power supply: ";
    std::getline(std::cin, pow_supp_s);
    std::cout << "Headphone jack: ";
    std::getline(std::cin, headphone_j_s);
    std::cout << "MicroSD: ";
    std::getline(std::cin, microSD_s);
    checkInt(microSD_s, microSD);   
    std::cout << "Size: ";
    std::getline(std::cin, size_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);   
    checkImage(image_path_s);

    Handheld handheld;
    handheld.setDescription(desc_s);
    handheld.setBrand(brand_s);
    handheld.setModel(model_s);
    handheld.setPrice(price);   
    handheld.setQuantity(quantity);
    handheld.setOnDisplay(on_display);
    handheld.setResolution(res_w, res_h);
    handheld.setMainProcessor(main_proc_s);
    handheld.setGraphicsProcessor(grap_proc_s);
    handheld.setStorageCapacity(storage_cap);   
    handheld.setUSB(usb_s);
    handheld.setDisplay(display_s);
    handheld.setInputOutputPort(in_out_s);
    handheld.setWifi(wifi_s);
    handheld.setWeight(weight);
    handheld.setBluetooth(blue_tooth_s);
    handheld.setPowerConsumption(power_con);    
    handheld.setControllerVibration(cont);
    handheld.setTVMode(tv);
    handheld.setBattery(battery_s);
    handheld.setPowerSupply(pow_supp_s);
    handheld.setHeadphoneJack(headphone_j_s);
    handheld.setMicroSDSlot(microSD);
    handheld.setSize(size_s);
    handheld.setImagePath(image_path_s);
    Handheld::updateVec(handheld);
    
}

void Dev::addStationed() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string main_proc_s;
    std::string grap_proc_s;
    std::string storage_cap_s;
    std::string usb_s;
    std::string display_s;
    std::string in_out_s;
    std::string wifi_s;
    std::string weight_s;
    std::string blue_tooth_s;
    std::string power_con_s;
    std::string cont_s;
    std::string tv_s;
    std::string ssd;
    std::string size;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;
    int res_w, res_h;
    int storage_cap;
    double weight;
    bool cont, tv;
    double power_con;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "Main processor: ";
    std::getline(std::cin, main_proc_s);
    std::cout << "Graphics processor: ";
    std::getline(std::cin, grap_proc_s);
    std::cout << "Storage capacity: ";
    std::getline(std::cin, storage_cap_s);
    checkInt(storage_cap_s, storage_cap);
    std::cout << "USB: ";
    std::getline(std::cin, usb_s);
    std::cout << "Display: ";
    std::getline(std::cin, display_s);
    std::cout << "In/Out: ";
    std::getline(std::cin, in_out_s);
    std::cout << "Wifi: ";
    std::getline(std::cin, wifi_s);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Bluetooth: ";
    std::getline(std::cin, blue_tooth_s);
    std::cout << "Power consumption: ";
    std::getline(std::cin, power_con_s);
    checkDouble(power_con_s, power_con);
    std::cout << "Controller vibration: ";
    std::getline(std::cin, cont_s);
    checkBool(cont_s, cont);
    std::cout << "TV mode: ";
    std::getline(std::cin, tv_s);
    checkBool(tv_s, tv);
    std::cout << "SSD: ";
    std::getline(std::cin, ssd);
    std::cout << "Size: ";
    std::getline(std::cin, size);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Stationed stationed;
    stationed.setDescription(desc_s);
    stationed.setBrand(brand_s);
    stationed.setModel(model_s);
    stationed.setPrice(price);
    stationed.setQuantity(quantity);
    stationed.setOnDisplay(on_display);
    stationed.setResolution(res_w, res_h);  
    stationed.setMainProcessor(main_proc_s);
    stationed.setGraphicsProcessor(grap_proc_s);
    stationed.setStorageCapacity(storage_cap);
    stationed.setUSB(usb_s);
    stationed.setDisplay(display_s);
    stationed.setInputOutputPort(in_out_s);
    stationed.setWifi(wifi_s);
    stationed.setWeight(weight);
    stationed.setBluetooth(blue_tooth_s);
    stationed.setPowerConsumption(power_con);
    stationed.setControllerVibration(cont);
    stationed.setTVMode(tv);
    stationed.setSSD(ssd);
    stationed.setSize(size);
    stationed.setImagePath(image_path_s);
    Stationed::updateVec(stationed);
}

void Dev::addDesktop() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string cpu_s;
    std::string gpu_s;
    std::string mem_s;
    std::string storage_s;
    std::string psu_s;
    std::string case_s;
    std::string cooling_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);    
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "CPU: ";
    std::getline(std::cin, cpu_s);
    std::cout << "GPU: ";
    std::getline(std::cin, gpu_s);
    std::cout << "Memory: ";
    std::getline(std::cin, mem_s);
    std::cout << "Storage (comma separated): ";
    std::getline(std::cin, storage_s);
    std::cout << "PSU: ";
    std::getline(std::cin, psu_s);
    std::cout << "Case: ";
    std::getline(std::cin, case_s);
    std::cout << "Cooling: ";
    std::getline(std::cin, cooling_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Desktop desktop;
    desktop.setDescription(desc_s);
    desktop.setBrand(brand_s);
    desktop.setModel(model_s);
    desktop.setPrice(price);
    desktop.setQuantity(quantity);
    desktop.setOnDisplay(on_display);
    desktop.setCPU(cpu_s);
    desktop.setGPU(gpu_s);
    desktop.setMemory(mem_s);
    std::istringstream s_storage(storage_s);
    std::string st;
    while (std::getline(s_storage, st, ',')){
        desktop.addStorage(st);
    }
    desktop.setPSU(psu_s);
    desktop.setPCCase(case_s);
    desktop.setCooling(cooling_s);
    desktop.setImagePath(image_path_s);
    Desktop::updateVec(desktop);
}

void Dev::addLaptop() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string cpu_s;
    std::string gpu_s;
    std::string mem_s;
    std::string storage_s;
    std::string os_s;
    std::string display_s;
    std::string batt_cap_s;
    std::string batt_cell_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string diagonal_s;
    std::string weight_s;
    std::string touchscreen_s;
    std::string gaming_s;
    std::string image_path_s;

    double price, length, width, height, diagonal, weight, batt_cap;
    int quantity, batt_cell;
    bool on_display, touchscreen, gaming;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "CPU: ";
    std::getline(std::cin, cpu_s);
    std::cout << "GPU: ";
    std::getline(std::cin, gpu_s);
    std::cout << "Memory: ";
    std::getline(std::cin, mem_s);
    std::cout << "Storage (comma separated): ";
    std::getline(std::cin, storage_s);
    std::cout << "OS: ";
    std::getline(std::cin, os_s);
    std::cout << "Display: ";
    std::getline(std::cin, display_s);
    std::cout << "Battery capacity (WHr): ";
    std::getline(std::cin, batt_cap_s);
    checkDouble(batt_cap_s, batt_cap);
    std::cout << "Battery cells: ";
    std::getline(std::cin, batt_cell_s);
    checkInt(batt_cell_s, batt_cell);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Diagonal (in): ";
    std::getline(std::cin, diagonal_s);
    checkDouble(diagonal_s, diagonal);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Touchscreen (1 for yes, 0 for no): ";
    std::getline(std::cin, touchscreen_s);
    checkBool(touchscreen_s, touchscreen);
    std::cout << "Gaming (1 for yes, 0 for no): ";
    std::getline(std::cin, gaming_s);
    checkBool(gaming_s, gaming);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Laptop laptop;
    laptop.setDescription(desc_s);
    laptop.setBrand(brand_s);
    laptop.setModel(model_s);
    laptop.setPrice(price);
    laptop.setQuantity(quantity);
    laptop.setOnDisplay(on_display);
    laptop.setCPU(cpu_s);
    laptop.setGPU(gpu_s);
    laptop.setMemory(mem_s);
    std::istringstream s_storage(storage_s);
    std::string st;
    while (std::getline(s_storage, st, ',')){
        laptop.addStorage(st);
    }
    laptop.setOS(os_s);
    laptop.setDisplay(display_s);
    laptop.setBattery(batt_cap, batt_cell);
    laptop.setDimensions(length, width, height, diagonal);
    laptop.setWeight(weight);
    laptop.setTouchscreen(touchscreen);
    laptop.setGaming(gaming);
    laptop.setImagePath(image_path_s);
    Laptop::updateVec(laptop);
}

void Dev::addEarbuds() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string batt_life_s;
    std::string anc_s;
    std::string water_res_s;
    std::string image_path_s;

    double price, batt_life;
    int quantity;
    bool on_display, anc, water_res;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Battery life (Hr): ";
    std::getline(std::cin, batt_life_s);
    checkDouble(batt_life_s, batt_life);
    std::cout << "ANC (1 for yes, 0 for no): ";
    std::getline(std::cin, anc_s);
    checkBool(anc_s, anc);
    std::cout << "Water resistance (1 for yes, 0 for no): ";
    std::getline(std::cin, water_res_s);
    checkBool(water_res_s, water_res);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Earbuds earbuds;
    earbuds.setDescription(desc_s);
    earbuds.setBrand(brand_s);
    earbuds.setModel(model_s);
    earbuds.setPrice(price);
    earbuds.setQuantity(quantity);
    earbuds.setOnDisplay(on_display);
    earbuds.setBatteryLife(batt_life);
    earbuds.setANC(anc);
    earbuds.setWaterResistant(water_res);
    earbuds.setImagePath(image_path_s);
    Earbuds::updateVec(earbuds);
}

void Dev::addEarphones() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string vol_cont_s;
    std::string water_res_s;
    std::string wire_len_s;
    std::string image_path_s;

    double price, wire_len;
    int quantity;
    bool on_display, water_res, vol_cont;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Volume control (1 for yes, 0 for no): ";
    std::getline(std::cin, vol_cont_s);
    checkBool(vol_cont_s, vol_cont);
    std::cout << "Water resistance (1 for yes, 0 for no): ";
    std::getline(std::cin, water_res_s);
    checkBool(water_res_s, water_res);
    std::cout << "Wire length (m): ";
    std::getline(std::cin, wire_len_s);
    checkDouble(wire_len_s, wire_len);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Earphones earphones;
    earphones.setDescription(desc_s);
    earphones.setBrand(brand_s);
    earphones.setModel(model_s);
    earphones.setPrice(price);
    earphones.setQuantity(quantity);
    earphones.setOnDisplay(on_display);
    earphones.setVolumeControl(vol_cont);
    earphones.setWaterResistant(water_res);
    earphones.setWireLength(wire_len);
    earphones.setImagePath(image_path_s);
    Earphones::updateVec(earphones);
}

void Dev::addHeadphones() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string anc_s;
    std::string wireless_s;
    std::string surround_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display, anc, wireless, surround;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "ANC (1 for yes, 0 for no): ";
    std::getline(std::cin, anc_s);
    checkBool(anc_s, anc);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "Surround sound (1 for yes, 0 for no): ";
    std::getline(std::cin, surround_s);
    checkBool(surround_s, surround);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Headphones headphones;
    headphones.setDescription(desc_s);
    headphones.setBrand(brand_s);
    headphones.setModel(model_s);
    headphones.setPrice(price);
    headphones.setQuantity(quantity);
    headphones.setOnDisplay(on_display);
    headphones.setANC(anc);
    headphones.setWireless(wireless);
    headphones.setSurroundSound(surround);
    headphones.setImagePath(image_path_s);
    Headphones::updateVec(headphones);
}

void Dev::addHeadset() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string wireless_s;
    std::string anc_s;
    std::string rgb_s;
    std::string surround_s;
    std::string image_path_s;

    double price;
    int quantity;   
    bool on_display, wireless, anc, rgb, surround;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "ANC (1 for yes, 0 for no): ";
    std::getline(std::cin, anc_s);
    checkBool(anc_s, anc);
    std::cout << "RGB (1 for yes, 0 for no): ";
    std::getline(std::cin, rgb_s);
    checkBool(rgb_s, rgb);
    std::cout << "Surround sound (1 for yes, 0 for no): ";
    std::getline(std::cin, surround_s);
    checkBool(surround_s, surround);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Headset headset;
    headset.setDescription(desc_s);
    headset.setBrand(brand_s);
    headset.setModel(model_s);
    headset.setPrice(price);
    headset.setQuantity(quantity);
    headset.setOnDisplay(on_display);
    headset.setWireless(wireless);
    headset.setANC(anc);
    headset.setRGB(rgb);
    headset.setSurroundSound(surround);
    headset.setImagePath(image_path_s);
    Headset::updateVec(headset);
}

void Dev::addMicrophone() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string direc_s;
    std::string usb_s;
    std::string xlr_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display, usb, xlr;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity); 
    std::cout << "On display (1 for yes, 0 for no): ";      
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Directional (1 for yes, 0 for no): ";
    std::getline(std::cin, direc_s);
    checkBool(direc_s, usb);
    std::cout << "USB (1 for yes, 0 for no): ";
    std::getline(std::cin, usb_s);
    checkBool(usb_s, usb);
    std::cout << "XLR (1 for yes, 0 for no): ";
    std::getline(std::cin, xlr_s);
    checkBool(xlr_s, xlr);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);   
    checkImage(image_path_s);

    Microphone microphone;
    microphone.setDescription(desc_s);
    microphone.setBrand(brand_s);   
    microphone.setModel(model_s);
    microphone.setPrice(price);
    microphone.setQuantity(quantity);
    microphone.setOnDisplay(on_display);
    microphone.setDirectionality(direc_s);
    microphone.setUSB(usb);
    microphone.setXLR(xlr);
    microphone.setImagePath(image_path_s);
    Microphone::updateVec(microphone);
}

void Dev::addSpeakers() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string power_out_s;
    std::string config_s;
    std::string wireless_s;
    std::string battery_life_s;
    std::string image_path_s;

    double price, power_out, battery_life, config;
    int quantity;
    bool on_display, wireless;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);     
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);    
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";  
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity); 
    std::cout << "On display (1 for yes, 0 for no): ";  
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Power output (W): ";
    std::getline(std::cin, power_out_s);
    checkDouble(power_out_s, power_out);
    std::cout << "Configuration: ";
    std::getline(std::cin, config_s);
    checkDouble(config_s, config);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "Battery life (Hr): ";
    std::getline(std::cin, battery_life_s);
    checkDouble(battery_life_s, battery_life);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Speakers speakers;
    speakers.setDescription(desc_s);
    speakers.setBrand(brand_s);
    speakers.setModel(model_s);
    speakers.setPrice(price);
    speakers.setQuantity(quantity);
    speakers.setOnDisplay(on_display);
    speakers.setPowerOutput(power_out);
    speakers.setConfiguration(config);
    speakers.setWireless(wireless);
    speakers.setBatteryLife(battery_life);
    speakers.setImagePath(image_path_s);
    Speakers::updateVec(speakers);
}

void Dev::addDisplay() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string refresh_rate_s;
    std::string dimen_w_s;
    std::string dimen_h_s;
    std::string hdr_s;
    std::string response_time_s;
    std::string image_path_s;

    double price, dimen_w, dimen_h;
    int quantity, res_w, res_h, refresh_rate, response_time;
    bool on_display, hdr;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "Refresh rate (Hz): ";
    std::getline(std::cin, refresh_rate_s);
    checkInt(refresh_rate_s, refresh_rate);
    std::cout << "Width (mm): ";
    std::getline(std::cin, dimen_w_s);
    checkDouble(dimen_w_s, dimen_w);
    std::cout << "Height (mm): ";
    std::getline(std::cin, dimen_h_s);
    checkDouble(dimen_h_s, dimen_h);
    std::cout << "HDR (1 for yes, 0 for no): ";
    std::getline(std::cin, hdr_s);
    checkBool(hdr_s, hdr);
    std::cout << "Response time (ms): ";
    std::getline(std::cin, response_time_s);
    checkInt(response_time_s, response_time);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Display display;
    display.setDescription(desc_s);
    display.setBrand(brand_s);
    display.setModel(model_s);
    display.setPrice(price);
    display.setQuantity(quantity);
    display.setOnDisplay(on_display);
    display.setResolution(res_w, res_h);
    display.setRefreshRate(refresh_rate);
    display.setDimensions(dimen_w, dimen_h);
    display.setHDR(hdr);
    display.setResponseTime(response_time);
    display.setImagePath(image_path_s);
    Display::updateVec(display);
}

void Dev::addKeyboard() const {
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string layout_s;
    std::string backlit_s;
    std::string wireless_s;
    std::string key_switch_s;
    std::string image_path_s;

    double price;
    int quantity;
    bool on_display, backlit, wireless;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Layout: ";
    std::getline(std::cin, layout_s);
    std::cout << "Backlit (1 for yes, 0 for no): ";
    std::getline(std::cin, backlit_s);
    checkBool(backlit_s, backlit);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "Key switch: ";
    std::getline(std::cin, key_switch_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Keyboard keyboard;
    keyboard.setDescription(desc_s);
    keyboard.setBrand(brand_s);
    keyboard.setModel(model_s);
    keyboard.setPrice(price);
    keyboard.setQuantity(quantity);
    keyboard.setOnDisplay(on_display);
    keyboard.setType(type_s);
    keyboard.setLayout(layout_s);
    keyboard.setBacklit(backlit);
    keyboard.setWireless(wireless);
    keyboard.setKeySwitch(key_switch_s);
    keyboard.setImagePath(image_path_s);
    Keyboard::updateVec(keyboard);
}

void Dev::addMouse() const {
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string sensor_s;
    std::string wireless_s;
    std::string min_dpi_s;
    std::string max_dpi_s;
    std::string weight_s;
    std::string battery_life_s;
    std::string rechargeable_s;
    std::string image_path_s;

    double price, weight, battery_life;
    int quantity, min_dpi, max_dpi; 
    bool on_display, wireless, rechargeable;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Sensor: ";
    std::getline(std::cin, sensor_s);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "Min DPI: ";
    std::getline(std::cin, min_dpi_s);
    checkInt(min_dpi_s, min_dpi);
    std::cout << "Max DPI: ";
    std::getline(std::cin, max_dpi_s);
    checkInt(max_dpi_s, max_dpi);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Battery life (Hr): ";
    std::getline(std::cin, battery_life_s);
    checkDouble(battery_life_s, battery_life);
    std::cout << "Rechargeable (1 for yes, 0 for no): ";
    std::getline(std::cin, rechargeable_s);
    checkBool(rechargeable_s, rechargeable);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Mouse mouse;
    mouse.setDescription(desc_s);
    mouse.setBrand(brand_s);
    mouse.setModel(model_s);
    mouse.setPrice(price);
    mouse.setQuantity(quantity);
    mouse.setOnDisplay(on_display);
    mouse.setType(type_s);
    mouse.setSensor(sensor_s);
    mouse.setWireless(wireless);
    mouse.setSensitivity(min_dpi, max_dpi);
    mouse.setWeight(weight);
    mouse.setBatteryLife(battery_life);
    mouse.setRechargeable(rechargeable);
    mouse.setImagePath(image_path_s);
    Mouse::updateVec(mouse);
}

void Dev::addPortable_HDD() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string storage_cap_s;
    std::string interface_s;
    std::string transfer_rate_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string weight_s;
    std::string image_path_s;

    double price, length, width, height, weight;
    int quantity, storage_cap, transfer_rate;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_cap_s);
    checkInt(storage_cap_s, storage_cap);
    std::cout << "Interface: ";
    std::getline(std::cin, interface_s);
    std::cout << "Transfer rate (MB/s): ";
    std::getline(std::cin, transfer_rate_s);
    checkInt(transfer_rate_s, transfer_rate);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Portable_HDD portable_hdd;
    portable_hdd.setDescription(desc_s);
    portable_hdd.setBrand(brand_s);
    portable_hdd.setModel(model_s);
    portable_hdd.setPrice(price);
    portable_hdd.setQuantity(quantity);
    portable_hdd.setOnDisplay(on_display);
    portable_hdd.setCapacity(storage_cap);
    portable_hdd.setInterface(interface_s);
    portable_hdd.setTransferSpeed(transfer_rate);
    portable_hdd.setDimensions(length, width, height);
    portable_hdd.setWeight(weight);
    portable_hdd.setImagePath(image_path_s);
    Portable_HDD::updateVec(portable_hdd);
}

void Dev::addPrinter() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string scanner_s;
    std::string wireless_s;
    std::string print_speed_s;
    std::string max_res_s;
    std::string duplex_s;
    std::string ink_toner_s;
    std::string page_yield_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string weight_s;
    std::string image_path_s;

    double price, length, width, height, weight;
    int quantity, print_speed, max_res, page_yield;
    bool on_display, scanner, wireless, duplex;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Scanner (1 for yes, 0 for no): ";
    std::getline(std::cin, scanner_s);
    checkBool(scanner_s, scanner);
    std::cout << "Wireless (1 for yes, 0 for no): ";
    std::getline(std::cin, wireless_s);
    checkBool(wireless_s, wireless);
    std::cout << "Print speed (ppm): ";
    std::getline(std::cin, print_speed_s);
    checkInt(print_speed_s, print_speed);
    std::cout << "Max resolution (dpi): ";
    std::getline(std::cin, max_res_s);
    checkInt(max_res_s, max_res);
    std::cout << "Duplex (1 for yes, 0 for no): ";
    std::getline(std::cin, duplex_s);
    checkBool(duplex_s, duplex);
    std::cout << "Ink or toner: ";
    std::getline(std::cin, ink_toner_s);
    std::cout << "Page yield: ";
    std::getline(std::cin, page_yield_s);
    checkInt(page_yield_s, page_yield);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Printer printer;
    printer.setDescription(desc_s);
    printer.setBrand(brand_s);
    printer.setModel(model_s);
    printer.setPrice(price);
    printer.setQuantity(quantity);
    printer.setOnDisplay(on_display);
    printer.setType(type_s);
    printer.setHasScanner(scanner);
    printer.setWireless(wireless);
    printer.setSpeed(print_speed);
    printer.setMaxRes(max_res);
    printer.setDuplex(duplex);
    printer.setInkOrToner(ink_toner_s, page_yield);
    printer.setDimensions(length, width, height);
    printer.setWeight(weight);
    printer.setImagePath(image_path_s);
    Printer::updateVec(printer);
}

void Dev::addSD_Card() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string storage_cap_s;
    std::string speed_s;
    std::string rating_s;
    std::string form_factor_s;
    std::string image_path_s;

    double price;
    int quantity, storage_cap, speed;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_cap_s);
    checkInt(storage_cap_s, storage_cap);
    std::cout << "Speed (MB/s): ";
    std::getline(std::cin, speed_s);
    checkInt(speed_s, speed);
    std::cout << "Rating: ";
    std::getline(std::cin, rating_s);
    std::cout << "Form factor: ";
    std::getline(std::cin, form_factor_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    SdCard sd_card;
    sd_card.setDescription(desc_s);
    sd_card.setBrand(brand_s);
    sd_card.setModel(model_s);
    sd_card.setPrice(price);
    sd_card.setQuantity(quantity);
    sd_card.setOnDisplay(on_display);
    sd_card.setType(type_s);
    sd_card.setCapacity(storage_cap);
    sd_card.setSpeed(speed);
    sd_card.setClassRating(rating_s);
    sd_card.setFormFactor(form_factor_s);
    sd_card.setImagePath(image_path_s);
    SdCard::updateVec(sd_card);
}

void Dev::addTouchpad() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string type_s;
    std::string length_s;
    std::string width_s;
    std::string image_path_s;

    double price, length, width;
    int quantity;
    bool on_display;

    std::cout << "Description: ";   
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);    
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s); 
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Length (mm): ";   
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Touchpad touchpad;
    touchpad.setDescription(desc_s);
    touchpad.setBrand(brand_s);
    touchpad.setModel(model_s);
    touchpad.setPrice(price);
    touchpad.setQuantity(quantity);
    touchpad.setOnDisplay(on_display);
    touchpad.setType(type_s);
    touchpad.setDimensions(length, width);
    touchpad.setImagePath(image_path_s);
    Touchpad::updateVec(touchpad);
}

void Dev::addUSB_Drive() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string storage_cap_s;
    std::string interface_s;
    std::string transfer_rate_s;
    std::string image_path_s;

    double price;
    int quantity, storage_cap, transfer_rate;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Storage capacity (GB): ";
    std::getline(std::cin, storage_cap_s);
    checkInt(storage_cap_s, storage_cap);
    std::cout << "Interface: ";
    std::getline(std::cin, interface_s);
    std::cout << "Transfer rate (MB/s): ";
    std::getline(std::cin, transfer_rate_s);
    checkInt(transfer_rate_s, transfer_rate);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    UsbDrive usb_drive;
    usb_drive.setDescription(desc_s);
    usb_drive.setBrand(brand_s);
    usb_drive.setModel(model_s);
    usb_drive.setPrice(price);
    usb_drive.setQuantity(quantity);
    usb_drive.setOnDisplay(on_display);
    usb_drive.setCapacity(storage_cap);
    usb_drive.setInterface(interface_s);
    usb_drive.setTransferSpeed(transfer_rate);
    usb_drive.setImagePath(image_path_s);
    UsbDrive::updateVec(usb_drive);
}

void Dev::addWebcam() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string fps_s;
    std::string fov_s;
    std::string mic_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string image_path_s;

    double price, length, width, height;
    int quantity, res_w, res_h, fps, fov;
    bool on_display, mic;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "FPS: ";
    std::getline(std::cin, fps_s);
    checkInt(fps_s, fps);
    std::cout << "Field of view (degrees): ";
    std::getline(std::cin, fov_s);
    checkInt(fov_s, fov);
    std::cout << "Microphone (1 for yes, 0 for no): ";
    std::getline(std::cin, mic_s);
    checkBool(mic_s, mic);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Webcam webcam;
    webcam.setDescription(desc_s);
    webcam.setBrand(brand_s);
    webcam.setModel(model_s);
    webcam.setPrice(price);
    webcam.setQuantity(quantity);
    webcam.setOnDisplay(on_display);
    webcam.setResolution(res_w, res_h);
    webcam.setFps(fps);
    webcam.setFieldOfView(fov);
    webcam.setHasMicrophone(mic);
    webcam.setDimensions(length, width, height);
    webcam.setImagePath(image_path_s);
    Webcam::updateVec(webcam);
}

void Dev::addWire() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string length_s;
    std::string type_s;
    std::string image_path_s;

    double price, length;
    int quantity;
    bool on_display;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Length (m): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Type: ";
    std::getline(std::cin, type_s);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Wire wire;
    wire.setDescription(desc_s);
    wire.setBrand(brand_s);
    wire.setModel(model_s);
    wire.setPrice(price);
    wire.setQuantity(quantity);
    wire.setOnDisplay(on_display);
    wire.setLength(length);
    wire.setType(type_s);
    wire.setImagePath(image_path_s);
    Wire::updateVec(wire);
}

void Dev::addSmartphones() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string processor_s;
    std::string os_s;
    std::string charger_s;
    std::string camera_s;
    std::string num_sim_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string storage_s;
    std::string refresh_r_s;
    std::string wifi_s;
    std::string brightness_s;
    std::string bluetooth_s;
    std::string weight_s;
    std::string battery_s;
    std::string finger_s;
    std::string face_s;
    std::string iris_s;
    std::string dual_sim_s;
    std::string micro_sd_s;
    std::string jack_s;
    std::string pen_s;   
    std::string image_path_s;

    double price, length, width, height, weight, battery, wifi, brightness, bluetooth;
    int quantity, res_w, res_h, storage, refresh_r, num_sim;
    bool on_display, finger, face, iris, dual_sim, micro_sd, jack, pen;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);    
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Display type: ";
    std::getline(std::cin, display_s);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "Processor: ";
    std::getline(std::cin, processor_s);
    std::cout << "Operating system: ";
    std::getline(std::cin, os_s);
    std::cout << "Charger: ";
    std::getline(std::cin, charger_s);
    std::cout << "Camera: ";
    std::getline(std::cin, camera_s);
    std::cout << "Number of SIMs: ";
    std::getline(std::cin, num_sim_s);
    checkInt(num_sim_s, num_sim);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Storage (GB): ";
    std::getline(std::cin, storage_s);
    checkInt(storage_s, storage);
    std::cout << "Refresh rate (Hz): ";
    std::getline(std::cin, refresh_r_s);
    checkInt(refresh_r_s, refresh_r);
    std::cout << "WiFi: ";
    std::getline(std::cin, wifi_s);
    checkDouble(wifi_s, wifi);
    std::cout << "Brightness (nits): ";
    std::getline(std::cin, brightness_s);
    checkDouble(brightness_s, brightness);
    std::cout << "Bluetooth: ";
    std::getline(std::cin, bluetooth_s);
    checkDouble(bluetooth_s, bluetooth);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Battery (mAh): ";
    std::getline(std::cin, battery_s);
    checkDouble(battery_s, battery);
    std::cout << "Fingerprint sensor (1 for yes, 0 for no): ";
    std::getline(std::cin, finger_s);
    checkBool(finger_s, finger);
    std::cout << "Face recognition (1 for yes, 0 for no): ";
    std::getline(std::cin, face_s);
    checkBool(face_s, face);
    std::cout << "Iris scanner (1 for yes, 0 for no): ";
    std::getline(std::cin, iris_s);
    checkBool(iris_s, iris);
    std::cout << "Dual SIM (1 for yes, 0 for no): ";
    std::getline(std::cin, dual_sim_s);
    checkBool(dual_sim_s, dual_sim);
    std::cout << "Micro SD slot (1 for yes, 0 for no): ";
    std::getline(std::cin, micro_sd_s);
    checkBool(micro_sd_s, micro_sd);
    std::cout << "Jack (1 for yes, 0 for no): ";
    std::getline(std::cin, jack_s);
    checkBool(jack_s, jack);
    std::cout << "Pen (1 for yes, 0 for no): ";
    std::getline(std::cin, pen_s);
    checkBool(pen_s, pen);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);
    
    Smartphones smartphones;
    smartphones.setDescription(desc_s);
    smartphones.setBrand(brand_s);
    smartphones.setModel(model_s);
    smartphones.setPrice(price);
    smartphones.setQuantity(quantity);
    smartphones.setOnDisplay(on_display);
    smartphones.setDisplay(display_s);
    smartphones.setResolution(res_w, res_h);
    smartphones.setProcessor(processor_s);
    smartphones.setOS(os_s);
    smartphones.setCharger(charger_s);
    smartphones.setCameraSpec(camera_s);
    smartphones.setNumSim(num_sim);
    smartphones.setDimensions(length, width, height);
    smartphones.setStorage(storage);
    smartphones.setRefreshRate(refresh_r);
    smartphones.setWifi(wifi);
    smartphones.setBrightness(brightness);
    smartphones.setBluetooth(bluetooth);
    smartphones.setWeight(weight);
    smartphones.setBattery(battery);
    smartphones.setBiometrics(finger, face, iris);
    smartphones.setMicroSD(micro_sd);
    smartphones.setJack(jack);
    smartphones.setHasPen(pen);
    smartphones.setImagePath(image_path_s);
    Smartphones::updateVec(smartphones);
}

void Dev::addSmartwatch() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string display_s;
    std::string sim_s;
    std::string bluetooth_s;
    std::string wifi_s;
    std::string capacity_s;
    std::string screensize_s;
    std::string case_size_s;
    std::string brightness_s;
    std::string water_r_s;
    std::string battery_s;
    std::string weight_s;
    std::string heartr_s;
    std::string mic_s;
    std::string gps_s;
    std::string blood_o2_s;
    std::string speaker_s;
    std::string image_path_s;

    double price, bluetooth, wifi, capacity, screensize, case_size, brightness, water_r, battery, weight;
    int quantity;
    bool on_display, sim, heartr, mic, gps, blood_o2, speaker;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Display type: ";
    std::getline(std::cin, display_s);
    std::cout << "SIM card slot (1 for yes, 0 for no): ";
    std::getline(std::cin, sim_s);
    checkBool(sim_s, sim);
    std::cout << "Bluetooth: ";
    std::getline(std::cin, bluetooth_s);
    checkDouble(bluetooth_s, bluetooth);
    std::cout << "WiFi: ";
    std::getline(std::cin, wifi_s);
    checkDouble(wifi_s, wifi);
    std::cout << "Capacity (GB): ";
    std::getline(std::cin, capacity_s);
    checkDouble(capacity_s, capacity);
    std::cout << "Screen size (mm): ";
    std::getline(std::cin, screensize_s);
    checkDouble(screensize_s, screensize);
    std::cout << "Case size (mm): ";
    std::getline(std::cin, case_size_s);
    checkDouble(case_size_s, case_size);
    std::cout << "Brightness (nits): ";
    std::getline(std::cin, brightness_s);
    checkDouble(brightness_s, brightness);
    std::cout << "Water resistance (m): ";
    std::getline(std::cin, water_r_s);
    checkDouble(water_r_s, water_r);
    std::cout << "Battery (mAh): ";
    std::getline(std::cin, battery_s);
    checkDouble(battery_s, battery);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Heart rate sensor (1 for yes, 0 for no): ";
    std::getline(std::cin, heartr_s);
    checkBool(heartr_s, heartr);
    std::cout << "Microphone (1 for yes, 0 for no): ";
    std::getline(std::cin, mic_s);
    checkBool(mic_s, mic);
    std::cout << "GPS (1 for yes, 0 for no): ";
    std::getline(std::cin, gps_s);
    checkBool(gps_s, gps);
    std::cout << "Blood oxygen sensor (1 for yes, 0 for no): ";
    std::getline(std::cin, blood_o2_s);
    checkBool(blood_o2_s, blood_o2);
    std::cout << "Speaker (1 for yes, 0 for no): ";
    std::getline(std::cin, speaker_s);
    checkBool(speaker_s, speaker);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);
    
    Smartwatch smartwatch;
    smartwatch.setDescription(desc_s);
    smartwatch.setBrand(brand_s);
    smartwatch.setModel(model_s);
    smartwatch.setPrice(price);
    smartwatch.setQuantity(quantity);
    smartwatch.setOnDisplay(on_display);
    smartwatch.setDisplay(display_s);
    smartwatch.setSim(sim);
    smartwatch.setBluetooth(bluetooth);
    smartwatch.setWifi(wifi);
    smartwatch.setCapacity(capacity);
    smartwatch.setScreenSize(screensize);
    smartwatch.setCaseSize(case_size);
    smartwatch.setBrightness(brightness);
    smartwatch.setWaterResistance(water_r);
    smartwatch.setBattery(battery);
    smartwatch.setWeight(weight);
    smartwatch.setHeartrateMonitoring(heartr);
    smartwatch.setHasMicrophones(mic);
    smartwatch.setHasGps(gps);
    smartwatch.setHeartrateMonitoring(blood_o2);
    smartwatch.setHasSpeaker(speaker);
    smartwatch.setImagePath(image_path_s);
    Smartwatch::updateVec(smartwatch);
}

void Dev::addTablet() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string display_s;
    std::string processor_s;
    std::string os_s;
    std::string storage_s;
    std::string camera_s;
    std::string battery_s;
    std::string bluetooth_s;
    std::string res_h_s;
    std::string res_w_s;
    std::string length_s;
    std::string width_s;
    std::string height_s;
    std::string weight_s;
    std::string brightness_s;
    std::string wifi_s;
    std::string pen_s;
    std::string internal_m_s;
    std::string external_m_s;
    std::string speaker_s;
    std::string finger_s;
    std::string face_s;
    std::string iris_s;
    std::string waterproof_s;
    std::string image_path_s;

    double price, battery, length, width, height, weight, brightness;
    int quantity, res_h, res_w;
    bool on_display, pen, finger, face, iris, waterproof;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);
    checkBool(on_display_s, on_display);
    std::cout << "Display type: ";
    std::getline(std::cin, display_s);
    std::cout << "Processor: ";
    std::getline(std::cin, processor_s);
    std::cout << "Operating system: ";
    std::getline(std::cin, os_s);
    std::cout << "Storage: ";
    std::getline(std::cin, storage_s);
    std::cout << "Camera: ";
    std::getline(std::cin, camera_s);
    std::cout << "Battery (mAh): ";
    std::getline(std::cin, battery_s);
    checkDouble(battery_s, battery);
    std::cout << "Bluetooth: ";
    std::getline(std::cin, bluetooth_s);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "Length (mm): ";
    std::getline(std::cin, length_s);
    checkDouble(length_s, length);
    std::cout << "Width (mm): ";
    std::getline(std::cin, width_s);
    checkDouble(width_s, width);
    std::cout << "Height (mm): ";
    std::getline(std::cin, height_s);
    checkDouble(height_s, height);
    std::cout << "Weight (g): ";
    std::getline(std::cin, weight_s);
    checkDouble(weight_s, weight);
    std::cout << "Brightness (nits): ";
    std::getline(std::cin, brightness_s);
    checkDouble(brightness_s, brightness);
    std::cout << "WiFi: ";
    std::getline(std::cin, wifi_s);
    std::cout << "Pen (1 for yes, 0 for no): ";
    std::getline(std::cin, pen_s);
    checkBool(pen_s, pen);
    std::cout << "Internal memory (GB): ";
    std::getline(std::cin, internal_m_s);
    std::cout << "External memory (GB): ";
    std::getline(std::cin, external_m_s);
    std::cout << "Speaker (1 for yes, 0 for no): ";
    std::getline(std::cin, speaker_s);
    std::cout << "Fingerprint sensor (1 for yes, 0 for no): ";
    std::getline(std::cin, finger_s);
    checkBool(finger_s, finger);
    std::cout << "Face recognition (1 for yes, 0 for no): ";
    std::getline(std::cin, face_s);
    checkBool(face_s, face);
    std::cout << "Iris scanner (1 for yes, 0 for no): ";
    std::getline(std::cin, iris_s);
    checkBool(iris_s, iris);
    std::cout << "Waterproof (1 for yes, 0 for no): ";  
    std::getline(std::cin, waterproof_s);
    checkBool(waterproof_s, waterproof);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    Tablet tablet;
    tablet.setDescription(desc_s);
    tablet.setBrand(brand_s);
    tablet.setModel(model_s);
    tablet.setPrice(price);
    tablet.setQuantity(quantity);
    tablet.setOnDisplay(on_display);
    tablet.setDisplay(display_s);
    tablet.setProcessor(processor_s);
    tablet.setOs(os_s);
    tablet.setStorage(storage_s);
    tablet.setCamera(camera_s);
    tablet.setBattery(battery);
    tablet.setBluetooth(bluetooth_s);
    tablet.setResolution(res_w, res_h);
    tablet.setDimensions(length, width, height);
    tablet.setWeight(weight);
    tablet.setBrightness(brightness);
    tablet.setWifi(wifi_s);
    tablet.setHavePen(pen);
    tablet.setInternal_Memory(internal_m_s);
    tablet.setExternal_Memory(external_m_s);
    tablet.setSpeaker(speaker_s);
    tablet.setBiometrics(finger, face, iris);
    tablet.setIsWaterproof(waterproof);
    tablet.setImagePath(image_path_s);
    Tablet::updateVec(tablet);
}

void Dev::addVR() const{
    std::string desc_s, brand_s, model_s, price_s, quantity_s, on_display_s;
    std::string display_s;
    std::string res_w_s;
    std::string res_h_s;
    std::string with_cont_s;
    std::string type_usb_s;
    std::string max_refresh_s;
    std::string fov_s;
    std::string display_size_s;
    std::string image_path_s;

    double price, display_size, fov;
    int quantity, res_w, res_h, max_refresh;;
    bool on_display, with_cont;

    std::cout << "Description: ";
    std::getline(std::cin, desc_s);
    std::cout << "Brand: ";
    std::getline(std::cin, brand_s);
    std::cout << "Model: ";
    std::getline(std::cin, model_s);
    std::cout << "Price: ";
    std::getline(std::cin, price_s);
    checkDouble(price_s, price);
    std::cout << "Quantity: ";
    std::getline(std::cin, quantity_s);
    checkInt(quantity_s, quantity);
    std::cout << "On display (1 for yes, 0 for no): ";
    std::getline(std::cin, on_display_s);   
    checkBool(on_display_s, on_display);
    std::cout << "Display type: ";
    std::getline(std::cin, display_s);
    std::cout << "Resolution width (px): ";
    std::getline(std::cin, res_w_s);
    checkInt(res_w_s, res_w);
    std::cout << "Resolution height (px): ";
    std::getline(std::cin, res_h_s);
    checkInt(res_h_s, res_h);
    std::cout << "With controller (1 for yes, 0 for no): ";
    std::getline(std::cin, with_cont_s);
    checkBool(with_cont_s, with_cont);
    std::cout << "Type of USB: ";
    std::getline(std::cin, type_usb_s);
    std::cout << "Max refresh rate (Hz): ";
    std::getline(std::cin, max_refresh_s);
    checkInt(max_refresh_s, max_refresh);
    std::cout << "Field of view (degrees): ";
    std::getline(std::cin, fov_s);
    checkDouble(fov_s, fov);
    std::cout << "Display size (inches): ";
    std::getline(std::cin, display_size_s);
    checkDouble(display_size_s, display_size);
    std::cout << "Image name in img folder (\"n\" for no image): ";
    std::getline(std::cin, image_path_s);
    checkImage(image_path_s);

    VR vr;
    vr.setDescription(desc_s);
    vr.setBrand(brand_s);
    vr.setModel(model_s);
    vr.setPrice(price);
    vr.setQuantity(quantity);
    vr.setOnDisplay(on_display);
    vr.setDisplay(display_s);
    vr.setResolution(res_w, res_h);
    vr.setWithControllers(with_cont);
    vr.setUsbCable(type_usb_s);
    vr.setRefreshRate(max_refresh);
    vr.setFieldOfView(fov);
    vr.setSizeDisplayInch(display_size);
    vr.setImagePath(image_path_s);
    VR::updateVec(vr);
}

//----------------------------------------------------------------------------------------------

void Dev::removeDevice(const std::string id) const{
    if (id.size() != 6){
        std::cout << "Invalid ID\n";
        return;
    }
    const std::string id_start = id.substr(0, 2);
    if (id_start == "AA"){
        CPU::cpu_vec.erase(std::remove_if(CPU::cpu_vec.begin(), CPU::cpu_vec.end(), [id](const CPU& cpu){return cpu.getID() == id;}), CPU::cpu_vec.end());
        try{
            CPU::updateVec(CPU::cpu_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/cpu.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AB") {
        GPU::gpu_vec.erase(std::remove_if(GPU::gpu_vec.begin(), GPU::gpu_vec.end(), [id](const GPU& gpu){return gpu.getID() == id;}), GPU::gpu_vec.end());
        try{
            GPU::updateVec(GPU::gpu_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/gpu.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AC") {
        Memory::memory_vec.erase(std::remove_if(Memory::memory_vec.begin(), Memory::memory_vec.end(), [id](const Memory& memory){return memory.getID() == id;}), Memory::memory_vec.end());
        try{
            Memory::updateVec(Memory::memory_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/memory.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AD") {
        CoolingUnit::cooling_unit_vec.erase(std::remove_if(CoolingUnit::cooling_unit_vec.begin(), CoolingUnit::cooling_unit_vec.end(), [id](const CoolingUnit& cooling_unit){return cooling_unit.getID() == id;}), CoolingUnit::cooling_unit_vec.end());
        try{
            CoolingUnit::updateVec(CoolingUnit::cooling_unit_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/cooling_unit.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AE") {
        PCCase::pc_case_vec.erase(std::remove_if(PCCase::pc_case_vec.begin(), PCCase::pc_case_vec.end(), [id](const PCCase& pc_case){return pc_case.getID() == id;}), PCCase::pc_case_vec.end());
        try{
            PCCase::updateVec(PCCase::pc_case_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/pc_case.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AF") {
        Motherboard::motherboard_vec.erase(std::remove_if(Motherboard::motherboard_vec.begin(), Motherboard::motherboard_vec.end(), [id](const Motherboard& motherboard){return motherboard.getID() == id;}), Motherboard::motherboard_vec.end());
        try{
            Motherboard::updateVec(Motherboard::motherboard_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/motherboard.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AG") {
        PSU::psu_vec.erase(std::remove_if(PSU::psu_vec.begin(), PSU::psu_vec.end(), [id](const PSU& psu){return psu.getID() == id;}), PSU::psu_vec.end());
        try{
            PSU::updateVec(PSU::psu_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/psu.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AH") {
        SSD::ssd_vec.erase(std::remove_if(SSD::ssd_vec.begin(), SSD::ssd_vec.end(), [id](const SSD& ssd){return ssd.getID() == id;}), SSD::ssd_vec.end());
        try{
            SSD::updateVec(SSD::ssd_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/ssd.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AI") {
        HDD::hdd_vec.erase(std::remove_if(HDD::hdd_vec.begin(), HDD::hdd_vec.end(), [id](const HDD& hdd){return hdd.getID() == id;}), HDD::hdd_vec.end());
        try{
            HDD::updateVec(HDD::hdd_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/hdd.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AJ") {
        Wire::wire_vec.erase(std::remove_if(Wire::wire_vec.begin(), Wire::wire_vec.end(), [id](const Wire& wire){return wire.getID() == id;}), Wire::wire_vec.end());
        try{
            Wire::updateVec(Wire::wire_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/wire.txt", std::ios::trunc);
            std::cout << "cleared\n";
            file.close();
        }
        return;
    } else if (id_start == "AK") {
        Mouse::mouse_vec.erase(std::remove_if(Mouse::mouse_vec.begin(), Mouse::mouse_vec.end(), [id](const Mouse& mouse){return mouse.getID() == id;}), Mouse::mouse_vec.end());
        try{
            Mouse::updateVec(Mouse::mouse_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/mouse.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AL") {
        Keyboard::keyboard_vec.erase(std::remove_if(Keyboard::keyboard_vec.begin(), Keyboard::keyboard_vec.end(), [id](const Keyboard& keyboard){return keyboard.getID() == id;}), Keyboard::keyboard_vec.end());
        try{
            Keyboard::updateVec(Keyboard::keyboard_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/keyboard.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AM") {
        Touchpad::touchpad_vec.erase(std::remove_if(Touchpad::touchpad_vec.begin(), Touchpad::touchpad_vec.end(), [id](const Touchpad& touchpad){return touchpad.getID() == id;}), Touchpad::touchpad_vec.end());
        try{
            Touchpad::updateVec(Touchpad::touchpad_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/touchpad.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AN") {
        Display::display_vec.erase(std::remove_if(Display::display_vec.begin(), Display::display_vec.end(), [id](const Display& display){return display.getID() == id;}), Display::display_vec.end());
        try{
            Display::updateVec(Display::display_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/display.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AO") {
        Earbuds::earbuds_vec.erase(std::remove_if(Earbuds::earbuds_vec.begin(), Earbuds::earbuds_vec.end(), [id](const Earbuds& earbuds){return earbuds.getID() == id;}), Earbuds::earbuds_vec.end());
        try{
            Earbuds::updateVec(Earbuds::earbuds_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/earbuds.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AP") {
        Earphones::earphones_vec.erase(std::remove_if(Earphones::earphones_vec.begin(), Earphones::earphones_vec.end(), [id](const Earphones& earphones){return earphones.getID() == id;}), Earphones::earphones_vec.end());
        try{
            Earphones::updateVec(Earphones::earphones_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/earphones.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AQ") {
        Headset::headset_vec.erase(std::remove_if(Headset::headset_vec.begin(), Headset::headset_vec.end(), [id](const Headset& headset){return headset.getID() == id;}), Headset::headset_vec.end());
        try{
            Headset::updateVec(Headset::headset_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/headset.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AR") {
        Headphones::headphones_vec.erase(std::remove_if(Headphones::headphones_vec.begin(), Headphones::headphones_vec.end(), [id](const Headphones& headphones){return headphones.getID() == id;}), Headphones::headphones_vec.end());
        try{
            Headphones::updateVec(Headphones::headphones_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/headphones.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AS") {
        Speakers::speakers_vec.erase(std::remove_if(Speakers::speakers_vec.begin(), Speakers::speakers_vec.end(), [id](const Speakers& speakers){return speakers.getID() == id;}), Speakers::speakers_vec.end());
        try{
            Speakers::updateVec(Speakers::speakers_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/speakers.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AT") {
        Microphone::microphone_vec.erase(std::remove_if(Microphone::microphone_vec.begin(), Microphone::microphone_vec.end(), [id](const Microphone& microphone){return microphone.getID() == id;}), Microphone::microphone_vec.end());
        try{
            Microphone::updateVec(Microphone::microphone_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/microphone.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AU"){
        Printer::printer_vec.erase(std::remove_if(Printer::printer_vec.begin(), Printer::printer_vec.end(), [id](const Printer& printer){return printer.getID() == id;}), Printer::printer_vec.end());
        try{
            Printer::updateVec(Printer::printer_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/printer.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AV"){
        Webcam::webcam_vec.erase(std::remove_if(Webcam::webcam_vec.begin(), Webcam::webcam_vec.end(), [id](const Webcam& webcam){return webcam.getID() == id;}), Webcam::webcam_vec.end());
        try{
            Webcam::updateVec(Webcam::webcam_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/webcam.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AW"){
        UsbDrive::usb_drive_vec.erase(std::remove_if(UsbDrive::usb_drive_vec.begin(), UsbDrive::usb_drive_vec.end(), [id](const UsbDrive& usb_drive){return usb_drive.getID() == id;}), UsbDrive::usb_drive_vec.end());
        try{
            UsbDrive::updateVec(UsbDrive::usb_drive_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/usb_drive.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AX"){
        Portable_HDD::portable_hdd_vec.erase(std::remove_if(Portable_HDD::portable_hdd_vec.begin(), Portable_HDD::portable_hdd_vec.end(), [id](const Portable_HDD& portable_hdd){return portable_hdd.getID() == id;}), Portable_HDD::portable_hdd_vec.end());
        try{
            Portable_HDD::updateVec(Portable_HDD::portable_hdd_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/portable_hdd.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AY"){
        SdCard::sd_card_vec.erase(std::remove_if(SdCard::sd_card_vec.begin(), SdCard::sd_card_vec.end(), [id](const SdCard& sd_card){return sd_card.getID() == id;}), SdCard::sd_card_vec.end());
        try{
            SdCard::updateVec(SdCard::sd_card_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/sd_card.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "AZ"){
        VR::vr_vec.erase(std::remove_if(VR::vr_vec.begin(), VR::vr_vec.end(), [id](const VR& vr){return vr.getID() == id;}), VR::vr_vec.end());
        try{
            VR::updateVec(VR::vr_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/vr.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BA"){
        Smartphones::smartphones_vec.erase(std::remove_if(Smartphones::smartphones_vec.begin(), Smartphones::smartphones_vec.end(), [id](const Smartphones& smartphones){return smartphones.getID() == id;}), Smartphones::smartphones_vec.end());
        try{
            Smartphones::updateVec(Smartphones::smartphones_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/smartphones.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BB"){
        Smartwatch::smartwatch_vec.erase(std::remove_if(Smartwatch::smartwatch_vec.begin(), Smartwatch::smartwatch_vec.end(), [id](const Smartwatch& smartwatch){return smartwatch.getID() == id;}), Smartwatch::smartwatch_vec.end());
        try{
            Smartwatch::updateVec(Smartwatch::smartwatch_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/smartwatch.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BC"){
        Stationed::stationed_vec.erase(std::remove_if(Stationed::stationed_vec.begin(), Stationed::stationed_vec.end(), [id](const Stationed& stationed){return stationed.getID() == id;}), Stationed::stationed_vec.end());
        try{
            Stationed::updateVec(Stationed::stationed_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/stationed.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BD"){
        Tablet::tablet_vec.erase(std::remove_if(Tablet::tablet_vec.begin(), Tablet::tablet_vec.end(), [id](const Tablet& tablet){return tablet.getID() == id;}), Tablet::tablet_vec.end());
        try{
            Tablet::updateVec(Tablet::tablet_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/tablet.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BE"){
        Laptop::laptop_vec.erase(std::remove_if(Laptop::laptop_vec.begin(), Laptop::laptop_vec.end(), [id](const Laptop& laptop){return laptop.getID() == id;}), Laptop::laptop_vec.end());
        try{
            Laptop::updateVec(Laptop::laptop_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/laptop.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BG"){
        Desktop::desktop_vec.erase(std::remove_if(Desktop::desktop_vec.begin(), Desktop::desktop_vec.end(), [id](const Desktop& desktop){return desktop.getID() == id;}), Desktop::desktop_vec.end());
        try{
            Desktop::updateVec(Desktop::desktop_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/desktop.txt", std::ios::trunc);
            file.close();
        }
        return;
    } else if (id_start == "BH"){
        Handheld::handheld_vec.erase(std::remove_if(Handheld::handheld_vec.begin(), Handheld::handheld_vec.end(), [id](const Handheld& handheld){return handheld.getID() == id;}), Handheld::handheld_vec.end());
        try{
            Handheld::updateVec(Handheld::handheld_vec[0]);
        }catch (std::out_of_range& e){
            std::ofstream file("../txt_files/handheld.txt", std::ios::trunc);
            file.close();
        }
    }
    std::cout << "Invalid ID\n";
    return;
}

void Dev::putOnDisplay(std::string id) const{
    if (id.size() != 6){
        std::cout << "Invalid ID\n";
        return;
    }
    const std::string id_start = id.substr(0, 2);
    if (id_start == "AA"){
        for (CPU& cpu : CPU::cpu_vec){
            if (cpu.getID() == id){
                cpu.setOnDisplay(true);
                CPU::updateVec(cpu);
                return;
            }
        }
    } else if (id_start == "AB") {
        for (GPU& gpu : GPU::gpu_vec){
            if (gpu.getID() == id){
                gpu.setOnDisplay(true);
                GPU::updateVec(gpu);
                return;
            }
        }
    } else if (id_start == "AC") {
        for (Memory& memory : Memory::memory_vec){
            if (memory.getID() == id){
                memory.setOnDisplay(true);
                Memory::updateVec(memory);
                return;
            }
        }
    } else if (id_start == "AD") {
        for (CoolingUnit& cooling_unit : CoolingUnit::cooling_unit_vec){
            if (cooling_unit.getID() == id){
                cooling_unit.setOnDisplay(true);
                CoolingUnit::updateVec(cooling_unit);
                return;
            }
        }
    } else if (id_start == "AE") {
        for (PCCase& pc_case : PCCase::pc_case_vec){
            if (pc_case.getID() == id){
                pc_case.setOnDisplay(true);
                PCCase::updateVec(pc_case);
                return;
            }
        }
    } else if (id_start == "AF") {
        for (Motherboard& motherboard : Motherboard::motherboard_vec){
            if (motherboard.getID() == id){
                motherboard.setOnDisplay(true);
                Motherboard::updateVec(motherboard);
                return;
            }
        }
    } else if (id_start == "AG") {
        for (PSU& psu : PSU::psu_vec){
            if (psu.getID() == id){
                psu.setOnDisplay(true);
                PSU::updateVec(psu);
                return;
            }
        }
    } else if (id_start == "AH") {
        for (SSD& ssd : SSD::ssd_vec){
            if (ssd.getID() == id){
                ssd.setOnDisplay(true);
                SSD::updateVec(ssd);
                return;
            }
        }
    } else if (id_start == "AI") {
        for (HDD& hdd : HDD::hdd_vec){
            if (hdd.getID() == id){
                hdd.setOnDisplay(true);
                HDD::updateVec(hdd);
                return;
            }
        }
    } else if (id_start == "AJ") {
        for (Wire& wire : Wire::wire_vec){
            if (wire.getID() == id){
                wire.setOnDisplay(true);
                Wire::updateVec(wire);
                return;
            }
        }
    } else if (id_start == "AK") {
        for (Mouse& mouse : Mouse::mouse_vec){
            if (mouse.getID() == id){
                mouse.setOnDisplay(true);
                Mouse::updateVec(mouse);
                return;
            }
        }
    } else if (id_start == "AL") {
        for (Keyboard& keyboard : Keyboard::keyboard_vec){
            if (keyboard.getID() == id){
                keyboard.setOnDisplay(true);
                Keyboard::updateVec(keyboard);
                return;
            }
        }
    } else if (id_start == "AM") {
        for (Touchpad& touchpad : Touchpad::touchpad_vec){
            if (touchpad.getID() == id){
                touchpad.setOnDisplay(true);
                Touchpad::updateVec(touchpad);
                return;
            }
        }
    } else if (id_start == "AN") {
        for (Display& display : Display::display_vec){
            if (display.getID() == id){
                display.setOnDisplay(true);
                Display::updateVec(display);
                return;
            }
        }
    } else if (id_start == "AO") {
        for (Earbuds& earbuds : Earbuds::earbuds_vec){
            if (earbuds.getID() == id){
                earbuds.setOnDisplay(true);
                Earbuds::updateVec(earbuds);
                return;
            }
        }
    } else if (id_start == "AP") {
        for (Earphones& earphones : Earphones::earphones_vec){
            if (earphones.getID() == id){
                earphones.setOnDisplay(true);
                Earphones::updateVec(earphones);
                return;
            }
        }
    } else if (id_start == "AQ") {
        for (Headset& headset : Headset::headset_vec){
            if (headset.getID() == id){
                headset.setOnDisplay(true);
                Headset::updateVec(headset);
                return;
            }
        }
    } else if (id_start == "AR") {
        for (Headphones& headphones : Headphones::headphones_vec){
            if (headphones.getID() == id){
                headphones.setOnDisplay(true);
                Headphones::updateVec(headphones);
                return;
            }
        }
    } else if (id_start == "AS") {
        for (Speakers& speakers : Speakers::speakers_vec){
            if (speakers.getID() == id){
                speakers.setOnDisplay(true);
                Speakers::updateVec(speakers);
                return;
            }
        }
    } else if (id_start == "AT") {
        for (Microphone& microphone : Microphone::microphone_vec){
            if (microphone.getID() == id){
                microphone.setOnDisplay(true);
                Microphone::updateVec(microphone);
                return;
            }
        }
    } else if (id_start == "AU"){
        for (Printer& printer : Printer::printer_vec){
            if (printer.getID() == id){
                printer.setOnDisplay(true);
                Printer::updateVec(printer);
                return;
            }
        }
    } else if (id_start == "AV"){
        for (Webcam& webcam : Webcam::webcam_vec){
            if (webcam.getID() == id){
                webcam.setOnDisplay(true);
                Webcam::updateVec(webcam);
                return;
            }
        }
    } else if (id_start == "AW"){
        for (UsbDrive& usb_drive : UsbDrive::usb_drive_vec){
            if (usb_drive.getID() == id){
                usb_drive.setOnDisplay(true);
                UsbDrive::updateVec(usb_drive);
                return;
            }
        }
    } else if (id_start == "AX"){
        for (Portable_HDD& portable_hdd : Portable_HDD::portable_hdd_vec){
            if (portable_hdd.getID() == id){
                portable_hdd.setOnDisplay(true);
                Portable_HDD::updateVec(portable_hdd);
                return;
            }
        }
    } else if (id_start == "AY"){
        for (SdCard& sd_card : SdCard::sd_card_vec){
            if (sd_card.getID() == id){
                sd_card.setOnDisplay(true);
                SdCard::updateVec(sd_card);
                return;
            }
        }
    } else if (id_start == "AZ"){
        for (VR& vr : VR::vr_vec){
            if (vr.getID() == id){
                vr.setOnDisplay(true);
                VR::updateVec(vr);
                return;
            }
        }
    } else if (id_start == "BA"){
        for (Smartphones& smartphones : Smartphones::smartphones_vec){
            if (smartphones.getID() == id){
                smartphones.setOnDisplay(true);
                Smartphones::updateVec(smartphones);
                return;
            }
        }
    } else if (id_start == "BB"){
        for (Smartwatch& smartwatch : Smartwatch::smartwatch_vec){
            if (smartwatch.getID() == id){
                smartwatch.setOnDisplay(true);
                Smartwatch::updateVec(smartwatch);
                return;
            }
        }
    } else if (id_start == "BC"){
        for (Stationed& stationed : Stationed::stationed_vec){
            if (stationed.getID() == id){
                stationed.setOnDisplay(true);
                Stationed::updateVec(stationed);
                return;
            }
        }
    } else if (id_start == "BD"){
        for (Tablet& tablet : Tablet::tablet_vec){
            if (tablet.getID() == id){
                tablet.setOnDisplay(true);
                Tablet::updateVec(tablet);
                return;
            }
        }
    } else if (id_start == "BE"){
        for (Laptop& laptop : Laptop::laptop_vec){
            if (laptop.getID() == id){
                laptop.setOnDisplay(true);
                Laptop::updateVec(laptop);
                return;
            }
        }
    } else if (id_start == "BG"){
        for (Desktop& desktop : Desktop::desktop_vec){
            if (desktop.getID() == id){
                desktop.setOnDisplay(true);
                Desktop::updateVec(desktop);
                return;
            }
        }
    } else if (id_start == "BH"){
        for (Handheld& handheld : Handheld::handheld_vec){
            if (handheld.getID() == id){
                handheld.setOnDisplay(true);
                Handheld::updateVec(handheld);
                return;
            }
        }
    }
    std::cout << "Invalid ID\n";
    return;
}

void Dev::removeFromDisplay(std::string id) const{
    if (id.size() != 6){
        std::cout << "Invalid ID\n";
        return;
    }
    const std::string id_start = id.substr(0, 2);
    if (id_start == "AA"){
        for (CPU& cpu : CPU::cpu_vec){
            if (cpu.getID() == id){
                cpu.setOnDisplay(false);
                CPU::updateVec(cpu);
                return;
            }
        }
    } else if (id_start == "AB") {
        for (GPU& gpu : GPU::gpu_vec){
            if (gpu.getID() == id){
                gpu.setOnDisplay(false);
                GPU::updateVec(gpu);
                return;
            }
        }
    } else if (id_start == "AC") {
        for (Memory& memory : Memory::memory_vec){
            if (memory.getID() == id){
                memory.setOnDisplay(false);
                Memory::updateVec(memory);
                return;
            }
        }
    } else if (id_start == "AD") {
        for (CoolingUnit& cooling_unit : CoolingUnit::cooling_unit_vec){
            if (cooling_unit.getID() == id){
                cooling_unit.setOnDisplay(false);
                CoolingUnit::updateVec(cooling_unit);
                return;
            }
        }
    } else if (id_start == "AE") {
        for (PCCase& pc_case : PCCase::pc_case_vec){
            if (pc_case.getID() == id){
                pc_case.setOnDisplay(false);
                PCCase::updateVec(pc_case);
                return;
            }
        }
    } else if (id_start == "AF") {
        for (Motherboard& motherboard : Motherboard::motherboard_vec){
            if (motherboard.getID() == id){
                motherboard.setOnDisplay(false);
                Motherboard::updateVec(motherboard);
                return;
            }
        }
    } else if (id_start == "AG") {
        for (PSU& psu : PSU::psu_vec){
            if (psu.getID() == id){
                psu.setOnDisplay(false);
                PSU::updateVec(psu);
                return;
            }
        }
    } else if (id_start == "AH") {
        for (SSD& ssd : SSD::ssd_vec){
            if (ssd.getID() == id){
                ssd.setOnDisplay(false);
                SSD::updateVec(ssd);
                return;
            }
        }
    } else if (id_start == "AI") {
        for (HDD& hdd : HDD::hdd_vec){
            if (hdd.getID() == id){
                hdd.setOnDisplay(false);
                HDD::updateVec(hdd);
                return;
            }
        }
    } else if (id_start == "AJ") {
        for (Wire& wire : Wire::wire_vec){
            if (wire.getID() == id){
                wire.setOnDisplay(false);
                Wire::updateVec(wire);
                return;
            }
        }
    } else if (id_start == "AK") {
        for (Mouse& mouse : Mouse::mouse_vec){
            if (mouse.getID() == id){
                mouse.setOnDisplay(false);
                Mouse::updateVec(mouse);
                return;
            }
        }
    } else if (id_start == "AL") {
        for (Keyboard& keyboard : Keyboard::keyboard_vec){
            if (keyboard.getID() == id){
                keyboard.setOnDisplay(false);
                Keyboard::updateVec(keyboard);
                return;
            }
        }
    } else if (id_start == "AM") {
        for (Touchpad& touchpad : Touchpad::touchpad_vec){
            if (touchpad.getID() == id){
                touchpad.setOnDisplay(false);
                Touchpad::updateVec(touchpad);
                return;
            }
        }
    } else if (id_start == "AN") {
        for (Display& display : Display::display_vec){
            if (display.getID() == id){
                display.setOnDisplay(false);
                Display::updateVec(display);
                return;
            }
        }
    } else if (id_start == "AO") {
        for (Earbuds& earbuds : Earbuds::earbuds_vec){
            if (earbuds.getID() == id){
                earbuds.setOnDisplay(false);
                Earbuds::updateVec(earbuds);
                return;
            }
        }
    } else if (id_start == "AP") {
        for (Earphones& earphones : Earphones::earphones_vec){
            if (earphones.getID() == id){
                earphones.setOnDisplay(false);
                Earphones::updateVec(earphones);
                return;
            }
        }
    } else if (id_start == "AQ") {
        for (Headset& headset : Headset::headset_vec){
            if (headset.getID() == id){
                headset.setOnDisplay(false);
                Headset::updateVec(headset);
                return;
            }
        }
    } else if (id_start == "AR") {
        for (Headphones& headphones : Headphones::headphones_vec){
            if (headphones.getID() == id){
                headphones.setOnDisplay(false);
                Headphones::updateVec(headphones);
                return;
            }
        }
    } else if (id_start == "AS") {
        for (Speakers& speakers : Speakers::speakers_vec){
            if (speakers.getID() == id){
                speakers.setOnDisplay(false);
                Speakers::updateVec(speakers);
                return;
            }
        }
    } else if (id_start == "AT") {
        for (Microphone& microphone : Microphone::microphone_vec){
            if (microphone.getID() == id){
                microphone.setOnDisplay(false);
                Microphone::updateVec(microphone);
                return;
            }
        }
    } else if (id_start == "AU"){
        for (Printer& printer : Printer::printer_vec){
            if (printer.getID() == id){
                printer.setOnDisplay(false);
                Printer::updateVec(printer);
                return;
            }
        }
    } else if (id_start == "AV"){
        for (Webcam& webcam : Webcam::webcam_vec){
            if (webcam.getID() == id){
                webcam.setOnDisplay(false);
                Webcam::updateVec(webcam);
                return;
            }
        }
    } else if (id_start == "AW"){
        for (UsbDrive& usb_drive : UsbDrive::usb_drive_vec){
            if (usb_drive.getID() == id){
                usb_drive.setOnDisplay(false);
                UsbDrive::updateVec(usb_drive);
                return;
            }
        }
    } else if (id_start == "AX"){
        for (Portable_HDD& portable_hdd : Portable_HDD::portable_hdd_vec){
            if (portable_hdd.getID() == id){
                portable_hdd.setOnDisplay(false);
                Portable_HDD::updateVec(portable_hdd);
                return;
            }
        }
    } else if (id_start == "AY"){
        for (SdCard& sd_card : SdCard::sd_card_vec){
            if (sd_card.getID() == id){
                sd_card.setOnDisplay(false);
                SdCard::updateVec(sd_card);
                return;
            }
        }
    } else if (id_start == "AZ"){
        for (VR& vr : VR::vr_vec){
            if (vr.getID() == id){
                vr.setOnDisplay(false);
                VR::updateVec(vr);
                return;
            }
        }
    } else if (id_start == "BA"){
        for (Smartphones& smartphones : Smartphones::smartphones_vec){
            if (smartphones.getID() == id){
                smartphones.setOnDisplay(false);
                Smartphones::updateVec(smartphones);
                return;
            }
        }
    } else if (id_start == "BB"){
        for (Smartwatch& smartwatch : Smartwatch::smartwatch_vec){
            if (smartwatch.getID() == id){
                smartwatch.setOnDisplay(false);
                Smartwatch::updateVec(smartwatch);
                return;
            }
        }
    } else if (id_start == "BC"){
        for (Stationed& stationed : Stationed::stationed_vec){
            if (stationed.getID() == id){
                stationed.setOnDisplay(false);
                Stationed::updateVec(stationed);
                return;
            }
        }
    } else if (id_start == "BD"){
        for (Tablet& tablet : Tablet::tablet_vec){
            if (tablet.getID() == id){
                tablet.setOnDisplay(false);
                Tablet::updateVec(tablet);
                return;
            }
        }
    } else if (id_start == "BE"){
        for (Laptop& laptop : Laptop::laptop_vec){
            if (laptop.getID() == id){
                laptop.setOnDisplay(false);
                Laptop::updateVec(laptop);
                return;
            }
        }
    } else if (id_start == "BG"){
        for (Desktop& desktop : Desktop::desktop_vec){
            if (desktop.getID() == id){
                desktop.setOnDisplay(false);
                Desktop::updateVec(desktop);
                return;
            }
        }
    } else if (id_start == "BH"){
        for (Handheld& handheld : Handheld::handheld_vec){
            if (handheld.getID() == id){
                handheld.setOnDisplay(false);
                Handheld::updateVec(handheld);
                return;
            }
        }
    }
    std::cout << "Invalid ID\n";
}