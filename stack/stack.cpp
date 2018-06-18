#include "stack.hpp"

namespace Stack {
  IndexOutOfRangeException::IndexOutOfRangeException(
                                                     IndexOutOfRangeException::index attempted,
                                                     IndexOutOfRangeException::index highest_legal,
                                                     IndexOutOfRangeException::index max_size
                                                     )
    : attempted_idx_(attempted)
    , highest_legal_idx_(highest_legal)
    , max_size_(max_size)
  {
    std::ostringstream string_stream;
        
    string_stream << "Stack attempted index "
                  << this->attempted_idx_;
    if (this->attempted_idx_ > this->max_size_) {
      string_stream << " is larger than max size "
                    << this->max_size_;
    } else {
      string_stream << " is larger than highest legal index "
                    << this->highest_legal_idx_;
    }
    this->description_ = string_stream.str();
  }
}
