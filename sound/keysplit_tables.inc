@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (keysplit_piano), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

keysplit piano, 36
	split 0, 55
	split 1, 70
	split 2, 91
	split 3, 108

keysplit strings, 36
	split 0, 69
	split 1, 81
	split 2, 108

keysplit trumpet, 36
	split 0, 66
	split 1, 84
	split 2, 108

keysplit tuba, 24
	split 0, 42
	split 1, 108

keysplit french_horn, 36
	split 0, 66
	split 1, 108

keysplit KeySplitTable6, 0
    split 0, 44
    split 1, 58
    split 2, 65
    split 3, 72
    split 4, 77
    split 5, 84
    split 6, 89

keysplit KeySplitTable7, 0
    split 0, 31

keysplit KeySplitTable8, 0
    split 0, 55

keysplit KeySplitTable9, 0
	split 0, 56

keysplit KeySplitTable10, 0
	split 0, 44
	split 1, 58

keysplit KeySplitTable11, 0
    split 0, 48
    split 1, 60
    split 2, 72
    split 3, 84
    split 4, 96

keysplit KeySplitTable11, 0
    split 0, 48
    split 1, 60
    split 2, 72
    split 3, 84
    split 4, 96

keysplit KeySplitTable12, 0
    split 0, 72
    split 1, 84

keysplit KeySplitTable13, 0
    split 0, 49
    split 1, 66
    split 2, 77
    split 3, 89

keysplit KeySplitTable14, 0
    split 0, 67
    split 1, 79
    split 2, 91

keysplit KeySplitTable15, 0
    split 0, 37
    split 1, 53
    split 2, 68

keysplit KeySplitTable16, 0
    split 0, 60
    split 1, 78
    split 2, 90

keysplit KeySplitTable17, 0
    split 0, 60

keysplit KeySplitTable18, 0
    split 0, 36
    split 1, 48
    split 2, 60

keysplit KeySplitTable19, 0
    split 0, 46
    split 1, 58
    split 2, 70

keysplit KeySplitTable20, 0
    split 0, 48
    split 1, 60
	
keysplit KeySplitTable21, 0
    split 0, 48
    split 1, 61
    split 2, 73
    split 3, 80

keysplit KeySplitTable22, 0
    split 0, 44
    split 1, 51

keysplit KeySplitTable23, 0
    split 0, 35
    split 1, 48

keysplit KeySplitTable24, 0
    split 0, 48
    split 1, 70
    split 2, 89

keysplit KeySplitTable25, 0
    split 0, 72

keysplit KeySplitTable26, 0
    split 0, 72
    split 1, 84
    split 2, 96

keysplit KeySplitTable27, 0
    split 0, 49

keysplit KeySplitTable28, 0
    split 0, 44
    split 1, 54
    split 2, 70

keysplit KeySplitTable29, 0
    split 0, 65
    split 1, 85

keysplit KeySplitTable30, 0
    split 0, 53
    split 1, 63

keysplit KeySplitTable31, 0
    split 0, 32

keysplit KeySplitTable32, 0
    split 0, 48
    split 1, 61
    split 2, 73

keysplit KeySplitTable33, 0
    split 0, 73
    split 1, 90

keysplit KeySplitTable34, 0
    split 0, 58
