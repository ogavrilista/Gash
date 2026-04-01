# Gash (Gabriel Shell)

## Intro
Hello, world! 🌎

Gash is a minimal UNIX Shell made by me for learning purposes.
<br>
Gash is extremely simple, so do you cannot use this shell in daily use, but the Gash have several advantages in comparison with other mini shells.

## What are this advantages?

The majority of mini shell uses ```<stdio.h>``` functions like ```fgets()``` or ```getline()```, in otherwise, Gash uses the GNU Readline, thanks GNU Readline, Gash gain a several Bash features as:

• Command history
<br>
• Autocomplete
<br>
• Movement of cursor to front with Ctrl+F shortcut.
<br>
• Movement of cursor to behind with Ctrl+B shortcut.
<br>
• Arrow keys support.

## How compile Gash?

If you want to use Gash or believes in project evolution, your steps are:

• Define environment variable GASH_PREFIX if you need compile the Gash out of the ```/usr/local```. <br>
• Run ```make``` command or ```make -j$(nproc)``` (That's unneeded, because Gash have only two files). <br>
• Run ```make install```, if you install Gash. <br>
• Run ```make uninstall```, if you need uninstall Gash. <br>
• Run ```make clean```, if you need uninstall, remove all object files and the Gash binary in ```bin```.

## Future plans

• Use Lexer and Parser rather than ```strtok()```. <br>
• Add a command builder. <br>
• Add pipe support. <br>
• Add redirection support. <br>
• Add environment variable support. <br>
• Add ```if``` conditional. <br>
• Add ```for``` conditional. <br>
• Add ```while``` conditional. <br>
• Block ending with ```end```. <br>
• Add subshell support. <br>
• Add status expansion support. <br>
• Add PID expansion support.
