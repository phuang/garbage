#include <iostream>
#include <string>
#include <vector>

namespace {

template<typename T>
void print_array(std::vector<T>& array, int first = 0, int last = -1) {
  if (last == -1)
    last = array.size() - 1;
  for (int c = first; c <= last; ++c) {
    std::cout << array[c] << " ";
  }
  std::cout << std::endl;
}

template<typename T>
void qsort(std::vector<T>& array, int first, int last) {
  if (first >= last)
    return;
  
  int i = first;
  int j = last;
  
  T pv = array[j];
  
  while (i != j) {

    while (i < j) {
      if (array[i] > pv) {
        array[j--] = array[i];
        break;
      } else {
        i++;
      }
    }

    while (j > i) {
      if (array[j] < pv) {
        array[i++] = array[j];
        break;
      } else {
        j--;
      }
    }
  }
  array[i] = pv;

  qsort(array, first, i - 1);
  qsort(array, i + 1, last);
}

}

int main() {

  std::vector<int> test;
  test.push_back(9);
  test.push_back(4);
  test.push_back(10);
  test.push_back(11);
  test.push_back(1);
  test.push_back(1);
  test.push_back(45);
  test.push_back(17);
  test.push_back(13);
  test.push_back(4);
  
  print_array(test);
  qsort(test, 0, test.size() - 1);
  print_array(test);

  std::vector<std::string> words;

  while(!std::cin.eof()) {
    std::string word;
    std::cin >> word;
    words.push_back(word);
  }

  qsort(words, 0, words.size() - 1);

  print_array(words);
}
