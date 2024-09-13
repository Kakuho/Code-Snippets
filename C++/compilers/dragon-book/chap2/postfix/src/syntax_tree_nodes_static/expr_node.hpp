#ifndef SYNTAX_TREE_EXPR_NODE_HPP
#define SYNTAX_TREE_EXPR_NODE_HPP

#include <cstdint>
#include <string>
#include <concepts>

#include "op_node.hpp"
#include "ident_node.hpp"
#include "num_node.hpp"

namespace Kexpr::Nodes::Static{

struct ExprNode{
  ExprNode(IdentNode& termnode_t, OpNode* rNode_t)
    : 
      identNode{&termnode_t}, rNode{rNode_t}
  {
  };

  ExprNode(NumNode& termnode_t, OpNode* rNode_t)
    : 
      numNode{&termnode_t}, rNode{rNode_t}
  {
  };

  OpNode* rNode;
  union{
    IdentNode* identNode;
    NumNode* numNode;
  };
};

}   // namespace Kexpr::Nodes

#endif
