// Copyright 2021 by FORTYSS

#include "Loger.hpp"
void Loger::Write(const std::string_view& message) const {
  *out_ << "[info] " << message << std::endl;
}
void Loger::WriteDebug(const std::string_view& message) const {
  if (level_) *out_ << "[debug] " << message << std::endl;
}
Loger& Loger::GetInstance() {
  static Loger instance;
  return instance;
}
void Loger::Setting(bool level) {
  level_ = level;
}
