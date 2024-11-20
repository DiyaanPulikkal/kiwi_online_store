#include "console.h"

Console::Console(): Devices() {
    resolution = std::make_tuple(0, 0);
    main_processor = "-";
    graphics_processor = "-";
    storage_capacity = 0;
    USB = "-";
    display = "-";
    input_output_port = "-";
    wifi = "-";
    weight = 0.0;
    bluetooth = "-";
    controller_vibration = false;
    TV_mode = false;
}

Console::Console(const int q, const double p) : Devices(q, p) {
    resolution = std::make_tuple(0, 0);
    main_processor = "-";
    graphics_processor = "-";
    storage_capacity = 0;
    USB = "-";
    display = "-";
    input_output_port = "-";
    wifi = "-";
    weight = 0.0;
    bluetooth = "-";
    controller_vibration = false;
    TV_mode = false;
}

std::tuple<int, int> Console::getResolution() const {
    return resolution;
}

std::string Console::getMainProcessor() const {
    return main_processor;
}

std::string Console::getGraphicsProcessor() const {
    return graphics_processor;
}

int Console::getStorageCapacity() const {
    return storage_capacity;
}

std::string Console::getUSB() const {
    return USB;
}

std::string Console::getDisplay() const {
    return display;
}

std::string Console::getInputOutputPort() const {
    return input_output_port;
}

std::string Console::getWifi() const {
    return wifi;
}

double Console::getWeight() const {
    return weight;
}

std::string Console::getBluetooth() const {
    return bluetooth;
}

bool Console::getControllerVibration() const {
    return controller_vibration;
}

bool Console::getTVMode() const {
    return TV_mode;
}

double Console::getPowerConsumption() const {
    return power_consumption;
}

void Console::setResolution(const int w, const int h) {
    resolution = std::make_tuple(w, h);
}

void Console::setMainProcessor(const std::string m) {
    main_processor = m;
}

void Console::setGraphicsProcessor(const std::string g) {
    graphics_processor = g;
}

void Console::setStorageCapacity(const int s) {
    storage_capacity = s;
}

void Console::setUSB(const std::string u) {
    USB = u;
}

void Console::setDisplay(const std::string d) {
    display = d;
}

void Console::setInputOutputPort(const std::string i) {
    input_output_port = i;
}

void Console::setWifi(const std::string w) {
    wifi = w;
}

void Console::setWeight(const double w) {
    weight = w;
}

void Console::setBluetooth(const std::string b) {
    bluetooth = b;
}

void Console::setControllerVibration(const bool c) {
    controller_vibration = c;
}

void Console::setTVMode(const bool t) {
    TV_mode = t;
}


void Console::setPowerConsumption(const double p) {
    power_consumption = p;
}