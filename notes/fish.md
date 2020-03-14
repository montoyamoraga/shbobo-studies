## Fish

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

Fish is the program (for Windows, Linux, and Macintosh) to edit and upload patches for Shbobo devices (SHNTH and SHTAR). With the release of the new Shbobo SHTAR, the program has received an overhaul. Most noticeably, the older system of tabbed soups has been replaced with a universal map of the whole file as loaded. Thus, soups are all visible, adjacent to each other. It is like a world map, and users are encouraged to use both horizontal and vertical layouts to organize their patch ideas. 

The expression selection system now follows keyboard focus. Only one expression can be focused at any time, when it becomes the current object being edited. In the following picture, "slewb" is selected, as indicated by a yellow plaid fill: 

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
Let's review what expressions are. In lisp, there is only one kind of expression, besides symbols, the parentheses, (). In Shlisp, as it stands, there are Fish, and Soup, respectively denoted as () and {}. Fish is a DSP core expression, and Soup is a preset. The new version of Fish paves the way for two new types, known as Tank and Boat, denoted as [] and <>. They are not implemented yet, but Tank will be for listing things and Boat will be for scripting things in classical Lisp, thus the possibility for generative patches. Note that the previous version of Fish had randuplicate, and this has been eliminated because Tank and Boat will be bearing the burden of generating permutations of patches.

The new version of Fish is available at shbobo.net, as shbobo.zip 
