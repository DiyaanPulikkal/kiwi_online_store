#include "customer.h"

void Customer::viewSpecs(const std::string id){
    const std::string id_start = id.substr(0, 2);
    if (id_start == "AA"){
        for (const CPU& cpu : CPU::cpu_vec){
            if (cpu.getID() == id){
                std::cout << "ID: " << cpu.getID() << std::endl;
                std::cout << "Brand: " << cpu.getBrand() << std::endl;
                std::cout << "Model: " << cpu.getModel() << std::endl;
                std::cout << "Price ($): " << cpu.getPrice() << std::endl;
                std::cout << "In stock: " << cpu.getQuantity() << std::endl;
                std::cout << "Description: " << cpu.getDescription() << std::endl;
                std::cout << "Socket: " << cpu.getSocket() << std::endl;
                std::cout << "Form factor: " << cpu.getFormFactor() << std::endl;
                std::cout << "Cores: " << cpu.getCoreNo() << std::endl;
                std::cout << "Threads: " << cpu.getThreadNo() << std::endl;
                std::cout << "Base clock (GHz): " << cpu.getBaseClock() << std::endl;
                std::cout << "Boost clock (GHz): " << cpu.getBoostClock() << std::endl;
                std::cout << "Has overclocking: " << (cpu.getHasOverclock()? "Yes" : "No") << std::endl;
                std::cout << "Memory type supported: " << std::get<0>(cpu.getMemorySupport()) << std::endl;
                std::cout << "Max memory frequency supported (MHz): " << std::get<1>(cpu.getMemorySupport()) << std::endl;
                std::cout << "Max memory quantity supported (MHz): " << std::get<2>(cpu.getMemorySupport()) << std::endl;
                std::cout << "Integrated graphics: " << cpu.getIntegratedGraphics() << std::endl;
                return;
            }
        }
    } else if (id_start == "AB"){
        for (const GPU& gpu : GPU::gpu_vec){
            if (gpu.getID() == id){
                std::cout << "ID: " << gpu.getID() << std::endl;
                std::cout << "Brand: " << gpu.getBrand() << std::endl;
                std::cout << "Model: " << gpu.getModel() << std::endl;
                std::cout << "Price: " << gpu.getPrice() << std::endl;
                std::cout << "In stock: " << gpu.getQuantity() << std::endl;
                std::cout << "Description: " << gpu.getDescription() << std::endl;
                std::cout << "Base clock (Ghz): " << gpu.getBaseClock() << std::endl;
                std::cout << "Boost clock (Ghz): " << gpu.getBoostClock() << std::endl;
                std::cout << "Memory type: " << std::get<0>(gpu.getMemorySupport()) << std::endl;
                std::cout << "VRAM (GB): " << std::get<1>(gpu.getMemorySupport()) << std::endl;
                std::cout << "Bus width (Bit): " << std::get<2>(gpu.getMemorySupport()) << std::endl;
                std::cout << "Output ports: " << gpu.getOutputPorts()[0] << std::endl;
                for (int i = 1; i < gpu.getOutputPorts().size(); i++){
                    std::cout << "              " << gpu.getOutputPorts()[i] << std::endl;
                }
                std::cout << "Power consumption (W): " << std::get<0>(gpu.getPowerConsumption()) << std::endl;
                std::cout << "Power pins: " << std::get<1>(gpu.getPowerConsumption()) << std::endl;
                std::cout << "Cooling type: " << gpu.getCoolingType() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(gpu.getDimension()) << "x" << std::get<1>(gpu.getDimension()) << "x" << std::get<2>(gpu.getDimension()) << std::endl;
                std::cout << "Benchmark score (Kiwi exclusive): " << gpu.getBenchmarkScore() << std::endl;
                return;
            }
        }
    } else if (id_start == "AC"){
        for (const Memory& memory : Memory::memory_vec){
            if (memory.getID() == id){
                std::cout << "ID: " << memory.getID() << std::endl;
                std::cout << "Brand: " << memory.getBrand() << std::endl;
                std::cout << "Model: " << memory.getModel() << std::endl;
                std::cout << "Price: " << memory.getPrice() << std::endl;
                std::cout << "In stock: " << memory.getQuantity() << std::endl;
                std::cout << "Description: " << memory.getDescription() << std::endl;
                std::cout << "Memory type: " << memory.getType() << std::endl;
                std::cout << "Memory size (GB): " << memory.getCapacity() << std::endl;
                std::cout << "Memory frequency (MHz): " << memory.getFrequency() << std::endl;
                std::cout << "Memory latency (CL): " << memory.getLatency() << std::endl;
                std::cout << "Form Factor: " << memory.getFormFactor() << std::endl;
                std::cout << "Voltage (V): " << memory.getVoltage() << std::endl;
                std::cout << "ECC: " << (memory.getHasECC()? "Yes" : "No") << std::endl;
                std::cout << "Compatible with: " << memory.getCompatibleWith() << std::endl;
                return;
            }
        }
    } else if (id_start == "AD"){
        for (const CoolingUnit& cooling_u: CoolingUnit::cooling_unit_vec){
            if (cooling_u.getID() == id){
                std::cout << "ID: " << cooling_u.getID() << std::endl;
                std::cout << "Brand: " << cooling_u.getBrand() << std::endl;
                std::cout << "Model: " << cooling_u.getModel() << std::endl;
                std::cout << "Price: " << cooling_u.getPrice() << std::endl;
                std::cout << "In stock: " << cooling_u.getQuantity() << std::endl;
                std::cout << "Description: " << cooling_u.getDescription() << std::endl;
                std::cout << "Form factor: " << cooling_u.getFormFactor() << std::endl;
                std::cout << "Type: " << cooling_u.getType() << std::endl;
                std::cout << "Cooling capacity (W): " << cooling_u.getCoolCapacity() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(cooling_u.getDimension()) << "x" << std::get<1>(cooling_u.getDimension()) << "x" << std::get<2>(cooling_u.getDimension()) << std::endl;
                std::cout << "Noise level (dB): " << cooling_u.getNoiseLevel() << std::endl;
                std::cout << "Fan speed (rpm): " << cooling_u.getFanSpeed() << std::endl;
                std::cout << "RGB: " << (cooling_u.getIsRgb()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AE"){
        for (const PCCase& pc_case : PCCase::pc_case_vec){
            if (pc_case.getID() == id  ){
                std::cout << "ID: " << pc_case.getID() << std::endl;
                std::cout << "Brand: " << pc_case.getBrand() << std::endl;
                std::cout << "Model: " << pc_case.getModel() << std::endl;
                std::cout << "Price: " << pc_case.getPrice() << std::endl;
                std::cout << "In stock: " << pc_case.getQuantity() << std::endl;
                std::cout << "Description: " << pc_case.getDescription() << std::endl;
                std::cout << "Form factor: " << pc_case.getFormFactor() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(pc_case.getDimension()) << "x" << std::get<1>(pc_case.getDimension()) << "x" << std::get<2>(pc_case.getDimension()) << std::endl;
                std::cout << "Cooling Type: " << pc_case.getCoolingType() << std::endl;
                std::cout << "Max GPU length (mm): " << pc_case.getMaxGPULength() << std::endl;
                std::cout << "Max CPU cooler height (mm): " << pc_case.getMaxCPUHeight() << std::endl;
                std::cout << "Fan supports: " << std::endl;
                unsigned int count = 1;
                for (const std::tuple<std::string, int> fans : pc_case.getFanSupport()){
                    std::cout << std::setw(15) << "Fan size (" + std::to_string(count) + "): " << std::get<0>(fans) << std::endl;
                    std::cout << std::setw(15) << "Fan noise: " << std::get<1>(fans) << std::endl;
                    count++;
                }
                return;
            }
        }
    } else if (id_start == "AF"){
        for (const Motherboard& motherboard : Motherboard::motherboard_vec){
            if (motherboard.getID() == id){
                std::cout << "ID: " << motherboard.getID() << std::endl;
                std::cout << "Brand: " << motherboard.getBrand() << std::endl;
                std::cout << "Model: " << motherboard.getModel() << std::endl;
                std::cout << "Price: " << motherboard.getPrice() << std::endl;
                std::cout << "In stock: " << motherboard.getQuantity() << std::endl;
                std::cout << "Description: " << motherboard.getDescription() << std::endl;
                std::cout << "Form factor: " << motherboard.getSocket() << std::endl;
                std::cout << "Socket: " << motherboard.getSocket() << std::endl;
                std::cout << "Memory type: " << std::get<0>(motherboard.getMemory()) << std::endl;
                std::cout << "Memory size (GB): " << std::get<1>(motherboard.getMemory()) << std::endl;
                std::cout << "Chipset: " << motherboard.getChipset() << std::endl;
                std::cout << "PCIe slots: " << motherboard.getExpansionSlots()[0] << std::endl;
                for (int i = 1; i < motherboard.getExpansionSlots().size(); i++){
                    std::cout << "             " << motherboard.getExpansionSlots()[i] << std::endl;
                }
                std::cout << "Connectivity: " << motherboard.getConnectivity()[0] << std::endl;
                for (int i = 1; i < motherboard.getConnectivity().size(); i++){
                    std::cout << "             " << motherboard.getConnectivity()[i] << std::endl;
                }
                std::cout << "Storage slots: " << motherboard.getStorage()[0] << std::endl;
                for (int i = 1; i < motherboard.getStorage().size(); i++){
                    std::cout << "             " << motherboard.getStorage()[i] << std::endl;
                }
                std::cout << "Audio: " << motherboard.getAudio() << std::endl;
                std::cout << "Multi-GPU supported: " << motherboard.getMultiGPU() << std::endl;
                std::cout << "BIOS: " << motherboard.getBios() << std::endl;
                return;
            }
        }
    } else if (id_start == "AG"){
        for (const PSU& psu : PSU::psu_vec){
            if (psu.getID() == id){
                std::cout << "ID: " << psu.getID() << std::endl;
                std::cout << "Brand: " << psu.getBrand() << std::endl;
                std::cout << "Model: " << psu.getModel() << std::endl;
                std::cout << "Price: " << psu.getPrice() << std::endl;
                std::cout << "In stock: " << psu.getQuantity() << std::endl;
                std::cout << "Description: " << psu.getDescription() << std::endl;
                std::cout << "Form factor: " << psu.getFormFactor() << std::endl;
                std::cout << "Efficiency (%): " << psu.getEfficiency() << std::endl;
                std::cout << "Modularity: " << psu.getModular() << std::endl;
                std::cout << "Wattage (W): " << psu.getWattage() << std::endl;
                std::cout << "Fan size: " << std::get<0>(psu.getFan()) << std::endl;
                std::cout << "Noise level (dB): " << std::get<1>(psu.getFan()) << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(psu.getDimension()) << "x" << std::get<1>(psu.getDimension()) << "x" << std::get<2>(psu.getDimension()) << std::endl;
                return;
            }
        }
    } else if (id_start == "AH"){
        for (const SSD& ssd : SSD::ssd_vec){
            if (ssd.getID() == id){
                std::cout << "ID: " << ssd.getID() << std::endl;
                std::cout << "Brand: " << ssd.getBrand() << std::endl;
                std::cout << "Model: " << ssd.getModel() << std::endl;
                std::cout << "Price: " << ssd.getPrice() << std::endl;
                std::cout << "In stock: " << ssd.getQuantity() << std::endl;
                std::cout << "Description: " << ssd.getDescription() << std::endl;
                std::cout << "Form factor: " << ssd.getFormFactor() << std::endl;
                std::cout << "Capacity (GB): " << ssd.getStorageCapacity() << std::endl;
                std::cout << "Interface: " << ssd.getInterface() << std::endl;
                std::cout << "Average Speed (MB/s): " << ssd.getStorageSpeed() << std::endl;
                std::cout << "Power Consumption (W): " << ssd.getPowerConsumption() << std::endl;
                return;
            }
        }
    } else if (id_start == "AI"){
        for (const HDD& hdd : HDD::hdd_vec){
            if (hdd.getID() == id){
                std::cout << "ID: " << hdd.getID() << std::endl;
                std::cout << "Brand: " << hdd.getBrand() << std::endl;
                std::cout << "Model: " << hdd.getModel() << std::endl;
                std::cout << "Price: " << hdd.getPrice() << std::endl;
                std::cout << "In stock: " << hdd.getQuantity() << std::endl;
                std::cout << "Description: " << hdd.getDescription() << std::endl;
                std::cout << "Form factor: " << hdd.getFormFactor() << std::endl;
                std::cout << "Capacity (GB): " << hdd.getStorageCapacity() << std::endl;
                std::cout << "Interface: " << hdd.getInterface() << std::endl;
                std::cout << "Average Speed (MB/s): " << hdd.getStorageSpeed() << std::endl;
                std::cout << "Rotation speed (rpm): " << hdd.getRotationSpeed() << std::endl;
                std::cout << "Power consumption [IDLE] (W): " << std::get<0>(hdd.getPowerConsumption()) << std::endl;
                std::cout << "Power consumption [READ] (W): " << std::get<1>(hdd.getPowerConsumption()) << std::endl;
                std::cout << "Power consumption [WRITE] (W): " << std::get<2>(hdd.getPowerConsumption()) << std::endl;
                return;
            }
        }
    } else if (id_start == "AJ"){
        for (const Wire& wire : Wire::wire_vec){
            if (wire.getID() == id){
                std::cout << "ID: " << wire.getID() << std::endl;
                std::cout << "Brand: " << wire.getBrand() << std::endl;
                std::cout << "Model: " << wire.getModel() << std::endl;
                std::cout << "Price: " << wire.getPrice() << std::endl;
                std::cout << "In stock: " << wire.getQuantity() << std::endl;
                std::cout << "Description: " << wire.getDescription() << std::endl;
                std::cout << "Type: " << wire.getType() << std::endl;
                std::cout << "Length (m): " << wire.getLength() << std::endl;
                return;
            }
        }
    } else if (id_start == "AK"){
        for (const Mouse& mouse : Mouse::mouse_vec){
            if (mouse.getID() == id){
                std::cout << "ID: " << mouse.getID() << std::endl;
                std::cout << "Brand: " << mouse.getBrand() << std::endl;
                std::cout << "Model: " << mouse.getModel() << std::endl;
                std::cout << "Price: " << mouse.getPrice() << std::endl;
                std::cout << "In stock: " << mouse.getQuantity() << std::endl;
                std::cout << "Description: " << mouse.getDescription() << std::endl;
                std::cout << "Type: " << mouse.getType() << std::endl;
                std::cout << "Sensor: " << mouse.getSensor() << std::endl;
                std::cout << "Wireless: " << (mouse.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "Sensitivity (DPI): " << std::get<0>(mouse.getSensitivity()) << " - " << std::get<1>(mouse.getSensitivity()) << std::endl;
                std::cout << "Weight (g): " << mouse.getWeight() << std::endl;
                std::cout << "Battery life (hours): " << mouse.getBatteryLife() << std::endl;
                std::cout << "Rechargeable: " << (mouse.getRechargeable()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AL"){
        for (const Keyboard& keyboard : Keyboard::keyboard_vec){
            if (keyboard.getID() == id){
                std::cout << "ID: " << keyboard.getID() << std::endl;
                std::cout << "Brand: " << keyboard.getBrand() << std::endl;
                std::cout << "Model: " << keyboard.getModel() << std::endl;
                std::cout << "Price: " << keyboard.getPrice() << std::endl;
                std::cout << "In stock: " << keyboard.getQuantity() << std::endl;
                std::cout << "Description: " << keyboard.getDescription() << std::endl;
                std::cout << "Type: " << keyboard.getType() << std::endl;
                std::cout << "Layout: " << keyboard.getLayout() << std::endl;
                std::cout << "Backlit: " << (keyboard.getBacklit()? "Yes" : "No") << std::endl;
                std::cout << "Wireless: " << (keyboard.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "Key switch: " << keyboard.getKeySwitch() << std::endl;
                return;
            }
        }
    } else if (id_start == "AM"){
        for (const Touchpad& touchpad : Touchpad::touchpad_vec){
            if (touchpad.getID() == id){
                std::cout << "ID: " << touchpad.getID() << std::endl;
                std::cout << "Brand: " << touchpad.getBrand() << std::endl;
                std::cout << "Model: " << touchpad.getModel() << std::endl;
                std::cout << "Price: " << touchpad.getPrice() << std::endl;
                std::cout << "In stock: " << touchpad.getQuantity() << std::endl;
                std::cout << "Description: " << touchpad.getDescription() << std::endl;
                std::cout << "Type: " << touchpad.getType() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(touchpad.getDimensions()) << "x" << std::get<1>(touchpad.getDimensions()) << std::endl;
                return;
            }
        }
    } else if (id_start == "AN"){
        for (const Display& display: Display::display_vec){
            if (display.getID() == id){
                std::cout << "ID: " << display.getID() << std::endl;
                std::cout << "Brand: " << display.getBrand() << std::endl;
                std::cout << "Model: " << display.getModel() << std::endl;
                std::cout << "Price: " << display.getPrice() << std::endl;
                std::cout << "In stock: " << display.getQuantity() << std::endl;
                std::cout << "Description: " << display.getDescription() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(display.getResolution()) << "x" << std::get<1>(display.getResolution()) << std::endl;
                std::cout << "Refresh rate (Hz): " << display.getRefreshRate() << std::endl;
                std::cout << "Dimensions (inches): " << std::get<0>(display.getDimensions()) << "x" << std::get<1>(display.getDimensions()) << std::endl;
                std::cout << "HDR supported: " << (display.getHDR()? "Yes" : "No") << std::endl;
                std::cout << "Response time (ms): " << display.getResponseTime() << std::endl;
                return;
            }
        }
    } else if (id_start == "AO"){
        for (const Earbuds& earbuds : Earbuds::earbuds_vec){
            if (earbuds.getID() == id){
                std::cout << "ID: " << earbuds.getID() << std::endl;
                std::cout << "Brand: " << earbuds.getBrand() << std::endl;
                std::cout << "Model: " << earbuds.getModel() << std::endl;
                std::cout << "Price: " << earbuds.getPrice() << std::endl;
                std::cout << "In stock: " << earbuds.getQuantity() << std::endl;
                std::cout << "Description: " << earbuds.getDescription() << std::endl;
                std::cout << "Battery life (hours): " << earbuds.getBatteryLife() << std::endl;
                std::cout << "ANC: " << (earbuds.getANC()? "Yes" : "No") << std::endl;
                std::cout << "Water resistant: " << (earbuds.getWaterResistant()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AP"){
        for (const Earphones& earphones : Earphones::earphones_vec){
            if (earphones.getID() == id){
                std::cout << "ID: " << earphones.getID() << std::endl;
                std::cout << "Brand: " << earphones.getBrand() << std::endl;
                std::cout << "Model: " << earphones.getModel() << std::endl;
                std::cout << "Price: " << earphones.getPrice() << std::endl;
                std::cout << "In stock: " << earphones.getQuantity() << std::endl;
                std::cout << "Description: " << earphones.getDescription() << std::endl;
                std::cout << "Volume control: " << (earphones.getVolumeControl()? "Yes" : "No") << std::endl;
                std::cout << "Water resistant: " << (earphones.getWaterResistant()? "Yes" : "No") << std::endl;
                std::cout << "Wire length (m): " << earphones.getWireLength() << std::endl;
                return;
            }
        }
    } else if (id_start == "AQ"){
        for (const Headset& headset : Headset::headset_vec){
            if (headset.getID() == id){
                std::cout << "ID: " << headset.getID() << std::endl;
                std::cout << "Brand: " << headset.getBrand() << std::endl;
                std::cout << "Model: " << headset.getModel() << std::endl;
                std::cout << "Price: " << headset.getPrice() << std::endl;
                std::cout << "In stock: " << headset.getQuantity() << std::endl;
                std::cout << "Description: " << headset.getDescription() << std::endl;
                std::cout << "Wireless: " << (headset.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "ANC: " << (headset.getANC()? "Yes" : "No") << std::endl;
                std::cout << "RGB: " << (headset.getRGB()? "Yes" : "No") << std::endl;
                std::cout << "Surround sound: " << (headset.getSurroundSound()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AR"){
        for (const Headphones& headphones : Headphones::headphones_vec){
            if (headphones.getID() == id){
                std::cout << "ID: " << headphones.getID() << std::endl;
                std::cout << "Brand: " << headphones.getBrand() << std::endl;
                std::cout << "Model: " << headphones.getModel() << std::endl;
                std::cout << "Price: " << headphones.getPrice() << std::endl;
                std::cout << "In stock: " << headphones.getQuantity() << std::endl;
                std::cout << "Description: " << headphones.getDescription() << std::endl;
                std::cout << "ANC: " << (headphones.getANC()? "Yes" : "No") << std::endl;
                std::cout << "Wireless: " << (headphones.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "Surround sound: " << (headphones.getSurroundSound()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AS"){
        for (const Speakers& speaker: Speakers::speakers_vec){
            if (speaker.getID() == id){
                std::cout << "ID: " << speaker.getID() << std::endl;
                std::cout << "Brand: " << speaker.getBrand() << std::endl;
                std::cout << "Model: " << speaker.getModel() << std::endl;
                std::cout << "Price: " << speaker.getPrice() << std::endl;
                std::cout << "In stock: " << speaker.getQuantity() << std::endl;
                std::cout << "Description: " << speaker.getDescription() << std::endl;
                std::cout << "Wireless: " << (speaker.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "Power output (W): " << speaker.getPowerOutput() << std::endl;
                std::cout << "Configuration: " << speaker.getConfiguration() << std::endl;
                std::cout << "Battery life (hours): " << speaker.getBatteryLife() << std::endl;
                return;
            }
        }
    } else if (id_start == "AT"){
        for (const Microphone& mic: Microphone::microphone_vec){
            if (mic.getID() == id){
                std::cout << "ID: " << mic.getID() << std::endl;
                std::cout << "Brand: " << mic.getBrand() << std::endl;
                std::cout << "Model: " << mic.getModel() << std::endl;
                std::cout << "Price: " << mic.getPrice() << std::endl;
                std::cout << "In stock: " << mic.getQuantity() << std::endl;
                std::cout << "Description: " << mic.getDescription() << std::endl;
                std::cout << "Directionality: " << mic.getDirectionality() << std::endl;
                std::cout << "USB: " << (mic.getUSB()? "Yes" : "No") << std::endl;
                std::cout << "XLR: " << (mic.getXLR()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "AU"){
        for (const Printer& printer: Printer::printer_vec){
            if (printer.getID() == id){
                std::cout << "ID: " << printer.getID() << std::endl;
                std::cout << "Brand: " << printer.getBrand() << std::endl;
                std::cout << "Model: " << printer.getModel() << std::endl;
                std::cout << "Price: " << printer.getPrice() << std::endl;
                std::cout << "In stock: " << printer.getQuantity() << std::endl;
                std::cout << "Description: " << printer.getDescription() << std::endl;
                std::cout << "Type: " << printer.getType() << std::endl;
                std::cout << "Scanner included: " << (printer.getHasScanner()? "Yes" : "No") << std::endl;
                std::cout << "Wireless: " << (printer.getWireless()? "Yes" : "No") << std::endl;
                std::cout << "Speed (ppm): " << printer.getSpeed() << std::endl;
                std::cout << "Max resolution (dpi): " << printer.getMaxRes() << std::endl;
                std::cout << "Duplex: " << (printer.getDuplex()? "Yes" : "No") << std::endl;
                std::cout << "Ink or Toner: " << std::get<0>(printer.getInkOrToner()) << " - " << std::get<1>(printer.getInkOrToner()) << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(printer.getDimensions()) << "x" << std::get<1>(printer.getDimensions()) << "x" << std::get<2>(printer.getDimensions()) << std::endl;
                std::cout << "Weight (kg): " << printer.getWeight() << std::endl;
                return;
            }
        }
    } else if (id_start == "AV"){
        for (const Webcam& webcam: Webcam::webcam_vec){
            if (webcam.getID() == id ){
                std::cout << "ID: " << webcam.getID() << std::endl;
                std::cout << "Brand: " << webcam.getBrand() << std::endl;
                std::cout << "Model: " << webcam.getModel() << std::endl;
                std::cout << "Price: " << webcam.getPrice() << std::endl;
                std::cout << "In stock: " << webcam.getQuantity() << std::endl;
                std::cout << "Description: " << webcam.getDescription() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(webcam.getResolution()) << "x" << std::get<1>(webcam.getResolution()) << std::endl;
                std::cout << "FPS: " << webcam.getFps() << std::endl;
                std::cout << "Field of view (degrees): " << webcam.getFieldOfView() << std::endl;
                std::cout << "Has microphone: " << (webcam.getHasMicrophone()? "Yes" : "No") << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(webcam.getDimensions()) << "x" << std::get<1>(webcam.getDimensions()) << "x" << std::get<2>(webcam.getDimensions()) << std::endl;                
                return;
            }
        }
    } else if (id_start == "AW"){
        for (const UsbDrive& usb: UsbDrive::usb_drive_vec){
            if (usb.getID() == id){
                std::cout << "ID: " << usb.getID() << std::endl;
                std::cout << "Brand: " << usb.getBrand() << std::endl;
                std::cout << "Model: " << usb.getModel() << std::endl;
                std::cout << "Price: " << usb.getPrice() << std::endl;
                std::cout << "In stock: " << usb.getQuantity() << std::endl;
                std::cout << "Description: " << usb.getDescription() << std::endl;
                std::cout << "Capacity (GB): " << usb.getCapacity() << std::endl;
                std::cout << "Interface: " << usb.getInterface() << std::endl;
                std::cout << "Transfer speed (MB/s): " << usb.getTransferSpeed() << std::endl;
                return;
            }
        }
    } else if (id_start == "AX"){
        for (const Portable_HDD& p_hdd: Portable_HDD::portable_hdd_vec){
            if (p_hdd.getID() == id ){
                std::cout << "ID: " << p_hdd.getID() << std::endl;
                std::cout << "Brand: " << p_hdd.getBrand() << std::endl;
                std::cout << "Model: " << p_hdd.getModel() << std::endl;
                std::cout << "Price: " << p_hdd.getPrice() << std::endl;
                std::cout << "In stock: " << p_hdd.getQuantity() << std::endl;
                std::cout << "Description: " << p_hdd.getDescription() << std::endl;
                std::cout << "Capacity (GB): " << p_hdd.getCapacity() << std::endl;
                std::cout << "Interface: " << p_hdd.getInterface() << std::endl;
                std::cout << "Transfer speed (MB/s): " << p_hdd.getTransferSpeed() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(p_hdd.getDimensions()) << "x" << std::get<1>(p_hdd.getDimensions()) << std::endl;
                std::cout << "Weight (g): " << p_hdd.getWeight() << std::endl;
                return;
            }
        }
    } else if (id_start == "AY"){
        for (const SdCard& sd: SdCard::sd_card_vec){
            if (sd.getID() == id){
                std::cout << "ID: " << sd.getID() << std::endl;
                std::cout << "Brand: " << sd.getBrand() << std::endl;
                std::cout << "Model: " << sd.getModel() << std::endl;
                std::cout << "Price: " << sd.getPrice() << std::endl;
                std::cout << "In stock: " << sd.getQuantity() << std::endl;
                std::cout << "Description: " << sd.getDescription() << std::endl;
                std::cout << "Capacity (GB): " << sd.getCapacity() << std::endl;
                std::cout << "Type: " << sd.getType() << std::endl;
                std::cout << "Transfer speed (MB/s): " << sd.getSpeed() << std::endl;
                std::cout << "Class Rating: " << sd.getClassRating() << std::endl;
                std::cout << "Form factor: " << sd.getFormFactor() << std::endl;
                return;
            }
        }
    } else if (id_start == "AZ"){
        for (const VR& vr: VR::vr_vec){
            if (vr.getID() == id){
                std::cout << "ID: " << vr.getID() << std::endl;
                std::cout << "Brand: " << vr.getBrand() << std::endl;
                std::cout << "Model: " << vr.getModel() << std::endl;
                std::cout << "Price: " << vr.getPrice() << std::endl;
                std::cout << "In stock: " << vr.getQuantity() << std::endl;
                std::cout << "Description: " << vr.getDescription() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(vr.getResolution()) << "x" << std::get<1>(vr.getResolution()) << std::endl;
                std::cout << "With controllers: " << (vr.getWithControllers()? "Yes" : "No") << std::endl;
                std::cout << "Display: " << vr.getDisplay() << std::endl;
                std::cout << "USB cable type: " << vr.getHaveUsbCable() << std::endl;
                std::cout << "Max refresh rate (Hz): " << vr.getRefreshRate() << std::endl;
                std::cout << "Field of view (degrees): " << vr.getFieldOfView() << std::endl;
                std::cout << "Display size (inches): " << vr.getSizeDisplayInch() << std::endl;               
                return;
            }
        }
    } else if (id_start == "BA"){
        for (const Smartphones& sphone: Smartphones::smartphones_vec){
            if (sphone.getID() == id ){
                std::cout << "ID: " << sphone.getID() << std::endl;
                std::cout << "Brand: " << sphone.getBrand() << std::endl;
                std::cout << "Model: " << sphone.getModel() << std::endl;
                std::cout << "Price: " << sphone.getPrice() << std::endl;
                std::cout << "In stock: " << sphone.getQuantity() << std::endl;
                std::cout << "Description: " << sphone.getDescription() << std::endl;
                std::cout << "Display: " << sphone.getDisplay() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(sphone.getResolution()) << "x" << std::get<1>(sphone.getResolution()) << std::endl;
                std::cout << "Processor: " << sphone.getProcessor() << std::endl;
                std::cout << "OS: " << sphone.getOS() << std::endl;
                std::cout << "Charger: " << sphone.getCharger() << std::endl;
                std::cout << "Camera specs: " << sphone.getCameraSpec() << std::endl;
                std::cout << "Sim slots: " << sphone.getNumSim() << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(sphone.getDimensions()) << "x" << std::get<1>(sphone.getDimensions()) << "x" << std::get<2>(sphone.getDimensions()) << std::endl;
                std::cout << "Storage (GB): " << sphone.getStorage() << std::endl;
                std::cout << "Refresh rate (Hz): " << sphone.getRefreshRate() << std::endl;
                std::cout << "Wifi: " << sphone.getWifi() << std::endl;
                std::cout << "Brightness (nits): " << sphone.getBrightness() << std::endl;
                std::cout << "Bluetooth: " << sphone.getBluetooth() << std::endl;
                std::cout << "Weight (g): " << sphone.getWeight() << std::endl;
                std::cout << "Battery (mAh): " << sphone.getBattery() << std::endl;
                std::cout << "Fingerprint: " << (sphone.getBiometrics()[0]? "Yes" : "No") << std::endl;
                std::cout << "Face recognition: " << (sphone.getBiometrics()[1]? "Yes" : "No") << std::endl;
                std::cout << "Iris scanner: " << (sphone.getBiometrics()[2]? "Yes" : "No") << std::endl;
                std::cout << "MicroSD slot: " << (sphone.getMicroSD()? "Yes" : "No") << std::endl;
                std::cout << "Jack: " << (sphone.getJack()? "Yes" : "No") << std::endl;
                std::cout << "Pen: " << (sphone.getHasPen()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "BB"){
        for (const Smartwatch& swatch: Smartwatch::smartwatch_vec){
            if (swatch.getID() == id ){
                std::cout << "ID: " << swatch.getID() << std::endl;
                std::cout << "Brand: " << swatch.getBrand() << std::endl;
                std::cout << "Model: " << swatch.getModel() << std::endl;
                std::cout << "Price: " << swatch.getPrice() << std::endl;
                std::cout << "In stock: " << swatch.getQuantity() << std::endl;
                std::cout << "Description: " << swatch.getDescription() << std::endl;
                std::cout << "Cellular: " << (swatch.getSim()? "Yes" : "No") << std::endl;
                std::cout << "Bluetooth: " << swatch.getBluetooth() << std::endl;
                std::cout << "Wifi: " << swatch.getWifi() << std::endl;
                std::cout << "Capacity (GB): " << swatch.getCapacity() << std::endl;
                std::cout << "Screen size (mm): " << swatch.getScreenSize() << std::endl;
                std::cout << "Case size (mm): " << swatch.getCaseSize() << std::endl;
                std::cout << "Brightness (nits): " << swatch.getBrightness() << std::endl;
                std::cout << "Water resistant: " << swatch.getWaterResistance() << std::endl;
                std::cout << "Battery life (hours): " << swatch.getBattery() << std::endl;
                std::cout << "Weight (g): " << swatch.getWeight() << std::endl;
                std::cout << "Heart rate monitor: " << (swatch.getHeartrateMonitoring()? "Yes" : "No") << std::endl;
                std::cout << "Internal microphone: " << (swatch.getHasMicrophones()? "Yes" : "No") << std::endl;
                std::cout << "GPS: " << (swatch.getHasGps()? "Yes" : "No") << std::endl;
                std::cout << "Blood oxygen sensor: " << (swatch.getHasBloodOxygenSensor()? "Yes" : "No") << std::endl;
                std::cout << "Internal speaker: " << (swatch.getHasSpeaker()? "Yes" : "No") << std::endl;
            }
        }
    } else if (id_start == "BC"){
        for (const Stationed& stationed: Stationed::stationed_vec){
            if (stationed.getID() == id){
                std::cout << "ID: " << stationed.getID() << std::endl;
                std::cout << "Brand: " << stationed.getBrand() << std::endl;
                std::cout << "Model: " << stationed.getModel() << std::endl;
                std::cout << "Price: " << stationed.getPrice() << std::endl;
                std::cout << "In stock: " << stationed.getQuantity() << std::endl;
                std::cout << "Description: " << stationed.getDescription() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(stationed.getResolution()) << "x" << std::get<1>(stationed.getResolution()) << std::endl;
                std::cout << "Main processor: " << stationed.getMainProcessor() << std::endl;
                std::cout << "Graphics processor: " << stationed.getGraphicsProcessor() << std::endl;
                std::cout << "Storage Capacity: " << stationed.getStorageCapacity() << std::endl;
                std::cout << "USB: " << stationed.getUSB() << std::endl;
                std::cout << "Display: " << stationed.getDisplay() << std::endl;
                std::cout << "I/O ports: " << stationed.getInputOutputPort() << std::endl;
                std::cout << "Wifi: " << stationed.getWifi() << std::endl;
                std::cout << "Weight (g): " << stationed.getWeight() << std::endl;
                std::cout << "Bluetooth: " << stationed.getBluetooth() << std::endl;
                std::cout << "Power consumption (W): " << stationed.getPowerConsumption() << std::endl;
                std::cout << "Controller vibration available: " << (stationed.getControllerVibration()? "Yes" : "No") << std::endl;
                std::cout << "TV mode available: " << (stationed.getTVMode()? "Yes" : "No") << std::endl;
                std::cout << "SSD: " << stationed.getSSD() << std::endl;
                std::cout << "Size: " << stationed.getSize() << std::endl;
                return;
            }
        }
    } else if (id_start == "BD"){
        for (const Tablet& tablet: Tablet::tablet_vec){
            if (tablet.getID() == id ){
                std::cout << "ID: " << tablet.getID() << std::endl;
                std::cout << "Brand: " << tablet.getBrand() << std::endl;
                std::cout << "Model: " << tablet.getModel() << std::endl;
                std::cout << "Price: " << tablet.getPrice() << std::endl;
                std::cout << "In stock: " << tablet.getQuantity() << std::endl;
                std::cout << "Description: " << tablet.getDescription() << std::endl;
                std::cout << "Display: " << tablet.getDisplay() << std::endl;
                std::cout << "Processor: " << tablet.getProcessor() << std::endl;
                std::cout << "OS: " << tablet.getOs() << std::endl;
                std::cout << "Storage: " << tablet.getStorage() << std::endl;
                std::cout << "Camera specs: " << tablet.getCamera() << std::endl;
                std::cout << "Battery capacity (mAh): " << tablet.getBattery() << std::endl;
                std::cout << "Bluetooth: " << tablet.getBluetooth() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(tablet.getResolution()) << "x" << std::get<1>(tablet.getResolution()) << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(tablet.getDimensions()) << "x" << std::get<1>(tablet.getDimensions()) << "x" << std::get<2>(tablet.getDimensions()) << std::endl;
                std::cout << "Weight (g): " << tablet.getWeight() << std::endl;
                std::cout << "Brightness (nits): " << tablet.getBrightness() << std::endl;
                std::cout << "Wifi: " << tablet.getWifi() << std::endl;
                std::cout << "Pen: " << (tablet.getHavePen()? "Yes" : "No") << std::endl;
                std::cout << "Internal Memory: " << tablet.getInternal_Memory() << std::endl;
                std::cout << "External Memory: " << tablet.getExternal_Memory() << std::endl;
                std::cout << "Speaker: " << tablet.getSpeaker() << std::endl;
                std::cout << "Fingerprint scanner: " << (tablet.getBiometrics()[0]? "Yes" : "No") << std::endl;
                std::cout << "Face recognition: " << (tablet.getBiometrics()[1]? "Yes" : "No") << std::endl;
                std::cout << "Iris scanner: " << (tablet.getBiometrics()[2]? "Yes" : "No") << std::endl;
                std::cout << "Waterproof: " << (tablet.getIsWaterproof()? "Yes" : "No") << std::endl;
                return;
            }
        }
    } else if (id_start == "BE"){
        for (const Laptop& laptop: Laptop::laptop_vec){
            if (laptop.getID() == id ){
                std::cout << "ID: " << laptop.getID() << std::endl;
                std::cout << "Brand: " << laptop.getBrand() << std::endl;
                std::cout << "Model: " << laptop.getModel() << std::endl;
                std::cout << "Price: " << laptop.getPrice() << std::endl;
                std::cout << "In stock: " << laptop.getQuantity() << std::endl;
                std::cout << "CPU: " << laptop.getCPU() << std::endl;
                std::cout << "GPU: " << laptop.getGPU() << std::endl;
                std::cout << "Memory: " << laptop.getMemory() << std::endl;
                std::cout << "Storage: " << laptop.getStorage()[0] << std::endl;
                for (int i = 1; i < laptop.getStorage().size(); i++){
                    std::cout << "        " << laptop.getStorage()[i] << std::endl;
                }
                std::cout << "OS: " << laptop.getOS() << std::endl;
                std::cout << "Display: " << laptop.getDisplay() << std::endl;
                std::cout << "Battery capacity (Whr): " << std::get<0>(laptop.getBattery()) << std::endl;
                std::cout << "Number of cells: " << std::get<1>(laptop.getBattery()) << std::endl;
                std::cout << "Dimensions (mm): " << std::get<0>(laptop.getDimensions()) << "x" << std::get<1>(laptop.getDimensions()) << "x" << std::get<2>(laptop.getDimensions()) << std::endl;
                std::cout << "Standardized size (inches): " << std::get<3>(laptop.getDimensions()) << std::endl;
                std::cout << "Weight (kg): " << laptop.getWeight() << std::endl;
                std::cout << "Touchscreen available: " << (laptop.getTouchscreen()? "Yes" : "No") << std::endl;
                std::cout << "Gaming: " << (laptop.getGaming()? "Yes" : "No") << std::endl;
                return;
            }

        }
    } else if (id_start == "BG"){
        for (const Desktop& desktop: Desktop::desktop_vec){
            if (desktop.getID() == id  ){
                std::cout << "ID: " << desktop.getID() << std::endl;
                std::cout << "Brand: " << desktop.getBrand() << std::endl;
                std::cout << "Model: " << desktop.getModel() << std::endl;
                std::cout << "Price: " << desktop.getPrice() << std::endl;
                std::cout << "In stock: " << desktop.getQuantity() << std::endl;
                std::cout << "CPU: " << desktop.getCPU() << std::endl;
                std::cout << "GPU: " << desktop.getGPU() << std::endl;
                std::cout << "Memory: " << desktop.getMemory() << std::endl;
                std::cout << "Storage: " << desktop.getStorage()[0] << std::endl;
                for (int i = 1; i < desktop.getStorage().size(); i++){
                    std::cout << "        " << desktop.getStorage()[i] << std::endl;
                }
                std::cout << "OS: " << desktop.getOS() << std::endl;
                std::cout << "Power supply: " << desktop.getPSU() << std::endl;
                std::cout << "Motherboard: " << desktop.getMotherboard() << std::endl;
                std::cout << "Case: " << desktop.getPCCase() << std::endl;
                std::cout << "Cooling: " << desktop.getCooling() << std::endl;
                return;
            }
        }
    } else if (id_start == "BH"){
        for (const Handheld& handheld: Handheld::handheld_vec){
            if (handheld.getID() == id){
                std::cout << "ID: " << handheld.getID() << std::endl;
                std::cout << "Brand: " << handheld.getBrand() << std::endl;
                std::cout << "Model: " << handheld.getModel() << std::endl;
                std::cout << "Price: " << handheld.getPrice() << std::endl;
                std::cout << "In stock: " << handheld.getQuantity() << std::endl;
                std::cout << "Description: " << handheld.getDescription() << std::endl;
                std::cout << "Resolution (px): " << std::get<0>(handheld.getResolution()) << "x" << std::get<1>(handheld.getResolution()) << std::endl;
                std::cout << "Main processor: " << handheld.getMainProcessor() << std::endl;
                std::cout << "Graphics processor: " << handheld.getGraphicsProcessor() << std::endl;
                std::cout << "Storage Capacity: " << handheld.getStorageCapacity() << std::endl;
                std::cout << "USB: " << handheld.getUSB() << std::endl;
                std::cout << "Display: " << handheld.getDisplay() << std::endl;
                std::cout << "I/O ports: " << handheld.getInputOutputPort() << std::endl;
                std::cout << "Wifi: " << handheld.getWifi() << std::endl;
                std::cout << "Weight (g): " << handheld.getWeight() << std::endl;
                std::cout << "Bluetooth: " << handheld.getBluetooth() << std::endl;
                std::cout << "Power consumption (W): " << handheld.getPowerConsumption() << std::endl;
                std::cout << "Controller vibration available: " << (handheld.getControllerVibration()? "Yes" : "No") << std::endl;
                std::cout << "TV mode available: " << (handheld.getTVMode()? "Yes" : "No") << std::endl;
                std::cout << "Battery: " << handheld.getBattery() << std::endl;
                std::cout << "Power supply: " << handheld.getPowerSupply() << std::endl;
                std::cout << "Headphone jack: " << handheld.getHeadphoneJack() << std::endl;
                std::cout << "MicroSD slot: " << handheld.getMicroSDSlot() << std::endl;
                std::cout << "Size: " << handheld.getSize() << std::endl;
                return;
            }
        }
    }
    std::cout << "Item not found" << std::endl;
    return;
}

void Customer::addToCart(const std::string id, const unsigned int quantity){
    for (CPU& device : CPU::cpu_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (GPU& device : GPU::gpu_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Memory& device : Memory::memory_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (SSD& device : SSD::ssd_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (HDD& device : HDD::hdd_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Motherboard& device : Motherboard::motherboard_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (PSU& device : PSU::psu_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (PCCase& device : PCCase::pc_case_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (CoolingUnit& device : CoolingUnit::cooling_unit_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Headset& device : Headset::headset_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Earbuds& device : Earbuds::earbuds_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Earphones& device : Earphones::earphones_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Headphones& device : Headphones::headphones_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Speakers& device : Speakers::speakers_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Microphone& device : Microphone::microphone_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Display& device : Display::display_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Keyboard& device : Keyboard::keyboard_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Mouse& device : Mouse::mouse_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Portable_HDD& device : Portable_HDD::portable_hdd_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Printer& device : Printer::printer_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (SdCard& device : SdCard::sd_card_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Touchpad& device : Touchpad::touchpad_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (UsbDrive& device : UsbDrive::usb_drive_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Webcam& device : Webcam::webcam_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Wire& device : Wire::wire_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for(Handheld& device : Handheld::handheld_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Stationed& device : Stationed::stationed_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Laptop& device : Laptop::laptop_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Desktop& device : Desktop::desktop_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Smartphones& device : Smartphones::smartphones_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Smartwatch& device : Smartwatch::smartwatch_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (Tablet& device : Tablet::tablet_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    for (VR& device : VR::vr_vec){
        if (device.getID() == id && device.getQuantity() >= quantity && device.getOnDisplay()){
            cart.push_back(std::make_tuple(&device, quantity));
            updateCart();
            return;
        }
    }
    std::cout << "Item not found, not for sale or insufficient" << std::endl;
}

void Customer::removeFromCart(const unsigned int index, const unsigned int quantity){
    std::get<1>(cart[index]) -= quantity;
    if (std::get<1>(cart[index]) == 0){
        cart.erase(cart.begin() + index);
    }
    updateCart();
}

void Customer::viewCart(){
    if (cart.size() == 0){
        std::cout << "Cart is empty" << std::endl;
        return;
    }
    unsigned int i = 1;
    for (const auto& device : cart) {
        std::cout << i << ". " << std::endl;
        std::visit([](auto&& arg) {
            using DeviceType = std::decay_t<decltype(*arg)>;
            std::cout << "ID: " << arg->getID(); 
            std::cout << "Brand: " << arg->getBrand() << "     ";
            std::cout << "Model: " << arg->getModel() << "     ";
            std::cout << "Price: " << arg->getPrice() << "     ";
        }, std::get<0>(device));
        std::cout << "Quantity: " << std::get<1>(device) << std::endl;
        i++;
    }
    std::cout << "Total: " << calculateTotal() << std::endl;
}

double Customer::calculateTotal(){
    double total = 0;
    for (const auto& device : cart){
        total += std::visit([](auto&& arg) { return arg->getPrice(); }, std::get<0>(device)) * std::get<1>(device);
    }
    return total;
}

void Customer::checkout(){
    if (cart.size() == 0){
        std::cout << "Cart is empty" << std::endl;
        return;
    }
    std::cout << "Items in cart: " << std::endl;
    viewCart();
    std::cout << "Total: " << calculateTotal() << std::endl;
    std::cout << "Proceed to checkout? (Y/N)" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    if (input == "Y"){
        for (const auto& device : cart){
            std::visit([&device](auto&& arg) {
                arg->purchaseDevice(std::get<1>(device));            
            }, std::get<0>(device));
        }
        cart.clear();
        updateCart();
        std::cout << "Checkout successful" << std::endl;
    } else {
        std::cout << "Checkout cancelled" << std::endl;
    }
}

void Customer::updateCart(){
    std::ofstream cart_file("../customer/cart.txt");
    if (!cart_file.is_open() || cart_file.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    if (cart.size() == 0){
        cart_file.close();
        std::ofstream cart_file("../customer/cart.txt", std::ios::trunc);
        cart_file.close();
        return;
    }
    for (const auto& device : cart){
        std::visit([&cart_file, &device](auto&& arg) {
            cart_file << arg->getID() << "|" << std::get<1>(device) << std::endl;
        }, std::get<0>(device));
    }
    cart_file.close();
}

void Customer::loadCart(){
    std::ifstream cart_file("../customer/cart.txt");
    if (!cart_file.is_open() || cart_file.fail()){
        std::cerr << "File Error" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(cart_file, line)){
        std::string id = line.substr(0, line.find("|"));
        unsigned int quantity = std::stoi(line.substr(line.find("|") + 1));
        addToCart(id, quantity);
    }
    cart_file.close();
    updateCart();
}