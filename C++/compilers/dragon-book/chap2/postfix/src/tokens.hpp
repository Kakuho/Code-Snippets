#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <cstdint>

namespace Kexpr{

enum class Symbol{
  plus,
  minus,
  multiply,
  divide,
  leftbracket,
  rightbracket,
  number,
  ident
};

struct Token{
  Symbol symbol;
  std::uint64_t index;
};

}

#endif
