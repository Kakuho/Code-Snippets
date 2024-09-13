#ifndef SYNTAX_TREE_IDENT_NODE_HPP
#define SYNTAX_TREE_IDENT_NODE_HPP

#include <cstdint>
#include <string>

namespace Kexpr::Nodes{
  struct IdentNode{
    IdentNode(std::string&& identifer)
      : 
        identifer{std::move(identifer)}
    {};

    std::string identifer;
  };
}   // namespace Kexpr::Nodes

#endif
