 Fish is the program (for Windows, Linux, and Macintosh) to edit and upload patches for Shbobo devices (SHNTH and SHTAR). With the release of the new Shbobo SHTAR, the program has received an overhaul. Most noticeably, the older system of tabbed soups has been replaced with a universal map of the whole file as loaded. Thus, soups are all visible, adjacent to each other. It is like a world map, and users are encouraged to use both horizontal and vertical layouts to organize their patch ideas. 

 To facilitate navigation, there is a Zelda, or world map, like the Photoshop navigator, so you can click on different parts of your world and teleport there.

The expression selection system now follows keyboard focus. Only one expression can be focused at any time, when it becomes the current object being 

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

The language shall continue to be C++ and JUCE is the interface, but I'd like to add support for lisp scripting, so there are four types of basic atoms now: crock and fish as in the original Fish, but now it adds "fiberglass" boat and tank. 

They are the computer music opcodes. The necklace chain represents an evolution of the original Gwonzer, to support multiple Shbobo devices (shnth and shtar). Two-way communication (asynchronous/simulcast) is a priority.

 Back to tuning–the shtar shall divide the octave into seventeen equal parts, for 33 total frets. Fourths, fifths and octaves have the customary pearl marker as power spots. Neutral seconds and thirds also have a marker for modal playing. Three strings–a fifth for strumming and an octave for soli. 

Fish is the program (for Windows, Linux, and Macintosh) to edit and upload patches for Shbobo devices (SHNTH and SHTAR). With the release of the new Shbobo SHTAR, the program has received an overhaul. Most noticeably, the older system of tabbed soups has been replaced with a universal map of the whole file as loaded. Thus, soups are all visible, adjacent to each other. It is like a world map, and users are encouraged to use both horizontal and vertical layouts to organize their patch ideas. 

 To facilitate navigation, there is a Zelda, or world map, like the Photoshop navigator, so you can click on different parts of your world and teleport there.

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

CSound virtual instrument using the, again wrong, catalogue of Ancient Greek scales by Kathleen Schlesinger.

Using 8038 sine/triangle/square oscillator chip with linear current input to tune a drum/drone machine by ear.  Linear input means that when the voltage, converted to current by a resistor, doubles, an octave is made: 1volt, 2volt, 4volts roughly for the octaves.

And now, I would like to speak of some of the digital tunings I developed for Shbobo, for use on the Shnth device.  It all flowed pretty naturally from my analog experience, especially with the triangle oscillator that has two controls: one for the slope/speed, and the other for its bounds.  The former control will be called the "nume", for numerator; the latter control is the "deno" for denominator.  You see, they two actually come together to make an "alternative" form of expressing pitch than logarithmic 12tone equal temperament, or what might be used in virtual synthesizers, floats which are converted exponentially.  The nume/deno system is Just Intonation, and you can of course read Harry Partch's book for more info on that.  Also you can see his wonderful misinterpretation/California embellishment of the Ancient Greek kithara.  The first program I wrote in this system was called Just Ints, and like the name it only uses the int type, but it can express pitch in actually very fine increments, using only 8 bits for nume and 8 for deno.  You can multiply that out and not discounting repeat tones, there are about 64k pitches there.  Of course some of them are in very high prime limits, like 197, 199, 211, or 223, so I also developed a way of expressing/modulating the prime limit as you scroll through pitches.  There are two ways developed to scroll through pitches: kingal, tuning the nume and deno separately; and queenal, which uses a dictionary of pitches to allow you to scroll through them "chromatically", although with a high prime limit it almost sounds glissando/analog scroll.

