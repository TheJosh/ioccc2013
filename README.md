ioccc2013
=========

My (failed) IOCCC entry for 2013


Remarks
-------

This is a simple two-player shooting game, which uses SDL for video and event handling
You will require SDL 1.3 to compile this program.
SDL should offer good compatibility with a variery of systems. 


Usage
-----

The game takes a single argument, that being the game world to load. The game comes
with two levels, "outside" and "space". Additional levels can be created by the user
according to the specifications explained later in this document.

The controls for player one are:

* A = Move left
* D = Move right
* W = Jump
* Left shift = Fire

The controls for player two are:

* Left arrow = Move left
* Right arrow = Move right
* Up arrow = Jump
* Right ctrl = Fire

It should be possible to change these controls by editing the source code.


Rule Abuse
----------

I've got more than 1048576 of additional data, but I've put it into a .tar.bz2 file
to keep it under the limit.

In the guidelines, you mention a dislike of gzip:

> Please do not use things like gzip to get around the size limit.
> Be more creative.

That's why I went with bzip2 instead.


Obfuscations
------------

I've tried to make the game feel fairly natural, at least to begin with. The top
third of the source is fairly clean, giving the impression of generally sane codebase.

The illusion decays as you scroll down; the source just gets worse and worse.

Most of my efforts were simply to get under the size limits. The first version of the
game was more than double the allowable size! There are a few macros ("D" "E" "A" "T" "H")
which helped the size restrictions a lot, as well as renaming all of my variables
to single letters ("p" "l" "a" "y" "e" "r" "s"). You'll also notice the macro for
loading the game data.

Finally, I've included a few gotos to simplify the game logic.


Compatibility
-------------

The game has only been tested at 32-bit colour. This colour format is very common
these days and was deemed to be acceptable. The game may operate at other bit depths,
but this hasn't been tested.

I've compiled on Linux using "cc", "gcc", and "clang" compilers. The clang compiler
is quite fussy and emits many warnings, but the others do not.

On the gcc compiler, I've compiled successfully using -ansi, -std=c99 and -std=c89.

As far as I'm aware, there shouldn't be any issues with big or little endian machines,
and there shouldn't be any issues with 32 vs 64 bit machines.

There may be some minor visual issues with RGB-ordered graphics instead of BGR-ordered
graphics. These issues are very minor and should not affect gameplay.


Limitations
-----------

If the video mode can not be used (800x600 at 32-bit colour), an error will be output
and the game will segfault.

If no level argument is provided, an error will be output and the game will segfault.

If a file load fails, an error will be output and the game will segfault.

Game level directory names need to be shorter than sizeof(int) * 7 - sizeof(char) * 6
anything under about 50 characters should be fine in every case.


Level format
------------

Levels are a group of .bmp image files. Magenta (R=255, G=0, B=255) is used for
transparency.

Yes, these filenames are case sensitive. The dimensions need to remain as-is.

a.bmp, d.bmp = Character sprite
g.bmp, n.bmp = Fire
I.bmp, M.bmp = Player number (1, 2)
G.bmp = Winner message
i.bmp = Dead character

L.bmp
Background image. Must be 800x600

o.bmp
Mask for which areas a player can stand on. Black areas are "solid", white areas
are "air".


Copyright notes
---------------

The moon and asteroid images in the "space" level were produced by NASA, and as such
are public domain as per:

http://www.nasa.gov/audience/formedia/features/MP_Photo_Guidelines.html

All other artwork is my own creation (as you can probably tell).


