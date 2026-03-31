# Gash

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

• Create a folder called ```bin``` in project root. <br>
• Define environment variable GASH_PREFIX if you need compile the Gash out of the ```/usr/local```. <br>
• Run ```make``` command or ```make -j$(nproc)``` (That's unneeded, because Gash have only two files). <br>
• Run ```make install```, if you install Gash. <br>
• Run ```make uninstall```, if you need uninstall Gash. <br>
• Run ```make clean```, if you need uninstall, remove all object files and the Gash binary in ```bin```.

## Future plans

• Use Lexer and Parser rather than ```strtok()```.
• Add a command builder.
• Add pipe support.
• Add redirection support.
• Add environment variable support.
• Add if conditional.
• Add for conditional.
• Add while conditional.
• Block ending with end.
• Add subshell support.
• Add status expansion support.
• Add PID expansion support.
