#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include <cmath>
class MergeSort {
  public:
    template <class T>
    static std::vector<T> sort(std::vector<T> a);
  private:
    template <class T>
    static std::vector<T> mergesort(std::vector<T>& vec);
    template <class T>
    static std::vector<T> merge(std::vector<T> &vec,const std::vector<T>& left, const std::vector<T>& right);
};

#include "MergeSortImpl.h"

#endif
