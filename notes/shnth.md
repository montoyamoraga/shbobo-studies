# SHNTH

## About

The Shnth, by Shbobo, is a computer music device that features the ARM Cortex M3 32 bit processor. It connects to host computer via USB, wherein the host computer (windows, linux, or macintosh) may read its "squish data" and create graphics and sound. Or, the Shnth itself is a standalone synthesizer, which may be programmed by host in the new language, "Shlisp", by Shbobo. It is potentially self powered, by batteries, which are charged, again, via USB. A switch turns it on, and 16 bit sound comes out a standard stereo 3.5mm jack. Like a laptop; it is "handtop". Four bars on top feel your fingers and two woven antennae below sense flesh, complimented by a battery of buttons. There are red lights.

The Shnth is an attempt to do classic computer music in an embedded setting.  Granular synthesis was a big goal, but we could only fit a limited number in.  Thus it is the sound, the hallmark of granular synthesis, but unlimited clouds are not possible.  I like it better, with limitations, and I think you will too!  It was an adventure, quite frustrating at times, especially programming the USB stack.  But everything folds over, and the USB code may have even informed the more creative, sonic codes. 

## Description with images

### Front

* 4 vertical wooden bars
* 8 upper LEDs (2 per wooden bar)
* 1x upper row of circular black pushbuttons (1 per wooden bar)
* 1x lower row of circular gray pushbuttons (1 per wooden bar)
* 1 upper center circular red pushbutton 
* 1 microphone (under the hood)

![shnth-front-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-front-small.jpg "shnth-front-small.jpg") ![shnth-front-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-front-notes.jpg "shnth-front-notes.jpg")


### Back

* 1 left antenna, gray, for left hand
* 1 right antenna, yellow and orange, for right hand

![shnth-back-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-back-small.jpg "shnth-back-small.jpg") ![shnth-back-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-back-notes.jpg "shnth-back-notes.jpg")

### Up

* 1x 1/8" stereo line output jack, for headphones or mixer
* 1x USB B cable, for uploading scripts and charging internal batteries
* 1x on/off switch, on is towards USB, off is towards edge of instrument

![shnth-up-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-up-small.jpg "shnth-up-small.jpg") ![shnth-up-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-up-notes.jpg "shnth-up-notes.jpg")

### Down

* 1x 1/8" stereo(?) line input jack

![shnth-down-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-down-small.jpg "shnth-down-small.jpg") ![shnth-down-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-down-notes.jpg "shnth-down-notes.jpg")

### Left

![shnth-left-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-left-small.jpg "shnth-left-small.jpg") ![shnth-left-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-left-notes.jpg "shnth-left-notes.jpg")

### Right

![shnth-right-small.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-right-small.jpg "shnth-right-small.jpg") ![shnth-right-notes.jpg](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/shnth-right-notes.jpg "shnth-right-notes.jpg")


## UNORGANIZED

This pursual of intuition was essential in developing the idea of the Shinth, and also a hatred of knobs.  

Phirst let me back up and point out something essential in this discussion, that it is the history of a synthesized word.  The word, "shinth" was initially composed of "shit" and "synth", and was not self deprecating at all.  Rather, it was to point out the glory of thrown away sounds, of alley trash, and yes, of broken fart systems from too much ham.  Later, as this history will point out, the word was appropriated for a digital synthesizer, the "shnth".  Here, with the loss of the vowel "i", it carried a different synthesized meaning.  It is more derived from the abstract sound meaning of the consonant "sh"; the sound of data like as heard on the old modem connections, programs and instructions transmitted at high speed over wires which sounds like the noise produced by the mouth in this consonant.  The rest of the word, "nth", besides carrying the implication of synthesis, also was found to suggest, the idea of discrete numbers; the variable "n" and its cardinality "nth" is used in quantum physics to refer to quantum numbers, which are not gray but integers that express key properties subatomically.  The Shnth of 2013 uses only integer math to synthesize a wide range of classic sounds, including triangle waves, granular synthesis, filters, water, "horses", and strings. 

