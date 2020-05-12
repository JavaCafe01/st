<p align="center">
  <img width="15%" src="https://github.com/javacafe01.png" />
</p>

<p align="center">
  <b>Suckless - software that sucks less</b>
</p>

<p align="center">
  <b>👻 Gokul's dwm Setup 👻</b>
</p>

<img src="https://i.redd.it/4q4srdypk3y41.png" alt="img" align="right" width="400px">

## System Info

+ **WM**: dwm
+ **OS**: Manjaro
+ **Shell**: zsh
+ **Terminal**: st
+ **Editor**: neovim
+ **File Manager**: thunar
+ **Launcher**: dmenu
+ **Browser**: firefox
+ **Color Scheme**: Nord
+ **GTK Theme**: oomix generated

## Autostart

Don't forget to create an `autostart.sh` file in the `~/.dwm` directory. For example,
```bash
#! /bin/bash
picom &
nitrogen --restore &
dwmblocks &
pulseaudio --start -D &
```
