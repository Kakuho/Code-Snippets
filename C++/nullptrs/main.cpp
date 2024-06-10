#include <memory>

// adapted from scott meyeres modern effective c++

struct A{

};

void fShared(std::shared_ptr<A> ptr){

}

void fUnique(std::unique_ptr<A> ptr){

}

void fRaw(A* ptr){

}

template<typename FuncType, typename PtrType>
auto Delegater(FuncType func, PtrType ptr) -> decltype(func(ptr)){
  return func(ptr);
}

int main(){
  // these three compiles
  fShared(0);
  fUnique(0);
  fRaw(0);

  // however these three do not
  /*
  Delegater(fShared, 0);
  Delegater(fUnique, 0);
  Delegater(fRaw, 0);
  */

  //  this is because template argument deduces 0 as type int, and 
  //  fShared(int) 
  //  fUnique(int)
  //  fRaw(int)
  //  are all undefined
  //
  //  whereas the first three function calls compiles as 0 is a null pointer constant
  //
  //  STANDARD - 7.3.12
  //    A null pointer constant is an integer literal (5.13.2) with value zero or a prvalue of type std::nullptr_t. A
  //    null pointer constant can be converted to a pointer type; the result is the null pointer value of that type (6.8.4)
  //    and is distinguishable from every other value of object pointer or function pointer type. Such a conversion
  //    is called a null pointer conversion. Two null pointer values of the same type shall compare equal. The
  //    conversion of a null pointer constant to a pointer to cv-qualified type is a single conversion, and not the
  //    sequence of a pointer conversion followed by a qualification conversion (7.3.6). A null pointer constant of
  //    integral type can be converted to a prvalue of type std::nullptr_t
  //  END QUOTE
  //
  //  thus there exists an conversion from 0, an integral literal, which is a null pointer constant, to a
  //  std::nullptr_t. std::shared_ptr and std::unique_ptr both have constructors accepting a std::nullptr_t, meanwhile 
  //  for fRaw() uses the ability of std::nullptr_t being implicitly castable to all pointer types, and thus the beginning calls are legal.
}
