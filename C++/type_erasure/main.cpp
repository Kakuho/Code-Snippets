// example to understand type erasure
//
// Taken from https://www.modernescpp.com/index.php/type-erasure/
//
// Type erasure refers to when we want to remove type annotations associated with variables / objects before 
// execution at run time
//
// "ensuring that the run-time execution of a program doesn't depend on type information"
//
// Type erasure is a type-safe generic way to provide one interface for different types.
//
// Applications:
//  
//  Dispatch tables, where you accept functions of any types. 
//
//    Old C wayis to use void(*)();
//
//    a bit more modern C++ way is to define a base class as an interface and then create derived classes
//
//    This way is via type erasure method
//
// typeErasure.cpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Object {                                              // (2)
	 
public:
   // generic constructor => Object can be constructed with any class 
   template <typename T>                                   // (3)
   Object(T&& obj): object( std::make_shared<Model<T>>( std::forward<T>(obj) ) ){}
     
   // forwards to the object
   std::string getName() const {                           // (4)
       return object->getName(); 
   }
	

   struct Concept {                                         // (5)
       virtual ~Concept() {}
       virtual std::string getName() const = 0;
   };

   // 
   template< typename T >                                   // (6)
   struct Model : Concept {

      Model(const T& t) : object(t) {}

      // performs virtual dispatch 
	    std::string getName() const override {
		   return object.getName();
	   }

     private:
       T object;
   };
  
   // type concept
   //
   std::shared_ptr<const Concept> object;
};


void printName(std::vector<Object> vec){                    // (7)
    for (auto v: vec) std::cout << v.getName() << '\n';
}

struct Bar{
    // we will be creating container of objects - where we don't care about the type
    // getName is the method defined by the objects
    std::string getName() const {                           // (8)
        return "Bar";
    }
};

struct Foo{
    std::string getName() const {                           // (8)
        return "Foo";
    }
};

int main(){
	
    std::cout << '\n';
	
    std::vector<Object> vec{Object(Foo()), Object(Bar())};  // (1)
	
    printName(vec);
	
    std::cout << '\n';

}
