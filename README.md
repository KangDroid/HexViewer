# What is this?
Don't know, its a fancy hex viewer with noob-coding in it. If you are looking for a professional - type of coding and viewer(or) editor, you might wanna leave this repository.

So, it is basically based on noob-c on it, using colsole application. This is pretty much optimized for, and fairly working on OSX or linux. Actually any BASH-Like system will work.

I've ran code on windows(visual studio 15), it is still working, functional, but it just look more dirty because I didn't implemented "system(clear)" for windows. So it still works, but bit messy.

If you want to contribute, or make a open - suggestion, please feel free to open a pull request.

# Structure(File information)
Even somtimes I confused with this :)

## Code.c
----
Where int main() exists. It handles some kind of menu and global functions like determineSize & clearScreen.

## dumpHex.c
----
This is function-file for dumping hex information to plain text file. Basically read file data and stream to output path(file).

## showHex.c
----
As well is dumpHex, it is also function-file with showing hex data to STDOUT(Console) - printf.
