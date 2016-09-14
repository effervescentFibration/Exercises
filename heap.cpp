#include<string>
#include<cstdlib>
#include<iostream>

template <typename T>
class Heap {
private:
  T * h;
  int capacity;
  int size;
  void doubleCapacity() {
    // must handle empty case separately
    int new_cap = ((capacity * 2) > 1) ? capacity * 2 : 1;
    T * h_new = new T[new_cap];
    for (int i = 0; i < capacity; ++i) {
      (h_new)[i] = (h)[i];
    }
    capacity = new_cap;
    free(h);
    h = h_new;
  }
  int left(int i) {
    return 2 * i;
  }
  int right(int i) {
    return 2 * i + 1;
  }
  int parent(int i) {
    return i / 2;
  }
 
  void percolateDown(int i) {
    int l = left(i);
    int r = right(i);
    int c = i;
    if (l < size && h[l] < h[i]) {
      c = l;
    }
    else if (r < size && h[r] < h[i]) {
      c = r;
    }
    if (c != i) {
      T temp = h[i];
      h[i] = h[c];
      h[c] = temp;
      percolateDown(c);
    }
  }

  void percolateUp(int i) {
    int p = parent(i);
    if (i > 0 && h[p] > h[i]) {
      T temp = h[i];
      h[i] = h[p];
      h[p] = temp;
      percolateUp(p);
    }
  }
  
public:
  Heap() {
    h = nullptr;
    capacity = 0;
    size = 0;
    return;
  }
  Heap(T t) {
    h = new T[1];
    capacity = 1;
    size = 1;
    h[0] = t;
  }

  Heap(const Heap & other) {
    h = new T[other.capacity];
    for (int i = 0; i < other.size; ++i) {
      (* h)[i] = (* other.h)[i];
    }
    size = other.size;
    capacity = other.capacity;
  }

  Heap(Heap && other) {
    h = other.h;
    size = other.size;
    capacity = other.capacity;
    other.h = nullptr;
    other.size = 0;
    other.capacity = 0;
  }

  void insert(T t) {
    if (size == capacity) {
      doubleCapacity();
    }
    h[size] = t;
    size++;
    percolateUp(size - 1);
    std::cout << toString();
  }

  T pop() {
    T temp = h[0];
    h[0] = h[size-- - 1];
    percolateDown(0);
    return temp;
  }

  bool isEmpty() {
    return (size == 0);
  }

  std::string toString() {
    std::string string_vector[size + 2];
    string_vector[0] = "[ ";
    for (int i = 0; i < size; ++i) {
      string_vector[i + 1] = std::to_string(h[i]) + " ";
    }
    string_vector[size + 1] = "]\n";
    int string_length = 0;
    for (int i = 0; i < size + 2; ++i) {
      string_length += string_vector[i].size();
    }
    std::string final_string;
    final_string.resize(string_length);
    for (int i = 0, j = 0, k = 0; i < string_length; ++i, ++k) {
      if (k == string_vector[j].size()) {
	++j;
	k = 0;
      }
      final_string[i] = string_vector[j][k];
    }
    return final_string;
  }
};

int main(int argc, char * argv[]) {
  Heap<int> h;
  h.insert(123);
  h.insert(1);
  h.insert(2);
  h.insert(3);
  h.insert(0);
  h.insert(72);
  h.insert(27);
  h.insert(333);
  while (!h.isEmpty()) {
    std::cout << h.pop() << '\n';
  }
}
