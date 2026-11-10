#include "model/Terminal.hpp"

Terminal parseTerminal(const std::string & terminal) {
  if (terminal == "2A")
    return TERM_2A;
  if (terminal == "2B")
    return TERM_2B;
  if (terminal == "2C")
    return TERM_2C;
  if (terminal == "2D")
    return TERM_2D;
  if (terminal == "2E")
    return TERM_2E;
  if (terminal == "2F")
    return TERM_2F;
  if (terminal == "2G")
    return TERM_2G;
  return TERM_NULL;  
}

std::string printTerminal(Terminal terminal) {
  switch (terminal) {
  case TERM_2A:
    return "2A";
  case TERM_2B:
    return "2B";
  case TERM_2C:
    return "2C";
  case TERM_2D:
    return "2D";
  case TERM_2E:
    return "2E";
  case TERM_2F:
    return "2F";
  case TERM_2G:
    return "2G";
  case TERM_NULL:
    return "UNKNOWN";
  }
}
