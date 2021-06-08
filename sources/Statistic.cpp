// Copyright 2021 by FORTYSS

#include "Statistic.hpp"
void Statistic::OnLoaded(const std::vector<Item>& new_items) {
  Loger::GetInstance().WriteDebug("StatSender::OnDataLoad");

  AsyncSend(new_items, "/items/loaded");
}

void Statistic::Skip(const Item& item) {
  AsyncSend({item}, "/items/skiped");
}

void Statistic::AsyncSend(const std::vector<Item>& items,
                           std::string_view path) {
  Loger::GetInstance().Write(path);
  Loger::GetInstance().Write("send stat " + std::to_string(items.size()));

  for (const auto& item : items) {
    Loger::GetInstance().WriteDebug("send: " + item.id);
    // ... some code
    fstr << item.id << item.name << item.score;
    fstr.flush();
  }
}
