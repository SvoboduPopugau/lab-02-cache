// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_CPU_TESTER_HPP_
#define INCLUDE_CPU_TESTER_HPP_

#include <vector>
#include <random>
#include <chrono>

const int TESTCOUNT = 1000;
const int TRANSFORM = 256;

class CPU_tester{
 public:
  CPU_tester(const std::vector<int>& ArrSizes,
             const int L1Cache, const int L3Cache);
  void completeAllTests();
 private:
  void SetArrSizes();
  double DirectTest(int arr_size);
  double ReverseTest(int arr_size);
  double RandomTest(int arr_size);
  int *GetRandArr(int size);
  int GetRandom(int first, int last);
 private:
  std::vector<int> arr_sizes;
  int Cache[2];
};

#endif  // INCLUDE_CPU_TESTER_HPP_
