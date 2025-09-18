#include "PpmParser.h"

std::vector<uint8_t> PpmParser::PpmToRgbData(const std::string& filename) {

      std::ifstream file(filename);
    if (!file) throw std::runtime_error("File not found");

    std::string magic;
    int width, height, maxVal;

    // Read magic number
    file >> magic;
    if (magic != "P3") throw std::runtime_error("Not a P3 PPM file");

    // Skip comments
    while (file.peek() == '#') file.ignore(2048,'\n');

    // Read width, height
    file >> width >> height;

    // Skip comments again before maxVal
    while (file.peek() == '#') file.ignore(2048,'\n');

    // Read max color value
    file >> maxVal;
    file.ignore(1); // skip single whitespace after maxVal

    std::vector<uint8_t> pixels;
    pixels.reserve(width * height * 3);

    int r, g, b;
    while (file >> r >> g >> b) {
        pixels.push_back(static_cast<uint8_t>(r));
        pixels.push_back(static_cast<uint8_t>(g));
        pixels.push_back(static_cast<uint8_t>(b));
    }

    file.close();

    return pixels;

}
