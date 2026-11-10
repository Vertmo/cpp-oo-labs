#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <string>

enum Terminal { TERM_NULL, TERM_2A, TERM_2B, TERM_2C, TERM_2D, TERM_2E, TERM_2F, TERM_2G };

Terminal parseTerminal(const std::string & terminal);
std::string printTerminal(Terminal term);
    
#endif
