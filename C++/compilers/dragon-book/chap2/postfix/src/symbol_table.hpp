#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

// Class to represent the symbol table
// Symbol tables is a lut for identifiers in scope

#include <unordered_map>
#include <string>
#include <cstdint>

namespace Kexpr{

class SymbolTable{
  public:
    // ----------------------------------------------------------------- //
    // Lifetime 
    // ----------------------------------------------------------------- ////

    SymbolTable();

    // ----------------------------------------------------------------- //
    //  Operational
    // ----------------------------------------------------------------- ////

    void SetPrevious(SymbolTable& tbl);

    // these two could probably be operator overloaded
    void Put(std::string&& identifier, std::uint16_t value);
    void Get(std::string&& identifier);

  private:
    SymbolTable* m_prev;
    std::unordered_map<std::string, std::uint16_t> m_lut;
};

} // namespace Kexpr

#endif
