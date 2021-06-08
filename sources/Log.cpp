// Copyright 2021 by FORTYSS

#include "Log.hpp"
void Log::Write(const std::string_view& message) const {
  *out_ << "[info] " << message << std::endl;
}
void Log::WriteDebug(const std::string_view& message) const {
  if (level_) *out_ << "[debug] " << message << std::endl;
}
Log& Log::GetInstance() {
  static Log instance;
  return instance;
}
void Log::Setting(bool level) {
  level_ = level;
}
