<p align="center">
<img width="15%" src="https://github.com/javacafe01.png" />
</p>

<p align="center">
<b>Suckless - software that sucks less</b>
</p>

<p align="center">
<b>👻 Gokul's dwm Setup 👻</b>
</p>

<p align="center">
<img src="https://preview.redd.it/x6g0f44zuez41.png?width=960&crop=smart&auto=webp&s=07d763ffd64f3e892948174e16b0d315530ffab5" alt="img" width="800px">
</p>

## System Info

+ **WM**: dwm
+ **OS**: Manjaro
+ **Shell**: zsh
+ **Terminal**: st
+ **Editor**: neovim
+ **File Manager**: thunar
+ **Launcher**: dmenu
+ **Browser**: firefox
+ **Color Scheme**: Custom
+ **GTK Theme**: wpg generated

## Autostart

Don't forget to create an `autostart.sh` file in the `~/.dwm` directory. For example,
```bash
#! /bin/bash

#  Compositor
    picom &

# Wallpaper
    nitrogen --restore &

# Status Bar
    dwmblocks &

# To update volume and brightness labels
    pkill -RTMIN+10 dwmblocks &

# For extra bitmap fonts
    xset +fp /home/javacafe01/.local/share/fonts &
    xset fp rehash &
