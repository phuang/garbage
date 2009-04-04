#!/usr/bin/python
# vim: et ts=4 sts=4 
import bz2

def load_phrases():
    phrase_dict = {}
    for line in bz2.BZ2File("phrase_freq-1.txt.bz2"):
        #strip line
        line = line.strip()
        phrase, freq = line.split()
    
        # insert phrase and freq into dict
        if phrase in phrase_dict:
            phrase_dict[phrase] = phrase_dict[phrase][0] + int(freq), phrase_dict[phrase][1] + 1
        else:
            phrase_dict[phrase] = (int(freq), 1)
        
    # calculate the average of freq
    phrases = []
    for key, values in phrase_dict.iteritems():
        phrases.append((key, values[0] / values[1]))

    phrases.sort()

    for key, freq in phrases:
        print key, freq
        

def main():
    load_phrases()


if __name__ == "__main__":
    main()
