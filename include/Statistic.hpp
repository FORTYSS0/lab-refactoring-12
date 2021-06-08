// Copyright 2021 by FORTYSS

#ifndef INCLUDE_STATISTIC_HPP_
#define INCLUDE_STATISTIC_HPP_
#include <fstream>
#include <string_view>
#include <vector>
#include <iostream>

#include "Loger.hpp"

class Statistic {
 public:
  void OnLoaded(const std::vector<Item>& new_items);

  void Skip(const Item& item);

  virtual ~Statistic() = default;

 private:
  virtual void AsyncSend(const std::vector<Item>& items, std::string_view path);

  std::ofstream fstr{"network", std::ios::binary};
};
#endif  // INCLUDE_STATISTIC_HPP_
