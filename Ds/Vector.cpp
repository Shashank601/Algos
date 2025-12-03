if the requested size fits inside the heap chunk the C++ allocator already has => no syscall.
if the allocator needs more PAGES => one syscall, eg. mmap or sbrk

If we create two vectors, 
we get two separate heap allocations, means:
    
Worst case: 2 syscalls (one for each vector’s initial buffer)
Best case: 0 syscalls (if the runtime fulfills them from existing heap memory)

so, heap alloc != sys call 


Heap allocation does not always mean a syscall.

Break it cleanly:

1. malloc/new often serve memory from user-space arenas
No syscall. Just pointer arithmetic inside glibc’s heap arena.

2. Syscalls only happen when allocator needs more pages  (okk)

That’s when we see:

mmap
brk / sbrk

This happens only when the ALLOCATOR`s CURRENT arena is exhausted.



so,
heap allocation => maybe syscall
syscall         => definitely heap expansion

but when large vector => occasional syscalls maybe



    
#include <iostream>
using namespace std;

template <typename T>
class Vector {
    T* arr;          // pointer to the data on heap
    int cap;         // total capacity
    int sz;          // current size

public:
    Vector() {
        arr = new T[1];
        cap = 1;
        sz = 0;
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(const T& val) {
        if (sz == cap) {
          //on full double it (new loc)
            cap *= 2;
            T* newArr = new T[cap];
            for (int i = 0; i < sz; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[sz++] = val;
    }

    void pop_back() {
        if (sz > 0) sz--;
    }

    int size() const { return sz; }
    int capacity() const { return cap; }
  //“const object access” and “non-const access.”  try again..
  T& operator[](int i) { return arr[i]; } //idhr multitasking
    const T& operator[](int i) const { return arr[i]; }
};

// int main() {
//     Vector<int> v;
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);

//     for (int i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
// }


