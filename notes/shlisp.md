# Shlisp

## About

Shlisp is the language that Shbobo instruments use.

Shlisp can be programmed either with text, or through the graphical user interface Fish.

## Opcodes

### Opcodes palette as shown on Fish 2.0

Here is a screenshot of the complete 63 opcodes palette, as shown on the Fish 2.0 graphical user interface.

![alt text](https://github.com/montoyamoraga/shbobo-studies/raw/master/images/fish-opcodes.png "fish-opcodes.png")

*Screenshot of the opcodes on the software Fish, running on a MacOS system, retrieved on Monday March 23 2020*

Here is a transcription of the complete ordered list of 63 opcodes, inlcuding the description that pops up when hovering over them.

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
* Example:
```
;use mic to control volume and pitch of triangle oscillator
([left]
    ([arab]
    ([horn a] ([add] ([slew a]) 90) 190 ([slew a] ([wind]) 245 5))
  )
```

#### finger 

* Description: Top finger fretted. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### corp

* Description: transmits the value of the specified antenna, range is -128 to 127.
* Syntax:
```
[corp] mul add
```
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
;use corp to widely bend horn pitch. slew smooths out steppiness
([horn a] ([slew a] ([corp a] 70 30) 8 8) ([slew b] ([corp b] 30 70) 8 8))
```

#### plank

* Description: all the frets' bits. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### bar

* Description: transmits the value of the specified barre. Typical response is an s-curve (press and release) between -128 to 127.
* Syntax:
```
[bar] mul add
```
* Arguments:
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
;simple 4note saw organ
([saw a] 24 94 ([bar a])) ([saw b] 28 85 ([bar b]))
([saw c] 39 73 ([bar c])) ([saw d] 43 61 ([bar d]))

;simple sidrassi emulation with panning
([horn a] 24 94 ([bar a])) ([horn b] 28 85 ([bar b]))
([horn c] 39 73 ([bar c])) ([horn d] 43 61 ([bar d]))
(pan ([horn a]) ([bar a])) (pan ([horn b]) ([bar b]))
(pan ([horn c]) ([bar c])) (pan ([horn d]) ([bar d]))
```

#### top

* Description: top knob. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### bot

* Description: bottom knob. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### heart 

* Description: heart-shaped chambre. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### bridge

* Description: bridge of the strings. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### minor

* Description: transmits the value of the bottom buttons (0 or 1).
* Syntax:
```
[minor] mul add
```
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
;use minor buttons to play synth
([horn b] 24 126 ([slew b] ([minor b]) 80 5))
([horn c] 36 127 ([slew c] ([minor c]) 80 5))
([horn d] 48 128 ([slew d] ([minor d]) 80 5))
```

#### brass

* Description: brass marked frets. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### major

* Description: transmits the value of the top buttons  (0 or 1)
* Syntax: [major] mul add
* Parameters: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
;use major buttons and bars to play synth with filtering
([wave b] ([saw b] 24 126 ([slew b] ([major b]) 120 10)) 20 ([slew f] ([bar d]) 7 7))
([wave c] ([saw c] 36 127 ([slew c] ([major c]) 120 10)) 20 ([slew g] ([bar c]) 7 7))
([wave d] ([saw d] 48 128 ([slew d] ([major d]) 120 10)) 20 ([slew h] ([bar b]) 7 7))
```

#### steel

* Description: steel marked frets. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### horn

* Description: a triangle oscillator
* Syntax: [horn] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate at which the oscillator rises and falls
  * deno: sets the oscillator’s boundaries (height/depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
;use barres to amplitude modulate
([left]
([horn a]  84 ([corp a] -12 48) ([bar a]))
([horn b]  96 ([corp b] -16 48) ([bar d])))

;frequency modulate the nume with another horn
([right]
([arab]
([horn c]  ([horn b]) ([corp a] 40 96) ([swoop c] ([square] ([bar c]) 50) 4 252))
([horn d]  ([horn a]) ([corp b] 30 126) ([swoop d] ([square] ([bar b]) 50) 6 242)))
```

#### saw

* Description: a sawtooth oscillator (instantaneous rise)
* Syntax: [saw] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate at which the oscillator falls
  * deno: sets the oscillator’s boundaries (height/depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; turn saws on and off with toggle
([right] ([right]
([toggle a] ([major d])
  ([saw a] 22 111 ([swoop a] ([swoop a] 1) 14 55)))
)))
([left]
([toggle b] ([major b])
  ([saw b] 38 111 ([swoop b] ([swoop b] 1) 15 55)))
([toggle c] ([major c])
  ([saw b] 52 111 ([swoop c] ([swoop c] 1) 3 118)))
```

#### toggle

* Description: turns things on and off
* Syntax: [toggle] square
* Arguments: square
  * square: switches the toggle from on to off
* Example:
```
  ; use minor b button to toggle on/off a granular synth you control with corps
([fog a] ([dust a] ([corp a] 100) ([toggle a] ([minor b])))
  ([corp b] 40 20) ([corp a] 20 105) ([corp a] 68 24) ([corp b] 60 64))
```

#### togo

* Description: steps through a sequence of values, advancing one step each time it receives a trigger. takes an unlimited list
* Syntax: [togo a] signotrig liszt
* Arguments: signotrig liszt
  * signotrig: a signed trigger - positive moves one step forward in the sequence, negative moves one step back. in dirac mode it may be necessary to use [square] before some trigger sources
  * liszt: the sequence of values or S-expressions to be stepped through
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
([horn a]
([togo a] ([major d]) 53 13 94 11 52 110 35 26 35 43 36 8)
([togo b] ([major d]) 65 14 32 85 57 43 14 28 50 11 35)
([slew a] ([major d]) 8 8)))
```

#### swoop

* Description: a slow triangle wave, can be used as envelope or LFO
* Syntax: [swoop] trig nume deno mul add
* Arguments: trig nume deno mul add
  * trig/square: begins a swoop cycle
  * nume: sets the rate of rise and fall of the swoop
  * deno: sets the swoop’s boundaries (height or depth)
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; use minor b button to trigger a note with separate envelopes for amplitude,  filter q and filter freq
([wave a] ([horn a] 60 84 ([swoop a] ([minor b]) 3 120))
([swoop b] ([minor b]) 10 30 40 5)
([swoop c] ([minor b]) 2 72))
```

#### mount

* Description: a slow-cycling LFO
* Syntax: [mount] nume deno mul add
* Arguments: nume deno mul add
  * nume: sets the rate of rise and fall
  * deno: sets the boundaries
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; slow moving LFOs modulating pitch (nume and deno) and volume of two saws
([saw a] ([mount a] 73 21) ([mount b] 32 41) ([mount c] 80 100))
([saw b] ([mount d] 13 52) ([mount e] 99 98) ([mount f] 23 83))
```

#### smoke

* Description: generates white smoke (random values)
* Syntax: [smoke] mul add
* Arguments: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; use major b and d buttons to trigger 808 kick and hihat
([smoke a] ([slew a] ([major a]) 100 5 64))
([horn a] 24 127([slew b] ([minor a]) 100 1))
```

#### dust

* Description: pulses spaced randomly over a wide range
* Syntax: [dust] speed mul add
* Arguments: speed mul add
  * speed: sets the density of pulses
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; use the bars to trigger a chaotic cascade of zither strings
([zither a] ([sauce a] 30 ([dust a] ([bar a]))) ([corp a]) ([corp b] 80 40))
([zither b] ([sauce b] 20 ([dust b] ([bar b]))) ([corp b] 70 50) ([corp a]))
([zither c] ([sauce c] 10 ([dust c] ([bar c]))) ([corp a]) ([corp b] 60 60))
([zither d] ([dust d] ([bar d] 60)) ([corp b] 50 70) ([corp a]))
```

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
* Example:
```
; use the bars to trigger a chaotic cascade of grains
([fog a] ([dust a] ([bar a])) ([corp a] 60 10) ([corp b] 90 30)
([salsa a] ([dust a]) ([smoke a])) 80)
([haze b] ([dust b] ([bar b])) ([corp a] 70 20) ([corp b] 100 20)
([salsa b] ([dust b]) ([smoke b])) 60 50))
([right]
([haze c] ([dust c] ([bar c])) ([corp a] 52 10) ([corp b] 96 26)
([salsa c] ([dust c]) ([smoke c])) 40 50)
([swamp d] ([dust d] ([bar d])) ([corp a] 63 20) ([corp b] 88 38)
([salsa d] ([dust d]) ([smoke d])) 20))
```

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
* Example:
```
; use the bars to trigger a chaotic cascade of grains
([fog a] ([dust a] ([bar a])) ([corp a] 60 10) ([corp b] 90 30)
([salsa a] ([dust a]) ([smoke a])) 80)
([haze b] ([dust b] ([bar b])) ([corp a] 70 20) ([corp b] 100 20)
([salsa b] ([dust b]) ([smoke b])) 60 50))
([right]
([haze c] ([dust c] ([bar c])) ([corp a] 52 10) ([corp b] 96 26)
([salsa c] ([dust c]) ([smoke c])) 40 50)
([swamp d] ([dust d] ([bar d])) ([corp a] 63 20) ([corp b] 88 38)
([salsa d] ([dust d]) ([smoke d])) 20))
```

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
* Example:
```
; use the bars to trigger a chaotic cascade of grains
([fog a] ([dust a] ([bar a])) ([corp a] 60 10) ([corp b] 90 30)
([salsa a] ([dust a]) ([smoke a])) 80)
([haze b] ([dust b] ([bar b])) ([corp a] 70 20) ([corp b] 100 20)
([salsa b] ([dust b]) ([smoke b])) 60 50))
([right]
([haze c] ([dust c] ([bar c])) ([corp a] 52 10) ([corp b] 96 26)
([salsa c] ([dust c]) ([smoke c])) 40 50)
([swamp d] ([dust d] ([bar d])) ([corp a] 63 20) ([corp b] 88 38)
([salsa d] ([dust d]) ([smoke d])) 20))
```

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
* Example:
```
; play strings with butts and corps
([string a] ([minor a]) 1 ([corp b]  8 24) 126)
([string b] ([minor b]) 1 ([corp b]  8 20) 125)
([string c] ([minor c]) 1 ([corp a]  4 16) 127)
([string d] ([minor d]) 1 ([corp a]   4 12) 126)
```

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
* Example:
```
; comb filtered resonant pings - play with bars and corps
([right]
([comb a]
  ([water b]
    ([dust b]  ([corp a] 8) -6)
    1 ([corp b] 33 38))
  1  100 110))
