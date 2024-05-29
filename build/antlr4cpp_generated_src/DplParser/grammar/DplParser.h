
// Generated from /home/vind/dpl/grammar/DplParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace dplgrammar {


class  DplParser : public antlr4::Parser {
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

  enum {
    RuleProg = 0, RuleProcdec = 1, RuleParams = 2, RuleStm = 3, RuleStms = 4, 
    RuleBlock = 5, RuleIfstm = 6, RuleElsestm = 7, RuleWhilestm = 8, RuleAssignstm = 9, 
    RuleFlowstm = 10, RuleReturnstm = 11, RuleOrexpr = 12, RuleAndexpr = 13, 
    RuleNotexpr = 14, RuleEqulexpr = 15, RuleCompexpr = 16, RulePlusexpr = 17, 
    RuleTablexpr = 18, RuleMultexpr = 19, RulePolaexpr = 20, RuleExpoexpr = 21, 
    RuleTerm = 22, RuleNumber = 23, RuleSubscript = 24, RuleList = 25, RuleTable = 26, 
    RuleColumn = 27, RuleIndex = 28, RuleHeaderindex = 29, RuleFiltering = 30, 
    RuleUnaryexpr = 31, RuleProccall = 32, RuleArgs = 33
  };

  explicit DplParser(antlr4::TokenStream *input);

  DplParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DplParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class ProcdecContext;
  class ParamsContext;
  class StmContext;
  class StmsContext;
  class BlockContext;
  class IfstmContext;
  class ElsestmContext;
  class WhilestmContext;
  class AssignstmContext;
  class FlowstmContext;
  class ReturnstmContext;
  class OrexprContext;
  class AndexprContext;
  class NotexprContext;
  class EqulexprContext;
  class CompexprContext;
  class PlusexprContext;
  class TablexprContext;
  class MultexprContext;
  class PolaexprContext;
  class ExpoexprContext;
  class TermContext;
  class NumberContext;
  class SubscriptContext;
  class ListContext;
  class TableContext;
  class ColumnContext;
  class IndexContext;
  class HeaderindexContext;
  class FilteringContext;
  class UnaryexprContext;
  class ProccallContext;
  class ArgsContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StmContext *> stm();
    StmContext* stm(size_t i);
    std::vector<ProcdecContext *> procdec();
    ProcdecContext* procdec(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Newline();
    antlr4::tree::TerminalNode* Newline(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  ProcdecContext : public antlr4::ParserRuleContext {
  public:
    ProcdecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Def();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *OpenPar();
    antlr4::tree::TerminalNode *ClosePar();
    antlr4::tree::TerminalNode *Colon();
    BlockContext *block();
    ParamsContext *params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcdecContext* procdec();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  StmContext : public antlr4::ParserRuleContext {
  public:
    StmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfstmContext *ifstm();
    WhilestmContext *whilestm();
    AssignstmContext *assignstm();
    FlowstmContext *flowstm();
    ReturnstmContext *returnstm();
    OrexprContext *orexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmContext* stm();

  class  StmsContext : public antlr4::ParserRuleContext {
  public:
    StmsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmContext *> stm();
    StmContext* stm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Newline();
    antlr4::tree::TerminalNode* Newline(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmsContext* stms();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Indent();
    StmsContext *stms();
    antlr4::tree::TerminalNode *Dedent();
    std::vector<antlr4::tree::TerminalNode *> Newline();
    antlr4::tree::TerminalNode* Newline(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  IfstmContext : public antlr4::ParserRuleContext {
  public:
    IfstmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *Colon();
    BlockContext *block();
    ElsestmContext *elsestm();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfstmContext* ifstm();

  class  ElsestmContext : public antlr4::ParserRuleContext {
  public:
    ElsestmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *Colon();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElsestmContext* elsestm();

  class  WhilestmContext : public antlr4::ParserRuleContext {
  public:
    WhilestmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *Colon();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhilestmContext* whilestm();

  class  AssignstmContext : public antlr4::ParserRuleContext {
  public:
    AssignstmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SubscriptContext *subscript();
    antlr4::tree::TerminalNode *Assign();
    OrexprContext *orexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignstmContext* assignstm();

  class  FlowstmContext : public antlr4::ParserRuleContext {
  public:
    FlowstmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Continue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlowstmContext* flowstm();

  class  ReturnstmContext : public antlr4::ParserRuleContext {
  public:
    ReturnstmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    OrexprContext *orexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnstmContext* returnstm();

  class  OrexprContext : public antlr4::ParserRuleContext {
  public:
    OrexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndexprContext *> andexpr();
    AndexprContext* andexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Or();
    antlr4::tree::TerminalNode* Or(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrexprContext* orexpr();

  class  AndexprContext : public antlr4::ParserRuleContext {
  public:
    AndexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NotexprContext *> notexpr();
    NotexprContext* notexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> And();
    antlr4::tree::TerminalNode* And(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndexprContext* andexpr();

  class  NotexprContext : public antlr4::ParserRuleContext {
  public:
    NotexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Not();
    NotexprContext *notexpr();
    EqulexprContext *equlexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotexprContext* notexpr();

  class  EqulexprContext : public antlr4::ParserRuleContext {
  public:
    EqulexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CompexprContext *> compexpr();
    CompexprContext* compexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Equal();
    antlr4::tree::TerminalNode* Equal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NotEqual();
    antlr4::tree::TerminalNode* NotEqual(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqulexprContext* equlexpr();

  class  CompexprContext : public antlr4::ParserRuleContext {
  public:
    CompexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PlusexprContext *> plusexpr();
    PlusexprContext* plusexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Greater();
    antlr4::tree::TerminalNode* Greater(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GreaterEqual();
    antlr4::tree::TerminalNode* GreaterEqual(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Less();
    antlr4::tree::TerminalNode* Less(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LessEqual();
    antlr4::tree::TerminalNode* LessEqual(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompexprContext* compexpr();

  class  PlusexprContext : public antlr4::ParserRuleContext {
  public:
    PlusexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TablexprContext *> tablexpr();
    TablexprContext* tablexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Plus();
    antlr4::tree::TerminalNode* Plus(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Minus();
    antlr4::tree::TerminalNode* Minus(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PlusexprContext* plusexpr();

  class  TablexprContext : public antlr4::ParserRuleContext {
  public:
    TablexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultexprContext *> multexpr();
    MultexprContext* multexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Union();
    antlr4::tree::TerminalNode* Union(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Intersection();
    antlr4::tree::TerminalNode* Intersection(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TablexprContext* tablexpr();

  class  MultexprContext : public antlr4::ParserRuleContext {
  public:
    MultexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PolaexprContext *> polaexpr();
    PolaexprContext* polaexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Star();
    antlr4::tree::TerminalNode* Star(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Slash();
    antlr4::tree::TerminalNode* Slash(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Mod();
    antlr4::tree::TerminalNode* Mod(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultexprContext* multexpr();

  class  PolaexprContext : public antlr4::ParserRuleContext {
  public:
    PolaexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PolaexprContext *polaexpr();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    ExpoexprContext *expoexpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PolaexprContext* polaexpr();

  class  ExpoexprContext : public antlr4::ParserRuleContext {
  public:
    ExpoexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Exponent();
    antlr4::tree::TerminalNode* Exponent(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpoexprContext* expoexpr();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenPar();
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *ClosePar();
    ListContext *list();
    TableContext *table();
    NumberContext *number();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *None();
    SubscriptContext *subscript();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Integer();
    antlr4::tree::TerminalNode *Float();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  SubscriptContext : public antlr4::ParserRuleContext {
  public:
    SubscriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<ProccallContext *> proccall();
    ProccallContext* proccall(size_t i);
    std::vector<HeaderindexContext *> headerindex();
    HeaderindexContext* headerindex(size_t i);
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);
    std::vector<FilteringContext *> filtering();
    FilteringContext* filtering(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubscriptContext* subscript();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenSquare();
    ArgsContext *args();
    antlr4::tree::TerminalNode *CloseSquare();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListContext* list();

  class  TableContext : public antlr4::ParserRuleContext {
  public:
    TableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenCurly();
    std::vector<ColumnContext *> column();
    ColumnContext* column(size_t i);
    antlr4::tree::TerminalNode *CloseCurly();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableContext* table();

  class  ColumnContext : public antlr4::ParserRuleContext {
  public:
    ColumnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrexprContext *> orexpr();
    OrexprContext* orexpr(size_t i);
    antlr4::tree::TerminalNode *Colon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnContext* column();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenSquare();
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *CloseSquare();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  HeaderindexContext : public antlr4::ParserRuleContext {
  public:
    HeaderindexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenSquare();
    antlr4::tree::TerminalNode *Dollar();
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *CloseSquare();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HeaderindexContext* headerindex();

  class  FilteringContext : public antlr4::ParserRuleContext {
  public:
    FilteringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenSquare();
    UnaryexprContext *unaryexpr();
    antlr4::tree::TerminalNode *CloseSquare();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FilteringContext* filtering();

  class  UnaryexprContext : public antlr4::ParserRuleContext {
  public:
    UnaryexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrexprContext *orexpr();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *GreaterEqual();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *LessEqual();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryexprContext* unaryexpr();

  class  ProccallContext : public antlr4::ParserRuleContext {
  public:
    ProccallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OpenPar();
    antlr4::tree::TerminalNode *ClosePar();
    ArgsContext *args();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProccallContext* proccall();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrexprContext *> orexpr();
    OrexprContext* orexpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace dplgrammar
