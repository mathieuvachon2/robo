#!/usr/bin/env python3
# -*- coding : utf-8 -*-
#
# Ever heard about it?
#

try:
    import pyttsx3 as pyttsx
except ImportError:
    import pyttsx

pasta = '''Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you. It’s a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but not himself.'''


engine = pyttsx.init()
SPEED = engine.getProperty('rate') * 0.5
engine.setProperty('rate', SPEED)
# print(engine.getProperty('voice'))

# engine.say("2 + 2 is 4. Minus 1 that's 3 QUICK MATHS.")
# engine.say('Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you.')
# engine.say(pasta);
# engine.say('You... are already dead.')
with open("out1.txt", "r+") as testFile:
    for line in testFile.readlines():
        engine.say(line)

engine.runAndWait()
