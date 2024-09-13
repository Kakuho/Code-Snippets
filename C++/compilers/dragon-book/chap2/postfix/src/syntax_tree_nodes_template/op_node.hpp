#ifndef SYNTAX_TREE_OP_NODE_HPP
#define SYNTAX_TREE_OP_NODE_HPP

#include <cstdint>
#include <string>
#include <concepts>
#include <type_traits>

#include "ident_node.hpp"
#include "num_node.hpp"
#include "concepts.hpp"

namespace Kexpr::Nodes{

enum class Op{
  Add,
  Sub
};

template<typename T>
  requires(IsTermNode<T>)
struct OpNode{
  OpNode(Op optype, T& term, OpNode* r)
    : 
      optype{optype}, termNode{term}, rNode{r}
  {}

  Op optype;
  T& termNode;
  OpNode* rNode;
};

}   // namespace Kexpr::Nodes

#endif
