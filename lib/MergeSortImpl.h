#include <iostream>

template <class T>
std::vector<T> MergeSort::sort(std::vector<T> a) {
  return mergesort(a);
}

template<class T>
std::vector<T> MergeSort::mergesort(std::vector<T>& vec)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }
 
    // Determine the location of the middle element in the vector
    typename std::vector<T>::iterator middle = vec.begin() + (vec.size() / 2);
 
    std::vector<T> left(vec.begin(), middle);
    std::vector<T> right(middle, vec.end());
 
    // Perform a merge sort on the two smaller vectors
    left = mergesort(left);
    right = mergesort(right);
 
    return merge(vec,left, right);
}

template <class T>
std::vector<T> MergeSort::merge(std::vector<T> &vec,const std::vector<T>& left, const std::vector<T>& right)
{
    // Fill the resultant vector with sorted results from both vectors
    std::vector<T> result;
    unsigned left_it = 0, right_it = 0;
 
    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // To the resultant vector
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }
 
    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }
 
    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }
  //show merge process..
  /*int i;
  for(i=0;i<result.size();i++)
  {                                
    std::cout<<result[i]<<" ";
  }
  // break each line for display purposes..
  std::cout<<"***********"<<std::endl;*/
  
  //take a source vector and parse the result to it. then return it.  
	vec = result;				
	return vec;
}
/*template <class T>
void MergeSort::mergesort(std::vector<T> & a, int l, int r){
  if (l<r) {
    std::cout << "merging" << std::endl;
    T m = std::floor((l+r)/2);
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, r, m); // this is a separate function given below
  }
}

template <class T>
void MergeSort::merge(std::vector<T> & a, int l, int r, int m)
{
  std::vector<T> temp(r+1-l);
  // trace through the two subarrays, copying To a temporary one
  T i = l, j = m+1, k = 0;
  while (i <= m || j <= r)  // at least one subarray contains another element
  {
    // next smallest element in left subarray
    if (i <= m && (j > r || a.at(i) < a.at(j)))
    {
      temp.at(k) = a.at(i);
      i++;
      k++;
    } else { 
      temp.at(k) = a.at(j);
      j++;
      k++;
    }
    // next smallest element in right subarray
  }
  // now copy over the merged array To the original
  for (k = 0; k < r+1-l; k ++){
    a.at(k+l) = temp.at(k);
  }
}*/
