![st](https://imgur.com/B1i036L.png)

# st - simple terminal

st is a simple terminal emulator for X which sucks more tbh.

My build of st contains these patches:
* box draw
* font 2 (allows for emojis)
* scroll back
* ligatures

The patches are in the `patches` folder.

### Requirements

In order to build st you need the Xlib header files.

For emoji support, you need to replace the libxft package with libxft-bgra. To make this simple, emoji rendering is not a st problem, but libxft. If you use arch and have an aur helper, such as paru, install it like so:

```bash
paru -S libxft-bgra-git
```

### Installation

After you have cloned the repo and copied the files into your config, go to .config/st.  

Edit config.mk to match your local setup (st is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install st (if
necessary as root):

```bash
make clean install
```

### Running st

If you did not install st with make clean install, you must compile
the st terminfo entry with the following command:

```bash
tic -sx st.info
```

See the man page for additional details.

### Credits

Based on Aurélien APTEL <aurelien dot aptel at gmail dot com> bt source code.