([left]
([comb b]
  ([sauce a] 3 ([water c]
    ([dust c]  ([bar a] 18) -8)
    1 ([bar d] 18 28)))
  1  110 112))
```

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
* Example:
```
([srate] 12)
([togo a] ([major b]) 10 15 30)
([togo b] ([major c]) 48 60 72)
([togo c] ([major d]) 40 46 54)
([togo d] ([minor d]) () -36)

([left]

([zither b] ([square] ([swoop b] ([swoop b] 1) ([slew a] ([togo a]) 4 4) 100) 1) ([togo b]) 30 118))

([right]
([zither c] ([square] ([swoop c] ([swoop c] 1) ([slew a]) ([add] 100 ([togo d]))) 1) ([togo c]) 70 118))
```

#### wave

* Description: variable resonance filter - wave is lopass
* Syntax: [wave ] inn q rate mul add
* Arguments: inn q rate mul add
  * inn: the source to be filtered
  * q: sets the filter resonance
  * rate: sets the filter base frequency
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
; waveering a saw wave with freq being swept by mount, vary Q with corp
  ([pan] ([mount a])
([wave a]
    ([saw a] 36 87 )
  ([corp a] 14 2)  ([mount a] 11 97))
```

#### water

* Description: a wash of resonant filter pings
* Syntax: [water ] trig q rate mul add
* Arguments: trig q rate mul add
  * trig: the trigger source
  * q: sets the filter resonance
  * rate: sets the filter base frequency
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### salt