Making my way back to the digital discussion.  We already covered the Just Intonation triangle oscillator with nume and deno.  That is the "Yang: sunlight", and its moon should be the wet State Variable Filter, which is also programmable digitally.  An oscillator and a filter: a song for Becke.  The State Variable Filter, or wave equation, is commonly programmed for all sorts of simulations/stimulations.  But you will note that there is usually another block of code before it which is to "linearize" the pitch.  Yes, the pitch control is actually in a sort of "s curve" kind of like the one for the serge differential amplifier: tapered and logarithmic at the bass and also dwelling in microtones at the top, whilst linear in the middle.  Needless to say, I eliminated the compensating block of code at the beginning.  When you use the "Wave" as it is called in Shlisp, you give it a "rate" parameter, and it is this rate that exhibits its own tuning system, that is like an s curve.  So if you use the same control for the rate of a wave and the nume of a triangle, you will get a slightly different mapping.  It is this mapping difference, this "dissonance of curves" that brings more variety to any composition, i feel. 

 It should thus be apparent that there are many ways of tuning electronic instruments, string instruments, and digital instruments, not to mention woodwinds and brass, and drums.  A platonic tuning system would only control the pitch, and only according to strict, universal rules that are for the betterment of the metropolis.  However, tuning systems are not always quite this way, and I have found it worthwhile to explore the differences amongst tuning systems.  The control of pitch and timbre at the same time are quite common in electronics, but you can also have like a buzzy fret on a guitar, or a squeaky note on a bassoon. I have always had a mantra: "eliminate compensation", which has always brought users closer to the machinery, making it more visceral, rather than farther away, more Platonic, more classical, and "BACH".  I want to emphasize that there are infinite kinds of tuning systems, and most stem from some underlying machinery, like the triangle wave with nume and deno, or the tetrax wave with timbre/pitch duality, or the digital state variable filter with its scurved mapping.  They are like what you get on playing a microtonal guitar, some arbitrary system within which to work.

 As High Zero 2013 approaches the geography of Baltimore, I am summoned to prepare lecture notes for a workshop there, on the Shnth handheld squish synthesizer.  I visit the squash courts of my college in order to gain inspiration but only gain a headache.  However, this reminds me of my collegiate pursual of another courted sport in the past, the sport of racquetball.  For I am not a noncoach of this sport, that of the blue balls that bounce around the room at high velocities, requiring all the inbuilt jerk processing of the human brane to comprehend where it may go next and how to act.  This pursual of intuition was essential in developing the idea of the Shinth, and also a hatred of knobs.  

Phirst let me back up and point out something essential in this discussion, that it is the history of a synthesized word.  The word, "shinth" was initially composed of "shit" and "synth", and was not self deprecating at all.  Rather, it was to point out the glory of thrown away sounds, of alley trash, and yes, of broken fart systems from too much ham.  Later, as this history will point out, the word was appropriated for a digital synthesizer, the "shnth".  Here, with the loss of the vowel "i", it carried a different synthesized meaning.  It is more derived from the abstract sound meaning of the consonant "sh"; the sound of data like as heard on the old modem connections, programs and instructions transmitted at high speed over wires which sounds like the noise produced by the mouth in this consonant.  The rest of the word, "nth", besides carrying the implication of synthesis, also was found to suggest, the idea of discrete numbers; the variable "n" and its cardinality "nth" is used in quantum physics to refer to quantum numbers, which are not gray but integers that express key properties subatomically.  The Shnth of 2013 uses only integer math to synthesize a wide range of classic sounds, including triangle waves, granular synthesis, filters, water, "horses", and strings. 

Now let us set the clock back as far as possible to see where the shinth came from.  In Providence, after a tour of synthesizers and simple string instruments and gongs, I began a process of building my first "rollable synthesizer".  The rollable synthesizer is a theme that I came back to over the years, and it hangs on the wall to be played but also to be experienced as a convenient, and pretty sound installation.  It features the wiring and also exposed circuit boards that synthesizer art cherishes. 

The design of the rollable synthesizer I found to be quite pleasing.  Inspired by a high school art history project, where I was chosen by Mr. Hudenberg to write a paper on Jackson Pollock plus recreate one of his art pieces, or shall I say I received Jackson Pollock by chance operation of picking his name out of a hat.  It was a great assignment, because Pollocks work is actually really fun to recreate and has a great ability to hang on the wall, and embellish canvas in a modern, non representational way.  Finding some historical house paint in a Providence dumpster: colors matched to the 200 year old houses added an extra twist of locating the piece in the place it was built.  Later pieces made in Baltimore used more funky, ghettotastic colors.  The rollable synthesizer had an extra merit, or shall we say it was designed to fill a need, for a portable synthesizer that had presence.  Hung on the wall or other mechanism, the performer in a wonderful, upright position rather than stooping over gear.  Then rolled to pack away neatly.

In retrospect the rollability is least important, however the hangability brought out unseen new dimensions of interface.  The ability to watch a synthesizer like a piece of art, and as I said play it in a standing position, brought out great possibilities for using the sound in space without having the sound object in the center; later with my wife this was used to great effect in dance pieces. 

