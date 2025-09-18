#include "CosineDiscreteTransform.h"

#include <valarray>

std::vector<uint8_t> CosineDiscreteTransformer::YChannel( std::vector<uint8_t>& data) {
    std::vector<uint8_t> yChannel ;
    for ( int i = 0 ; i < data.size(); i = i + 3  ) {

        uint8_t r = data[i];
        uint8_t g = data[i + 1];
        uint8_t b = data[i + 2];

        uint8_t y = 0.299 * r + 0.587 * g + 0.114 * b;
        yChannel.push_back( y);

    }

    return yChannel;
}

std::vector<uint8_t> CosineDiscreteTransformer::CrChannel( std::vector<uint8_t>& data) {
    std::vector<uint8_t> CrChannel ;
    for ( int i = 0 ; i < data.size(); i = i + 3  ) {

        uint8_t r = data[i];
        uint8_t g = data[i + 1];
        uint8_t b = data[i + 2];

        uint8_t cr = 0.5*r - 0.418688*g +0.5*b + 128 ;
        CrChannel.push_back( cr );

    }

    return CrChannel;
}

std::vector<uint8_t> CosineDiscreteTransformer::CbChannel( std::vector<uint8_t>& data) {
    std::vector<uint8_t> cbChannel ;
    for ( int i = 0 ; i < data.size(); i = i + 3  ) {

        uint8_t r = data[i];
        uint8_t g = data[i + 1];
        uint8_t b = data[i + 2];

        uint8_t cb = -0.168736 * r - 0.331264 * g + 0.5 * b + 128;
        cbChannel.push_back(cb);

    }

    return cbChannel;
}


std::vector<int8_t> CosineDiscreteTransformer::ShiftDataForCDT( std::vector<uint8_t>& data) {
    std::vector<int8_t> shiftData ;
    for ( int i = 0 ; i < data.size();  i++) {
        shiftData.push_back(data[i] - 128);
    }

    return shiftData;
}


std::vector<std::vector<int>> CosineDiscreteTransformer::SelectCdtSegment( int i , int j , std::vector<int8_t>& data) {
    std::vector<std::vector<int>> segment (8, std::vector<int>(8));
    int size = std::sqrt( data.size());
    int startRow = 8* i ;
    int startColumn = 8* j ;

    for ( int row = 0 ;  row < 8 ; row = row + 1 ) {
        for ( int column = 0 ; column < 8 ; column = column + 1 ) {
            int idx = (startRow + row)*size + startColumn + column ;
            segment[row][column] = data[ idx] ;
        }
    }

    return segment ;

}

std::vector<std::vector<double>> CosineDiscreteTransformer::CdtApply( std::vector<std::vector<int>> matrixData) {
    int N = 8;
    std::vector<std::vector<double>> result(N, std::vector<double>(N, 0.0));

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            double alpha = (u == 0) ? std::sqrt(1.0 / N) : std::sqrt(2.0 / N);
            double beta  = (v == 0) ? std::sqrt(1.0 / N) : std::sqrt(2.0 / N);

            double sum = 0.0;

            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    sum += matrixData[x][y] *
                           std::cos(((2 * x + 1) * u *3.14 ) / (2.0 * N)) *
                           std::cos(((2 * y + 1) * v * 3.14) / (2.0 * N));
                }
            }

            result[u][v] = alpha * beta * sum;
        }
    }

    return result;
}
