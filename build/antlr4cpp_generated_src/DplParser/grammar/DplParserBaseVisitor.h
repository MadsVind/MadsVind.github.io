
// Generated from /home/vind/dpl/grammar/DplParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DplParserVisitor.h"


namespace dplgrammar {

/**
 * This class provides an empty implementation of DplParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DplParserBaseVisitor : public DplParserVisitor {
public:

  virtual std::any visitProg(DplParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcdec(DplParser::ProcdecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(DplParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStm(DplParser::StmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStms(DplParser::StmsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(DplParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfstm(DplParser::IfstmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElsestm(DplParser::ElsestmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhilestm(DplParser::WhilestmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignstm(DplParser::AssignstmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlowstm(DplParser::FlowstmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnstm(DplParser::ReturnstmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrexpr(DplParser::OrexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndexpr(DplParser::AndexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotexpr(DplParser::NotexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqulexpr(DplParser::EqulexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompexpr(DplParser::CompexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlusexpr(DplParser::PlusexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTablexpr(DplParser::TablexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultexpr(DplParser::MultexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPolaexpr(DplParser::PolaexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpoexpr(DplParser::ExpoexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(DplParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(DplParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscript(DplParser::SubscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList(DplParser::ListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTable(DplParser::TableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitColumn(DplParser::ColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(DplParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHeaderindex(DplParser::HeaderindexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFiltering(DplParser::FilteringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryexpr(DplParser::UnaryexprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProccall(DplParser::ProccallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(DplParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace dplgrammar
