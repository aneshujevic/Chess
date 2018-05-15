#ifndef COLORS_H
#define COLORS_H

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)

#define RESET     "\x1B[0m" // reset to normal
#define BOLD      "\x1B[1m" // bolded text

#define RED       "\x1B[31m"  // red
#define GRN       "\x1B[32m"  // green
#define YEL       "\x1B[33m"  // yellow
#define BLU       "\x1B[34m"  // blue
#define MAG       "\x1B[35m"  // magenta
#define CYN       "\x1B[36m"  // cyan


#else

#define RESET     ""
#define BOLD      ""
#define RED       ""
#define GRN       ""
#define YEL       ""
#define BLU       ""
#define MAG       ""
#define CYN       ""

#endif

#endif // COLORS_H