* Description: variable resonance filters - salt is highpass
* Syntax: [salt ] inn q rate mul add
* Arguments: inn q rate mul add
* Example:
```
; waveering a saw wave with freq being swept by mount, vary Q with corp
  ([pan] ([mount a])
([wave a]
    ([saw a] 36 87 )
  ([corp a] 14 2)  ([mount a] 11 97))
```

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
* Example:
```
; set waveshape with barres and corps, waveer output with [corp a] also modulating cutoff)
  ([wave a]
    ([horse a]
      ([bar a] 26 ([corp a] 35 50))
      ([bar b] 14 91)
      ([bar c] 53 61)
      ([bar d] 42 ([corp b] 22 63))
    ([corp b]))
  11  ([corp a] 33 60)
```

#### slew

* Description: slows the movement from one value to the next; works bi-directionally
* Syntax: [slew] inn upp donn mul add
* Arguments: inn upp donn mul add
  * inn: input the expression to be slewed
  * upp: the slew rate for increasing values (lower number is slower)
  * donn: the slew rate for decreasing values (lower number is slower)
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
([slew a]) ….
```

#### wheel

* Description: accumulates values, often used to make bars, buttons and corps increment upwards and/or downwards
* Syntax: [wheel] up down mul add
* Arguments: up down mul add
  * up: value to be positively incremented
  * down: value to be negatively incremented
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
([wheel a] ….
```

