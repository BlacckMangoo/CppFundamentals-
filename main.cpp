#include "PpmParser.h"
#include "huffmanEncoder.h"
#include <iostream>

int main(){
    std::string input = "lla hsd h fh";
    std::string ppmFile = "sample.ppm";  // File is in the same directory as the executable
    HuffmanEncoder encoder;
    PpmParser parser;


    std::vector<uint8_t> data = parser.PpmToRgbData(ppmFile);
    for (uint8_t byte : data) {
        std::cout << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    return 0;


}

