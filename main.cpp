#include "PpmParser.h"
#include "huffmanEncoder.h"
#include <iostream>
#include "CosineDiscreteTransform.h"


int main(){
    std::string input = "lla hsd h fh";
    std::string ppmFile = "sample.ppm";  // File is in the same directory as the executable
    HuffmanEncoder encoder;
    PpmParser parser;
    CosineDiscreteTransformer transformer ;


    std::vector<uint8_t> data = parser.PpmToRgbData(ppmFile);


    std::vector<uint8_t> yData = transformer.YChannel(data);
    std::vector<uint8_t> CbData = transformer.CbChannel(data) ;
    std::vector<uint8_t> CrData = transformer.CrChannel(data) ;

    std::vector<int8_t> shiftedY = transformer.ShiftDataForCDT(yData);

    std::vector<std::vector<int>> matrix = transformer.SelectCdtSegment(1,0,shiftedY);

    for ( auto& i : matrix) {
        for ( auto& j : i) {
            std::cout << j << " ";

        }
        std::cout << std::endl;
    }




}

