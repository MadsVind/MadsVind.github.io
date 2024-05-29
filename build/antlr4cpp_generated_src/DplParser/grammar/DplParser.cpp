
// Generated from /home/vind/dpl/grammar/DplParser.g4 by ANTLR 4.13.1


#include "DplParserVisitor.h"

#include "DplParser.h"


using namespace antlrcpp;
using namespace dplgrammar;

using namespace antlr4;

namespace {

struct DplParserStaticData final {
  DplParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DplParserStaticData(const DplParserStaticData&) = delete;
  DplParserStaticData(DplParserStaticData&&) = delete;
  DplParserStaticData& operator=(const DplParserStaticData&) = delete;
  DplParserStaticData& operator=(DplParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag dplparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DplParserStaticData *dplparserParserStaticData = nullptr;

void dplparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (dplparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(dplparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DplParserStaticData>(
    std::vector<std::string>{
      "prog", "procdec", "params", "stm", "stms", "block", "ifstm", "elsestm", 
      "whilestm", "assignstm", "flowstm", "returnstm", "orexpr", "andexpr", 
      "notexpr", "equlexpr", "compexpr", "plusexpr", "tablexpr", "multexpr", 
      "polaexpr", "expoexpr", "term", "number", "subscript", "list", "table", 
      "column", "index", "headerindex", "filtering", "unaryexpr", "proccall", 
      "args"
    },
    std::vector<std::string>{
      "", "", "", "'if'", "'else'", "'while'", "'break'", "'continue'", 
      "'return'", "'def'", "'('", "')'", "'{'", "'}'", "'['", "']'", "':'", 
      "','", "'$'", "'**'", "'+'", "'-'", "'*'", "'/'", "'%'", "'=='", "'!='", 
      "'<'", "'<='", "'>'", "'>='", "'and'", "'or'", "'not'", "'='", "'union'", 
      "'intersection'", "", "", "", "", "'None'"
    },
    std::vector<std::string>{
      "", "Indent", "Dedent", "If", "Else", "While", "Break", "Continue", 
      "Return", "Def", "OpenPar", "ClosePar", "OpenCurly", "CloseCurly", 
      "OpenSquare", "CloseSquare", "Colon", "Comma", "Dollar", "Exponent", 
      "Plus", "Minus", "Star", "Slash", "Mod", "Equal", "NotEqual", "Less", 
      "LessEqual", "Greater", "GreaterEqual", "And", "Or", "Not", "Assign", 
      "Union", "Intersection", "Integer", "Float", "Bool", "String", "None", 
      "Identifier", "Comment", "Newline", "Whitespace"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,322,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,3,0,71,8,
  	0,1,0,1,0,3,0,75,8,0,1,0,4,0,78,8,0,11,0,12,0,79,1,0,1,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,98,8,1,1,2,1,2,1,2,5,
  	2,103,8,2,10,2,12,2,106,9,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,114,8,3,1,4,1,
  	4,3,4,118,8,4,1,4,4,4,121,8,4,11,4,12,4,122,1,5,1,5,3,5,127,8,5,1,5,1,
  	5,1,5,3,5,132,8,5,1,6,1,6,1,6,1,6,1,6,3,6,139,8,6,1,7,1,7,1,7,1,7,1,8,
  	1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,3,11,159,8,11,
  	1,12,1,12,1,12,5,12,164,8,12,10,12,12,12,167,9,12,1,13,1,13,1,13,5,13,
  	172,8,13,10,13,12,13,175,9,13,1,14,1,14,1,14,3,14,180,8,14,1,15,1,15,
  	1,15,5,15,185,8,15,10,15,12,15,188,9,15,1,16,1,16,1,16,5,16,193,8,16,
  	10,16,12,16,196,9,16,1,17,1,17,1,17,5,17,201,8,17,10,17,12,17,204,9,17,
  	1,18,1,18,1,18,5,18,209,8,18,10,18,12,18,212,9,18,1,19,1,19,1,19,5,19,
  	217,8,19,10,19,12,19,220,9,19,1,20,1,20,1,20,3,20,225,8,20,1,21,1,21,
  	1,21,5,21,230,8,21,10,21,12,21,233,9,21,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,3,22,246,8,22,1,23,1,23,1,23,3,23,251,8,23,1,
  	24,1,24,1,24,1,24,1,24,5,24,258,8,24,10,24,12,24,261,9,24,1,25,1,25,1,
  	25,1,25,1,25,1,25,3,25,269,8,25,1,26,1,26,1,26,1,26,5,26,275,8,26,10,
  	26,12,26,278,9,26,1,26,1,26,1,26,1,26,3,26,284,8,26,1,27,1,27,1,27,1,
  	27,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,
  	31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,32,3,32,312,8,32,1,33,1,33,1,
  	33,5,33,317,8,33,10,33,12,33,320,9,33,1,33,0,0,34,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,
  	62,64,66,0,8,1,0,6,7,1,0,25,26,1,0,27,30,1,0,20,21,1,0,35,36,1,0,22,24,
  	1,0,37,38,1,0,25,30,333,0,77,1,0,0,0,2,97,1,0,0,0,4,99,1,0,0,0,6,113,
  	1,0,0,0,8,120,1,0,0,0,10,124,1,0,0,0,12,133,1,0,0,0,14,140,1,0,0,0,16,
  	144,1,0,0,0,18,149,1,0,0,0,20,153,1,0,0,0,22,158,1,0,0,0,24,160,1,0,0,
  	0,26,168,1,0,0,0,28,179,1,0,0,0,30,181,1,0,0,0,32,189,1,0,0,0,34,197,
  	1,0,0,0,36,205,1,0,0,0,38,213,1,0,0,0,40,224,1,0,0,0,42,226,1,0,0,0,44,
  	245,1,0,0,0,46,250,1,0,0,0,48,252,1,0,0,0,50,268,1,0,0,0,52,283,1,0,0,
  	0,54,285,1,0,0,0,56,289,1,0,0,0,58,293,1,0,0,0,60,298,1,0,0,0,62,302,
  	1,0,0,0,64,311,1,0,0,0,66,313,1,0,0,0,68,70,3,6,3,0,69,71,5,44,0,0,70,
  	69,1,0,0,0,70,71,1,0,0,0,71,78,1,0,0,0,72,74,3,2,1,0,73,75,5,44,0,0,74,
  	73,1,0,0,0,74,75,1,0,0,0,75,78,1,0,0,0,76,78,5,44,0,0,77,68,1,0,0,0,77,
  	72,1,0,0,0,77,76,1,0,0,0,78,79,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,
  	81,1,0,0,0,81,82,5,0,0,1,82,1,1,0,0,0,83,84,5,9,0,0,84,85,5,42,0,0,85,
  	86,5,10,0,0,86,87,5,11,0,0,87,88,5,16,0,0,88,98,3,10,5,0,89,90,5,9,0,
  	0,90,91,5,42,0,0,91,92,5,10,0,0,92,93,3,4,2,0,93,94,5,11,0,0,94,95,5,
  	16,0,0,95,96,3,10,5,0,96,98,1,0,0,0,97,83,1,0,0,0,97,89,1,0,0,0,98,3,
  	1,0,0,0,99,104,5,42,0,0,100,101,5,17,0,0,101,103,5,42,0,0,102,100,1,0,
  	0,0,103,106,1,0,0,0,104,102,1,0,0,0,104,105,1,0,0,0,105,5,1,0,0,0,106,
  	104,1,0,0,0,107,114,3,12,6,0,108,114,3,16,8,0,109,114,3,18,9,0,110,114,
  	3,20,10,0,111,114,3,22,11,0,112,114,3,24,12,0,113,107,1,0,0,0,113,108,
  	1,0,0,0,113,109,1,0,0,0,113,110,1,0,0,0,113,111,1,0,0,0,113,112,1,0,0,
  	0,114,7,1,0,0,0,115,117,3,6,3,0,116,118,5,44,0,0,117,116,1,0,0,0,117,
  	118,1,0,0,0,118,121,1,0,0,0,119,121,5,44,0,0,120,115,1,0,0,0,120,119,
  	1,0,0,0,121,122,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,9,1,0,0,0,
  	124,126,5,1,0,0,125,127,5,44,0,0,126,125,1,0,0,0,126,127,1,0,0,0,127,
  	128,1,0,0,0,128,129,3,8,4,0,129,131,5,2,0,0,130,132,5,44,0,0,131,130,
  	1,0,0,0,131,132,1,0,0,0,132,11,1,0,0,0,133,134,5,3,0,0,134,135,3,24,12,
  	0,135,136,5,16,0,0,136,138,3,10,5,0,137,139,3,14,7,0,138,137,1,0,0,0,
  	138,139,1,0,0,0,139,13,1,0,0,0,140,141,5,4,0,0,141,142,5,16,0,0,142,143,
  	3,10,5,0,143,15,1,0,0,0,144,145,5,5,0,0,145,146,3,24,12,0,146,147,5,16,
  	0,0,147,148,3,10,5,0,148,17,1,0,0,0,149,150,3,48,24,0,150,151,5,34,0,
  	0,151,152,3,24,12,0,152,19,1,0,0,0,153,154,7,0,0,0,154,21,1,0,0,0,155,
  	156,5,8,0,0,156,159,3,24,12,0,157,159,5,8,0,0,158,155,1,0,0,0,158,157,
  	1,0,0,0,159,23,1,0,0,0,160,165,3,26,13,0,161,162,5,32,0,0,162,164,3,26,
  	13,0,163,161,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,
  	166,25,1,0,0,0,167,165,1,0,0,0,168,173,3,28,14,0,169,170,5,31,0,0,170,
  	172,3,28,14,0,171,169,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,173,174,
  	1,0,0,0,174,27,1,0,0,0,175,173,1,0,0,0,176,177,5,33,0,0,177,180,3,28,
  	14,0,178,180,3,30,15,0,179,176,1,0,0,0,179,178,1,0,0,0,180,29,1,0,0,0,
  	181,186,3,32,16,0,182,183,7,1,0,0,183,185,3,32,16,0,184,182,1,0,0,0,185,
  	188,1,0,0,0,186,184,1,0,0,0,186,187,1,0,0,0,187,31,1,0,0,0,188,186,1,
  	0,0,0,189,194,3,34,17,0,190,191,7,2,0,0,191,193,3,34,17,0,192,190,1,0,
  	0,0,193,196,1,0,0,0,194,192,1,0,0,0,194,195,1,0,0,0,195,33,1,0,0,0,196,
  	194,1,0,0,0,197,202,3,36,18,0,198,199,7,3,0,0,199,201,3,36,18,0,200,198,
  	1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,35,1,0,0,
  	0,204,202,1,0,0,0,205,210,3,38,19,0,206,207,7,4,0,0,207,209,3,38,19,0,
  	208,206,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,0,0,211,37,
  	1,0,0,0,212,210,1,0,0,0,213,218,3,40,20,0,214,215,7,5,0,0,215,217,3,40,
  	20,0,216,214,1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,0,218,219,1,0,0,0,
  	219,39,1,0,0,0,220,218,1,0,0,0,221,222,7,3,0,0,222,225,3,40,20,0,223,
  	225,3,42,21,0,224,221,1,0,0,0,224,223,1,0,0,0,225,41,1,0,0,0,226,231,
  	3,44,22,0,227,228,5,19,0,0,228,230,3,44,22,0,229,227,1,0,0,0,230,233,
  	1,0,0,0,231,229,1,0,0,0,231,232,1,0,0,0,232,43,1,0,0,0,233,231,1,0,0,
  	0,234,235,5,10,0,0,235,236,3,24,12,0,236,237,5,11,0,0,237,246,1,0,0,0,
  	238,246,3,50,25,0,239,246,3,52,26,0,240,246,3,46,23,0,241,246,5,39,0,
  	0,242,246,5,40,0,0,243,246,5,41,0,0,244,246,3,48,24,0,245,234,1,0,0,0,
  	245,238,1,0,0,0,245,239,1,0,0,0,245,240,1,0,0,0,245,241,1,0,0,0,245,242,
  	1,0,0,0,245,243,1,0,0,0,245,244,1,0,0,0,246,45,1,0,0,0,247,248,7,3,0,
  	0,248,251,3,46,23,0,249,251,7,6,0,0,250,247,1,0,0,0,250,249,1,0,0,0,251,
  	47,1,0,0,0,252,259,5,42,0,0,253,258,3,64,32,0,254,258,3,58,29,0,255,258,
  	3,56,28,0,256,258,3,60,30,0,257,253,1,0,0,0,257,254,1,0,0,0,257,255,1,
  	0,0,0,257,256,1,0,0,0,258,261,1,0,0,0,259,257,1,0,0,0,259,260,1,0,0,0,
  	260,49,1,0,0,0,261,259,1,0,0,0,262,263,5,14,0,0,263,264,3,66,33,0,264,
  	265,5,15,0,0,265,269,1,0,0,0,266,267,5,14,0,0,267,269,5,15,0,0,268,262,
  	1,0,0,0,268,266,1,0,0,0,269,51,1,0,0,0,270,271,5,12,0,0,271,276,3,54,
  	27,0,272,273,5,17,0,0,273,275,3,54,27,0,274,272,1,0,0,0,275,278,1,0,0,
  	0,276,274,1,0,0,0,276,277,1,0,0,0,277,279,1,0,0,0,278,276,1,0,0,0,279,
  	280,5,13,0,0,280,284,1,0,0,0,281,282,5,12,0,0,282,284,5,13,0,0,283,270,
  	1,0,0,0,283,281,1,0,0,0,284,53,1,0,0,0,285,286,3,24,12,0,286,287,5,16,
  	0,0,287,288,3,24,12,0,288,55,1,0,0,0,289,290,5,14,0,0,290,291,3,24,12,
  	0,291,292,5,15,0,0,292,57,1,0,0,0,293,294,5,14,0,0,294,295,5,18,0,0,295,
  	296,3,24,12,0,296,297,5,15,0,0,297,59,1,0,0,0,298,299,5,14,0,0,299,300,
  	3,62,31,0,300,301,5,15,0,0,301,61,1,0,0,0,302,303,7,7,0,0,303,304,3,24,
  	12,0,304,63,1,0,0,0,305,306,5,10,0,0,306,312,5,11,0,0,307,308,5,10,0,
  	0,308,309,3,66,33,0,309,310,5,11,0,0,310,312,1,0,0,0,311,305,1,0,0,0,
  	311,307,1,0,0,0,312,65,1,0,0,0,313,318,3,24,12,0,314,315,5,17,0,0,315,
  	317,3,24,12,0,316,314,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,0,318,319,
  	1,0,0,0,319,67,1,0,0,0,320,318,1,0,0,0,33,70,74,77,79,97,104,113,117,
  	120,122,126,131,138,158,165,173,179,186,194,202,210,218,224,231,245,250,
  	257,259,268,276,283,311,318
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  dplparserParserStaticData = staticData.release();
}

}

DplParser::DplParser(TokenStream *input) : DplParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DplParser::DplParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DplParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *dplparserParserStaticData->atn, dplparserParserStaticData->decisionToDFA, dplparserParserStaticData->sharedContextCache, options);
}

DplParser::~DplParser() {
  delete _interpreter;
}

const atn::ATN& DplParser::getATN() const {
  return *dplparserParserStaticData->atn;
}

std::string DplParser::getGrammarFileName() const {
  return "DplParser.g4";
}

const std::vector<std::string>& DplParser::getRuleNames() const {
  return dplparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& DplParser::getVocabulary() const {
  return dplparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DplParser::getSerializedATN() const {
  return dplparserParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

DplParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ProgContext::EOF() {
  return getToken(DplParser::EOF, 0);
}

std::vector<DplParser::StmContext *> DplParser::ProgContext::stm() {
  return getRuleContexts<DplParser::StmContext>();
}

DplParser::StmContext* DplParser::ProgContext::stm(size_t i) {
  return getRuleContext<DplParser::StmContext>(i);
}

std::vector<DplParser::ProcdecContext *> DplParser::ProgContext::procdec() {
  return getRuleContexts<DplParser::ProcdecContext>();
}

DplParser::ProcdecContext* DplParser::ProgContext::procdec(size_t i) {
  return getRuleContext<DplParser::ProcdecContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::ProgContext::Newline() {
  return getTokens(DplParser::Newline);
}

tree::TerminalNode* DplParser::ProgContext::Newline(size_t i) {
  return getToken(DplParser::Newline, i);
}


size_t DplParser::ProgContext::getRuleIndex() const {
  return DplParser::RuleProg;
}


std::any DplParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ProgContext* DplParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, DplParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(77);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DplParser::If:
        case DplParser::While:
        case DplParser::Break:
        case DplParser::Continue:
        case DplParser::Return:
        case DplParser::OpenPar:
        case DplParser::OpenCurly:
        case DplParser::OpenSquare:
        case DplParser::Plus:
        case DplParser::Minus:
        case DplParser::Not:
        case DplParser::Integer:
        case DplParser::Float:
        case DplParser::Bool:
        case DplParser::String:
        case DplParser::None:
        case DplParser::Identifier: {
          setState(68);
          stm();
          setState(70);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
          case 1: {
            setState(69);
            match(DplParser::Newline);
            break;
          }

          default:
            break;
          }
          break;
        }

        case DplParser::Def: {
          setState(72);
          procdec();
          setState(74);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
          case 1: {
            setState(73);
            match(DplParser::Newline);
            break;
          }

          default:
            break;
          }
          break;
        }

        case DplParser::Newline: {
          setState(76);
          match(DplParser::Newline);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(79); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 26259433215976) != 0));
    setState(81);
    match(DplParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcdecContext ------------------------------------------------------------------

DplParser::ProcdecContext::ProcdecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ProcdecContext::Def() {
  return getToken(DplParser::Def, 0);
}

tree::TerminalNode* DplParser::ProcdecContext::Identifier() {
  return getToken(DplParser::Identifier, 0);
}

tree::TerminalNode* DplParser::ProcdecContext::OpenPar() {
  return getToken(DplParser::OpenPar, 0);
}

tree::TerminalNode* DplParser::ProcdecContext::ClosePar() {
  return getToken(DplParser::ClosePar, 0);
}

tree::TerminalNode* DplParser::ProcdecContext::Colon() {
  return getToken(DplParser::Colon, 0);
}

DplParser::BlockContext* DplParser::ProcdecContext::block() {
  return getRuleContext<DplParser::BlockContext>(0);
}

DplParser::ParamsContext* DplParser::ProcdecContext::params() {
  return getRuleContext<DplParser::ParamsContext>(0);
}


size_t DplParser::ProcdecContext::getRuleIndex() const {
  return DplParser::RuleProcdec;
}


std::any DplParser::ProcdecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitProcdec(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ProcdecContext* DplParser::procdec() {
  ProcdecContext *_localctx = _tracker.createInstance<ProcdecContext>(_ctx, getState());
  enterRule(_localctx, 2, DplParser::RuleProcdec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(83);
      match(DplParser::Def);
      setState(84);
      match(DplParser::Identifier);
      setState(85);
      match(DplParser::OpenPar);
      setState(86);
      match(DplParser::ClosePar);
      setState(87);
      match(DplParser::Colon);
      setState(88);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(DplParser::Def);
      setState(90);
      match(DplParser::Identifier);
      setState(91);
      match(DplParser::OpenPar);
      setState(92);
      params();
      setState(93);
      match(DplParser::ClosePar);
      setState(94);
      match(DplParser::Colon);
      setState(95);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

DplParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DplParser::ParamsContext::Identifier() {
  return getTokens(DplParser::Identifier);
}

tree::TerminalNode* DplParser::ParamsContext::Identifier(size_t i) {
  return getToken(DplParser::Identifier, i);
}

std::vector<tree::TerminalNode *> DplParser::ParamsContext::Comma() {
  return getTokens(DplParser::Comma);
}

tree::TerminalNode* DplParser::ParamsContext::Comma(size_t i) {
  return getToken(DplParser::Comma, i);
}


size_t DplParser::ParamsContext::getRuleIndex() const {
  return DplParser::RuleParams;
}


std::any DplParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ParamsContext* DplParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 4, DplParser::RuleParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(DplParser::Identifier);
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Comma) {
      setState(100);
      match(DplParser::Comma);
      setState(101);
      match(DplParser::Identifier);
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmContext ------------------------------------------------------------------

DplParser::StmContext::StmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DplParser::IfstmContext* DplParser::StmContext::ifstm() {
  return getRuleContext<DplParser::IfstmContext>(0);
}

DplParser::WhilestmContext* DplParser::StmContext::whilestm() {
  return getRuleContext<DplParser::WhilestmContext>(0);
}

DplParser::AssignstmContext* DplParser::StmContext::assignstm() {
  return getRuleContext<DplParser::AssignstmContext>(0);
}

DplParser::FlowstmContext* DplParser::StmContext::flowstm() {
  return getRuleContext<DplParser::FlowstmContext>(0);
}

DplParser::ReturnstmContext* DplParser::StmContext::returnstm() {
  return getRuleContext<DplParser::ReturnstmContext>(0);
}

DplParser::OrexprContext* DplParser::StmContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}


size_t DplParser::StmContext::getRuleIndex() const {
  return DplParser::RuleStm;
}


std::any DplParser::StmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitStm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::StmContext* DplParser::stm() {
  StmContext *_localctx = _tracker.createInstance<StmContext>(_ctx, getState());
  enterRule(_localctx, 6, DplParser::RuleStm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      ifstm();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(108);
      whilestm();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109);
      assignstm();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(110);
      flowstm();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(111);
      returnstm();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(112);
      orexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmsContext ------------------------------------------------------------------

DplParser::StmsContext::StmsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::StmContext *> DplParser::StmsContext::stm() {
  return getRuleContexts<DplParser::StmContext>();
}

DplParser::StmContext* DplParser::StmsContext::stm(size_t i) {
  return getRuleContext<DplParser::StmContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::StmsContext::Newline() {
  return getTokens(DplParser::Newline);
}

tree::TerminalNode* DplParser::StmsContext::Newline(size_t i) {
  return getToken(DplParser::Newline, i);
}


size_t DplParser::StmsContext::getRuleIndex() const {
  return DplParser::RuleStms;
}


std::any DplParser::StmsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitStms(this);
  else
    return visitor->visitChildren(this);
}

DplParser::StmsContext* DplParser::stms() {
  StmsContext *_localctx = _tracker.createInstance<StmsContext>(_ctx, getState());
  enterRule(_localctx, 8, DplParser::RuleStms);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(120);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DplParser::If:
        case DplParser::While:
        case DplParser::Break:
        case DplParser::Continue:
        case DplParser::Return:
        case DplParser::OpenPar:
        case DplParser::OpenCurly:
        case DplParser::OpenSquare:
        case DplParser::Plus:
        case DplParser::Minus:
        case DplParser::Not:
        case DplParser::Integer:
        case DplParser::Float:
        case DplParser::Bool:
        case DplParser::String:
        case DplParser::None:
        case DplParser::Identifier: {
          setState(115);
          stm();
          setState(117);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
          case 1: {
            setState(116);
            match(DplParser::Newline);
            break;
          }

          default:
            break;
          }
          break;
        }

        case DplParser::Newline: {
          setState(119);
          match(DplParser::Newline);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(122); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 26259433215464) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

DplParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::BlockContext::Indent() {
  return getToken(DplParser::Indent, 0);
}

DplParser::StmsContext* DplParser::BlockContext::stms() {
  return getRuleContext<DplParser::StmsContext>(0);
}

tree::TerminalNode* DplParser::BlockContext::Dedent() {
  return getToken(DplParser::Dedent, 0);
}

std::vector<tree::TerminalNode *> DplParser::BlockContext::Newline() {
  return getTokens(DplParser::Newline);
}

tree::TerminalNode* DplParser::BlockContext::Newline(size_t i) {
  return getToken(DplParser::Newline, i);
}


size_t DplParser::BlockContext::getRuleIndex() const {
  return DplParser::RuleBlock;
}


std::any DplParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

DplParser::BlockContext* DplParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 10, DplParser::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    match(DplParser::Indent);
    setState(126);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(125);
      match(DplParser::Newline);
      break;
    }

    default:
      break;
    }
    setState(128);
    stms();
    setState(129);
    match(DplParser::Dedent);
    setState(131);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(130);
      match(DplParser::Newline);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstmContext ------------------------------------------------------------------

DplParser::IfstmContext::IfstmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::IfstmContext::If() {
  return getToken(DplParser::If, 0);
}

DplParser::OrexprContext* DplParser::IfstmContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::IfstmContext::Colon() {
  return getToken(DplParser::Colon, 0);
}

DplParser::BlockContext* DplParser::IfstmContext::block() {
  return getRuleContext<DplParser::BlockContext>(0);
}

DplParser::ElsestmContext* DplParser::IfstmContext::elsestm() {
  return getRuleContext<DplParser::ElsestmContext>(0);
}


size_t DplParser::IfstmContext::getRuleIndex() const {
  return DplParser::RuleIfstm;
}


std::any DplParser::IfstmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitIfstm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::IfstmContext* DplParser::ifstm() {
  IfstmContext *_localctx = _tracker.createInstance<IfstmContext>(_ctx, getState());
  enterRule(_localctx, 12, DplParser::RuleIfstm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(DplParser::If);
    setState(134);
    orexpr();
    setState(135);
    match(DplParser::Colon);
    setState(136);
    block();
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DplParser::Else) {
      setState(137);
      elsestm();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElsestmContext ------------------------------------------------------------------

DplParser::ElsestmContext::ElsestmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ElsestmContext::Else() {
  return getToken(DplParser::Else, 0);
}

tree::TerminalNode* DplParser::ElsestmContext::Colon() {
  return getToken(DplParser::Colon, 0);
}

DplParser::BlockContext* DplParser::ElsestmContext::block() {
  return getRuleContext<DplParser::BlockContext>(0);
}


size_t DplParser::ElsestmContext::getRuleIndex() const {
  return DplParser::RuleElsestm;
}


std::any DplParser::ElsestmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitElsestm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ElsestmContext* DplParser::elsestm() {
  ElsestmContext *_localctx = _tracker.createInstance<ElsestmContext>(_ctx, getState());
  enterRule(_localctx, 14, DplParser::RuleElsestm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(DplParser::Else);
    setState(141);
    match(DplParser::Colon);
    setState(142);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhilestmContext ------------------------------------------------------------------

DplParser::WhilestmContext::WhilestmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::WhilestmContext::While() {
  return getToken(DplParser::While, 0);
}

DplParser::OrexprContext* DplParser::WhilestmContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::WhilestmContext::Colon() {
  return getToken(DplParser::Colon, 0);
}

DplParser::BlockContext* DplParser::WhilestmContext::block() {
  return getRuleContext<DplParser::BlockContext>(0);
}


size_t DplParser::WhilestmContext::getRuleIndex() const {
  return DplParser::RuleWhilestm;
}


std::any DplParser::WhilestmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitWhilestm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::WhilestmContext* DplParser::whilestm() {
  WhilestmContext *_localctx = _tracker.createInstance<WhilestmContext>(_ctx, getState());
  enterRule(_localctx, 16, DplParser::RuleWhilestm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(DplParser::While);
    setState(145);
    orexpr();
    setState(146);
    match(DplParser::Colon);
    setState(147);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignstmContext ------------------------------------------------------------------

DplParser::AssignstmContext::AssignstmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DplParser::SubscriptContext* DplParser::AssignstmContext::subscript() {
  return getRuleContext<DplParser::SubscriptContext>(0);
}

tree::TerminalNode* DplParser::AssignstmContext::Assign() {
  return getToken(DplParser::Assign, 0);
}

DplParser::OrexprContext* DplParser::AssignstmContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}


size_t DplParser::AssignstmContext::getRuleIndex() const {
  return DplParser::RuleAssignstm;
}


std::any DplParser::AssignstmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitAssignstm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::AssignstmContext* DplParser::assignstm() {
  AssignstmContext *_localctx = _tracker.createInstance<AssignstmContext>(_ctx, getState());
  enterRule(_localctx, 18, DplParser::RuleAssignstm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    subscript();
    setState(150);
    match(DplParser::Assign);
    setState(151);
    orexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlowstmContext ------------------------------------------------------------------

DplParser::FlowstmContext::FlowstmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::FlowstmContext::Break() {
  return getToken(DplParser::Break, 0);
}

tree::TerminalNode* DplParser::FlowstmContext::Continue() {
  return getToken(DplParser::Continue, 0);
}


size_t DplParser::FlowstmContext::getRuleIndex() const {
  return DplParser::RuleFlowstm;
}


std::any DplParser::FlowstmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitFlowstm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::FlowstmContext* DplParser::flowstm() {
  FlowstmContext *_localctx = _tracker.createInstance<FlowstmContext>(_ctx, getState());
  enterRule(_localctx, 20, DplParser::RuleFlowstm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    _la = _input->LA(1);
    if (!(_la == DplParser::Break

    || _la == DplParser::Continue)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnstmContext ------------------------------------------------------------------

DplParser::ReturnstmContext::ReturnstmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ReturnstmContext::Return() {
  return getToken(DplParser::Return, 0);
}

DplParser::OrexprContext* DplParser::ReturnstmContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}


size_t DplParser::ReturnstmContext::getRuleIndex() const {
  return DplParser::RuleReturnstm;
}


std::any DplParser::ReturnstmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitReturnstm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ReturnstmContext* DplParser::returnstm() {
  ReturnstmContext *_localctx = _tracker.createInstance<ReturnstmContext>(_ctx, getState());
  enterRule(_localctx, 22, DplParser::RuleReturnstm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(155);
      match(DplParser::Return);
      setState(156);
      orexpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      match(DplParser::Return);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrexprContext ------------------------------------------------------------------

DplParser::OrexprContext::OrexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::AndexprContext *> DplParser::OrexprContext::andexpr() {
  return getRuleContexts<DplParser::AndexprContext>();
}

DplParser::AndexprContext* DplParser::OrexprContext::andexpr(size_t i) {
  return getRuleContext<DplParser::AndexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::OrexprContext::Or() {
  return getTokens(DplParser::Or);
}

tree::TerminalNode* DplParser::OrexprContext::Or(size_t i) {
  return getToken(DplParser::Or, i);
}


size_t DplParser::OrexprContext::getRuleIndex() const {
  return DplParser::RuleOrexpr;
}


std::any DplParser::OrexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitOrexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::OrexprContext* DplParser::orexpr() {
  OrexprContext *_localctx = _tracker.createInstance<OrexprContext>(_ctx, getState());
  enterRule(_localctx, 24, DplParser::RuleOrexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    andexpr();
    setState(165);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Or) {
      setState(161);
      match(DplParser::Or);
      setState(162);
      andexpr();
      setState(167);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndexprContext ------------------------------------------------------------------

DplParser::AndexprContext::AndexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::NotexprContext *> DplParser::AndexprContext::notexpr() {
  return getRuleContexts<DplParser::NotexprContext>();
}

DplParser::NotexprContext* DplParser::AndexprContext::notexpr(size_t i) {
  return getRuleContext<DplParser::NotexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::AndexprContext::And() {
  return getTokens(DplParser::And);
}

tree::TerminalNode* DplParser::AndexprContext::And(size_t i) {
  return getToken(DplParser::And, i);
}


size_t DplParser::AndexprContext::getRuleIndex() const {
  return DplParser::RuleAndexpr;
}


std::any DplParser::AndexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitAndexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::AndexprContext* DplParser::andexpr() {
  AndexprContext *_localctx = _tracker.createInstance<AndexprContext>(_ctx, getState());
  enterRule(_localctx, 26, DplParser::RuleAndexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    notexpr();
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::And) {
      setState(169);
      match(DplParser::And);
      setState(170);
      notexpr();
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotexprContext ------------------------------------------------------------------

DplParser::NotexprContext::NotexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::NotexprContext::Not() {
  return getToken(DplParser::Not, 0);
}

DplParser::NotexprContext* DplParser::NotexprContext::notexpr() {
  return getRuleContext<DplParser::NotexprContext>(0);
}

DplParser::EqulexprContext* DplParser::NotexprContext::equlexpr() {
  return getRuleContext<DplParser::EqulexprContext>(0);
}


size_t DplParser::NotexprContext::getRuleIndex() const {
  return DplParser::RuleNotexpr;
}


std::any DplParser::NotexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitNotexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::NotexprContext* DplParser::notexpr() {
  NotexprContext *_localctx = _tracker.createInstance<NotexprContext>(_ctx, getState());
  enterRule(_localctx, 28, DplParser::RuleNotexpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DplParser::Not: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        match(DplParser::Not);
        setState(177);
        notexpr();
        break;
      }

      case DplParser::OpenPar:
      case DplParser::OpenCurly:
      case DplParser::OpenSquare:
      case DplParser::Plus:
      case DplParser::Minus:
      case DplParser::Integer:
      case DplParser::Float:
      case DplParser::Bool:
      case DplParser::String:
      case DplParser::None:
      case DplParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(178);
        equlexpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqulexprContext ------------------------------------------------------------------

DplParser::EqulexprContext::EqulexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::CompexprContext *> DplParser::EqulexprContext::compexpr() {
  return getRuleContexts<DplParser::CompexprContext>();
}

DplParser::CompexprContext* DplParser::EqulexprContext::compexpr(size_t i) {
  return getRuleContext<DplParser::CompexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::EqulexprContext::Equal() {
  return getTokens(DplParser::Equal);
}

tree::TerminalNode* DplParser::EqulexprContext::Equal(size_t i) {
  return getToken(DplParser::Equal, i);
}

std::vector<tree::TerminalNode *> DplParser::EqulexprContext::NotEqual() {
  return getTokens(DplParser::NotEqual);
}

tree::TerminalNode* DplParser::EqulexprContext::NotEqual(size_t i) {
  return getToken(DplParser::NotEqual, i);
}


size_t DplParser::EqulexprContext::getRuleIndex() const {
  return DplParser::RuleEqulexpr;
}


std::any DplParser::EqulexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitEqulexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::EqulexprContext* DplParser::equlexpr() {
  EqulexprContext *_localctx = _tracker.createInstance<EqulexprContext>(_ctx, getState());
  enterRule(_localctx, 30, DplParser::RuleEqulexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    compexpr();
    setState(186);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Equal

    || _la == DplParser::NotEqual) {
      setState(182);
      _la = _input->LA(1);
      if (!(_la == DplParser::Equal

      || _la == DplParser::NotEqual)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(183);
      compexpr();
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompexprContext ------------------------------------------------------------------

DplParser::CompexprContext::CompexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::PlusexprContext *> DplParser::CompexprContext::plusexpr() {
  return getRuleContexts<DplParser::PlusexprContext>();
}

DplParser::PlusexprContext* DplParser::CompexprContext::plusexpr(size_t i) {
  return getRuleContext<DplParser::PlusexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::CompexprContext::Greater() {
  return getTokens(DplParser::Greater);
}

tree::TerminalNode* DplParser::CompexprContext::Greater(size_t i) {
  return getToken(DplParser::Greater, i);
}

std::vector<tree::TerminalNode *> DplParser::CompexprContext::GreaterEqual() {
  return getTokens(DplParser::GreaterEqual);
}

tree::TerminalNode* DplParser::CompexprContext::GreaterEqual(size_t i) {
  return getToken(DplParser::GreaterEqual, i);
}

std::vector<tree::TerminalNode *> DplParser::CompexprContext::Less() {
  return getTokens(DplParser::Less);
}

tree::TerminalNode* DplParser::CompexprContext::Less(size_t i) {
  return getToken(DplParser::Less, i);
}

std::vector<tree::TerminalNode *> DplParser::CompexprContext::LessEqual() {
  return getTokens(DplParser::LessEqual);
}

tree::TerminalNode* DplParser::CompexprContext::LessEqual(size_t i) {
  return getToken(DplParser::LessEqual, i);
}


size_t DplParser::CompexprContext::getRuleIndex() const {
  return DplParser::RuleCompexpr;
}


std::any DplParser::CompexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitCompexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::CompexprContext* DplParser::compexpr() {
  CompexprContext *_localctx = _tracker.createInstance<CompexprContext>(_ctx, getState());
  enterRule(_localctx, 32, DplParser::RuleCompexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    plusexpr();
    setState(194);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2013265920) != 0)) {
      setState(190);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2013265920) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(191);
      plusexpr();
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlusexprContext ------------------------------------------------------------------

DplParser::PlusexprContext::PlusexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::TablexprContext *> DplParser::PlusexprContext::tablexpr() {
  return getRuleContexts<DplParser::TablexprContext>();
}

DplParser::TablexprContext* DplParser::PlusexprContext::tablexpr(size_t i) {
  return getRuleContext<DplParser::TablexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::PlusexprContext::Plus() {
  return getTokens(DplParser::Plus);
}

tree::TerminalNode* DplParser::PlusexprContext::Plus(size_t i) {
  return getToken(DplParser::Plus, i);
}

std::vector<tree::TerminalNode *> DplParser::PlusexprContext::Minus() {
  return getTokens(DplParser::Minus);
}

tree::TerminalNode* DplParser::PlusexprContext::Minus(size_t i) {
  return getToken(DplParser::Minus, i);
}


size_t DplParser::PlusexprContext::getRuleIndex() const {
  return DplParser::RulePlusexpr;
}


std::any DplParser::PlusexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitPlusexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::PlusexprContext* DplParser::plusexpr() {
  PlusexprContext *_localctx = _tracker.createInstance<PlusexprContext>(_ctx, getState());
  enterRule(_localctx, 34, DplParser::RulePlusexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(197);
    tablexpr();
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(198);
        _la = _input->LA(1);
        if (!(_la == DplParser::Plus

        || _la == DplParser::Minus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(199);
        tablexpr(); 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TablexprContext ------------------------------------------------------------------

DplParser::TablexprContext::TablexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::MultexprContext *> DplParser::TablexprContext::multexpr() {
  return getRuleContexts<DplParser::MultexprContext>();
}

DplParser::MultexprContext* DplParser::TablexprContext::multexpr(size_t i) {
  return getRuleContext<DplParser::MultexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::TablexprContext::Union() {
  return getTokens(DplParser::Union);
}

tree::TerminalNode* DplParser::TablexprContext::Union(size_t i) {
  return getToken(DplParser::Union, i);
}

std::vector<tree::TerminalNode *> DplParser::TablexprContext::Intersection() {
  return getTokens(DplParser::Intersection);
}

tree::TerminalNode* DplParser::TablexprContext::Intersection(size_t i) {
  return getToken(DplParser::Intersection, i);
}


size_t DplParser::TablexprContext::getRuleIndex() const {
  return DplParser::RuleTablexpr;
}


std::any DplParser::TablexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitTablexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::TablexprContext* DplParser::tablexpr() {
  TablexprContext *_localctx = _tracker.createInstance<TablexprContext>(_ctx, getState());
  enterRule(_localctx, 36, DplParser::RuleTablexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    multexpr();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Union

    || _la == DplParser::Intersection) {
      setState(206);
      _la = _input->LA(1);
      if (!(_la == DplParser::Union

      || _la == DplParser::Intersection)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(207);
      multexpr();
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultexprContext ------------------------------------------------------------------

DplParser::MultexprContext::MultexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::PolaexprContext *> DplParser::MultexprContext::polaexpr() {
  return getRuleContexts<DplParser::PolaexprContext>();
}

DplParser::PolaexprContext* DplParser::MultexprContext::polaexpr(size_t i) {
  return getRuleContext<DplParser::PolaexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::MultexprContext::Star() {
  return getTokens(DplParser::Star);
}

tree::TerminalNode* DplParser::MultexprContext::Star(size_t i) {
  return getToken(DplParser::Star, i);
}

std::vector<tree::TerminalNode *> DplParser::MultexprContext::Slash() {
  return getTokens(DplParser::Slash);
}

tree::TerminalNode* DplParser::MultexprContext::Slash(size_t i) {
  return getToken(DplParser::Slash, i);
}

std::vector<tree::TerminalNode *> DplParser::MultexprContext::Mod() {
  return getTokens(DplParser::Mod);
}

tree::TerminalNode* DplParser::MultexprContext::Mod(size_t i) {
  return getToken(DplParser::Mod, i);
}


size_t DplParser::MultexprContext::getRuleIndex() const {
  return DplParser::RuleMultexpr;
}


std::any DplParser::MultexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitMultexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::MultexprContext* DplParser::multexpr() {
  MultexprContext *_localctx = _tracker.createInstance<MultexprContext>(_ctx, getState());
  enterRule(_localctx, 38, DplParser::RuleMultexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    polaexpr();
    setState(218);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0)) {
      setState(214);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 29360128) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(215);
      polaexpr();
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PolaexprContext ------------------------------------------------------------------

DplParser::PolaexprContext::PolaexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DplParser::PolaexprContext* DplParser::PolaexprContext::polaexpr() {
  return getRuleContext<DplParser::PolaexprContext>(0);
}

tree::TerminalNode* DplParser::PolaexprContext::Plus() {
  return getToken(DplParser::Plus, 0);
}

tree::TerminalNode* DplParser::PolaexprContext::Minus() {
  return getToken(DplParser::Minus, 0);
}

DplParser::ExpoexprContext* DplParser::PolaexprContext::expoexpr() {
  return getRuleContext<DplParser::ExpoexprContext>(0);
}


size_t DplParser::PolaexprContext::getRuleIndex() const {
  return DplParser::RulePolaexpr;
}


std::any DplParser::PolaexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitPolaexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::PolaexprContext* DplParser::polaexpr() {
  PolaexprContext *_localctx = _tracker.createInstance<PolaexprContext>(_ctx, getState());
  enterRule(_localctx, 40, DplParser::RulePolaexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(221);
      _la = _input->LA(1);
      if (!(_la == DplParser::Plus

      || _la == DplParser::Minus)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(222);
      polaexpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(223);
      expoexpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpoexprContext ------------------------------------------------------------------

DplParser::ExpoexprContext::ExpoexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::TermContext *> DplParser::ExpoexprContext::term() {
  return getRuleContexts<DplParser::TermContext>();
}

DplParser::TermContext* DplParser::ExpoexprContext::term(size_t i) {
  return getRuleContext<DplParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::ExpoexprContext::Exponent() {
  return getTokens(DplParser::Exponent);
}

tree::TerminalNode* DplParser::ExpoexprContext::Exponent(size_t i) {
  return getToken(DplParser::Exponent, i);
}


size_t DplParser::ExpoexprContext::getRuleIndex() const {
  return DplParser::RuleExpoexpr;
}


std::any DplParser::ExpoexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitExpoexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ExpoexprContext* DplParser::expoexpr() {
  ExpoexprContext *_localctx = _tracker.createInstance<ExpoexprContext>(_ctx, getState());
  enterRule(_localctx, 42, DplParser::RuleExpoexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    term();
    setState(231);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Exponent) {
      setState(227);
      match(DplParser::Exponent);
      setState(228);
      term();
      setState(233);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

DplParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::TermContext::OpenPar() {
  return getToken(DplParser::OpenPar, 0);
}

DplParser::OrexprContext* DplParser::TermContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::TermContext::ClosePar() {
  return getToken(DplParser::ClosePar, 0);
}

DplParser::ListContext* DplParser::TermContext::list() {
  return getRuleContext<DplParser::ListContext>(0);
}

DplParser::TableContext* DplParser::TermContext::table() {
  return getRuleContext<DplParser::TableContext>(0);
}

DplParser::NumberContext* DplParser::TermContext::number() {
  return getRuleContext<DplParser::NumberContext>(0);
}

tree::TerminalNode* DplParser::TermContext::Bool() {
  return getToken(DplParser::Bool, 0);
}

tree::TerminalNode* DplParser::TermContext::String() {
  return getToken(DplParser::String, 0);
}

tree::TerminalNode* DplParser::TermContext::None() {
  return getToken(DplParser::None, 0);
}

DplParser::SubscriptContext* DplParser::TermContext::subscript() {
  return getRuleContext<DplParser::SubscriptContext>(0);
}


size_t DplParser::TermContext::getRuleIndex() const {
  return DplParser::RuleTerm;
}


std::any DplParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

DplParser::TermContext* DplParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 44, DplParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DplParser::OpenPar: {
        enterOuterAlt(_localctx, 1);
        setState(234);
        match(DplParser::OpenPar);
        setState(235);
        orexpr();
        setState(236);
        match(DplParser::ClosePar);
        break;
      }

      case DplParser::OpenSquare: {
        enterOuterAlt(_localctx, 2);
        setState(238);
        list();
        break;
      }

      case DplParser::OpenCurly: {
        enterOuterAlt(_localctx, 3);
        setState(239);
        table();
        break;
      }

      case DplParser::Plus:
      case DplParser::Minus:
      case DplParser::Integer:
      case DplParser::Float: {
        enterOuterAlt(_localctx, 4);
        setState(240);
        number();
        break;
      }

      case DplParser::Bool: {
        enterOuterAlt(_localctx, 5);
        setState(241);
        match(DplParser::Bool);
        break;
      }

      case DplParser::String: {
        enterOuterAlt(_localctx, 6);
        setState(242);
        match(DplParser::String);
        break;
      }

      case DplParser::None: {
        enterOuterAlt(_localctx, 7);
        setState(243);
        match(DplParser::None);
        break;
      }

      case DplParser::Identifier: {
        enterOuterAlt(_localctx, 8);
        setState(244);
        subscript();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

DplParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DplParser::NumberContext* DplParser::NumberContext::number() {
  return getRuleContext<DplParser::NumberContext>(0);
}

tree::TerminalNode* DplParser::NumberContext::Minus() {
  return getToken(DplParser::Minus, 0);
}

tree::TerminalNode* DplParser::NumberContext::Plus() {
  return getToken(DplParser::Plus, 0);
}

tree::TerminalNode* DplParser::NumberContext::Integer() {
  return getToken(DplParser::Integer, 0);
}

tree::TerminalNode* DplParser::NumberContext::Float() {
  return getToken(DplParser::Float, 0);
}


size_t DplParser::NumberContext::getRuleIndex() const {
  return DplParser::RuleNumber;
}


std::any DplParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

DplParser::NumberContext* DplParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 46, DplParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DplParser::Plus:
      case DplParser::Minus: {
        enterOuterAlt(_localctx, 1);
        setState(247);
        _la = _input->LA(1);
        if (!(_la == DplParser::Plus

        || _la == DplParser::Minus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(248);
        number();
        break;
      }

      case DplParser::Integer:
      case DplParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(249);
        _la = _input->LA(1);
        if (!(_la == DplParser::Integer

        || _la == DplParser::Float)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubscriptContext ------------------------------------------------------------------

DplParser::SubscriptContext::SubscriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::SubscriptContext::Identifier() {
  return getToken(DplParser::Identifier, 0);
}

std::vector<DplParser::ProccallContext *> DplParser::SubscriptContext::proccall() {
  return getRuleContexts<DplParser::ProccallContext>();
}

DplParser::ProccallContext* DplParser::SubscriptContext::proccall(size_t i) {
  return getRuleContext<DplParser::ProccallContext>(i);
}

std::vector<DplParser::HeaderindexContext *> DplParser::SubscriptContext::headerindex() {
  return getRuleContexts<DplParser::HeaderindexContext>();
}

DplParser::HeaderindexContext* DplParser::SubscriptContext::headerindex(size_t i) {
  return getRuleContext<DplParser::HeaderindexContext>(i);
}

std::vector<DplParser::IndexContext *> DplParser::SubscriptContext::index() {
  return getRuleContexts<DplParser::IndexContext>();
}

DplParser::IndexContext* DplParser::SubscriptContext::index(size_t i) {
  return getRuleContext<DplParser::IndexContext>(i);
}

std::vector<DplParser::FilteringContext *> DplParser::SubscriptContext::filtering() {
  return getRuleContexts<DplParser::FilteringContext>();
}

DplParser::FilteringContext* DplParser::SubscriptContext::filtering(size_t i) {
  return getRuleContext<DplParser::FilteringContext>(i);
}


size_t DplParser::SubscriptContext::getRuleIndex() const {
  return DplParser::RuleSubscript;
}


std::any DplParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}

DplParser::SubscriptContext* DplParser::subscript() {
  SubscriptContext *_localctx = _tracker.createInstance<SubscriptContext>(_ctx, getState());
  enterRule(_localctx, 48, DplParser::RuleSubscript);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(DplParser::Identifier);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(257);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(253);
          proccall();
          break;
        }

        case 2: {
          setState(254);
          headerindex();
          break;
        }

        case 3: {
          setState(255);
          index();
          break;
        }

        case 4: {
          setState(256);
          filtering();
          break;
        }

        default:
          break;
        } 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

DplParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ListContext::OpenSquare() {
  return getToken(DplParser::OpenSquare, 0);
}

DplParser::ArgsContext* DplParser::ListContext::args() {
  return getRuleContext<DplParser::ArgsContext>(0);
}

tree::TerminalNode* DplParser::ListContext::CloseSquare() {
  return getToken(DplParser::CloseSquare, 0);
}


size_t DplParser::ListContext::getRuleIndex() const {
  return DplParser::RuleList;
}


std::any DplParser::ListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitList(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ListContext* DplParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 50, DplParser::RuleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(262);
      match(DplParser::OpenSquare);
      setState(263);
      args();
      setState(264);
      match(DplParser::CloseSquare);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(266);
      match(DplParser::OpenSquare);
      setState(267);
      match(DplParser::CloseSquare);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableContext ------------------------------------------------------------------

DplParser::TableContext::TableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::TableContext::OpenCurly() {
  return getToken(DplParser::OpenCurly, 0);
}

std::vector<DplParser::ColumnContext *> DplParser::TableContext::column() {
  return getRuleContexts<DplParser::ColumnContext>();
}

DplParser::ColumnContext* DplParser::TableContext::column(size_t i) {
  return getRuleContext<DplParser::ColumnContext>(i);
}

tree::TerminalNode* DplParser::TableContext::CloseCurly() {
  return getToken(DplParser::CloseCurly, 0);
}

std::vector<tree::TerminalNode *> DplParser::TableContext::Comma() {
  return getTokens(DplParser::Comma);
}

tree::TerminalNode* DplParser::TableContext::Comma(size_t i) {
  return getToken(DplParser::Comma, i);
}


size_t DplParser::TableContext::getRuleIndex() const {
  return DplParser::RuleTable;
}


std::any DplParser::TableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitTable(this);
  else
    return visitor->visitChildren(this);
}

DplParser::TableContext* DplParser::table() {
  TableContext *_localctx = _tracker.createInstance<TableContext>(_ctx, getState());
  enterRule(_localctx, 52, DplParser::RuleTable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      match(DplParser::OpenCurly);
      setState(271);
      column();
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DplParser::Comma) {
        setState(272);
        match(DplParser::Comma);
        setState(273);
        column();
        setState(278);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(279);
      match(DplParser::CloseCurly);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(281);
      match(DplParser::OpenCurly);
      setState(282);
      match(DplParser::CloseCurly);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnContext ------------------------------------------------------------------

DplParser::ColumnContext::ColumnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::OrexprContext *> DplParser::ColumnContext::orexpr() {
  return getRuleContexts<DplParser::OrexprContext>();
}

DplParser::OrexprContext* DplParser::ColumnContext::orexpr(size_t i) {
  return getRuleContext<DplParser::OrexprContext>(i);
}

tree::TerminalNode* DplParser::ColumnContext::Colon() {
  return getToken(DplParser::Colon, 0);
}


size_t DplParser::ColumnContext::getRuleIndex() const {
  return DplParser::RuleColumn;
}


std::any DplParser::ColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitColumn(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ColumnContext* DplParser::column() {
  ColumnContext *_localctx = _tracker.createInstance<ColumnContext>(_ctx, getState());
  enterRule(_localctx, 54, DplParser::RuleColumn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    orexpr();
    setState(286);
    match(DplParser::Colon);
    setState(287);
    orexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

DplParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::IndexContext::OpenSquare() {
  return getToken(DplParser::OpenSquare, 0);
}

DplParser::OrexprContext* DplParser::IndexContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::IndexContext::CloseSquare() {
  return getToken(DplParser::CloseSquare, 0);
}


size_t DplParser::IndexContext::getRuleIndex() const {
  return DplParser::RuleIndex;
}


std::any DplParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

DplParser::IndexContext* DplParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 56, DplParser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(DplParser::OpenSquare);
    setState(290);
    orexpr();
    setState(291);
    match(DplParser::CloseSquare);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderindexContext ------------------------------------------------------------------

DplParser::HeaderindexContext::HeaderindexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::HeaderindexContext::OpenSquare() {
  return getToken(DplParser::OpenSquare, 0);
}

tree::TerminalNode* DplParser::HeaderindexContext::Dollar() {
  return getToken(DplParser::Dollar, 0);
}

DplParser::OrexprContext* DplParser::HeaderindexContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::HeaderindexContext::CloseSquare() {
  return getToken(DplParser::CloseSquare, 0);
}


size_t DplParser::HeaderindexContext::getRuleIndex() const {
  return DplParser::RuleHeaderindex;
}


std::any DplParser::HeaderindexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitHeaderindex(this);
  else
    return visitor->visitChildren(this);
}

DplParser::HeaderindexContext* DplParser::headerindex() {
  HeaderindexContext *_localctx = _tracker.createInstance<HeaderindexContext>(_ctx, getState());
  enterRule(_localctx, 58, DplParser::RuleHeaderindex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(DplParser::OpenSquare);
    setState(294);
    match(DplParser::Dollar);
    setState(295);
    orexpr();
    setState(296);
    match(DplParser::CloseSquare);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilteringContext ------------------------------------------------------------------

DplParser::FilteringContext::FilteringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::FilteringContext::OpenSquare() {
  return getToken(DplParser::OpenSquare, 0);
}

DplParser::UnaryexprContext* DplParser::FilteringContext::unaryexpr() {
  return getRuleContext<DplParser::UnaryexprContext>(0);
}

tree::TerminalNode* DplParser::FilteringContext::CloseSquare() {
  return getToken(DplParser::CloseSquare, 0);
}


size_t DplParser::FilteringContext::getRuleIndex() const {
  return DplParser::RuleFiltering;
}


std::any DplParser::FilteringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitFiltering(this);
  else
    return visitor->visitChildren(this);
}

DplParser::FilteringContext* DplParser::filtering() {
  FilteringContext *_localctx = _tracker.createInstance<FilteringContext>(_ctx, getState());
  enterRule(_localctx, 60, DplParser::RuleFiltering);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    match(DplParser::OpenSquare);
    setState(299);
    unaryexpr();
    setState(300);
    match(DplParser::CloseSquare);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryexprContext ------------------------------------------------------------------

DplParser::UnaryexprContext::UnaryexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DplParser::OrexprContext* DplParser::UnaryexprContext::orexpr() {
  return getRuleContext<DplParser::OrexprContext>(0);
}

tree::TerminalNode* DplParser::UnaryexprContext::Equal() {
  return getToken(DplParser::Equal, 0);
}

tree::TerminalNode* DplParser::UnaryexprContext::NotEqual() {
  return getToken(DplParser::NotEqual, 0);
}

tree::TerminalNode* DplParser::UnaryexprContext::Greater() {
  return getToken(DplParser::Greater, 0);
}

tree::TerminalNode* DplParser::UnaryexprContext::GreaterEqual() {
  return getToken(DplParser::GreaterEqual, 0);
}

tree::TerminalNode* DplParser::UnaryexprContext::Less() {
  return getToken(DplParser::Less, 0);
}

tree::TerminalNode* DplParser::UnaryexprContext::LessEqual() {
  return getToken(DplParser::LessEqual, 0);
}


size_t DplParser::UnaryexprContext::getRuleIndex() const {
  return DplParser::RuleUnaryexpr;
}


std::any DplParser::UnaryexprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitUnaryexpr(this);
  else
    return visitor->visitChildren(this);
}

DplParser::UnaryexprContext* DplParser::unaryexpr() {
  UnaryexprContext *_localctx = _tracker.createInstance<UnaryexprContext>(_ctx, getState());
  enterRule(_localctx, 62, DplParser::RuleUnaryexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2113929216) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(303);
    orexpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProccallContext ------------------------------------------------------------------

DplParser::ProccallContext::ProccallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DplParser::ProccallContext::OpenPar() {
  return getToken(DplParser::OpenPar, 0);
}

tree::TerminalNode* DplParser::ProccallContext::ClosePar() {
  return getToken(DplParser::ClosePar, 0);
}

DplParser::ArgsContext* DplParser::ProccallContext::args() {
  return getRuleContext<DplParser::ArgsContext>(0);
}


size_t DplParser::ProccallContext::getRuleIndex() const {
  return DplParser::RuleProccall;
}


std::any DplParser::ProccallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitProccall(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ProccallContext* DplParser::proccall() {
  ProccallContext *_localctx = _tracker.createInstance<ProccallContext>(_ctx, getState());
  enterRule(_localctx, 64, DplParser::RuleProccall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      match(DplParser::OpenPar);
      setState(306);
      match(DplParser::ClosePar);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(307);
      match(DplParser::OpenPar);
      setState(308);
      args();
      setState(309);
      match(DplParser::ClosePar);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

DplParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DplParser::OrexprContext *> DplParser::ArgsContext::orexpr() {
  return getRuleContexts<DplParser::OrexprContext>();
}

DplParser::OrexprContext* DplParser::ArgsContext::orexpr(size_t i) {
  return getRuleContext<DplParser::OrexprContext>(i);
}

std::vector<tree::TerminalNode *> DplParser::ArgsContext::Comma() {
  return getTokens(DplParser::Comma);
}

tree::TerminalNode* DplParser::ArgsContext::Comma(size_t i) {
  return getToken(DplParser::Comma, i);
}


size_t DplParser::ArgsContext::getRuleIndex() const {
  return DplParser::RuleArgs;
}


std::any DplParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DplParserVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

DplParser::ArgsContext* DplParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 66, DplParser::RuleArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    orexpr();
    setState(318);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DplParser::Comma) {
      setState(314);
      match(DplParser::Comma);
      setState(315);
      orexpr();
      setState(320);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void DplParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  dplparserParserInitialize();
#else
  ::antlr4::internal::call_once(dplparserParserOnceFlag, dplparserParserInitialize);
#endif
}
