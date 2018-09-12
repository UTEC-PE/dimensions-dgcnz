#ifndef VECTOR_H
#define VECTOR_H

template <typename Tr> class Vector {
public:
  typedef typename Tr::T T;
  typedef typename Tr::Operation Operation;

private:
  T *data;
  int dataSize;
  Operation op;
  int dimensions;
  int *dimensionSizes;

public:
  Vector() : data(nullptr){};

  Vector(int dimensions, int *dimensionSizes)
      : dimensions(dimensions), dimensionSizes(dimensionSizes) {
    for (int i = 0; i < dimensions; ++i) {
      this->dataSize *= *(dimensionSizes + i);
    }
    this->data = new int[this->dataSize];
  }

  void set(T datum, int *coordinates) {

    this->data[op(coordinates, this->dimensionSizes, this->dimensions)] = datum;
  }

  T get(int *coordinates) {
    return data[op(coordinates, this->dimensionSizes, this->dimensions)];
  }
  ~Vector() { delete[] this->data; }
};

#endif
