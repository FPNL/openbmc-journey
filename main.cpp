#include <iostream>
#include <unistd.h>

int main() {
    while (true) {
        std::cout << "Hello from my first service!" << std::endl;
        sleep(3);
    }
    return 0;
}
