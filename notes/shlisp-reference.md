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
