#include <iostream>

template <class T>
std::vector<T> MergeSort::sort(std::vector<T> a) {

  return mergesort(a);
  
}

template<class T>
/*
 *  The mergesort function
 *  Takes in a vector mergeVector, and returns the sorted vector
 */
std::vector<T> MergeSort::mergesort(std::vector<T> & mergeVector){

    if(mergeVector.size() == 1){

        return mergeVector;
        
    }
    //find midpoint to split upon using vector iterators!
    typename std::vector<T>::iterator mid = mergeVector.begin()+(mergeVector.size()/2);
 
    /*
     *  Create vector l for the left half of the original vector
     */
    std::vector<T> l(mergeVector.begin(), mid);
    
    /*
     *  Create vector r for the right half of the original vector
     */
    std::vector<T> r(mid, mergeVector.end());
 
    // merge the vectors
    l = mergesort(l);
    r = mergesort(r);

    // return the merged vectors
    return merge(mergeVector, l, r);
    
}

template <class T>
/*
 *  The merge function
 *  the helper function for the mergesort function
 *  Merge's two SORTED vectors together and returns the resultant vector (which is sorted too)
 */
std::vector<T> MergeSort::merge(std::vector<T> & mergeVector, const std::vector<T> & l, const std::vector<T> & right){

    int left_iterator = 0;
    int right_iterator = 0;
    std::vector<T> outputVector;
 
    while(right_iterator < right.size() && left_iterator < l.size()){
        
        if (l[left_iterator] < right[right_iterator]){
            
            //push back the left vector's value since it is smaller
            outputVector.push_back( l[left_iterator] );
            left_iterator++;
            
        } else {
            
            //push back the right vector's value if it's smaller
            outputVector.push_back( right[right_iterator] );
            right_iterator++;

        }
    }
 
    // Push back the rest of the elements, it should be sorted because of our comparisons above
    while(left_iterator < l.size()){

        outputVector.push_back(l[left_iterator]);
        left_iterator++;

    }
 
    while(right_iterator < right.size()){

        outputVector.push_back(right[right_iterator]);
        right_iterator++;
        
    }

    //set the mergeVector to the merged output vector
	  mergeVector = outputVector;				
    
	return mergeVector;
  
}
