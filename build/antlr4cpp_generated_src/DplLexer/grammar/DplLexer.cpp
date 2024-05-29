
// Generated from /home/vind/dpl/grammar/DplLexer.g4 by ANTLR 4.13.1


    #include <queue>


#include "DplLexer.h"


using namespace antlr4;

using namespace dplgrammar;


using namespace antlr4;

namespace {

struct DplLexerStaticData final {
  DplLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DplLexerStaticData(const DplLexerStaticData&) = delete;
  DplLexerStaticData(DplLexerStaticData&&) = delete;
  DplLexerStaticData& operator=(const DplLexerStaticData&) = delete;
  DplLexerStaticData& operator=(DplLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag dpllexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DplLexerStaticData *dpllexerLexerStaticData = nullptr;

void dpllexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (dpllexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(dpllexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DplLexerStaticData>(
    std::vector<std::string>{
      "If", "Else", "While", "Break", "Continue", "Return", "Def", "OpenPar", 
      "ClosePar", "OpenCurly", "CloseCurly", "OpenSquare", "CloseSquare", 
      "Colon", "Comma", "Dollar", "Exponent", "Plus", "Minus", "Star", "Slash", 
      "Mod", "Equal", "NotEqual", "Less", "LessEqual", "Greater", "GreaterEqual", 
      "And", "Or", "Not", "Assign", "Union", "Intersection", "DIGIT", "ALPHA", 
      "ALPHANUM", "Integer", "Float", "Bool", "String", "None", "Identifier", 
      "Comment", "Newline", "Whitespace"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,45,292,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,8,1,
  	8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,
  	1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,
  	1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,
  	1,27,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,31,1,31,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,
  	1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,4,37,220,
  	8,37,11,37,12,37,221,1,38,5,38,225,8,38,10,38,12,38,228,9,38,1,38,1,38,
  	4,38,232,8,38,11,38,12,38,233,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,
  	1,39,3,39,245,8,39,1,40,1,40,1,40,1,40,5,40,251,8,40,10,40,12,40,254,
  	9,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,42,1,42,3,42,265,8,42,1,42,
  	1,42,5,42,269,8,42,10,42,12,42,272,9,42,1,43,1,43,5,43,276,8,43,10,43,
  	12,43,279,9,43,1,43,1,43,1,44,3,44,284,8,44,1,44,1,44,1,44,1,45,1,45,
  	1,45,1,45,0,0,46,1,3,3,4,5,5,7,6,9,7,11,8,13,9,15,10,17,11,19,12,21,13,
  	23,14,25,15,27,16,29,17,31,18,33,19,35,20,37,21,39,22,41,23,43,24,45,
  	25,47,26,49,27,51,28,53,29,55,30,57,31,59,32,61,33,63,34,65,35,67,36,
  	69,0,71,0,73,0,75,37,77,38,79,39,81,40,83,41,85,42,87,43,89,44,91,45,
  	1,0,6,1,0,48,57,2,0,65,90,97,122,3,0,48,57,65,90,97,122,3,0,10,10,13,
  	13,34,34,2,0,10,10,13,13,2,0,9,9,32,32,299,0,1,1,0,0,0,0,3,1,0,0,0,0,
  	5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,
  	0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,
  	0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,
  	1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,
  	0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,
  	0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,75,
  	1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,
  	0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,1,93,1,0,0,0,3,96,1,0,0,0,
  	5,101,1,0,0,0,7,107,1,0,0,0,9,113,1,0,0,0,11,122,1,0,0,0,13,129,1,0,0,
  	0,15,133,1,0,0,0,17,135,1,0,0,0,19,137,1,0,0,0,21,139,1,0,0,0,23,141,
  	1,0,0,0,25,143,1,0,0,0,27,145,1,0,0,0,29,147,1,0,0,0,31,149,1,0,0,0,33,
  	151,1,0,0,0,35,154,1,0,0,0,37,156,1,0,0,0,39,158,1,0,0,0,41,160,1,0,0,
  	0,43,162,1,0,0,0,45,164,1,0,0,0,47,167,1,0,0,0,49,170,1,0,0,0,51,172,
  	1,0,0,0,53,175,1,0,0,0,55,177,1,0,0,0,57,180,1,0,0,0,59,184,1,0,0,0,61,
  	187,1,0,0,0,63,191,1,0,0,0,65,193,1,0,0,0,67,199,1,0,0,0,69,212,1,0,0,
  	0,71,214,1,0,0,0,73,216,1,0,0,0,75,219,1,0,0,0,77,226,1,0,0,0,79,244,
  	1,0,0,0,81,246,1,0,0,0,83,257,1,0,0,0,85,264,1,0,0,0,87,273,1,0,0,0,89,
  	283,1,0,0,0,91,288,1,0,0,0,93,94,5,105,0,0,94,95,5,102,0,0,95,2,1,0,0,
  	0,96,97,5,101,0,0,97,98,5,108,0,0,98,99,5,115,0,0,99,100,5,101,0,0,100,
  	4,1,0,0,0,101,102,5,119,0,0,102,103,5,104,0,0,103,104,5,105,0,0,104,105,
  	5,108,0,0,105,106,5,101,0,0,106,6,1,0,0,0,107,108,5,98,0,0,108,109,5,
  	114,0,0,109,110,5,101,0,0,110,111,5,97,0,0,111,112,5,107,0,0,112,8,1,
  	0,0,0,113,114,5,99,0,0,114,115,5,111,0,0,115,116,5,110,0,0,116,117,5,
  	116,0,0,117,118,5,105,0,0,118,119,5,110,0,0,119,120,5,117,0,0,120,121,
  	5,101,0,0,121,10,1,0,0,0,122,123,5,114,0,0,123,124,5,101,0,0,124,125,
  	5,116,0,0,125,126,5,117,0,0,126,127,5,114,0,0,127,128,5,110,0,0,128,12,
  	1,0,0,0,129,130,5,100,0,0,130,131,5,101,0,0,131,132,5,102,0,0,132,14,
  	1,0,0,0,133,134,5,40,0,0,134,16,1,0,0,0,135,136,5,41,0,0,136,18,1,0,0,
  	0,137,138,5,123,0,0,138,20,1,0,0,0,139,140,5,125,0,0,140,22,1,0,0,0,141,
  	142,5,91,0,0,142,24,1,0,0,0,143,144,5,93,0,0,144,26,1,0,0,0,145,146,5,
  	58,0,0,146,28,1,0,0,0,147,148,5,44,0,0,148,30,1,0,0,0,149,150,5,36,0,
  	0,150,32,1,0,0,0,151,152,5,42,0,0,152,153,5,42,0,0,153,34,1,0,0,0,154,
  	155,5,43,0,0,155,36,1,0,0,0,156,157,5,45,0,0,157,38,1,0,0,0,158,159,5,
  	42,0,0,159,40,1,0,0,0,160,161,5,47,0,0,161,42,1,0,0,0,162,163,5,37,0,
  	0,163,44,1,0,0,0,164,165,5,61,0,0,165,166,5,61,0,0,166,46,1,0,0,0,167,
  	168,5,33,0,0,168,169,5,61,0,0,169,48,1,0,0,0,170,171,5,60,0,0,171,50,
  	1,0,0,0,172,173,5,60,0,0,173,174,5,61,0,0,174,52,1,0,0,0,175,176,5,62,
  	0,0,176,54,1,0,0,0,177,178,5,62,0,0,178,179,5,61,0,0,179,56,1,0,0,0,180,
  	181,5,97,0,0,181,182,5,110,0,0,182,183,5,100,0,0,183,58,1,0,0,0,184,185,
  	5,111,0,0,185,186,5,114,0,0,186,60,1,0,0,0,187,188,5,110,0,0,188,189,
  	5,111,0,0,189,190,5,116,0,0,190,62,1,0,0,0,191,192,5,61,0,0,192,64,1,
  	0,0,0,193,194,5,117,0,0,194,195,5,110,0,0,195,196,5,105,0,0,196,197,5,
  	111,0,0,197,198,5,110,0,0,198,66,1,0,0,0,199,200,5,105,0,0,200,201,5,
  	110,0,0,201,202,5,116,0,0,202,203,5,101,0,0,203,204,5,114,0,0,204,205,
  	5,115,0,0,205,206,5,101,0,0,206,207,5,99,0,0,207,208,5,116,0,0,208,209,
  	5,105,0,0,209,210,5,111,0,0,210,211,5,110,0,0,211,68,1,0,0,0,212,213,
  	7,0,0,0,213,70,1,0,0,0,214,215,7,1,0,0,215,72,1,0,0,0,216,217,7,2,0,0,
  	217,74,1,0,0,0,218,220,3,69,34,0,219,218,1,0,0,0,220,221,1,0,0,0,221,
  	219,1,0,0,0,221,222,1,0,0,0,222,76,1,0,0,0,223,225,3,69,34,0,224,223,
  	1,0,0,0,225,228,1,0,0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,
  	0,228,226,1,0,0,0,229,231,5,46,0,0,230,232,3,69,34,0,231,230,1,0,0,0,
  	232,233,1,0,0,0,233,231,1,0,0,0,233,234,1,0,0,0,234,78,1,0,0,0,235,236,
  	5,84,0,0,236,237,5,114,0,0,237,238,5,117,0,0,238,245,5,101,0,0,239,240,
  	5,70,0,0,240,241,5,97,0,0,241,242,5,108,0,0,242,243,5,115,0,0,243,245,
  	5,101,0,0,244,235,1,0,0,0,244,239,1,0,0,0,245,80,1,0,0,0,246,252,5,34,
  	0,0,247,251,8,3,0,0,248,249,5,92,0,0,249,251,5,34,0,0,250,247,1,0,0,0,
  	250,248,1,0,0,0,251,254,1,0,0,0,252,250,1,0,0,0,252,253,1,0,0,0,253,255,
  	1,0,0,0,254,252,1,0,0,0,255,256,5,34,0,0,256,82,1,0,0,0,257,258,5,78,
  	0,0,258,259,5,111,0,0,259,260,5,110,0,0,260,261,5,101,0,0,261,84,1,0,
  	0,0,262,265,3,71,35,0,263,265,5,95,0,0,264,262,1,0,0,0,264,263,1,0,0,
  	0,265,270,1,0,0,0,266,269,3,73,36,0,267,269,5,95,0,0,268,266,1,0,0,0,
  	268,267,1,0,0,0,269,272,1,0,0,0,270,268,1,0,0,0,270,271,1,0,0,0,271,86,
  	1,0,0,0,272,270,1,0,0,0,273,277,5,35,0,0,274,276,8,4,0,0,275,274,1,0,
  	0,0,276,279,1,0,0,0,277,275,1,0,0,0,277,278,1,0,0,0,278,280,1,0,0,0,279,
  	277,1,0,0,0,280,281,6,43,0,0,281,88,1,0,0,0,282,284,5,13,0,0,283,282,
  	1,0,0,0,283,284,1,0,0,0,284,285,1,0,0,0,285,286,5,10,0,0,286,287,6,44,
  	1,0,287,90,1,0,0,0,288,289,7,5,0,0,289,290,1,0,0,0,290,291,6,45,0,0,291,
  	92,1,0,0,0,12,0,221,226,233,244,250,252,264,268,270,277,283,2,6,0,0,1,
  	44,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  dpllexerLexerStaticData = staticData.release();
}

}

DplLexer::DplLexer(CharStream *input) : Lexer(input) {
  DplLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *dpllexerLexerStaticData->atn, dpllexerLexerStaticData->decisionToDFA, dpllexerLexerStaticData->sharedContextCache);
}

DplLexer::~DplLexer() {
  delete _interpreter;
}

std::string DplLexer::getGrammarFileName() const {
  return "DplLexer.g4";
}

const std::vector<std::string>& DplLexer::getRuleNames() const {
  return dpllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& DplLexer::getChannelNames() const {
  return dpllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& DplLexer::getModeNames() const {
  return dpllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& DplLexer::getVocabulary() const {
  return dpllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DplLexer::getSerializedATN() const {
  return dpllexerLexerStaticData->serializedATN;
}

const atn::ATN& DplLexer::getATN() const {
  return *dpllexerLexerStaticData->atn;
}


void DplLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 44: NewlineAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void DplLexer::NewlineAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  addDentTokens();  break;

  default:
    break;
  }
}



void DplLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  dpllexerLexerInitialize();
#else
  ::antlr4::internal::call_once(dpllexerLexerOnceFlag, dpllexerLexerInitialize);
#endif
}
