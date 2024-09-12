#include "lexer.hpp"

int main(){
  Kexpr::Lexer lex{};
  std::cout << lex.ReadIdentifier("hello") << '\n';
  assert("hello" == lex.ReadIdentifier("hello"));

  std::cout << lex.ReadIdentifier("fku") << '\n';
  assert("fku" == lex.ReadIdentifier("fku"));

  std::cout << lex.ReadIdentifier("jennifier") << '\n';
  assert("jennifier" == lex.ReadIdentifier("jennifier"));

  std::cout << lex.ReadIdentifier("kakathejenny") << '\n';
  assert("kakathejenny" == lex.ReadIdentifier("kakathejenny"));

  //std::cout << lex.ReadIdentifier("kakath3j3nny") << '\n';

  assert(1234 == lex.ReadNumber("1234"));
  assert(4423124 == lex.ReadNumber("4423124"));
  std::cout << lex.ReadNumber("4ab13413de") << '\n';
}
