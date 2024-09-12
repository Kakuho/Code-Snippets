#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstdint>

enum class Symbol{
  id,
  equals,
  add,
  multiply,
  integer
};

struct Token{
  Symbol symbol;
  std::uint64_t entry;    // symbol table entry
};

#endif
