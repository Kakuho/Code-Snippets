#ifndef SYNTAX_TREE_EXPR_NODE_HPP
#define SYNTAX_TREE_EXPR_NODE_HPP

#include <cstdint>
#include <string>
#include <concepts>

#include "op_node.hpp"
#include "ident_node.hpp"
#include "num_node.hpp"
#include "concepts.hpp"

namespace Kexpr::Nodes{

template<typename T>
  requires(IsTermNode<T>)
struct ExprNode{
  ExprNode(T& termnode_t, OpNode<T>* rNode_t)
    : 
      termNode{termnode_t}, rNode{rNode_t}
  {};

  T& termNode;
  OpNode<T>* rNode;
};

}   // namespace Kexpr::Nodes

#endif
