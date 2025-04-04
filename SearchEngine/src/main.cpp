#include "Application/Application.h"
#include <iostream>
#include <Windows.h>

int main() {
    std::locale::global(std::locale("Russian"));
    std::setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try {
        Application app("Config.ini");
        app.run();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}