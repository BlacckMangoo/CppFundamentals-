#pragma once
#include <vector>

class CosineDiscreteTransformer {
    public:
    // they return a vector of size data / 3 merge rgb

    std::vector<uint8_t> YChannel( std::vector<uint8_t>& data);
    std::vector<uint8_t> CbChannel( std::vector<uint8_t>& data);
    std::vector<uint8_t> CrChannel( std::vector<uint8_t>& data);
    std::vector<int8_t> ShiftDataForCDT( std::vector<uint8_t>& data);

// input image must be a square
    std::vector<std::vector<int>> SelectCdtSegment( int i , int j , std::vector<int8_t>& data) ;
   // this will be applied on a 8x8 matrix 
    std::vector<std::vector<int>> CdtApply(std::vector<std::vector<int>>& matrixData);

};
