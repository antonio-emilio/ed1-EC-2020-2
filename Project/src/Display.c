#include "Display.h"


void printBanner(int y, int x){


    char* banner_lines[] = { 

        "8888888b.                   d8b                   888   ", 
        "888   Y88b                  Y8P                   888   ",
        "888    888                                        888   ",
        "888   d88P 888d888 .d88b.  8888  .d88b.   .d8888b 888888", 
        "8888888P`  888P`  d88``88b `888 d8P  Y8b d88P`    888   ", 
        "888        888    888  888  888 88888888 888      888   ", 
        "888        888    Y88..88P  888 Y8b.     Y88b.    Y88b. ", 
        "888        888     `Y88P`   888  `Y8888   `Y8888P  `Y888", 
        "                            888                         ", 
        "                           d88P                         ", 
        "                         888P                           ", 

        " .d88888b.                                    d8b                           ",
        "d88P` `Y88b                                   Y8P                           ",
        "888     888                                                                 ",
        "888     888 888d888 .d88b.   8888b.  88888b.  888 88888888  .d88b.  888d888 ",
        "888     888 888P`  d88P`88b     `88b 888 `88b 888    d88P  d8P  Y8b 888P`   ",
        "888     888 888    888  888 .d888888 888  888 888   d88P   88888888 888     ",
        "Y88b. .d88P 888    Y88b 888 888  888 888  888 888  d88P    Y8b.     888     ",
        " `Y88888P`  888     `Y88888 `Y888888 888  888 888 88888888  `Y8888  888     ",
        "                         888                                                ",
        "                    Y8b d88P                                                ",
        "                     `Y88P`                                                 "

    };
    init_pair(BANNER_COLOR, COLOR_CYAN, COLOR_BLACK); 

    x -= strlen(banner_lines[0]); 

    attron(COLOR_PAIR(BANNER_COLOR));

    for(int i = 0; i < 22; i++)
        mvprintw(y++, x,"%s", banner_lines[i]);

    attroff(COLOR_PAIR(BANNER_COLOR));
        
}


int selectWin(char** options, char* question, int num_options, int y, int x, unsigned int width,unsigned int height,  int default_choice){

    int menu_width;
    int menu_height;

    if(!width || !height) 
    {
        menu_width = strlen(question) + 10;
        menu_height = num_options + 4;
    }
    else
    {
        menu_width  = width;
        menu_height = height;
    }

    // define the location considering the size of the win
    int menu_x = x - menu_width;
    int menu_y = y - menu_height;

    menu_x = menu_x < 0 ? 0 : menu_x;
    menu_y = menu_y < 0 ? 0 : menu_y;

    WINDOW* menu_win = newwin(menu_height, menu_width, menu_y , menu_x); 

    box(menu_win, 0, 0);

    int question_length = strlen(question);

    mvwprintw(menu_win, 0, (menu_width - question_length)/2, question);

    keypad(menu_win, TRUE );

    refresh();

    int selected = default_choice;
    bool bye = FALSE; 

    while(!bye)
    {
        for(int i = 0; i < num_options; i++)
        {
            if(i == selected)
                wattron(menu_win, A_REVERSE); 

            mvwprintw(menu_win, 2 + i, 1, options[i]);
            wattroff(menu_win, A_REVERSE);
        } 
        wrefresh(menu_win);

        int choice = getch();

        switch(choice)
        {
            case 65: // key up
                selected--;
                break;
            case 66: // key down
                selected++;
                break;
            case 10: // enter
                bye = TRUE;
                break;
        }

        if(selected < 0)
            selected = num_options - 1;

        if(selected > num_options - 1)
            selected = 0;

        wrefresh(menu_win);
    }

    delwin(menu_win);

    return selected;



}