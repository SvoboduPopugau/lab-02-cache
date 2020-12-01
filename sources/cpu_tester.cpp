// Copyright 2020 Your Name <your_email>

#include <cpu_tester.hpp>
#include <iostream>
CPU_tester::CPU_tester(const std::vector<int>& arrSizes)
    : arr_sizes(arrSizes) {
  this->Set_arrSizes();
}
void CPU_tester::Set_arrSizes() {
  int L1 = 32;
  int L3 = 8192;  //in Kib
  int size = L1/2;
  while (size < 3 * L3 / 2) {
    arr_sizes.push_back(size * 256);
    size *= 2;
  }
  arr_sizes.push_back(3 * 256 * L3 / 2);
}
void CPU_tester::completeAllTests() {
//    Direct test
  std::cout << "investigation: " << std::endl << "travel variant: direct" <<\
      std::endl << "experiments: " << std::endl;
  for (size_t i = 0; i < arr_sizes.size(); ++i){
    std::cout << "- experiment: " << std::endl <<\
        "    number: " << i + 1 << std::endl <<\
        "    input data: " << std::endl <<\
        "      buffer size: " << arr_sizes[i]/256 << "KiB" << std::endl <<\
        "    results: " << std::endl <<\
        "      duration: " << DirectTest(arr_sizes[i]) << " mcs" <<\
        std::endl;
  }
  //Reverse test
  std::cout << "investigation: " << std::endl << "travel variant: reverse" <<\
      std::endl << "experiments: " << std::endl;
  for (size_t i = 0; i < arr_sizes.size(); ++i){
    std::cout << "- experiment: " << std::endl <<\
        "    number: " << i + 1 << std::endl <<\
        "    input data: " << std::endl <<\
        "      buffer size: " << arr_sizes[i]/256 << "KiB" << std::endl <<\
        "    results: " << std::endl <<\
        "      duration: " << ReverseTest(arr_sizes[i]) << " mcs" <<\
        std::endl;
  }
    //Random test
  std::cout << "investigation: " << std::endl << "travel variant: random" <<\
      std::endl << "experiments: " << std::endl;
  for (size_t i = 0; i < arr_sizes.size(); ++i){
    std::cout << "- experiment: " << std::endl <<\
        "    number: " << i + 1 << std::endl <<\
        "    input data: " << std::endl <<\
        "      buffer size: " << arr_sizes[i]/256 << "KiB" << std::endl <<\
        "    results: " << std::endl <<\
        "      duration: " << RandomTest(arr_sizes[i]) << " mcs" <<\
        std::endl;
  }
}
double CPU_tester::DirectTest(int arr_size) {
  int* array = GetRandArr(arr_size);
  int temp = 0;
  temp = temp + 1;

  for (int i = 0; i < arr_size; i+=16)
    temp = array[i];

  double time = 0;
  for (int j = 0; j < TESTCOUNT; ++j){
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < arr_size; i+=16)
      temp = array[i];
    auto finish = std::chrono::steady_clock::now();
    time +=
        std::chrono::duration_cast<std::chrono::microseconds>(finish-start)
            .count();
  }
  delete array;
  return time/static_cast<double>(TESTCOUNT);
}
double CPU_tester::ReverseTest(int arr_size) {
  int* array = GetRandArr(arr_size);
  int temp = 0;
  temp = temp + 1;

  for (int i = 0; i < arr_size; i+=16)
    temp = array[arr_size-1-i];

  double time = 0;
  for (int j = 0; j < TESTCOUNT; ++j){
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < arr_size; i+=16)
      temp = array[arr_size-1-i];
    auto finish = std::chrono::steady_clock::now();
    time +=
        std::chrono::duration_cast<std::chrono::microseconds>(finish - start)
        .count();
  }
  delete array;
  return time/static_cast<double>(TESTCOUNT);
}
double CPU_tester::RandomTest(int arr_size) {
  int* array = GetRandArr(arr_size);
  int temp = 0;
  temp = temp +1;

  for (int i = 0; i < arr_size/16; ++i)
    temp = array[GetRandom(0, arr_size - 1)];

  double time = 0;
  for (int j = 0; j < TESTCOUNT; ++j){
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < arr_size/16; ++i)
      temp = array[GetRandom(0, arr_size-1)];
    auto finish = std::chrono::steady_clock::now();
    time +=
        std::chrono::duration_cast<std::chrono::microseconds>(finish - start)
            .count();
  }
  delete array;
  return time/static_cast<double>(TESTCOUNT);
}
int CPU_tester::GetRandom(int first, int last) {
  return first + random() % (last - first + 1);
}
int* CPU_tester::GetRandArr(int size) {
  int *arr = new int[size];
  for (int i = 0; i < size; ++i)
    arr[i] = rand();
  return arr;
}
