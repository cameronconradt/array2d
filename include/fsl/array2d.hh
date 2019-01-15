#ifndef FSL_ARRAY2D_HH
#define FSL_ARRAY2D_HH

#include <cstddef>
#include <utility>
#include <valarray>
#include <iostream>

namespace fsl {

template <class T> class array2d {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = T const &;
  using size_type = std::size_t;

  class ProxyRow {
  public:
	  ProxyRow(std::valarray<T>& array, size_type columns, size_type row) :
		  array(array), columns(columns), row(row) {}
	  reference operator[](size_type n) {
		  if (n >= columns)
			  throw std::invalid_argument("column out of bounds");
		  return array[row * columns + n];
	  }
  private:
	  std::valarray<T>& array;
	  size_type columns;
	  size_type row;

  };

  array2d() : columns_{}, storage_{} {}

  array2d(size_type rows, size_type columns)
      : columns_{columns}, storage_(rows * columns) {}

  array2d(array2d const &b) = default;
  array2d(array2d &&b) noexcept = default;
  ~array2d() = default;

  size_type rows() const {
    // How do we calculate the number of rows since we did not store it?
	  size_type size = 1;
	  for (auto i = begin(storage_); i != end(storage_); i++) {
		  size++;
	  }
    return size/columns_;
  }

  size_type columns() const { 
	  return columns_; }

  bool empty() const {
    // How do we know if the structure is empty?
	  return storage_.size() == 0;
  }

  /* Return row `n` from the storage. */
  ProxyRow operator[](size_type n) {
    // How do we return a single row? How big is a single row?
    // What should the return type of this member function be?
	  if (n >= rows()) {
		  throw std::invalid_argument("row out of bounds");
	  }
	  return ProxyRow(storage_, columns_, n);
  }

  ProxyRow const operator[](size_type n) const {
	  
    // How do we implement the const version?
	  if (n >= rows()) {
		  throw std::invalid_argument("row out of bounds");
	  }
	  return ProxyRow(storage_, columns_, n);
  }

  /* Return the element at row and column. These should be equivalent:
   *     (*this)(row, column) == (*this)[row][column]
   * but operator() should generally be more efficient. */
  reference operator()(size_type row, size_type column) {
    // How do we translate row and column (2d) into offset (1d)?
	  size_type offset{ row * this->columns_ + column };
	  if (offset >= storage_.size())
		  throw std::invalid_argument("out of bounds");
    return storage_[offset];
  }

  const_reference operator()(size_type row, size_type column) const {
    // How do we implement the const version?
	  size_type offset{ row * this->columns_ + column };
	  if (offset >= storage_.size())
		  throw std::invalid_argument("out of bounds");
    return storage_[offset];
  }

  void swap(array2d &other) {
    using std::swap;
	size_type tempType{ columns_ };
	columns_ = other.columns_;
	other.columns_ = tempType;
	swap(storage_, other.storage_);
    // How do we swap these?
  }


private:
  /* The number of columns per row. */
  size_type columns_;
  std::valarray<value_type> storage_;
};

template <class T> void swap(array2d<T> &a, array2d<T> &b) { a.swap(b); }
} // namespace fsl

#endif
