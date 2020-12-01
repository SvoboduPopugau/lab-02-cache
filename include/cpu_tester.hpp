// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_CPU_TESTER_HPP_
#define INCLUDE_CPU_TESTER_HPP_

#include <vector>
#include <random>
#include <chrono>

#define TESTCOUNT 1000

class CPU_tester{
 public:
  explicit CPU_tester(const std::vector<int>& arrSizes);
  void completeAllTests();
 private:
  void Set_arrSizes();
  double DirectTest(int arr_size);
  double ReverseTest(int arr_size);
  double RandomTest(int arr_size);
  int *GetRandArr(int size);
  int GetRandom(int first, int last);
 private:
  std::vector<int> arr_sizes;
};

#endif  // INCLUDE_CPU_TESTER_HPP_