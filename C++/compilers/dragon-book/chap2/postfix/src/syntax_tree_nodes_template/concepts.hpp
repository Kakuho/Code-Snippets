#ifndef NODE_CONCEPTS_HPP   
#define NODE_CONCEPTS_HPP

#include "ident_node.hpp"
#include "num_node.hpp"

namespace Kexpr::Nodes{

  template<typename T>
  concept IsTermNode = std::same_as<T, IdentNode> || 
                       std::same_as<T, NumNode>;
}

#endif
