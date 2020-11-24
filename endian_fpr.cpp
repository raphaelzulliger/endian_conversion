#include <boost/pfr.hpp>
#include <boost/endian/conversion.hpp>

#include <iostream>

/** Prints a "value" in hex notation. Borrowed from 
 * https://stackoverflow.com/questions/10599068/how-do-i-print-bytes-as-hexadecimal */
template <typename T>
void printHex(const std::string& appendix, const T& value) {
    std::cout << std::hex << std::setfill('0');  // needs to be set only once
    auto *ptr = reinterpret_cast<const unsigned char *>(&value);
    for (int i = 0; i < sizeof(value); i++, ptr++) {
        if (i % sizeof(uint64_t) == 0) {
            std::cout << std::endl;
        }
        std::cout << std::setw(2) << static_cast<unsigned>(*ptr) << " ";
    }
    std::cout << " " << appendix;
}

/** A sample struct with some PODs */
struct EndianTest {
    uint32_t u1;
    uint16_t u2;
    uint8_t u3;
    uint64_t u4;
    double f1;
    float f2;
};

int main() {
    EndianTest test{1, 2, 3, 4, 5.5, 6.6};
    boost::pfr::flat_for_each_field(test, 
        [] (const auto& field) {
            printHex("(native)", field);
            auto copy = field;
            boost::endian::endian_reverse_inplace(copy);
            printHex("(converted)", copy);
        });
    return 0;
}