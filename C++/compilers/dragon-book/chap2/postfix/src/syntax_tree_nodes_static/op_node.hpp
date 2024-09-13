#ifndef SYNTAX_TREE_OP_NODE_HPP
#define SYNTAX_TREE_OP_NODE_HPP

#include <cstdint>
#include <string>
#include <concepts>
#include <type_traits>
#include <cassert>

#include "ident_node.hpp"
#include "num_node.hpp"

namespace Kexpr::Nodes::Static{

enum class Op{
  Add,
  Sub
};

enum class TermNode{
  Ident,
  Num
};

struct OpNode{
  OpNode(Op optype, IdentNode& term, OpNode* r)
    : 
      optype{optype}, 
      identNode{&term}, 
      rNode{r},
      termType{TermNode::Ident}
  {
  }

  OpNode(Op optype, NumNode& term, OpNode* r)
    : 
      optype{optype}, 
      numNode{&term}, 
      rNode{r},
      termType{TermNode::Ident}
  {
  }

  Op optype;
  TermNode termType;
  OpNode* rNode;
  union{
    IdentNode* identNode;
    NumNode* numNode;
  };

};

}   // namespace Kexpr::Nodes

#endif
