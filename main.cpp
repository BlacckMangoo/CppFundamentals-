#include <PpmParser.h>
#include <huffmanEncoder.h>

int main(){
    const std::string input = "lla hsd h fh";
    
    HuffmanEncoder encoder;
    encoder.Encode(input);
    encoder.PrintCodes();
    
    return 0;


}

