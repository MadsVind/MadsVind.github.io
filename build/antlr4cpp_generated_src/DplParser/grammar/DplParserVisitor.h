
// Generated from /home/vind/dpl/grammar/DplParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DplParser.h"


namespace dplgrammar {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by DplParser.
 */
class  DplParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DplParser.
   */
    virtual std::any visitProg(DplParser::ProgContext *context) = 0;

    virtual std::any visitProcdec(DplParser::ProcdecContext *context) = 0;

    virtual std::any visitParams(DplParser::ParamsContext *context) = 0;

    virtual std::any visitStm(DplParser::StmContext *context) = 0;

    virtual std::any visitStms(DplParser::StmsContext *context) = 0;

    virtual std::any visitBlock(DplParser::BlockContext *context) = 0;

    virtual std::any visitIfstm(DplParser::IfstmContext *context) = 0;

    virtual std::any visitElsestm(DplParser::ElsestmContext *context) = 0;

    virtual std::any visitWhilestm(DplParser::WhilestmContext *context) = 0;

    virtual std::any visitAssignstm(DplParser::AssignstmContext *context) = 0;

    virtual std::any visitFlowstm(DplParser::FlowstmContext *context) = 0;

    virtual std::any visitReturnstm(DplParser::ReturnstmContext *context) = 0;

    virtual std::any visitOrexpr(DplParser::OrexprContext *context) = 0;

    virtual std::any visitAndexpr(DplParser::AndexprContext *context) = 0;

    virtual std::any visitNotexpr(DplParser::NotexprContext *context) = 0;

    virtual std::any visitEqulexpr(DplParser::EqulexprContext *context) = 0;

    virtual std::any visitCompexpr(DplParser::CompexprContext *context) = 0;

    virtual std::any visitPlusexpr(DplParser::PlusexprContext *context) = 0;

    virtual std::any visitTablexpr(DplParser::TablexprContext *context) = 0;

    virtual std::any visitMultexpr(DplParser::MultexprContext *context) = 0;

    virtual std::any visitPolaexpr(DplParser::PolaexprContext *context) = 0;

    virtual std::any visitExpoexpr(DplParser::ExpoexprContext *context) = 0;

    virtual std::any visitTerm(DplParser::TermContext *context) = 0;

    virtual std::any visitNumber(DplParser::NumberContext *context) = 0;

    virtual std::any visitSubscript(DplParser::SubscriptContext *context) = 0;

    virtual std::any visitList(DplParser::ListContext *context) = 0;

    virtual std::any visitTable(DplParser::TableContext *context) = 0;

    virtual std::any visitColumn(DplParser::ColumnContext *context) = 0;

    virtual std::any visitIndex(DplParser::IndexContext *context) = 0;

    virtual std::any visitHeaderindex(DplParser::HeaderindexContext *context) = 0;

    virtual std::any visitFiltering(DplParser::FilteringContext *context) = 0;

    virtual std::any visitUnaryexpr(DplParser::UnaryexprContext *context) = 0;

    virtual std::any visitProccall(DplParser::ProccallContext *context) = 0;

    virtual std::any visitArgs(DplParser::ArgsContext *context) = 0;


};

}  // namespace dplgrammar
