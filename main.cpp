#include <iostream>
#include <vector>
#include <ccomplex>
#include <random>

#include "dsp.h"

int main () {

    // create random bits in unpacked array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 1);

    std::vector<uint32_t> inputBits(64);
    for (auto& item : inputBits) {
        item = dis(gen);
    }

    printVector (inputBits);
    std::cout << std::endl;

    auto modulatedBits = modulate_dpsk(inputBits);
    printVector (modulatedBits);
    std::cout << std::endl;

    auto outputBits = demodulate_dpsk (modulatedBits);
    printVector (outputBits);
    std::cout << std::endl;

    std::cout << std::boolalpha;
    std::cout << (inputBits == outputBits);
    std::cout << std::endl;

    return 0;
}