#### slave

* Description: count pulses by variable integer amount
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### pulse

* Description: trigger a pulse and decay with variable height
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### sauce

* Description: slows things down by only evaluating expressions after waiting a specified delay period
* Syntax: [sauce] period inn mul add
* Arguments: period inn mul add
  * period: sets the period to wait before evaluating each expression
  * inn: the expression to be slowed down
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
([sauce c] ….
```

#### salsa

* Description: a sample and hold
* Syntax: [salsa] trig inn mul add
* Arguments: trig inn mul add
  * trig: triggers a sample
  * inn: the source to be sampled
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### melody

* Description: record and repeat melodies. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### worm

* Description: rectify and hold an input, like an envelope generator. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### scale

* Description: convert frets to exponential (musical) pitch. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### ladder

* Description: traverse a list of 32 according to input. Only for SHTAR.
* Syntax: TODO
* Arguments: TODO
* Example: TODO

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
* Example: TODO

#### leak

* Description: a noise gate
* Syntax: [leak] inn nume mul add
* Arguments: inn nume mul add
  * inn: the source to be gated
  * nume: the amount of noise gating to apply
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### reflect

* Description: part of a family of waveshapers; reflect - reflects input down at threshold
* Syntax: [reflect] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### return

* Description: part of a family of waveshapers; return-  returns input to 0 at threshold;
* Syntax: [return] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### and

* Description: part of a family of waveshapers; and - bitwise and of two signals
* Syntax: [and] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### xor

* Description: part of a family of waveshapers; xor - bitwise xor of two signals
* Syntax: [xor] inn oth mul add
* Arguments: inn oth mul add
  * inn: input to be waveshaped
  * oth: threshold / other value for logic function
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### negwon

* Description: use this expression for the value -1
* Syntax: (negwon)
* Arguments: TODO
* Example: TODO

#### left

* Description: sends the output to the left DAC
* Syntax: [left] liszt
* Arguments: liszt
  * liszt: takes an unlimited list
* Example: TODO

#### right

* Description: sends the output to the right DAC
* Syntax: [right] liszt
* Arguments: liszt
  * liszt: takes an unlimited list
* Example: TODO

#### square

* Description: a comparator which generates a squarewave if the input is greater than the other
* Syntax: [square] inn oth mul add
* Arguments: inn oth mul add
  * inn: the input
  * oth: the other input (reference)
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### modo

* Description: a circuit-bending type effect whereby one input is mulitplied by another without scaling to keep it in range
* Syntax: [modo] inn oth mul add
* Arguments: inn oth mul add
  * inn: the input
  * oth: the other input
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example: TODO

#### srate

* Description: sets the sampling rate. this is a global variable
* Syntax: [srate] inn
* Arguments: inn
  * inn: sets the sampling rate
* Example:
```
([srate] ….
```

#### mul

* Description: multiplies values in the list
* Syntax: [mul] inn mul add
* Arguments: inn mul add
  * inn: input to be mul’d
  * mul: inn will be multiplied by this value
  * add: this value will be added to output
* Example:
```
[mul] ….
```

#### add

* Description: adds values in the list. can be used to combine several s-expressions into one m-expression. it is infinitely reusable
* Syntax: [add] liszt
* Arguments: liszt
  * liszt: takes an unlimited list
* Example: TODO

#### tar

* Description: transmits the value of the tare button (0 or 1)
* Syntax: [tar] mul add
* Arguments: mul add
  * mul: output will be multiplied by this value
  * add: this value will be added to output
* Example:
```
([tar] ….
```

#### bend

* Description: bend through the fish soup
* Syntax: TODO
* Arguments: TODO
* Example: TODO

#### jump

* Description: if 0, stays put; otherwise  jumps value situations, as demarcated by curly brackets {... }. value may be negative
* Syntax: [jump] value
* Arguments: value
* Example: TODO

trigger a jump to another soup

#### pan

* Description: pans the output through the stereo field. In Dirac mode, -128 is full left and 127 is full right. In Arab mode 0 is full left and 255 is full right
* Syntax: [pan] inn place
* Arguments: inn place
  * Description: 
  * inn: value to be panned
  * place: position in the stereo field
* Example: TODO

#### short

* Description: describes a 16-bit precision number. Use bigg for coarser adjustments and  smal for finer
* Syntax: [short] bigg smal
* Arguments: bigg smal
  * bigg: coarser adjustment of value (msb)
  * smal: finer adjustment of value (lsb)
* Example: TODO

#### dirac

* Description: default, execute using signed numbers, range from -128 to 127
* Syntax: TODO
* Arguments: liszt
* Example: TODO

#### arab

* Description:  esoteric, execute using unsigned numbers, range from 0 to 255
* Syntax: TODO
* Arguments: liszt
* Example: TODO

#### lights

* Description: put an input to the LEDs. Used to address the 8 burgundy LEDs
* Syntax: TODO
* Arguments: inn
  * inn: determines which LEDs are on/off
* Example:
  ```
  ; use LEDs to represent value of [corp a]
  ([lights] ([corp a]))
  ```

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

The latest source code for shLISP can be downloaded at www.shbobo.net. The zip file contains the source and binaries for the three main political parties in the OS arena: mac, lin, and win.  That's macintosh, linux, and windows. To use SHLISP you must be familiar with the terminal.  On Macintosh it is buried down in applications->utilities, but on Linux it is usually a central part of the system. So, after you have unzipped the source to your Desktop, then you must "cd" there.  That means "change directories".  So for example your first step will probably be "cd Desktop".  Then cd into the shnth directory.  Then, cd into the shlsp directory.  From here you can run shlisp as "./shlisp.app".  On Linux, you will also need sudo.  So, to program your device with an example file, here are the respective commands:

./shlisp.app examp/vancouver.txt

sudo ./shlisp examp/vancouver.txt

These program the device with the "vancouver" source text.

Now we should talk about what's in that text.

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

Note the formatting conventions commonly followed: the more you nest, the more you indent.  An open parenthesis is always matched by a closed parenthesis, and the same with square brackets. It may be useful to write your texts with a text editor that does auto-balancing of parantheses such as TextWrangler (http://www.barebones.com/products/textwrangler/ , for Mac only, free).

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
