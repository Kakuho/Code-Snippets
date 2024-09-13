#ifndef SYNTAX_TREE_NUM_NODE_HPP
#define SYNTAX_TREE_NUM_NODE_HPP

#include <cstdint>

namespace Kexpr::Nodes{
  struct NumNode{
    NumNode(std::uint64_t number)
      : 
        number{number}
    {}

    std::uint64_t number;
  };
}   // namespace Kexpr::Nodes

#endif