Having given some history of the form of the rollable synthesizer, I would like to now point out its role in the prehistory of the shinth.  A reading of Deleuze convinced me of the importance of the plane of rhizomality, where circuits interact on an equal footing and not in hierarchical ways.   The rollable synthesizer was a first step to achieving this rhizomality, by abstracting connections into a wordless space.  Although the formal connection points were classed into a binary category, either input and output, the goal was to eventually obfuscate this distinction by making every point both an input and output.  This is an idea passed on to me by Twig Harper, who would later play the shinth in a tour. 

Another prefigure of the rollable synthesizer is that its circuit boards were exposed "trace side out", and could be played circuit bent by touching with fingers.  This reflects my first foray into formalizing circuit bending.  I loved the people involved in it, and the creative, DIY culture around it, but I had a personal problem with using toys for it.  I wanted to make instruments that were designed for that modality, along with all the previous modalities of traditional synthesis, such as patching.  Thus an important initial fact was that they were to be played by hand, not circuit broken with metal, but only bent by human flesh.

One final thing about the rollable synthesizer: it was a collection of twittering modules. Paul Klee's painting, "Twittering Machine", is the inspiration here, and it has also been reproduced verbatim in Deleuze's Thousand Plateaus.  It is key because it offers an aesthetic of machines as beautiful multiplicity, not threatening but also not quite under the complete control of humans.  Rather we can crank the machine and watch it perform wonderful intricate movements.  It's not like we're programming it or texting it, it's more like we have a visceral interface with it.  The crank may seem mechanical, but I can offer a short metaphor to heal that: my dog when I was a kid, you could crank his tail around and that would "wind him up" and he would run around being the spanky little thing that he was.  The rollable synthesizer was a collection of twittering modules, and this means that each was trying to not be a monolithic synth module, like a VCO, but rather things more idiosyncratic, and the difference between modules was more like the difference between birds; there is an inner organic feeling difference rather than a purely rational function.

So here we have the groundwork for the Shinth: visceral touchability, twittering machines, and perhaps the idea of alternative playing postures.  The Shinth proper, was the proposal for a grant in 2003 from the Daniel Langlois Fondation pour L'art la Science et la Technologie.  In it, I described wanting to build a synthesizer conducive to intuition, by touching.  The shinth would not require any patching on the part of the user, since the twittering machines within were wired together on an inner, organalog surface.  The outer surface, in the non traditional format of "trace side out", could be touched to inject electronic noise into ones body, and it is this noise that could be heard by putting metal spoon in mouth which was connected to amplifier.  The Shinth was and still is dangerous, and brings up images of the electric chair.  Current is passed through the body.  Later ideas eliminated the spoon, however potent the analogy may have been.

Twig Harper plays Shinth
The Shinth was "marketed" to the burgeoning noise community of the naughts.  We had a tour across the continent of U.S., being stopped several times by the authorities.  Hard electronic noises were had, but it was also found that subtle ones could be brought out by softer touch.  No really, it wasn't actually marketed.  However, the opportunity to make the shinth brought out a twist in my life that started my business in making analog synths, often based on some notion of touchability.  I found, during the tour, that I could put the shinth out with a tape recorder and blank, 5 minute tapes, and audience members could make their own mixtape of shinth sounds.  The spoon and touch interface was easy to pick up and offered instant gratification with twittering machine sounds.

Now I have presented the historical shinth.  Many other prototypes of this touchable concept were developed in intervening years.  The Din Datin Dudero took this controversial, and dangerous "trace side out" circuit board and added a layer of wood around it.  The wood protected user and synth from breakage at critical nodes, and allowed curating of the most important sandrodes, or "androgynous nodes", to bring them to the surface for playing with hands, wires, or even worms.  Fourses and Fyrall were "coffee table versions" of the Din Datin Dudero.  They all used some version of the infinitely touchable brass node which projects from a wooden chassis.  Later I made analog organs with flexible bars to control the envelope, kindof like the function of the spoon but with much greater expression and noise elimination.  But even with the bars, there was always a sort of electronically touchable interface, using brass nodes.  I also created several paper circuits like "Mr. Grassi", which used touchable brass nodes to trigger harsh but very diverse noise sounds, like a simplified shinth for 5 year old boys. 

