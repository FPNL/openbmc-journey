#include <iostream>
#include <fstream>
#include <unistd.h>

const float WARN_THRESHOLD = 50.0f;

float readCpuTemp() {
    std::ifstream file("/sys/class/thermal/thermal_zone0/temp");
    int temp;
    file >> temp;
    return temp / 1000.0f;
}

int main() {
    while (true) {
        float temp = readCpuTemp();

        if (temp >= WARN_THRESHOLD) {
            std::cerr << "WARNING: CPU Temperature critical: "
                      << temp << " °C" << std::endl;
        } else {
            std::cout << "CPU Temperature: " << temp << " °C" << std::endl;
        }

        sleep(3);
    }
    return 0;
}