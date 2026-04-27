#include <iostream>
#include <fstream>
#include <unistd.h>

float readCpuTemp() {
    std::ifstream file("/sys/class/thermal/thermal_zone0/temp");
    int temp;
    file >> temp;
    return temp / 1000.0f;
}

int main() {
    while (true) {
        float temp = readCpuTemp();
        std::cout << "CPU Temperature: " << temp << " °C" << std::endl;
        sleep(3);
    }
    return 0;
}