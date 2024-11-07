#pragma once
#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <matplot/matplot.h>
#include <sstream>
#include <string>
#include <vector>
// For the container part
#include <map>
#include <set>
// For the algorithms part
#include <utility>

namespace homework {

/**
 * Read the contents of a file into a vector of characters.
 * Replaces non alphabetical characters with spaces.
 * Lowercases all characters.
 * @param fileName The name of the file to read.
 * @return A vector of characters containing the contents of the file.
 */
std::vector<char> readBook(const std::string &fileName) {
  std::ifstream file(fileName);
  if (!file.is_open()) {
    std::cerr << std::format("Could not open file {}\n", fileName);
    std::terminate();
  }
  std::vector<char> book;
  // Remove all non-alphabetic characters
  for (char c; file.get(c);) {
    book.push_back(std::isalpha(c) ? std::tolower(c) : ' ');
  }
  return book;
}

/**
 * Get a vector of words from a vector of characters.
 * Words are defined as sequences of alphabetical characters separated by some
 * kind of space.
 * @param book The vector of characters to extract words from.
 * @return A vector of strings containing the words from the book.
 */
std::vector<std::string> getWords(const std::vector<char> &book) {
  std::istringstream stream(std::string(book.begin(), book.end()));
  std::vector<std::string> words;
  for (std::string word; stream >> word;) {
    words.push_back(word);
  }
  return words;
}

/**
 * Plot the word frequencies to a file.
 * Also outputs the ranks of the words to a file
 * @param frequencies The word frequencies to plot.
 * @param imageFilename The name of the file to save the image to.
 * @param rankFilename The name of the file to save the ranks to.
 */
template <typename PairContainer>
void plotWordFrequencies(const PairContainer &sortedFrequencies,
                         const std::string &imageFilename,
                         const std::string &rankFilename) {
  std::vector<int> ranks;
  std::vector<int> counts;
  int current_rank = 1;
  std::ofstream rankFile(rankFilename);
  for (auto &[frequency, word] : sortedFrequencies) {
    ranks.push_back(current_rank);
    counts.push_back(frequency);
    rankFile << std::format("{} {} {}\n", current_rank, frequency, word);
    current_rank++;
  }
  matplot::plot(ranks, counts);
  matplot::xlabel("Rank");
  matplot::ylabel("Frequency");
  matplot::title("Word Frequencies");
  matplot::save(imageFilename);
}
/**
 * Prints 10 arbitrary words that appear only once in the book (or all of them
 * if there are less than 10)
 * @param frequencies The word frequencies to process.
 */
template <class PairContainer>
void hapaxLegomena(const PairContainer &frequencies) {
  int count = 0;
  std::cout << "Some Hapax Legomena in the provided book:\n";
  for (auto &[frequency, word] : frequencies) {
    if (frequency == 1) {
      std::cout << word << "\n";
      count++;
    }
    if (count == 10) {
      break;
    }
  }
}
namespace containers {

/**
 * Compute the frequency of words in a book.
 * @param book The book to compute the frequency of words in.
 * @return A map from words to the number of times they appear in the book.
 */
std::map<std::string, int> computeWordFrequency(const std::vector<char> &book) {
  std::map<std::string, int> frequencies;
  for (const auto &word : getWords(book)) {
    frequencies[word]++;
  }
  return frequencies;
}

/**
 * Count the number of unique words in a book.
 * @param book The book to count the number of unique words in.
 * @return The number of unique words in the book.
 */
int countUniqueWords(const std::vector<char> &book) {
  std::set<std::string> uniqueWords;
  for (const auto &word : getWords(book)) {
    uniqueWords.insert(word);
  }
  return uniqueWords.size();
}

/**
 * Sort a map of word frequencies by frequency.
 * @param frequencies The map of word frequencies to sort.
 * @return A multimap of word frequencies sorted by frequency.
 */
std::multimap<int, std::string, std::greater<>>
sortFrequencies(const std::map<std::string, int> &frequencies) {
  std::multimap<int, std::string, std::greater<>> sortedFrequencies;
  for (const auto &[word, frequency] : frequencies) {
    sortedFrequencies.insert({frequency, word});
  }
  return sortedFrequencies;
}
} // namespace containers

/**
 * Equivalent functions to the ones in the containers namespace, but using the
 * STL algorithms. Only std::vector is allowed as a container
 */
namespace algorithms {
std::vector<std::pair<std::string, int>>
computeWordFrequency(const std::vector<char> &book) {
  std::vector<std::string> words = getWords(book);
  std::vector<std::pair<std::string, int>> result;
  std::sort(words.begin(), words.end());
  for (auto it = words.begin(); it != words.end();) {
    auto next = std::upper_bound(it, words.end(), *it);
    result.push_back({*it, next - it});
    it = next;
  }
  return result;
}

int countUniqueWords(const std::vector<char> &book) {
  std::vector<std::string> words = getWords(book);
  std::sort(words.begin(), words.end());
  return std::distance(words.begin(), std::unique(words.begin(), words.end()));
}

std::vector<std::pair<int, std::string>>
sortFrequencies(const std::vector<std::pair<std::string, int>> &frequencies) {
  std::vector<std::pair<int, std::string>> result;
  std::transform(frequencies.begin(), frequencies.end(),
                 std::back_inserter(result), [](const auto &p) {
                   return std::pair<int, std::string>(p.second, p.first);
                 });
  std::sort(result.begin(), result.end(), std::greater<>());
  return result;
}

} // namespace algorithms
} // namespace homework
