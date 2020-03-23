# Fish

## About

### Fish description at petermopar.blogspot.com

Fish is the program (for Windows, Linux, and Macintosh) to edit and upload patches for Shbobo devices (SHNTH and SHTAR). With the release of the new Shbobo SHTAR, the program has received an overhaul. Most noticeably, the older system of tabbed soups has been replaced with a universal map of the whole file as loaded. Thus, soups are all visible, adjacent to each other. It is like a world map, and users are encouraged to use both horizontal and vertical layouts to organize their patch ideas. 

*Retrieved from the Fish 2.0 blog post at the petermopar.blogspot.com website, available at <https://petermopar.blogspot.com/2018/04/fish-20.html>, accessed on Monday March 23 2020.* )


## Download

As of March 2020, the newest version of Fish is available at [shbobo.net](https://shbobo.net/), as shbobo.zip.

It is also included in the folder [original/]() in this repository.

"will definitely do a tuning one. just to try and answer your question here briefly, with the Shnth the opcode 'srate' sets the fundamental frequency (which is 4 octaves below the *actual* sampling rate). if you want to do tonal stuff then its best to specify the srate using 16-bit numbers, then you can dial it in exactly. meng qi made a very helpful srate calculator which gives the 'short' (16-bit number) for each corresponding note on a standard keyboard, its available on the shbobo forum. so basically the nume and deno of an oscillator specify its pitch relationship to that fundamental based on the just intonation tuning system...so for example a horn with a nume of 96 and a deno of 64 will be a perfect 5th above the fundamental (ie 3:2 ratio), one with a nume of 80 and a deno of 64 will be a major 3rd above it (5:4 ratio), etc. there's a couple of really good websites on just intonation online, i can send you the links if you like. its gets really interesting when you get into the larger prime limits like 11 or 13, then you can explore these really hairy microtonal scales. i'll try to explain all this better in a video and associated forum post but hopefully this will help a bit until then."

- in one sense the shnth is like a complete modular synth with 20+ oscillators, 12 filters, 16 lfo/envelopes, 8 n-length sequencers, 8 slews, 12 granular sounds, 16 delay & karplus effects, 8 sample and holds, 8 random generators, 8 pulse divider/staircase generator with a variable length, 8 variable duty cycle pulse wave, unlimited nuts for circuit bending, waveshaping, comparators,etc. plus peter is still developing more opcodes, including some really unique ones, so this is just whats in the initial release. so just by its nature its designed to be flexible. - 2nd, the way peter designed all these operators to work together was pretty ingenius in that any thing in shlisp can be plugged into any other thing in shlisp including of course itself, i.e. there is no distinction between audio, control signals, gestures,etc they are all just 'data'. plus everything in shLISP effects the sound in some way, there are no other programming structures to setup or learn. alot of the power of shLISP come from the simple idea of recursion, i.e. plugging an expression into the parameter of another expression then plugging the output of that into the input of another expression, and so on and so forth. so basically everything can be modulated by everything else..again, just like in a modular synth. - 3rd, there are several ways to pre-compose patches if you desire - there are the sequencers which can store preset parameter values and switch them at the press of a button (sort of like the serge SQP); there is the ability to trigger sounds or switch them on and off, using buttons though actually any gesture or other opcode can do this..you can patch the mic to fire off an envelope which makes a sound audible when the mic input rises above a certain threshold for example. and then a third way to compose is to arrange various situations within a txt and step through them in the order you desire. they can be very subtle variations on the same patch, maybe with diff't parameter values or changing the filter type,etc or they can be completely different sounds in the order you want to perform them..or you can jump around them randomly with a sample and hold for example. 4th, this is all wrapped in a custom-designed touch interface (4 bars, 9 buttons, 2 touch antennas, 1 mic) which can all be used to control any aspect of the synth. again i think this is the critical thing about the shnth - because there is no distinction between 'audio', 'control signals' and 'gestures' any of these things can be substituted for anything else in any expression, as many layers deep as you want. so you can squish the filter cutoff and Q while speaking into the mic which is being AM'd by a triangle wave which is being modulated by the antennas you're touching...and then you can take that whole thing and make it determine the tuning of your granular oscillator which is having its rate and grain envelope being determined by bar presses, etc. i can't stress enough how powerful the simple idea of recursion is when implemented in a 'modular synth' paradigm like this."

## Origin

Let's review what expressions are. In lisp, there is only one kind of expression, besides symbols, the parentheses, (). In Shlisp, as it stands, there are Fish, and Soup, respectively denoted as () and {}. Fish is a DSP core expression, and Soup is a preset. The new version of Fish paves the way for two new types, known as Tank and Boat, denoted as [] and <>. They are not implemented yet, but Tank will be for listing things and Boat will be for scripting things in classical Lisp, thus the possibility for generative patches. Note that the previous version of Fish had randuplicate, and this has been eliminated because Tank and Boat will be bearing the burden of generating permutations of patches.

Fish is the program (for Windows, Linux, and Macintosh) to edit and upload patches for Shbobo devices (SHNTH and SHTAR). With the release of the new Shbobo SHTAR, the program has received an overhaul. Most noticeably, the older system of tabbed soups has been replaced with a universal map of the whole file as loaded. Thus, soups are all visible, adjacent to each other. It is like a world map, and users are encouraged to use both horizontal and vertical layouts to organize their patch ideas.

To facilitate navigation, there is a Zelda, or world map, like the Photoshop navigator, so you can click on different parts of your world and teleport there.

## Menu

"Serve selected" tries to upload the currently selected expression to your device, so you can listen to parts of patches. The command for this is redundant with the simple action of double-clicking. Yes, double click on any soup or fish to quick upload only that code! "Serve all" uploads the complete file. "Change cuisine," as before, is for re-initializing your device's DSP matrix. Note, pick "shnth.bin" or "shtar.bin" appropriate to your device.

Gwonzer is a readout of the data received:

Typewriting
Patches can be composed visually, mostly through dragging and dropping, but also keys can be used almost identically to the way they would be if it were a vanilla text editor. For example, I typed the following keys into a new file:

    {
    (
    "left"
    enter
    (
    "horn"
    enter
    space
    space

Doubleclick
Doubleclick shall become an important tool in this new version. As mentioned, a doubleclick on any recipe will upload it to the device. However, if you double click on the head of an expression, the symbol that denotes its opcode, the program will open up a representative help file from the local "tutor" directory. Thus doubleclicking "horn" will open up "horn.txt" to explain it.
Fish Soup Tank Boat
Let's review what expressions are. In lisp, there is only one kind of expression, besides symbols, the parentheses, (). In Shlisp, as it stands, there are Fish, and Soup, respectively denoted as () and {}. Fish is a DSP core expression, and Soup is a preset. The new version of Fish paves the way for two new types, known as Tank and Boat, denoted as [] and <>. They are not implemented yet, but Tank will be for listing things and Boat will be for scripting things in classical Lisp, thus the possibility for generative patches. Note that the previous version of Fish had randuplicate, and this has been eliminated because Tank and Boat will be bearing the burden of generating permutations of patches.

The rules of fishiness:

* comments are a bare newline, or that begun with semi-colon ;with stuff in between
* balanced expressions: fish () soup {} tank [] boat <>
* guts are numbers or a magical word from the shlisp dictionary

The parser is simply a regex:

```perl
while ($texte=~ /(\n|;[^\n]+\n)|([\{\(\[\<;])|([+\w-]+)|([\}\)\]\>;])/g)
```

To this point I've created the shlisp opcodes in ARM assembly, coded command-line interpreter in c, programmed an editor uploader in C++, created sound games in SDL. Now, add to that list a dummy interpreter for the sake of editing in Javascript, and a dummy interpreter in Perl, for the sake of security against bots.

[] is space list
<> is time function
{} is space situation
() is time sound 

There are four types of basic atoms now: crock and fish as in the original Fish, but now it adds "fiberglass" boat and tank. 

They are the computer music opcodes. The necklace chain represents an evolution of the original Gwonzer, to support multiple Shbobo devices (shnth and shtar). Two-way communication (asynchronous/simulcast) is a priority.

The expression selection system now follows keyboard focus. Only one expression can be focused at any time, when it becomes the current object being edited.

Most are self explanatory, but let's talk about the "Reference" command. This is important for writing patches in core Shlisp, where it enables feedback loops most notably. A reference is simply a fish-expression, with its "cdr" removed, so it is just the "head" or "opcode". Thus (horn 64 64) becomes (horn) as a reference. At runtime, this expression will yield the last computed value of that opcode.

 Here's the "Shbobo" menu. "Serve selected" tries to upload the currently selected expression to your device, so you can listen to parts of patches. The command for this is redundant with the simple action of double-clicking. Yes, double click on any soup or fish to quick upload only that code! "Serve all" uploads the complete file. "Change cuisine," as before, is for re-initializing your device's DSP matrix. Note, pick "shnth.bin" or "shtar.bin" appropriate to your device. Gwonzer is a readout of the data received:

Typewriting
Patches can be composed visually, mostly through dragging and dropping, but also keys can be used almost identically to the way they would be if it were a vanilla text editor. For example, I typed the following keys into a new file:

    {
    (
    "left"
    enter
    (
    "horn"
    enter
    space
    space

This is the patch that Fish thus composed (with random values for spacepress):

 Doubleclick
Doubleclick shall become an important tool in this new version. As mentioned, a doubleclick on any recipe will upload it to the device. However, if you double click on the head of an expression, the symbol that denotes its opcode, the program will open up a representative help file from the local "tutor" directory. Thus doubleclicking "horn" will open up "horn.txt" to explain it.
Fish Soup Tank Boat
