#include <iostream>
#include <string_view>

int main(int argc, char** argv) {
    if (argc > 1 && std::string_view{argv[1]} == "--version") {
        std::cout << "tofu 0.0.1" << std::endl;
        return 0;
    }
    std::cout << "Tofu compiler (work in progress)" << std::endl;
    return 0;
}
