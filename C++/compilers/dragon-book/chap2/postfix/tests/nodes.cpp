#include <catch2/catch_test_macros.hpp>
#include <string>
#include <cstdint>


#include "./../src/syntax_tree_node.hpp"
#include "./../src/syntax_tree_nodes/ident_node.hpp"
#include "./../src/syntax_tree_nodes/op_node.hpp"
#include "./../src/syntax_tree_nodes/expr_node.hpp"
#include "./../src/syntax_tree_nodes/start_node.hpp"

TEST_CASE( "Syntax tree Node tests", "[syntax_node]" ) {
  SECTION( "syntaxnode construction" ) {
    using namespace Kexpr::Nodes;
    IdentNode rarity = IdentNode{"Rarity"};
    OpNode<IdentNode> opnode{Op::Add, rarity, nullptr};
    REQUIRE(1 == 1);
  }
  
  SECTION( "start node construction" ) {
    using namespace Kexpr::Nodes;
    IdentNode rarity = IdentNode{"Rarity"};
    OpNode<IdentNode> opnode{Op::Add, rarity, nullptr};
    ExprNode exprNode{rarity, &opnode};
    StartNode startNode{exprNode};
    REQUIRE(1 == 1);
  }

}
