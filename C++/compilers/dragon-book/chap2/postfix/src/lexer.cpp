#include "lexer.hpp"
#include <sstream>

namespace Kexpr{

Lexer::Lexer()
  : m_cursor{0},
    m_wslut{
      {
        ' ', '\n', '\r'
      }
    },
    m_numbers{
      {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
      }
    },
    m_alphabet{
      {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 't', 'u', 'v', 'w', 'x', 'y', 'z'
      }
    }
{

}

Lexer::Lexer(std::string&& filename)
  : m_filename{std::move(filename)},
    m_cursor{0},
    m_wslut{
      {
        ' ', '\n', '\r'
      }
    },
    m_numbers{
      {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
      }
    },
    m_alphabet{
      {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 't', 'u', 'v', 'w', 'x', 'y', 'z'
      }
    }

{
  m_binary.reserve(50);
  LoadFile();
}

Lexer::Lexer(std::vector<char>&& input)
  : m_inputBuffer{std::move(input)},
    m_cursor{0},
    m_wslut{
      {
        ' ', '\n', '\r'
      }
    },
    m_numbers{
      {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
      }
    },
    m_alphabet{
      {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 't', 'u', 'v', 'w', 'x', 'y', 'z'
      }
    }
{
  m_binary.reserve(50);
}

//---------------------------------------------------------------//
// printing 
//---------------------------------------------------------------//

void Lexer::PrintCharacters(){
  for(std::size_t i = 0; i < m_inputBuffer.size(); i++){
    std::cout << m_inputBuffer[i] << ' ';
  }
  std::cout << '\n';
}

void Lexer::PrintHexCharacters(){
  for(std::size_t i = 0; i < m_inputBuffer.size(); i++){
    std::cout << static_cast<unsigned>(m_inputBuffer[i] & 0xFF) << ' ';
  }
  std::cout << '\n';
}


//---------------------------------------------------------------//
// main driver procedure
//---------------------------------------------------------------//

void Lexer::Convert(){
  while(m_cursor < m_inputBuffer.size() - 1){
    char ch = GetNextCharacter();
    switch(ch){
      // automaton starters
    }
  }
}

//---------------------------------------------------------------//
// Helpers
//---------------------------------------------------------------//

void Lexer::Match(char ch){
  if(m_inputBuffer[m_cursor] == ch){
    //std::cout << "matched " << ch << '\n';
    m_cursor++;
  }
  else{
    throw std::runtime_error{"Syntax Error;"};
  }
}

void Lexer::MatchWhitespace(){
  bool isWhitespace = m_wslut.find(m_inputBuffer[m_cursor]) != 
    m_wslut.end();
  if(isWhitespace){
    //std::cout << "matched isWhitespace" << '\n';
    m_cursor++;
  }
  else{
    throw std::runtime_error{"Syntax Error; Whitespace is not matched"};
  }
}

char Lexer::GetNextCharacter(){
  if(m_cursor == 0){
    return m_inputBuffer[m_cursor];
  }
  if(m_cursor < m_inputBuffer.size()){
    m_cursor++;
    return m_inputBuffer[m_cursor];
  }
}

void Lexer::ParseUntilWhitespace(){
  // useful for dealing with new lines
  while(m_wslut.find(m_inputBuffer[m_cursor]) != m_wslut.end()){
    m_cursor++;
  }
}

void Lexer::SkipUntilNewLine(){
  while(m_inputBuffer[m_cursor] != '\n'){
    m_cursor++;
  }
}

std::string Lexer::ReadDigitsUntilWhitespace(){
  // useful for some handlers like blow and submerge
  std::string value{};
  value.reserve(20);
  while(m_numbers.find(m_inputBuffer[m_cursor]) != m_numbers.end()){
    value.push_back(m_inputBuffer[m_cursor]);
    m_cursor++;
  }
  //std::cout << "digits: " << value << '\n';
  return value;
}

//---------------------------------------------------------------//
// automaton handlers
//---------------------------------------------------------------//
// automaton handler template:
//  we first see if the corresponding text matches
//  when we pass the matching tests, we produce the IR
//  (i still haven't decided to write the IR to a binary rep or
//   to write it directly to a lexical rep)
//  
//  on a fail, we throw a syntax error.

std::string Lexer::ReadIdentifier(std::string&& input){
  std::size_t index = 0;
  std::string value{};
  while(m_alphabet.contains(input[index])){
    value.push_back(input[index]);
    index++;
  }
  if(index != input.size()){
    std::stringstream ost;
    ost << "NOT ALL ALPHABET :: Index = " << index 
        << " :: input.size() = " << input.size()
        << " :: Original string = " << input 
        << " :: Violation = " << input[index] << '\n';
    throw std::runtime_error{ost.str()}; 
  }
  return value;
}

std::uint64_t Lexer::ReadNumber(std::string&& input){
  std::size_t index = 0;
  std::string value{};
  while(m_numbers.contains(input[index])){
    value.push_back(input[index]);
    index++;
  }
  if(index != input.size()){
    std::stringstream ost;
    ost << "NOT ALL NUMBERICAL :: Index = " << index 
        << " :: input.size() = " << input.size()
        << " :: Original string = " << input 
        << " :: Violation = " << input[index] << '\n';
    throw std::runtime_error{ost.str()}; 
  }
  return std::stoull(value);
}

} // namespace Kexpr
