#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class PpmParser {
public:
    // Takes filename by const reference since we don't modify it
    std::vector<uint8_t> PpmToRgbData(const std::string& filename);
};