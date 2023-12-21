#pragma once

#include <fstream>
#include <string_view>

class Logger {
  class Sequence {
    template <typename Char, typename Traits>
    friend std::basic_ostream<Char, Traits>& operator<<(
        std::basic_ostream<Char, Traits>& os, Sequence&);

    std::size_t m_sequenceNo = 1;
  };

  template <typename Char, typename Traits>
  friend std::basic_ostream<Char, Traits>& operator<<(
      std::basic_ostream<Char, Traits>& os, Logger::Sequence&);

 public:
  Logger(std::string_view prefix, std::string_view name);
  ~Logger();

  Logger(Logger&) = delete;
  Logger(Logger&&) = default;

  Logger& operator=(const Logger&) = delete;
  Logger& operator=(Logger&&) = default;

  void putRecord(std::string_view record);

 private:
  Sequence m_sequence;
  std::ofstream m_file;
};