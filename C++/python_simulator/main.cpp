// python style argument passing in C++
//  python distinguishes between immutable types and mutable types
//
// citations: https://stackoverflow.com/questions/986006/how-do-i-pass-a-variable-by-reference

#include <cassert>

#include "ref.hpp"

using namespace pp;

template<typename T>
auto Add(ref<T> a, ref<T> b) -> decltype(a + b){
  return a + b;
}

template<typename T>
auto Increment(ref<T> a) -> decltype(a++){ 
  return a++; 
}

template<typename T>
auto Change(ref<T> a, T val) -> void{ 
  a = val;
}

void CheckEquality(){

}

int main(){
  ref<int> a{10};
  ref<int> a2 = a;
  ref<int> b{10};
  assert(a == a2);
  assert(a == b);
  assert(a.is(b));
}