The name, "zwave" came from classification work I was doing of curves, looking at sensor data.  When you flex a bar, it makes a sort of "scurve", a rounded form that first goes above zero, and then below.  There came a need, in designing the shnth, to make a facsimile of this, called the zcurve, which is one segment, or a "one-shot," of a triangle wave, which is triggered by external event.  We shall see that this is part of the process of enabling a primitive sort of granular synthesis in its matrix.

Now you may be confused by the use of a one-shot that has two peaks, one above and one below zero.  It is actually a unique sound to have grains made from these events; it corresponds to the daoist and pretty much everyone else's need for complimentarity, "yin and yang", or from the arp 2000 users' manual "to and fro".  However, the Shnth has two synthesis modes, Dirac and Arab, which offer signed and unsigned maths, respectively.  Those curves are in Dirac mode, because they go positive and negative.  But if you look at them in Arab mode, you see they strongly resemble grain envelopes:

This was the process of enabling a very primitive, embedded granular synthesis in the Shnth: make triangle waves, then make one-shot, triggerable "swoops" to envelope them.  Let's move on to a few comments about digital, then I would like to demonstrate the applications that work with the Shnth.

In fact, the Shnth uses only an Arm Cortex-M3, which is only integer math.  The decision to use this chipset was made after I wrote the program "Justints," which graphically represents triangle wave tuning systems, using a synthesis core of only integer math, and successfully deployed it on mac, win and lin.  In exploring triangle waves and just intonation with the Shnth, two modalities of tuning movement revealed themselves: kingal and queenal.  Kingal is taking the nume and deno separately and moving them; queenal moves through the compound space melismatically, by having a perspexCUBE, precompiled linked list of all ratio possibilities, in order of actual pitch.  Justints was written in an "8bit pitch space" so they highest prime is 243 or thereabouts.  That yields about 64k unique ratios, so the queenal movement can be very microtonal indeed.  But furthermore, Justints allows you to control the prime-limit of the tuning, so queenal can become a sort of pythagorean pentatonic with a prime limit of 3. 

And now, I would like to speak of some of the digital tunings I developed for Shbobo, for use on the Shnth device.  It all flowed pretty naturally from my analog experience, especially with the triangle oscillator that has two controls: one for the slope/speed, and the other for its bounds.  The former control will be called the "nume", for numerator; the latter control is the "deno" for denominator.  You see, they two actually come together to make an "alternative" form of expressing pitch than logarithmic 12tone equal temperament, or what might be used in virtual synthesizers, floats which are converted exponentially.  The nume/deno system is Just Intonation, and you can of course read Harry Partch's book for more info on that.  Also you can see his wonderful misinterpretation/California embellishment of the Ancient Greek kithara.  The first program I wrote in this system was called Just Ints, and like the name it only uses the int type, but it can express pitch in actually very fine increments, using only 8 bits for nume and 8 for deno.  You can multiply that out and not discounting repeat tones, there are about 64k pitches there.  Of course some of them are in very high prime limits, like 197, 199, 211, or 223, so I also developed a way of expressing/modulating the prime limit as you scroll through pitches.  There are two ways developed to scroll through pitches: kingal, tuning the nume and deno separately; and queenal, which uses a dictionary of pitches to allow you to scroll through them "chromatically", although with a high prime limit it almost sounds glissando/analog scroll.

The SHNTH is a USB device powered by internal batteries, or, you can connect with standard USB cable to a HOST computer.  When connected, the SHNTH is always recharging its internal batteries.  To hear the SHNTH, connect it to your computer via a USB cable and connect the ⅛” stereo audio output jack to your headphones or use a stereo cable to connect to the AUX input of your amplifier. Depending on the configuration of your amplifier or mixer you may also need a ‘stereo-to-dual mono’ adapter cable. These can be made yourself or purchased cheaply at most electronics distributors such as allectronics.com. Once your SHNTH is plugged in, you should hear some sound.  You can experiment with squishing the bars, and pressing buttons, and hearing how it affects the synthesis patches.