Then in 2010, I met Steve Korn and he asked, "what about a digital version of all this work?".  For a while we were naming it "chub", because I had a habit of calling all "chubby" USB devices that name.  But of course there are problems with that word, and in the search for a new word, we took the shinth because of all the touchability ideas, and the idea of containing a twittering machine, and changed it, as I said above, to accomodate the new idea of digital synthesis.  Now we can proceed with the tutorial on programming the shinth, using shlisp, in a graphical environment, called "Fish". 

 The name, "zwave" came from classification work I was doing of curves, looking at sensor data.  When you flex a bar, it makes a sort of "scurve", a rounded form that first goes above zero, and then below.  There came a need, in designing the shnth, to make a facsimile of this, called the zcurve, which is one segment, or a "one-shot," of a triangle wave, which is triggered by external event.  We shall see that this is part of the process of enabling a primitive sort of granular synthesis in its matrix.

  Now you may be confused by the use of a one-shot that has two peaks, one above and one below zero.  It is actually a unique sound to have grains made from these events; it corresponds to the daoist and pretty much everyone else's need for complimentarity, "yin and yang", or from the arp 2000 users' manual "to and fro".  However, the Shnth has two synthesis modes, Dirac and Arab, which offer signed and unsigned maths, respectively.  Those curves are in Dirac mode, because they go positive and negative.  But if you look at them in Arab mode, you see they strongly resemble grain envelopes:

   This was the process of enabling a very primitive, embedded granular synthesis in the Shnth: make triangle waves, then make one-shot, triggerable "swoops" to envelope them.  Let's move on to a few comments about digital, then I would like to demonstrate the applications that work with the Shnth.

    Interlude: Shnth Description
The Shnth, by Shbobo, is a computer music device that features the ARM Cortex M3 32 bit processor. It connects to host computer via USB, wherein the host computer (windows, linux, or macintosh) may read its "squish data" and create graphics and sound. Or, the Shnth itself is a standalone synthesizer, which may be programmed by host in the new language, "Shlisp", by Shbobo. It is potentially self powered, by batteries, which are charged, again, via USB. A switch turns it on, and 16 bit sound comes out a standard stereo 3.5mm jack. Like a laptop; it is "handtop". Four bars on top feel your fingers and two woven antennae below sense flesh, complimented by a battery of buttons. There are red lights.

 Allowing control of bounce and bounds, the analog concepts, yields an important artifact of digitalization: that the two taken together allow rational control of pitch.  Rational refers to Just Intonation, a tuning system pioneered by the ancients but fully described in a modern context by Harry Partch.  It simply means, describing pitch relationships using ratios of numerator and denominator.  I call these snippets of code "nume/deno oscillators," because the speed of bounce is numerator, and the width of bounds is denominator; they are complimentary.  Furthermore, they allow grey intermediary values to be described, without using floating point, or fixed point arithmetic.  In fact, the Shnth uses only an Arm Cortex-M3, which is only integer math.  The decision to use this chipset was made after I wrote the program "Justints," which graphically represents triangle wave tuning systems, using a synthesis core of only integer math, and successfully deployed it on mac, win and lin.  In exploring triangle waves and just intonation with the Shnth, two modalities of tuning movement revealed themselves: kingal and queenal.  Kingal is taking the nume and deno separately and moving them; queenal moves through the compound space melismatically, by having a perspexCUBE, precompiled linked list of all ratio possibilities, in order of actual pitch.  Justints was written in an "8bit pitch space" so they highest prime is 243 or thereabouts.  That yields about 64k unique ratios, so the queenal movement can be very microtonal indeed.  But furthermore, Justints allows you to control the prime-limit of the tuning, so queenal can become a sort of pythagorean pentatonic with a prime limit of 3. 

  As I spoke of earlier, the Shnth is an attempt to do classic computer music in an embedded setting.  Granular synthesis was a big goal, but we could only fit a limited number in.  Thus it is the sound, the hallmark of granular synthesis, but unlimited clouds are not possible.  I like it better, with limitations, and I think you will too!  It was an adventure, quite frustrating at times, especially programming the USB stack.  But everything folds over, and the USB code may have even informed the more creative, sonic codes.  Here's two pdfs for the benefit of the audience:

