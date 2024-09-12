#ifndef SYNTAX_TREE_NODE_HPP
#define SYNTAX_TREE_NODE_HPP

#include "expr_node.hpp"
#include "concepts.hpp"

namespace Kexpr::Nodes{

  template<typename T>
    requires(IsTermNode<T>)
  struct StartNode{
    StartNode(ExprNode<T>& expr)
      :
        expr{expr}
    {};

    ExprNode<T>& expr;
  };
}   // namespace Kexpr::Nodes

#endif
