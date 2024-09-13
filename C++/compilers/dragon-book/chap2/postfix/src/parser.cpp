#include "parser.hpp"
#include <stdexcept>

namespace Kexpr{

// ------------------------------------------------------ //
//  Lifetime
// ------------------------------------------------------ //

Parser::Parser()
  :
    m_index{0}
{

}

Parser::Parser(std::vector<Token>&& src)
  :
    m_index{0},
    m_input{std::move(src)}
{

}

// ------------------------------------------------------ //
// Helper functions for recursive descent
// ------------------------------------------------------ //

void Parser::Match(Symbol symbol_t){
  if(m_input[m_index].symbol == symbol_t){
    m_index++;
  }
  else{
    throw std::runtime_error{"Error in Match"};
  }
}

Symbol Parser::NextSymbol(){
  return NextSymbol(0);
}

Symbol Parser::NextSymbol(std::size_t lookahead){
  return m_input[m_index + lookahead].symbol;
}

// ------------------------------------------------------ //
//  Recursive Descent
// ------------------------------------------------------ //

using namespace Nodes::Static;

void Parser::Start(){
 ExprNode expr = Expr();
}

ExprNode Parser::Expr(){
  TermNode term = Term();
  OpNode opnode = R();
}

OpNode Parser::R(){
  Symbol current = NextSymbol();
  switch(current){
    case Symbol::plus:
      Match(Symbol::plus);
      Term();
      R();
    case Symbol::minus:
      Match(Symbol::minus);
      Term();
      R();
    default:
  }
}

TermNode Parser::Term(){
  Symbol current = NextSymbol();
  switch(current){
    case Symbol::ident:
      Match(Symbol::ident);
    case Symbol::number:
      Match(Symbol::number);
  }
}

} // namespace Kexpr
