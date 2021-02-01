# Shlisp reference

Here is a transcription of the complete ordered list of 63 opcodes.

Most opcodes can be used for programming both Shbobo instruments (Shnth and Shtar), and they are shown with a white background on the opcodes palette.

The few ones that are only for the Shtar and not for the Shbobo, are shown with a red background on the opcode palette, and in this transcription that is represented with **bold letters**.

* [wind](#wind): microphone
* [**finger**](#finger): top finger fretted
* [corp 2](#corp): antennae
* [**plank 2**](#plank): all the frets' bits
* [bar 4](#bar): barflex
* [**top**](#top): top knob
* [**bot**](#bot): bottom knob
* [**heart**](#heart): heart-shaped chambre
* [**bridge**](#bridge): bridge of the strings
* [minor 4](#minor): lower buttons
* [**brass 4**](#brass): brass marked frets
* [major 4](#major): upper buttons
* [**steel 4**](#steel): steel marked frets
* [horn 8](#horn): triangle waveform
* [saw 8](#saw): sawtooth waveform
* [toggle 8](#toggle): trigger a flipflop
* [togo 8](#togo): sequencer
* [swoop 8](#swoop): trigger a pyramid
* [mount 8](#mount): slow triangle waveform
* [smoke 8](#smoke): random noise
* [dust 8](#dust): random pulses
* [fog 4](#fog): trigger triangular grains
* [haze 4](#haze): trigger sawtooth grains
* [swamp 4](#swamp): trigger swoping grains
* [string 4](#string): trigger a pluckd string
* [comb 4](#comb): input sound to the string
* [zither 4](#zither): trigger a bunch strings
* [wave 8](#wave): low pass filter
* [water 4](#water): trigger a cluster of waves
* [salt 4](#salt): hi pass filter
* [horse 4](#horse): variable duty sawtri
* [slew 8](#slew): filter a signal with different up and down rates
* [wheel 8](#wheel): input numbers to bring the value up or down
* [slave 8](#slave): count pulses by variable integer amount
* [pulse 8](#pulse): trigger a pulse and decay with variable height
* [sauce 8](#sauce): slow an input by a period
* [salsa 8](#salsa): selectively trigger an input
* [**melody 4**](#melody): record and repeat melodies
* [**worm 4**](#worm): rectify and hold an input, like an envelope generator
* [**scale 4**](#scale): convert frets to exponential (musical) pitch
* [**ladder 4**](#ladder): traverse a list of 32 according to input
* [press 4](#press): compressor
* [leak 4](#leak): leak DC from a sound
* [reflect](#reflect): waveshaper that reflects
* [return](#return): waveshaper that returns
* [and](#and): bitwise and of two signals
* [xor](#xor): bitwise xor of two signals
* [negwon](#negwon): return negative one
* [left](#left): send sound out the left
* [right](#right): send sound out the right
* [square](#square): make an input into a square, compared against an optional other
* [modo](#modo): multiply without scaling
* [srate](#srate): change the sample rate!
* [mul](#mul): multiply scaling
* [add](#add): add a lizst
* [tar](#tar): tarbutton
* [bend](#bend): bend through the fish soup
* [jump](#jump): trigger a jump to another soup
* [pan](#pan): send sound out spatialized
* [short](#short): sixteen bit precision number
* [dirac](#dirac): default, execute using negative numbers
* [arab](#arab): esoteric, execute using no negatives
* [lights](#lights): put an input to the LEDs

### Opcodes reference

#### wind

* Description: Transmits the value received by the onboard microphone.
* Syntax:
```
[wind] mul add
```
* Arguments: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### finger 

* Description: Top finger fretted. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### corp

* Description: transmits the value of the specified antenna, range is -128 to 127.
* Syntax:
```
[corp] mul add
```
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### plank

* Description: all the frets' bits. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### bar

* Description: transmits the value of the specified barre. Typical response is an s-curve (press and release) between -128 to 127.
* Syntax:
```
[bar] mul add
```
* Arguments:
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### top

* Description: top knob. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### bot

* Description: bottom knob. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### heart 

* Description: heart-shaped chambre. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### bridge

* Description: bridge of the strings. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### minor

* Description: transmits the value of the bottom buttons (0 or 1).
* Syntax:
```
[minor] mul add
```
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### brass

* Description: brass marked frets. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### major

* Description: transmits the value of the top buttons  (0 or 1)
* Syntax: [major] mul add
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### steel

* Description: steel marked frets. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### horn

* Description: a triangle oscillator
* Syntax: [horn] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate at which the oscillator rises and falls
  * deno: sets the oscillator’s boundaries (height/depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### saw

* Description: a sawtooth oscillator (instantaneous rise)
* Syntax: [saw] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate at which the oscillator falls
  * deno: sets the oscillator’s boundaries (height/depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### toggle

* Description: turns things on and off
* Syntax: [toggle] square
* Arguments: square
  * square: switches the toggle from on to off

#### togo

* Description: steps through a sequence of values, advancing one step each time it receives a trigger. takes an unlimited list
* Syntax: [togo a] signotrig liszt
* Arguments: signotrig liszt
  * signotrig: a signed trigger - positive moves one step forward in the sequence, negative moves one step back. in dirac mode it may be necessary to use [square] before some trigger sources
  * liszt: the sequence of values or S-expressions to be stepped through
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### swoop

* Description: a slow triangle wave, can be used as envelope or LFO
* Syntax: [swoop] trig nume deno mul add
* Arguments: trig nume deno mul add
  * trig/square: begins a swoop cycle
  * nume: sets the rate of rise and fall of the swoop
  * deno: sets the swoop’s boundaries (height or depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### mount

* Description: a slow-cycling LFO
* Syntax: [mount] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate of rise and fall
  * deno: sets the boundaries
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### smoke

* Description: generates white smoke (random values)
* Syntax: [smoke] mul add
* Arguments: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### dust

* Description: pulses spaced randomly over a wide range
* Syntax: [dust] speed mul add
* Arguments: speed mul add
  * speed: sets the density of pulses
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### fog

* Description: granular synthesis-type effect, utilizing an internal oscillator and envelope to articulate the grains. fog uses horn grains.
* Syntax: [fog] trig nume deno nume deno mul add
* Arguments: trig nume deno nume deno mul add
  * trig: trigger the playing of grains
  * nume: sets the rate of rise/fall of the internal envelope
  * deno: sets the boundaries (height/depth) of the internal envelope
  * nume: sets the rise/fall of the internal oscillator
  * deno: sets the boundaries (heigh/depth) of the internal oscillator
  * mul:  output will be multiplied by this value
  * add: this value will be added to output

#### haze

* Description: granular synthesis-type effect, utilizing an internal oscillator and envelope to articulate the grains. haze uses saw grains
* Syntax: [haze] trig nume deno nume deno mul add
* Arguments: trig nume deno nume deno mul add
  * trig: trigger the playing of grains
  * nume: sets the rate of rise/fall of the internal envelope
  * deno: sets the boundaries (height/depth) of the internal envelope
  * nume: sets the rise/fall of the internal oscillator
  * deno: sets the boundaries (heigh/depth) of the internal oscillator
  * mul:  output will be multiplied by this value
  * add: this value will be added to output

#### swamp

* Description: granular synthesis-type effect, utilizing an internal oscillator and envelope to articulate the grains. uses animated grains
* Syntax: [swamp] trig nume deno nume deno mul add
* Arguments: trig nume deno nume deno mul add
  * trig: trigger the playing of grains
  * nume: sets the rate of rise/fall of the internal envelope
  * deno: sets the boundaries (height/depth) of the internal envelope
  * nume: sets the rise/fall of the internal oscillator
  * deno: sets the boundaries (heigh/depth) of the internal oscillator
  * mul:  output will be multiplied by this value
  * add: this value will be added to output

#### string

* Description: a stringlus-strong string synthesis algorithm
* Syntax: [string] trig nume deno feedback mul add
* Arguments: trig nume deno feedback mul add
  * trig:  the excitation source
  * nume: numerator of delay period (set to 1 for lower pitch effects)
  * deno: denominator of delay period (set higher for lower pitch effects)
  * feedback: sets the feedback amount (set higher for more resonance)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### comb

* Description: a comb filter with variable delay time and feedback
* Syntax: [comb] inn nume deno feedback mul add
* Arguments: inn nume deno feedback mul add
  * inn: the source to be delayed
  * nume: numerator of delay period (set to 1 for lower pitch effects)
  * deno: denominator of delay period (set higher for lower pitch effects)
  * feedback: sets the feedback amount (set higher for more resonance)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### zither

* Description: stringlus-strong synthesis consisting of 4 plucks per instance
* Syntax: [string] trig nume deno feedback mul add
* Arguments: trig nume deno feedback mul add
  * trig: the excitation source
  * nume: numerator of delay period (set to 1 for lower pitch effects)
  * deno: denominator of delay period (set higher for lower pitch effects)
  * feedback: sets the feedback amount (set higher for more resonance)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### wave

* Description: variable resonance filter - wave is lopass
* Syntax: [wave ] inn q rate mul add
* Arguments: inn q rate mul add
  * inn: the source to be filtered
  * q: sets the filter resonance
  * rate: sets the filter base frequency
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### water

* Description: a wash of resonant filter pings
* Syntax: [water ] trig q rate mul add
* Arguments: trig q rate mul add
  * trig: the trigger source
  * q: sets the filter resonance
  * rate: sets the filter base frequency
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### salt

* Description: variable resonance filters - salt is highpass
* Syntax: [salt ] inn q rate mul add
* Arguments: inn q rate mul add

#### horse

* Description: an oscillator with independently settable rise and fall and upper/lower boundaries
* Syntax: [horse] nume nume deno deno mul add
* Arguments: nume nume deno deno mul add
  * nume: sets the rate at which the oscillator rises
  * deno: sets the rate at which the oscillator falls
  * nume: sets the oscillator’s upper boundary (height)
  * deno: sets the oscillator’s lower boundary (depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### slew

* Description: slows the movement from one value to the next; works bi-directionally
* Syntax: [slew] inn upp donn mul add
* Arguments: inn upp donn mul add
  * inn: input the expression to be slewed
  * upp: the slew rate for increasing values (lower number is slower)
  * donn: the slew rate for decreasing values (lower number is slower)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### wheel

* Description: accumulates values, often used to make bars, buttons and corps increment upwards and/or downwards
* Syntax: [wheel] up down mul add
* Arguments: up down mul add
  * up: value to be positively incremented
  * down: value to be negatively incremented
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### slave

* Description: count pulses by variable integer amount
* Syntax: TODO
* Arguments: TODO

#### pulse

* Description: trigger a pulse and decay with variable height
* Syntax: TODO
* Arguments: TODO

#### sauce

* Description: slows things down by only evaluating expressions after waiting a specified delay period
* Syntax: [sauce] period inn mul add
* Arguments: period inn mul add
  * period: sets the period to wait before evaluating each expression
  * inn: the expression to be slowed down
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### salsa

* Description: a sample and hold
* Syntax: [salsa] trig inn mul add
* Arguments: trig inn mul add
  * trig: triggers a sample
  * inn: the source to be sampled
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### melody

* Description: record and repeat melodies. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### worm

* Description: rectify and hold an input, like an envelope generator. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### scale

* Description: convert frets to exponential (musical) pitch. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### ladder

* Description: traverse a list of 32 according to input. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO

#### press

* Description: a compressor
* Syntax: [press] inn att dec mul add
* Arguments: inn att dec mul add
  * inn: the source to be compressed
  * att: the attack of the compressor
  * dec: the decay of the compressor
  * thresh: the threshold above which the compressor kicks in
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### leak

* Description: a noise gate
* Syntax: [leak] inn nume mul add
* Arguments: inn nume mul add
  * inn: the source to be gated
  * nume: the amount of noise gating to apply
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### reflect

* Description: part of a family of waveshapers; reflect - reflects input down at threshold
* Syntax: [reflect] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### return

* Description: part of a family of waveshapers; return-  returns input to 0 at threshold;
* Syntax: [return] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### and

* Description: part of a family of waveshapers; and - bitwise and of two signals
* Syntax: [and] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### xor

* Description: part of a family of waveshapers; xor - bitwise xor of two signals
* Syntax: [xor] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### negwon

* Description: use this expression for the value -1
* Syntax: (negwon)
* Arguments: TODO

#### left

* Description: sends the output to the left DAC
* Syntax: [left] liszt
* Arguments: liszt
  * liszt: takes an unlimited list

#### right

* Description: sends the output to the right DAC
* Syntax: [right] liszt
* Arguments: liszt
  * liszt: takes an unlimited list

#### square

* Description: a comparator which generates a squarewave if the input is greater than the other
* Syntax: [square] inn oth mul add
* Arguments: inn oth mul add
  * inn: the input
  * oth: the other input (reference)
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### modo

* Description: a circuit-bending type effect whereby one input is mulitplied by another without scaling to keep it in range
* Syntax: [modo] inn oth mul add
* Arguments: inn oth mul add
  * inn: the input
  * oth: the other input
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### srate

* Description: sets the sampling rate. this is a global variable
* Syntax: [srate] inn
* Arguments: inn
  * inn: sets the sampling rate

#### mul

* Description: multiplies values in the list
* Syntax: [mul] inn mul add
* Arguments: inn mul add
  * inn: input to be mul’d
  * mul: inn will be multiplied by this value
  * add: this value will be added to output

#### add

* Description: adds values in the list. can be used to combine several s-expressions into one m-expression. it is infinitely reusable
* Syntax: [add] liszt
* Arguments: liszt
  * liszt: takes an unlimited list

#### tar

* Description: transmits the value of the tare button (0 or 1)
* Syntax: [tar] mul add
* Arguments: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output

#### bend

* Description: bend through the fish soup
* Syntax: TODO
* Arguments: TODO

#### jump

* Description: if 0, stays put; otherwise  jumps value situations, as demarcated by curly brackets {... }. value may be negative
* Syntax: [jump] value
* Arguments: value

trigger a jump to another soup

#### pan

* Description: pans the output through the stereo field. In Dirac mode, -128 is full left and 127 is full right. In Arab mode 0 is full left and 255 is full right
* Syntax: [pan] inn place
* Arguments: inn place
  * Description: 
  * inn: value to be panned
  * place: position in the stereo field

#### short

* Description: describes a 16-bit precision number. Use bigg for coarser adjustments and  smal for finer
* Syntax: [short] bigg smal
* Arguments: bigg smal
  * bigg: coarser adjustment of value (msb)
  * smal: finer adjustment of value (lsb)

#### dirac

* Description: default, execute using signed numbers, range from -128 to 127
* Syntax: TODO
* Arguments: liszt

#### arab

* Description:  esoteric, execute using unsigned numbers, range from 0 to 255
* Syntax: TODO
* Arguments: liszt

#### lights

* Description: put an input to the LEDs. Used to address the 8 burgundy LEDs
* Syntax: TODO
* Arguments: inn
  * inn: determines which LEDs are on/off
