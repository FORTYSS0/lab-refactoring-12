// Copyright 2021 by FORTYSS

#ifndef INCLUDE_PAGECONTAINER_HPP_
#define INCLUDE_PAGECONTAINER_HPP_
#include <algorithm>
#include <set>
#include <sstream>
#include <vector>

#include "Histogram.hpp"
#include "Log.hpp"
#include "StatSender.hpp"
#include "UsedMemory.hpp"
#include "header.hpp"

constexpr size_t kMinLines = 10;

class PageContainer {
 public:
  void RawLoad(std::istream& file);

  [[nodiscard]] const Item& ByIndex(const size_t& i) const;

  [[nodiscard]] const Item& ById(const std::string& id) const;

  [[nodiscard]] size_t GetRawDataSize() const;

  [[nodiscard]] size_t GetDataSize() const;

  void DataLoad(const float& threshold);

  static bool IsCorrect(string& line);

  void PrintTable() const;

  explicit PageContainer(UsedMemory* memory_counter = new UsedMemory(),
                         StatSender* stat_sender = new StatSender())
      : memory_counter_(memory_counter), stat_sender_(stat_sender){}

  ~PageContainer();

 private:
  UsedMemory* memory_counter_;
  StatSender* stat_sender_;
  std::vector<Item> data_;
  std::vector<std::string> raw_data_;
};
#endif  // INCLUDE_PAGECONTAINER_HPP_
