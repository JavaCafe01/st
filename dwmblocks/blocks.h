//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Command*/    /*Update Interval*/    /*Update Signal*/
    {"", "~/.suckless/dwmblocks/blocks/spotify", 1, 0},

    {"", "~/.suckless/dwmblocks/blocks/net", 10, 0},

  //{"", "~/.suckless/dwmblocks/blocks/battery", 5, 0},

  //{"", "~/.suckless/dwmblocks/blocks/backlight", 0, 10},

    {"", "~/.suckless/dwmblocks/blocks/volume", 0, 10},

    {"", "~/.suckless/dwmblocks/blocks/date", 60, 0},

    {"", "~/.suckless/dwmblocks/blocks/time", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
