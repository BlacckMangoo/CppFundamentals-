#include <string>
#include <vector>
#include <fstream>


struct PpmImage {
    int width ;
    int height ;

    std::vector<uint8_t> rgbData ;
};


PpmImage loadImage( std :: string filename ) {

    std::ifstream file(filename,std::ios::binary);
    if (!file) throw std::runtime_error("File not found");

    std::string p6Confirm ;

   file >> p6Confirm ;
    if (p6Confirm != "P3") {
        throw std::runtime_error("P3 not found");
    }

    int width ;
    int height ;
    int maxVal ;

    file >> width >> height >> maxVal ;

}