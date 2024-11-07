#include"zipfs.h"
using namespace homework;

int main(int argc, char *argv[]){
  if(argc == 1){
    std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::string fileName = argv[1];
  auto book = readBook(fileName);
  auto frequencies = algorithms::computeWordFrequency(book);
  auto uniqueWords = algorithms::countUniqueWords(book);
  auto sortedFrequencies = algorithms::sortFrequencies(frequencies);
  hapaxLegomena(sortedFrequencies);
  plotWordFrequencies(sortedFrequencies, "zipfs.png", "zipfs.txt");
}
