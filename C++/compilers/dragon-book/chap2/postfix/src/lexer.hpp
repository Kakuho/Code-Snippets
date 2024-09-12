#ifndef LEXER_HPP
#define LEXER_HPP

// Simplfications:
//
//    Identifiers may only have alphabetical characters
//
//    Numbers are unsigned 64bit integrals

#include <cstdint>
#include <vector>
#include <set>
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

#include "tokens.hpp"
#include "util.hpp"

namespace Kexpr{

class Lexer{
  public:
    // ------------------------------------------------------ //
    // Lifetime
    // ------------------------------------------------------ //

    Lexer();
    Lexer(std::string&& filename);
    Lexer(std::vector<char>&& input);

    // ------------------------------------------------------ //
    // Printing
    // ------------------------------------------------------ //
    
    void PrintCharacters();
    void PrintHexCharacters();

    // ------------------------------------------------------ //
    // Main driver procedure
    // ------------------------------------------------------ //

    void Convert();
    std::vector<std::uint8_t>&& DestructiveGetBinaryIR()
    {return std::move(m_binary);}

    // ------------------------------------------------------ //
    // Helpers
    // ------------------------------------------------------ //
    
    void Match(char ch);
    void MatchWhitespace();
    char GetNextCharacter();
    void ParseUntilWhitespace();
    void SkipUntilNewLine();
    std::string ReadDigitsUntilWhitespace();

    std::string ReadIdentifier(std::string&& chars);
    std::uint64_t ReadNumber(std::string&& chars);

    // ------------------------------------------------------ //
    // automaton handlers - modeled as DFAs
    // ------------------------------------------------------ //

    struct unimplemented_ex{};

    // these procedures, should produce symbol_table entries
    Token MatchIdentifier() { throw unimplemented_ex{};}
    Token MatchNumber()     { throw unimplemented_ex{};}

  private:
    void LoadFile(){
      // procedure to load the ascii bytes to ram
      std::ifstream inputfile{m_filename, std::ios::in | std::ios::ate};
      if(!inputfile){
        throw std::runtime_error{"Input file error"};
      }
      std::size_t filesize = inputfile.tellg();
      // now we place all the bytes into ram
      m_inputBuffer.reserve(filesize);
      m_inputBuffer.resize(filesize);
      inputfile.seekg(0);
      if(!inputfile.read(&m_inputBuffer[0], filesize)){
        throw std::runtime_error{"error reading bytes into vector buffer"};
      }
    }

  private:
    std::string m_filename;
    std::vector<char> m_inputBuffer;
    std::size_t m_cursor;
    std::set<char> m_wslut;
    std::set<char> m_numbers;
    std::set<char> m_alphabet;
    std::vector<std::uint8_t> m_binary;   // the binary representation
};

} // namespace Kexpr

#endif
