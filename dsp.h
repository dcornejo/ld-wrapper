//
// Created by dave on 2/12/2024.
//

#ifndef LD_WRAPPER_DSP_H
#define LD_WRAPPER_DSP_H

#include <liquid/liquid.h>

void printVector (std::vector<std::complex<float>> X);
void printVector (std::vector<uint32_t> X);

std::vector<liquid_float_complex> modulate_dpsk (const std::vector<uint32_t> &input);
std::vector<uint32_t> demodulate_dpsk (const std::vector<liquid_float_complex> &input);

#endif //LD_WRAPPER_DSP_H
