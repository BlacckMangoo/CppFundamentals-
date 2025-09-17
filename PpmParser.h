#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class PpmParser {

public:


    std::vector<uint8_t> PpmToRgbData(std::string& filename) ;

};