#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void delay(int);
void initPairs();

int main(int argc, char **argv) {
  const int width = 1920;
  const int height = 1080;

  // seed time cuz C.
  srand(time(NULL));

  int chars = 1000000;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  start_color();
  initPairs();
  for (int i = 0; i < chars; ++i) {
    int randx = rand() % width, randy = rand() % height, randcolor = rand() % 6;
    attron(COLOR_PAIR(randcolor));
    char randchar = 'A' + (rand() % 26);
    char holder[2];
    holder[0] = randchar;
    holder[1] = '\0';
    mvprintw(randy, randx, holder);
    refresh();
    attroff(COLOR_PAIR(randcolor));
  }
  getch();
  endwin();

  return 0;
}

void delay(int time) {
  int milli = 1000 * time;

  clock_t start = clock();

  while (clock() < start + milli);
}

void initPairs() {
  init_pair(0, COLOR_RED, COLOR_BLACK);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_WHITE, COLOR_BLACK);
}