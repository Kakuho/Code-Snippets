#ifndef PARSER_HPP   
#define PARSER_HPP

// Recursive descent parser for expression evaluation
//
// Produces an abstract syntax tree, which can then be used 
// for evaluation

#include <vector>
#include <cstdint>
#include <stdexcept>

#include "tokens.hpp"
#include "syntax_tree_nodes_static/start_node.hpp"
#include "syntax_tree_nodes_static/expr_node.hpp"
#include "syntax_tree_nodes_static/op_node.hpp"
#include "syntax_tree_nodes_static/num_node.hpp"
#include "syntax_tree_nodes_static/ident_node.hpp"

namespace Kexpr{

class Parser{
  public:
    // ------------------------------------------------------ //
    //  Lifetime
    // ------------------------------------------------------ //

    Parser();
    Parser(std::vector<Token>&& src);

    // ------------------------------------------------------ //
    // Helper functions for recursive descent
    // ------------------------------------------------------ //

    void Match(Symbol symbol_t);
    Symbol NextSymbol();
    Symbol NextSymbol(std::size_t lookahead);

    // ------------------------------------------------------ //
    //  Recusrive Descent
    // ------------------------------------------------------ //
    
    // non terminals
    void Start();
    Nodes::Static::ExprNode Expr();
    Nodes::Static::OpNode R();
    Nodes::Static::TermNode Term();

  private:
    std::size_t m_index;
    std::vector<Token> m_input;
    Nodes::Static::StartNode* m_root;
};

} // namespace Kexpr

#endif
