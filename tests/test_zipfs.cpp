#include "zipfs.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace homework;

// Helper function to create a temporary file for testing purposes
void createTempFile(const std::string &filename, const std::string &content) {
  std::ofstream file(filename);
  file << content;
}
// Test for readBook function
TEST(HomeworkTest, ReadBook_Success) {
  // Create a temporary file
  std::string tempFile = "temp.txt";
  createTempFile(tempFile, "Hello, World!");
  // Call readBook
  std::vector<char> result = readBook(tempFile);
  // Expected output: all lowercase, non-alphabetical characters replaced with
  // spaces
  std::vector<char> expected = {'h', 'e', 'l', 'l', 'o', ' ', ' ',
                                'w', 'o', 'r', 'l', 'd', ' '};
  EXPECT_EQ(result, expected);
  // Clean up
  std::remove(tempFile.c_str());
}

// Test for getWords function
TEST(HomeworkTest, GetWords) {
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o', ' ',
                             'w', 'o', 'r', 'l', 'd', ' '};
  std::vector<std::string> result = getWords(input);
  std::vector<std::string> expected = {"hello", "world"};
  EXPECT_EQ(result, expected);
}
// Test for computeWordFrequency in containers namespace
TEST(HomeworkTest, ComputeWordFrequency_Containers) {
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o', ' ', 'h', 'e', 'l',
                             'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
  std::map<std::string, int> result = containers::computeWordFrequency(input);
  std::map<std::string, int> expected = {{"hello", 2}, {"world", 1}};
  EXPECT_EQ(result, expected);
}
// Test for computeWordFrequency in algorithms namespace
TEST(HomeworkTest, ComputeWordFrequency_Algorithms) {
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o', ' ', 'h', 'e', 'l',
                             'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
  std::vector<std::pair<std::string, int>> result =
      algorithms::computeWordFrequency(input);
  std::vector<std::pair<std::string, int>> expected = {{"hello", 2},
                                                       {"world", 1}};
  EXPECT_EQ(result, expected);
}
// Test for countUniqueWords in containers namespace
TEST(HomeworkTest, CountUniqueWords_Containers) {
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o', ' ',
                             'w', 'o', 'r', 'l', 'd'};
  int result = containers::countUniqueWords(input);
  EXPECT_EQ(result, 2);
}
// Test for countUniqueWords in algorithms namespace
TEST(HomeworkTest, CountUniqueWords_Algorithms) {
  std::vector<char> input = {'h', 'e', 'l', 'l', 'o', ' ',
                             'w', 'o', 'r', 'l', 'd'};
  int result = algorithms::countUniqueWords(input);
  EXPECT_EQ(result, 2);
}
// Test for sortFrequencies in containers namespace
TEST(HomeworkTest, SortFrequencies_Containers) {
  std::map<std::string, int> frequencies = {{"hello", 2}, {"world", 1}};
  auto result = containers::sortFrequencies(frequencies);
  std::vector<std::pair<int, std::string>> expected = {{2, "hello"},
                                                       {1, "world"}};
  int i = 0;
  for (const auto &[frequency, word] : result) {
    EXPECT_EQ(frequency, expected[i].first);
    EXPECT_EQ(word, expected[i].second);
    i++;
  }
}
// Test for sortFrequencies in algorithms namespace
TEST(HomeworkTest, SortFrequencies_Algorithms) {
  std::vector<std::pair<std::string, int>> frequencies = {{"hello", 2},
                                                          {"world", 1}};
  auto result = algorithms::sortFrequencies(frequencies);
  std::vector<std::pair<int, std::string>> expected = {{2, "hello"},
                                                       {1, "world"}};
  EXPECT_EQ(result, expected);
}
// Test for hapaxLegomena function
TEST(HomeworkTest, HapaxLegomena) {
  std::multimap<int, std::string, std::greater<>> frequencies = {
      {1, "apple"}, {1, "banana"}, {2, "orange"}};
  // Capture console output
  testing::internal::CaptureStdout();
  hapaxLegomena(frequencies);
  std::string output = testing::internal::GetCapturedStdout();
  // Expected output: list of hapax legomena (words with frequency 1)
  EXPECT_TRUE(output.find("apple") != std::string::npos);
  EXPECT_TRUE(output.find("banana") != std::string::npos);
  EXPECT_TRUE(output.find("orange") == std::string::npos);
}
