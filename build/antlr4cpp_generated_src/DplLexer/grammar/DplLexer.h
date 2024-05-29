
// Generated from /home/vind/dpl/grammar/DplLexer.g4 by ANTLR 4.13.1

#pragma once


    #include <queue>


#include "antlr4-runtime.h"


namespace dplgrammar {


class  DplLexer : public antlr4::Lexer {
public:
  enum {
    Indent = 1, Dedent = 2, If = 3, Else = 4, While = 5, Break = 6, Continue = 7, 
    Return = 8, Def = 9, OpenPar = 10, ClosePar = 11, OpenCurly = 12, CloseCurly = 13, 
    OpenSquare = 14, CloseSquare = 15, Colon = 16, Comma = 17, Dollar = 18, 
    Exponent = 19, Plus = 20, Minus = 21, Star = 22, Slash = 23, Mod = 24, 
    Equal = 25, NotEqual = 26, Less = 27, LessEqual = 28, Greater = 29, 
    GreaterEqual = 30, And = 31, Or = 32, Not = 33, Assign = 34, Union = 35, 
    Intersection = 36, Integer = 37, Float = 38, Bool = 39, String = 40, 
    None = 41, Identifier = 42, Comment = 43, Newline = 44, Whitespace = 45
  };

  explicit DplLexer(antlr4::CharStream *input);

  ~DplLexer() override;


      /**
      * Starts by pushing 0 onto the stack.
      * Calculate the indentation of the current line if EOF is set to 0 to add remaining dedent tokens
      * If current lines indentation > top of the stack, push it onto the stack and add an indent token
      * Else if the current lines indentation is < top of the stack, pop the stack and add dedent tokens until indentation >= top of the stack. 
      */
      void addDentTokens() {
          int indent = _input->LA(1) == EOF ? 0 : getIndentation();
          char nextChar = computeNextChar();

          if (indent > indentLevels.top()) {
              indentLevels.push(indent);
              pendingTokens.push(_factory->create({ this, _input }, Indent, "Indent", channel, tokenStartCharIndex, getCharIndex() - 1, tokenStartLine, tokenStartCharPositionInLine));
          } else if (indent < indentLevels.top() && nextChar != '\n') {
              while (indent < indentLevels.top()) {
                  indentLevels.pop();
                  pendingTokens.push(_factory->create({ this, _input }, Dedent, "Dedent", channel, tokenStartCharIndex, getCharIndex() - 1, tokenStartLine, tokenStartCharPositionInLine));
              }
          }
      }

      /**
      * Returns the next token in the queue if not empty
      * Otherwise, get next token from lexer and add it to the queue
      * If the queue is still empty, return the token otherwise return the next token in the queue
      */
      std::unique_ptr<antlr4::Token> nextToken() override {
          if (pendingTokens.empty()) {
              std::unique_ptr<antlr4::Token> next = antlr4::Lexer::nextToken();
              if (pendingTokens.empty()) {
                  return next;
              }

              pendingTokens.push(std::move(next));
          }

          std::unique_ptr<antlr4::Token> token = std::move(pendingTokens.front());
          pendingTokens.pop();

          return token;
      }

      /**
      * Call addDentTokens() at end of file to add missing dedent tokens
      */
      antlr4::Token* emitEOF() override {
          addDentTokens();
          return antlr4::Lexer::emitEOF();
      }


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

      std::stack<int> indentLevels = std::stack<int>({0});
      std::queue<std::unique_ptr<antlr4::Token>> pendingTokens;

      /**
      * Calculate indentation of current line
      */
      int getIndentation() {
          int length = 0;
          int i = 1;

          // Increment by 1 if space or 8 if tab
          while (_input->LA(i) == ' ' || _input->LA(i) == '\t') {
              length += _input->LA(i) == ' ' ? 1 : 8;
              ++i;
          }

          return length;
      }

      /**
      * Compute the next character in the input stream.
      * Auxiliary function used to make sure lines with only whitespace
      * are not getting spammed with dedent & indent tokens.
      */
      char computeNextChar() {
          char nextChar = _input->LA(1);
          int i = 1;

          while (nextChar == ' ' || nextChar == '\t') {
              ++i;
              nextChar = _input->LA(i);
          }

          return nextChar;
      }


  // Individual action functions triggered by action() above.
  void NewlineAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace dplgrammar
