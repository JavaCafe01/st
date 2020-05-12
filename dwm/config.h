/* appearance */
static const unsigned int borderpx    = 0;        /* border pixel of windows */
static const unsigned int snap        = 32;       /* snap pixel */
static const unsigned int gappx       = 15;        /* pixel gap between clients */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 1;        /* 0 means bottom bar */
static const int horizpadbar          = 6;        /* horizontal padding for statusbar */
static const int vertpadbar           = 7;        /* vertical padding for statusbar */

/* Mononoki Nerd Font must be installed from AUR nerd-fonts-complete.
 * Otherwise, your default font will be Hack which is found in the standard
 * Arch repos and is listed as a dependency for this build. JoyPixels is also
 * a hard dependency and makes colored fonts and emojis possible.
 */

//static const char *fonts[]            = {"Mononoki Nerd Font:size=9:antialias=true:autohint=true",
//                                         "Hack:size=8:antialias=true:autohint=true",
 //                                        "JoyPixels:size=10:antialias=true:autohint=true"
//										};

static const char *fonts[] = { "Wuncon Siji", "Mononoki Nerd Font:size=9:antialias=true:autohint=true" };

/*
static const char col_gray1[]         = "#2e3440";
static const char col_gray2[]         = "#2e3440"; 
static const char col_gray3[]         = "#96b5b4";
static const char col_gray4[]         = "#d8dee9";
static const char col_cyan[]          = "#81A1C1"; 
*/

//static const char *colors[][3]        = {
//	/*               fg         bg         border   */
//	[SchemeNorm] = { col_gray4, col_gray1, col_gray2 },
//	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
//};

/* colors */
static const char col_black[]  = "#20242c";
static const char col_gray[]   = "#2E3440";
static const char col_white[]  = "#dfe4ed";
static const char col_cyan[]   = "#88c0d0";
static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_black, col_gray },
	[SchemeSel]  = { col_cyan,  col_gray,  col_cyan  },
};



/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0xee; 
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
    { "zoom",     NULL,       NULL,       1 << 8,       0,           -1 },

};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
    { "",      spiral },
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ "",      grid },
    { "",      dwindle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
static const char *webcmd[]      = { "firefox", NULL };
static const char *termcmd[]     = { "st", NULL };
static const char *filecmd[]     = { "thunar", NULL};

/* For Built in keys */
#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier             key        function        argument */
	{ MODKEY,               XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,               XK_t,      spawn,          {.v = termcmd } },
    { MODKEY,               XK_w,      spawn,          {.v = webcmd } },
    { MODKEY,               XK_f,      spawn,          {.v = filecmd } },
    { MODKEY,               XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,     XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,               XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,               XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,   XK_Return, zoom,           {0} },
	{ MODKEY,               XK_Tab,    view,           {0} },
	{ MODKEY,               XK_q,      killclient,     {0} },

    /* Layout manipulation */
	{ MODKEY,               XK_Tab,    cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_Tab,    cyclelayout,    {.i = +1 } },
	{ MODKEY,               XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,     XK_space,  togglefloating, {0} },

    /* Switch to specific layouts */
    { MODKEY|ShiftMask,     XK_s,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,     XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,     XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,     XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,     XK_g,      setlayout,      {.v = &layouts[4]} },

	{ MODKEY,               XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     XK_0,      tag,            {.ui = ~0 } },

    /* Switching between monitors */
	{ MODKEY,               XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,               XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_period, tagmon,         {.i = +1 } },

     /* Audio and Brightness Keys*/
    { 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pamixer --allow-boost -i 2; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pamixer --allow-boost -d 2; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_AudioMute,	        spawn,		SHCMD("pamixer -t; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_MonBrightnessUp,	spawn,		SHCMD("xbacklight -inc 10; pkill -RTMIN+10 dwmblocks") },
    { 0, XF86XK_MonBrightnessDown,	spawn,		SHCMD("xbacklight -dec 10; pkill -RTMIN+10 dwmblocks") },
    
	TAGKEYS(                  XK_1,          0)
	TAGKEYS(                  XK_2,          1)
	TAGKEYS(                  XK_3,          2)
	TAGKEYS(                  XK_4,          3)
	TAGKEYS(                  XK_5,          4)
	TAGKEYS(                  XK_6,          5)
	TAGKEYS(                  XK_7,          6)
	TAGKEYS(                  XK_8,          7)
	TAGKEYS(                  XK_9,          8)
	{ MODKEY|ShiftMask,       XK_q,	   quit,           {0} },
        { MODKEY|ShiftMask,       XK_r,    quit,           {1} }, 
}; 

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click           event mask   button          function        argument */
	{ ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
	{ ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,     0,           Button1,        togglewin,      {0} },
	{ ClkWinTitle,     0,           Button2,        zoom,           {0} },
	{ ClkStatusText,   0,           Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
	{ ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
	{ ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
	{ ClkTagBar,       0,           Button1,        view,           {0} },
	{ ClkTagBar,       0,           Button3,        toggleview,     {0} },
	{ ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
	{ ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};
