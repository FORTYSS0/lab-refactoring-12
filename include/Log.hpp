// Copyright 2021 by FORTYSS

#ifndef TEMPLATE_LOG_HPP
#define TEMPLATE_LOG_HPP
#include "header.hpp"

class Log {
 public:
  static Log& GetInstance();

  void Setting(bool level);

  void Write(const std::string_view& message) const;

  void WriteDebug(const std::string_view& message) const;

 private:
  Log(): level_(false), out_(&std::cout){};

  Log( const Log&) = delete;
  Log& operator=( Log& ) = delete;

  bool level_ = false;
  mutable std::ostream* out_;
};

struct Item {
  std::string id;
  std::string name;
  float score = 0;
};
#endif  // TEMPLATE_LOG_HPP
