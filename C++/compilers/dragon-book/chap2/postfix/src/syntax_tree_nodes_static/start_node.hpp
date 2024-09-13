#ifndef SYNTAX_TREE_NODE_HPP
#define SYNTAX_TREE_NODE_HPP

#include "expr_node.hpp"

namespace Kexpr::Nodes::Static{

  struct StartNode{
    StartNode(ExprNode& expr)
      :
        expr{expr}
    {};

    ExprNode& expr;
  };
}   // namespace Kexpr::Nodes

#endif
