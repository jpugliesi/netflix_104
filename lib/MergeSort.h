#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort {
  public:
    template <class T>
    static vector<T> sort (vector<T> a) {
      MergeSort(a, 0, a.size());
      return a;
    }
  private:
    void MergeSort(vector<T> & a, int l, int r){
      if (l<r) {
        int m = floor((l+r)/2);
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        Merge(a, l, r, m); // this is a separate function given below
      }
    }

    void Merge (vector<T> & a, int l, int r, int m)
    {
      T temp[r+1-l];
      // trace through the two subarrays, copying into a temporary one
      int i = l, j = m+1, k = 0;
      while (i <= m || j <= r)  // at least one subarray contains another element
      {
        // next smallest element in left subarray
        if (i <= m && (j > r || a[i] < a[j]))
        {
          temp[k] = a[i]; i ++; k ++;
        } else { 
          temp[k] = a[j]; j ++; k ++;
        }
        // next smallest element in right subarray
      }
      // now copy over the merged array into the original
      for (k = 0; k < r+1-l; k ++) a[k+l] = temp[k];
    }
};

#endif
