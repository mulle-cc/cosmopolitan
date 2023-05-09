#if 0
/*─────────────────────────────────────────────────────────────────╗
│ To the extent possible under law, Justine Tunney has waived      │
│ all copyright and related or neighboring rights to this file,    │
│ as it is written in the following disclaimers:                   │
│   • http://unlicense.org/                                        │
│   • http://creativecommons.org/publicdomain/zero/1.0/            │
╚─────────────────────────────────────────────────────────────────*/
#endif
#include "libc/stdio/stdio.h"
#include "libc/str/str.h"

int _cescapec2(int);

uint32_t kCescapeC[256] = {
    [0] = '\\' | '0' << 8 | '0' << 16 | '0' << 24,
    [1] = '\\' | '0' << 8 | '0' << 16 | '1' << 24,
    [2] = '\\' | '0' << 8 | '0' << 16 | '2' << 24,
    [3] = '\\' | '0' << 8 | '0' << 16 | '3' << 24,
    [4] = '\\' | '0' << 8 | '0' << 16 | '4' << 24,
    [5] = '\\' | '0' << 8 | '0' << 16 | '5' << 24,
    [6] = '\\' | '0' << 8 | '0' << 16 | '6' << 24,
    [7] = '\\' | 'a' << 8,
    [8] = '\\' | 'b' << 8,
    [9] = '\\' | 't' << 8,
    [10] = '\\' | 'n' << 8,
    [11] = '\\' | 'v' << 8,
    [12] = '\\' | 'f' << 8,
    [13] = '\\' | 'r' << 8,
    [14] = '\\' | '0' << 8 | '1' << 16 | '6' << 24,
    [15] = '\\' | '0' << 8 | '1' << 16 | '7' << 24,
    [16] = '\\' | '0' << 8 | '2' << 16 | '0' << 24,
    [17] = '\\' | '0' << 8 | '2' << 16 | '1' << 24,
    [18] = '\\' | '0' << 8 | '2' << 16 | '2' << 24,
    [19] = '\\' | '0' << 8 | '2' << 16 | '3' << 24,
    [20] = '\\' | '0' << 8 | '2' << 16 | '4' << 24,
    [21] = '\\' | '0' << 8 | '2' << 16 | '5' << 24,
    [22] = '\\' | '0' << 8 | '2' << 16 | '6' << 24,
    [23] = '\\' | '0' << 8 | '2' << 16 | '7' << 24,
    [24] = '\\' | '0' << 8 | '3' << 16 | '0' << 24,
    [25] = '\\' | '0' << 8 | '3' << 16 | '1' << 24,
    [26] = '\\' | '0' << 8 | '3' << 16 | '2' << 24,
    [27] = '\\' | '0' << 8 | '3' << 16 | '3' << 24,
    [28] = '\\' | '0' << 8 | '3' << 16 | '4' << 24,
    [29] = '\\' | '0' << 8 | '3' << 16 | '5' << 24,
    [30] = '\\' | '0' << 8 | '3' << 16 | '6' << 24,
    [31] = '\\' | '0' << 8 | '3' << 16 | '7' << 24,
    [32] = ' ',
    [33] = '!',
    [34] = '\\' | '"' << 8,
    [35] = '#',
    [36] = '$',
    [37] = '%',
    [38] = '&',
    [39] = '\\' | '\'' << 8,
    [40] = '(',
    [41] = ')',
    [42] = '*',
    [43] = '+',
    [44] = ',',
    [45] = '-',
    [46] = '.',
    [47] = '/',
    [48] = '0',
    [49] = '1',
    [50] = '2',
    [51] = '3',
    [52] = '4',
    [53] = '5',
    [54] = '6',
    [55] = '7',
    [56] = '8',
    [57] = '9',
    [58] = ':',
    [59] = ';',
    [60] = '<',
    [61] = '=',
    [62] = '>',
    [63] = '?',
    [64] = '@',
    [65] = 'A',
    [66] = 'B',
    [67] = 'C',
    [68] = 'D',
    [69] = 'E',
    [70] = 'F',
    [71] = 'G',
    [72] = 'H',
    [73] = 'I',
    [74] = 'J',
    [75] = 'K',
    [76] = 'L',
    [77] = 'M',
    [78] = 'N',
    [79] = 'O',
    [80] = 'P',
    [81] = 'Q',
    [82] = 'R',
    [83] = 'S',
    [84] = 'T',
    [85] = 'U',
    [86] = 'V',
    [87] = 'W',
    [88] = 'X',
    [89] = 'Y',
    [90] = 'Z',
    [91] = '[',
    [92] = '\\' | '\\' << 8,
    [93] = ']',
    [94] = '^',
    [95] = '_',
    [96] = '`',
    [97] = 'a',
    [98] = 'b',
    [99] = 'c',
    [100] = 'd',
    [101] = 'e',
    [102] = 'f',
    [103] = 'g',
    [104] = 'h',
    [105] = 'i',
    [106] = 'j',
    [107] = 'k',
    [108] = 'l',
    [109] = 'm',
    [110] = 'n',
    [111] = 'o',
    [112] = 'p',
    [113] = 'q',
    [114] = 'r',
    [115] = 's',
    [116] = 't',
    [117] = 'u',
    [118] = 'v',
    [119] = 'w',
    [120] = 'x',
    [121] = 'y',
    [122] = 'z',
    [123] = '{',
    [124] = '|',
    [125] = '}',
    [126] = '~',
    [127] = '\\' | '1' << 8 | '7' << 16 | '7' << 24,
    [128] = '\\' | '2' << 8 | '0' << 16 | '0' << 24,
    [129] = '\\' | '2' << 8 | '0' << 16 | '1' << 24,
    [130] = '\\' | '2' << 8 | '0' << 16 | '2' << 24,
    [131] = '\\' | '2' << 8 | '0' << 16 | '3' << 24,
    [132] = '\\' | '2' << 8 | '0' << 16 | '4' << 24,
    [133] = '\\' | '2' << 8 | '0' << 16 | '5' << 24,
    [134] = '\\' | '2' << 8 | '0' << 16 | '6' << 24,
    [135] = '\\' | '2' << 8 | '0' << 16 | '7' << 24,
    [136] = '\\' | '2' << 8 | '1' << 16 | '0' << 24,
    [137] = '\\' | '2' << 8 | '1' << 16 | '1' << 24,
    [138] = '\\' | '2' << 8 | '1' << 16 | '2' << 24,
    [139] = '\\' | '2' << 8 | '1' << 16 | '3' << 24,
    [140] = '\\' | '2' << 8 | '1' << 16 | '4' << 24,
    [141] = '\\' | '2' << 8 | '1' << 16 | '5' << 24,
    [142] = '\\' | '2' << 8 | '1' << 16 | '6' << 24,
    [143] = '\\' | '2' << 8 | '1' << 16 | '7' << 24,
    [144] = '\\' | '2' << 8 | '2' << 16 | '0' << 24,
    [145] = '\\' | '2' << 8 | '2' << 16 | '1' << 24,
    [146] = '\\' | '2' << 8 | '2' << 16 | '2' << 24,
    [147] = '\\' | '2' << 8 | '2' << 16 | '3' << 24,
    [148] = '\\' | '2' << 8 | '2' << 16 | '4' << 24,
    [149] = '\\' | '2' << 8 | '2' << 16 | '5' << 24,
    [150] = '\\' | '2' << 8 | '2' << 16 | '6' << 24,
    [151] = '\\' | '2' << 8 | '2' << 16 | '7' << 24,
    [152] = '\\' | '2' << 8 | '3' << 16 | '0' << 24,
    [153] = '\\' | '2' << 8 | '3' << 16 | '1' << 24,
    [154] = '\\' | '2' << 8 | '3' << 16 | '2' << 24,
    [155] = '\\' | '2' << 8 | '3' << 16 | '3' << 24,
    [156] = '\\' | '2' << 8 | '3' << 16 | '4' << 24,
    [157] = '\\' | '2' << 8 | '3' << 16 | '5' << 24,
    [158] = '\\' | '2' << 8 | '3' << 16 | '6' << 24,
    [159] = '\\' | '2' << 8 | '3' << 16 | '7' << 24,
    [160] = '\\' | '2' << 8 | '4' << 16 | '0' << 24,
    [161] = '\\' | '2' << 8 | '4' << 16 | '1' << 24,
    [162] = '\\' | '2' << 8 | '4' << 16 | '2' << 24,
    [163] = '\\' | '2' << 8 | '4' << 16 | '3' << 24,
    [164] = '\\' | '2' << 8 | '4' << 16 | '4' << 24,
    [165] = '\\' | '2' << 8 | '4' << 16 | '5' << 24,
    [166] = '\\' | '2' << 8 | '4' << 16 | '6' << 24,
    [167] = '\\' | '2' << 8 | '4' << 16 | '7' << 24,
    [168] = '\\' | '2' << 8 | '5' << 16 | '0' << 24,
    [169] = '\\' | '2' << 8 | '5' << 16 | '1' << 24,
    [170] = '\\' | '2' << 8 | '5' << 16 | '2' << 24,
    [171] = '\\' | '2' << 8 | '5' << 16 | '3' << 24,
    [172] = '\\' | '2' << 8 | '5' << 16 | '4' << 24,
    [173] = '\\' | '2' << 8 | '5' << 16 | '5' << 24,
    [174] = '\\' | '2' << 8 | '5' << 16 | '6' << 24,
    [175] = '\\' | '2' << 8 | '5' << 16 | '7' << 24,
    [176] = '\\' | '2' << 8 | '6' << 16 | '0' << 24,
    [177] = '\\' | '2' << 8 | '6' << 16 | '1' << 24,
    [178] = '\\' | '2' << 8 | '6' << 16 | '2' << 24,
    [179] = '\\' | '2' << 8 | '6' << 16 | '3' << 24,
    [180] = '\\' | '2' << 8 | '6' << 16 | '4' << 24,
    [181] = '\\' | '2' << 8 | '6' << 16 | '5' << 24,
    [182] = '\\' | '2' << 8 | '6' << 16 | '6' << 24,
    [183] = '\\' | '2' << 8 | '6' << 16 | '7' << 24,
    [184] = '\\' | '2' << 8 | '7' << 16 | '0' << 24,
    [185] = '\\' | '2' << 8 | '7' << 16 | '1' << 24,
    [186] = '\\' | '2' << 8 | '7' << 16 | '2' << 24,
    [187] = '\\' | '2' << 8 | '7' << 16 | '3' << 24,
    [188] = '\\' | '2' << 8 | '7' << 16 | '4' << 24,
    [189] = '\\' | '2' << 8 | '7' << 16 | '5' << 24,
    [190] = '\\' | '2' << 8 | '7' << 16 | '6' << 24,
    [191] = '\\' | '2' << 8 | '7' << 16 | '7' << 24,
    [192] = '\\' | '3' << 8 | '0' << 16 | '0' << 24,
    [193] = '\\' | '3' << 8 | '0' << 16 | '1' << 24,
    [194] = '\\' | '3' << 8 | '0' << 16 | '2' << 24,
    [195] = '\\' | '3' << 8 | '0' << 16 | '3' << 24,
    [196] = '\\' | '3' << 8 | '0' << 16 | '4' << 24,
    [197] = '\\' | '3' << 8 | '0' << 16 | '5' << 24,
    [198] = '\\' | '3' << 8 | '0' << 16 | '6' << 24,
    [199] = '\\' | '3' << 8 | '0' << 16 | '7' << 24,
    [200] = '\\' | '3' << 8 | '1' << 16 | '0' << 24,
    [201] = '\\' | '3' << 8 | '1' << 16 | '1' << 24,
    [202] = '\\' | '3' << 8 | '1' << 16 | '2' << 24,
    [203] = '\\' | '3' << 8 | '1' << 16 | '3' << 24,
    [204] = '\\' | '3' << 8 | '1' << 16 | '4' << 24,
    [205] = '\\' | '3' << 8 | '1' << 16 | '5' << 24,
    [206] = '\\' | '3' << 8 | '1' << 16 | '6' << 24,
    [207] = '\\' | '3' << 8 | '1' << 16 | '7' << 24,
    [208] = '\\' | '3' << 8 | '2' << 16 | '0' << 24,
    [209] = '\\' | '3' << 8 | '2' << 16 | '1' << 24,
    [210] = '\\' | '3' << 8 | '2' << 16 | '2' << 24,
    [211] = '\\' | '3' << 8 | '2' << 16 | '3' << 24,
    [212] = '\\' | '3' << 8 | '2' << 16 | '4' << 24,
    [213] = '\\' | '3' << 8 | '2' << 16 | '5' << 24,
    [214] = '\\' | '3' << 8 | '2' << 16 | '6' << 24,
    [215] = '\\' | '3' << 8 | '2' << 16 | '7' << 24,
    [216] = '\\' | '3' << 8 | '3' << 16 | '0' << 24,
    [217] = '\\' | '3' << 8 | '3' << 16 | '1' << 24,
    [218] = '\\' | '3' << 8 | '3' << 16 | '2' << 24,
    [219] = '\\' | '3' << 8 | '3' << 16 | '3' << 24,
    [220] = '\\' | '3' << 8 | '3' << 16 | '4' << 24,
    [221] = '\\' | '3' << 8 | '3' << 16 | '5' << 24,
    [222] = '\\' | '3' << 8 | '3' << 16 | '6' << 24,
    [223] = '\\' | '3' << 8 | '3' << 16 | '7' << 24,
    [224] = '\\' | '3' << 8 | '4' << 16 | '0' << 24,
    [225] = '\\' | '3' << 8 | '4' << 16 | '1' << 24,
    [226] = '\\' | '3' << 8 | '4' << 16 | '2' << 24,
    [227] = '\\' | '3' << 8 | '4' << 16 | '3' << 24,
    [228] = '\\' | '3' << 8 | '4' << 16 | '4' << 24,
    [229] = '\\' | '3' << 8 | '4' << 16 | '5' << 24,
    [230] = '\\' | '3' << 8 | '4' << 16 | '6' << 24,
    [231] = '\\' | '3' << 8 | '4' << 16 | '7' << 24,
    [232] = '\\' | '3' << 8 | '5' << 16 | '0' << 24,
    [233] = '\\' | '3' << 8 | '5' << 16 | '1' << 24,
    [234] = '\\' | '3' << 8 | '5' << 16 | '2' << 24,
    [235] = '\\' | '3' << 8 | '5' << 16 | '3' << 24,
    [236] = '\\' | '3' << 8 | '5' << 16 | '4' << 24,
    [237] = '\\' | '3' << 8 | '5' << 16 | '5' << 24,
    [238] = '\\' | '3' << 8 | '5' << 16 | '6' << 24,
    [239] = '\\' | '3' << 8 | '5' << 16 | '7' << 24,
    [240] = '\\' | '3' << 8 | '6' << 16 | '0' << 24,
    [241] = '\\' | '3' << 8 | '6' << 16 | '1' << 24,
    [242] = '\\' | '3' << 8 | '6' << 16 | '2' << 24,
    [243] = '\\' | '3' << 8 | '6' << 16 | '3' << 24,
    [244] = '\\' | '3' << 8 | '6' << 16 | '4' << 24,
    [245] = '\\' | '3' << 8 | '6' << 16 | '5' << 24,
    [246] = '\\' | '3' << 8 | '6' << 16 | '6' << 24,
    [247] = '\\' | '3' << 8 | '6' << 16 | '7' << 24,
    [248] = '\\' | '3' << 8 | '7' << 16 | '0' << 24,
    [249] = '\\' | '3' << 8 | '7' << 16 | '1' << 24,
    [250] = '\\' | '3' << 8 | '7' << 16 | '2' << 24,
    [251] = '\\' | '3' << 8 | '7' << 16 | '3' << 24,
    [252] = '\\' | '3' << 8 | '7' << 16 | '4' << 24,
    [253] = '\\' | '3' << 8 | '7' << 16 | '5' << 24,
    [254] = '\\' | '3' << 8 | '7' << 16 | '6' << 24,
    [255] = '\\' | '3' << 8 | '7' << 16 | '7' << 24,
};

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < 256; ++i) {
    printf("[%d] = ", i);
    int j = 0;
    uint32_t x = _cescapec(i);
    do {
      if (j) {
        printf(" | ");
      }
      if (isprint(x & 255)) {
        if ((x & 255) == '\\') {
          printf("'\\\\'");
        } else {
          printf("'%c'", x & 255);
        }
      } else {
        printf("%d", x & 255);
      }
      if (j) {
        printf(" << %d", j);
      }
      j += 8;
    } while ((x >>= 8));
    printf(",\n");
  }
}