#ifndef ref_hpp
#define ref_hpp

#include <concepts>

namespace pp{
  // mutable reference class for python like references
  template<typename T>
  class ref{
    public:
      // lifetime
      ref<T>() = delete;

      ref<T>(const ref<T>& src): 
        value{src.value}
      {
        // constructing a mutable object is performing a shallow copy
      }

      const ref<T>& operator=(const ref<T>& src){
        this->value = new T{src.value};
        return *this;
      }

      ref<T>(const T& src): value{new T{src}}
      {
      }

      ref<T>& operator=(const T& src){
        // operator= on mutable references is performing a complete rebind
        this->value = new T{src};
        return *this;
      }

      ref<T>(const T&& src): value{new T{src}}{
      }

    public:
      // operator overloads
      bool operator==(ref<T> rhs){
        // operator== does a deep value comparison
        return *(this->value) == *(rhs.value) ? true : false;
      }

      ref<T> operator+(ref<T> rhs){
        return *(this->value) + *(rhs.value);
      }

      friend ref<T> operator++(ref<T> src, int){
        return *(src.value)++;
      }

    public:
      // python keywords
      bool is(ref<T> rhs){
        // performs a shallow comparison of the references. 
        //  Do the references refer to the same object?
        return this->value == rhs.value ? true : false;
      }

    public:
      // encapsulation breaking


    private:
      T* value;
  };

  // immutable reference class for python like references
  template<typename T>
  class refImm{
    public:
      refImm<T>() = default;
      refImm<T> operator+(refImm<T> rhs){
        return *(this->value) + *(rhs.value);
      }

    private:
      refImm<T>(const T& src): value{new T{src}}{}
      T* value;
  };
  
  template<typename T>
  concept ppReferenceType = std::same_as<T, ref<T>> || std::same_as<T, refImm<T>>;

  template<typename T>
    requires ppReferenceType<T>
  auto DeepCopy(T a, T b) -> decltype(T{}){

  }

} // namespace pp

#endif
