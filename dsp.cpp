
#include <liquid/liquid.h>
#include <vector>
//#include <complex>
#include <iostream>

#include <ccomplex>

/**
 * @brief Convert a std::complex<float> to a liquid_float_complex.
 *
 * @param input The input std::complex<float>.
 * @return The converted liquid_float_complex.
 */
liquid_float_complex to_liquid_float_complex (std::complex<float> input) {
    liquid_float_complex output;
    output.real = input.real ();
    output.imag = input.imag ();
    return output;
}

/**
 * @brief Prints a vector of complex numbers to the standard output.
 *
 * This function takes a vector of complex numbers as input and prints each element to the console.
 * The complex numbers are printed in the format 'real + imagi', where 'real' is the real part
 * of the complex number and 'imag' is the imaginary part.
 *
 * @param X The input vector of complex numbers.
 */
void printVector (std::vector<std::complex<float>> X) {
    for (size_t i = 0; i < X.size (); ++i) {
        std::cout << X[i];
        if (i != X.size () - 1) {
            std::cout << ",";
        }
    }
}

/**
 * @brief Prints the elements of a vector.
 *
 * This function takes a vector of unsigned 32-bit integers and prints each element separated by a comma.
 * The function uses a for loop to iterate through the vector, printing each element
 * to the standard output. A comma is printed after each element except for the last one.
 *
 * @param X The vector of unsigned 32-bit integers to be printed.
 *
 * @return None.
 */
void printVector (std::vector<uint32_t> X) {
    for (size_t i = 0; i < X.size (); ++i) {
        std::cout << X[i];
        if (i != X.size () - 1) {
            std::cout << ",";
        }
    }
}

/**
 * @brief Modulates a vector of input values using DPSK modulation scheme.
 *
 * This function takes a vector of unsigned 32-bit integers as input and uses
 * differential phase shift keying (DPSK) modulation to modulate each value
 * in the input vector. The modulated symbols are stored in a vector of
 * complex floating-point numbers and returned.
 *
 * @param input The vector of input values to be modulated.
 *
 * @return A vector of complex floating-point numbers representing the
 *         modulated symbols.
 */
std::vector<liquid_float_complex> modulate_dpsk (const std::vector<uint32_t> &input) {
    const modulation_scheme ms = LIQUID_MODEM_DPSK2;
    modemcf modem = modemcf_create (ms);

    std::vector<liquid_float_complex> result;
    result.reserve (input.size ());

    for (const auto &value: input) {
        liquid_float_complex tmp;
        modemcf_modulate (modem, value, &tmp);
        result.push_back (tmp);
    }

    modemcf_destroy (modem);
    return result;
}

std::vector<uint32_t> demodulate_dpsk (const std::vector<std::complex<float>> &input) {
    const modulation_scheme ms = LIQUID_MODEM_DPSK2;
    modemcf modem = modemcf_create (ms);

    std::vector<uint32_t> result;
    result.reserve (input.size ());

    for (const auto &value: input) {
        uint32_t tmp;
        liquid_float_complex valueC = to_liquid_float_complex (value);

        modemcf_demodulate (modem, valueC, &tmp);
        result.push_back (tmp);
    }

    modemcf_destroy (modem);
    return result;
}

// up-sample

// down-sample
