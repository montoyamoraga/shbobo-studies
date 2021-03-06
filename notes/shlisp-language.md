# Shlisp

## About

Shlisp is the language that Shbobo instruments use.

Shlisp can be programmed either with text, or through the graphical user interface Fish.

## Opcodes

### Opcodes palette as shown on Fish 2.0

Here is a screenshot of the complete 63 opcodes palette, as shown on the Fish 2.0 graphical user interface.

![alt text](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/fish-opcodes.png "fish-opcodes.png")

TODO: cleanup after this

These “patches”, or “presets” are arranged in a larger list of presets, or, if you will, a “situation vector”, max size 256.  Each situation is coded by enclosing curly braces: “{“ and “}”.  The compiler/interpreter, on reaching a new section enclosed by curlies, makes note of the position in the generated byte code stream, to write in a special “byte code vector” at programming time.  Programming time is when the user plugs a SHNTH in to USB, and invokes shlisp, giving a text file that is SHLISP code.  

So, to sum up, shLISP is fundamentally DSP bytecode, that is interpreted and synthesized on the arm cortex embedded chip.  shLISP consists of m-expressions, enclosed by “[“ and “]”, which are simply specifications of a certain musical opcode, such as triangle wave, resonant filter, granular synthesis.  Another “layer of the onion skin” on top of m-expressions, are s-expressions, enclosed by “(“ and “)”.  these are the completions of the functional expressions of DSP, with functional parameters to modulate the sounds.  Of course, an s-expression can be passed another s-expression, as well as a simple old atom.  Let me back up and say that atoms are “chars”, signed or unsigned, they are 8 bits, from 0 to 255 or -128 to 127 depending on context.  This is the “arab-dirac” dichotomy.  Reference to web texts on ancient arabic algebra, which had no negative numbers, and dirac, who first posited anti-matter.  And one more thing, is that: in the primitive shlisp bytecode language, 255 is equal to “(“, as well as negative one.  So you can’t use 255 or -1 as an atom.  And likewise, you can’t use zero as an atom.  Instead you must use the two atoms “()”.  BTW, for negative one you can use an opcode, an m-expression with no parameters: “([negwon])” will generate a strict negative one (don’t worry you won’t ever really need to use it).

Now, you will notice that m-expressions, and s-expressions have been entirely co-opted into the shlisp language.  That was the intent, to use the vintage look and feel of lisp for this synthesis language.  Now, we find that to manage many presets (we have 64k of bytecode program memory, and 256 vectors), we want another layer ontop, like a macro generator, but less like c and more like lisp, which can dynamically manipulate macro functions like lambda expressions, and their content.  So, we propose to utilize the characters “<” and “>” like parentheses, to specify a fully functional, authentic, but minimal dialect of LISP as a meta-layer. This will be the direction of future development.

Is it compiler or interpreter?

Well to answer this question is difficult.  First let me say that there are many functions accomplished by invoking the command “shlisp”.  It is a nexus of activity, and it can even reprogram the synthesizer itself.  That means that you can re-write all of its functionality, if you wish, in ARM CORTEX M3 assembly code.  Let’s talk first about language tiering, with the following bulleted list:

* The embedded synthesizer, as I said, runs ARM CORTEX M3 assembly code.  It scans the bytecode on every sample, and uses m-expressions as keys to a matrix of synth-opcodes, which it efficiently executes for aural satisfaction’s sake.
* So, this synthesizer is reading bytecode which is programmed/reprogrammed by a USB connection from a host.  This bytecode is COMPILED SHLISP.  It has an introductory vector that branches it to all its “situations” so you can traverse them effortlessly.  
* (BTW the USB connection, ADC loop, DAC, systick, theremin timers, are in a not-to-be-reprogrammed space in the embed, they are the bullet-proofed code)
* Now, back to the host.  The host must compile SHLISP BYTECODE and transmit it in chunks of 8bytes, and terminate this stream with something smaller in size than 8bytes.
* The first 64k go into BYTECODE memory, and then you have the option to include another file that is assembled ARM CORTEX M3 code to reprogram the matrix.  We’re gonna completely not worry about this in this white-paper.  It is for another piece of white-paper completely!  The glossary at the end here only applies to standard, shbobo shlisp.
* So we talk about only the first 64k, the SHLISP BYTECODE.  Host has a c program, at the moment, that can convert simple s-expressions and m-expressions into said bytecode, and using core USB HID interface “SetReport”, to program these bytes and their vector table into the embed.  At the moment, this is all filed under the concept of “compiling”

Part 3: Getting Started with shLISP

The latest source code for shLISP can be downloaded at www.shbobo.net. The zip file contains the source and binaries for the three main political parties in the OS arena: mac, lin, and win.  That's macintosh, linux, and windows. To use SHLISP you must be familiar with the terminal.  On Macintosh it is buried down in applications->utilities, but on Linux it is usually a central part of the system. So, after you have unzipped the source to your Desktop, then you must "cd" there.  That means "change directories".  So for example your first step will probably be "cd Desktop".  Then cd into the shnth directory.  Then, cd into the shlsp directory.  From here you can run shlisp as "./shlisp.app".

SHLISP is a computer music programming language based loosely on LISP.  LISP looks vintage, and there are even some "lost" features that we have brought back to life here.  The original specification had two kinds of expressions:

* M-expressions (or ‘mexp’ for short), which we have appropriated to mean "Musical expression," in the sense of "Computer Music".  They may be enclosed by square brackets, which can contain a letter a..d that indicates “which instance” of the mexp.  For example, [horn a],  [horn b] or, if only using a single instance,  just simply horn.
* S-expressions (or ‘sexp’), which holds the archetypal look of LISP.  We use them to mean "Signal expressions," in the sense of "Digital Signal Processing".  Enclosed by parentheses: ([horn a] 52  62).  Note that a sexp contains a mexp at its head.  Thus mexps can be thought of as the "function" or "opcode", and the sexp groups the parameters in a list.

Each mexp, enclosed by square brackets, evaluates to a single atom.  So do numbers.  Briefly, numbers are either signed bytes (-128 .. 127), or unsigned (0 .. 255).

* ;  a comment is preceded by semi colon
* (  ;for specific reason, every text starts with "("
* {  ;this means a situation has begun
* (  ;our first sexpression
* [left]  ;begins with an M-expression, sends the output left
* ([horn a] 82 10)  ;we will hear a triangle wave there
* )  ;close out the left
* }  ;close out the situation

Note the mention of "situation", and using a new kind of bracket to mark it.  We didn't mention this until now, so don't worry.  Situations are gonna be our kind of "patch" or "preset" system.  Basically you can write many of them into one text and, using some special M-expressions, jump between them.  But for the moment we will only focus on one situation at a time.

Let's talk now about the insides of M-expressions.  [left] is a single word within square brackets, which thus has a single meaning.  You can use it as many times as you want, to output sound to the left speaker.  To output to the right, use [right].  [horn a] is another M-expression, but it contains two words.  It is a true opcode, in that it has instances that are unique in time and space.  For "horn", which means triangle wave, there are eight possible instances, from the letter a to the letter h.  Obviously, we are only using one, so we can use the letter a.

Now we can see how M-expressions are synthesized in an S-expression.  [horn a] by itself has no pitch parameters, these are specified by the text in the rest of its S-expression.  horn, in particular, takes two parameters, called "nume" and "deno", short for numerator and denominator.  These are the two parts of a ratio for specifying pitch.  SHLISP is a musical language of Just Intonation, which means it uses these ratios.  We threw out two numbers: 82 and 10, but these can be any number.  Get good at choosing numbers.  The other thing you can do is "nest" other S-expressions as those numbers.

([horn a] ([horn b] 55 32) 10)

Here, [horn a] is frequency modulated by [horn b].  It is the first parameter of [horn a], the nume, that is modulated.  

([horn a] 82 10 ([bar a]))

Here, [horn a] is amplitude modulated by [bar a]. This will make the physical bar control the loudness of the triangle wave.  Notice that nume and deno are unmodulated, but it is a third parameter, called "mul" that is used, to multiply the triangle by the bar.  "mul" is optional, but it is highly used, so it is often following the other, mandatory parameters.

([horn a] ([horn b] 55 32 ([bar a]) 29) 10)

After "mul" comes "add".  It too is optional.  It means to add an offset to the value already computed in multiply.  We use it to add 29 to the value of the modulator, to change the sidebands of the modulation.  The idea of mul and add as final parameters is not new, it comes from "Supercollider".

Superposition means to add several signals together.  This is what the [left] and [right] mexps actually do: they can take a list of many sexpressions and sum them together, like an audio mixer:

```
([left]
  ([horn a] 82 10)
  ([horn b] 83 10)
  ([horn c] 84 10)
  ([horn d] 85 10)  
  ;these four triangle waves should PHASZE
) ;close out the left
```

Note the formatting conventions commonly followed: the more you nest, the more you indent.  An open parenthesis is always matched by a closed parenthesis, and the same with square brackets.

So now we are about to present a complete list of the SHLISP musical expressions.  They are divided into three categories:

* Butts, as in buttons, these give you a signal directly from the physical interface, including the buttons bars, corps (antennae) and the mike.  Since these reflect the physical state of your device you can call them as many times you want without changing anything.
* Nuts, like in "assorted nuts", as in the comestible and also the mechanical fastener.  These are individual helpful things to have, like [left].  Typically they are reusable in many different contexts.
* Ops, as in opcodes.  Every time you call one of these, they calculate something, like ‘move along the triangle wave’ or ‘filter a sound’.  Thus they have either 4 or 8 specific instances, as already mentioned.  You can call each instance as many times as you want, but every time you call it, it changes state. However there is one exception to  this: if you call an opcode and don't put any parameters in the S-expression, ie, just call it by itself, then you will get a signal of what it is at the moment, without changing it.  Thus you can set up a horn ahead of time, and then reference it as a modulation later on.

For example:

```
([horn a] 74 31)
([left]
  ([horn b] ([horn a]) 10)
)
```

Here [horn a] is referenced to FM [horn b].  Note that to reference it, you still need to have parentheses around the square brackets.  

*You can get a list of all shLISP mexps and their parameters at any time by using command line help. Just cd into the shlsp folder and type:          ./shlisp -h (lin), ./shlisp.app -h (mac), .\shlisp.exe -h (win)

If you would like help in chinese then type  -z instead of -h

```
((corp 4 saw) 21 32)
```

an sexp as an opcode, what does that mean?  This is a dynamic mexp.  It can change and it is controlled by corp, scaled down to four pos/neg, and offset by the number for “saw”, which makes the range between the saws and the horns, so you can hear them switching back and forth.  try it.

BUTTS

Without further ado, let's list the butts that you can call, to give you a feel.  When there are parameters, they are listed following the opcode.  For butts, the only parameters are mul and add, which are optional.

* [wind] mul add ;the microphone
* [corp a/b] mul add ;the woven antennae
* [bar a/b/c/d] mul add ;one of the bars
* [minor a/b/c/d] mul add ;the lower buttons
* [major a/b/c/d] mul add ;the upper buttons
* minor are the lower tier of four buttons, and major are the upper.

NUTS
* [left] liszt; means it takes a superposition
* [right] liszt;  an indefinite amount of parameters
* [srate] value ;  change sample rate to this value
* [jump] value ;  if zero stay here, otherwise jump value situations, which may be negative.
* [mul] inn mul add; do a multiplication
* [add] inn add ; do an add
* [reflect] inn oth  mul add ; a type of waveshaper (reflects down at threshold)
* [return] inn oth mul add ; another type of waveshaper (returns to 0 at threshold)
* [and] inn oth ; another waveshaper, also can be logic
* [xor] inn oth ; another waveshaper,  also can be logic
* [modo] inn oth; a circuit-bending effect, multiples two inputs w/o scaling and wraps the result
* [short] big little ;make a 16 bit constant

ShLISP runs on the arm cortex which is a 32-bit processor.  The DSP uses all 32 bits, while signal patching is done with 16 bits.  The byte code you are programming uses 8 bits per byte, so the [short] mexp is telling that you can have finer precision if you need it. [short] is especially useful in generating difference tones, as in the example below. By playing around with both the big and little values of the short as well as the deno value of the horn, a huge range of sonic artifacts can be explored:

```
([right]
  ([horn a] ([short] 110 20) 50)
  ([horn b] ([short] 111 20) 50)
)
```

OPCODES
* [horn a..h] nume deno mul add ; triangle oscillator
* [saw a..h] nume deno mul add ; saw oscillator
* [toggle a..h] square mul add 
* [togo a..h] signotrig liszt
* [swoop a..h] trig nume deno mul add ;a triggered triangular envelope
* [mount a..h] nume deno mul add ; slow LFO
* [smoke a..d] mul add; white smoke
* [dust a..d] amount mul add ;random pulses
* [fog a..d] trig nume deno nume deno mul add ; granular oscillator
* [haze a..d] trig nume deno nume deno mul add ; granular oscillator
* [swamp a..d] trig nume deno nume deno mul add ; granular oscillator
* [string a..d] trig nume deno feedback mul add ; stringlus-strong
* [comb a..d] inn nume deno feedback mul add ; comb filter
* [zither a..d] trig deno feedback mul add; a quartet of strings
* [wave a..d] inn q freq mul add ; resonant lopass filter
* [water a..d] trig q freq mul add ; triggered filter pings
* [salt a..d] inn q freq mul add ; hipass filter
* [horse a..d] upp don upp don mul add ; fourses oscillator
* [slew a..d] inn upp don mul add ; resonant filter
* [wheel a..d] upp don mul add ; triggered filter pings
* [sauce a..d] period mul add; slows things down
* [salsa a..d] trig inn mul add ; sample and hold
* [square] inn ref mul add ;a comparator

ShLlisp is running on a 32-bit processor but it is not float computation;  rather, it is computing sounds using "Just Intonation".  Thus it is using "just integers".  In floats, when you multiply signals, they are usually between -1 and 1, so the result doesn't go out of range, but stays neatly between unary values.  The same thing can be done with integers, but how to specify it?  

The mul parameter is actually better thought of as a "scaling" value.  In signed numbers, 127 is full steam, -128 is full anti-steam.  So we can write out what mul really represents as:

"signal * mul / 128".

 That means it is divided back down by 128 to stay within range.

We mentioned signed versus unsigned so now we are forced to speak about this dichotomy.  In signal processing, most signals are thought of as having positive and negative components, so signed math is the most natural.  However, the arm cortex supports both signed and unsigned equally so to offer the unique features of unsigned signal processing, you can switch into "arab" mode at any point in your code:

([arab]

        ([horn a] 231 129) ;note nume is above 127!

) ;arab math is only positive, between 0 and 255

This is an homage to ancient Arabic algebra, which had no negative numbers.  There is a corresponding switch back to signed math, called [dirac], named after the physicist who discovered anti-particles.  It is the default mode.

DIRAC = -128 .. 127; donotuse -1, 0

ARAB = 0 .. 254; donotuse 255, 0

If you really need -1, there is a nut to get it: ([negwon])

If you need zero, you must consult the ancient annals of the original LISP language.  There, 0 = ().  So to get zero you type an empty s-expression!

The reason you do not use these two numbers, is because 255, which is equivalent to -1 in chars, is the shlisp bytecode for "(".  0 is the shlisp bytecode for ")".  So you see, all the parentheses you type out in your program do not "boil out" on shlisping, but are sent directly to the device Flash as 255s and Zeros.

Now we will back up and cover a special mode called "Orange Light Affair".  This has two purposes: if you have written bad code to the device and it locks up, you can enter this mode, which also initiates a "fast charge" of the batteries.  You can leave it in this mode and it will automatically exit after about 2 minutes.  During that time, the synthesizer is off, to prevent running viral code, but you can still reprogram it.

More Info on Selected Opcodes

Fog began as an interpretation of the classic Csound opcode, “grain”. It was chosen that four grains would be available per, so it was originally named forg but that sounded too much like borg, bjork, and korg. That said, it has the emulation of primitive “nineties” granular boxes, Capybara sounds, although Csound was my preference, under the tutelage of Gary Lee Nelson. Fog is like mist in the woods, or the ocean. That said, it is better to think of it as a string quartet, as it is, in fact, a musical expression. The string quartet is handed notes by a stroke of the baton, that baton of the conductor. He triggers each player in turn, who memorizes four runes, to play until triggered again in turn. So you see if you run the trigger fast enough and the grains are short enough, it can be like a cloud. The trick is in the nume deno nume deno. Giving them smoke, muld down, and offsetted to your cloud zone DC. Then give the trig a feed of dust, to make the coincidental, “brownian walk” motion of classical granular synthesis.

Swamp, like fog, is a string quartet.  This means that there are four voices per operator, so you get 16 total, because there are four operators. Swamp, as a musical expression, is almost exactly the same as fog; it has a conductor, who triggers grains in turn, who then memorize four runes (nume deno nume deno).  But there is one difference, we will get to later.

Let me explain these four runes.  Each grain has two parts: a swoop and a horn, built into it.  When the swoop is triggered, it goes up and down, or makes a scurve, depending if you are Arab or Dirac.  This swoop goes on to mul by the value of the horn, which is saying "VCA", i.e. it envelopes it.  It modulates the volume of it, making the traditional grain surrounded by silence.

Fog and swamp both output a superposition of the four grains.  Now, what is the difference between fog and swamp?  In swamp, the swoops are added to the static value of the horn deno, making them swoop in pitch like swamp creatures!
