#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vec_;
  size_t m_;
  PComparator comp_;
};
// Add implementation of member functions here
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("head::top on empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec_.front();
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap::pop on empty");
  }

  std::swap(vec_.front(), vec_.back());
  vec_.pop_back();
  if (vec_.empty()) {return;}

  size_t i = 0;
    while (true) {
        size_t first = m_ * i + 1;
        if (first >= vec_.size()) {break;}

        size_t last = std::min(vec_.size(), first + (m_));
        size_t greatest_priority = first;
        for (size_t c = first + 1; c < last; ++c) {
            if (comp_(vec_[c], vec_[greatest_priority])) {greatest_priority = c;}
        }
            
        if (comp_(vec_[greatest_priority], vec_[i])) {
            std::swap(vec_[i], vec_[greatest_priority]);
            i = greatest_priority;
        } else break;
    }
}
//OTHER FUNCTIONS
// constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : vec_(), m_(m), comp_(c) 
  {
    if(m < 2) throw std::invalid_argument("m must be >= 2");
  }
// destructor
template <typename T, typename PComparator> 
Heap<T,PComparator>::~Heap() = default; // destructor
// empty()
template<typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return vec_.empty();
}
// size() 
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return vec_.size();
}
// push()
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec_.push_back(item);
  // sift up
  size_t child_index = vec_.size() - 1;
  while (child_index > 0) {
    size_t parent = (child_index - 1) / (m_);
    if (comp_(vec_[child_index], vec_[parent])) {
      std::swap(vec_[child_index], vec_[parent]);
      child_index = parent;
    } else {
      break;
    }
  }
}
#endif

